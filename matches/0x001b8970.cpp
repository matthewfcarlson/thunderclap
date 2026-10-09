int FUN_001b8970(short *p, int limit)
{
    int i = 0;
    bool pending = false;
    int lines = 1;
    while (*p != 0) {
        if (pending) {
            if (*p == 0x20) {
                i = 0;
                pending = false;
                *p = 10;
                ++lines;
            }
        } else if (i > limit) {
            pending = true;
        } else {
            ++i;
        }
        ++p;
    }
    return lines;
}