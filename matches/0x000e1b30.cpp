#include "compat/ptr.h"
extern "C" char DAT_0040c05c[];
class FEDoMenu {
  public:
    int a;
    int gap;
    int b;
    int c;
    int d;
    char e;
    char pad[31];
    int f;
    FEDoMenu(int x, const char* s);
};
extern void __cdecl FUN_000dfcc0(char*, int, const char*, ...);
FEDoMenu::FEDoMenu(int x, const char* s) {
    b = -1;
    c = -1;
    d = x;
    e = 0;
    a = ((hulk_intptr)DAT_0040c05c);
    FUN_000dfcc0((char*)this + 0x34, 0x20, "%s", s);
}