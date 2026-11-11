// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001ef470..0x001ef4f0 (kind game, layer game, confidence medium), dominant class CSoundCommand_PlayInterruptEvent
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f825b68b {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f825b68b {} using namespace fn_f825b68b;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f825b68b {
struct SoundHandle {
    void FUN_001f3370(void *params);
};
struct SoundBank_1ef470 {
    void FUN_001f47b0(int arg);
    SoundHandle *FUN_001f2f30(void *event, int arg);
};
struct EventTable {
    void *FUN_001e98b0(void *key);
};
struct SoundSystem_1ef470 {
    SoundBank_1ef470 *bank;
    EventTable *events;
};
class CSoundCommand_PlayInterruptEvent {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(int arg, int unused);

    char pad4[0xc];
    char key[8];      // +0x10
    char params[8];   // +0x18
};


// 0x001ef470 CSoundCommand_PlayInterruptEvent::vfunc_1 (123 B): equivalent/0x001ef470.cpp
// sym: ?vfunc_1@CSoundCommand_PlayInterruptEvent@fn_f825b68b@@UAEXHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// CSoundCommand_PlayInterruptEvent::vfunc_1 @ 0x001ef470
void CSoundCommand_PlayInterruptEvent::vfunc_1(int arg, int unused) {
    DAT_004e371c++;
    (*(SoundSystem_1ef470**)&DAT_004e370c)->bank->FUN_001f47b0(arg);
    void *event = (*(SoundSystem_1ef470**)&DAT_004e370c)->events->FUN_001e98b0(key);
    if (event == 0) {
        DAT_004e3720++;
        return;
    }
    SoundHandle *handle = (*(SoundSystem_1ef470**)&DAT_004e370c)->bank->FUN_001f2f30(event, arg);
    if (handle != 0) {
        handle->FUN_001f3370(params);
        return;
    }
    DAT_004e3724++;
}

} // namespace fn_f825b68b
