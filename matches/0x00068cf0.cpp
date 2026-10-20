#include "compat/ptr.h"
extern "C" char DAT_003f98d0[];
extern "C" char DAT_003fb9c4[];
class Part_68cf0 {
  public:
    void Init();
};
class CJointTrack {
  public:
    char pad[0x18];
    Part_68cf0 part;
    void Finish();
    void Init();
};
void CJointTrack::Init() {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_003fb9c4);
    part.Init();
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_003f98d0);
    Finish();
}
