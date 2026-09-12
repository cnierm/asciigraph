#include <termios.h>
#include <unistd.h>

class window
{
private:
    struct termios oldt;
    struct termios newt;
public:
    struct { int rows; int cols; } dimensions;

    window();

    ~window();

    void set_dimensions();
};