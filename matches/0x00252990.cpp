#include "decls/data/engine/audio.h"
// data: sClose = DAT_004298dc, sName_00429ff0 = DAT_00429ff0, sOpen = DAT_004298f4

struct Stm_252990 {
    char pad[0x24];
    int depth;
};
extern bool Match(Stm_252990*, const char*);
extern bool ReadTrack_00252470(Stm_252990**, const char*, void*);
class SeqEvent {
  public:
    virtual void v0();
    virtual bool v1(Stm_252990**);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class SeqEventVarVolume_252990 : public SeqEvent {
    char pad[8];

  public:
    int vfunc_1(Stm_252990**);
};
int SeqEventVarVolume_252990::vfunc_1(Stm_252990** p) {
    if (SeqEvent::v1(p)) {
        if (Match(*p, DAT_004298f4)) {
            (*p)->depth++;
            if (ReadTrack_00252470(p, DAT_00429ff0, (char*)this + 8)) {
                (*p)->depth--;
                Stm_252990* s = *p;
                if (Match(s, DAT_004298dc))
                    return 1;
            }
        }
    }
    return 0;
}
