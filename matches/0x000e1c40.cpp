#include "compat/ptr.h"
extern int vtable_e1c40;
class FEDoPopDialog {
  public:
    hulk_intptr vptr;
    int a;
    int b;
    int c;
    int d;
    char e;
    FEDoPopDialog(int);
};
FEDoPopDialog::FEDoPopDialog(int x) {
    b = -1;
    c = -1;
    d = x;
    e = 0;
    vptr = (hulk_intptr)&vtable_e1c40;
}