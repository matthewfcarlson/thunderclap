#include "gen/hulkfight.h"

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

void hulkfight::motion::GrappleExecuteTrack::FUN_00147800() {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_00413738);
    ((PartA_147800*)((char*)this + 0x24))->Init();
    ((PartB_147800*)((char*)this + 0x14))->Init();
    ((End_147800*)this)->Finish();
}
