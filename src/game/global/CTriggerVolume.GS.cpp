// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001fb3f0..0x001fc600 (kind game, layer game, confidence high), dominant class CTriggerVolume
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f9c1dcf2 {
#define TREE_TU_END }
namespace fn_f9c1dcf2 {} using namespace fn_f9c1dcf2;
#include "game/global.h"


// 0x001fb5a0 CTriggerVolume::vfunc_13 (253 B): equivalent/0x001fb5a0.cpp [wrapped: conflict: CTriggerVolume]
// sym: ?vfunc_13@CTriggerVolume@fn_001fb5a0@@UAEXPAUInput_1fb5a0@2@@Z @c09d7450bf96 @wffc7320954ce
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_001fb5a0 {
// STATUS: equivalent (tools/equiv.py level 3: 10484 inputs, branch coverage 6/6)
// CTriggerVolume::vfunc_13 @ 0x001fb5a0
// cl-flags: /GS
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

struct Input_1fb5a0 { char pad[8]; unsigned a,b; unsigned *value; unsigned FUN_00036d00(); };
struct Packet_1fb5a0 { unsigned type; char text[64]; char rest[628]; void FUN_001d1630(); };
struct Message_1fb5a0 { char data[84]; void FUN_001caf80(const char*,unsigned); };
struct Manager_1fb5a0 { void FUN_001d3b00(const char*,Packet_1fb5a0); };
struct Receiver_1fb5a0 { void FUN_001cbc20(Message_1fb5a0*); };
struct World { char pad[48]; Receiver_1fb5a0* receiver; };
extern Manager_1fb5a0* __cdecl FUN_001d4c90();
extern int __cdecl _sprintf(char*,const char*,...);
extern int __cdecl FUN_000964a0(char*,unsigned,const char*,...);
struct CTriggerVolume { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(unsigned,unsigned,int); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(Input_1fb5a0*); char pad[140]; char name[1]; };
void CTriggerVolume::vfunc_13(Input_1fb5a0* input) {
 vfunc_9(input->a,input->b,1);
 Manager_1fb5a0* manager=FUN_001d4c90();
 if(manager) {
 char eventName[256]; _sprintf(eventName,"%s_OnEnter",name);
 Packet_1fb5a0 packet; packet.FUN_001d1630(); packet.type=1;
 unsigned id=input->FUN_00036d00(); FUN_000964a0(packet.text,64,"%s",id);
 manager->FUN_001d3b00(eventName,packet);
 if(DAT_004dd700 && DAT_004dd700->receiver) {
 Receiver_1fb5a0* r=DAT_004dd700->receiver;
 Message_1fb5a0 message; message.FUN_001caf80(name,*input->value); r->FUN_001cbc20(&message);
 }
 }
}
} // namespace fn_001fb5a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001fb6a0 CTriggerVolume::vfunc_14 (253 B): equivalent/0x001fb6a0.cpp [wrapped: conflict: CTriggerVolume; FUN_001d4c90; World]
// sym: ?vfunc_14@CTriggerVolume@fn_001fb6a0@@UAEXPAUInput_1fb6a0@2@@Z @87a412e5df98 @w6f131a0d8b7c
namespace fn_001fb6a0 {
// STATUS: equivalent (tools/equiv.py level 3: 10508 inputs, branch coverage 6/6)
// CTriggerVolume::vfunc_14 @ 0x001fb6a0
// cl-flags: /GS
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

struct EventData_1fb6a0 { int words[174]; void FUN_001d1630(); };
struct Key_1fb6a0 { char data[84]; void FUN_001cb050(const char*, int); };
struct Input_1fb6a0 { char pad[8]; int a,b; int* value; int FUN_00036d00(); };
struct Manager_1fb6a0 { void FUN_001d3b00(const char*, EventData_1fb6a0); };
struct Receiver_1fb6a0 { void FUN_001cbc20(Key_1fb6a0*); };
struct World { char pad[48]; Receiver_1fb6a0* receiver; };
extern Manager_1fb6a0* __cdecl FUN_001d4c90();
extern int __cdecl _sprintf(char*, const char*, ...);
extern void __cdecl FUN_000964a0(char*, int, const char*, ...);
struct CTriggerVolume {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(int,int,int); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(Input_1fb6a0*); virtual void vfunc_15();
char pad[140]; char name[1];
};
void CTriggerVolume::vfunc_14(Input_1fb6a0* input) {
vfunc_9(input->a,input->b,0);
Manager_1fb6a0* manager=FUN_001d4c90();
if(manager) {
const char* n=name;
char eventName[256];
_sprintf(eventName,"%s_OnExit",n);
EventData_1fb6a0 data;
data.FUN_001d1630();
data.words[0]=1;
int text=input->FUN_00036d00();
FUN_000964a0((char*)&data.words[1],64,"%s",text);
manager->FUN_001d3b00(eventName,data);
if(DAT_004dd700 && DAT_004dd700->receiver) {
Receiver_1fb6a0* receiver=DAT_004dd700->receiver;
Key_1fb6a0 key;
key.FUN_001cb050(n,*input->value);
receiver->FUN_001cbc20(&key);
}
}
}
} // namespace fn_001fb6a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001fb7a0 CTriggerVolume::vfunc_15 (176 B): matches/0x001fb7a0.cpp [wrapped: conflict: CTriggerVolume; FUN_000964a0; FUN_001d4c90]
// sym: ?vfunc_15@CTriggerVolume@fn_001fb7a0@@QAEXPAUArgument_1fb7a0@2@@Z
namespace fn_001fb7a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CTriggerVolume::vfunc_15 @ 0x001fb7a0
// cl-flags: /GS
struct Params { unsigned kind; char text[692]; void FUN_001d1630(); };
struct Recipient_1fb7a0 { void FUN_001d3b00(const char*, Params); };
Recipient_1fb7a0* __cdecl FUN_001d4c90();
struct Argument_1fb7a0 { const char* FUN_00036d00(); };

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
int __cdecl sprintf(char*, const char*, ...);
#endif

void __cdecl FUN_000964a0(char*, unsigned, const char*, ...);
struct CTriggerVolume { char pad[0x90]; char name[1]; void vfunc_15(Argument_1fb7a0*); };
void CTriggerVolume::vfunc_15(Argument_1fb7a0* argument) {
 Recipient_1fb7a0* recipient = FUN_001d4c90();
 if (recipient) {
 char eventName[256];
 sprintf(eventName, "%s_OnInside", name);
 Params params;
 params.FUN_001d1630();
 params.kind = 1;
 const char* value = argument->FUN_00036d00();
 FUN_000964a0(params.text, 64, "%s", value);
 recipient->FUN_001d3b00(eventName, params);
 }
}
} // namespace fn_001fb7a0


// 0x001fbfb0 CLocator::vfunc_7 (21 B): matches/0x001fbfb0.cpp
// sym: ?vfunc_7@CLocator@@UAEXH@Z
void CLocator::vfunc_7(int ) {
    char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
}


// 0x001fc460 CTriggerVolume::vfunc_7 (21 B): matches/0x001fc460.cpp
// sym: ?vfunc_7@CTriggerVolume@@UAEXH@Z
// Same code shape as 0x001fbfb0 (propagated; names are from that function)
void CTriggerVolume::vfunc_7(int ) {
    char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
}

