// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// (regress, tri2, treeblk) WRONG: the third pointer is another global. A wrapped block whose function declares `extern const float zero_d94e0;` at block scope:
// MSVC 7.1 names it ?zero_d94e0@@3MB, clang ?zero_d94e0@fn_000d94e0@@3MB (the enclosing namespace). One variable.
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }
extern "C" { extern void* DAT_0052c2a8; }

// 0x000d94e0 FUN_000d94e0 (187 B): equivalent/0x000d94e0.cpp [wrapped: conflict: Singleton_4dd6ec]
// sym: ?target@Target_d94e0@fn_000d94e0@@QAEXH@Z
namespace fn_000d94e0 {
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 4/4)
// FUN_000d94e0 @ 0x000d94e0
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

struct State_d94e0 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d94e0* FUN_00086280(); };
struct Label_d94e0 {  };
struct Service_d94e0 {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
void FUN_000be310(const char*, char*, const float*, const float*, const float*, int, unsigned int, unsigned int);
};
struct Target_d94e0 {
char pad0[0x150]; Label_d94e0* label; char pad1[0xc8]; unsigned int value; char pad2[0x190]; unsigned char active; char pad3[0x3a]; unsigned char mode;
Service_d94e0* FUN_000fc3d0();
void target(int);
};
void Target_d94e0::target(int) {
char buffer[1024];
Service_d94e0* service=FUN_000fc3d0();
service->v44();
const char* text;
if(mode) text=(*(const char**)&DAT_004a0ce8);
else if(DAT_004dd6ec->FUN_00086280()->flag) text=(*(const char**)&DAT_004a0ce4);
else text=(*(const char**)&DAT_004a0ce0);
extern const float zero_d94e0; // the shared 0.0f constant in .rdata
unsigned int setting=(*(hulk_uintptr*)&DAT_004a0c60);
service->FUN_000be310(text,buffer,&zero_d94e0,&zero_d94e0,(const float*)&DAT_004a0c60,3,setting,setting);
active=1;
value=0;
((owners::MenuScreen_bc9f0 *)label)->FUN_000bc9f0((hulk_intptr)"DynamicControlButtonLabel", 0);
}
} // namespace fn_000d94e0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


