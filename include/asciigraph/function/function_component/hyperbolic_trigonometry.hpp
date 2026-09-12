#pragma once

#include <asciigraph/function/function_base.hpp>
#include <memory>

class f_sinh : public unary_base
{
public:
    f_sinh(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_cosh : public unary_base
{
public:
    f_cosh(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_tanh : public unary_base
{
public:
    f_tanh(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_sech : public unary_base
{
public:
    f_sech(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_csch : public unary_base
{
public:
    f_csch(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_coth : public unary_base
{
public:
    f_coth(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_asinh : public unary_base
{
public:
    f_asinh(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_acosh : public unary_base
{
public:
    f_acosh(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_atanh : public unary_base
{
public:
    f_atanh(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_asech : public unary_base
{
public:
    f_asech(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_acsch : public unary_base
{
public:
    f_acsch(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_acoth : public unary_base
{
public:
    f_acoth(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

