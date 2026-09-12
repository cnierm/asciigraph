#include "asciigraph/function/function_base.hpp"
#include <asciigraph/function_parser/function_parser_2.hpp>
#include <cstddef>
#include <memory>
#include <string>

std::shared_ptr<function> function_parser::parse(std::string input)
{
    balance_brackets(input);
}

void function_parser::balance_brackets(std::string &input)
{
    int running_count = 0;
    for (std::size_t i = 0; i < input.size(); ++i) 
    {
        if (input[i] == '(')
        {
            ++running_count;
        }
        else if (input[i] == ')')
        {
            if (running_count == 0)
            {
                input.insert(0, "(");
            }
            else 
            {
                --running_count;
            }
            
        }
        if (running_count > 0) 
        {
            input.append(running_count, ')');
        }
    }

}