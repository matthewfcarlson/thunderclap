#include "decls/data/engine/audio.h"
// data: expr = DAT_00429ca4

#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" char DAT_00429c8c[];
class SeqEvent_2509c0 {
  public:
    SeqEvent_2509c0();
};
class Text_2509c0 {
  public:
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
    ((owners::String_23fc40 *)&text)->FUN_0023fc40(DAT_00429ca4, (hulk_intptr)2);
}