#pragma once

#include "asciigraph/function/function_base.hpp"
#include <asciigraph/function/function.hpp>
#include <memory>

class f_pow : public binary_base
{
public:
    f_pow(std::shared_ptr<function> lhs, std::shared_ptr<function> rhs);

    double evaluate(double x) const override;
};

class f_square : public f_pow
{
public:
    f_square(std::shared_ptr<function> arg);
};

class f_cube : public f_pow
{
public:
    f_cube(std::shared_ptr<function> arg);
};

class f_sqrt : public unary_base
{
public:
    f_sqrt(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_cbrt : public unary_base
{
public:
    f_cbrt(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_exp : public unary_base
{
public:
    f_exp(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_ln : public unary_base
{
public:
    f_ln(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_log : public unary_base
{
public:
    f_log(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};