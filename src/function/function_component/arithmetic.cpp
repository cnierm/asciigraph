#include <asciigraph/function/function_component/arithmetic.hpp>
#include <memory>
#include <cmath>

f_add::f_add(std::shared_ptr<function> lhs, std::shared_ptr<function> rhs)
    : binary_base(std::move(lhs), std::move(rhs), "+") {}

double f_add::evaluate(double x) const
{
    return this->larg->evaluate(x) + this->rarg->evaluate(x);
}

f_subtract::f_subtract(std::shared_ptr<function> lhs, std::shared_ptr<function> rhs)
    : binary_base(std::move(lhs), std::move(rhs), "-") {}

double f_subtract::evaluate(double x) const
{
    return this->larg->evaluate(x) - this->rarg->evaluate(x);
}

f_mult::f_mult(std::shared_ptr<function> lhs, std::shared_ptr<function> rhs)
    : binary_base(std::move(lhs), std::move(rhs), "*") {}

double f_mult::evaluate(double x) const
{
    return this->larg->evaluate(x) * this->rarg->evaluate(x);
}

f_div::f_div(std::shared_ptr<function> lhs, std::shared_ptr<function> rhs)
    : binary_base(std::move(lhs), std::move(rhs), "/") {}

double f_div::evaluate(double x) const
{
    return this->larg->evaluate(x) / this->rarg->evaluate(x);
}

f_mod::f_mod(std::shared_ptr<function> lhs, std::shared_ptr<function> rhs)
    : binary_base(std::move(lhs), std::move(rhs), "%") {}

double f_mod::evaluate(double x) const
{
    return std::fmod(this->larg->evaluate(x), this->rarg->evaluate(x));
}