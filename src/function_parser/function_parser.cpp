#include <algorithm>
#include <asciigraph/function/function.hpp>
#include <asciigraph/function_parser/function_parser.hpp>
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <memory>
#include <numbers>
#include <print>
#include <string>
#include <vector>

std::vector<std::string> function_parser::tokenize(const std::string& input)
{
    // handle parentheses
    if (input.find_first_of("()") != std::string::npos)
    {
        return deparenthesize(input);
    }

    // recursively tokenize all single character tokens
    std::size_t index = input.find_first_of(
        "+-*/%^!"); // TODO: make sure x is not next to any other letters
                    // (other than maybe x)
    if (index != std::string::npos)
    {
        return function_parser::split(input, index, 1);
    }

    index = input.find_first_of("0123456789.");
    if (index != std::string::npos)
    {
        int num_decimals {input.at(index) == '.'};
        int l {1};
        bool next_is_digit_or_decimal {true};
        while (num_decimals < 2 and next_is_digit_or_decimal)
        {
            if (std::isdigit(input.at(index + l)))
                ++l;
            else if (input.at(index + l) == '.') 
            {
                if(++num_decimals < 2) 
                    ++l;
            }
            else
                next_is_digit_or_decimal = false;
        }
        return function_parser::split(input, index, l);
        
    }

    // (I think) other keywords go here
    // maybe: make a list of keywords

    for (const auto &op : multi_char_operations)
    {
        index = input.find(op);
        if (index != std::string::npos)
        {
            return function_parser::split(input, index, op.length());
        }
    }

    index = input.find_first_of("ex");
    if (index != std::string::npos && input.find_first_not_of("ex") == std::string::npos)
    {
        return function_parser::split(input, index, 1);
    }

    return {input};
}

std::vector<std::string> function_parser::deparenthesize(const std::string& input)
{
    std::string new_input {input};
    int net_parentheses = 0;
    for (const auto &c : new_input)
    {
        if (c == '(')
            ++net_parentheses;
        else if (c == ')')
            --net_parentheses;
    }

    while (net_parentheses != 0)
    {
        if (net_parentheses > 0)
        {
            new_input.push_back(')');
            --net_parentheses;
        }
        else
        {
            new_input.insert(0, "(");
            ++net_parentheses;
        }
    }

    std::size_t open_paren {new_input.find_first_of("(")};
    std::size_t closed_paren {open_paren + 1};
    int paren_count {1};
    for (; closed_paren < new_input.length() and paren_count > 0; ++closed_paren) {
        if (new_input.at(closed_paren) == '(')
            ++paren_count;
        else if (new_input.at(closed_paren) == ')')
            --paren_count;
    }
    --closed_paren;

    while (paren_count > 0)
    {
        new_input.push_back(')');
        ++closed_paren;
        --paren_count;
    }
    new_input.erase(open_paren, 1);
    new_input.erase(--closed_paren, 1);
    std::size_t length {closed_paren - open_paren};
    return function_parser::split(new_input, open_paren, length);
}

std::vector<std::string> function_parser::split(const std::string& input, std::size_t index, std::size_t length)
{
    std::string ltokens_str {input.substr(0, index)};
    std::string split_token {input.substr(index, length)};
    std::string rtokens_str {input.substr(index + length)};

    bool left_not_empty {ltokens_str.size() != 0};
    bool right_not_empty {rtokens_str.size() != 0};

    std::vector<std::string> ltokens;
    std::vector<std::string> rtokens;

    if (left_not_empty) 
    {
        ltokens = function_parser::tokenize(ltokens_str);
    }
    if (right_not_empty)
    {
        rtokens = function_parser::tokenize(rtokens_str);
    }

    std::vector<std::string> tokens;
    tokens.reserve(ltokens.size() + length + rtokens.size());
    if (left_not_empty)
    {
        tokens.insert(tokens.end(),
            std::make_move_iterator(ltokens.begin()),
            std::make_move_iterator(ltokens.end()));
    }

    tokens.push_back(split_token);
    
    if (right_not_empty)
    {
        tokens.insert(tokens.end(), 
            std::make_move_iterator(rtokens.begin()), 
            std::make_move_iterator(rtokens.end()));
    }
    

    return tokens;
}

std::shared_ptr<function> parse(std::vector<std::string> tokens) {
    // reverse pemdas

    auto it = std::find_if(tokens.rbegin(), tokens.rend(), [](std::string s) 
    {
        return s.size() == 1 and std::string{"+-"}.find(s) != std::string::npos;
    });

    if (it != tokens.rend()) {
        std::size_t token_index = std::distance(it, tokens.rend()) - 1;
        std::vector<std::string> ltokens {tokens.begin(), tokens.begin() + token_index};
        std::vector<std::string> rtokens {tokens.begin() + token_index + 1, tokens.end()};
        if (tokens[token_index] == "+")
        {
            
        }
    }

    return std::make_shared<f_var>();
}

std::shared_ptr<function> function_parser::parse_simple(const std::string &token)
{
    if (token == "x")
        return std::make_shared<f_var>();
    if (token == "e")
        return std::make_shared<f_const>(std::numbers::e);
    if (token == "pi")
        return std::make_shared<f_const>(std::numbers::pi);
    if (token == "phi")
        return std::make_shared<f_const>(std::numbers::phi);
    if (token.find_first_not_of("1234567890.") == std::string::npos)
        return std::make_shared<f_const>(std::stod(token));
    else
        return std::make_shared<f_error>(token);
    
}

std::shared_ptr<function> function_parser::parse(const std::string &input)
{
    std::string new_input {input};
    new_input.erase(
        std::remove_if(
            new_input.begin(), 
            new_input.end(), 
            [](char c){return std::isspace(c);}), 
        new_input.end());
    auto tokens {function_parser::tokenize(new_input)};

    std::println("{:}", tokens);
    std::string s;
    std::getline(std::cin, s);

    // base case
    if (tokens.size() == 1) 
    {
        auto token = tokens.at(0);
        if (token == function_parser::tokenize(token).at(0))
        {
            function_parser::parse_simple(token);
        }
        else
        {
            return function_parser::parse(token);
        }
        
    }
    else 
    {
        auto is_operand {[](std::string s) 
        {
            std::puts(s.c_str());
            auto s_tokenized = function_parser::tokenize(s);
            //std::puts(s_tokenized[0].c_str());
            return (s_tokenized.size() != 1 and s != s_tokenized.at(0))
                or (s == "x" or s == "phi" or s == "tau" or s == "pi" 
                or s.find_first_of("1234567890.") != std::string::npos);
        }};

        // put multiplication operators between two operands: "2x" -> "2 * x"
        // in addition, if a unary left-side operater is right of an operand: "4sinx" -> "4 * sinx"
        auto it = std::find_if(tokens.begin(), tokens.end(), is_operand);
        std::println("hi");
        while (it != tokens.end())
        {
            std::println("operand at {}", 0);
            std::getline(std::cin, s);
            auto index {std::distance(tokens.begin(), it)};
            
            if (index > 0 and is_operand(tokens.at(index - 1)))
            {
                tokens.insert(it, "*");
                std::advance(it, 1);
            }

            ++it;
            it = std::find_if(it, tokens.end(), is_operand);
        }

        // differentiate subtraction operators and negation operators
        it = std::find(tokens.begin(), tokens.end(), "-");
        while (it != tokens.end())
        {
            auto index {std::distance(tokens.begin(), it)};
            std::println("- at {}", index);
            std::getline(std::cin, s);
            if (index == 0 or not is_operand(tokens.at(index - 1)))
            {
                tokens.at(index) = "-1";
                tokens.insert(it + 1, "*");
            }

            it = std::find(tokens.begin(), tokens.end(), "-");
        }
        std::println("{:}", tokens);
        std::getline(std::cin, s);

        std::println("{:}", tokens);
        std::getline(std::cin, s);
    }
    return nullptr;
}