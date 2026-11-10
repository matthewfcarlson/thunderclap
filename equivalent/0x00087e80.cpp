// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_00087e80 @ 0x00087e80
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
namespace math { class Vector_87e80 { public: float x, y, z; }; }
// CGame and the two members it binds to Lua (Quit, fe_restart: Closure0<CGame, void> through the helper 0x00087dc0);
// complete before any pointer to a member is formed (one code pointer on every build).
extern "C" char DAT_003ffab4[];  // CGame's vftable
extern "C" char DAT_003ffb50[];  // Function2<float, float, float>'s
extern "C" char DAT_003ffb70[];  // Function2<const char*, const char*, const char*>'s
struct CGame { void* vftable; int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s; unsigned char flag; CGame(); void FUN_00086a10(); void FUN_000861f0(); };
// The free functions bound as Function<N> (0x00086fa0's Invoke calls them __cdecl): their real types are the game's
// Function<N> instantiations.
float __cdecl FUN_000964e0();
float __cdecl FUN_00096540(float, float);
extern "C" const char* __cdecl FUN_00096ed0(const char*, const char*);
const char* __cdecl FUN_00096f10(const char*);
bool __cdecl FUN_00096f40(math::Vector_87e80, math::Vector_87e80, math::Vector_87e80, math::Vector_87e80);

struct Registry_87e80 { void FUN_00087dc0(const char*, CGame*, void (CGame::*)()); void FUN_00087a90(const char*, float (__cdecl*)()); void FUN_00087b40(const char*, const char* (__cdecl*)(const char*)); void FUN_001d3b70(const char*,void*); };
extern "C" Registry_87e80* __cdecl FUN_001d4c90(); extern "C" void* __cdecl FUN_0008d690(unsigned);
// Function's fields (include/decls/data/script.h) after the vftable; Function<N> keeps the bound free function after
// them. The vftables are the game's (stored by address: a local class's own vftable would be the 64-bit link's stub).
struct FunctionBase_87e80 { void* vftable; ScriptFunctionFields f; void FUN_001d0480(const char*,int); };
struct Function4_87e80 : FunctionBase_87e80 { bool (__cdecl* callback)(math::Vector_87e80, math::Vector_87e80, math::Vector_87e80, math::Vector_87e80); void* FUN_00086fc0(const char*, bool (__cdecl*)(math::Vector_87e80, math::Vector_87e80, math::Vector_87e80, math::Vector_87e80)); };
template<class R,class A,class B> struct Function2 : FunctionBase_87e80 { R (__cdecl* callback)(A, B); };
CGame::CGame() { vftable=(void*)DAT_003ffab4; a=b=0; d=e=f=g=h=i=j=k=l=m=n=o=p=q=r=s=0; flag=0; Registry_87e80* reg=FUN_001d4c90(); typedef Function2<float,float,float> Alloc1_87e80; HULK_SIZE32(Alloc1_87e80,0x20); typedef Function2<const char*,const char*,const char*> Alloc2_87e80; HULK_SIZE32(Alloc2_87e80,0x20); HULK_SIZE32(Function4_87e80,0x20); reg->FUN_00087dc0("Quit",this,&CGame::FUN_00086a10); reg->FUN_00087a90("util_GetRandomFloat",FUN_000964e0); Function2<float,float,float>* one=(Function2<float,float,float>*)FUN_0008d690((int)sizeof(Function2<float,float,float>)); if(one) { one->FUN_001d0480("util_GetWorldOrientation",2); one->vftable=(void*)DAT_003ffb50; one->callback=FUN_00096540; one->f.retType=FUN_001d04d0(((int*)&DAT_0048e128)); one->f.argTypes[0]=FUN_001d04d0(((int*)&DAT_0048e128)); one->f.argTypes[1]=FUN_001d04d0(((int*)&DAT_0048e128)); } reg->FUN_001d3b70("util_GetWorldOrientation",one); reg->FUN_00087b40("util_MakeUID",FUN_00096f10); Function2<const char*,const char*,const char*>* two=(Function2<const char*,const char*,const char*>*)FUN_0008d690((int)sizeof(Function2<const char*,const char*,const char*>)); if(two) { two->FUN_001d0480("util_AppendToUID",2); two->vftable=(void*)DAT_003ffb70; two->callback=FUN_00096ed0; two->f.retType=FUN_001d04d0(((int*)&DAT_0048e0f0)); two->f.argTypes[0]=FUN_001d04d0(((int*)&DAT_0048e0f0)); two->f.argTypes[1]=FUN_001d04d0(((int*)&DAT_0048e0f0)); } reg->FUN_001d3b70("util_AppendToUID",two); Function4_87e80* three=(Function4_87e80*)FUN_0008d690((int)sizeof(Function4_87e80)); void* result=0; if(three) result=three->FUN_00086fc0("hack_IsFieldGoal",FUN_00096f40); reg->FUN_001d3b70("hack_IsFieldGoal",result); reg->FUN_00087dc0("fe_restart",this,&CGame::FUN_000861f0); }
