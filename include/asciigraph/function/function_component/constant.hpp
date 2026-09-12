#pragma once

#include <asciigraph/function/function.hpp>

class f_const : public function
{
private:
    const double value;
public:
    f_const(double v);

    double evaluate(double) const override;
    std::string name() const override;
};

class f_const_e : public f_const
{
public:
    f_const_e();

    std::string name() const override;
};

class f_const_phi : public f_const
{
public:
    f_const_phi();

    std::string name() const override;
};

class f_const_pi : public f_const
{
public:
    f_const_pi();

    std::string name() const override;
};

class f_const_tau : public f_const
{
public:
    f_const_tau();

    std::string name() const override;
};