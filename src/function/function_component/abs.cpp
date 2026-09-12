#include "asciigraph/function/function_base.hpp"
#include <asciigraph/function/function_component/abs.hpp>
#include <cmath>
#include <memory>
#include <string>

f_abs::f_abs(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "abs") {}

double f_abs::evaluate(double x) const
{
    return std::fabs(arg->evaluate(x));
}

std::string f_abs::name() const
{
    return "|" + arg->name() + "|";
}

f_sgn::f_sgn(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "sgn") {}

double f_sgn::evaluate(double x) const
{
    double result = arg->evaluate(x);

    return (result > 0) - (result < 0);
}