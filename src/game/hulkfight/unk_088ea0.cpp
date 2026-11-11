// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00088ea0..0x00089400 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9371648 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9371648 {} using namespace fn_f9371648;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_f9371648 {
typedef unsigned int U_88ea0;
struct This_FUN_000f7d30 {
};
class Obj_88ec0 {
  public:
    char pad[0xc];
    char mValue;
    void Set(char x);
    void Callback_001be490();
};
struct Obj_88ee0 {
    char pad[0xc];
    unsigned char value;
    unsigned char Get();
};
typedef unsigned int u32_88fa0;
struct X_88fb0 {
    int pad;
    unsigned int value;
};
extern void __cdecl Scan(unsigned int, const char*, ...);
extern "C" void __cdecl FUN_00267760(char*, int, const char*, ...);
extern int __stdcall Check(void*);
struct CO {
    int pad;
    int val;
};
struct Res_88fe0 {
};
struct Svc_88fe0 {
    Res_88fe0* Run();
};
struct Glob_88fe0 {
    char pad[0x54];
    Svc_88fe0* svc;
};
extern Glob_88fe0* hulk_at_004dd700;
struct Slot_89160 {
    bool on;
    char pad[3];
    unsigned int n;
    char rest[0xbe0];
};
struct Pool_89160 {
    int h;
    Slot_89160 s[5];
};
struct Owner_89160 {
    char pad[0xac8];
    Pool_89160* pool;
    unsigned int Count();
};
class Data_891e0;
class Owner_891e0 {
  public:
    char pad[0xac8];
    Data_891e0* p;
    unsigned int Fn();
};
class Data_891e0 {
  public:
    char pad0[4];
    unsigned char a;
    char p0[3];
    unsigned int n0;
    char p1[0xbec - 12];
    unsigned char b;
    char p2[3];
    unsigned int n1;
    char p3[0x17d4 - 0xbf4];
    unsigned char c;
    char p4[3];
    unsigned int n2;
    char p5[0x23bc - 0x17dc];
    unsigned char d;
    char p6[3];
    unsigned int n3;
    char p7[0x2fa4 - 0x23c4];
    unsigned char e;
    char p8[3];
    unsigned int n4;
};
typedef unsigned int u32_892c0;
class Callee_892c0 {
  public:
    int Run_0008cd80(int a, int b);
};
class Obj_892c0 {
  public:
    char pad[0xac4];
    Callee_892c0* mArg;
    char* mBase;
    int Target(int param2, int index);
};
class Manager_89300 {
  public:
};
class Obj_89300 {
  public:
    char pad[0xabe];
    unsigned char flag;
    char pad2[1];
    Manager_89300* mgr;
    void Target(const char*);
    void Prepare_001d4c90();
};
class Target_89380 {
  public:
    char pad[0x108];
    int value;
};
class X_89390 {
    char pad[0x108];

  public:
    int value;
};

} // namespace fn_f9371648

// 0x00088ea0 FUN_00088ea0 (25 B): matches/0x00088ea0.cpp
// sym: ?FUN_00088ea0@A_88ea0@owners@@QAEHI@Z
hulk_intptr owners::A_88ea0::FUN_00088ea0(hulk_uintptr x) {
    U_88ea0 r = ((unsigned int)((owners::A_f7d30 *)(((This_FUN_000f7d30*)this)))->FUN_000f7d30((hulk_intptr)(((U_88ea0)x))));
    return f(r);
}

namespace fn_f9371648 {

// 0x00088ec0 FUN_00088ec0 (26 B): matches/0x00088ec0.cpp
// sym: ?Set@Obj_88ec0@fn_f9371648@@QAEXD@Z
void Obj_88ec0::Set(char x) {
    if (mValue != x) {
        Callback_001be490();
    }
    mValue = x;
}


// 0x00088ee0 FUN_00088ee0 (4 B): matches/0x00088ee0.cpp
// sym: ?Get@Obj_88ee0@fn_f9371648@@QAEEXZ
unsigned char Obj_88ee0::Get() {
    return value;
}


// 0x00088fa0 FUN_00088fa0 (3 B): matches/0x00088fa0.cpp
// sym: ?FUN_00088fa0@fn_f9371648@@YIIPAI@Z
u32_88fa0 __fastcall FUN_00088fa0(u32_88fa0* p) {
    return *p;
}


// 0x00088fb0 FUN_00088fb0 (4 B): matches/0x00088fb0.cpp
// sym: ?FUN_00088fb0@fn_f9371648@@YIIPAUX_88fb0@1@@Z
// Same code shape as 0x00086270 (propagated; names are from that function)
unsigned int __fastcall FUN_00088fb0(X_88fb0* p) {
    return p->value;
}

} // namespace fn_f9371648

// 0x00088fe0 FUN_00088fe0 (115 B): matches/0x00088fe0.cpp
// sym: ?FUN_00088fe0@Obj_88fe0@owners@@QAEXI@Z
// data: gCheckObj = DAT_004dd830
void owners::Obj_88fe0::FUN_00088fe0(unsigned int arg) {
    Scan(arg, "c%dm%d", &a, &b);
    FUN_00267760(buf, 32, "c%02dm%02d", a, b);
    ((owners::K_b4c10 *)(hulk_at_004dd700->svc->Run()))->FUN_000b4c10((const char *)(hulk_uintptr)(unsigned int)arg);
    if (a > 1) {
        if (Check(((CO*)&DAT_004dd830)) != (*(CO*)&DAT_004dd830).val) {
            do {
                FUN_001bb0b0("TBS_STOP_PIRATING");
            } while (1);
        }
    }
}

namespace fn_f9371648 {

// 0x00089160 FUN_00089160 (116 B): matches/0x00089160.cpp
// sym: ?Count@Owner_89160@fn_f9371648@@QAEIXZ
unsigned int Owner_89160::Count() {
    unsigned int m = 0;
    Pool_89160* p = pool;
    if (p->s[0].on && p->s[0].n > 0)
        m = p->s[0].n;
    for (int i = 1; i < 4; i++) {
        if (p->s[i].on && p->s[i].n > m)
            m = p->s[i].n;
    }
    if (p->s[4].on && p->s[4].n > m)
        return p->s[4].n + 1;
    return m + 1;
}


// 0x000891e0 FUN_000891e0 (135 B): matches/0x000891e0.cpp
// sym: ?Fn@Owner_891e0@fn_f9371648@@QAEIXZ
unsigned int Owner_891e0::Fn() {
    Data_891e0* x = p;
    unsigned int m = 0;
    unsigned int r = 0;
    if (x->a && x->n0 > 0)
        m = x->n0;
    if (x->b && x->n1 > m) {
        m = x->n1;
        r = 1;
    }
    if (x->c && x->n2 > m) {
        m = x->n2;
        r = 2;
    }
    if (x->d && x->n3 > m) {
        m = x->n3;
        r = 3;
    }
    if (x->e && x->n4 > m)
        r = 4;
    return r;
}


// 0x000892c0 FUN_000892c0 (60 B): matches/0x000892c0.cpp
// sym: ?Target@Obj_892c0@fn_f9371648@@QAEHHH@Z
int Obj_892c0::Target(int param2, int index) {
    char* p = mBase + index * 0xbe8;
    for (int i = 0; i < 0x2fa; ++i)
        ((u32_892c0*)p)[i] = 0;
    p[4] = 0;
    return mArg->Run_0008cd80(param2, index);
}


// 0x00089300 FUN_00089300 (119 B): matches/0x00089300.cpp
// sym: ?Target@Obj_89300@fn_f9371648@@QAEXPBD@Z
void Obj_89300::Target(const char* s) {
    Prepare_001d4c90();
    int a = strcmp(s, "story");
    if (a == 0) {
        flag = 1;
        ((owners::Target_86420 *)mgr)->FUN_00086420(2);
        return;
    }
    int b = strcmp(s, "oneshot");
    if (b == 0)
        flag = (unsigned char)b;
    ((owners::Target_86420 *)mgr)->FUN_00086420(2);
}


// 0x00089380 FUN_00089380 (7 B): matches/0x00089380.cpp
// sym: ?FUN_00089380@fn_f9371648@@YIXPAVTarget_89380@1@@Z
void __fastcall FUN_00089380(Target_89380* self) {
    ++self->value;
}


// 0x00089390 FUN_00089390 (11 B): matches/0x00089390.cpp
// sym: ?FUN_00089390@fn_f9371648@@YIXPAVX_89390@1@@Z
void __fastcall FUN_00089390(X_89390* self) {
    self->value = 0;
}

} // namespace fn_f9371648

// 0x000893c0 FUN_000893c0 (7 B): matches/0x000893c0.cpp
// sym: ?FUN_000893c0@Target_893c0@owners@@QAEEXZ
unsigned char owners::Target_893c0::FUN_000893c0() {
    return value;
}

