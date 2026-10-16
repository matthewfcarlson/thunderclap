// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 8/8)
// FUN_00189a50 @ 0x00189a50
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

typedef unsigned int size_t;
inline void* __cdecl operator new(size_t, void* p) { return p; }
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void __cdecl FUN_0017f430();
extern "C" void __cdecl FUN_0017f450();
extern "C" void __cdecl FUN_0017f460();
namespace hulkfight { namespace motion { class GrapplePropStateByNameCondition; } }
struct IntBase_189a50 { virtual void slot0(); char pad[12]; void (*callback)(); unsigned int tail; void FUN_002348e0(const char*); };
struct EnumBase_189a50 { virtual void slot0(); char pad[12]; void* list; unsigned int count; void (*callback)(); unsigned int tail; void FUN_00234cc0(const char*); };
struct NameBase_189a50 { virtual void slot0(); char pad[12]; void (*callback)(); unsigned int tail; void FUN_00234a90(const char*); };
namespace fight {
template<class T> struct ParamIntConstRange : IntBase_189a50 { virtual void slot0(); };
template<class T> struct ParamEnumConstList : EnumBase_189a50 { virtual void slot0(); };
template<class T> struct ParamName : NameBase_189a50 { virtual void slot0(); };
}
extern "C" void __cdecl FUN_002347b0(void*,void**,int);
void __cdecl FUN_00189a50() {
 if (!DAT_004e1414) {
 void* params[3];
 IntBase_189a50* a=(IntBase_189a50*)FUN_0008d690(24);
 if(a){ a->FUN_002348e0("attachmentIndex"); new(a) fight::ParamIntConstRange<hulkfight::motion::GrapplePropStateByNameCondition>; a->callback=FUN_0017f430; } params[0]=a;
 EnumBase_189a50* b=(EnumBase_189a50*)FUN_0008d690(32);
 if(b){ unsigned int count=(*(unsigned int*)&DAT_00427760); b->FUN_00234cc0("compare"); b->count=count; new(b) fight::ParamEnumConstList<hulkfight::motion::GrapplePropStateByNameCondition>; b->list=((unsigned int*)&DAT_00427758); b->callback=FUN_0017f450;} params[1]=b;
 NameBase_189a50* c=(NameBase_189a50*)FUN_0008d690(24);
 if(c){ c->FUN_00234a90("state"); new(c) fight::ParamName<hulkfight::motion::GrapplePropStateByNameCondition>; c->callback=FUN_0017f460;} params[2]=c;
 FUN_002347b0(((unsigned int*)&DAT_004e1410),params,3);
 }
 ++DAT_004e1414;
}