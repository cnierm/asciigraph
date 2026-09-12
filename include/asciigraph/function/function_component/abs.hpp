#pragma once

#include <asciigraph/function/function_base.hpp>
#include <string>

class f_abs : public unary_base
{
    f_abs(std::shared_ptr<function> arg);

    double evaluate(double x) const override;

    std::string name() const override;
};

class f_sgn : public unary_base
{
    f_sgn(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};