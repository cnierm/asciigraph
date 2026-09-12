#include <memory>
#include <asciigraph/function/function_base.hpp>
#include <string>
#include <limits>

function::~function() = default;

unary_base::unary_base(std::shared_ptr<function> f, std::string func_name) 
    : arg{ std::move(f) }, func_name{ std::move(func_name) } {}

std::string unary_base::name() const
{
    return this->func_name + "(" + this->arg->name() + ")";
}

binary_base::binary_base(std::shared_ptr<function> lhs, std::shared_ptr<function> rhs, std::string symbol)
        : larg { std::move(lhs) }, rarg { std::move(rhs) }, symbol { std::move(symbol) } {}

std::string binary_base::name() const
{
    return this->larg->name() + this->symbol + this->rarg->name();
}

f_error::f_error(std::string token) : error_token {token} {}

double f_error::evaluate(double) const
{
    return std::numeric_limits<double>::quiet_NaN();
}

std::string f_error::name() const
{
        return "\x1b[31m???\x1b[0m";
}