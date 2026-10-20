// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_000717e0 @ 0x000717e0
#include "compat/ptr.h"
#include "decls/data/game/global.h"

void* __cdecl FUN_0008d690(hulk_uintptr);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void __cdecl FUN_00068520();
void __cdecl FUN_00068530();
void __cdecl FUN_00068540();
class CDrainHealthTrack;
struct ParamBase_717e0 {
    virtual void slot0();
    char data[12];
    void FUN_00234960(const char*);
};
namespace fight {
template<class T> struct ParamFloatConstRange : ParamBase_717e0 {
    virtual void slot0();
    void (__cdecl *callback)();
    unsigned int tail;
};
}
void __cdecl FUN_002347b0(void*, void*, int);
void __cdecl FUN_000717e0() {
    if (!DAT_004dcf7c) {
        fight::ParamFloatConstRange<CDrainHealthTrack>* params[3];
        const char* names[3] = {"timeBegin", "timeEnd", "damage"};
        void (__cdecl *callbacks[3])() = {FUN_00068520,FUN_00068530,FUN_00068540};
        for (int i=0;i<3;++i) {
            void* memory=FUN_0008d690(24);
            if (memory) {
                ((ParamBase_717e0*)memory)->FUN_00234960(names[i]);
                params[i]=new(memory) fight::ParamFloatConstRange<CDrainHealthTrack>;
                params[i]->callback=callbacks[i];
            } else params[i]=0;
        }
        FUN_002347b0(&DAT_004dcf78,params,3);
    }
    ++DAT_004dcf7c;
}