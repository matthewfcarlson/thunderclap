#include "gen/audio.h"

extern char __cdecl ParseA(void*, void*);
extern char __cdecl ParseB(void*, void*);
extern char __cdecl ParseC(void*, void*);
class SeqEventStopTrack_250e00 : public audio::SeqEvent {
  public:
    char m8[4];
    char mC[4];
    char m10[12];
    virtual int vfunc_0(int*);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
int SeqEventStopTrack_250e00::vfunc_0(int* p) {
    if (((char)(audio::SeqEvent::vfunc_0(p)))) {
        if (ParseA(p, (char*)this + 8)) {
            if (ParseA(p, (char*)this + 12)) {
                if (ParseB(p, (char*)this + 16)) {
                    if (ParseC(p, (char*)this + 28))
                        return 1;
                }
            }
        }
    }
    return 0;
}