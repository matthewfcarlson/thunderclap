#include "compat/ptr.h"
extern "C" char DAT_003f9980[];
class Helper_5abb0 {
  public:
    void Init();
    void Finish();
};
class CGrappleSwapTrack {
  public:
    char pad[0x10];
    int member10, member14, member18;
    void Run();
};
void CGrappleSwapTrack::Run() {
    *(void**)this = (void*)((hulk_intptr)DAT_003f9980);
    ((Helper_5abb0*)((char*)this + 0x18))->Init();
    ((Helper_5abb0*)((char*)this + 0x10))->Init();
    ((Helper_5abb0*)this)->Finish();
}