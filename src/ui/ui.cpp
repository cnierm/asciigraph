#include "asciigraph/function/function_base.hpp"
#include <asciigraph/ui/ui.hpp>
#include <cstddef>
#include <format>
#include <iostream>
#include <memory>
#include <print>
#include <string>
#include <vector>

ui::ui() : w {window{}}{}

void ui::render_background()
{
    clear_screen();
    

    w.set_dimensions();
    int width {w.dimensions.cols};
    int height {w.dimensions.rows};
    std::string pattern {};
    pattern.reserve(width * height);

    pattern += std::format("╭{:─^{}}╮\n", "", width - 2);
    pattern += std::format("│ f(x) = {: ^{}}│\n", "", width - 10);
    pattern += std::format("╰{:─^{}}╯\n", "", width - 2);

    int left_width = (width - 2) / 2;
    int right_width = width - left_width - 3;
    pattern += std::format("╭{0:─^{1}}┬{0:─^{2}}╮\n", "", left_width, right_width);

    int bottom_height = (height - 5) / 2;
    int top_height = height - bottom_height - 6;
    if (top_height % 2)
    {
        pattern += "│\x1b[90m";
        pattern += std::format("{: ^{}}", "", (left_width % 4));
        for (int i = 0; i < left_width / 4; ++i) pattern += "│   ";
        pattern += "\x1b[0m│\x1b[90m";
        for (int i = 0; i < right_width / 4; ++i) pattern += "   │";
        pattern += std::format("{: ^{}}", "", (right_width % 4));
        pattern += "\x1b[0m│\n";
    }
    for (int i = 0; i < top_height / 2; ++i)
    {
        pattern += "│\x1b[90m";
        pattern += std::format("{:─^{}}", "", (left_width % 4));
        for (int i = 0; i < left_width / 4; ++i) pattern += "┼───";
        pattern += "\x1b[0m┼\x1b[90m";
        for (int i = 0; i < right_width / 4; ++i) pattern += "───┼";
        pattern += std::format("{:─^{}}", "", (right_width % 4));
        pattern += "\x1b[0m│\n│\x1b[90m";
        pattern += std::format("{: ^{}}", "", (left_width % 4));
        for (int i = 0; i < left_width / 4; ++i) pattern += "│   ";
        pattern += "\x1b[0m│\x1b[90m";
        for (int i = 0; i < right_width / 4; ++i) pattern += "   │";
        pattern += std::format("{: ^{}}", "", (right_width % 4));
        pattern += "\x1b[0m│\n";
    }

    pattern += "│";
    pattern += std::format("{:─^{}}", "", (left_width % 4));
    for (int i = 0; i < left_width / 4; ++i) pattern += "┼───";
    pattern += "┼";
    for (int i = 0; i < right_width / 4; ++i) pattern += "───┼";
    pattern += std::format("{:─^{}}", "", (right_width % 4));
    pattern += "│\n";

    if (bottom_height % 2)
    {
        pattern += "│\x1b[90m";
        pattern += std::format("{: ^{}}", "", (left_width % 4));
        for (int i = 0; i < left_width / 4; ++i) pattern += "│   ";
        pattern += "\x1b[0m│\x1b[90m";
        for (int i = 0; i < right_width / 4; ++i) pattern += "   │";
        pattern += std::format("{: ^{}}", "", (right_width % 4));
        pattern += "\x1b[0m│\n";
    }
    for (int i = 0; i < bottom_height / 2; ++i)
    {
        pattern += "│\x1b[90m";
        pattern += std::format("{:─^{}}", "", (left_width % 4));
        for (int i = 0; i < left_width / 4; ++i) pattern += "┼───";
        pattern += "\x1b[0m┼\x1b[90m";
        for (int i = 0; i < right_width / 4; ++i) pattern += "───┼";
        pattern += std::format("{:─^{}}", "", (right_width % 4));
        pattern += "\x1b[0m│\n│\x1b[90m";
        pattern += std::format("{: ^{}}", "", (left_width % 4));
        for (int i = 0; i < left_width / 4; ++i) pattern += "│   ";
        pattern += "\x1b[0m│\x1b[90m";
        for (int i = 0; i < right_width / 4; ++i) pattern += "   │";
        pattern += std::format("{: ^{}}", "", (right_width % 4));
        pattern += "\x1b[0m│\n";
    }

    pattern += std::format("╰{0:─^{1}}┴{0:─^{2}}╯", "", left_width, right_width);

    std::print("{}", pattern);
    
}

std::string ui::get_input()
{
    move_cursor(2, 10);

    std::string s;
    std::getline(std::cin, s);
    return s;
}

void ui::render_function(std::shared_ptr<function> f)
{
    render_background();

    int width {w.dimensions.cols};
    int height {w.dimensions.rows};

    struct {
        int x;
        int y;
    } origin {(width + 2) / 2, (height + 4) / 2};

    move_cursor(origin.y, origin.x);
    std::print("o");

    // set the color
    std::print("\x1b[34m");

    for (int y = 5; y < height; ++y)
    {
        int x = 2;
        move_cursor(y, x);

        // there is probably a better way of doing this...
        std::vector<bool> above_curve {std::vector<bool>(6)};

        struct { double x; double y; }
        vec_2 {(x - origin.x) / 4.0, (origin.y - y) / 2.0};

        double x_for_f = vec_2.x - 0.125;

        double f_of_x = f->evaluate(x_for_f);

        above_curve.at(0) = (vec_2.y + 0.25) > f_of_x;
        above_curve.at(1) = (vec_2.y) > f_of_x;
        above_curve.at(2) = (vec_2.y - 0.25) > f_of_x;

        for (; x < width; ++x)
        {
            vec_2 = {(x - origin.x) / 4.0, (origin.y - y) / 2.0};

            x_for_f = vec_2.x + 0.125;

            f_of_x = f->evaluate(x_for_f);

            above_curve.at(3) = (vec_2.y + 0.25) > f_of_x;
            above_curve.at(4) = (vec_2.y) > f_of_x;
            above_curve.at(5) = (vec_2.y - 0.25) > f_of_x;

            // if (vec_2.x == 0.25 && vec_2.y == 0) {
            //     std::print("{:}", above_curve);
            // }

            bool draw_top 
            {
                above_curve.at(0) != above_curve.at(1) or
                above_curve.at(0) != above_curve.at(3) or
                above_curve.at(0) != above_curve.at(4) or
                above_curve.at(1) != above_curve.at(3) or
                above_curve.at(1) != above_curve.at(4) or
                above_curve.at(3) != above_curve.at(4)
            };
            bool draw_bottom 
            {
                above_curve.at(1) != above_curve.at(2) or
                above_curve.at(1) != above_curve.at(4) or
                above_curve.at(1) != above_curve.at(5) or
                above_curve.at(2) != above_curve.at(4) or
                above_curve.at(2) != above_curve.at(5) or
                above_curve.at(4) != above_curve.at(5)
            };

            
            if (draw_top and draw_bottom) std::print("█");
            else if (draw_top) std::print("▀");
            else if (draw_bottom) std::print("▄");
            else std::print("\x1b[1C"); // move right

            above_curve.at(0) = above_curve.at(3);
            above_curve.at(1) = above_curve.at(4);
            above_curve.at(2) = above_curve.at(5);
        }
    }
    clear_formatting();
}

void ui::render_function_2(std::shared_ptr<function> f)
{
    render_background();
    move_cursor(5, 2);
    std::print("\x1b[34m");

    int width {w.dimensions.cols};
    int height {w.dimensions.rows};

    struct {
        int x;
        int y;
    } origin {(width + 2) / 2, (height + 4) / 2};


    std::vector<double> func_map;

    double leftmost = (2 - origin.x) / 4.0 - 0.125;
    double rightmost = ((width - 1) - origin.x) / 4.0 + 0.125;

    for (double i = leftmost; i <= rightmost; i += 0.125) 
        func_map.push_back(f->evaluate(i));

    double topmost = (origin.y - 5) / 2.0;
    double bottommost = (origin.y - (height - 1)) / 2.0;

    std::vector<bool> above_curve = std::vector<bool>(12);

    for (double y = topmost; y >= bottommost; y -= 0.5)
    {
        move_cursor((-2 * y) + origin.y, 2);
        double y_1 = y + 0.25;
        double y_2 = y + 1.0 / 12.0;
        double y_3 = y - 1.0 / 12.0;
        double y_4 = y - 0.25;
        above_curve.at(0) = (y_1) > func_map.at(0);
        above_curve.at(1) = (y_2) > func_map.at(0);
        above_curve.at(2) = (y_3) > func_map.at(0);
        above_curve.at(3) = (y_4) > func_map.at(0);

        for (std::size_t x = 1; x < func_map.size() - 1; x += 2)
        {
            above_curve.at(4) = (y_1) > func_map.at(x);
            above_curve.at(5) = (y_2) > func_map.at(x);
            above_curve.at(6) = (y_3) > func_map.at(x);
            above_curve.at(7) = (y_4) > func_map.at(x);
            above_curve.at(8) = (y_1) > func_map.at(x + 1);
            above_curve.at(9) = (y_2) > func_map.at(x + 1);
            above_curve.at(10) = (y_3) > func_map.at(x + 1);
            above_curve.at(11) = (y_4) > func_map.at(x + 1);

            int dot1 = above_curve.at(0) + above_curve.at(1) + above_curve.at(4) + above_curve.at(5);
            int dot2 = above_curve.at(1) + above_curve.at(2) + above_curve.at(5) + above_curve.at(6);
            int dot3 = above_curve.at(2) + above_curve.at(3) + above_curve.at(6) + above_curve.at(7);
            int dot4 = above_curve.at(4) + above_curve.at(5) + above_curve.at(8) + above_curve.at(9);
            int dot5 = above_curve.at(5) + above_curve.at(6) + above_curve.at(9) + above_curve.at(10);
            int dot6 = above_curve.at(6) + above_curve.at(7) + above_curve.at(10) + above_curve.at(11);

            int n {};

            if (dot1 > 0 and dot1 < 4) n += 1;
            if (dot2 > 0 and dot2 < 4) n += 2;
            if (dot3 > 0 and dot3 < 4) n += 4;
            if (dot4 > 0 and dot4 < 4) n += 8;
            if (dot5 > 0 and dot5 < 4) n += 16;
            if (dot6 > 0 and dot6 < 4) n += 32;

            std::string s;
            switch (n)
            {
                case  0: s = "\x1b[1C"; break; case  1: s = "⠁"; break;
                case  2: s = "⠂"; break;       case  3: s = "⠃"; break;
                case  4: s = "⠄"; break;       case  5: s = "⠅"; break;
                case  6: s = "⠆"; break;       case  7: s = "⠇"; break;
                case  8: s = "⠈"; break;       case  9: s = "⠉"; break;
                case 10: s = "⠊"; break;       case 11: s = "⠋"; break;
                case 12: s = "⠌"; break;       case 13: s = "⠍"; break;
                case 14: s = "⠎"; break;       case 15: s = "⠏"; break;
                case 16: s = "⠐"; break;       case 17: s = "⠑"; break;
                case 18: s = "⠒"; break;       case 19: s = "⠓"; break;
                case 20: s = "⠔"; break;       case 21: s = "⠕"; break;
                case 22: s = "⠖"; break;       case 23: s = "⠗"; break;
                case 24: s = "⠘"; break;       case 25: s = "⠙"; break;
                case 26: s = "⠚"; break;       case 27: s = "⠛"; break;
                case 28: s = "⠜"; break;       case 29: s = "⠝"; break;
                case 30: s = "⠞"; break;       case 31: s = "⠟"; break;
                case 32: s = "⠠"; break;       case 33: s = "⠡"; break;
                case 34: s = "⠢"; break;       case 35: s = "⠣"; break;
                case 36: s = "⠤"; break;       case 37: s = "⠥"; break;
                case 38: s = "⠦"; break;       case 39: s = "⠧"; break;
                case 40: s = "⠨"; break;       case 41: s = "⠩"; break;
                case 42: s = "⠪"; break;       case 43: s = "⠫"; break;
                case 44: s = "⠬"; break;       case 45: s = "⠭"; break;
                case 46: s = "⠮"; break;       case 47: s = "⠯"; break;
                case 48: s = "⠰"; break;       case 49: s = "⠱"; break;
                case 50: s = "⠲"; break;       case 51: s = "⠳"; break;
                case 52: s = "⠴"; break;       case 53: s = "⠵"; break;
                case 54: s = "⠶"; break;       case 55: s = "⠷"; break;
                case 56: s = "⠸"; break;       case 57: s = "⠹"; break;
                case 58: s = "⠺"; break;       case 59: s = "⠻"; break;
                case 60: s = "⠼"; break;       case 61: s = "⠽"; break;
                case 62: s = "⠾"; break;       case 63: s = "⠿"; break;
            }
            std::print("{}", s);

            above_curve.at(0) = above_curve.at(8);
            above_curve.at(1) = above_curve.at(9);
            above_curve.at(2) = above_curve.at(10);
            above_curve.at(3) = above_curve.at(11);
        }
    }
    std::print("\x1b[0m");
}


