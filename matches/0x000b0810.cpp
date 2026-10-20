#include "compat/ptr.h"
extern char zero_b0810;
class Obj_b0810 {
  public:
    char pad[0x110];
    struct E {
        int count;
        hulk_intptr base;
    } e[11];
    char* get(int a, int b);
};
char* Obj_b0810::get(int a, int b) {
    if (a < 0 || a >= 11)
        return &zero_b0810;
    if (b >= 0 && b < e[a].count)
        return (char*)e[a].base + b * 32;
    return &zero_b0810;
}