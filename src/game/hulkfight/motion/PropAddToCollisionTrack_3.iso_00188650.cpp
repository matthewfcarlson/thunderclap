// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00187340..0x00188ab0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAddToCollisionTrack
#include "tree_prelude.h"


// 0x00188650 FUN_00188650 (213 B): equivalent/0x00188650.cpp [isolated: helper definitions (2 out-of-line function bodies); compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: ?target@fn_fec23778@@YAXXZ
#include "gen/owners.h"
#include "decls/data/game/hulkfight/motion.h"
namespace fn_fec23778 {} using namespace fn_fec23778;
namespace fn_fec23778 {
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 8/8)
// FUN_00188650 @ 0x00188650

void* __cdecl FUN_0008d690(unsigned int);

} // namespace fn_fec23778
HULK_NATIVE_INLINE void* operator new(size_t, void* p) { return p; }
namespace fn_fec23778 {

void SetTimeBegin_001803e0(); void SetAttachmentIndex_00180400(); void SetDamage_00180420();
namespace hulkfight { namespace motion { class PropDamageTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void v0(); char data[12]; void (*callback)(); int tail;
 void FUN_00234960(const char*);
};
template<class T> struct ParamIntConstRange {
 virtual void v0(); char data[12]; void (*callback)(); int tail;
 void FUN_002348e0(const char*);
};
}
 
void __cdecl FUN_002347b0(void*,void**,int);
void target() {
 if (!DAT_004e14dc) {
 void* params[3];
 typedef fight::ParamFloatConstRange<hulkfight::motion::PropDamageTrack> F;
 typedef fight::ParamIntConstRange<hulkfight::motion::PropDamageTrack> I;
 F* a=(F*)FUN_0008d690((int)sizeof(F));
 if(a) { a->FUN_00234960("timeBegin"); new(a) F; a->callback=SetTimeBegin_001803e0; } params[0]=a;
 I* b=(I*)FUN_0008d690((int)sizeof(I));
 if(b) { b->FUN_002348e0("attachmentIndex"); new(b) I; b->callback=SetAttachmentIndex_00180400; } params[1]=b;
 F* c=(F*)FUN_0008d690((int)sizeof(F));
 if(c) { c->FUN_00234960("damage"); new(c) F; c->callback=SetDamage_00180420; } params[2]=c;
 FUN_002347b0(&DAT_004e14d8,params,3);
 }
 ++DAT_004e14dc;
}
} // namespace fn_fec23778

