#pragma once

#include <asciigraph/function/function_base.hpp>
#include <string>

class f_gamma : public unary_base
{
public:
    f_gamma(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_factorial : public unary_base
{
public:
    f_factorial(std::shared_ptr<function> arg);

    double evaluate(double x) const override;

    std::string name() const override;
};