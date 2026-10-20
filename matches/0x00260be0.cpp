#include "compat/ptr.h"
extern "C" int sprintf(char*, const char*, ...);
class Owner_260be0 {
  public:
    char pad[0x2004];
    int offset;
};
int FUN_00260be0(Owner_260be0* owner, float value) {
    char buffer[256];
    int i = sprintf(buffer, "%f", (double)value);
    --i;
    if (i != 0) {
        do {
            if (buffer[i] != '0') {
                if (buffer[i] == '.')
                    buffer[i] = 0;
                else
                    buffer[i + 1] = 0;
                break;
            }
            --i;
        } while (i != 0);
    }
    int pos = owner->offset;
    owner->offset = pos + i + 1;
    char* src = buffer;
    char c;
    do {
        c = *src;
        src[pos - (hulk_intptr)buffer] = c;
        ++src;
    } while (c);
    return pos;
}