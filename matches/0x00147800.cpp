#include "compat/ptr.h"
extern "C" char DAT_00413738[];
struct PartA_147800 {
    void Init();
};
struct PartB_147800 {
    void Init();
};
struct End_147800 {
    void Finish();
};
class GrappleExecuteTrack {
  public:
    virtual void v0();
    char pad4[0x10];
    PartB_147800 p14;
    char pad18[0x0c];
    PartA_147800 p24;
    void Run();
};
void GrappleExecuteTrack::Run() {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_00413738);
    ((PartA_147800*)((char*)this + 0x24))->Init();
    ((PartB_147800*)((char*)this + 0x14))->Init();
    ((End_147800*)this)->Finish();
}
