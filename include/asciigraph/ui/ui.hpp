#pragma once

#include "asciigraph/function/function_base.hpp"
#include "window.hpp"
#include <memory>
#include <print>
#include <string>

class ui 
{
public:
    ui();
    void render_background();
    std::string get_input();
    void render_function(std::shared_ptr<function> f);
    void render_function_2(std::shared_ptr<function> f);
private:
    window w;
    inline void clear_screen() {std::print("\x1b[2J");}
    inline void set_dim() {std::print("\x1b[2m");}
    inline void clear_formatting() {std::print("\x1b[0m");}
    inline void move_cursor(int row, int col) {std::print("\x1b[{};{}f", row, col);}
    
};