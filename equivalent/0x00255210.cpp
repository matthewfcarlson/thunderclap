// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::SeqEventLogicOr::vfunc_2 @ 0x00255210
#include "decls/data/engine/audio.h"

typedef unsigned int size_t;
inline void* __cdecl operator new(size_t, void* ptr) { return ptr; }
void* __cdecl FUN_00247530(void*);
struct SeqEventLogicOr;
struct SeqCommandLogicOr {
    virtual void vfunc_0();
    virtual void vfunc_1();
    char reserved[4];
    SeqEventLogicOr* event;
};
struct Context { void FUN_0025dba0(SeqCommandLogicOr*); };
struct SeqEventLogicOr {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(Context* context);
};
void SeqEventLogicOr::vfunc_2(Context* context) {
    SeqCommandLogicOr* command = (SeqCommandLogicOr*)FUN_00247530(((char*)&DAT_004e7410));
    if (command) {
        new(command) SeqCommandLogicOr;
        command->event = this;
    }
    context->FUN_0025dba0(command);
}