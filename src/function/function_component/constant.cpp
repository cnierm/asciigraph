#include <asciigraph/function/function_component/constant.hpp>
#include <numbers>
#include <string>

f_const::f_const(double v) : value{ v } {}

double f_const::evaluate(double) const
{
    return value;
}
std::string f_const::name() const
{
    return std::to_string(value);
}

f_const_e::f_const_e() : f_const(std::numbers::e) {}

std::string f_const_e::name() const { return "e"; }

f_const_phi::f_const_phi() : f_const(std::numbers::phi) {}

std::string f_const_phi::name() const { return "φ"; }

f_const_pi::f_const_pi() : f_const(std::numbers::pi) {}

std::string f_const_pi::name() const { return "π"; }

f_const_tau::f_const_tau() : f_const(2 * std::numbers::pi) {}

std::string f_const_tau::name() const { return "τ"; }