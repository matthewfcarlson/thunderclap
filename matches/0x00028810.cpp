#include "compat/ptr.h"
struct Result {
    char pad[0x1cee];
    unsigned char flag;
};
class Obj {
  public:
    Result* get(__int64);
    void fn(int, unsigned char);
};
extern "C" __int64 __cdecl make(int, int, hulk_intptr);
void Obj::fn(int a, unsigned char b) {
    Result* p = get(make(a, 0, 0));
    if (p)
        p->flag = b;
}