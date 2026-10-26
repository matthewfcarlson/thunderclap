#include "decls/data/engine/audio.h"
// data: sClose_0042a2c8 = DAT_0042a2c8, sName_0042a2cc = DAT_0042a2cc, sOpen = DAT_004298f4

struct Stm_254190 {
    char pad[0x24];
    int depth;
};
extern bool Match(Stm_254190*, const char*);
extern bool ReadTrack_00254000(Stm_254190**, const char*, void*);
class SeqEvent {
  public:
    virtual void v0();
    virtual bool v1(Stm_254190**);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class SeqEventStream_254190 : public SeqEvent {
    char pad[8];

  public:
    int vfunc_1(Stm_254190**);
};
int SeqEventStream_254190::vfunc_1(Stm_254190** p) {
    if (SeqEvent::v1(p)) {
        if (Match(*p, DAT_004298f4)) {
            (*p)->depth++;
            if (ReadTrack_00254000(p, DAT_0042a2cc, (char*)this + 8)) {
                (*p)->depth--;
                Stm_254190* s = *p;
                if (Match(s, DAT_0042a2c8))
                    return 1;
            }
        }
    }
    return 0;
}
