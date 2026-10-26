#include "decls/data/engine/audio.h"
// data: sClose = DAT_004298dc, sName_0042a108 = DAT_0042a108, sOpen = DAT_004298f4

struct Stm_253210 {
    char pad[0x24];
    int depth;
};
extern bool Match(Stm_253210*, const char*);
extern bool ReadTrack_002530b0(Stm_253210**, const char*, void*);
class SeqEvent {
  public:
    virtual void v0();
    virtual bool v1(Stm_253210**);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class SeqEventVarPosDist_253210 : public SeqEvent {
    char pad[8];

  public:
    int vfunc_1(Stm_253210**);
};
int SeqEventVarPosDist_253210::vfunc_1(Stm_253210** p) {
    if (SeqEvent::v1(p)) {
        if (Match(*p, DAT_004298f4)) {
            (*p)->depth++;
            if (ReadTrack_002530b0(p, DAT_0042a108, (char*)this + 8)) {
                (*p)->depth--;
                Stm_253210* s = *p;
                if (Match(s, DAT_004298dc))
                    return 1;
            }
        }
    }
    return 0;
}
