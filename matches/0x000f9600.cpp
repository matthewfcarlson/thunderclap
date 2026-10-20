#include "compat/ptr.h"
struct Sub_f9600 {
    void Write(char* out, int a, int b, int c);
};
struct Owner_f9600 {
    char pad[0x284];
    Sub_f9600* sub;
    hulk_intptr Fn(hulk_intptr p);
};
hulk_intptr Owner_f9600::Fn(hulk_intptr p) {
    unsigned char tmp[4];
    sub->Write((char*)tmp + 3, 1, 1, 1);
    unsigned int n = tmp[3];
    sub->Write((char*)p, n, 1, 1);
    *((char*)p + n) = 0;
    return p;
}
