#include <asciigraph/function/function_component/variable.hpp>

double f_var::evaluate(double x) const 
{
    return x;
}

std::string f_var::name() const
{
    return "x";
}
