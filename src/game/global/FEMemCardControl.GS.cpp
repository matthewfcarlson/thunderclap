// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000d7af0..0x000dc230 (kind game, layer game, confidence high), dominant class FEMemCardControl
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"


// 0x000d8030 FEMemCardControl::vfunc_13 (270 B): matches/0x000d8030.cpp [wrapped: conflict: FUN_000fc3d0]
// sym: ?vfunc_13@FEMemCardControl@fn_000d8030@@QAEXH@Z
namespace fn_000d8030 {
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 4/4)
// FEMemCardControl::vfunc_13 @ 0x000d8030
// cl-flags: /GS

struct Label_d8030 { void FUN_000bc9f0(const char*, int); struct Stage1_d8030* FUN_000b5000(); };
struct Stage2_d8030 { void FUN_0008c870(int); };
struct Stage1_d8030 { Stage2_d8030* FUN_00089a50(); };
struct Child_d8030 { char pad[0xab9]; unsigned char flag; };
struct Parent_d8030 { char pad[0x175c]; Child_d8030* child; };
struct Timer { int value; void FUN_000f8500(void*, int, int); };
struct Service_d8030 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual int s44(); };
Service_d8030* __cdecl FUN_000fc3d0();
struct FEMemCardControl {
 char p0[0xa8]; Parent_d8030* parent; char p1[0x150-0xac]; Label_d8030* label; char p2[0x1d0-0x154]; int a,b; char p3[0x34c-0x1d8]; int c,d,e; char p4[4]; Timer timer; char p5[0x380-0x360]; unsigned char flag380; char p6[0x3ac-0x381]; int state; unsigned char skip; char p7[0x3e9-0x3b1]; unsigned char f9,fa,fb,fc; char p8[3]; int count; char p9[0x418-0x3f4]; int x,y,z;
 void vfunc_13(int);
};
void FEMemCardControl::vfunc_13(int) {
 char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
 if (!skip) {
  bool active=fa!=0;
  x=31; fc=0; count=0; f9=0; fb=0;
  if(active) {
   fb=1; y=31; z=31;
   label->FUN_000bc9f0("DynamicControlButtonLabel",0);
   parent->child->flag=0;
   state=15;
  } else state=0;
  b=0; a=0;
  label->FUN_000b5000()->FUN_00089a50()->FUN_0008c870(0);
  d=4; e=4; c=0; flag380=0;
  int v=FUN_000fc3d0()->s44();
  timer.value=0;
  timer.FUN_000f8500((*(void**)&DAT_004a0c64),v,1);
 }
 skip=0;
}
} // namespace fn_000d8030


// 0x000d8410 FUN_000d8410 (610 B): equivalent/0x000d8410.cpp [wrapped: conflict: FUN_000fc3d0]
// sym: ?FUN_000d8410@FEMemCardControl_d8410@fn_000d8410@@QAEXXZ @aa0a9f9fbbf3 @w0de2456636c6
namespace fn_000d8410 {
// STATUS: equivalent (tools/equiv.py level 3: 3151 inputs, branch coverage 77/78, incomplete)
// FUN_000d8410 @ 0x000d8410
// cl-flags: /GS


struct Dummy_d8410 {
    int FUN_0008c740(int zero, unsigned int *out1, int *out2);
    void FUN_0008c920();
};

struct Mid_d8410 {
};

struct Mgr_d8410 {
    Mid_d8410 *FUN_000b5000();
};

struct Player_d8410 {
    char pad0[0x9a8];
    char busy;
};

class Game_d8410 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual int v44();
    char pad04[0x2218 - 4];
    Player_d8410 *player;
    void FUN_000e63a0();
};

Game_d8410 *FUN_000fc3d0();

struct Timer {
    int value;
    void FUN_000f8500(const char *name, int a, int flag);
};

class FEMemCardControl_d8410 {
public:
    void FUN_000d8410();

    char pad0[0x150];
    Mgr_d8410 *mgr;
    char pad154[0x1d0 - 0x154];
    int pending;
    char pad1d4[0x34c - 0x1d4];
    unsigned int kind;
    int prevState;
    int state;
    char pad358[4];
    Timer timer;
    char pad360[0x380 - 0x360];
    char started;
    char pad381[0x3ac - 0x381];
    int mode;
    char pad3b0[0x3eb - 0x3b0];
    char flag3eb;
    char pad3ec[0x418 - 0x3ec];
    int altMode;
};

void FEMemCardControl_d8410::FUN_000d8410()
{
    char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
    unsigned int o1;
    int o2;

    ((Dummy_d8410 *)((owners::Obj_89a50 *)(mgr->FUN_000b5000()))->FUN_00089a50())->FUN_0008c920();
    int r = ((Dummy_d8410 *)((owners::Obj_89a50 *)(mgr->FUN_000b5000()))->FUN_00089a50())->FUN_0008c740(0, &o1, &o2);
    if (r == 0 && o1 < 4)
        r = 7;
    prevState = state;
    state = r;
    kind = o1;

    int handle = FUN_000fc3d0()->v44();
    timer.value = 0;
    timer.FUN_000f8500((*(const char**)&DAT_004a0c64), handle, 1);

    int old = prevState;
    int next = state;
    if (old == next && started) {
        return;
    }
    started = 1;
    int m = mode;
    int check = m;
    if (m == 0x1d)
        check = altMode;
    if (check == 4 || check == 5 || check == 6 || check == 0x1c || check == 7 || check == 0x10 || check == 0x1f) {
        return;
    }
    if (flag3eb) {
        if (old != 4 || next == old) {
            return;
        }
        for (;;) {
            Player_d8410 *pl = FUN_000fc3d0()->player;
            if (pl == 0 || !pl->busy)
                break;
            FUN_000fc3d0()->FUN_000e63a0();
        }
        if (mode == 0x1d)
            altMode = 0xf;
        else
            mode = 0xf;
        return;
    }
    if (pending != 0) {
        return;
    }
    if (m == 8 || m == 9 || m == 0xb || m == 0xc || m == 0xd || m == 0x19 || m == 0x12 || m == 0x1e || m == 0x14) {
        for (;;) {
            Player_d8410 *pl = FUN_000fc3d0()->player;
            if (pl == 0 || !pl->busy)
                break;
            FUN_000fc3d0()->FUN_000e63a0();
        }
    }
    if (mode == 0x1d)
        altMode = 0;
    else
        mode = 0;
}
} // namespace fn_000d8410


// 0x000d8990 FUN_000d8990 (246 B): equivalent/0x000d8990.cpp [wrapped: conflict: FUN_000fc3d0]
// sym: ?FUN_000d8990@FEMemCardControl_d8990@fn_000d8990@@QAEXH@Z @8d14744bf03f @w4e82a2d3e911
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_000d8990 {
// STATUS: equivalent (tools/equiv.py level 3: 17513 inputs, branch coverage 4/4)
// FUN_000d8990 @ 0x000d8990
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

struct Manager_d8990;
struct Entry_d8990 {
 char prefix[0x1c]; unsigned char marked; char suffix[0x1b];
 const char* FUN_000f83f0(Manager_d8990*, int);
};
struct Manager_d8990 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
 virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
 virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
 virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
 virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
 virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
 virtual Manager_d8990* slot44();
 void FUN_000be310(const char*, char*, const float*, const char*, const char*, int, const char*, const char*);
};
extern Manager_d8990* __cdecl FUN_000fc3d0();
extern void __cdecl FUN_000fc020(char*,int,const char*,...);
struct Settings_d8990 { char pad[0x1bc8]; unsigned char active; };
struct Singleton_4dd6ec { Settings_d8990* FUN_00086280(); };
struct FEMemCardControl_d8990 {
 char pad0[0x21c]; int state; char pad1[0x13c]; Entry_d8990 entries[2]; char pad2[0x1f]; unsigned char mode;
 void FUN_000d8990(int index);
};
void FEMemCardControl_d8990::FUN_000d8990(int index) {
 char text[1024];
 Manager_d8990* manager = FUN_000fc3d0()->slot44();
 int key = ((int)((owners::A_f7d30 *)manager)->FUN_000f7d30((hulk_intptr)((*(const char**)&DAT_004a0cb8))));
 const char* format = ((const char *)((owners::C_f7220 *)manager)->FUN_000f7220((hulk_intptr)key));
 const char* value = entries[index].FUN_000f83f0(manager,0);
 FUN_000fc020(text,512,format,value);
 Manager_d8990* ui = FUN_000fc3d0();
 const char* title;
 if(mode) title = (*(const char**)&DAT_004a0ce8);
 else if(DAT_004dd6ec->FUN_00086280()->active) title = (*(const char**)&DAT_004a0ce4);
 else title = (*(const char**)&DAT_004a0ce0);
 const char* callback = (*(const char**)&DAT_004a0c60);
 ui->FUN_000be310(title,text,&DAT_003f335c,"TBS_MENU_ITEM_LS_OVERWRITE","TBS_CANCEL",2,callback,callback);
 entries[1].marked = 1;
 state = 0;
}
} // namespace fn_000d8990
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d8a90 FUN_000d8a90 (246 B): equivalent/0x000d8a90.cpp [wrapped: conflict: FUN_000fc3d0; Singleton_4dd6ec]
// sym: ?run@FEMemCardControl_d8a90@fn_000d8a90@@QAEXH@Z @8da053c5e59d @wd724db421729
namespace fn_000d8a90 {
// STATUS: equivalent (tools/equiv.py level 3: 17099 inputs, branch coverage 4/4)
// FUN_000d8a90 @ 0x000d8a90
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

struct UI_d8a90 {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual UI_d8a90* v44();
 
void FUN_000be310(const char*, const unsigned short*, const float*, const char*, const char*, int, const char*, const char*);
};
UI_d8a90* __cdecl FUN_000fc3d0();
void __cdecl FUN_000fc020(unsigned short*, int, const char*, ...);
struct Entry_d8a90 { char data[0x38]; const char* FUN_000f83f0(UI_d8a90*,int); };
struct State_d8a90 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d8a90* FUN_00086280(); };
struct FEMemCardControl_d8a90 { char pad0[0x21c]; int value; char pad1[0x35c-0x220]; Entry_d8a90 entries[1]; char pad2[0x3b0-0x394]; unsigned char active; char pad3[0x3eb-0x3b1]; unsigned char mode; void run(int index); };
void FEMemCardControl_d8a90::run(int index) {
unsigned short text[512];
UI_d8a90* ui = FUN_000fc3d0()->v44();
int id = ((int)((owners::A_f7d30 *)ui)->FUN_000f7d30((hulk_intptr)((*(const char**)&DAT_004a0cbc))));
const char* format = ((const char *)((owners::C_f7220 *)ui)->FUN_000f7220((hulk_intptr)id));
const char* name = entries[index].FUN_000f83f0(ui,0);
FUN_000fc020(text,512,format,name);
UI_d8a90* dialog = FUN_000fc3d0();
const char* title;
if(mode) title=(*(const char**)&DAT_004a0ce8);
else if(DAT_004dd6ec->FUN_00086280()->flag) title=(*(const char**)&DAT_004a0ce4);
else title=(*(const char**)&DAT_004a0ce0);
const char* extra=(*(const char**)&DAT_004a0c60);
dialog->FUN_000be310(title,text,&DAT_003f335c,"TBS_MENU_ITEM_MC_LOAD","TBS_CANCEL",2,extra,extra);
active=1;
value=0;
}
} // namespace fn_000d8a90
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d8cb0 FUN_000d8cb0 (278 B): equivalent/0x000d8cb0.cpp [wrapped: conflict: FUN_000fc3d0; Singleton_4dd6ec]
// sym: ?target@FEMemCardControl_d8cb0@fn_000d8cb0@@QAEXEH@Z @f91114fe48ca @w01d5333379a6
namespace fn_000d8cb0 {
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 6/6)
// FUN_000d8cb0 @ 0x000d8cb0
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

struct TextStore_d8cb0 {   };
struct UI_d8cb0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual TextStore_d8cb0* v44();
 void FUN_000be310(const char*, const unsigned short*, const char*, const char*, const char*, int, const char*, const char*);
};
UI_d8cb0* __cdecl FUN_000fc3d0();
void __cdecl FUN_000fc020(unsigned short*, int, const char*, ...);
struct State_d8cb0 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d8cb0* FUN_00086280(); };
struct Widget_d8cb0 {  };
struct FEMemCardControl_d8cb0 {
 char pad0[0x150]; Widget_d8cb0* widget; char pad1[0x21c-0x154]; int value; char pad2[0x3b0-0x220]; unsigned char active; char pad3[0x3eb-0x3b1]; unsigned char flag;
 void target(unsigned char unused, int mode);
};
void FEMemCardControl_d8cb0::target(unsigned char unused, int mode) {
 unsigned short text[512];
 TextStore_d8cb0* store = FUN_000fc3d0()->v44();
 const char* common = (*(const char**)&DAT_004a0c60);
 int id = ((int)((owners::A_f7d30 *)store)->FUN_000f7d30((hulk_intptr)((unsigned char)mode ? (*(const char**)&DAT_004a0c70) : (*(const char**)&DAT_004a0c6c))));
 const char* source = ((const char *)((owners::C_f7220 *)store)->FUN_000f7220((hulk_intptr)id));
 FUN_000fc020(text,512,source);
 UI_d8cb0* ui = FUN_000fc3d0();
 const char* label;
 if(flag) label=(*(const char**)&DAT_004a0ce8);
 else label=DAT_004dd6ec->FUN_00086280()->flag ? (*(const char**)&DAT_004a0ce4) : (*(const char**)&DAT_004a0ce0);
 ui->FUN_000be310(label,text,"","","",3,common,common);
 Widget_d8cb0* w = widget;
 active=1;
 value=0;
 ((owners::MenuScreen_bc9f0 *)w)->FUN_000bc9f0((hulk_intptr)"DynamicControlButtonLabel", 0);
}
} // namespace fn_000d8cb0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d8dd0 FUN_000d8dd0 (234 B): equivalent/0x000d8dd0.cpp [wrapped: conflict: FUN_000fc3d0; Singleton_4dd6ec]
// sym: ?run@FEMemCardControl_d8dd0@fn_000d8dd0@@QAEXH@Z @f1a4521b2932 @w9ff1da143b51
namespace fn_000d8dd0 {
// STATUS: equivalent (tools/equiv.py level 3: 17337 inputs, branch coverage 4/4)
// FUN_000d8dd0 @ 0x000d8dd0
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

struct Manager_d8dd0;
struct Provider_d8dd0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual Manager_d8dd0* v44(); void FUN_000be310(const char*, unsigned short*, const float*, const float*, const float*, int, const char*, const char*); };
struct Manager_d8dd0 {   };
struct State_d8dd0 { char pad[0x1bc8]; unsigned char active; };
struct Singleton_4dd6ec { State_d8dd0* FUN_00086280(); };
struct Widget_d8dd0 {  };
extern Provider_d8dd0* __cdecl FUN_000fc3d0();
extern void __cdecl FUN_000fc020(unsigned short*, int, const char*, ...);
struct FEMemCardControl_d8dd0 { char pad0[0x150]; Widget_d8dd0* widget; char pad1[0x21c-0x154]; int value; char pad2[0x3b0-0x220]; unsigned char enabled; char pad3[0x3eb-0x3b1]; unsigned char mode; void run(int); };
void FEMemCardControl_d8dd0::run(int) {
 unsigned short buffer[512];
 Provider_d8dd0* p=FUN_000fc3d0();
 Manager_d8dd0* m=p->v44();
 int id=((int)((owners::A_f7d30 *)m)->FUN_000f7d30((hulk_intptr)((*(const char**)&DAT_004a0c74))));
 const char* text=((const char *)((owners::C_f7220 *)m)->FUN_000f7220((hulk_intptr)id));
 FUN_000fc020(buffer,512,text);
 p=FUN_000fc3d0();
 const char* label;
 if(mode) label=(*(const char**)&DAT_004a0ce8);
 else if(DAT_004dd6ec->FUN_00086280()->active) label=(*(const char**)&DAT_004a0ce4);
 else label=(*(const char**)&DAT_004a0ce0);
 p->FUN_000be310(label,buffer,((float*)&DAT_003f335c),((float*)&DAT_003f335c),((float*)&DAT_003f335c),3,(*(const char**)&DAT_004a0c60),(*(const char**)&DAT_004a0c60));
 Widget_d8dd0* w=widget;
 enabled=1;
 value=0;
 ((owners::MenuScreen_bc9f0 *)w)->FUN_000bc9f0((hulk_intptr)"DynamicControlButtonLabel", 0);
}
} // namespace fn_000d8dd0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d8ec0 FUN_000d8ec0 (216 B): equivalent/0x000d8ec0.cpp [wrapped: conflict: FUN_000fc3d0; Singleton_4dd6ec]
// sym: ?FUN_000d8ec0@FEMemCardControl_d8ec0@fn_000d8ec0@@QAEXHH@Z @915463d4a2dc @w9ee5d40da4b2
namespace fn_000d8ec0 {
// STATUS: equivalent (tools/equiv.py level 3: 18277 inputs, branch coverage 4/4)
// FUN_000d8ec0 @ 0x000d8ec0
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

struct Menu_d8ec0;
struct Provider_d8ec0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual Menu_d8ec0* v44();
 void FUN_000be310(const char*, const char*, const char*, const char*, const char*, int, const char*, const char*);
};
struct Menu_d8ec0 {   };
extern Provider_d8ec0* __cdecl FUN_000fc3d0();
extern void __cdecl FUN_000fc020(char*, int, const char*, ...);
struct State_d8ec0 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d8ec0* FUN_00086280(); };
struct FEMemCardControl_d8ec0 {
 char p0[0x21c]; int state; char p1[0x3b0-0x220]; unsigned char active; char p2[0x3eb-0x3b1]; unsigned char mode;
 void FUN_000d8ec0(int, int);
};
void FEMemCardControl_d8ec0::FUN_000d8ec0(int, int) {
 char buffer[1024];
 Menu_d8ec0* menu = FUN_000fc3d0()->v44();
 int id = ((int)((owners::A_f7d30 *)menu)->FUN_000f7d30((hulk_intptr)((*(const char**)&DAT_004a0c94))));
 const char* text = ((const char *)((owners::C_f7220 *)menu)->FUN_000f7220((hulk_intptr)id));
 FUN_000fc020(buffer, 512, text);
 Provider_d8ec0* provider = FUN_000fc3d0();
 const char* message;
 if (mode) message = (*(const char**)&DAT_004a0ce8);
 else if (DAT_004dd6ec->FUN_00086280()->flag) message = (*(const char**)&DAT_004a0ce4);
 else message = (*(const char**)&DAT_004a0ce0);
 provider->FUN_000be310(message, buffer, ((const char*)&DAT_003f335c), ((const char*)&DAT_003f335c), "TBS_MENU_ITEM_OK", 2, (*(const char**)&DAT_004a0c60), (*(const char**)&DAT_004a0c60));
 active = 1;
 state = 0;
}
} // namespace fn_000d8ec0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d8fa0 FUN_000d8fa0 (216 B): equivalent/0x000d8fa0.cpp [wrapped: conflict: FUN_000fc3d0; Singleton_4dd6ec]
// sym: ?FUN_000d8fa0@FEMemCardControl_d8fa0@fn_000d8fa0@@QAEXHH@Z @62f7a5e9b1dd @we8fc14f499f5
namespace fn_000d8fa0 {
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 4/4)
// FUN_000d8fa0 @ 0x000d8fa0
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

struct Menu_d8fa0;
struct Manager_d8fa0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual Menu_d8fa0* v44();
 void FUN_000be310(const char*, const unsigned short*, const float*,const float*,const char*,int,const char*,const char*);
};
struct Menu_d8fa0 {   };
Manager_d8fa0* __cdecl FUN_000fc3d0();
void __cdecl FUN_000fc020(unsigned short*,int,const char*,...);
struct State_d8fa0 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d8fa0* FUN_00086280(); };
struct FEMemCardControl_d8fa0 { char pad[0x21c]; int field21c; char pad2[0x190]; unsigned char field3b0; char pad3[0x3a]; unsigned char field3eb; void FUN_000d8fa0(int,int); };
void FEMemCardControl_d8fa0::FUN_000d8fa0(int,int) {
 unsigned short text[512];
 Menu_d8fa0* menu=FUN_000fc3d0()->v44();
 int id=((int)((owners::A_f7d30 *)menu)->FUN_000f7d30((hulk_intptr)((*(const char**)&DAT_004a0c9c))));
 const char* source=((const char *)((owners::C_f7220 *)menu)->FUN_000f7220((hulk_intptr)id));
 FUN_000fc020(text,512,source);
 Manager_d8fa0* manager=FUN_000fc3d0();
 const char* title;
 if(field3eb) title=(*(const char**)&DAT_004a0ce8);
 else if(DAT_004dd6ec->FUN_00086280()->flag) title=(*(const char**)&DAT_004a0ce4);
 else title=(*(const char**)&DAT_004a0ce0);
 const char* button=(*(const char**)&DAT_004a0c60);
 manager->FUN_000be310(title,text,&DAT_003f335c,&DAT_003f335c,"TBS_MENU_ITEM_OK",2,button,button);
 field3b0=1;
 field21c=0;
}
} // namespace fn_000d8fa0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d9180 FUN_000d9180 (313 B): equivalent/0x000d9180.cpp [wrapped: conflict: Singleton_4dd6ec]
// sym: ?run@FEMemCardControl_d9180@fn_000d9180@@QAEXH@Z @c9d14282f161 @w8158987a383e
namespace fn_000d9180 {
// STATUS: equivalent (tools/equiv.py level 3: 17405 inputs, branch coverage 6/6)
// FUN_000d9180 @ 0x000d9180
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

struct Locale {
    int FUN_000f7d30(const char* key);
    const char* FUN_000f7220(int id);
};

struct TextOwner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual Locale* v44();
};

struct Widget_d9180 {
    int FUN_000f83f0(Locale* loc, int arg);
    char pad[0x38];
};

struct Settings_d9180 {
    char pad[0x1bc8];
    char flag;
};

struct Singleton_4dd6ec {
    Settings_d9180* FUN_00086280();
};

struct Screen_d9180 {
    void FUN_000be310(const char* font, char* text, const float* a, const float* b, const char* name,
                      int n, const char* s1, const char* s2);
};

class FEMemCardControl_d9180 {
public:
    void run(int idx);
    char p0[0x21c];
    int n21c;
    char p1[0x34c - 0x220];
    int offset;
    char p2[0x35c - 0x350];
    Widget_d9180 widgets[1];
    char p3[0x3b0 - 0x35c - 0x38];
    char done;
    char p4[0x3eb - 0x3b1];
    char alt;
};

extern TextOwner* FUN_000fc3d0();
void FUN_000fc020(char* buf, int n, const char* fmt, ...);

void FEMemCardControl_d9180::run(int idx)
{
    char buf[0x400];
    Screen_d9180* screen = (Screen_d9180*)FUN_000fc3d0();
    Locale* loc = ((TextOwner*)screen)->v44();
    if (idx == 0) {
        int remaining = 4 - offset;
        const char* fmt = loc->FUN_000f7220(loc->FUN_000f7d30((*(const char**)&DAT_004a0cc4)));
        FUN_000fc020(buf, 0x200, fmt, remaining);
    } else {
        const char* fmt = loc->FUN_000f7220(loc->FUN_000f7d30((*(const char**)&DAT_004a0ca4)));
        int v = ((Widget_d9180*)((char*)this + 0x35c + idx * 0x38))->FUN_000f83f0(loc, 0);
        FUN_000fc020(buf, 0x200, fmt, v, 4);
    }
    const char* font;
    if (alt == 0) {
        if (DAT_004dd6ec->FUN_00086280()->flag != 0)
            font = (*(const char**)&DAT_004a0ce4);
        else
            font = (*(const char**)&DAT_004a0ce0);
    } else {
        font = (*(const char**)&DAT_004a0ce8);
    }
    screen->FUN_000be310(font, buf, ((float*)&DAT_003f335c), ((float*)&DAT_003f335c), "TBS_MENU_ITEM_OK", 2, (*(const char**)&DAT_004a0c60), (*(const char**)&DAT_004a0c60));
    done = 1;
    n21c = 0;
}
} // namespace fn_000d9180
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d92c0 FUN_000d92c0 (359 B): equivalent/0x000d92c0.cpp [wrapped: conflict: Singleton_4dd6ec]
// sym: ?run@FEMemCardControl_d92c0@fn_000d92c0@@QAEXH@Z @c0295c6f7ebc @w92022d760ec5
namespace fn_000d92c0 {
// STATUS: equivalent (tools/equiv.py level 3: 16675 inputs, branch coverage 10/10)
// FUN_000d92c0 @ 0x000d92c0
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

struct Locale {
    int FUN_000f7d30(const char* key);
    const char* FUN_000f7220(int id);
};

struct TextOwner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual Locale* v44();
};

struct Widget_d92c0 {
    int FUN_000f83f0(Locale* loc, int arg);
    char pad[0x38];
};

struct Settings_d92c0 {
    char pad[0x1bc8];
    char flag;
};

struct Singleton_4dd6ec {
    Settings_d92c0* FUN_00086280();
};

struct Screen_d92c0 {
    void FUN_000be310(const char* font, char* text, const float* a, const char* b, const char* name,
                      int n, const char* s1, const char* s2);
};

class FEMemCardControl_d92c0 {
public:
    void run(int idx);
    char p0[0x21c];
    int n21c;
    char p1[0x35c - 0x220];
    Widget_d92c0 widgets[1];
    char p3[0x3ac - 0x35c - 0x38];
    int n3ac;
    char flag3b0;
    char p4[0x3e8 - 0x3b1];
    char mode;
    char p5[2];
    char alt;
};

extern TextOwner* FUN_000fc3d0();
void FUN_000fc020(char* buf, int n, const char* fmt, ...);

void FEMemCardControl_d92c0::run(int idx)
{
    char buf[0x400];
    Screen_d92c0* screen = (Screen_d92c0*)FUN_000fc3d0();
    Locale* loc = ((TextOwner*)screen)->v44();
    const char* fmt = loc->FUN_000f7220(loc->FUN_000f7d30((*(const char**)&DAT_004de660)));
    int v = ((Widget_d92c0*)((char*)this + 0x35c + idx * 0x38))->FUN_000f83f0(loc, 0);
    FUN_000fc020(buf, 0x200, fmt, v);
    screen = (Screen_d92c0*)FUN_000fc3d0();

    bool pick = (mode != 0);
    char altv = alt;
    const char* font;
    if (altv == 0) {
        if (DAT_004dd6ec->FUN_00086280()->flag != 0)
            font = (*(const char**)&DAT_004a0ce4);
        else
            font = (*(const char**)&DAT_004a0ce0);
    } else {
        font = (*(const char**)&DAT_004a0ce8);
    }
    if (pick) {
        screen->FUN_000be310(font, buf, ((float*)&DAT_003f335c), "TBS_MENU_ITEM_CONTINUE", "TBS_CANCEL", 2, (*(const char**)&DAT_004a0c60), (*(const char**)&DAT_004a0c60));
        n3ac = 1;
        flag3b0 = 1;
    } else {
        screen->FUN_000be310(font, buf, ((float*)&DAT_003f335c), "", "TBS_MENU_ITEM_OK", 2, (*(const char**)&DAT_004a0c60), (*(const char**)&DAT_004a0c60));
        flag3b0 = 1;
    }
    n21c = 0;
}
} // namespace fn_000d92c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d94e0 FUN_000d94e0 (187 B): equivalent/0x000d94e0.cpp [wrapped: conflict: Singleton_4dd6ec]
// sym: ?target@Target_d94e0@fn_000d94e0@@QAEXH@Z @5728a6875c54 @w45c3f5dd6f77
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
service->FUN_000be310(text,buffer,&zero_d94e0,&zero_d94e0,&zero_d94e0,3,setting,setting);
active=1;
value=0;
((owners::MenuScreen_bc9f0 *)label)->FUN_000bc9f0((hulk_intptr)"DynamicControlButtonLabel", 0);
}
} // namespace fn_000d94e0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d95a0 FUN_000d95a0 (214 B): equivalent/0x000d95a0.cpp [wrapped: conflict: Singleton_4dd6ec]
// sym: ?target@FEMemCardControl_d95a0@fn_000d95a0@@QAEXH@Z @2c2d132cd640 @we083ab717955
namespace fn_000d95a0 {
// STATUS: equivalent (tools/equiv.py level 3: 18802 inputs, branch coverage 4/4)
// FUN_000d95a0 @ 0x000d95a0
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

struct TextBank {   };
struct Menu_d95a0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual TextBank* v44();
 void FUN_000be310(const char*, unsigned short*, const float*, const float*, const char*, int, void*, void*);
};
struct State_d95a0 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d95a0* FUN_00086280(); };
void __cdecl FUN_000fc020(unsigned short*, int, const unsigned short*, ...);
struct FEMemCardControl_d95a0 {
 char pad0[0x21c]; int field21c; char pad1[0x3b0-0x220]; unsigned char field3b0; char pad2[0x3eb-0x3b1]; unsigned char field3eb;
 Menu_d95a0* FUN_000fc3d0();
 void target(int);
};
void FEMemCardControl_d95a0::target(int) {
 unsigned short text[512];
 Menu_d95a0* menu = FUN_000fc3d0();
 TextBank* bank = menu->v44();
 int id = ((int)((owners::A_f7d30 *)bank)->FUN_000f7d30((hulk_intptr)((*(void**)&DAT_004de648))));
 const unsigned short* source = ((const unsigned short *)((owners::C_f7220 *)bank)->FUN_000f7220((hulk_intptr)id));
 FUN_000fc020(text,512,source);
 const char* heading;
 if(field3eb) heading=(*(const char**)&DAT_004a0ce8);
 else if(DAT_004dd6ec->FUN_00086280()->flag) heading=(*(const char**)&DAT_004a0ce4);
 else heading=(*(const char**)&DAT_004a0ce0);
 void* style=(*(void**)&DAT_004a0c60);
 menu->FUN_000be310(heading,text,((float*)&DAT_003f335c),((float*)&DAT_003f335c),"TBS_MENU_ITEM_OK",2,style,style);
 field3b0=1;
 field21c=0;
}
} // namespace fn_000d95a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d9680 FUN_000d9680 (272 B): matches/0x000d9680.cpp [wrapped: conflict: Singleton_4dd6ec]
// sym: ?target@FEMemCardControl_d9680@fn_000d9680@@QAEXH@Z
namespace fn_000d9680 {
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 4/4)
// FUN_000d9680 @ 0x000d9680
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

struct Profile_d9680 {   };
struct Item_d9680 { char data[0x1c]; unsigned char active; char rest[0x1b]; void* FUN_000f83f0(Profile_d9680*, int); };
struct State_d9680 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d9680* FUN_00086280(); };
struct Dialog_d9680 {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual Profile_d9680* v44();
void FUN_000be310(void*, void*, const char*, const char*, const char*, int, void*, void*);
};
     
void __cdecl FUN_000fc020(void*, int, void*, ...);
struct FEMemCardControl_d9680 {
char pad0[0x21c]; int status; char pad1[0x35c-0x220]; Item_d9680 items[2]; char pad2[0x3eb-0x3cc]; unsigned char flag;
Dialog_d9680* FUN_000fc3d0();
void target(int index);
};
void FEMemCardControl_d9680::target(int index) {
char buffer[1024];
Dialog_d9680* dialog=FUN_000fc3d0();
Profile_d9680* profile=dialog->v44();
int id=((int)((owners::A_f7d30 *)profile)->FUN_000f7d30((hulk_intptr)DAT_004de64c));
void* text=((void *)((owners::C_f7220 *)profile)->FUN_000f7220((hulk_intptr)id));
void* item=items[index].FUN_000f83f0(profile,0);
FUN_000fc020(buffer,512,text,item);
if(flag) {
void* value=(*(void**)&DAT_004a0c60);
dialog->FUN_000be310((*(void**)&DAT_004a0ce8),buffer,"","TBS_MENU_ITEM_CONTINUE_WITHOUT_SAVE","TBS_MENU_ITEM_RETRY",2,value,value);
} else {
State_d9680* state=DAT_004dd6ec->FUN_00086280();
void* heading=state->flag ? (*(void**)&DAT_004a0ce4) : (*(void**)&DAT_004a0ce0);
void* value=(*(void**)&DAT_004a0c60);
dialog->FUN_000be310(heading,buffer,"","","TBS_MENU_ITEM_OK",2,value,value);
}
items[1].active=1;
status=0;
}
} // namespace fn_000d9680
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d9790 FUN_000d9790 (244 B): equivalent/0x000d9790.cpp [wrapped: conflict: Singleton_4dd6ec]
// sym: ?target@FEMemCardControl_d9790@fn_000d9790@@QAEXH@Z @d57e12a378aa @wae72dcee6164
namespace fn_000d9790 {
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 4/4)
// FUN_000d9790 @ 0x000d9790
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

typedef unsigned short wchar_t;
struct TextTable_d9790 {   };
struct Entry_d9790 { char data[0x38]; const wchar_t* FUN_000f83f0(TextTable_d9790*, int); };
struct UI_d9790 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual TextTable_d9790* v44();
 void FUN_000be310(const wchar_t*,const wchar_t*,const void*,const char*,const char*,int,const wchar_t*,const wchar_t*);
};
struct State_d9790 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d9790* FUN_00086280(); };
extern void __cdecl FUN_000fc020(wchar_t*,int,const wchar_t*,...);
struct FEMemCardControl_d9790 {
 char pad0[0x21c]; int status; char pad1[0x13c]; Entry_d9790 entries[1]; char pad2[0x1c]; unsigned char shown; char pad3[0x3a]; unsigned char special;
 UI_d9790* FUN_000fc3d0();
 void target(int index);
};
void FEMemCardControl_d9790::target(int index) {
 wchar_t buffer[512];
 UI_d9790* ui=FUN_000fc3d0();
 TextTable_d9790* text=ui->v44();
 int key=((int)((owners::A_f7d30 *)text)->FUN_000f7d30((hulk_intptr)((*(const wchar_t**)&DAT_004a0ca8))));
 const wchar_t* format=((const wchar_t *)((owners::C_f7220 *)text)->FUN_000f7220((hulk_intptr)key));
 const wchar_t* item=entries[index].FUN_000f83f0(text,0);
 FUN_000fc020(buffer,512,format,item);
 const wchar_t* title;
 if(special) title=(*(const wchar_t**)&DAT_004a0ce8);
 else if(DAT_004dd6ec->FUN_00086280()->flag) title=(*(const wchar_t**)&DAT_004a0ce4);
 else title=(*(const wchar_t**)&DAT_004a0ce0);
 const wchar_t* common=(*(const wchar_t**)&DAT_004a0c60);
 ui->FUN_000be310(title,buffer,((float*)&DAT_003f335c),"TBS_INSTRUCTION_DELETE","TBS_CANCEL",2,common,common);
 shown=1;
 status=0;
}
} // namespace fn_000d9790
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d9890 FUN_000d9890 (262 B): equivalent/0x000d9890.cpp [wrapped: conflict: Singleton_4dd6ec]
// sym: ?run@FEMemCardControl_d9890@fn_000d9890@@QAEXH@Z @ebc300607d80 @wd0454cc67b7e
namespace fn_000d9890 {
// STATUS: equivalent (tools/equiv.py level 3: 16480 inputs, branch coverage 4/4)
// FUN_000d9890 @ 0x000d9890
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

struct View;
struct Item_d9890 { char pad[0x1c]; unsigned char active; char tail[0x1b]; int FUN_000f83f0(View*,int); };
struct View {   };
struct Manager_d9890 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual View* v44(); void FUN_000be310(const char*, char*, const float*,const float*,const float*,int,const char*,const char*); };
struct State_d9890 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d9890* FUN_00086280(); };
struct Control_d9890 {  };
    
extern void __cdecl FUN_000fc020(char*,int,int,...);
struct FEMemCardControl_d9890 { char p0[0x150]; Control_d9890* control; char p1[0x21c-0x154]; int field21c; char p2[0x35c-0x220]; Item_d9890 items[2]; char p3[0x3eb-0x3cc]; unsigned char flag; Manager_d9890* FUN_000fc3d0(); void run(int); };
void FEMemCardControl_d9890::run(int index) { char buffer[1024];  Manager_d9890* manager=FUN_000fc3d0(); View* view=manager->v44(); int a=((int)((owners::A_f7d30 *)view)->FUN_000f7d30((hulk_intptr)((*(const char**)&DAT_004a0cac)))); int b=((int)((owners::C_f7220 *)view)->FUN_000f7220((hulk_intptr)a)); int c=items[index].FUN_000f83f0(view,0); FUN_000fc020(buffer,512,b,c); const char* label; if(flag) label=(*(const char**)&DAT_004a0ce8); else { State_d9890* state=DAT_004dd6ec->FUN_00086280(); label=state->flag?(*(const char**)&DAT_004a0ce4):(*(const char**)&DAT_004a0ce0); } const char* value=(*(const char**)&DAT_004a0c60); manager->FUN_000be310(label,buffer,&DAT_003f335c,&DAT_003f335c,&DAT_003f335c,3,value,value); items[1].active=1; field21c=0; ((owners::MenuScreen_bc9f0 *)control)->FUN_000bc9f0((hulk_intptr)"DynamicControlButtonLabel", 0);  }
} // namespace fn_000d9890
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d99a0 FUN_000d99a0 (214 B): equivalent/0x000d99a0.cpp [wrapped: conflict: Singleton_4dd6ec]
// sym: ?FUN_000d99a0@FEMemCardControl_d99a0@fn_000d99a0@@QAEXH@Z @993af11e0d92 @wfdb0432e1849
namespace fn_000d99a0 {
// STATUS: equivalent (tools/equiv.py level 3: 18771 inputs, branch coverage 4/4)
// FUN_000d99a0 @ 0x000d99a0
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

struct TextService_d99a0 {   };
struct Dialog_d99a0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual TextService_d99a0* v44();
 void FUN_000be310(const char*, unsigned short*, const float*, const float*, const char*, int, const char*, const char*);
};
struct State_d99a0 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d99a0* FUN_00086280(); };
void __cdecl FUN_000fc020(unsigned short*, int, const unsigned short*, ...);
struct FEMemCardControl_d99a0 {
 char pad0[0x21c]; int value; char pad1[0x190]; unsigned char active; char pad2[0x3a]; unsigned char alternate;
 Dialog_d99a0* FUN_000fc3d0();
 void FUN_000d99a0(int);
};
void FEMemCardControl_d99a0::FUN_000d99a0(int) {
 unsigned short text[512];
 Dialog_d99a0* dialog = FUN_000fc3d0();
 TextService_d99a0* service = dialog->v44();
 int id = ((int)((owners::A_f7d30 *)service)->FUN_000f7d30((hulk_intptr)((*(const char**)&DAT_004a0cb4))));
 const unsigned short* source = ((const unsigned short *)((owners::C_f7220 *)service)->FUN_000f7220((hulk_intptr)id));
 FUN_000fc020(text, 512, source);
 const char* title;
 if (alternate) title = (*(const char**)&DAT_004a0ce8);
 else { State_d99a0* state = DAT_004dd6ec->FUN_00086280(); title = state->flag ? (*(const char**)&DAT_004a0ce4) : (*(const char**)&DAT_004a0ce0); }
 const char* style = (*(const char**)&DAT_004a0c60);
 dialog->FUN_000be310(title, text, ((float*)&DAT_003f335c), ((float*)&DAT_003f335c), "TBS_MENU_ITEM_OK", 2, style, style);
 active = 1;
 value = 0;
}
} // namespace fn_000d99a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d9a80 FUN_000d9a80 (214 B): equivalent/0x000d9a80.cpp [wrapped: conflict: Singleton_4dd6ec]
// sym: ?FUN_000d9a80@FEMemCardControl_d9a80@fn_000d9a80@@QAEXH@Z @b765c609e77e @w185cc27b6ec4
namespace fn_000d9a80 {
// STATUS: equivalent (tools/equiv.py level 3: 18875 inputs, branch coverage 4/4)
// FUN_000d9a80 @ 0x000d9a80
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

struct TextTable_d9a80 {
};
struct Dialog_d9a80 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
 virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
 virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
 virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
 virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
 virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
 virtual TextTable_d9a80* slot44();
 void FUN_000be310(const char*, const unsigned short*, const float*, const float*, const char*, int, const char*, const char*);
};
struct Status_d9a80 { char pad[0x1bc8]; unsigned char active; };
struct Singleton_4dd6ec { Status_d9a80* FUN_00086280(); };
void __cdecl FUN_000fc020(unsigned short*, int, const unsigned short*, ...);
struct FEMemCardControl_d9a80 {
 char pad0[0x21c]; int state;
 char pad1[0x3b0-0x220]; unsigned char visible;
 char pad2[0x3eb-0x3b1]; unsigned char mode;
 Dialog_d9a80* FUN_000fc3d0();
 void FUN_000d9a80(int);
};
void FEMemCardControl_d9a80::FUN_000d9a80(int) {
 unsigned short text[512];
 Dialog_d9a80* dialog = FUN_000fc3d0();
 TextTable_d9a80* table = dialog->slot44();
 int id = ((int)((owners::A_f7d30 *)table)->FUN_000f7d30((hulk_intptr)((*(const char**)&DAT_004a0cb0))));
 const unsigned short* source = ((const unsigned short *)((owners::C_f7220 *)table)->FUN_000f7220((hulk_intptr)id));
 FUN_000fc020(text, 512, source);
 const char* heading;
 if (mode) heading = (*(const char**)&DAT_004a0ce8);
 else {
 Status_d9a80* status = DAT_004dd6ec->FUN_00086280();
 heading = status->active ? (*(const char**)&DAT_004a0ce4) : (*(const char**)&DAT_004a0ce0);
 }
 const char* option = (*(const char**)&DAT_004a0c60);
 dialog->FUN_000be310(heading, text, ((float*)&DAT_003f335c), ((float*)&DAT_003f335c), "TBS_MENU_ITEM_OK", 2, option, option);
 visible = 1;
 state = 0;
}
} // namespace fn_000d9a80
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d9c40 FUN_000d9c40 (244 B): equivalent/0x000d9c40.cpp [wrapped: conflict: FUN_000fc020; FUN_000fc3d0; Singleton_4dd6ec]
// sym: ?run@FEMemCardControl_d9c40@fn_000d9c40@@QAEXXZ @11bf4a944091 @wb56b3c376a94
namespace fn_000d9c40 {
// STATUS: equivalent (tools/equiv.py level 3: 17117 inputs, branch coverage 4/4)
// FUN_000d9c40 @ 0x000d9c40
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

struct TextTable_d9c40 {   };
extern int __cdecl FUN_000fc020(char*, int, const char*, ...);
struct Screen_d9c40 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual TextTable_d9c40* v44();
 void FUN_000be310(const char*, const char*, const float*, const char*, const char*, int, const char*, const char*);
};
extern Screen_d9c40* __cdecl FUN_000fc3d0();
struct State_d9c40 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d9c40* FUN_00086280(); };
struct Control_d9c40 {  };
struct FEMemCardControl_d9c40 { char p0[0x150]; Control_d9c40* control; char p1[0x21c-0x154]; int value; char p2[0x34c-0x220]; int blocks; char p3[0x3b0-0x350]; unsigned char active; char p4[0x3eb-0x3b1]; unsigned char mode; void run(); };
void FEMemCardControl_d9c40::run() {
 char text[1024];
 Screen_d9c40* screen=FUN_000fc3d0();
 TextTable_d9c40* table=screen->v44();
 int count=4-blocks;
 const char* entry=((const char *)((owners::A_f7d30 *)table)->FUN_000f7d30((hulk_intptr)((*(const char**)&DAT_004a0cc4))));
 const char* format=((const char *)((owners::C_f7220 *)table)->FUN_000f7220((hulk_intptr)entry));
 FUN_000fc020(text,512,format,count);
 const char* label;
 if(mode) label=(*(const char**)&DAT_004a0ce8);
 else if(DAT_004dd6ec->FUN_00086280()->flag) label=(*(const char**)&DAT_004a0ce4);
 else label=(*(const char**)&DAT_004a0ce0);
 const char* extra=(*(const char**)&DAT_004a0c60);
 screen->FUN_000be310(label,text,((float*)&DAT_003f335c),"TBS_MENU_ITEM_CONTINUE_WITHOUT_SAVE","TBS_MENU_ITEM_FREE_MORE_BLOCKS",2,extra,extra);
 Control_d9c40* c=control;
 active=1;
 value=0;
 ((owners::MenuScreen_bc9f0 *)c)->FUN_000bc9f0((hulk_intptr)"DynamicControlButtonLabel", 3);
}
} // namespace fn_000d9c40
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d9d40 FUN_000d9d40 (245 B): equivalent/0x000d9d40.cpp [wrapped: conflict: FUN_000fc3d0; Singleton_4dd6ec]
// sym: ?FUN_000d9d40@FEMemCardControl_d9d40@fn_000d9d40@@QAEXXZ @ca78860411fb @wf6658ca89184
namespace fn_000d9d40 {
// STATUS: equivalent (tools/equiv.py level 3: 17216 inputs, branch coverage 4/4)
// FUN_000d9d40 @ 0x000d9d40
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

struct TextService_d9d40 { int FUN_000f7d30(const char*); const char* FUN_000f7220(int); };
struct Menu_d9d40 {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual TextService_d9d40* v44();
void FUN_000be310(const char*, const unsigned short*, const float*, const char*, const char*, int, const char*, const char*);
};
extern Menu_d9d40* __cdecl FUN_000fc3d0();
extern void __cdecl FUN_000fc020(unsigned short*, int, const char*, ...);
struct State_d9d40 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d9d40* FUN_00086280(); };
struct FEMemCardControl_d9d40 { char pad0[0x21c]; int value; char pad1[0x190]; unsigned char active; char pad2[0x3a]; unsigned char mode; void FUN_000d9d40(); };
void FEMemCardControl_d9d40::FUN_000d9d40() {
unsigned short buffer[512];
Menu_d9d40* menu = FUN_000fc3d0();
TextService_d9d40* text = menu->v44();
const char* secondKey = (*(const char**)&DAT_004a0c64);
const char* first = text->FUN_000f7220(text->FUN_000f7d30((*(const char**)&DAT_004a0cc8)));
const char* second = text->FUN_000f7220(text->FUN_000f7d30(secondKey));
FUN_000fc020(buffer,512,first,second);
const char* title;
if(mode) title=(*(const char**)&DAT_004a0ce8);
else if(DAT_004dd6ec->FUN_00086280()->flag) title=(*(const char**)&DAT_004a0ce4);
else title=(*(const char**)&DAT_004a0ce0);
const char* key=(*(const char**)&DAT_004a0c60);
menu->FUN_000be310(title,buffer,&DAT_003f335c,"TBS_MENU_ITEM_FREE_MORE_BLOCKS","TBS_CANCEL",2,key,key);
active=1; value=0;
}
} // namespace fn_000d9d40
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d9e80 FUN_000d9e80 (244 B): equivalent/0x000d9e80.cpp [wrapped: conflict: FUN_000fc3d0; Singleton_4dd6ec]
// sym: ?FUN_000d9e80@FEMemCardControl_d9e80@fn_000d9e80@@QAEXH@Z @f6177872a84b @wd520e3015bea
namespace fn_000d9e80 {
// STATUS: equivalent (tools/equiv.py level 3: 17625 inputs, branch coverage 4/4)
// FUN_000d9e80 @ 0x000d9e80
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

struct Item_d9e80 { char data[0x38]; int FUN_000f83f0(void*, int); };
struct Save {   };
struct Menu_d9e80 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual Save* v44();
 void FUN_000be310(const char*, char*, const char*, const char*, const char*, int, const char*, const char*);
};
struct State_d9e80 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d9e80* FUN_00086280(); };
Menu_d9e80* __cdecl FUN_000fc3d0();
void __cdecl FUN_000fc020(char*, int, int, ...);
struct FEMemCardControl_d9e80 {
 char pad0[0x21c]; int field21c; char pad1[0x35c-0x220]; Item_d9e80 items[1]; char pad2[0x3b0-0x394]; unsigned char flag3b0; char pad3[0x3eb-0x3b1]; unsigned char flag3eb;
 void FUN_000d9e80(int index);
};
void FEMemCardControl_d9e80::FUN_000d9e80(int index) {
 char buffer[1024];
 Menu_d9e80* menu=FUN_000fc3d0();
 Save* save=menu->v44();
 int a=((int)((owners::A_f7d30 *)save)->FUN_000f7d30((hulk_intptr)((*(int*)&DAT_004de650))));
 int b=((int)((owners::C_f7220 *)save)->FUN_000f7220((hulk_intptr)a));
 int c=items[index].FUN_000f83f0(save,0);
 FUN_000fc020(buffer,512,b,c);
 const char* text;
 if(flag3eb) text=(*(const char**)&DAT_004a0ce8);
 else { State_d9e80* state=DAT_004dd6ec->FUN_00086280(); text=state->flag ? (*(const char**)&DAT_004a0ce4) : (*(const char**)&DAT_004a0ce0); }
 const char* extra=(*(const char**)&DAT_004a0c60);
 menu->FUN_000be310(text,buffer,"TBS_MENU_ITEM_CONTINUE_WITHOUT_SAVE","TBS_MENU_ITEM_RETRY","TBS_INSTRUCTION_DELETE",1,extra,extra);
 flag3b0=1;
 field21c=0;
}
} // namespace fn_000d9e80
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d9f80 FUN_000d9f80 (244 B): equivalent/0x000d9f80.cpp [wrapped: conflict: Singleton_4dd6ec]
// sym: ?FUN_000d9f80@FEMemCardControl_d9f80@fn_000d9f80@@QAEXH@Z @7937b2291547 @w8d9747499c14
namespace fn_000d9f80 {
// STATUS: equivalent (tools/equiv.py level 3: 17706 inputs, branch coverage 4/4)
// FUN_000d9f80 @ 0x000d9f80
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

struct Resource_d9f80 {   };
struct Menu_d9f80 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual Resource_d9f80* v44();
 void FUN_000be310(void*,char*,float*,const char*,const char*,int,void*,void*);
};
struct Status_d9f80 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { Status_d9f80* FUN_00086280(); };
struct Entry_d9f80 { char pad[0x38]; void* FUN_000f83f0(Resource_d9f80*,int); };
   
extern void __cdecl FUN_000fc020(char*,int,void*,...);
struct FEMemCardControl_d9f80 {
 char pad0[0x21c]; int state; char pad1[0x13c]; Entry_d9f80 entries[2]; char pad2[0x1f]; unsigned char special;
 Menu_d9f80* FUN_000fc3d0();
 void FUN_000d9f80(int index);
};
void FEMemCardControl_d9f80::FUN_000d9f80(int index) {
 char text[1024];
 Menu_d9f80* menu = FUN_000fc3d0();
 Resource_d9f80* resource = menu->v44();
 int id = ((int)((owners::A_f7d30 *)resource)->FUN_000f7d30((hulk_intptr)((*(void**)&DAT_004de658))));
 void* format = ((void *)((owners::C_f7220 *)resource)->FUN_000f7220((hulk_intptr)id));
 void* value = entries[index].FUN_000f83f0(resource,0);
 FUN_000fc020(text,512,format,value);
 void* label;
 if (special) label = (*(void**)&DAT_004a0ce8);
 else { Status_d9f80* status = DAT_004dd6ec->FUN_00086280(); label = status->flag ? (*(void**)&DAT_004a0ce4) : (*(void**)&DAT_004a0ce0); }
 void* option = (*(void**)&DAT_004a0c60);
 menu->FUN_000be310(label,text,((float*)&DAT_003f335c),"TBS_MENU_ITEM_CONTINUE_WITHOUT_SAVE","TBS_MENU_ITEM_RETRY",2,option,option);
 entries[1].pad[0x1c] = 1;
 state = 0;
}
} // namespace fn_000d9f80
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000da180 FUN_000da180 (169 B): equivalent/0x000da180.cpp [wrapped: conflict: Singleton_4dd6ec]
// sym: ?target@FEMemCardControl_da180@fn_000da180@@QAEXH@Z @548d3c2560d3 @w73378f18447e
namespace fn_000da180 {
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 4/4)
// FUN_000da180 @ 0x000da180
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

struct Menu_da180 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); void FUN_000be310(const char*, char*, const float*, const char*, const char*, int, const char*, const char*); };
struct State_da180 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_da180* FUN_00086280(); };
struct FEMemCardControl_da180 { char pad[0x21c]; unsigned int value; char pad2[0x190]; unsigned char active; char pad3[0x3a]; unsigned char flag; Menu_da180* FUN_000fc3d0(); void target(int); };
void FEMemCardControl_da180::target(int) { char buffer[1024]; Menu_da180* menu=FUN_000fc3d0(); menu->v44(); const char* text; if(flag) text=(*(const char**)&DAT_004a0ce8); else if(DAT_004dd6ec->FUN_00086280()->flag) text=(*(const char**)&DAT_004a0ce4); else text=(*(const char**)&DAT_004a0ce0); const char* item=(*(const char**)&DAT_004a0c60); menu->FUN_000be310(text,buffer,&DAT_003f335c,"TBS_MENU_ITEM_CONTINUE_WITHOUT_SAVE","TBS_MENU_ITEM_RETRY",2,item,item); active=1; value=0;  }
} // namespace fn_000da180
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000da230 FUN_000da230 (333 B): matches/0x000da230.cpp [wrapped: conflict: Singleton_4dd6ec]
// sym: ?FUN_000da230@FEMemCardControl_da230@fn_000da230@@QAEXH@Z
namespace fn_000da230 {
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 10/10)
// FUN_000da230 @ 0x000da230
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

struct Locale {
    int FUN_000f7d30(const char* key);
    const char* FUN_000f7220(int id);
};

struct TextOwner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual Locale* v44();
};

struct Widget_da230 {
    int FUN_000f83f0(Locale* loc, int arg);
    char pad[0x38];
};

struct Settings_da230 {
    char pad[0x1bc8];
    char flag;
};

struct Singleton_4dd6ec {
    Settings_da230* FUN_00086280();
};

struct Screen_da230 {
    void FUN_000be310(const char* font, char* text, const float* a, const void* b, const void* c,
                      int n, const char* s1, const char* s2);
};

class FEMemCardControl_da230 {
public:
    void FUN_000da230(int idx);
    char p0[0x21c];
    int n21c;
    char p1[0x34c - 0x220];
    int offset;
    char p2[0x35c - 0x350];
    Widget_da230 widgets[1];
    char p3[0x3b0 - 0x35c - 0x38];
    char done;
    char p4[0x3ea - 0x3b1];
    char retryMode;
    char alt;
};

extern TextOwner* FUN_000fc3d0();
void FUN_000fc020(char* buf, int n, const char* fmt, ...);

void FEMemCardControl_da230::FUN_000da230(int idx)
{
    char buf[0x400];
    Screen_da230* screen = (Screen_da230*)FUN_000fc3d0();
    Locale* loc = ((TextOwner*)screen)->v44();
    const char* fmt = loc->FUN_000f7220(loc->FUN_000f7d30((*(const char**)&DAT_004de668)));
    int v = ((Widget_da230*)((char*)this + 0x35c + idx * 0x38))->FUN_000f83f0(loc, 0);
    FUN_000fc020(buf, 0x200, fmt, v);
    if (retryMode != 0) {
        const char* font;
        if (alt == 0) {
            if (DAT_004dd6ec->FUN_00086280()->flag != 0)
                font = (*(const char**)&DAT_004a0ce4);
            else
                font = (*(const char**)&DAT_004a0ce0);
        } else {
            font = (*(const char**)&DAT_004a0ce8);
        }
        screen->FUN_000be310(font, buf, ((float*)&DAT_003f335c), "TBS_MENU_ITEM_CONTINUE_WITHOUT_SAVE", "TBS_MENU_ITEM_RETRY", 2, (*(const char**)&DAT_004a0c60), (*(const char**)&DAT_004a0c60));
    } else {
        const char* font;
        if (alt == 0) {
            if (DAT_004dd6ec->FUN_00086280()->flag != 0)
                font = (*(const char**)&DAT_004a0ce4);
            else
                font = (*(const char**)&DAT_004a0ce0);
        } else {
            font = (*(const char**)&DAT_004a0ce8);
        }
        screen->FUN_000be310(font, buf, ((float*)&DAT_003f335c), ((float*)&DAT_003f335c), "TBS_MENU_ITEM_OK", 2, (*(const char**)&DAT_004a0c60), (*(const char**)&DAT_004a0c60));
    }
    done = 1;
    n21c = 0;
}
} // namespace fn_000da230
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000da480 FUN_000da480 (233 B): equivalent/0x000da480.cpp [wrapped: conflict: Singleton_4dd6ec]
// sym: ?target@FEMemCardControl_da480@fn_000da480@@QAEXH@Z @0353ea6cfb8e @w3851e3766242
namespace fn_000da480 {
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 4/4)
// FUN_000da480 @ 0x000da480
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

struct Texts_da480 {   };
struct Format_da480 { int FUN_000f83f0(Texts_da480*, int); };
struct Menu_da480 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual Texts_da480* v44(); void FUN_000be310(const char*, unsigned short*, const float*, const float*, const char*, int, const char*, const char*); };
struct State_da480 { char pad[0x1bc8]; unsigned char enabled; };
struct Singleton_4dd6ec { State_da480* FUN_00086280(); };
void __cdecl FUN_000fc020(unsigned short*, int, int, ...);
struct FEMemCardControl_da480 { char p0[0x21c]; int field21c; char p1[0x3b0-0x220]; unsigned char field3b0; char p2[0x3eb-0x3b1]; unsigned char field3eb; char p3[8]; Format_da480 format; Menu_da480* FUN_000fc3d0(); void target(int); };
void FEMemCardControl_da480::target(int) { unsigned short buffer[512]; Menu_da480* menu=FUN_000fc3d0(); Texts_da480* texts=menu->v44(); int id=((int)((owners::A_f7d30 *)texts)->FUN_000f7d30((hulk_intptr)((*(const char**)&DAT_004a0cd0)))); int text=((int)((owners::C_f7220 *)texts)->FUN_000f7220((hulk_intptr)id)); int fmt=format.FUN_000f83f0(texts,0); FUN_000fc020(buffer,512,text,fmt); const char* label; if(field3eb) label=(*(const char**)&DAT_004a0ce8); else { State_da480* state=DAT_004dd6ec->FUN_00086280(); label=state->enabled ? (*(const char**)&DAT_004a0ce4) : (*(const char**)&DAT_004a0ce0); } const char* extra=(*(const char**)&DAT_004a0c60); menu->FUN_000be310(label,buffer,&DAT_003f335c,&DAT_003f335c,"TBS_MENU_ITEM_OK",2,extra,extra); field3b0=1; field21c=0;  }
} // namespace fn_000da480
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000da570 FUN_000da570 (233 B): equivalent/0x000da570.cpp [wrapped: conflict: Singleton_4dd6ec]
// sym: ?FUN_000da570@FEMemCardControl_da570@fn_000da570@@QAEXH@Z @b85e3b13b761 @w76db1f9455e8
namespace fn_000da570 {
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 4/4)
// FUN_000da570 @ 0x000da570
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

struct TextSource_da570 {   };
struct Menu_da570 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual TextSource_da570* v44(); void FUN_000be310(const char*, unsigned short*, const float*, const float*, const char*, int, const char*, const char*); };
struct Formatter_da570 { const char* FUN_000f83f0(TextSource_da570*, int); };
struct State_da570 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_da570* FUN_00086280(); };
void __cdecl FUN_000fc020(unsigned short*, int, const char*, ...);
struct FEMemCardControl_da570 { char p0[0x21c]; int status; char p1[0x3b0-0x220]; unsigned char active; char p2[0x3eb-0x3b1]; unsigned char special; char p3[8]; Formatter_da570 formatter; Menu_da570* FUN_000fc3d0(); void FUN_000da570(int); };
void FEMemCardControl_da570::FUN_000da570(int) { unsigned short buffer[512]; Menu_da570* menu=FUN_000fc3d0(); TextSource_da570* source=menu->v44(); int id=((int)((owners::A_f7d30 *)source)->FUN_000f7d30((hulk_intptr)((*(const char**)&DAT_004a0cd4)))); const char* text=((const char *)((owners::C_f7220 *)source)->FUN_000f7220((hulk_intptr)id)); const char* format=formatter.FUN_000f83f0(source,0); FUN_000fc020(buffer,512,text,format); const char* title; if(special) title=(*(const char**)&DAT_004a0ce8); else { State_da570* state=DAT_004dd6ec->FUN_00086280(); title=state->flag ? (*(const char**)&DAT_004a0ce4) : (*(const char**)&DAT_004a0ce0); } const char* option=(*(const char**)&DAT_004a0c60); menu->FUN_000be310(title,buffer,((float*)&DAT_003f335c),((float*)&DAT_003f335c),"TBS_MENU_ITEM_OK",2,option,option); active=1; status=0;  }
} // namespace fn_000da570
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000da660 FUN_000da660 (233 B): equivalent/0x000da660.cpp [wrapped: conflict: Singleton_4dd6ec]
// sym: ?target@FEMemCardControl_da660@fn_000da660@@QAEXH@Z @e1097bd2cc63 @w9ecc626723bb
namespace fn_000da660 {
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 4/4)
// FUN_000da660 @ 0x000da660
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

struct TextSource_da660 {
};
struct Menu_da660 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual TextSource_da660* v44();
 void FUN_000be310(const char*, const unsigned short*, const char*, const char*, const char*, int, const char*, const char*);
};
struct Formatter_da660 { int FUN_000f83f0(TextSource_da660*, int); };
struct State_da660 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_da660* FUN_00086280(); };
void __cdecl FUN_000fc020(unsigned short*, int, const unsigned short*, ...);
struct FEMemCardControl_da660 {
 char pad0[0x21c]; int value; char pad1[0x3b0-0x220]; unsigned char active; char pad2[0x3eb-0x3b1]; unsigned char mode; char pad3[8]; Formatter_da660 formatter;
 Menu_da660* FUN_000fc3d0();
 void target(int);
};
void FEMemCardControl_da660::target(int) {
 unsigned short buffer[512];
 Menu_da660* menu = FUN_000fc3d0();
 TextSource_da660* source = menu->v44();
 int key = ((int)((owners::A_f7d30 *)source)->FUN_000f7d30((hulk_intptr)((*(const char**)&DAT_004a0cd8))));
 const unsigned short* text = ((const unsigned short *)((owners::C_f7220 *)source)->FUN_000f7220((hulk_intptr)key));
 int format = formatter.FUN_000f83f0(source, 0);
 FUN_000fc020(buffer, 512, text, format);
 const char* heading;
 if(mode) heading = (*(const char**)&DAT_004a0ce8);
 else { State_da660* state = DAT_004dd6ec->FUN_00086280(); heading = state->flag ? (*(const char**)&DAT_004a0ce4) : (*(const char**)&DAT_004a0ce0); }
 const char* option = (*(const char**)&DAT_004a0c60);
 menu->FUN_000be310(heading, buffer, "", "", "TBS_MENU_ITEM_OK", 2, option, option);
 active = 1;
 value = 0;
}
} // namespace fn_000da660
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000da830 FUN_000da830 (244 B): equivalent/0x000da830.cpp [wrapped: conflict: Singleton_4dd6ec]
// sym: ?run@FEMemCardControl_da830@fn_000da830@@QAEXH@Z @0a2b23a77baa @wfff3ab553488
namespace fn_000da830 {
// STATUS: equivalent (tools/equiv.py level 3: 18320 inputs, branch coverage 4/4)
// FUN_000da830 @ 0x000da830
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

struct Context;
struct Manager_da830 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual Context* v44(); void FUN_000be310(const char*,char*,const float*,const float*,const char*,int,const char*,const char*); };
struct Context { int FUN_000f7d30(const char*); const char* FUN_000f7220(int); };
struct Item_da830 { char pad[0x38]; const char* FUN_000f83f0(Context*,int); };
struct State_da830 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_da830* FUN_00086280(); };
extern void __cdecl FUN_000fc020(char*,int,const char*,...);
struct FEMemCardControl_da830 { char pad0[0x21c]; int field21c; char pad1[0x13c]; Item_da830 items[1]; char pad2[0x1c]; unsigned char active; char pad3[0x3a]; unsigned char mode; Manager_da830* FUN_000fc3d0(); void run(int index); };
void FEMemCardControl_da830::run(int index) { char buffer[1024]; Manager_da830* manager=FUN_000fc3d0(); Context* context=manager->v44(); const char* format=context->FUN_000f7220(context->FUN_000f7d30((*(const char**)&DAT_004a0cdc))); const char* value=items[index].FUN_000f83f0(context,0); FUN_000fc020(buffer,512,format,value); const char* text; if(mode) text=(*(const char**)&DAT_004a0ce8); else { State_da830* state=DAT_004dd6ec->FUN_00086280(); text=state->flag?(*(const char**)&DAT_004a0ce4):(*(const char**)&DAT_004a0ce0); } const char* option=(*(const char**)&DAT_004a0c60); manager->FUN_000be310(text,buffer,((float*)&DAT_003f335c),((float*)&DAT_003f335c),"TBS_MENU_ITEM_OK",2,option,option); active=1; field21c=0;  }
} // namespace fn_000da830
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000da930 FEMemCardControl::vfunc_4 (5290 B): equivalent/0x000da930.cpp [wrapped: conflict: DAT_004a0c88; FEMemCardControl; FUN_000fc3d0; Singleton_4dd6ec]
// sym: ?vfunc_4@FEMemCardControl@fn_000da930@@UAEXXZ @2054c1ac4712 @wd4d85e8745cd
namespace fn_000da930 {
// STATUS: equivalent (tools/equiv.py level 3: 3442 inputs, branch coverage 314/320, incomplete)
// FEMemCardControl::vfunc_4 @ 0x000da930
// cl-flags: /GS
// FEMemCardControl::vfunc_4 @ 0x000da930
// FEMemCardControl::vfunc_4 @ 0x000da930
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


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sin(double);
#endif

extern float (__cdecl *DAT_004de948)();
extern unsigned char DAT_004dd841;
extern void* DAT_004a0c88;
static const char kLabel[] = "DynamicControlButtonLabel";

class FEMemCardControl;
struct Fn1_da930 {
    void (FEMemCardControl::*fn)(int);
};
struct Fn2_da930 {
    void (FEMemCardControl::*fn)(int, int);
};

struct Item_da930 {
    char data[0x24];
    void FUN_000f79a0(int a, int b);
    void FUN_000f8500(void* a, int b, int c);
    void FUN_000f83c0(Item_da930* other);
};

struct Singleton_4dd6ec {
    void FUN_00086310();
};

struct Stage2_da930 {
    void FUN_0008ca30(int a);
    void FUN_0008c920();
    void FUN_0008c680(int a);
};

struct Stage1_da930 {
    Stage2_da930* FUN_00089a50();
    char FUN_0008b4b0(int idx, unsigned char* active, char* buf, int len, char* extra, int* out);
    void FUN_0008a8f0(int a, Singleton_4dd6ec* m);
    void FUN_00089830(const char* s);
    void FUN_000895e0(void* p);
    void FUN_00089810(const char* s);
    void FUN_00089300(const char* s);
    bool FUN_000893c0();
    int FUN_000891e0();
};

struct Obj50_da930 {
    void FUN_0008ffe0();
};

struct Label_da930 {
    char pad0[0x50];
    Obj50_da930* obj50;
    char pad54[0x1bc8 - 0x54];
    unsigned char f1bc8;
    Stage1_da930* FUN_000b5000();
    void FUN_000bc9f0(const char* name, int mode);
    void* FUN_000b4cf0(const char* name);
};

struct Delegate_da930 {
    FEMemCardControl* self;
    int pad4;
    char fnA[16];
    char fnB[16];
    int arg0;
    int arg1;
    void FUN_000d7be0(Fn1_da930 f, int a);
    void FUN_000d7c30(Fn2_da930 f, int a, int b);
    void FUN_000d7c80();
    void FUN_000d7d10();
};

struct Child_da930 { char pad[0xab9]; unsigned char flag; };
struct Parent_da930 { char pad[0x175c]; Child_da930* child; };

class Sink_da930 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(int mode);
};
struct Hub_da930 { char pad0[4]; Sink_da930* sink; };
struct Holder_da930 { char pad0[8]; Hub_da930* hub; };

struct Player_da930 { char pad0[0x9a8]; unsigned char busy; };
class UI_da930 {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual int s44();
    char pad[0x2218 - 4];
    Player_da930* player;
    int status;
    void FUN_000e63a0();
};
UI_da930* __cdecl FUN_000fc3d0();
extern "C" void __cdecl FUN_000fc2f0();
extern "C" void __cdecl FUN_000fc300();

struct Frame_da930 {
    char pad0[2];
    char gotA, gotB;
    int outv;
    int kind0;
    int pad[1];
    char buf[0x40];
};

struct Entry_da930 {
    Item_da930 item;
    char pad24[12];
    unsigned char active;
    char pad31[7];
    unsigned char flag;
    char pad39[3];
};

struct Slot_da930 {
    int f0;
    int f4;
    int kind;
    int count;
    Item_da930 item;
    unsigned char flag;
    char pad35[3];
};

class FEMemCardControl {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11();
    virtual char vfunc_12(int cmd, int unused);
    char pad04[0x10];
    Holder_da930* holder;
    char pad18[0xa8 - 0x18];
    Parent_da930* parent;
    char pada8[0x150 - 0xac];
    Label_da930* label;
    char pad154[0x1d0 - 0x154];
    int sel;
    int sel2;
    char pad1d8[0x21c - 0x1d8];
    float f21c;
    Entry_da930 entries[5];
    Slot_da930 slots[1];
    char pad384[0x3a8 - 0x34c - 0x38];
    unsigned char f3a8;
    char pad3a9[3];
    int state;
    char pad3b0[0x3c8 - 0x3b0];
    float f3c8;
    char pad3cc[0x3e4 - 0x3cc];
    float f3e4;
    unsigned char f3e8, f3e9, f3ea, f3eb, f3ec;
    char pad3ed[3];
    const char* name;
    Item_da930 item3;
    int f418;
    int f41c;
    int f420;
    char pad424[4];
    Delegate_da930 cb;

    void FUN_000d8410();
    void FUN_000d7ec0(int a);
    void FUN_000d7ef0(int a);
    bool FUN_000d7f30();
    void FUN_000d7f60();
    void FUN_000d8150();
    int FUN_000d8170(int a, int b);
    int FUN_000d8190(int a, int b);
    int FUN_000d81c0(int a, int b);
    int FUN_000d8220(int a);
    void FUN_000d88f0(int id, char* a, char* b);
    void FUN_000d8cb0(int a, int b);
    void FUN_000d8dd0(int a);
    void FUN_000d9180(int a);
    void FUN_000d92c0(int a);
    void FUN_000d94e0(int a);
    void FUN_000d9890(int a);
    void FUN_000d9c40();
    void FUN_000d9d40();
    void FUN_000d9e80(int a);
    void FUN_000d9f80(int a);
    void FUN_000da180(int a);
    void FUN_000da230(int a);
    void FUN_000da830(int a);
    void FUN_000d8ec0(int a, int b);
    void FUN_000d8fa0(int a, int b);
    void FUN_000d9080(int a, int b);
    void FUN_000d9100(int a, int b);
    void FUN_000d95a0(int a);
    void FUN_000d9680(int a);
    void FUN_000d99a0(int a);
    void FUN_000d9a80(int a);
    void FUN_000da480(int a);
    void FUN_000da570(int a);
    void FUN_000da660(int a);
};


void FEMemCardControl::vfunc_4()
{
    Frame_da930 fr;
    char& gotA = fr.gotA;
    char& gotB = fr.gotB;
    int& outv = fr.outv;
    char* buf = fr.buf;
    {
        hulk_freg t = DAT_004de948() * 6.2831855f + f3e4;
        f3c8 = (float)((sin((double)t) + 1.0f) * 0.5f);
        outv = (int)(0.15915494f * t);
        f3e4 = t - outv * 6.2831855f;
        if (*(volatile float*)&f3e4 >= 0.0f && *(volatile float*)&f3e4 <= 6.2831855f) {
        } else if (!(*(volatile float*)&f3e4 > 6.2831855f)) {
            f3e4 = 0.0f;
        } else {
            f3e4 = 6.2831855f;
        }
    }
    f21c += DAT_004de948();
    int cur = state;
    if (cur == 0)
        f3eb = 0;
    if (f3e8) {
        state = 0x1f;
        f3e9 = 1;
    } else if (!f3eb || cur == 0x10 || cur == 0x13 || cur == 0xb || cur == 0xc || cur == 9 || cur == 8 || cur == 0xd || cur == 0) {
        FUN_000d8410();
    }
    switch (state) {
    case 0:
        if (f3a8) {
            switch (slots[sel].kind) {
            case 0:
            case 7:
                FUN_000d8150();
                FUN_000d88f0(sel, &gotA, &gotB);
                if (slots[sel].kind == 7 && !gotA) {
                    FUN_000d9180(sel);
                    state = 0x1f;
                    break;
                }
                holder->hub->sink->v48(0);
                state = 2;
                break;
            case 4:
                FUN_000d92c0(sel);
                state = 0x1f;
                break;
            case 5:
                state = 0xb;
                FUN_000d7ec0(sel);
                break;
            default:
                break;
            }
        } else {
            switch (slots[sel].kind) {
            case 0:
            case 7:
                FUN_000d8150();
                FUN_000d88f0(sel, &gotA, &gotB);
                if (!gotA && !gotB) {
                    FUN_000da830(sel);
                    state = 0x1f;
                }
                holder->hub->sink->v48(0);
                state = 2;
                break;
            case 4:
                FUN_000d92c0(sel);
                state = 0x1f;
                break;
            case 5:
                state = 0xb;
                FUN_000d7ef0(sel);
                break;
            default:
                break;
            }
        }
        break;
    case 1: {
        Player_da930* p = FUN_000fc3d0()->player;
        if (p && p->busy)
            break;
        int r = FUN_000fc3d0()->status;
        if (r == 1) {
            state = 0x1f;
            f3e9 = 1;
        } else if (r == 2) {
            state = 0;
        }
        break;
    }
    case 2: {
        int i;
        for (i = 0; i < 5; ++i) {
            if (!label->FUN_000b5000()->FUN_0008b4b0(i, &entries[i].active, buf, 0x40, entries[i].pad24, &outv))
                break;
            entries[i].item.FUN_000f79a0(outv, 0);
            if (entries[i].flag) {
                entries[i].active = 1;
                entries[i].item.FUN_000f8500(DAT_004a0c88, FUN_000fc3d0()->s44(), 1);
            }
            if (!f3a8)
                FUN_000d7f60();
        }
        state = (i < 5) ? 0 : 3;
        break;
    }
    case 3: {
        if (!f3a8 && sel2 >= 0 && !entries[sel2].active)
            FUN_000d7f60();
        Player_da930* p = FUN_000fc3d0()->player;
        if (p && p->busy)
            break;
        if (sel2 < 0) {
            label->FUN_000bc9f0(kLabel, 2);
            break;
        }
        if (entries[sel2].active) {
            if (f3a8)
                label->FUN_000bc9f0(kLabel, 6);
            else
                label->FUN_000bc9f0(kLabel, 9);
        } else {
            label->FUN_000bc9f0(kLabel, 8);
        }
        break;
    }
    case 4:
        if (f21c < 0.2f)
            break;
        item3.FUN_000f83c0(&slots[sel].item);
        {
            int r = FUN_000d8190(sel, sel2);
            state = 0x1d;
            if (r == 4 || r == 3) {
                *(volatile int*)&f418 = 0xa;
                { Fn1_da930 x = { &FEMemCardControl::FUN_000da480 }; cb.FUN_000d7be0(x, sel); }
                break;
            }
            if (r == 7) {
                while (FUN_000d7f30())
                    FUN_000fc3d0()->FUN_000e63a0();
                f418 = 0x1f;
                f41c = 0x1f;
                state = 0x11;
                FUN_000d9c40();
                break;
            }
            if (r != 0) {
                *(volatile int*)&f418 = 0xa;
                { Fn2_da930 x = { &FEMemCardControl::FUN_000d8ec0 }; cb.FUN_000d7c30(x, sel, sel2); }
                break;
            }
            *(volatile int*)&f418 = 0x1f;
            { Fn2_da930 x = { &FEMemCardControl::FUN_000d9080 }; cb.FUN_000d7c30(x, sel, sel2); }
            f3e9 = 1;
            if (label->f1bc8) {
                f3ec = 1;
                DAT_004dd6ec->FUN_00086310();
                name = "end_level_already_saved";
            }
        }
        break;
    case 5:
        if (f21c < 0.2f)
            break;
        item3.FUN_000f83c0(&slots[sel].item);
        {
            int r = FUN_000d8170(sel, sel2);
            state = 0x1d;
            if (r == 4 || r == 3) {
                { Fn1_da930 x = { &FEMemCardControl::FUN_000da570 }; cb.FUN_000d7be0(x, sel); }
                f418 = 0xa;
                break;
            }
            if (r != 0) {
                { Fn2_da930 x = { &FEMemCardControl::FUN_000d8fa0 }; cb.FUN_000d7c30(x, sel, sel2); }
                f418 = 0xa;
                break;
            }
            label->FUN_000b5000()->FUN_0008a8f0(sel2, DAT_004dd6ec);
            { Fn2_da930 x = { &FEMemCardControl::FUN_000d9100 }; cb.FUN_000d7c30(x, sel, sel2); }
            f418 = 0x1f;
            f3e9 = 1;
        }
        break;
    case 6:
        if (f21c < 0.2f)
            break;
        item3.FUN_000f83c0(&slots[sel].item);
        {
            int r = FUN_000d8220(sel);
            state = 0x1d;
            if (r == 0) {
                { Fn1_da930 x = { &FEMemCardControl::FUN_000d95a0 }; cb.FUN_000d7be0(x, sel); }
                f418 = 0x1f;
                break;
            }
            if (r != 4 && f3eb) {
                { Fn1_da930 x = { &FEMemCardControl::FUN_000da230 }; cb.FUN_000d7be0(x, sel); }
                f418 = 0x1a;
            } else {
                { Fn1_da930 x = { &FEMemCardControl::FUN_000d9680 }; cb.FUN_000d7be0(x, sel); }
                f418 = 0x10;
            }
            label->FUN_000b5000()->FUN_00089a50()->FUN_0008c920();
            slots[sel].kind = 6;
            slots[sel].f4 = 6;
        }
        break;
    case 0x1c:
        if (f21c < 1.0f)
            break;
        while (FUN_000d7f30())
            FUN_000fc3d0()->FUN_000e63a0();
        state = 4;
        FUN_000d8dd0(sel);
        break;
    case 8:
    case 0x19:
        if (FUN_000d7f30())
            break;
        if (FUN_000fc3d0()->status != 1) {
            state = 3;
            break;
        }
        state = 4;
        FUN_000d8dd0(sel);
        break;
    case 0x1e:
        break;
    case 7:
        if (f21c < 0.2f)
            break;
        item3.FUN_000f83c0(&slots[sel].item);
        {
            int r = FUN_000d81c0(sel, sel2);
            state = 0x1d;
            if (r == 4 || r == 3) {
                { Fn1_da930 x = { &FEMemCardControl::FUN_000da660 }; cb.FUN_000d7be0(x, sel); }
                f418 = 0xa;
                break;
            }
            if (r != 0) {
                { Fn1_da930 x = { &FEMemCardControl::FUN_000d9a80 }; cb.FUN_000d7be0(x, sel); }
                f418 = 3;
                break;
            }
            entries[sel2].active = 0;
            slots[sel].count -= 1;
            { Fn1_da930 x = { &FEMemCardControl::FUN_000d99a0 }; cb.FUN_000d7be0(x, sel); }
            if (!f3a8) {
                FUN_000d7f60();
                if (sel2 < 0) {
                    f418 = 0;
                    slots[sel].flag = 0;
                    break;
                }
            }
            f418 = 0;
        }
        break;
    case 9:
        if (FUN_000d7f30())
            break;
        if (FUN_000fc3d0()->status != 1) {
            state = 3;
            break;
        }
        state = 5;
        FUN_000d8cb0(sel, 0);
        break;
    case 0xd:
        if (FUN_000d7f30())
            break;
        if (FUN_000fc3d0()->status != 1) {
            state = 3;
            break;
        }
        state = 7;
        FUN_000d9890(sel);
        break;
    case 0x1f:
        if (FUN_000d7f30())
            break;
        label->FUN_000b5000()->FUN_00089a50()->FUN_0008ca30(0);
        if (f3e8 && f3e9) {
            label->FUN_000b5000()->FUN_00089830("c00m01");
            void* item = label->FUN_000b4cf0("c00m01");
            if (!item)
                break;
            if (!label->FUN_000b5000()->FUN_000893c0())
                label->obj50->FUN_0008ffe0();
            label->FUN_000b5000()->FUN_000895e0(item);
            label->FUN_000b5000()->FUN_00089810("c00m01");
            label->FUN_000b5000()->FUN_00089300("story");
            state = 0x20;
            break;
        }
        if (f3ea) {
            FUN_000fc300();
            state = 0x20;
            break;
        }
        FUN_000fc2f0();
        state = 0x20;
        break;
    case 0xa:
        if (FUN_000d7f30())
            break;
        state = f3eb ? 0x1f : 0;
        break;
    case 0xb:
        if (FUN_000d7f30())
            break;
        if (FUN_000fc3d0()->status == 1) {
            state = 6;
            FUN_000d94e0(sel);
            break;
        }
        state = 0x1f;
        break;
    case 0xc:
        if (FUN_000d7f30())
            break;
        if (FUN_000fc3d0()->status == 1) {
            state = 6;
            FUN_000d94e0(sel);
            break;
        }
        state = f3eb ? 0xf : 0x1f;
        break;
    case 0xf:
        label->FUN_000bc9f0(kLabel, 0);
        if (FUN_000d7f30())
            break;
        slots[0].flag = 0;
        state = 0x10;
        break;
    case 0x10: {
        int* kinds = &fr.kind0;
        kinds[0] = slots[0].kind;
        for (int i = 0; i < 1; ++i) {
            int kind = kinds[i];
            sel = i;
            if (kind == 4) {
                if (DAT_004dd841) {
                    state = f41c;
                } else {
                    state = 0x13;
                    FUN_000da180(0);
                }
                break;
            } else if (kind == 5 || kind == 9) {
                state = 0x14;
                FUN_000d7ef0(i);
                break;
            } else if (kind == 6) {
                state = 0x1a;
                FUN_000da230(i);
                break;
            } else if (kind == 7 || kind == 0) {
                int& found = fr.outv;
                found = 1;
                for (int j = 0; j < 5; ++j) {
                    int r = FUN_000d8170(i, j);
                    if (r == 0)
                        found = r;
                }
                if (found == 0 || found == 0xc) {
                    int k = kinds[i];
                    if (k == 0 || k == 7) {
                        if (!f3eb) {
                            state = f41c;
                        } else {
                            FUN_000d8cb0(sel, 1);
                            sel2 = label->FUN_000b5000()->FUN_000891e0();
                            state = 0x1d;
                            f418 = 5;
                        }
                    } else if (k == 0xc) {
                        state = 0x1d;
                        f418 = 0x18;
                        FUN_000d9e80(i);
                    } else {
                        state = f41c;
                    }
                    break;
                }
                if (kind == 7) {
                    state = 0x11;
                    FUN_000d9c40();
                    break;
                }
                state = f41c;
            } else if (kind == 0xa || kind == 0xb) {
                state = 0x17;
                FUN_000d9f80(i);
                break;
            }
        }
        if (!FUN_000d7f30())
            break;
        parent->child->flag = 1;
        label->FUN_000bc9f0(kLabel, 3);
        break;
    }
    case 0x11:
        if (FUN_000d7f30())
            break;
        if (FUN_000fc3d0()->status == 1) {
            state = f41c;
            break;
        }
        holder->hub->sink->v48(0);
        state = 0x12;
        FUN_000d9d40();
        break;
    case 0x12:
        if (FUN_000d7f30())
            break;
        if (FUN_000fc3d0()->status != 1) {
            state = 0xf;
            break;
        }
        label->FUN_000b5000()->FUN_00089a50()->FUN_0008c680(sel);
        break;
    case 0x13:
        if (FUN_000d7f30())
            break;
        if (FUN_000fc3d0()->status != 1) {
            state = 0xf;
            break;
        }
        state = f420;
        break;
    case 0x14: {
        if (FUN_000d7f30())
            break;
        int r = FUN_000fc3d0()->status;
        if (r == 0) {
            state = f41c;
            break;
        }
        if (r == 1) {
            if (f3eb) {
                state = 0xf;
                break;
            }
            state = 0;
            vfunc_12(8, 0);
            break;
        }
        state = 6;
        FUN_000d94e0(sel);
        break;
    }
    case 0x16:
    case 0x17:
    case 0x1a:
        if (FUN_000d7f30())
            break;
        if (FUN_000fc3d0()->status != 1) {
            state = 0xf;
            break;
        }
        state = f41c;
        break;
    case 0x18: {
        if (FUN_000d7f30())
            break;
        int r = FUN_000fc3d0()->status;
        if (r == 0) {
            state = f41c;
            break;
        }
        if (r == 1) {
            state = 0xf;
            break;
        }
        state = 0x1b;
        FUN_000d9890(sel);
        break;
    }
    case 0x1b:
        if (f21c < 0.2f)
            break;
        item3.FUN_000f83c0(&slots[sel].item);
        {
            int r = FUN_000d81c0(sel, sel2);
            // the state is stored before the callback is registered (volatile keeps the store in front of the call)
            *(volatile int*)&state = 0x1d;
            if (r != 0) {
                { Fn1_da930 x = { &FEMemCardControl::FUN_000d9a80 }; cb.FUN_000d7be0(x, sel); }
            } else {
                { Fn1_da930 x = { &FEMemCardControl::FUN_000d99a0 }; cb.FUN_000d7be0(x, sel); }
            }
            f418 = f3eb ? 0xf : 0;
        }
        break;
    case 0x1d:
        if (f21c < 1.0f)
            break;
        if (FUN_000d7f30())
            FUN_000fc3d0()->FUN_000e63a0();
        state = f418;
        cb.FUN_000d7c80();
        cb.FUN_000d7d10();
        break;
    default:
        break;
    }
}
} // namespace fn_000da930
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

