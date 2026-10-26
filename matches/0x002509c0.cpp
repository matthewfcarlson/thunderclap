#include "decls/data/engine/audio.h"
// data: expr = DAT_00429ca4

#include "compat/ptr.h"
extern "C" char DAT_00429c8c[];
class SeqEvent_2509c0 {
  public:
    SeqEvent_2509c0();
};
class Text_2509c0 {
  public:
    void Set(const char*, int);
};
class SeqEventExpression : public SeqEvent_2509c0 {
  public:
    hulk_intptr vptr;
    char pad[4];
    Text_2509c0 text;
    SeqEventExpression();
};
SeqEventExpression::SeqEventExpression() {
    vptr = ((hulk_intptr)DAT_00429c8c);
    text.Set(DAT_00429ca4, 2);
}