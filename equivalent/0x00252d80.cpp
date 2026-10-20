// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::SeqEventVarTempoType::vfunc_3 @ 0x00252d80
#include "gen/audio.h"

#include "decls/data/engine/audio.h"

typedef unsigned int size_t;
inline void* operator new(size_t, void* p) throw() { return p; }
void* __cdecl FUN_00247530(void*);
namespace audio {
struct SeqEventVarTempo_252d80 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    int field4;
    int field8;
    int fieldc;
    float tempo;
    void FUN_0025fd00();
};

}
void* audio::SeqEventVarTempoType::vfunc_3() {
    void* memory = FUN_00247530(((char*)&DAT_004e6f88));
    if (!memory) return (void*)(0);
    ((SeqEventVarTempo_252d80*)memory)->FUN_0025fd00();
    SeqEventVarTempo_252d80* event = new(memory) SeqEventVarTempo_252d80;
    event->field8 = 4;
    event->fieldc = 4;
    event->tempo = 120.0f;
    return (void*)(event);
}
