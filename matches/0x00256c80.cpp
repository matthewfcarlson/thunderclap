#include "compat/ptr.h"
extern "C" char DAT_0042a600[];
struct Sub_256c80 {
    void Init();
};
class SeqTrack {
  public:
    char pad[0x1c];
    SeqTrack* Build(unsigned char);
};
int __cdecl GetTrack();
void __cdecl Cleanup(int, SeqTrack*);
SeqTrack* SeqTrack::Build(unsigned char flags) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042a600);
    ((Sub_256c80*)((char*)this + 0x1c))->Init();
    if (flags & 1)
        Cleanup(GetTrack(), this);
    return this;
}