#pragma once

#include <memory>
#include <string>

class function
{
public:
    
    virtual ~function();

    virtual double evaluate(double x) const = 0;

    virtual std::string name() const = 0;
    
};

class unary_base : public function
{
protected:
    std::shared_ptr<function> arg;
    std::string func_name;
public:
    unary_base(std::shared_ptr<function> arg, std::string func_name);

    std::string name() const override;
};

class binary_base : public function
{
protected:
    std::shared_ptr<function> larg;
    std::shared_ptr<function> rarg;
    std::string symbol;
public:
    binary_base(std::shared_ptr<function> lhs, std::shared_ptr<function> rhs, std::string symbol);

    std::string name() const override;
};

class f_error : public function
{
private:
    std::string error_token;
public:
    f_error(std::string token);
    double evaluate(double x) const override;
    std::string name() const override;
};