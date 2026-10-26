#include "decls/data/engine/audio.h"
// data: sClose = DAT_004298dc, sName = DAT_004298e0, sOpen = DAT_004298f4

struct Stm_24e760 {
    char pad[0x24];
    int depth;
};
extern bool Match(Stm_24e760*, const char*);
extern bool ReadTrack(Stm_24e760**, const char*, void*);
class SeqEvent {
  public:
    virtual void v0();
    virtual bool v1(Stm_24e760**);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class SeqEventNestTrack : public SeqEvent {
    char pad[8];

  public:
    int vfunc_1(Stm_24e760**);
};
int SeqEventNestTrack::vfunc_1(Stm_24e760** p) {
    if (SeqEvent::v1(p)) {
        if (Match(*p, DAT_004298f4)) {
            (*p)->depth++;
            if (ReadTrack(p, DAT_004298e0, (char*)this + 8)) {
                (*p)->depth--;
                Stm_24e760* s = *p;
                if (Match(s, DAT_004298dc))
                    return 1;
            }
        }
    }
    return 0;
}
