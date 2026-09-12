#pragma once

#include <asciigraph/function/function_base.hpp>
#include <memory>


class function_parser 
{

public:
    static std::shared_ptr<function> parse(std::string input); 
private:
    static void balance_brackets(std::string &input);
};