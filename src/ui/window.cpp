#include <asciigraph/ui/window.hpp>
#include <sys/ioctl.h>

window::window() 
{
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    // newt.c_iflag &= ~(IXON | ICRNL);
    // newt.c_lflag &= ~(ICANON | ECHO | IEXTEN | ISIG);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &newt);
    this->set_dimensions();
}

window::~window()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &oldt);
}

void window::set_dimensions()
{
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
        dimensions = {24, 80};
    }
    dimensions = {w.ws_row, w.ws_col};
}