#include "compat/ptr.h"
float __cdecl work(int, int, int, float, int, int, unsigned char, int);
class Obj {
    char pad[0x14];
    float factor;
    unsigned char mode;

  public:
    hulk_freg Run(int a, int b, int c, float value, int d, int e, unsigned char m, int p);
};
hulk_freg Obj::Run(int a, int b, int c, float value, int d, int e, unsigned char m, int p) {
    return work(a, b, c, value * factor * 0.001f, d, e, p == 0 ? mode : m, p);
}