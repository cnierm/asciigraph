#include "asciigraph/function/function_base.hpp"
#include <asciigraph/function/function_component/hyperbolic_trigonometry.hpp>
#include <cmath>
#include <memory>

f_sinh::f_sinh(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "sinh") {}

double f_sinh::evaluate(double x) const
{
    return std::sinh(arg->evaluate(x));
}

f_cosh::f_cosh(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "cosh") {}

double f_cosh::evaluate(double x) const
{
    return std::cosh(arg->evaluate(x));
}

f_tanh::f_tanh(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "tanh") {}

double f_tanh::evaluate(double x) const
{
    return std::tanh(arg->evaluate(x));
}

f_sech::f_sech(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "sech") {}

double f_sech::evaluate(double x) const
{
    return 1 / std::cosh(arg->evaluate(x));
}

f_csch::f_csch(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "csch") {}

double f_csch::evaluate(double x) const
{
    return 1 / std::sinh(arg->evaluate(x));
}

f_coth::f_coth(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "coth") {}

double f_coth::evaluate(double x) const
{
    return 1 / std::tanh(arg->evaluate(x));
}

f_asinh::f_asinh(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "asinh") {}

double f_asinh::evaluate(double x) const
{
    return std::asinh(arg->evaluate(x));
}

f_acosh::f_acosh(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "acosh") {}

double f_acosh::evaluate(double x) const
{
    return std::acosh(arg->evaluate(x));
}

f_atanh::f_atanh(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "atanh") {}

double f_atanh::evaluate(double x) const
{
    return std::atanh(arg->evaluate(x));
}

f_asech::f_asech(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "asech") {}

double f_asech::evaluate(double x) const
{
    return 1 / std::acosh(arg->evaluate(x));
}

f_acsch::f_acsch(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "acsch") {}

double f_acsch::evaluate(double x) const
{
    return 1 / std::asinh(arg->evaluate(x));
}

f_acoth::f_acoth(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "acoth") {}

double f_acoth::evaluate(double x) const
{
    return 1 / std::atanh(arg->evaluate(x));
}