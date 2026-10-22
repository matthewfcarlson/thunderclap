#include "compat/ptr.h"
extern "C" char DAT_00410bd4[];
class Sub_12b410 {
  public:
    void Init();
};
class ThreatDistanceCondition_12b410 {
  public:
    void Finish();
};
class ThreatCondition {
  public:
    void Run();
};
void ThreatCondition::Run() {
    *(void**)this = (void*)((hulk_intptr)DAT_00410bd4);
    ((Sub_12b410*)((char*)this + 0x10))->Init();
    ((ThreatDistanceCondition_12b410*)this)->Finish();
}
