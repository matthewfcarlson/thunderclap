// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000d40e0..0x000d6e00 (kind game, layer game, confidence high), dominant class MessageOverlay
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"


// 0x000d6640 FUN_000d6640 (657 B): equivalent/0x000d6640.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0MessageOverlay@fn_000d6640@@QAE@XZ @613e2d674c06 @wf230a5ada3db
HULK_NATIVE_INLINE void* __cdecl operator new(hulk_uintptr, void* p) { return p; }
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_000d6640 {
// STATUS: equivalent (tools/equiv.py level 3: 2747 inputs, branch coverage 12/12)
// FUN_000d6640 @ 0x000d6640
// equiv-map: ?thunk_FUN_000d4b60@MessageOverlay@@QAEXPBD000000@Z = 0x000d5f90
// (the game binds hud_MessageEx to the `jmp` thunk at 0x000d5f90; the native link binds the thunk_ name to 0x000d4b60's definition)
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

typedef unsigned int uint;

extern "C" void* __cdecl FUN_0008d690(uint);
extern void* __cdecl FUN_00263ea0(uint);
namespace math { class Vector_d6640 { public: float x, y, z; }; }
struct MessageOverlay;
// Function's fields (include/decls/data/script.h) after the vftable; Method1 keeps the bound member-function pointer.
struct Command_d6640 : ScriptFunctionFields { virtual void slot0(); void FUN_001d0480(const char*,int); };
template<class T,class R,class A> struct Method1 : Command_d6640 { virtual void slot0(); R (T::*callback)(A); };
template<class T,class R,class A> struct Closure1 : Method1<T,R,A> { virtual void slot0(); T* owner; };
struct CDropShadowDisplayEffect_d6640 { void FUN_000dee40(); char bytes[20]; }; struct CGlowDisplayEffect_d6640 { void FUN_000dee10(); char bytes[20]; };
struct Inner_d6640 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(uint,int); };
struct Shader_d6640 { virtual void v0(); char pad[12]; Inner_d6640* inner; Shader_d6640* FUN_0028edb0(); };
// MessageOverlay (its 32-bit layout) and the members it binds to Lua, typed by the game's Closure<N> instantiations
// (the helpers 0x000d6410 / 0x000d6470 / 0x000d6520 / 0x000d65e0 and the inline Method1s); complete before any
// pointer to a member is formed (one code pointer on every build).
struct MessageOverlay { virtual void* slot0_000d6900(char); unsigned char busy; char pad5[3]; uint f8,fc,f10; char pad14[0x248-0x14]; unsigned char f248; char pad249[0x484-0x249]; unsigned char f484; char pad485[0x7b0-0x485]; uint f7b0; char pad7b4[12]; Shader_d6640* resource; unsigned char f7c4; char pad7c5[3]; uint f7c8,f7cc; char pad7d0[4]; CDropShadowDisplayEffect_d6640 a; CGlowDisplayEffect_d6640 b; char pad7fc[16]; unsigned char f80c; MessageOverlay();
    void FUN_000d5fa0(const char*);                                                                                    // hud_Message
    void thunk_FUN_000d4b60(const char*, const char*, const char*, const char*, const char*, const char*, const char*);  // hud_MessageEx
    void FUN_000d4780(const char*, int, math::Vector_d6640);                                                             // hud_ComboMessage
    void FUN_000d45e0(bool);                                                                                             // hud_PersistentMessages
    void FUN_000d5440();                                                                                                 // hud_ClearMessages
    void FUN_000d4600(float);                                                                                            // hud_MessageHoldTime
    void FUN_000d47d0(const char*, int, math::Vector_d6640);                                                             // hud_BonusMessage
    void FUN_000d4720(int, const char*, int, math::Vector_d6640, float);                                                 // hud_ComboMessageEx
    void FUN_000d4850(bool);                                                                                             // hud_EnableComboMessages
};
struct Manager_d6640 { void FUN_001d3b70(const char*,void*);
    void FUN_000d6410(const char*,MessageOverlay*,void (MessageOverlay::*)(const char*, const char*, const char*, const char*, const char*, const char*, const char*));
    void FUN_000d6470(const char*,MessageOverlay*,void (MessageOverlay::*)(const char*, int, math::Vector_d6640));
    void FUN_000d6520(const char*,MessageOverlay*,void (MessageOverlay::*)());
    void FUN_000d65e0(const char*,MessageOverlay*,void (MessageOverlay::*)(int, const char*, int, math::Vector_d6640, float)); };
extern "C" Manager_d6640* FUN_001d4c90();
MessageOverlay::MessageOverlay() {
 busy=1; f248=0; f484=0; a.FUN_000dee40(); b.FUN_000dee10(); f8=0; fc=0; f7b0=0;
 Shader_d6640* r=(Shader_d6640*)FUN_00263ea0(32); resource=r?r->FUN_0028edb0():0; resource->v0(); resource->inner->v6(0x444d4c42,1);
 f7c4=0; f10=0; f7c8=0; f7cc=0; f80c=1;
 Manager_d6640* m=FUN_001d4c90(); if(m) {
 typedef Closure1<MessageOverlay,void,const char*> ClosureS;
 HULK_SIZE32(ClosureS, 0x24);
 typedef Closure1<MessageOverlay,void,bool> ClosureB;
 HULK_SIZE32(ClosureB, 0x24);
 typedef Closure1<MessageOverlay,void,float> ClosureF;
 HULK_SIZE32(ClosureF, 0x24);
 void* p=FUN_0008d690((int)sizeof(Closure1<MessageOverlay,void,const char*>)); if(p) { Command_d6640* c=(Command_d6640*)p; c->FUN_001d0480("hud_Message",1); Method1<MessageOverlay,void,const char*>* mt=new(p) Method1<MessageOverlay,void,const char*>; mt->callback=&MessageOverlay::FUN_000d5fa0; c->retType=FUN_001d04d0(((uint*)&DAT_0048e100)); c->argTypes[0]=FUN_001d04d0(((uint*)&DAT_0048e0f0)); Closure1<MessageOverlay,void,const char*>* q=new(p) Closure1<MessageOverlay,void,const char*>; q->owner=this; }
 m->FUN_001d3b70("hud_Message",p); m->FUN_000d6410("hud_MessageEx",this,&MessageOverlay::thunk_FUN_000d4b60); m->FUN_000d6470("hud_ComboMessage",this,&MessageOverlay::FUN_000d4780);
 p=FUN_0008d690((int)sizeof(Closure1<MessageOverlay,void,bool>)); if(p) { Command_d6640* c=(Command_d6640*)p; c->FUN_001d0480("hud_PersistentMessages",1); Method1<MessageOverlay,void,bool>* mt=new(p) Method1<MessageOverlay,void,bool>; mt->callback=&MessageOverlay::FUN_000d45e0; c->retType=FUN_001d04d0(((uint*)&DAT_0048e100)); c->argTypes[0]=FUN_001d04d0(((uint*)&DAT_0048e0e4)); Closure1<MessageOverlay,void,bool>* q=new(p) Closure1<MessageOverlay,void,bool>; q->owner=this; }
 m->FUN_001d3b70("hud_PersistentMessages",p); m->FUN_000d6520("hud_ClearMessages",this,&MessageOverlay::FUN_000d5440);
 p=FUN_0008d690((int)sizeof(Closure1<MessageOverlay,void,float>)); if(p) { Command_d6640* c=(Command_d6640*)p; c->FUN_001d0480("hud_MessageHoldTime",1); Method1<MessageOverlay,void,float>* mt=new(p) Method1<MessageOverlay,void,float>; mt->callback=&MessageOverlay::FUN_000d4600; c->retType=FUN_001d04d0(((uint*)&DAT_0048e100)); c->argTypes[0]=FUN_001d04d0(((uint*)&DAT_0048e128)); Closure1<MessageOverlay,void,float>* q=new(p) Closure1<MessageOverlay,void,float>; q->owner=this; }
 m->FUN_001d3b70("hud_MessageHoldTime",p); m->FUN_000d6470("hud_BonusMessage",this,&MessageOverlay::FUN_000d47d0); m->FUN_000d65e0("hud_ComboMessageEx",this,&MessageOverlay::FUN_000d4720);
 p=FUN_0008d690((int)sizeof(Closure1<MessageOverlay,void,bool>)); if(p) { Command_d6640* c=(Command_d6640*)p; c->FUN_001d0480("hud_EnableComboMessages",1); Method1<MessageOverlay,void,bool>* mt=new(p) Method1<MessageOverlay,void,bool>; mt->callback=&MessageOverlay::FUN_000d4850; c->retType=FUN_001d04d0(((uint*)&DAT_0048e100)); c->argTypes[0]=FUN_001d04d0(((uint*)&DAT_0048e0e4)); Closure1<MessageOverlay,void,bool>* q=new(p) Closure1<MessageOverlay,void,bool>; q->owner=this; }
 m->FUN_001d3b70("hud_EnableComboMessages",p); busy=0;
 }
}
} // namespace fn_000d6640
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

