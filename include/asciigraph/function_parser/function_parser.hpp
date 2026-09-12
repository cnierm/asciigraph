#pragma once
#include <memory>
#include <string>
#include <vector>
#include <asciigraph/function/function_base.hpp>

class function_parser
{
private:
    /**
     * @brief These are used in a loop and tokenized individually.
     * NOTE: put larger names first. If "tan" is before "atan", "atan" will never be found
     */
    static constexpr std::string multi_char_operations[]
    {
        "gamma",
        "floor", "ceil","trunc","round",
        "asinh", "acosh", "atanh", "acsch", "asech", "acoth",
        "sinh", "cosh", "tanh", "csch", "sech", "coth",
        "asin", "acos", "atan", "acsc", "asec", "acot",
        "sin", "cos", "tan", "csc", "sec", "cot",
        "sqrt",
        "log", "ln",
        "tau", "phi", "pi"
    };
    static std::vector<std::string> split(const std::string& input, std::size_t index, std::size_t length);
    static std::vector<std::string> tokenize(const std::string &input);
    static std::vector<std::string> deparenthesize(const std::string &input);
    static std::shared_ptr<function> parse_simple(const std::string &token);

  public:
    static std::shared_ptr<function> parse(const std::string& input);
};