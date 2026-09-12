#pragma once

#include <asciigraph/function/function_base.hpp>
#include <memory>

class f_sin : public unary_base
{
public:
    f_sin(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_cos : public unary_base
{
public:
    f_cos(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_tan : public unary_base
{
public:
    f_tan(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_sec : public unary_base
{
public:
    f_sec(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_csc : public unary_base
{
public:
    f_csc(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_cot : public unary_base
{
public:
    f_cot(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_asin : public unary_base
{
public:
    f_asin(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_acos : public unary_base
{
public:
    f_acos(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_atan : public unary_base
{
public:
    f_atan(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_asec : public unary_base
{
public:
    f_asec(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_acsc : public unary_base
{
public:
    f_acsc(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};

class f_acot : public unary_base
{
public:
    f_acot(std::shared_ptr<function> arg);

    double evaluate(double x) const override;
};