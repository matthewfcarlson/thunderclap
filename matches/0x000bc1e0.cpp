#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_000fc280(int);
class Child {
  public:
};
class Obj {
  public:
    char a[0x10];
    int state;
    char b[0x1c];
    Child* ptr;
    char c[0x1cc8];
    int flag;
    void run(hulk_intptr);
    void f2(int);
};
void Obj::run(hulk_intptr arg) {
    if (state != 9) {
        state = 9;
        flag = 0;
        FUN_000fc280(arg);
        if (ptr) {
            ((owners::Target_863e0 *)ptr)->FUN_000863e0(6);
            f2(1);
        }
    }
}