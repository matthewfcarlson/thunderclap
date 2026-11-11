// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001899a0..0x0018b4e0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_faa02fd3 {
#define TREE_TU_END }
namespace fn_faa02fd3 {} using namespace fn_faa02fd3;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_faa02fd3 {
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void __cdecl SetAttachmentIndex_0017f430();
extern "C" void __cdecl SetCompare_0017f450();
extern "C" void __cdecl GetState_0017f460();
} // namespace fn_faa02fd3
namespace hulkfight { namespace motion {
class GrapplePropStateByNameCondition_189a50;
} }
namespace fn_faa02fd3 {
struct IntBase_189a50 { virtual void slot0(); char pad[12]; void (*callback)(); unsigned int tail; void FUN_002348e0(const char*); };
struct EnumBase_189a50 { virtual void slot0(); char pad[12]; void* list; unsigned int count; void (*callback)(); unsigned int tail; void FUN_00234cc0(const char*); };
struct NameBase_189a50 { virtual void slot0(); char pad[12]; void (*callback)(); unsigned int tail;  };
} // namespace fn_faa02fd3
namespace fight {
template<class T> struct ParamIntConstRange_189a50 : IntBase_189a50 { virtual void slot0(); };
}
namespace fight {
template<class T> struct ParamEnumConstList_189a50 : EnumBase_189a50 { virtual void slot0(); };
}
namespace fight {
template<class T> struct ParamName_189a50 : NameBase_189a50 { virtual void slot0(); };
}
namespace fn_faa02fd3 {
extern "C" void __cdecl FUN_002347b0(void*,void**,int);


// 0x00189a50 FUN_00189a50 (231 B): equivalent/0x00189a50.cpp
// sym: _FUN_00189a50
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 8/8)
// FUN_00189a50 @ 0x00189a50
extern "C" void __cdecl FUN_00189a50() {
 if (!DAT_004e1414) {
 void* params[3];
 IntBase_189a50* a=(IntBase_189a50*)FUN_0008d690((int)sizeof(fight::ParamIntConstRange_189a50<hulkfight::motion::GrapplePropStateByNameCondition_189a50>));
 if(a){ a->FUN_002348e0("attachmentIndex"); new(a) fight::ParamIntConstRange_189a50<hulkfight::motion::GrapplePropStateByNameCondition_189a50>; a->callback=SetAttachmentIndex_0017f430; } params[0]=a;
 EnumBase_189a50* b=(EnumBase_189a50*)FUN_0008d690((int)sizeof(fight::ParamEnumConstList_189a50<hulkfight::motion::GrapplePropStateByNameCondition_189a50>));
 if(b){ unsigned int count=(*(unsigned int*)&DAT_00427760); b->FUN_00234cc0("compare"); b->count=count; new(b) fight::ParamEnumConstList_189a50<hulkfight::motion::GrapplePropStateByNameCondition_189a50>; b->list=((unsigned int*)&DAT_00427758); b->callback=SetCompare_0017f450;} params[1]=b;
 NameBase_189a50* c=(NameBase_189a50*)FUN_0008d690((int)sizeof(fight::ParamName_189a50<hulkfight::motion::GrapplePropStateByNameCondition_189a50>));
 if(c){ ((fight::ParamValueName *)(NameBase_189a50 *)c)->FUN_00234a90("state"); new(c) fight::ParamName_189a50<hulkfight::motion::GrapplePropStateByNameCondition_189a50>; c->callback=GetState_0017f460;} params[2]=c;
 FUN_002347b0(((unsigned int*)&DAT_004e1410),params,3);
 }
 ++DAT_004e1414;
}

} // namespace fn_faa02fd3
