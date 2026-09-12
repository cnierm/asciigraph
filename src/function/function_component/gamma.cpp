#include <asciigraph/function/function_component/gamma.hpp>
#include <cmath>
#include <memory>
#include <string>

f_gamma::f_gamma(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "gamma") {}

double f_gamma::evaluate(double x) const
{
    return std::tgamma(arg->evaluate(x));
}

f_factorial::f_factorial(std::shared_ptr<function> arg)
    : unary_base(std::move(arg), "factorial") {}

double f_factorial::evaluate(double x) const
{
    return std::tgamma(arg->evaluate(x) + 1);
}

std::string f_factorial::name() const
{
    return "(" + arg->name() + ")!";
}