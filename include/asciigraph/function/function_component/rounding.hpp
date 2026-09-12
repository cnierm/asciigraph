#pragma once

#include <asciigraph/function/function_base.hpp>

class f_floor : public unary_base
{
public:
    f_floor(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_ceil : public unary_base
{
public:
    f_ceil(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_trunc : public unary_base
{
public:
    f_trunc(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_round : public unary_base
{
public:
    f_round(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};