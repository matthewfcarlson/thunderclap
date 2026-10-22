#include "compat/ptr.h"
extern "C" char DAT_0041d3cc[];
class Sub_1aae10 {
  public:
    void Init();
};
class Condition_1aae10 {
  public:
    void Tail();
};
class Event_TriggerVolumeNameCondition : public Condition_1aae10 {
  public:
    void* vptr;
    char pad[0x0c];
    Sub_1aae10 sub;
    void Fn();
};
void Event_TriggerVolumeNameCondition::Fn() {
    vptr = (void*)((hulk_intptr)DAT_0041d3cc);
    sub.Init();
    Tail();
}