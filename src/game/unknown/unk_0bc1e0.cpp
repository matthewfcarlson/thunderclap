// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000bc1e0..0x000be1c0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f87c96cc {
#define TREE_TU_END }
namespace fn_f87c96cc {} using namespace fn_f87c96cc;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f87c96cc {
extern "C" void __cdecl FUN_000fc280(int);
class Child {
  public:
};
class Obj {
  public:
    char a[0x10];
    int state;
    char b[0x1c];
    Child* ptr;
    char c[0x1cc8];
    int flag;
    void run(hulk_intptr);
    void f2_000b90c0(int);
};
} // namespace fn_f87c96cc
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char *__cdecl strncpy(char *dst, const char *src, unsigned n);
#endif
namespace fn_f87c96cc {
class Manager_bc230 { public: char pad[4]; };
extern "C" Manager_bc230 *__cdecl FUN_000fc1b0();
struct TextEntry_bc230 {
    void FUN_000f8500(const char *name, Manager_bc230 *manager, char flag);
};
class FEObject_bc230 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x10];
    int f14;
    TextEntry_bc230 entry;
};
class TextLabel_bc230 : public FEObject_bc230 {
public:
    virtual void vfunc_4();
};
class TextWindow_bc230 : public FEObject_bc230 {
public:
    virtual void vfunc_4();
};
class TextButton_bc230 : public FEObject_bc230 {
public:
    virtual void vfunc_4();
};
extern "C" FEObject_bc230 *__cdecl FUN_000fc260(const char *name);
class Widget_bc230 {
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
    virtual void vfunc_19(int a);
};
class Hook_bc230 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Widget_bc230 *vfunc_3(const char *name);
};
extern "C" Hook_bc230 *__cdecl FUN_000fc3d0();
struct Sys_bc230 {
};
} // namespace fn_f87c96cc
struct World {
    char pad[0x2c];
    Sys_bc230 *sys;
};
namespace fn_f87c96cc {
class QuestionScreen {
public:
    char pad0[0x1c0c];
    char answer1[0x40];
    char answer2[0x40];
    void FUN_000bc230(const char *title, const char *text, const char *ans1, char *buf1, const char *ans2, char *buf2);
};
struct Obj_bc4d0;
extern void* g_b_bc4d0;
void __cdecl Fa_000fc130(void*);
void __cdecl Release_0008d340(void*);
Obj_bc4d0* Fc_000fc1b0();
struct Obj_bc4d0 {
    void Fd_000f7ce0();
};
struct Sub_bc4d0 {
    void Fe_001bdf00();
};
struct Mgr_bc4d0 {
    void Ff_002665a0();
};
struct Dev_bc4d0 {
    void Fg_00294980(int);
};
struct Main_bc4d0 {
    char pad0[0x10];
    int state;
    char pad1[0xc];
    Dev_bc4d0* dev;
    int arg;
    char pad2[0x34];
    Sub_bc4d0* sub;
    char pad3[0xc];
    void* a[0x80];
    void* b[0x80];
    char pad4[0x1bc8 - 0x46c];
    char flag;
    void Run();
};
struct Listener_bc5c0 { void FUN_00093c40(int); };
struct Player_bc5c0 {  void FUN_00089810(int);  void FUN_00089300(const char*); void FUN_00089a20(int); };
struct Object {
 char pad0[0x30]; void* resource; Player_bc5c0* player; char pad38[0x14]; Listener_bc5c0* listener;
 bool FUN_000b4dc0(const char*);
 void FUN_000bc5c0(const char* name, hulk_intptr id, int mode, int unused);
};
class Manager_bc750 {
  public:
    void FnA_00089a30(int);
    void* FnB_0008a2f0();
    void FnD_00089810(void*);
};
class Other_bc750 {
  public:
    void FnF_00093c40(void*);
};
class Obj_bc750 {
  public:
    char pad0[0x34];
    Manager_bc750* m34;
    Other_bc750* m38;
    char pad40[0x10];
    Other_bc750* m4c;
    void End();
};
extern "C" {
int __cdecl FUN_00209f50();
}
extern "C" {
char __cdecl FUN_000b51c0(int);
}
extern "C" {
const char* __cdecl FUN_000f7120(int);
}


// 0x000bc1e0 FUN_000bc1e0 (68 B): matches/0x000bc1e0.cpp
// sym: ?run@Obj@fn_f87c96cc@@QAEXH@Z
void Obj::run(hulk_intptr arg) {
    if (state != 9) {
        state = 9;
        flag = 0;
        FUN_000fc280(arg);
        if (ptr) {
            ((owners::Target_863e0 *)ptr)->FUN_000863e0(6);
            f2_000b90c0(1);
        }
    }
}


// 0x000bc230 FUN_000bc230 (399 B): matches/0x000bc230.cpp
// sym: ?FUN_000bc230@QuestionScreen@fn_f87c96cc@@QAEXPBD00PAD01@Z
// FUN_000bc230 @ 0x000bc230
void QuestionScreen::FUN_000bc230(const char *title, const char *text, const char *ans1, char *buf1, const char *ans2, char *buf2)
{
    TextLabel_bc230 *label = dynamic_cast<TextLabel_bc230 *>(FUN_000fc260("fullscreen_question_title"));
    if (label) {
        label->entry.FUN_000f8500(title, FUN_000fc1b0(), 1);
        label->vfunc_3();
    }
    TextWindow_bc230 *win = dynamic_cast<TextWindow_bc230 *>(FUN_000fc260("fullscreen_question_text"));
    if (win) {
        win->entry.FUN_000f8500(text, FUN_000fc1b0(), 1);
        win->vfunc_3();
    }
    TextButton_bc230 *b1 = dynamic_cast<TextButton_bc230 *>(FUN_000fc260("fullscreen_question_answer1"));
    if (b1) {
        b1->entry.FUN_000f8500(ans1, FUN_000fc1b0(), 1);
        // original calls through the previous object (win), not b1
        win->vfunc_3();
    }
    TextButton_bc230 *b2 = dynamic_cast<TextButton_bc230 *>(FUN_000fc260("fullscreen_question_answer2"));
    if (b2) {
        b2->entry.FUN_000f8500(ans2, FUN_000fc1b0(), 1);
        win->vfunc_3();
    }
    strncpy(answer1, buf1, 0x40);
    strncpy(answer2, buf2, 0x40);

    Widget_bc230 *w = FUN_000fc3d0()->vfunc_3("fullscreen_question");
    if (w) {
        FEObject_bc230 *a = FUN_000fc260("fullscreen_question_answer1");
        if (a)
            w->vfunc_19(a->f14);
    }
    ((::CScenarioManager *)(DAT_004dd700->sys))->FUN_001cc620(11);
}


// 0x000bc4d0 FUN_000bc4d0 (172 B): matches/0x000bc4d0.cpp
// sym: ?Run@Main_bc4d0@fn_f87c96cc@@QAEXXZ
// data: g_mgr_bc4d0 = DAT_004dd9cc
void Main_bc4d0::Run() {
    Fa_000fc130((*(void**)&DAT_0049f3b0));
    int i;
    for (i = 0; i < 0x80; i++) {
        if (!a[i])
            break;
        Release_0008d340(a[i]);
        a[i] = 0;
    }
    for (i = 0; i < 0x80; i++) {
        if (!b[i])
            break;
        Release_0008d340(b[i]);
        b[i] = 0;
    }
    FUN_000fc160();
    Obj_bc4d0* o = Fc_000fc1b0();
    if (o)
        o->Fd_000f7ce0();
    if (sub)
        sub->Fe_001bdf00();
    (*(Mgr_bc4d0**)&DAT_004dd9cc)->Ff_002665a0();
    dev->Fg_00294980(arg);
    state = 3;
    flag = 0;
}


// 0x000bc5c0 FUN_000bc5c0 (213 B): equivalent/0x000bc5c0.cpp
// sym: ?FUN_000bc5c0@Object@fn_f87c96cc@@QAEXPBDHHH@Z @4101bee53eda @wec3979453d49
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_000bc5c0 @ 0x000bc5c0
void Object::FUN_000bc5c0(const char* name, hulk_intptr id, int mode, int unused) {
 if (!resource || !player) return;
 if (!FUN_000b4dc0(name)) return;
 if (!((owners::K_b4c10 *)this)->FUN_000b4c10((const char *)(hulk_uintptr)(int)id)) return;
 int selected = 0;
 if (((owners::K_b4c10 *)this)->FUN_000b4c10((const char *)(hulk_uintptr)(int)id)) {
 selected = ((int)((owners::NameTable_b4cf0 *)this)->FUN_000b4cf0((const char *)(hulk_uintptr)(int)id));
 if (!selected) return;
 }
 const char* match = "oneshot";
 for (int i=0;i<8;++i) if (name[i]!=match[i]) return;
 if (listener) listener->FUN_00093c40(id);
 ((owners::LevelName_895e0 *)player)->FUN_000895e0((const char *)(hulk_uintptr)(int)selected);
 player->FUN_00089810(id);
 int chosen = DAT_0049cab4;
 if (chosen < 0 || chosen >= 3) chosen = mode;
 ((owners::C_895c0 *)player)->FUN_000895c0(chosen);
 player->FUN_00089300(name);
 player->FUN_00089a20(1);
}


// 0x000bc750 FUN_000bc750 (107 B): matches/0x000bc750.cpp
// sym: ?End@Obj_bc750@fn_f87c96cc@@QAEXXZ
void Obj_bc750::End() {
    if (m34 && m38) {
        ((::CScenarioManager *)m38)->FUN_001cc620(9);
        m34->FnA_00089a30(0);
        void* edi = m34->FnB_0008a2f0();
        if (edi) {
            int ebx = ((int)((owners::NameTable_b4cf0 *)this)->FUN_000b4cf0((const char *)edi));
            if (ebx) {
                if (m4c)
                    m4c->FnF_00093c40(edi);
                ((owners::LevelName_895e0 *)m34)->FUN_000895e0((const char *)(hulk_uintptr)(int)ebx);
                m34->FnD_00089810(edi);
                FUN_000fc300();
            }
        }
    }
}


// 0x000bc7c0 FUN_000bc7c0 (222 B): equivalent/0x000bc7c0.cpp
// sym: _FUN_000bc7c0 @5b18e88d0344 @w1416cf69464f
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/20, incomplete)
// FUN_000bc7c0 @ 0x000bc7c0
extern "C" void FUN_000bc7c0(char* dest) {
    int key = FUN_00209f50();
    int slot = 0;
    switch (key) {
    case 2: slot = 3; break;
    case 4: slot = 1; break;
    case 5: slot = 4; break;
    case 6: slot = 2; break;
    }
    if (DAT_004dd839 && slot == 0)
        slot = 5;
    int found = slot;
    if (!FUN_000b51c0(found)) {
        for (found = 0; found < 6; found++) {
            if (FUN_000b51c0(found))
                break;
        }
        if (found >= 6)
            return;
    }
    strncpy(dest, FUN_000f7120(found), 4);
}

} // namespace fn_f87c96cc

// 0x000bcbf0 FUN_000bcbf0 (533 B): equivalent/0x000bcbf0.cpp [wrapped: conflict: FUN_000fc1b0; FUN_000fc260]
// sym: ?FUN_000bcbf0@Owner_bcbf0@fn_000bcbf0@@QAEXXZ @9c8b462883da @w15217b0875e1
namespace fn_000bcbf0 {
// STATUS: equivalent (tools/equiv.py level 3: 11601 inputs, branch coverage 26/26)
// FUN_000bcbf0 @ 0x000bcbf0

struct Pair_bcbf0 {
    int a;
    int b;
};

struct Manager_bcbf0 {
    int FUN_000f7240(int a, int b);
};
Manager_bcbf0 *__cdecl FUN_000fc1b0();

struct TextEntry_bcbf0 {
    char pad[0x24];
    void FUN_000f8500(const char *name, Manager_bcbf0 *manager, int flag);
};


class CUnlockable_bcbf0 {
public:
    virtual void v0();
};

class CUnlockableMove_bcbf0 : public CUnlockable_bcbf0 {
public:
    char pad04[0x20 - 4];
    char flag20;
    char pad21[0x30 - 0x21];
    const char *name;
    int pad34;
    Pair_bcbf0 id;
    char FUN_00091f40();
    const char *FUN_00092040();
    Pair_bcbf0 *FUN_00092050();
};

class CUnlockableCheat_bcbf0 : public CUnlockable_bcbf0 {
public:
    char pad04[8 - 4];
    char f8;
    char pad09[0x20 - 9];
    char f20;
};

class FEObject_bcbf0 {
public:
    virtual void vfunc_0();
};

FEObject_bcbf0 *__cdecl FUN_000fc260(const char *name);

class TextSelector_bcbf0 : public FEObject_bcbf0 {
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19(TextEntry_bcbf0 *entry, int a, int b);
    virtual void vfunc_20(int index, TextEntry_bcbf0 *entry);
    char pad04[0x1d58 - 4];
    int count;
    void FUN_000e36c0();
};

struct Unlockables_bcbf0 {
};



struct NameSource_bcbf0 {
    const char *FUN_0027b010();
};

struct Owner_bcbf0 {
    char pad0[0x4c];
    Unlockables_bcbf0 *items;
    void FUN_000bcbf0();
};

void Owner_bcbf0::FUN_000bcbf0()
{
    CUnlockableMove_bcbf0 *first = dynamic_cast<CUnlockableMove_bcbf0 *>(((CUnlockable_bcbf0 *)((owners::C_92ad0 *)items)->FUN_00092ad0((hulk_intptr)0x266)));
    if (first == 0)
        return;
    const char *label = first->FUN_00092040();
    if (label == 0)
        return;
    TextSelector_bcbf0 *sel = dynamic_cast<TextSelector_bcbf0 *>(FUN_000fc260(label));
    if (sel == 0)
        return;

    char flag = 0;
    CUnlockableCheat_bcbf0 *cheat = dynamic_cast<CUnlockableCheat_bcbf0 *>(((CUnlockable_bcbf0 *)((owners::C_92ad0 *)items)->FUN_00092ad0((hulk_intptr)0x1d)));
    if (cheat) {
        if (cheat->f8 != 0)
            flag = 0;
        else if (cheat->f20 != 0)
            flag = 1;
        else
            flag = 0;
    }

    TextEntry_bcbf0 entry;
    ((owners::State_f7930 *)&entry)->FUN_000f7930();
    Manager_bcbf0 * tmp1 = FUN_000fc1b0();
    entry.FUN_000f8500(((char*)&DAT_003f335c), tmp1, 1);
    sel->FUN_000e36c0();

    for (int i = 0x266; i <= 0x2c9; i++) {
        int slot = ((owners::C_932a0 *)items)->FUN_000932a0(i - 0x266);
        if (slot == -1)
            continue;
        Pair_bcbf0 *p = ((Pair_bcbf0 *)((owners::C_92bb0 *)items)->FUN_00092bb0(slot));
        if ((p->a | p->b) == 0)
            continue;
        CUnlockableMove_bcbf0 *move = dynamic_cast<CUnlockableMove_bcbf0 *>(((CUnlockable_bcbf0 *)((owners::C_92ad0 *)items)->FUN_00092ad0((hulk_intptr)slot)));
        if (move == 0)
            continue;
        if (!move->FUN_00091f40() && !flag)
            continue;
        Pair_bcbf0 *q = ((Pair_bcbf0 *)((owners::C_92bb0 *)items)->FUN_00092bb0(slot));
        int arg1_ = q->b;
        int arg2_ = q->a;
        int id = FUN_000fc1b0()->FUN_000f7240(arg2_, arg1_);
        if (id != -1) {
            ((owners::Obj_f7a10 *)&entry)->FUN_000f7a10((hulk_intptr)id, 0);
        } else {
            Manager_bcbf0 *m = FUN_000fc1b0();
            NameSource_bcbf0 *ns = (NameSource_bcbf0 *)((Pair_bcbf0 *)((owners::C_92bb0 *)items)->FUN_00092bb0(slot));
            const char * tmp2 = ns->FUN_0027b010();
            entry.FUN_000f8500(tmp2, m, 1);
        }
        sel->vfunc_19(&entry, 0, 0);
        Pair_bcbf0 *r = move->FUN_00092050();
        int arg3_ = r->b;
        int arg4_ = r->a;
        int id2 = FUN_000fc1b0()->FUN_000f7240(arg4_, arg3_);
        ((owners::Obj_f7a10 *)&entry)->FUN_000f7a10((hulk_intptr)id2, 0);
        sel->vfunc_20(sel->count - 1, &entry);
    }
    sel->vfunc_3();
    ((owners::Thing_f7960 *)&entry)->FUN_000f7960();
}
} // namespace fn_000bcbf0


// 0x000bce10 FUN_000bce10 (296 B): equivalent/0x000bce10.cpp [wrapped: conflict: FUN_000fc1b0; FUN_000fc260]
// sym: ?run@Target_bce10@fn_000bce10@@QAEXXZ @0a59528ee817 @w3f9de3c175e2
namespace fn_000bce10 {
// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 14/14)
// FUN_000bce10 @ 0x000bce10
struct Manager_bce10 { int FUN_000f7240(int,int); };
extern Manager_bce10* __cdecl FUN_000fc1b0();
extern void* __cdecl FUN_000fc260(const char*);
extern char DAT_0049dba4, DAT_0049dbbc;
struct Selector_bce10;
extern Selector_bce10* __cdecl FUN_00344e74(void*,int,void*,void*,int);
struct Text_bce10 { char storage[36];   void FUN_000f8500(const char*,Manager_bce10*,int);  };
struct Item_bce10 { int first; int second; const char* FUN_0027b010(); };
struct List_bce10 {   };
struct Lookup_bce10 {  };
struct Selector_bce10 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(Text_bce10*,int,int); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(int);
 char pad[0x1d54]; int count;
 void FUN_000e36c0();
};
struct Target_bce10 { char pad[0x34]; List_bce10* list; char pad2[0x14]; Lookup_bce10* lookup; void FUN_000b8e70(int); void run(); };
void Target_bce10::run() {
 if (!list || !lookup) return;
 Selector_bce10* sel=FUN_00344e74(FUN_000fc260("jump_marker_selector"),0,&DAT_0049dba4,&DAT_0049dbbc,0);
 if (!sel) return;
 Text_bce10 text; ((owners::State_f7930 *)&text)->FUN_000f7930();
 text.FUN_000f8500("", FUN_000fc1b0(), 1);
 sel->FUN_000e36c0();
 for(int i=0;i<((int)((owners::C_89950 *)list)->FUN_00089950());++i) {
 int tmp1 = ((owners::C_89960 *)list)->FUN_00089960(i);
 Item_bce10* item=((Item_bce10 *)((owners::C_92bb0 *)lookup)->FUN_00092bb0(tmp1));
 int second=item->second; int first=item->first;
 int index=FUN_000fc1b0()->FUN_000f7240(first,second);
 if(index!=-1) ((owners::Obj_f7a10 *)&text)->FUN_000f7a10((hulk_intptr)index, 0);
 else text.FUN_000f8500(item->FUN_0027b010(), FUN_000fc1b0(), 1);
 sel->v19(&text,0,0);
 }
 if(sel->count>0) {sel->v25(0); FUN_000b8e70(0);}
 sel->v3();
 ((owners::Thing_f7960 *)&text)->FUN_000f7960();
}
} // namespace fn_000bce10


// 0x000bcf40 FUN_000bcf40 (270 B): matches/0x000bcf40.cpp [wrapped: conflict: World]
// sym: ?FUN_000bcf40@Menu_bcf40@fn_000bcf40@@QAEXH@Z
namespace fn_000bcf40 {
// FUN_000bcf40 @ 0x000bcf40
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

class Input_bcf40 {
  public:
    char FUN_00099740();
    char FUN_00099790();
    char FUN_00099750();
};
class World {
  public:
    char head[8];
    Input_bcf40* input;
};
class Widget_bcf40 {
  public:
    char FUN_001b8b30();
};
struct State_bcf40 {
    int id;
};
extern "C" char __cdecl FUN_000c5ef0(int who, int a, int b, int c, int d, int e);
extern "C" char __cdecl FUN_000c5d60(int who, int a);

class Menu_bcf40 {
  public:
    char pad0[0x30];
    State_bcf40* current;
    char pad1[0x54 - 0x34];
    Widget_bcf40* widget;
    void FUN_000b5a80();
    void FUN_000b5ad0();
    void FUN_000b5b50();
    void FUN_000b5b90();
    void FUN_000bcbf0();
    void FUN_000b99b0();
    void FUN_000b7490();
    void FUN_000b7590();
    void FUN_000b7660();
    void FUN_000b8d00();
    void FUN_000b76c0();
    void FUN_000bc1e0(const char* name);
    void FUN_000bcf40(hulk_intptr who);
};

void Menu_bcf40::FUN_000bcf40(hulk_intptr who) {
    if (current->id == 7)
        return;
    Input_bcf40* in = DAT_004dd700->input;
    if (in->FUN_00099740())
        return;
    if (in->FUN_00099790())
        return;
    if (in->FUN_00099750())
        return;
    if (widget != 0 && widget->FUN_001b8b30())
        return;
    if ((*(char*)&DAT_004ddbe1)) {
        char r = FUN_000c5ef0(who, 2, 7, -1, -1, -1);
        if (r)
            return;
        (*(char*)&DAT_004ddbe1) = 0;
        return;
    }
    if (FUN_000c5ef0(who, 2, 5, -1, -1, -1))
        return;
    if (!FUN_000c5d60(who, 4))
        return;
    FUN_000b5a80();
    FUN_000b5ad0();
    FUN_000b5b50();
    FUN_000b5b90();
    FUN_000bcbf0();
    FUN_000b99b0();
    FUN_000b7490();
    FUN_000b7590();
    FUN_000b7660();
    FUN_000b8d00();
    FUN_000b76c0();
    FUN_000bc1e0("pause");
}
} // namespace fn_000bcf40
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000bd1b0 FUN_000bd1b0 (2851 B): equivalent/0x000bd1b0.cpp [wrapped: conflict: FUN_000fc1b0; World]
// sym: ?FUN_000bd1b0@Menu_bd1b0@fn_000bd1b0@@QAEXE@Z @29b434f17a63 @w8c18c6fe6563
namespace fn_000bd1b0 {
// STATUS: equivalent (tools/equiv.py level 3: 20098 inputs, branch coverage 78/80, incomplete)
// FUN_000bd1b0 @ 0x000bd1b0
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
extern "C" void __fastcall __security_check_cookie(unsigned int);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int strcmp(const char *, const char *);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int memcmp(const void *, const void *, unsigned int);
#endif

extern unsigned int DAT_004d9968;

struct Measurer_bd1b0 {
    int dummy;
};

struct Metrics_bd1b0 {
    char pad0[0x24];
    void *f24;
    void *f28;
};

struct Mgr_bd1b0 {
    char pad0[0x24];
    Measurer_bd1b0 *measurers[1];
    unsigned short *FUN_00088ea0(const char *s);
};

struct Slot_bd1b0 {
    float weight;
    int a;
    int b;
    int value;
};

struct SlotStack_bd1b0 {
    Slot_bd1b0 slots[8];
    int index;
    float scale;
    void FUN_000f78f0();
};

struct Label_bd1b0 {
    int f0;
    char rest[0x20];
    void FUN_000f7930();
    void FUN_000f7960();
    void FUN_000f8500(const void *name, Mgr_bd1b0 *mgr, int flag);
    void FUN_000f79a0(const unsigned short *s, Mgr_bd1b0 *mgr);
};

struct Layout_bd1b0 {
    Metrics_bd1b0 *font;
    int current;
    SlotStack_bd1b0 stack;
    Layout_bd1b0 *FUN_000f7fe0(Metrics_bd1b0 *font);
    void FUN_000f87f0(Label_bd1b0 *e, void *arg);
    void FUN_000f78e0();
};

struct Style {
    int f0, f4, f8, fc;
    unsigned int f10;
    float f14;
    int f18;
    void FUN_000dee10();
};

class Gfx {
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
    virtual void v12(int a);
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
    virtual void v24(int a);
    virtual int v25();
    virtual void v26();
    virtual void v27();
    virtual void v28(float a, float b, float c, float d);
    virtual void v29();
    virtual struct Mesh_bd1b0 *v30(int handle, int a, int b, int c, int d);
    virtual void v31(struct Mesh_bd1b0 *m);
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
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54(int a);
    virtual int v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60(int a);
    virtual int v61();
};

struct Vertex_bd1b0 {
    float x, y, z;
};

struct Mesh_bd1b0 {
    char pad0[8];
    Vertex_bd1b0 *verts;
    char pad0c[4];
    unsigned int *colors;
    void FUN_0008ef00();
};

class Layer_bd1b0 {
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
    virtual void v13(int a);
    virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};

struct Canvas {
    Layer_bd1b0 *layer;
    void FUN_00293da0(float a, float b, float c);
    void FUN_00293d40(float a, float b, float c);
};

class Viewport_bd1b0 {
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
    virtual float v16();
};

struct Overlay20 {
    void FUN_00293ef0();
    void FUN_00294080();
};

struct Missions_bd1b0 {
    char *FUN_0008a2d0();
    char *FUN_0008a060(const char *id);
};

struct Sound_bd1b0 {
    void FUN_001ec480(const char *a, const char *b);
    void FUN_001eb2a0(float a, int b);
};

struct Dev10 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a, int b);
};

struct Obj68_bd1b0 {
    char pad0[0x10];
    Dev10 *f10;
    int pad14;
    int f18;
};

struct Probe_bd1b0 {
    int FUN_000d3f10(const void *key);
};
struct Sink_bd1b0 {
    void FUN_000afe80();
};
struct Obj86 {
    Probe_bd1b0 *FUN_00086350();
    Sink_bd1b0 *FUN_00086330();
};
struct World {
    char pad0[0x54];
    Obj86 *f54;
};

struct Sys52 {
    char pad0[0xd8];
    int fd8;
    void FUN_0028f9a0();
    void FUN_0028faf0(int a);
};

struct TblEntry {
    const char *name;
    const char *strs[4];
};


extern Mgr_bd1b0 *__cdecl FUN_000fc1b0();
extern unsigned int __cdecl FUN_00267f80();
extern char __cdecl FUN_0008db80();
extern void __cdecl FUN_002684c0();
extern int __cdecl FUN_001eb200();
extern int __cdecl FUN_000fb830(unsigned short *out, int size, const unsigned short *in, float maxWidth, Measurer_bd1b0 *m);
extern float __cdecl FUN_000186b0(float *v, float *lo, float *hi);
extern float __cdecl FUN_000186f0(float *a, float *b);

struct Frame_bd1b0 {
    union {
        float f;
        int i;
    } s0;                       // 0x00
    union {
        float f;
        int i;
    } s4;                       // 0x04
    hulk_intptr s8;                     // 0x08
    unsigned int dt;            // 0x0c
    void *self;                 // 0x10
    float lo;                   // 0x14
    int saved25;                // 0x18
    float hi;                   // 0x1c
    int saved61;                // 0x20
    Label_bd1b0 e1;                   // 0x24
    int saved55;                // 0x48
    Layout_bd1b0 layout;              // 0x4c
    Style style;                // 0xdc
    unsigned short buf[0x80];   // 0xf8
    char padHigh[0x2f8 - 0x1f8];
    unsigned int cookie;        // 0x2f8
};

class Menu_bd1b0 {
public:
    char pad0[0x20];
    Overlay20 *p20;
    char pad24[8];
    unsigned int t2c;
    int *p30;
    Missions_bd1b0 *p34;
    char pad38[4];
    Sound_bd1b0 *p3c;
    char pad40[0x68 - 0x40];
    Obj68_bd1b0 *p68;
    void FUN_000bd1b0(unsigned char flag);
};

void Menu_bd1b0::FUN_000bd1b0(unsigned char flag)
{
    Frame_bd1b0 f;
    f.cookie = DAT_004d9968;
    f.self = this;
    f.layout.FUN_000f7fe0((Metrics_bd1b0 *)FUN_000fc1b0());
    SlotStack_bd1b0 *st = &f.layout.stack;
    Menu_bd1b0 *me = this;
    if (f.layout.font->f24 != 0 && f.layout.font->f28 != 0) {
        unsigned int now = FUN_00267f80();
        f.dt = now - t2c;
        if (f.dt >= 0x80)
            f.dt = 0x80;
        if (f.dt >= 0x40 && !FUN_0008db80()) {
            hulk_freg aspect = 1.33333f / (*(Viewport_bd1b0**)&DAT_0052c2a4)->v16();
            DAT_004dd700->f54->FUN_00086330()->FUN_000afe80();
            FUN_002684c0();
            FUN_002684c0();
            FUN_002684c0();
            t2c = now;
            (*(Sys52**)&DAT_0052c2b4)->fd8 = 0;
            (*(Sys52**)&DAT_0052c2b4)->FUN_0028f9a0();
            f.saved25 = DAT_0052c2a8->v25();
            DAT_0052c2a8->v24(0);
            f.saved55 = DAT_0052c2a8->v55();
            DAT_0052c2a8->v54(0);
            f.saved61 = DAT_0052c2a8->v61();
            DAT_0052c2a8->v60(1);
            p20->FUN_00293ef0();
            DAT_0052c2a8->v28(0.1f, 10000.0f, 0.5235988f, (*(Viewport_bd1b0**)&DAT_0052c2a4)->v16());
            DAT_0052c2a8->v12(7);
            char *id = p34->FUN_0008a2d0();
            f.s8 = (hulk_intptr)id;
            bool done = false;
            if (p34 != 0) {
                char *r = p34->FUN_0008a060(id);
                if (r != 0 && memcmp(r, "complete", 9) == 0)
                    done = true;
            }
            if (!done) {
                if (DAT_004dd700->f54->FUN_00086350()->FUN_000d3f10(((unsigned int*)&DAT_00409030)) == 0) {
                    DAT_004dde24 = 0.0f;
                } else if (p30 != 0 && (*p30 == 2 || *p30 == 3)) {
                    f.s4.i = 0;
                    if (((TblEntry*)&DAT_004061e8)[0].name != 0) {
                        TblEntry *e = ((TblEntry*)&DAT_004061e8);
                        for (;;) {
                            if (strcmp(e->name, id) == 0)
                                break;
                            f.s4.i++;
                            e++;
                            if (e->name == 0)
                                break;
                        }
                    }
                    int idx = f.s4.i;
                    if (((TblEntry*)&DAT_004061e8)[idx].name != 0) {
                        DAT_004dde24 = (float)f.dt * 0.001f + DAT_004dde24;
                        f.e1.FUN_000f7930();
                        f.s0.f = 1.0f;
                        hulk_freg t = FUN_000186f0(&DAT_004dde24, &f.s0.f);
                        f.s0.f = t;
                        f.e1.f0 = 1;
                        st->FUN_000f78f0();
                        st->slots[st->index].value = 0xff000000;
                        st->slots[st->index].weight = 0.016f;
                        st->slots[st->index].b = 2;
                        st->slots[st->index].a = 1;
                        f.style.FUN_000dee10();
                        f.style.f10 = ((int)(f.s0.f * 128.0f) << 24) | 0x2bae11;
                        f.style.f14 = 1.0f;
                        (*(Canvas**)&DAT_0052c2ac)->layer->v15(0);
                        (*(Canvas**)&DAT_0052c2ac)->layer->v13(0);
                        (*(Canvas**)&DAT_0052c2ac)->FUN_00293da0(aspect, aspect, 1.0f);
                        (*(Canvas**)&DAT_0052c2ac)->FUN_00293d40(0.0f, 1.4f, 10.0f);
                        f.e1.FUN_000f8500("TBS_MENU_ITEM_PM_MISSION_OBJECTIVES", FUN_000fc1b0(), 1);
                        f.layout.FUN_000f87f0(&f.e1, &f.style);
                        (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
                        if (st->index > 0)
                            st->index--;
                        f.e1.f0 = 0;
                        st->FUN_000f78f0();
                        st->slots[st->index].weight = 0.014f;
                        st->slots[st->index].b = 1;
                        st->slots[st->index].a = 0;
                        f.s4.f = 0.0f;
                        f.s8 = (hulk_intptr)&((TblEntry*)&DAT_004061e8)[idx].strs[0];
                        for (int k = 0; k < 4; k++, f.s8 += 4) {
                            const char *str = *(const char **)f.s8;
                            if (str != 0 && *str != 0) {
                                f.s0.f = DAT_004dde24 - (float)(k + 1) * 0.25f;
                                f.lo = 0.01f;
                                f.hi = 1.0f;
                                hulk_freg c = FUN_000186b0(&f.s0.f, &f.lo, &f.hi);
                                int a8 = (int)(c * 255.0f);
                                st->slots[st->index].value = (a8 << 24) | 0xffffff;
                                (*(Canvas**)&DAT_0052c2ac)->layer->v15(0);
                                (*(Canvas**)&DAT_0052c2ac)->layer->v13(0);
                                (*(Canvas**)&DAT_0052c2ac)->FUN_00293da0(aspect, aspect, 1.0f);
                                f.s0.f = 1.0f - f.s4.f;
                                (*(Canvas**)&DAT_0052c2ac)->FUN_00293d40(-2.1f, f.s0.f, 10.0f);
                                f.e1.FUN_000f8500("TBS_MISSION_OBJECTIVE_STATUS_INCOMPLETE", FUN_000fc1b0(), 1);
                                f.layout.FUN_000f87f0(&f.e1, 0);
                                (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
                                (*(Canvas**)&DAT_0052c2ac)->layer->v15(0);
                                (*(Canvas**)&DAT_0052c2ac)->layer->v13(0);
                                (*(Canvas**)&DAT_0052c2ac)->FUN_00293da0(aspect, aspect, 1.0f);
                                (*(Canvas**)&DAT_0052c2ac)->FUN_00293d40(-1.8f, f.s0.f, 10.0f);
                                f.s0.i = FUN_000fb830((unsigned short *)f.buf, 0x100, FUN_000fc1b0()->FUN_00088ea0(str), 460.0f,
                                                       FUN_000fc1b0()->measurers[f.e1.f0]);
                                f.e1.FUN_000f79a0((unsigned short *)f.buf, FUN_000fc1b0());
                                f.layout.FUN_000f87f0(&f.e1, 0);
                                (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
                                f.s4.f = (float)f.s0.i * 0.2f + f.s4.f + 0.1f;
                            }
                        }
                        if (st->index > 0)
                            st->index--;
                        f.e1.FUN_000f7960();
                        me = (Menu_bd1b0 *)f.self;
                    }
                }
            }

            f.s0.f = (float)f.dt * 0.001f;
            {
                hulk_freg v = DAT_004dde20 + *(volatile float *)&f.s0.f;
                DAT_004dde20 = v;
                if (v > DAT_0049f5e0) {
                    do {
                        v = v - DAT_0049f5e0;
                    } while (v > DAT_0049f5e0);
                    DAT_004dde20 = v;
                }
            }
            if (!flag)
                (*(char*)&DAT_004dde1c) = 0;

            if (f.layout.font->f28 != 0) {
                (*(Canvas**)&DAT_0052c2ac)->layer->v15(0);
                (*(Canvas**)&DAT_0052c2ac)->layer->v13(0);
                (*(Canvas**)&DAT_0052c2ac)->FUN_00293da0(aspect, aspect, 1.0f);
                (*(Canvas**)&DAT_0052c2ac)->FUN_00293d40(0.0f, -1.0f, 10.0f);
                f.e1.FUN_000f7930();
                f.e1.f0 = 1;
                unsigned int c1 = 0x2b;
                unsigned int cA = 0xae;
                unsigned int cB = 0x11;
                if (flag) {
                    f.e1.FUN_000f8500("TBS_MENU_ITEM_PRESS_START2_XBOX", FUN_000fc1b0(), 1);
                    c1 = 0xfe;
                    cA = 0xf6;
                    cB = 0x18;
                    if (!(*(char*)&DAT_004dde1c)) {
                        me->p3c->FUN_001ec480("start", "prestart");
                        (*(char*)&DAT_004dde1c) = 1;
                    }
                    me->p3c->FUN_001eb2a0(0.01f, 1);
                } else {
                    f.e1.FUN_000f8500("TBS_MENU_ITEM_MC_LOADING_1", FUN_000fc1b0(), 1);
                }
                st->FUN_000f78f0();
                st->slots[st->index].b = 2;
                st->slots[st->index].a = 1;
                unsigned int base = ((c1 << 8) | cA) << 8;
                for (int i = 0; i < 2; i++) {
                    hulk_freg t = ((float)i * DAT_0049f5e0 * 0.5f + DAT_004dde20) / DAT_0049f5e0;
                    while (t > 1.0f)
                        t = t - 1.0f;
                    int a8 = (int)(255.0f * t);
                    st->slots[st->index].value = ((0xff - a8) << 24) | base | cB;
                    st->slots[st->index].weight = t * 0.05f;
                    f.layout.FUN_000f87f0(&f.e1, 0);
                }
                f.style.FUN_000dee10();
                unsigned int col2 = ((((c1 | 0xffffff00) << 8) | cA) << 8) | cB;
                f.style.f10 = 0x7f000000;
                f.style.f14 = 1.0f;
                st->slots[st->index].value = col2;
                st->slots[st->index].weight = 0.016f;
                f.layout.FUN_000f87f0(&f.e1, &f.style);
                if (st->index > 0)
                    st->index--;
                (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
                f.e1.FUN_000f7960();
            }

            if (!flag) {
                DAT_004dde18 = 0.0f;
            } else {
                DAT_004dde18 = DAT_004dde18 + f.s0.f;
                hulk_freg m;
                if (DAT_004dde18 < 1.0f)
                    m = DAT_004dde18;
                else
                    m = 1.0f;
                unsigned int col = ((unsigned int)(int)((1.0f - m) * 255.0f) << 24) | 0x2bae11;
                (*(Canvas**)&DAT_0052c2ac)->layer->v15(0);
                (*(Canvas**)&DAT_0052c2ac)->layer->v13(0);
                (*(Canvas**)&DAT_0052c2ac)->FUN_00293da0(aspect, aspect, 1.0f);
                (*(Canvas**)&DAT_0052c2ac)->FUN_00293d40(0.0f, 0.0f, 10.0f);
                Obj68_bd1b0 *o68 = me->p68;
                o68->f10->v6(0x444d4c42, 1);
                o68->f18 = 1;
                Mesh_bd1b0 *mesh = DAT_0052c2a8->v30((hulk_intptr)me->p68->f10, 1, 0x2020, 4, 0);
                {
                    Vertex_bd1b0 *vv = mesh->verts;
                    vv->x = -8.0f;
                    vv->y = -4.0f;
                    vv->z = 0.0f;
                }
                *mesh->colors = col;
                mesh->FUN_0008ef00();
                {
                    Vertex_bd1b0 *vv = mesh->verts;
                    vv->x = 8.0f;
                    vv->y = -4.0f;
                    vv->z = 0.0f;
                }
                *mesh->colors = col;
                mesh->FUN_0008ef00();
                {
                    Vertex_bd1b0 *vv = mesh->verts;
                    vv->x = -8.0f;
                    vv->y = 4.0f;
                    vv->z = 0.0f;
                }
                *mesh->colors = col;
                mesh->FUN_0008ef00();
                {
                    Vertex_bd1b0 *vv = mesh->verts;
                    vv->x = 8.0f;
                    vv->y = 4.0f;
                    vv->z = 0.0f;
                }
                *mesh->colors = col;
                mesh->FUN_0008ef00();
                DAT_0052c2a8->v31(mesh);
                (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
            }
            me->p20->FUN_00294080();
            DAT_0052c2a8->v54(f.saved55);
            DAT_0052c2a8->v60(f.saved61);
            DAT_0052c2a8->v24(f.saved25);
            (*(Sys52**)&DAT_0052c2b4)->FUN_0028faf0(1);
            if (FUN_001eb200())
                FUN_00267f80();
        }
    }
    f.layout.FUN_000f78e0();
    __security_check_cookie(f.cookie);
}
} // namespace fn_000bd1b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000bdd60 FUN_000bdd60 (430 B): equivalent/0x000bdd60.cpp [wrapped: conflict: FEObject; FUN_000fc260; Gfx; Overlay (+1)]
// sym: ?FUN_000bdd60@Menu_bdd60@fn_000bdd60@@QAEXXZ @e4a25dbd87ec @w86e32f67c750
namespace fn_000bdd60 {
// STATUS: equivalent (tools/equiv.py level 3: 20038 inputs, branch coverage 25/25)
// FUN_000bdd60 @ 0x000bdd60
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

// MSVC 7.1 expands memcmp inline (repe cmpsb); so does this.
static inline int memcmp_inline(const void *a, const void *b, unsigned n)
{
    const unsigned char *p = (const unsigned char *)a;
    const unsigned char *q = (const unsigned char *)b;
    for (; n != 0; n--, p++, q++)
        if (*p != *q)
            return *p - *q;
    return 0;
}

class FEObject {
public:
    virtual void vfunc_0();
};

class TextLabel : public FEObject {
public:
    virtual void vfunc_1();
    char pad04[0x3c - 4];
    unsigned int color;
};

class Screen_bdd60 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual const char *GetName();
};

class Gfx {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void SetVisible(int on);
};

struct Notifier_bdd60 { void FUN_0023f8f0(); };
struct Widget_bdd60 { void FUN_001bf8b0(); };
struct Overlay {
    void FUN_00293ef0();
    void FUN_00294080();
};


void FUN_000fc1a0();
extern "C" Screen_bdd60 *FUN_000fc310();
FEObject *FUN_000fc260(const char *name);
extern "C" float FUN_000186b0(float *v, float *lo, float *hi);

class Menu_bdd60 {
public:
    char pad0[0x10];
    unsigned int state;
    char pad14[0x20 - 0x14];
    Overlay *overlay;
    char pad24[0x5c - 0x24];
    Widget_bdd60 *widget;
    char pad60[0x1cfc - 0x60];
    float timer;
    void FUN_000bdd60();
};

void Menu_bdd60::FUN_000bdd60()
{
    overlay->FUN_00293ef0();
    if (state == 0) {
        FUN_000fc1a0();
        Screen_bdd60 *s = FUN_000fc310();
        if (s != 0) {
            if (memcmp_inline(s->GetName(), "blonsky_file", 13) == 0) {
                if (widget != 0)
                    widget->FUN_001bf8b0();
            }
        }
        (*(Notifier_bdd60**)&DAT_004dd6e8)->FUN_0023f8f0();
    } else if (state == 2 || state == 17) {
        DAT_0052c2a8->SetVisible(1);
        FUN_000fc1a0();
    } else if (state >= 18 && state <= 23) {
        FUN_000fc1a0();
        (*(Notifier_bdd60**)&DAT_004dd6e8)->FUN_0023f8f0();
    } else if (state == 9) {
        if (FUN_000fc310() != 0) {
            const char *name = FUN_000fc310()->GetName();
            if (name != 0) {
                if (memcmp_inline("fullscreen_message", name, 19) == 0 || memcmp_inline("mission_accept", name, 15) == 0) {
                    TextLabel *label = dynamic_cast<TextLabel *>(FUN_000fc260("DynamicControlButtonLabel"));
                    if (label != 0) {
                        float hi = 1.0f;
                        float lo = 0.01f;
                        float v = (timer - 2.0f) * 8.0f;
                        label->color = ((unsigned int)(__int64)(int)(__int64)(FUN_000186b0(&v, &lo, &hi) * 255.0f) << 24) | 0xffffff;
                    }
                }
            }
        }
        FUN_000fc1a0();
    } else if (state == 10) {
        FUN_000fc1a0();
    }
    overlay->FUN_00294080();
}
} // namespace fn_000bdd60
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

