#include "asciigraph/function/function_base.hpp"
#include <asciigraph/function/function_component/trigonometry.hpp>
#include <cmath>
#include <memory>

f_sin::f_sin(std::shared_ptr<function> arg) 
    : unary_base(std::move(arg), "sin") {}

double f_sin::evaluate(double x) const
{
    return std::sin(arg->evaluate(x));
}

f_cos::f_cos(std::shared_ptr<function> arg) 
    : unary_base(std::move(arg), "cos") {}

double f_cos::evaluate(double x) const
{
    return std::cos(arg->evaluate(x));
}

f_tan::f_tan(std::shared_ptr<function> arg) 
    : unary_base(std::move(arg), "tan") {}

double f_tan::evaluate(double x) const
{
    return std::tan(arg->evaluate(x));
}

f_sec::f_sec(std::shared_ptr<function> arg) 
    : unary_base(std::move(arg), "sec") {}

double f_sec::evaluate(double x) const
{
    return 1 / std::cos(arg->evaluate(x));
}

f_csc::f_csc(std::shared_ptr<function> arg) 
    : unary_base(std::move(arg), "csc") {}

double f_csc::evaluate(double x) const
{
    return 1 / std::sin(arg->evaluate(x));
}

f_cot::f_cot(std::shared_ptr<function> arg) 
    : unary_base(std::move(arg), "cot") {}

double f_cot::evaluate(double x) const
{
    return 1 / std::tan(arg->evaluate(x));
}

f_asin::f_asin(std::shared_ptr<function> arg) 
    : unary_base(std::move(arg), "asin") {}

double f_asin::evaluate(double x) const
{
    return std::asin(arg->evaluate(x));
}

f_acos::f_acos(std::shared_ptr<function> arg) 
    : unary_base(std::move(arg), "acos") {}

double f_acos::evaluate(double x) const
{
    return std::acos(arg->evaluate(x));
}

f_atan::f_atan(std::shared_ptr<function> arg) 
    : unary_base(std::move(arg), "atan") {}

double f_atan::evaluate(double x) const
{
    return std::atan(arg->evaluate(x));
}

f_asec::f_asec(std::shared_ptr<function> arg) 
    : unary_base(std::move(arg), "asec") {}

double f_asec::evaluate(double x) const
{
    return 1 / std::acos(arg->evaluate(x));
}

f_acsc::f_acsc(std::shared_ptr<function> arg) 
    : unary_base(std::move(arg), "acsc") {}

double f_acsc::evaluate(double x) const
{
    return 1 / std::asin(arg->evaluate(x));
}

f_acot::f_acot(std::shared_ptr<function> arg) 
    : unary_base(std::move(arg), "acot") {}

double f_acot::evaluate(double x) const
{
    return 1 / std::atan(arg->evaluate(x));
}