#include "decls/data/engine/audio.h"
// data: sClose = DAT_004298dc, sName_0042a238 = DAT_0042a238, sOpen = DAT_004298f4

struct Stm_253980 {
    char pad[0x24];
    int depth;
};
extern bool Match(Stm_253980*, const char*);
extern bool ReadTrack_00252470(Stm_253980**, const char*, void*);
class SeqEvent {
  public:
    virtual void v0();
    virtual bool v1(Stm_253980**);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class SeqEventVarPitch_253980 : public SeqEvent {
    char pad[8];

  public:
    int vfunc_1(Stm_253980**);
};
int SeqEventVarPitch_253980::vfunc_1(Stm_253980** p) {
    if (SeqEvent::v1(p)) {
        if (Match(*p, DAT_004298f4)) {
            (*p)->depth++;
            if (ReadTrack_00252470(p, DAT_0042a238, (char*)this + 8)) {
                (*p)->depth--;
                Stm_253980* s = *p;
                if (Match(s, DAT_004298dc))
                    return 1;
            }
        }
    }
    return 0;
}
