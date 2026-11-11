// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001eab10..0x001eecb0 (kind game, layer game, confidence high), dominant class CSoundRealTimeManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"


// 0x001ee820 FUN_001ee820 (924 B): equivalent/0x001ee820.cpp [wrapped: macros; helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_001ee820@CSoundRealTimeManager@fn_001ee820@@QAEXXZ
HULK_NATIVE_INLINE void* __cdecl operator new(hulk_uintptr, void* p) { return p; }
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_001ee820 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_001ee820 @ 0x001ee820
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)


extern "C" void* __cdecl FUN_0008d690(unsigned);
struct Owner { void FUN_001f2c00(unsigned); };
class CSoundRealTimeManager { public:
 Owner* owner; unsigned id;
 void FUN_001ee820();
 void FUN_001eb550(); void FUN_001eb560(const char*); void FUN_001eb6c0(const char*);
 void FUN_001eb130(float); void FUN_001eb140(bool); void FUN_001eb150(float); void FUN_001eb160(float);
 void FUN_001eb740(char*,char*,char*); void FUN_001eb870(); void FUN_001eb890(); void FUN_001eb8d0(char*); void FUN_001eb950(char*);
};
// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct __declspec(novtable) Command : public ScriptFunctionFields {
 virtual void slot0();
 void FUN_001d0480(const char*,int);
 void FUN_001edcf0(const char*, void (CSoundRealTimeManager::*)(char*,char*,char*));
 Command(const char* name) { FUN_001d0480(name,1); }
 Command(const char* name,void(CSoundRealTimeManager::*fn)(char*,char*,char*)) { FUN_001edcf0(name,fn); }
};
template<class C,class R,class A> class Method1: public Command { public:
 void (C::*method)(A);
 virtual void slot0();
 Method1(const char* name,void(C::*fn)(A),const void* type):Command(name) {
 method=fn; retType=FUN_001d04d0(((int*)&DAT_0048e100)); argTypes[0]=FUN_001d04d0(type);
 }
};
template<class C,class R,class A> class Closure1: public Method1<C,R,A> { public:
 C* object; virtual void slot0();
 Closure1(const char* name,C* obj,void(C::*fn)(A),const void* type):Method1<C,R,A>(name,fn,type) {object=obj;}
};
template<class C,class R,class A,class B,class D> class Closure3: public Command { public:
 void(C::*method)(A,B,D); C* object; virtual void slot0();
 Closure3(const char* name,C* obj,void(C::*fn)(A,B,D)):Command(name,fn) {object=obj;}
};
struct Registry {
 void FUN_001d3b70(const char*,Command*);
 void FUN_001ee5b0(const char*,CSoundRealTimeManager*,void(CSoundRealTimeManager::*)());
};
extern "C" Registry* __cdecl FUN_001d4c90();
#define ADD1(N,A,F,T) { typedef Closure1<CSoundRealTimeManager,void,A> Sized; HULK_SIZE32(Sized, 0x24); void* mem=FUN_0008d690((unsigned)sizeof(Sized)); Command* cmd=0; if(mem) cmd=new(mem) Closure1<CSoundRealTimeManager,void,A>(N,this,&CSoundRealTimeManager::F,&T); registry->FUN_001d3b70(N,cmd); }
void CSoundRealTimeManager::FUN_001ee820() {
 owner->FUN_001f2c00(id);
 Registry* registry=FUN_001d4c90();
 ADD1("snd_TriggerMusic",const char*,FUN_001eb560,(*(int*)&DAT_0048e0f0))
 registry->FUN_001ee5b0("snd_StopMusic",this,&CSoundRealTimeManager::FUN_001eb550);
 ADD1("snd_TriggerAmbience",const char*,FUN_001eb6c0,(*(int*)&DAT_0048e0f0))
 ADD1("snd_SetMusicVolume",float,FUN_001eb130,(*(int*)&DAT_0048e128))
 ADD1("snd_LockTransitions",bool,FUN_001eb140,(*(int*)&DAT_0048e0e4))
 {typedef Closure3<CSoundRealTimeManager,void,char*,char*,char*> Sized; HULK_SIZE32(Sized, 0x24); void* mem=FUN_0008d690((unsigned)sizeof(Sized)); Command* cmd=0; if(mem) cmd=new(mem) Sized("snd_PlayDialogue",this,&CSoundRealTimeManager::FUN_001eb740); registry->FUN_001d3b70("snd_PlayDialogue",cmd);}
 ADD1("snd_InstallMix",char*,FUN_001eb8d0,(*(int*)&DAT_0049cad8))
 ADD1("snd_InstallEffect",char*,FUN_001eb950,(*(int*)&DAT_0049cad8))
 ADD1("snd_Set_UserHealthDown",float,FUN_001eb150,(*(int*)&DAT_0048e128))
 ADD1("snd_Set_UserHealthNearDeath",float,FUN_001eb160,(*(int*)&DAT_0048e128))
 registry->FUN_001ee5b0("snd_Mute",this,&CSoundRealTimeManager::FUN_001eb870);
 registry->FUN_001ee5b0("snd_UnMute",this,&CSoundRealTimeManager::FUN_001eb890);
}
} // namespace fn_001ee820
#undef ADD1
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

