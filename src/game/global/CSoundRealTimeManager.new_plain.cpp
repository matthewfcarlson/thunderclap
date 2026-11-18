// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001eab10..0x001eecb0 (kind game, layer game, confidence high), dominant class CSoundRealTimeManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "game/script_bind.h"


// 0x001ee820 FUN_001ee820 (924 B): equivalent/0x001ee820.cpp [wrapped: macros; helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_001ee820@CSoundRealTimeManager@fn_001ee820@@QAEXXZ @e9ab6edc5143 @w3eb18e239fc6 @v19f2b956fc07
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
// (script1) the bound functions are include/game/script_bind.h's records with the game's vftables by address; the
// Closure3 is built in place by its out-of-line Method3 constructor 0x001edcf0, then the Closure3 vftable and the object.
struct Command { void* vftable; ScriptFunctionFields f; void (CSoundRealTimeManager::*method)(char*,char*,char*); CSoundRealTimeManager* object;
 void FUN_001edcf0(const char*, void (CSoundRealTimeManager::*)(char*,char*,char*)); };
extern "C" char DAT_00424358[], DAT_004243fc[];   // Method1 / Closure1<CSoundRealTimeManager,void,const char*>
extern "C" char DAT_00424378[], DAT_0042441c[];   // Method1 / Closure1<CSoundRealTimeManager,void,float>
extern "C" char DAT_00424388[], DAT_0042442c[];   // Method1 / Closure1<CSoundRealTimeManager,void,bool>
extern "C" char DAT_004243a8[], DAT_0042444c[];   // Method1 / Closure1<CSoundRealTimeManager,void,char*>
extern "C" char DAT_0042443c[];                   // Closure3<CSoundRealTimeManager,void,char*,char*,char*>
struct Registry {
 void FUN_001d3b70(const char*,void*);
 void FUN_001ee5b0(const char*,CSoundRealTimeManager*,void(CSoundRealTimeManager::*)());
};
extern "C" Registry* __cdecl FUN_001d4c90();
#define ADD1(N,A,F,MV,CV) { typedef hulk_script::ScriptClosure<hulk_script::ScriptMethod1<CSoundRealTimeManager,void,A>,CSoundRealTimeManager> Sized; HULK_SIZE32(Sized, 0x24); registry->FUN_001d3b70(N,new Sized(N,this,&CSoundRealTimeManager::F,MV,CV)); }
void CSoundRealTimeManager::FUN_001ee820() {
 owner->FUN_001f2c00(id);
 Registry* registry=FUN_001d4c90();
 ADD1("snd_TriggerMusic",const char*,FUN_001eb560,DAT_00424358,DAT_004243fc)
 registry->FUN_001ee5b0("snd_StopMusic",this,&CSoundRealTimeManager::FUN_001eb550);
 ADD1("snd_TriggerAmbience",const char*,FUN_001eb6c0,DAT_00424358,DAT_004243fc)
 ADD1("snd_SetMusicVolume",float,FUN_001eb130,DAT_00424378,DAT_0042441c)
 ADD1("snd_LockTransitions",bool,FUN_001eb140,DAT_00424388,DAT_0042442c)
 {HULK_SIZE32(Command, 0x24); Command* cmd=(Command*)FUN_0008d690((unsigned)sizeof(Command)); if(cmd) { cmd->FUN_001edcf0("snd_PlayDialogue",&CSoundRealTimeManager::FUN_001eb740); cmd->vftable=DAT_0042443c; cmd->object=this; } registry->FUN_001d3b70("snd_PlayDialogue",cmd);}
 ADD1("snd_InstallMix",char*,FUN_001eb8d0,DAT_004243a8,DAT_0042444c)
 ADD1("snd_InstallEffect",char*,FUN_001eb950,DAT_004243a8,DAT_0042444c)
 ADD1("snd_Set_UserHealthDown",float,FUN_001eb150,DAT_00424378,DAT_0042441c)
 ADD1("snd_Set_UserHealthNearDeath",float,FUN_001eb160,DAT_00424378,DAT_0042441c)
 registry->FUN_001ee5b0("snd_Mute",this,&CSoundRealTimeManager::FUN_001eb870);
 registry->FUN_001ee5b0("snd_UnMute",this,&CSoundRealTimeManager::FUN_001eb890);
}
} // namespace fn_001ee820
#undef ADD1
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

