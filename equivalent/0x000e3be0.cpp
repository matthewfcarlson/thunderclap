// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// TextWindow::vfunc_12 @ 0x000e3be0
struct TextWindow {
    char pad[0x964];
    unsigned int limit;
    char pad2[4];
    unsigned int position;
    unsigned int end;
    unsigned int vfunc_12(unsigned int direction, unsigned int unused);
};
unsigned int TextWindow::vfunc_12(unsigned int direction, unsigned int unused)
{
    if (direction == 0) {
        unsigned int value = position;
        if (value != 0) {
            value--;
            position = value;
            return (value & 0xffffff00u) | 1;
        }
        return 0;
    }
    if (direction == 4) {
        unsigned int value = limit - 1;
        if (end != value) {
            value = position + 1;
            position = value;
            return (value & 0xffffff00u) | 1;
        }
        return value & 0xffffff00u;
    }
    return direction & 0xffffff00u;
}