// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001e8c20..0x001e9de0 (kind game, layer game, confidence high), dominant class CSoundSequence
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/content.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9024596 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9024596 {} using namespace fn_f9024596;
#include "game/global.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl sprintf(char *, const char *, ...);
#endif
namespace fn_f9024596 {
struct Manager_1e8d40 { void FUN_00265920(char *, int *, int); };
struct Controller_1e95c0 { bool FUN_00266750(); void FUN_00263e90(); };
struct Subsystem_1e95c0 {  };
} // namespace fn_f9024596
struct World { char pad[0x54]; Subsystem_1e95c0* subsystem; };
namespace fn_f9024596 {
extern "C" int __cdecl FUN_00240750();
extern "C" void __cdecl FUN_00243090(int, float);
struct Entry_1e95c0 { int state; };
struct Target_1e95c0 { char pad[0x19c]; Entry_1e95c0* entries[200]; int count; void FUN_002696a0(); void update(float time, bool active); };
struct IdPair_1e9960 {
    unsigned int lo;
    unsigned int hi;
};
struct Resource_1e9960 {
};
struct Slot_1e9960 {
    char pad00[8];
    Resource_1e9960 *resource;
};
class Registry_1e9960 {
public:
    char pad00[0x4c0];
    Slot_1e9960 *slots[20];
    int count;

    Slot_1e9960 *FUN_001e9960(const char *name);
};

} // namespace fn_f9024596

// 0x001e8d40 FUN_001e8d40 (183 B): equivalent/0x001e8d40.cpp
// sym: ?FUN_001e8d40@Clip_1e8d40@owners@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 20019 inputs, branch coverage 11/12, incomplete)
// FUN_001e8d40 @ 0x001e8d40
void owners::Clip_1e8d40::FUN_001e8d40() {
 if (active == 0 && (*(hulk_intptr*)&DAT_004e3694) == 0) {
 char name[16];
 sprintf(name, "%d.%s", this, "clips");
 (*(Manager_1e8d40**)&DAT_00527c58)->FUN_00265920(name, ((int*)&DAT_004e3694), 1);
 unsigned int type = kind;
 active = 1;
 double amount = (int)size;
 if ((int)size < 0) amount += 4294967296.0f;
 if (type > 0) DAT_004e369c = amount + DAT_004e369c;
 else DAT_004e36a0 = amount + DAT_004e36a0;
 }
}

namespace fn_f9024596 {

// 0x001e95c0 FUN_001e95c0 (185 B): equivalent/0x001e95c0.cpp
// sym: ?update@Target_1e95c0@fn_f9024596@@QAEXM_N@Z
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 16/16)
// FUN_001e95c0 @ 0x001e95c0
void Target_1e95c0::update(float time, bool active) {
 char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
 FUN_002696a0();
 FUN_00240bb0();
 FUN_00243090(FUN_00240750(), time * 1000.0f);
 if (DAT_004dd700 && DAT_004dd700->subsystem) ((owners::Target_862a0 *)(DAT_004dd700->subsystem))->FUN_000862a0();
 if (active) {
 for(int i=0;i<count;++i) {
 Entry_1e95c0* entry=entries[i];
 if(entry && entry->state==1 && (*(Controller_1e95c0**)&DAT_004e3694)->FUN_00266750()) {
 entry->state=3;
 (*(Controller_1e95c0**)&DAT_004e3694)->FUN_00263e90();
 (*(Controller_1e95c0**)&DAT_004e3694)=0;
 }
 }
 }
}


// 0x001e9960 FUN_001e9960 (296 B): equivalent/0x001e9960.cpp
// sym: ?FUN_001e9960@Registry_1e9960@fn_f9024596@@QAEPAUSlot_1e9960@2@PBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 9159 inputs, branch coverage 18/18)
// FUN_001e9960 @ 0x001e9960
// Looks a slot up by its resource name hashed with a ".Mix" suffix.
Slot_1e9960 *Registry_1e9960::FUN_001e9960(const char *name)
{
    struct Frame {
        char buf[0x20];
    } fr = { "" };
    Registry_1e9960 *self = this;
    if (!name || *name == 0) {
        return 0;
    }
    strcpy(fr.buf, name);
    strcat(fr.buf, ".Mix");
    for (int i = 0; i < count; i++) {
        if (slots[i]) {
            unsigned __int64 id = FUN_002672f0(fr.buf, 0, 0);
            IdPair_1e9960 *found = ((IdPair_1e9960 *)((owners::CFightParamsCollision_243390 *)(slots[i]->resource))->FUN_00243390());
            if (found->lo == (unsigned int)id && found->hi == (unsigned int)(id >> 32)) {
                return self->slots[i];
            }
        }
    }
    return 0;
}

} // namespace fn_f9024596
