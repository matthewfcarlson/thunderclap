// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_000717e0 @ 0x000717e0
#include "decls/data/game/global.h"
#include "gen/fight.h"

extern "C" void* __cdecl FUN_0008d690(unsigned int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void __cdecl FUN_00068520();
void __cdecl FUN_00068530();
void __cdecl FUN_00068540();
class CDrainHealthTrack_717e0;
struct ParamBase_717e0 {
    virtual void slot0();
    char data[12];
};
namespace fight {
template<class T> struct ParamFloatConstRange_717e0 : ParamBase_717e0 {
    virtual void slot0();
    void (__cdecl *callback)();
    unsigned int tail;
};
}
void __cdecl FUN_002347b0(void*, void*, int);
extern "C" void __cdecl FUN_000717e0() {
    if (!DAT_004dcf7c) {
        fight::ParamFloatConstRange_717e0<CDrainHealthTrack_717e0>* params[3];
        const char* names[3] = {"timeBegin", "timeEnd", "damage"};
        void (__cdecl *callbacks[3])() = {FUN_00068520,FUN_00068530,FUN_00068540};
        for (int i=0;i<3;++i) {
            void* memory=FUN_0008d690(24);
            if (memory) {
                ((fight::ParamValueFloat *)(ParamBase_717e0 *)(((ParamBase_717e0*)memory)))->FUN_00234960(names[i]);
                params[i]=new(memory) fight::ParamFloatConstRange_717e0<CDrainHealthTrack_717e0>;
                params[i]->callback=callbacks[i];
            } else params[i]=0;
        }
        FUN_002347b0(&DAT_004dcf78,params,3);
    }
    ++DAT_004dcf7c;
}