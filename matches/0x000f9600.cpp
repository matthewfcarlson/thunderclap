#include "compat/ptr.h"
#include "gen/owners.h"
struct Sub_f9600 {
};
struct Owner_f9600 {
    char pad[0x284];
    Sub_f9600* sub;
    hulk_intptr Fn(hulk_intptr p);
};
hulk_intptr Owner_f9600::Fn(hulk_intptr p) {
    unsigned char tmp[4];
    ((owners::X_2647e0 *)sub)->FUN_002647e0((hulk_intptr)((char*)tmp + 3), (hulk_intptr)1, 1, (hulk_intptr)1);
    unsigned int n = tmp[3];
    ((owners::X_2647e0 *)sub)->FUN_002647e0((hulk_intptr)((char*)p), (hulk_intptr)n, 1, (hulk_intptr)1);
    *((char*)p + n) = 0;
    return p;
}
