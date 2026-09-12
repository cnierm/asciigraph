#pragma once

#include <asciigraph/function/function_base.hpp>
#include <memory>

class f_add : public binary_base
{
public:
    f_add(std::shared_ptr<function> lhs, std::shared_ptr<function> rhs);
    
    double evaluate(double x) const override;
};

class f_subtract : public binary_base
{
public:
    f_subtract(std::shared_ptr<function> lhs, std::shared_ptr<function> rhs);
    
    double evaluate(double x) const override;
};

class f_mult : public binary_base
{
public:
    f_mult(std::shared_ptr<function> lhs, std::shared_ptr<function> rhs);
    
    double evaluate(double x) const override;
};

class f_div : public binary_base
{
public:
    f_div(std::shared_ptr<function> lhs, std::shared_ptr<function> rhs);
    
    double evaluate(double x) const override;
};

class f_mod : public binary_base
{
public:
    f_mod(std::shared_ptr<function> lhs, std::shared_ptr<function> rhs);
    
    double evaluate(double x) const override;
};