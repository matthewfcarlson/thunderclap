// Same code shape as 0x000e1c40 (propagated; names are from that function)
#include "compat/ptr.h"
extern int vtable_e1c60;
class FEDoBackMenu_e1c60 {
  public:
    hulk_intptr vptr;
    int a;
    int b;
    int c;
    int d;
    char e;
    FEDoBackMenu_e1c60(int);
};
FEDoBackMenu_e1c60::FEDoBackMenu_e1c60(int x) {
    b = -1;
    c = -1;
    d = x;
    e = 0;
    vptr = (hulk_intptr)&vtable_e1c60;
}