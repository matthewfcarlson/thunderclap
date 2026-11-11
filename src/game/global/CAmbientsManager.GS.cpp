// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000788e0..0x00081340 (kind game, layer game, confidence high), dominant class CAmbientsManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa24d555 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fa24d555 {} using namespace fn_fa24d555;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fa24d555 {
struct Matrix { char data[64]; void FUN_0022b980(); void FUN_0022cc90(const void*);  };
struct Request { char data[8]; Request* FUN_0027b0e0(const char*); void FUN_0027af50(); };
struct Manager_796e0 { unsigned int FUN_001dd330(Request*, unsigned int, Matrix*, unsigned int, unsigned int, unsigned int, unsigned int); };
struct Holder_796e0 { char pad[12]; Manager_796e0* manager; };
extern "C" int __cdecl FUN_000964a0(char*, unsigned int, const char*, ...);
struct Object { char pad[0x382c]; Holder_796e0* holder; unsigned int FUN_000796e0(hulk_uintptr, const char*, const void*, const void*, unsigned int, unsigned int, unsigned int); };
} // namespace fn_fa24d555
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sin(double);
#endif
namespace fn_fa24d555 {
struct V3_7e740 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Mgr10_7e740 {
    bool FUN_00059a50(V3_7e740 *out);
};
struct Player_7e740 {
    char pad0[0x10];
    Mgr10_7e740 *f10;
    void FUN_00035550(V3_7e740 *out);
};
struct Zone_7e740 {
    char pad0[0x124];
    Player_7e740 *player;         // 0x124
};
struct Rng_7e740 {
    hulk_freg FUN_000787e0(float lo, float hi);
};
struct Cells {
    int FUN_00204200(V3_7e740 pos);
};
struct Grid_7e740 {
};
struct Mgr382c {
    char pad0[0x20];
    Zone_7e740 *zone;             // 0x20
    char pad24[0x54 - 0x24];
    Grid_7e740 *grid;             // 0x54
};
struct Item_7e740 {
};
struct Cell_7e740 {
    char pad0[3];
    char flag;
    int next;
};
extern "C" Rng_7e740 *FUN_000964d0();
void FUN_00224d70(float angle, V3_7e740 *v);
extern "C" char __cdecl FUN_00202560(V3_7e740 *origin, float dist, int a, V3_7e740 *outB, V3_7e740 *outA, int b, int c, int d);
int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);
class Game_7e740 {
public:
    char pad0[8];
    Cell_7e740 cells[0x6ff];      // 0x8
    Item_7e740 *items[10];        // 0x3800
    int count;              // 0x3828
    Mgr382c *mgr;           // 0x382c
    void FUN_0007de00(const char *name, int zero, V3_7e740 pos, V3_7e740 dir);
    void FUN_0007e740();
};
struct Frame_80820 { int a, b, c, d; char name[32];  };


// 0x000796e0 FUN_000796e0 (197 B): matches/0x000796e0.cpp
// sym: ?FUN_000796e0@Object@fn_fa24d555@@QAEIIPBDPBX1III@Z
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// FUN_000796e0 @ 0x000796e0
unsigned int Object::FUN_000796e0(hulk_uintptr a, const char* name, const void* p, const void* q, unsigned int b, unsigned int c, unsigned int d) { Matrix m; m.FUN_0022b980(); m.FUN_0022cc90(q); ((owners::Target_22be40 *)&m)->FUN_0022be40((const int *)p); char text[64]; FUN_000964a0(text,64,"%s_prop",name); Manager_796e0* manager=holder->manager; Request r; unsigned int result=manager->FUN_001dd330(r.FUN_0027b0e0(text),a,&m,b,c,d,0); r.FUN_0027af50();  return result; }

} // namespace fn_fa24d555

// 0x0007e680 FUN_0007e680 (189 B): equivalent/0x0007e680.cpp
// sym: ?FUN_0007e680@VehicleManager_7e680@owners@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 10/10)
// FUN_0007e680 @ 0x0007e680
void owners::VehicleManager_7e680::FUN_0007e680() {
 struct { int second, first; } o;  // original frame: second at S+0, first at S+4 (the call passes &first, &second)
 FUN_0007db80(&o.first, &o.second);
 if (o.first != -1 && o.second != -1) {
  char name[32];
  FUN_000964a0(name, 32, "vehicle%d", vehicle);
  unsigned index = FUN_000113e0(0, count - 1);
  int n = count;
  for (int i = 0; i < n; ++i) {
   if (counts[index] < limits[index]) {
    FUN_0007d700(name, index, o.first, o.second);
    break;
   }
   index = (index + 1) % (unsigned)n;
  }
 }
}

namespace fn_fa24d555 {

// 0x0007e740 FUN_0007e740 (681 B): equivalent/0x0007e740.cpp
// sym: ?FUN_0007e740@Game_7e740@fn_fa24d555@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 20030 inputs, branch coverage 20/20)
// FUN_0007e740 @ 0x0007e740
void Game_7e740::FUN_0007e740()
{
    struct Frame {
        V3_7e740 q;
        V3_7e740 w;
        float ang;
        V3_7e740 p;
        V3_7e740 r2;
        V3_7e740 r1;
        char name[0x20];
    } f;

    Player_7e740 *pl = mgr->zone->player;
    pl->f10->FUN_00059a50(&f.p);
    ((owners::C_35660 *)pl)->FUN_00035660((int *)(V3_7e740 *)(&f.q));
    if (f.q.x == (*(float*)&DAT_003f32e0) && f.q.z == (*(float*)&DAT_003f32e0))
        pl->FUN_00035550(&f.q);
    f.q.y = 0.0f;
    f.q.FUN_0022d110();
    f.ang = FUN_000964d0()->FUN_000787e0(-1.5707964f, 1.5707964f);
    FUN_00224d70(f.ang, &f.q);

    // the original keeps the x and y products unrounded until the sum is stored; z's is stored first
    hulk_freg sx = f.q.x * (*(float*)&DAT_003feed8);
    hulk_freg sy = f.q.y * (*(float*)&DAT_003feed8);
    volatile float sz = f.q.z * (*(float*)&DAT_003feed8);
    f.q.x = f.p.x + sx;
    f.q.y = f.p.y + sy;
    f.q.z = f.p.z + sz;

    Cells *grid = ((Cells *)((owners::Target_862a0 *)(mgr->grid))->FUN_000862a0());
    int idx = grid->FUN_00204200(f.q);
    if (cells[idx].flag) {
        f.q.y = f.q.y + (*(float*)&DAT_003fef48);
        if (FUN_00202560(&f.q, 20.0f, 0, &f.r2, &f.r1, 0, 0, 0)) {
            if (!(f.r1.y < (*(float*)&DAT_003f7548)) && !(f.r2.y < DAT_0049b8ac) && !(f.r2.y > DAT_0049b8b0)) {
                f.q.y = f.r2.y;
                bool blocked = false;
                for (int i = count - 1; i >= 0; i--) {
                    V3_7e740 *wp = ((V3_7e740 *)((owners::Owner_82cf0 *)(items[i]))->FUN_00082cf0());
                    f.w = *wp;
                    if ((f.w.y - f.q.y) * (f.w.y - f.q.y) + (f.w.z - f.q.z) * (f.w.z - f.q.z) + (f.w.x - f.q.x) * (f.w.x - f.q.x) < DAT_0049b8b4) {
                        blocked = true;
                        break;
                    }
                }
                if (!blocked) {
                    hulk_freg phi = FUN_000964d0()->FUN_000787e0(0.0f, 6.2831855f);
                    int n = DAT_004dd074 + 1;
                    DAT_004dd074 = n;
                    f.w.x = (float)cos((double)phi);
                    f.w.y = 0.0f;
                    f.w.z = (float)sin((double)phi);
                    FUN_000964a0(f.name, 0x20, "cow%d", n);
                    FUN_0007de00(f.name, 0, f.q, f.w);
                }
            }
        }
    }
}

} // namespace fn_fa24d555

// 0x00080820 FUN_00080820 (219 B): equivalent/0x00080820.cpp
// sym: ?FUN_00080820@Actor_80820@owners@@QAEHXZ
// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 4/4)
// FUN_00080820 @ 0x00080820
int owners::Actor_80820::FUN_00080820() {
 Frame_80820 fr;
 int result;
 if (FUN_0007a420(&fr.a,&fr.c,&fr.d,&fr.b)) {
  ++(*(int*)&DAT_004dd078);
  FUN_000964a0(fr.name,32,"civilian%d",(*(int*)&DAT_004dd078));
  result=FUN_0007f560(fr.name,fr.a,fr.c,fr.d,fr.b);
 } else {
  int index=FUN_0007a8f0(&fr.a,&fr.b);
  result=index;
  if(index!=-1) {
   ++(*(int*)&DAT_004dd078);
   FUN_000964a0(fr.name,32,"civilian%d",(*(int*)&DAT_004dd078));
   result=FUN_0007f690(fr.name,index,fr.a,fr.b);
  }
 }
 return result;
}

