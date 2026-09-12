#pragma once

#include <asciigraph/function/function.hpp>
#include <string>

class f_var : public function 
{
public:
    double evaluate(double x) const override;
    std::string name() const override;
};