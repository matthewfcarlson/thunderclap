#include "gen/owners.h"
class SeqEvent_2500e0 {
  public:
    virtual void V();
    SeqEvent_2500e0();
    int x;
};
class Part {
  public:
};
class SeqEventWait_2500e0 : public SeqEvent_2500e0 {
  public:
    Part part;
    SeqEventWait_2500e0();
    virtual void V();
};
SeqEventWait_2500e0::SeqEventWait_2500e0() {
    ((owners::String_23fc40 *)&part)->FUN_0023fc40("($= $myvar true)", (hulk_intptr)2);
}