#include <asciigraph/function/function_component/rounding.hpp>
#include <cmath>

f_floor::f_floor(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "floor") {}

double f_floor::evaluate(double x) const
{
    return std::floor(this->arg->evaluate(x));
}

f_ceil::f_ceil(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "ceil") {}

double f_ceil::evaluate(double x) const
{
    return std::ceil(this->arg->evaluate(x));
}

f_trunc::f_trunc(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "trunc") {}

double f_trunc::evaluate(double x) const
{
    return std::trunc(this->arg->evaluate(x));
}

f_round::f_round(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "round") {}

double f_round::evaluate(double x) const
{
    return std::round(this->arg->evaluate(x));
}