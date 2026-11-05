#include "compat/ptr.h"
class Function {
  public:
    virtual void f();
    int a;
    int b;
    int c;
    Function(hulk_intptr x, int y);
};
Function::Function(hulk_intptr x, int y) {
    a = x;
    c = y;
    b = 0;
}