#include <asciigraph/function/function.hpp>
// #include <asciigraph/function_parser/function_parser.hpp> This is to be replaced
#include <asciigraph/ui/ui.hpp>
#include <memory>

int main(void)
{

    auto tui = std::make_unique<ui>();

    // tui->render_background();

    auto f
    {
            std::make_shared<f_gamma>(
                std::make_shared<f_var>()
            )
    };
    

    tui->render_function_2(f);

    tui->get_input();

    return 0;
}