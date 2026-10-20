#include "compat/ptr.h"
extern "C" char DAT_00429c8c[];
extern const char expr[];
class Base_2509c0 {
  public:
    Base_2509c0();
};
class Text_2509c0 {
  public:
    void Set(const char*, int);
};
class SeqEventExpression : public Base_2509c0 {
  public:
    int vptr;
    char pad[4];
    Text_2509c0 text;
    SeqEventExpression();
};
SeqEventExpression::SeqEventExpression() {
    vptr = ((hulk_intptr)DAT_00429c8c);
    text.Set(expr, 2);
}