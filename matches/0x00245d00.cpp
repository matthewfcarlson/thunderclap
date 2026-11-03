#include "gen/owners.h"
class X {
    char pad[0x90];

  public:
    int lines;
    unsigned int pos, end;
    void Skip(unsigned int);
};
void X::Skip(unsigned int n) {
    while (n) {
        if (pos < end) {
            if (((char)((owners::RingReader_245b70 *)this)->FUN_00245b70(pos)) == '\n')
                ++lines;
            ++pos;
        }
        --n;
    }
}