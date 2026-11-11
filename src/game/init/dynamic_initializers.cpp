// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0035be88..0x00364840 (kind game-init, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/audio.h"
#include "decls/data/engine/choreo2.h"
#include "decls/data/engine/core.h"
#include "decls/data/engine/fight.h"
#include "decls/data/engine/movie.h"
#include "decls/data/engine/om.h"
#include "decls/data/engine/physics.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/DollyScript.h"
#include "decls/data/game/Render.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/ai.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/hulkfight/scenario.h"
#include "decls/data/game/om.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/audio.h"
#include "decls/data/platform/xbox/core.h"
#include "decls/data/platform/xbox/movie.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "decls/data/platform/xbox/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f1ddef39 {
#define TREE_TU_END }
namespace fn_f1ddef39 {} using namespace fn_f1ddef39;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_f1ddef39 {
void __cdecl FUN_003abdde(int);
class Obj {
  public:
    void Run_002580e0();
    void FUN_003b17b0();
    void FUN_0023fc40(const char*, float);
    void FUN_0025fa00(const char*, int);
    void FUN_0024e670();
    void FUN_002524e0();
    void Fn_002580e0();
};
class X {
  public:
    X();
    ~X();
    char bytes[4];
};
extern void foo();
class Part {
  public:
    Part();
    ~Part();
};
class Next {
  public:
    Next();
    ~Next();
};
class Outer {
    char pad[16];
    Part part;
    Next next;

  public:
    Outer();
};
struct Reg {
};
void FnSound();
extern "C" void __cdecl FUN_00363af0();
} // namespace fn_f1ddef39
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl _atexit(void(__cdecl* f)());
#endif
namespace fn_f1ddef39 {
extern int g0;
} // namespace fn_f1ddef39
unsigned __int64 FUN_0027b020(const char* s);
namespace fn_f1ddef39 {
typedef unsigned __int64 QWORD;
extern unsigned int g_hash_lo;
extern unsigned int g_hash_hi;
typedef unsigned __int64 U64_35c900;
} // namespace fn_f1ddef39
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl _atexit(void (*)());
#endif
namespace fn_f1ddef39 {
class Global {
  public:
    void FUN_0027af00();
    void FUN_002584d0(__int64*, __int64*, int, int);
};
void FUN_00363c30();
} // namespace fn_f1ddef39
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sin(double);
#endif
namespace fn_f1ddef39 {
typedef unsigned __int64 U64_35cb70;
struct Ent_35cb70 { U64_35cb70 id; bool flag; };
struct AnimKey {
    unsigned __int64 key;
    char loops;
    char pad[7];
};
class Sound {
  public:
};
extern Sound gSound;
extern "C" void __cdecl FUN_00363c90();
} // namespace fn_f1ddef39
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif
namespace fn_f1ddef39 {
extern "C" void FUN_00363ca0(void);
} // namespace fn_f1ddef39
extern "C" unsigned __int64 __cdecl FUN_0027b020(unsigned int*);
namespace fn_f1ddef39 {
extern "C" typedef struct {
    char* a;
    char* b;
} Pair_35d030;
extern char hulk_at_004dd750[];
extern char hulk_at_004dd754[];
extern "C" void FUN_00363cc0();
extern "C" void __cdecl FUN_00363cd0();
} // namespace fn_f1ddef39
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void (*f)());
#endif
namespace fn_f1ddef39 {
class Obj_35d140 {
  public:
    void FUN_002923b0();
};
extern "C" void __cdecl FUN_00363ce0();
typedef unsigned int uint32;
typedef unsigned long long uint64;
struct Pair_35d180 {
    unsigned int lo;
    unsigned int hi;
};
} // namespace fn_f1ddef39
extern Pair_35d180 __cdecl FUN_0027b020(void*);
namespace fn_f1ddef39 {
class T {
  public:
    T(const char*, int);
    ~T();
};
extern "C" void __cdecl FUN_00363cf0();
typedef unsigned long long U64_35d240;
struct Obj_b06e0 {
    char bytes[8];
};
extern "C" void __stdcall FUN_00011520(void*, int, int, void(__cdecl*)(Obj_b06e0*));
extern "C" void __cdecl FUN_000b06e0(Obj_b06e0*);
void __cdecl FUN_00363dc0();
extern "C" void cleanup();
struct Hash_35d3a0 {
    void* p;
    unsigned int s;
};
typedef unsigned __int64 U64_35d3c0;
extern "C" void __cdecl FUN_00363df0();
extern "C" void __cdecl Shutdown_00363e00();
extern "C" void __cdecl FUN_00363e10();
} // namespace fn_f1ddef39
extern "C++" __declspec(nothrow) unsigned long long __cdecl FUN_0027b020(const void*);
namespace fn_f1ddef39 {
struct Pair {
  public:
    unsigned a;
    unsigned b;
};
} // namespace fn_f1ddef39
extern Pair __cdecl FUN_0027b020(hulk_intptr);
namespace fn_f1ddef39 {
extern Pair g;
extern const float gB_35d580;
struct Pair_35d5c0 {
    int a;
    int b;
};
} // namespace fn_f1ddef39
Pair_35d5c0 __cdecl FUN_0027b020(int*);
extern __int64 __cdecl FUN_0027b020(const int*);
namespace fn_f1ddef39 {
typedef long long int64_35d850;
struct Pair_35d970 {
    int a;
    int b;
};
typedef unsigned long long U64_35db50;
typedef unsigned long long U64_35dbd0;
typedef unsigned __int64 int64_35dbf0;
extern "C" void __cdecl FUN_00363e50();
extern Obj gObj;
extern int g_a;
extern int g_b;
struct Band {
    float lo;
    float hi;
    int level;
};
static const char text[] = "}";
struct Pair_35df20 {
    int lo;
    int hi;
};
struct G {
    __int64 v;
};
extern unsigned int g_result_lo;
extern unsigned int g_result_hi;
extern Pair result;
extern "C" void __cdecl FUN_00363f30();
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern void __cdecl _atexit(void (*func)());
#endif
typedef unsigned long long U64_35e360;
extern "C" void __cdecl FUN_00363f50();
struct Device {
};
struct Hash_35e3e0 {
    unsigned int lo;
    unsigned int hi;
};
typedef unsigned long long U64_35e440;
extern "C" void __cdecl FUN_00363f90();
extern "C" void __cdecl FUN_00363fc0();
struct Mgr {
};
extern "C" void __cdecl FUN_00364000(void);
class CStaticAllocator_35e6b0 {
  public:
    void FUN_0008fde0(int, int, int, int);
};
extern "C" void __cdecl FUN_00364010();
typedef unsigned __int64 U64_35e780;
struct Handle_35e840 {
    int lo;
    int hi;
};
extern "C" unsigned __int64 FUN_0027afb0(const char *name);
typedef unsigned long long u64_35eb10;
struct Pair_35eb50 {
    unsigned int lo, hi;
};
typedef unsigned __int64 Key_35ec60;
class Registry {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
    void FUN_0025fa00(const char* name, int flags);
};
extern Registry hulk_at_004e2778;
extern void FUN_00364080();
typedef unsigned __int64 U64;
class Sub {
  public:
};
void FUN_003640a0();
extern "C" void __cdecl FUN_001e8800();
extern "C" void __cdecl FUN_001e8830();
extern "C" void __cdecl FUN_003640b0();
struct Allocator_35edb0 {
    void FUN_002475c0(void*, void*);
};
class Resource {
  public:
    Resource(const char*, int);
};
extern "C" void __cdecl FUN_003640e0();
class Item_35ee50 {
    char data[4];

  public:
    void FUN_0027af00();
};
struct Entry_35ee50 {
    Item_35ee50 a;
    char pad0[4];
    Item_35ee50 b;
    char pad1[4];
    Item_35ee50 c;
    char pad2[12];
};
void __cdecl FUN_003640f0();
} // namespace fn_f1ddef39
unsigned __int64 FUN_002672f0(const char* s, int a, int b);
namespace fn_f1ddef39 {
extern int g_lo;
extern int g_hi;
class TypeInfo_3469f5 {
  public:
    const char* FUN_003469f5();
};
extern "C" TypeInfo_3469f5 DAT_004c8040;
} // namespace fn_f1ddef39
extern "C" unsigned long long __cdecl FUN_002672f0(const void* p, int a, int b);
namespace fn_f1ddef39 {
typedef unsigned long long u64;
extern int hulk_at_004e5b50;
extern int hulk_at_004e5b54;
typedef unsigned int u32;
typedef __int64 I64;
struct MixType_35f300 {
    void FUN_00242010();
};
extern "C" void FUN_003641a0();
extern void __cdecl FUN_003641d0();
extern Registry registry;
void FUN_00364200();
extern "C" void __cdecl FUN_00364260(void);
class Holder {
  public:
    void FUN_002584d0(I64*, I64*, int, int);
};
class MetaType_35fa20 {
  public:
    void FUN_0025fa00(const char*, int);
};
extern "C" void __cdecl FUN_003642b0();
typedef void (*AtExitFn)();
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
void __cdecl _atexit(AtExitFn);
#endif
extern void __cdecl FUN_003642c0();
extern "C" void __cdecl FUN_003642e0();
class MetaType_35faa0 {
  public:
    void FUN_0025fa00(const char*, int);
};
extern "C" void __cdecl FUN_003642f0();
class ListenerEffectXBoxType_35fac0 {
  public:
    void FUN_0024d7d0();
};
extern void FUN_00364340();
extern "C" void __cdecl FUN_00364300();
struct ListenerEffectGcType_nv_35fae0 {
    void FUN_0024d8e0();
};
struct ListenerEffectPs2Type_35fb00 {
    void FUN_0024d9e0();
};
extern void FUN_00364310();
extern "C" TypeInfo_3469f5 DAT_004cc58c;
} // namespace fn_f1ddef39
extern "C" void _ReadWriteBarrier();
namespace fn_f1ddef39 {
extern "C" TypeInfo_3469f5 DAT_004cc5b8;
extern "C" TypeInfo_3469f5 DAT_004cc38c;
extern "C" TypeInfo_3469f5 DAT_004cc3b0;
extern "C" void __cdecl FUN_00364350();
extern "C" int __cdecl FUN_002673a0(const char*, int);
class Thing {
  public:
    void FUN_0024ed10();
};
extern "C" void __cdecl FUN_00364380();
struct Manager {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
extern "C++" __declspec(nothrow) void __cdecl FUN_003643b0();
class Holder_35ff90 {
  public:
    void FUN_0024fd10();
};
extern "C" void __cdecl FUN_003643c0();
struct SeqEventWaitBeatType_nv_360170 {
    void FUN_002506d0();
};
extern "C" void __cdecl FUN_00364400(void);
extern "C" void __cdecl FUN_00364430();
extern "C" void __cdecl FUN_00364460();
struct SeqEventPlayTrackType_3603e0 {
    void FUN_00251510();
};
extern "C" void __cdecl FUN_003644a0();
void __cdecl FUN_003644b0();
extern "C" void __cdecl FUN_003644d0();
class SeqEventVarVolumeType_3606d0 {
  public:
    void FUN_002528b0();
};
struct SeqEventVarTempoType_3607a0 {
    void FUN_00252d00();
};
extern "C" void __cdecl FUN_003644f0();
extern "C" void __cdecl FUN_00364530();
struct SeqEventVarPitchRandType_360940 {
    void FUN_002534b0();
};
extern "C" void __cdecl FUN_00364550();
struct SeqEventVarPitchType_360a10 {
    void FUN_002538a0();
};
struct SeqEventStreamType_360a80 {
    void FUN_002540a0();
};
extern "C" void __cdecl FUN_00364570();
extern "C" void __cdecl FUN_00254760();
extern "C" void __cdecl FUN_00364590();
struct G_360bb0 {
};
struct SeqEventLogicRepeatType_360c80 {
    void FUN_00254b10();
};
extern void FUN_003645b0();
struct Mgr_360ff0 {
    void FUN_002584d0(__int64*, __int64*, int, int);
};
extern "C" void __cdecl Done_00364720();
extern "C" void __cdecl FUN_00364730();
typedef unsigned __int64 U64_361630;
extern void __cdecl FUN_00364740();
class Registry_361630 {
  public:
    void FUN_002584d0(U64_361630*, U64_361630*, int, int);
};
extern "C" void __cdecl FUN_00364770();
struct Slot_361760 {
    void* p;
    int a;
    int b;
};
extern "C" void FUN_002705f0();
extern "C" void FUN_00364780();
extern "C" void __cdecl FUN_00364790();
class G_361810 {
  public:
};
class Obj_361820 {
  public:
};
extern "C" void __cdecl FUN_00364800();
struct Entry_3618a0 {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
void FUN_00328580();
void FUN_00328590();
void FUN_003285a0();
void FUN_003285b0();
struct Slot_3619a0 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct Terminator {
    int a, b, c;
    int last;
};
struct HandlerTable_3619a0 {
    Slot_3619a0 slot[4];
    Terminator end;
};
void FUN_003337f0();
void FUN_00333800();
void FUN_00333820();
void FUN_00333810();
typedef void (*Handler_361a90)();
void FUN_0032a4f0();
void FUN_0032a510();
void FUN_0032a530();
void FUN_003333a0();
void FUN_003333b0();
void FUN_003333c0();
void FUN_003333e0();
void FUN_003333f0();
void FUN_00333400();
void FUN_00333770();
void FUN_003337d0();
struct Entry_361a90 {
    Handler_361a90 fn;
    int a, b, c;
    int pad[2];
};
struct Entry_361bf0 {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
void FUN_00333410();
void FUN_00333780();
void FUN_00333830();
void FUN_0032ac50();
typedef void (*Handler_361cf0)();
struct Entry_361cf0 {
    Handler_361cf0 fn;
    int a;
    int b;
    int c;
    char pad[8];
};
struct LastEntry {
    int a, b, c, d;
};
void FUN_0032b940();
void FUN_0032b960();
void FUN_0032b980();
struct Slot_361e50 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct HandlerTable_361e50 {
    Slot_361e50 slot[4];
    Terminator end;
};
void FUN_0032bac0();
typedef void (__cdecl *Handler_361f50)();
void __cdecl FUN_0032c480();
struct Slot_361f50 {
    Handler_361f50 handler;
    int a;
    int b;
    int c;
    int unused[2];                  // not written here
};
struct Slot_362010 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct HandlerTable_362010 {
    Slot_362010 slot[8];
    Terminator end;
};
struct Entry_362120 {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
struct Entry_3621a0 {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
void FUN_0032cb40();
void FUN_0032cb70();
struct StateA { void (*callback)(); unsigned int first; unsigned int second; unsigned int third; char pad[8]; };
struct StateB { void (*callback)(); unsigned int first; unsigned int second; unsigned int third; char pad[8]; };
struct StateC { unsigned int first; unsigned int second; unsigned int third; int fourth; };
struct Slot_3622a0 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct HandlerTable_3622a0 {
    Slot_3622a0 slot[8];
    Terminator end;
};
struct Slot_3623b0 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct HandlerTable_3623b0 {
    Slot_3623b0 slot[3];
    Terminator end;
};
struct Slot_3624d0 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct HandlerTable_3624d0 {
    Slot_3624d0 slot[4];
    Terminator end;
};
void FUN_0032d290();
struct Slot_362570 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct HandlerTable_362570 {
    Slot_362570 slot[7];
    Terminator end;
};
void FUN_0032d2b0();
void FUN_0032d2c0();
void FUN_0032d2d0();
void FUN_0032d2e0();
void FUN_0032d2f0();
void FUN_0032d300();
void FUN_0032d310();
typedef void (*Handler_3626c0)();
struct Entry_3626c0 {
    Handler_3626c0 fn;
    int a;
    int b;
    int c;
    char pad[8];
};
void FUN_0032d8d0();
void FUN_0032da30();
void FUN_0032dab0();
void FUN_0032dad0();
void FUN_0032daf0();
struct Entry_362860 {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
struct Slot_362900 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct HandlerTable_362900 {
    Slot_362900 slot[4];
    Terminator end;
};
void FUN_0032e090();
struct Entry_3629a0 {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
void FUN_0032d9d0();
void FUN_0032da00();
void FUN_0032eb10();
typedef void (__cdecl *Handler_362a20)();
void __cdecl FUN_0032ef00();
struct Slot_362a20 {
    Handler_362a20 handler;
    int a;
    int b;
    int c;
    int unused[2];                  // not written here
};
struct Slot_362b30 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct HandlerTable_362b30 {
    Slot_362b30 slot[8];
    Terminator end;
};
struct Entry_362c40 {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
void FUN_0032eee0();
void FUN_0032eef0();
typedef void (*Handler_362d80)();
void FUN_0032fd10();
void FUN_00330470();
struct Entry_362d80 {
    Handler_362d80 fn;
    int a, b, c;
    int pad[2];
};
struct Slot_362ec0 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct HandlerTable_362ec0 {
    Slot_362ec0 slot[4];
    Terminator end;
};
void FUN_003304b0();
typedef void (*Handler_362f60)();
struct Entry_362f60 {
    Handler_362f60 fn;
    int a;
    int b;
    int c;
    char pad[8];
};
void FUN_00330ca0();
void FUN_00330cc0();
struct Entry_363190 {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
void FUN_00330d30();
typedef void (*Callback)();
void FUN_00331b90();
void FUN_00331bc0();
struct StateEntry {
    Callback callback;
    int a;
    int b;
    int c;
    int unused1;
    int unused2;
};
struct StateBlock {
    StateEntry entries[3];
    int endValue;
};
typedef void (__cdecl *Handler_363290)();
void __cdecl FUN_00331bf0();
struct Slot_363290 {
    Handler_363290 handler;
    int a;
    int b;
    int c;
    int unused[2];                  // not written here
};
struct Slot_363350 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct HandlerTable_363350 {
    Slot_363350 slot[8];
    Terminator end;
};
struct Slot_363460 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct HandlerTable_363460 {
    Slot_363460 slot[3];
    Terminator end;
};
struct Entry_363530 {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
void FUN_00332750();
void FUN_003327b0();
void FUN_00332780();
struct Slot_3635b0 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct HandlerTable_3635b0 {
    Slot_3635b0 slot[9];
    Terminator end;
};
void FUN_003327e0();
struct Slot_3636e0 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct HandlerTable_3636e0 {
    Slot_3636e0 slot[3];
    Terminator end;
};
struct Slot_363760 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct HandlerTable_363760 {
    Slot_363760 slot[4];
    Terminator end;
};
void FUN_00332e60();
void FUN_00332e90();
struct Entry { void (*callback)(); int a,b,c; };
struct Slot_363860 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct HandlerTable_363860 {
    Slot_363860 slot[9];
    Terminator end;
};
void FUN_00332ba0();
struct Entry_363990 {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
struct Entry_363a10 {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
struct Obj_363af0 {
};
struct Obj_363b00 {
    void Fnf_0027af50();
};
struct Obj_363b10 {
    void Fnf_0027af50();
};
struct Obj_363b20 {
    void Fnf_0027af50();
};
struct Obj_363b30 {
    void Fnf_0027af50();
};
extern "C" void __stdcall FUN_0027af50();
class A_363b40 {
  public:
    void Fn_0027af50();
};
extern "C++" __declspec(nothrow) void __fastcall FUN_0027af50(void*);
struct Obj_363b60 {
    void Fnf_0027af50();
};
struct Obj_363b70 {
    void Fnf_0027af50();
};
struct Obj_363b80 {
};
struct Obj_363b90 {
    void Fnf_0027af50();
};
struct Obj_363ba0 {
    void Fnf_0027af50();
};
struct Obj_363bb0 {
    void Fnf_0027af50();
};
struct Obj_363bc0 {
    void Fnf_0027af50();
};
struct Obj_363bd0 {
    void Fnf_0027af50();
};
struct Obj_363be0 {
    void Fnf_0027af50();
};
extern "C" void __cdecl FUN_00066930();
class C_363bf0 {
  public:
    void init_00230f50(void*, void*);
};
struct Obj_363c30 {
    void Fnf_0027af50();
};
struct Obj_363c40 {
    void Fnf_0027af50();
};
struct Obj_363c50 {
};
struct Obj_363c60 {
};
struct Obj_363c70 {
};
struct Obj_363c80 {
};
struct Obj_363ca0 {
};
struct Obj_363cb0 {
};
struct Obj_363cd0 {
};
extern "C" int __cdecl FUN_00085cd0();
extern "C" void __cdecl FUN_00085d70();
struct Obj_363d00 {
};
extern "C" void __cdecl release(void*);
struct Item {
    hulk_intptr a;
    void* p;
};
extern Item hulk_at_004ddb10[11];
extern "C" void __cdecl FUN_000b0ff0();
extern void __stdcall FUN_00013420(void*, int, int, void*);
struct Obj_363df0 {
};
struct Obj_363e00 {
};
struct Obj_363e10 {
};
struct Obj_363e20 {
};
struct Obj_363e70 {
    void Fnf_0027af50();
};
struct Obj_363e80 {
    void Fnf_0027af50();
};
struct Obj_363e90 {
    void Fnf_0027af50();
};
struct Obj_363ea0 {
    void Fnf_0027af50();
};
struct Obj_363eb0 {
    void Fnf_0027af50();
};
struct Obj_363ec0 {
    void Fnf_0027af50();
};
struct Obj_363ed0 {
    void Fnf_0027af50();
};
struct Obj_363ee0 {
    void Fnf_0027af50();
};
struct Obj_363ef0 {
    void Fnf_0027af50();
};
struct Obj_363f00 {
    void Fnf_0027af50();
};
struct Obj_363f10 {
    void Fnf_0027af50();
};
struct Obj_363f20 {
    void Fnf_0027af50();
};
struct Obj_363f30 {
};
struct Obj_363f40 {
};
struct Obj_363f50 {
};
struct Obj_363f60 {
    void Fnf_0027af50();
};
struct Obj_363f70 {
    void Fnf_0027af50();
};
struct Obj_363f80 {
};
struct Obj_363f90 {
};
struct Obj_363fa0 {
    void Fnf_0027af50();
};
struct Obj_363fc0 {
};
struct Obj_363fd0 {
    void Fnf_0027af50();
};
struct Obj_363ff0 {
    void Fnf_002fa750();
};
struct Obj_364000 {
};
struct CStaticAllocator_364010 {
    void Fnf_0008ff50();
};
struct Obj_364020 {
};
struct Obj_364030 {
};
struct Obj_364040 {
};
struct Obj_364050 {
};
struct Obj_364070 {
};
struct Obj_3640a0 {
};
struct Allocator_3640b0 {
    void Fnf_002475e0();
};
struct Obj_3640c0 {
};
struct Obj_3640d0 {
};
struct Obj_364120 {
};
struct Obj_364130 {
    void Fnf_0027af50();
};
struct Obj_364140 {
    void Fnf_0027af50();
};
struct Obj_364160 {
    void Run_002580e0();
};
class G_364170 {
  public:
    void Run_002580e0();
};
class T_364180 {
  public:
    void Fn_002580e0();
};
class A_364190 {
  public:
    void Fn_002580e0();
};
struct Obj_3641a0 {
    void Fnf_00243350();
};
extern "C" char DAT_00429254[];
class Allocator {
  public:
    virtual void Fn();
};
class Obj_3641e0 {
  public:
    void Fn_002580e0();
};
struct Obj_3641f0 {
    void Fn_002580e0();
};
struct X_364200 {
    void FnA_002580e0();
};
struct Obj_364210 {
    void Run_002580e0();
};
extern void __fastcall FUN_002580e0(void*);
class Obj_364230 {
  public:
    void Run_002580e0();
};
extern char g_data_364240[];
struct Obj_364240 {
    void Run_002580e0();
};
struct Obj_364270 {
};
class Obj_364280 {
  public:
    void Fn_002580e0();
};
class G_364290 {
  public:
    void Target_002580e0();
};
class Helper_3642a0 {
  public:
    void Run_002580e0();
};
struct MetaType_3642d0 {
    void FUN_0025fa80();
};
struct MetaType_3642f0 {
    void FUN_0025fa80();
};
struct Obj_364300 {
    void Fnf_00243350();
};
struct Obj_364330 {
    void Fnf_00243350();
};
extern "C" char g_target_364360[];
struct Obj_364360 {
    void Run_002580e0();
};
extern void __fastcall target_func_002580e0(void*);
struct G_364390 {
    void Run_002580e0();
};
struct Obj_3643a0 {
    void Fnf_00260680();
};
struct Obj_3643c0 {
    void Fnf_00260680();
};
struct Obj_3643d0 {
    void Fn_002580e0();
};
struct Obj_3643e0 {
    void Fnf_00260680();
};
class Obj_3643f0 {
  public:
    void Fn_002580e0();
};
struct Obj_364400 {
    void Fnf_00260680();
};
struct Helper_364410 {
    void Run_002580e0();
};
struct Obj_364420 {
    void Fnf_00260680();
};
class Obj_364430 {
  public:
    void Fn_002580e0();
};
class Sub_364450 {
  public:
    void Fn_002580e0();
};
struct Obj_364460 {
    void Fnf_00260680();
};
class SeqEventChannelSendVolumesType_364470 {
  public:
    void go_002580e0();
};
class Obj_364480 {
  public:
    void Fn_002580e0();
};
struct Obj_364490 {
    void Fnf_00260680();
};
class Obj_3644a0 {
  public:
    void Fn_002580e0();
};
struct Obj_3644d0 {
    void Fnf_00260680();
};
class Obj_3644e0 {
  public:
    void Fn_002580e0();
};
struct Obj_3644f0 {
    void Fnf_00260680();
};
extern void* g364520;
struct Obj_364520 {
    void Go_002580e0();
};
struct Obj_364530 {
    void Fnf_00260680();
};
class Obj_364540 {
  public:
    void Run_002580e0();
};
struct Obj_364550 {
    void Fnf_00260680();
};
struct Obj_364560 {
    void Fn_002580e0();
};
struct Obj_364570 {
    void Fnf_00260680();
};
struct Obj_364590 {
    void Fnf_00260680();
};
class Obj_3645a0 {
  public:
    void Fn_002580e0();
};
class Obj_3645c0 {
  public:
    void Run_002580e0();
};
struct Obj_3645d0 {
    void Fnf_00260680();
};
struct Obj_3645f0 {
    void Fnf_00260680();
};
struct Obj_364610 {
    void Fnf_00260680();
};
struct Obj_364620 {
    void Run_002580e0();
};
struct Obj_364630 {
    void Fnf_00243350();
};
struct Obj_364650 {
    void Fn_002580e0();
};
class Thing_364660 {
  public:
    ~Thing_364660() throw();
};
struct G_364670 {
    void Run_002580e0();
};
struct Obj_364680 {
    void Run();
};
void __fastcall FUN_002580e0(Obj_364680*) throw();
struct Obj_364690 {
    void Fn_002580e0();
};
class Obj_3646b0 {
  public:
    void Run_002580e0();
};
class Obj_3646c0 {
  public:
    void Fn_002580e0();
};
class Obj_3646d0 {
  public:
    void Run_002580e0();
};
struct Obj_3646e0 {
    void Init_002580e0();
};
struct Obj_3646f0 {
    void Run_002580e0();
};
class Obj_364700 {
  public:
    void Run_002580e0();
};
class Base_364710 {
  public:
    void Fn_002580e0();
};
class Obj_364710 : public Base_364710 {
  public:
    void Fn();
};
class A_364720 {
  public:
    void Run_002580e0();
};
struct Obj_364730 {
    void Run_002580e0();
};
class Obj_364750 {
  public:
    void Run_002580e0();
};
class Obj_364760 {
  public:
    void Target_002580e0();
};
extern "C" char DAT_003f6098[];
class IRefCount {
  public:
    virtual void F();
};
extern "C" void __cdecl thunk_FUN_00267090(int);
struct ImageConverter_3647b0 {
    void Fnf_002de240();
};
extern "C" {
void __cdecl thunk_0008d340(int);
}
extern "C" {
void __cdecl FUN_002f9fb0(int, int);
}
extern void* hulk_at_0043276c;
struct Obj_364810 {
    void Fnf_00337d40();
};
struct Obj_364820 {
    void Fnf_00337d40();
};

// 0x0035be88 __unwindfunclet_0035be88 (8 B): not yet verified
// 0x0035be9b __ehhandler_0035be9b (10 B): not yet verified
// 0x0035bea5 __unwindfunclet_0035bea5 (8 B): not yet verified
// 0x0035bead __unwindfunclet_0035bead (8 B): not yet verified
// 0x0035beb5 __unwindfunclet_0035beb5 (8 B): not yet verified
// 0x0035bebd __ehhandler_0035bebd (10 B): not yet verified
// 0x0035bec7 __unwindfunclet_0035bec7 (8 B): not yet verified
// 0x0035becf __unwindfunclet_0035becf (8 B): not yet verified
// 0x0035bed7 __unwindfunclet_0035bed7 (8 B): not yet verified
// 0x0035bedf __ehhandler_0035bedf (10 B): not yet verified
// 0x0035bee9 __unwindfunclet_0035bee9 (8 B): not yet verified
// 0x0035bef1 __unwindfunclet_0035bef1 (8 B): not yet verified
// 0x0035bef9 __unwindfunclet_0035bef9 (8 B): not yet verified
// 0x0035bf01 __ehhandler_0035bf01 (10 B): not yet verified
// 0x0035bf0b __unwindfunclet_0035bf0b (8 B): not yet verified
// 0x0035bf13 __ehhandler_0035bf13 (10 B): not yet verified
// 0x0035bf1d __unwindfunclet_0035bf1d (8 B): not yet verified
// 0x0035bf25 __ehhandler_0035bf25 (10 B): not yet verified
// 0x0035bf2f __unwindfunclet_0035bf2f (8 B): not yet verified
// 0x0035bf37 __unwindfunclet_0035bf37 (8 B): not yet verified
// 0x0035bf3f __unwindfunclet_0035bf3f (8 B): not yet verified
// 0x0035bf47 __ehhandler_0035bf47 (10 B): not yet verified
// 0x0035bf51 __unwindfunclet_0035bf51 (8 B): not yet verified
// 0x0035bf59 __ehhandler_0035bf59 (10 B): not yet verified
// 0x0035bf63 __unwindfunclet_0035bf63 (8 B): not yet verified
// 0x0035bf6b __ehhandler_0035bf6b (10 B): not yet verified
// 0x0035bf75 __unwindfunclet_0035bf75 (8 B): not yet verified
// 0x0035bf7d __ehhandler_0035bf7d (10 B): not yet verified
// 0x0035bf87 __unwindfunclet_0035bf87 (8 B): not yet verified
// 0x0035bf8f __unwindfunclet_0035bf8f (8 B): not yet verified
// 0x0035bf97 __ehhandler_0035bf97 (10 B): not yet verified
// 0x0035bfa1 __unwindfunclet_0035bfa1 (8 B): not yet verified
// 0x0035bfa9 __unwindfunclet_0035bfa9 (11 B): not yet verified
// 0x0035bfb4 __ehhandler_0035bfb4 (10 B): not yet verified
// 0x0035bfbe __unwindfunclet_0035bfbe (8 B): not yet verified
// 0x0035bfc6 __unwindfunclet_0035bfc6 (8 B): not yet verified
// 0x0035bfce __unwindfunclet_0035bfce (11 B): not yet verified
// 0x0035bfd9 __unwindfunclet_0035bfd9 (10 B): not yet verified
// 0x0035bfe3 __ehhandler_0035bfe3 (10 B): not yet verified
// 0x0035bfed __unwindfunclet_0035bfed (10 B): not yet verified
// 0x0035bff7 __ehhandler_0035bff7 (10 B): not yet verified
// 0x0035c001 __unwindfunclet_0035c001 (8 B): not yet verified
// 0x0035c009 __ehhandler_0035c009 (10 B): not yet verified
// 0x0035c013 __unwindfunclet_0035c013 (8 B): not yet verified
// 0x0035c01b __ehhandler_0035c01b (10 B): not yet verified
// 0x0035c025 __unwindfunclet_0035c025 (8 B): not yet verified
// 0x0035c02d __ehhandler_0035c02d (10 B): not yet verified
// 0x0035c037 __unwindfunclet_0035c037 (8 B): not yet verified
// 0x0035c03f __unwindfunclet_0035c03f (11 B): not yet verified
// 0x0035c04a __unwindfunclet_0035c04a (11 B): not yet verified
// 0x0035c055 __unwindfunclet_0035c055 (11 B): not yet verified
// 0x0035c060 __ehhandler_0035c060 (10 B): not yet verified
// 0x0035c06a __unwindfunclet_0035c06a (10 B): not yet verified
// 0x0035c074 __unwindfunclet_0035c074 (10 B): not yet verified
// 0x0035c07e __unwindfunclet_0035c07e (10 B): not yet verified
// 0x0035c088 __unwindfunclet_0035c088 (10 B): not yet verified
// 0x0035c092 __ehhandler_0035c092 (10 B): not yet verified
// 0x0035c09c __unwindfunclet_0035c09c (10 B): not yet verified
// 0x0035c0a6 __unwindfunclet_0035c0a6 (10 B): not yet verified

// 0x0035c0b0 FUN_0035c0b0 (10 B): equivalent/0x0035c0b0.cpp
// sym: ?FUN_0035c0b0@fn_f1ddef39@@YAXPAD@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0035c0b0 @ 0x0035c0b0
// equiv-conv: FUN_0035c0b0 ebp
void __cdecl FUN_0035c0b0(char *callerFrame) {
    FUN_003abdde(*(int *)(callerFrame - 0x10));
}

// 0x0035c0ba __unwindfunclet_0035c0ba (10 B): not yet verified
// 0x0035c0c4 __unwindfunclet_0035c0c4 (10 B): not yet verified
// 0x0035c0ce __unwindfunclet_0035c0ce (10 B): not yet verified
// 0x0035c0d8 __unwindfunclet_0035c0d8 (10 B): not yet verified
// 0x0035c0e2 __ehhandler_0035c0e2 (10 B): not yet verified
// 0x0035c0ec __unwindfunclet_0035c0ec (8 B): not yet verified
// 0x0035c0f4 __unwindfunclet_0035c0f4 (8 B): not yet verified
// 0x0035c0fc __unwindfunclet_0035c0fc (8 B): not yet verified
// 0x0035c104 __ehhandler_0035c104 (10 B): not yet verified
// 0x0035c10e __unwindfunclet_0035c10e (8 B): not yet verified
// 0x0035c116 __unwindfunclet_0035c116 (11 B): not yet verified
// 0x0035c121 __unwindfunclet_0035c121 (11 B): not yet verified
// 0x0035c12c __unwindfunclet_0035c12c (11 B): not yet verified
// 0x0035c137 __unwindfunclet_0035c137 (11 B): not yet verified
// 0x0035c142 __ehhandler_0035c142 (10 B): not yet verified
// 0x0035c14c __unwindfunclet_0035c14c (10 B): not yet verified
// 0x0035c156 __ehhandler_0035c156 (10 B): not yet verified
// 0x0035c160 __unwindfunclet_0035c160 (10 B): not yet verified
// 0x0035c16a __ehhandler_0035c16a (10 B): not yet verified
// 0x0035c174 __unwindfunclet_0035c174 (8 B): not yet verified
// 0x0035c17c __ehhandler_0035c17c (10 B): not yet verified
// 0x0035c186 __unwindfunclet_0035c186 (8 B): not yet verified
// 0x0035c18e __unwindfunclet_0035c18e (11 B): not yet verified
// 0x0035c199 __ehhandler_0035c199 (10 B): not yet verified
// 0x0035c1a3 __unwindfunclet_0035c1a3 (8 B): not yet verified
// 0x0035c1ab __ehhandler_0035c1ab (10 B): not yet verified
// 0x0035c1b5 __unwindfunclet_0035c1b5 (8 B): not yet verified
// 0x0035c1bd __ehhandler_0035c1bd (10 B): not yet verified
// 0x0035c1c7 __unwindfunclet_0035c1c7 (8 B): not yet verified
// 0x0035c1cf __unwindfunclet_0035c1cf (11 B): not yet verified
// 0x0035c1da __ehhandler_0035c1da (10 B): not yet verified
// 0x0035c1e4 __unwindfunclet_0035c1e4 (8 B): not yet verified
// 0x0035c1ec __ehhandler_0035c1ec (10 B): not yet verified
// 0x0035c1f6 __unwindfunclet_0035c1f6 (8 B): not yet verified
// 0x0035c1fe __ehhandler_0035c1fe (10 B): not yet verified
// 0x0035c208 __unwindfunclet_0035c208 (8 B): not yet verified
// 0x0035c210 __ehhandler_0035c210 (10 B): not yet verified
// 0x0035c21a __unwindfunclet_0035c21a (8 B): not yet verified
// 0x0035c222 __ehhandler_0035c222 (10 B): not yet verified
// 0x0035c22c __unwindfunclet_0035c22c (11 B): not yet verified
// 0x0035c237 __unwindfunclet_0035c237 (11 B): not yet verified
// 0x0035c242 __unwindfunclet_0035c242 (8 B): not yet verified
// 0x0035c24a __unwindfunclet_0035c24a (8 B): not yet verified
// 0x0035c252 __unwindfunclet_0035c252 (8 B): not yet verified
// 0x0035c25a __unwindfunclet_0035c25a (8 B): not yet verified
// 0x0035c262 __unwindfunclet_0035c262 (8 B): not yet verified
// 0x0035c26a __unwindfunclet_0035c26a (8 B): not yet verified
// 0x0035c272 __unwindfunclet_0035c272 (8 B): not yet verified
// 0x0035c27a __ehhandler_0035c27a (10 B): not yet verified
// 0x0035c284 __unwindfunclet_0035c284 (25 B): not yet verified
// 0x0035c29d __ehhandler_0035c29d (10 B): not yet verified
// 0x0035c2a7 __unwindfunclet_0035c2a7 (8 B): not yet verified
// 0x0035c2af __unwindfunclet_0035c2af (8 B): not yet verified
// 0x0035c2b7 __unwindfunclet_0035c2b7 (8 B): not yet verified
// 0x0035c2bf __unwindfunclet_0035c2bf (8 B): not yet verified
// 0x0035c2c7 __ehhandler_0035c2c7 (10 B): not yet verified
// 0x0035c2d1 __unwindfunclet_0035c2d1 (8 B): not yet verified
// 0x0035c2d9 __unwindfunclet_0035c2d9 (8 B): not yet verified
// 0x0035c2e1 __ehhandler_0035c2e1 (10 B): not yet verified
// 0x0035c2eb __unwindfunclet_0035c2eb (8 B): not yet verified
// 0x0035c2f3 __unwindfunclet_0035c2f3 (11 B): not yet verified
// 0x0035c2fe __unwindfunclet_0035c2fe (11 B): not yet verified
// 0x0035c309 __unwindfunclet_0035c309 (11 B): not yet verified
// 0x0035c314 __unwindfunclet_0035c314 (10 B): not yet verified
// 0x0035c31e __unwindfunclet_0035c31e (10 B): not yet verified
// 0x0035c328 __unwindfunclet_0035c328 (10 B): not yet verified
// 0x0035c332 __unwindfunclet_0035c332 (10 B): not yet verified
// 0x0035c33c __unwindfunclet_0035c33c (10 B): not yet verified
// 0x0035c346 __unwindfunclet_0035c346 (10 B): not yet verified
} // namespace fn_f1ddef39

// 0x0035c350 FUN_0035c350 (10 B): equivalent/0x0035c350.cpp [wrapped: conflict: FUN_003abdde]
// sym: ?FUN_0035c350@fn_0035c350@@YAHPAUContext@1@@Z
namespace fn_0035c350 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0035c350 @ 0x0035c350
struct Context { char padding[0x14]; int value; };
int __cdecl FUN_003abdde(int value);
// equiv-conv: FUN_0035c350 ebp
int FUN_0035c350(Context* context) {
    return FUN_003abdde(context->value);
}
} // namespace fn_0035c350

// 0x0035c35a __ehhandler_0035c35a (10 B): not yet verified
// 0x0035c364 __unwindfunclet_0035c364 (8 B): not yet verified
// 0x0035c36c __unwindfunclet_0035c36c (11 B): not yet verified
// 0x0035c377 __unwindfunclet_0035c377 (11 B): not yet verified
// 0x0035c382 __unwindfunclet_0035c382 (11 B): not yet verified
// 0x0035c38d __unwindfunclet_0035c38d (11 B): not yet verified
// 0x0035c398 __unwindfunclet_0035c398 (10 B): not yet verified
// 0x0035c3a2 __unwindfunclet_0035c3a2 (10 B): not yet verified
// 0x0035c3ac __unwindfunclet_0035c3ac (10 B): not yet verified
// 0x0035c3b6 __ehhandler_0035c3b6 (10 B): not yet verified
namespace fn_f1ddef39 {

// 0x0035c3c0 FUN_0035c3c0 (8 B): equivalent/0x0035c3c0.cpp
// sym: ?FUN_0035c3c0@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0035c3c0 @ 0x0035c3c0
void __cdecl FUN_0035c3c0() { Obj* object = 0; object->FUN_003b17b0(); }

// 0x0035c3c8 __unwindfunclet_0035c3c8 (14 B): not yet verified
// 0x0035c3d6 __ehhandler_0035c3d6 (10 B): not yet verified

// 0x0035c3e0 FUN_0035c3e0 (8 B): matches/0x0035c3e0.cpp
// sym: $L#0@?FUN_0035c3e0@fn_f1ddef39@@YAXHHHHHVX@1@@Z
void FUN_0035c3e0(int a, int b, int c, int d, int e, X obj) {
    foo();
}

// 0x0035c3e8 __unwindfunclet_0035c3e8 (8 B): not yet verified
// 0x0035c3f0 __ehhandler_0035c3f0 (10 B): not yet verified
// 0x0035c3fa __unwindfunclet_0035c3fa (8 B): not yet verified
// 0x0035c402 __ehhandler_0035c402 (10 B): not yet verified
// 0x0035c40c __unwindfunclet_0035c40c (8 B): not yet verified
// 0x0035c414 __ehhandler_0035c414 (10 B): not yet verified
// 0x0035c41e __unwindfunclet_0035c41e (8 B): not yet verified
// 0x0035c426 __unwindfunclet_0035c426 (8 B): not yet verified
// 0x0035c42e __ehhandler_0035c42e (10 B): not yet verified
// 0x0035c438 __unwindfunclet_0035c438 (8 B): not yet verified
// 0x0035c440 __ehhandler_0035c440 (10 B): not yet verified
// 0x0035c44a __unwindfunclet_0035c44a (10 B): not yet verified
// 0x0035c454 __unwindfunclet_0035c454 (10 B): not yet verified
// 0x0035c45e __unwindfunclet_0035c45e (10 B): not yet verified
// 0x0035c468 __unwindfunclet_0035c468 (10 B): not yet verified
// 0x0035c472 __ehhandler_0035c472 (10 B): not yet verified
// 0x0035c47c __unwindfunclet_0035c47c (8 B): not yet verified
// 0x0035c484 __unwindfunclet_0035c484 (8 B): not yet verified
// 0x0035c48c __unwindfunclet_0035c48c (8 B): not yet verified
// 0x0035c494 __unwindfunclet_0035c494 (8 B): not yet verified
// 0x0035c49c __unwindfunclet_0035c49c (8 B): not yet verified
// 0x0035c4a4 __unwindfunclet_0035c4a4 (10 B): not yet verified
// 0x0035c4ae __ehhandler_0035c4ae (10 B): not yet verified
// 0x0035c4b8 __unwindfunclet_0035c4b8 (8 B): not yet verified

// 0x0035c4c0 FUN_0035c4c0 (11 B): matches/0x0035c4c0.cpp
// sym: $L#0@??0Outer@fn_f1ddef39@@QAE@XZ
Outer::Outer() {}

// 0x0035c4cb __unwindfunclet_0035c4cb (11 B): not yet verified
// 0x0035c4d6 __unwindfunclet_0035c4d6 (11 B): not yet verified
// 0x0035c4e1 __unwindfunclet_0035c4e1 (11 B): not yet verified
// 0x0035c4ec __unwindfunclet_0035c4ec (11 B): not yet verified
// 0x0035c4f7 __ehhandler_0035c4f7 (10 B): not yet verified
// 0x0035c501 __unwindfunclet_0035c501 (8 B): not yet verified
// 0x0035c509 __unwindfunclet_0035c509 (11 B): not yet verified
// 0x0035c514 __unwindfunclet_0035c514 (11 B): not yet verified
// 0x0035c51f __unwindfunclet_0035c51f (11 B): not yet verified
// 0x0035c52a __unwindfunclet_0035c52a (11 B): not yet verified
// 0x0035c535 __unwindfunclet_0035c535 (11 B): not yet verified
// 0x0035c540 __ehhandler_0035c540 (10 B): not yet verified
// 0x0035c54a __unwindfunclet_0035c54a (8 B): not yet verified
// 0x0035c552 __unwindfunclet_0035c552 (8 B): not yet verified
// 0x0035c55a __ehhandler_0035c55a (10 B): not yet verified
// 0x0035c564 __unwindfunclet_0035c564 (11 B): not yet verified
// 0x0035c56f __unwindfunclet_0035c56f (11 B): not yet verified
// 0x0035c57a __ehhandler_0035c57a (10 B): not yet verified
// 0x0035c584 __unwindfunclet_0035c584 (11 B): not yet verified
// 0x0035c58f __unwindfunclet_0035c58f (11 B): not yet verified
// 0x0035c59a __unwindfunclet_0035c59a (22 B): not yet verified
// 0x0035c5b0 FUN_0035c5b0 (304 B): not yet verified
} // namespace fn_f1ddef39

// 0x0035c6e0 FUN_0035c6e0 (25 B): matches/0x0035c6e0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035c6e0@fn_0035c6e0@@YAXXZ
namespace fn_0035c6e0 {

struct Pair_35c6e0 {
    int lo;
    int hi;
};
extern "C++" __declspec(nothrow) Pair_35c6e0 FUN_0027b020(const char*);
void FUN_0035c6e0() {
    Pair_35c6e0 x = FUN_0027b020("golfBall_golfBall");
    (*(int*)&DAT_004dc030) = x.lo;
    (*(int*)((char*)&DAT_004dc030 + 4)) = x.hi;
}
} // namespace fn_0035c6e0

namespace fn_f1ddef39 {

// 0x0035c700 FUN_0035c700 (29 B): matches/0x0035c700.cpp
// sym: ?FUN_0035c700@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035c700() {
    ((owners::String_23fc40 *)&((*(Reg*)&DAT_004dc020)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    _atexit(FUN_00363af0);
}

} // namespace fn_f1ddef39

// 0x0035c720 FUN_0035c720 (25 B): matches/0x0035c720.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035c720@fn_0035c720@@YAXXZ
namespace fn_0035c720 {

extern "C" struct Result_35c720 {
    int a;
    int b;
};
extern "C++" __declspec(nothrow) Result_35c720 __cdecl FUN_0027b020(const char* name);
void FUN_0035c720() {
    Result_35c720 r = FUN_0027b020("golfBall_golfBall");
    (*(int*)&DAT_004dc088) = r.a;
    (*(int*)&DAT_004dc08c) = r.b;
}
} // namespace fn_0035c720


// 0x0035c740 FUN_0035c740 (25 B): matches/0x0035c740.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035c740@fn_0035c740@@YAXXZ
namespace fn_0035c740 {

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035c740() {
    unsigned long long h = FUN_0027b020("hulk");
    (*(unsigned long*)&DAT_004dc0e0) = (unsigned long)h;
    (*(unsigned long*)((char*)&DAT_004dc0e0 + 4)) = (unsigned long)(h >> 32);
}
} // namespace fn_0035c740

namespace fn_f1ddef39 {

// 0x0035c760 FUN_0035c760 (25 B): matches/0x0035c760.cpp
// sym: ?FUN_0035c760@fn_f1ddef39@@YAXXZ
void FUN_0035c760() {
    unsigned long long r = FUN_0027b020("missilesoldier");
    (*(unsigned int*)&DAT_004dc040) = (unsigned int)r;
    (*(unsigned int*)&DAT_004dc044) = (unsigned int)(r >> 32);
}


// 0x0035c780 FUN_0035c780 (25 B): matches/0x0035c780.cpp
// sym: ?FUN_0035c780@fn_f1ddef39@@YAXXZ
void FUN_0035c780() {
    unsigned long long r = FUN_0027b020("apache");
    g0 = (int)r;
    (*(int*)&DAT_004dc0a4) = (int)(r >> 32);
}


// 0x0035c7a0 FUN_0035c7a0 (25 B): matches/0x0035c7a0.cpp
// sym: ?FUN_0035c7a0@fn_f1ddef39@@YAXXZ
// data: gValue = DAT_004dc0b0
void FUN_0035c7a0() {
    (*(unsigned __int64*)&DAT_004dc0b0) = FUN_0027b020("blackhawk");
}


// 0x0035c7c0 FUN_0035c7c0 (25 B): matches/0x0035c7c0.cpp
// sym: ?FUN_0035c7c0@fn_f1ddef39@@YAXXZ
// data: g_symbol = DAT_004dc058
void FUN_0035c7c0() {
    (*(QWORD*)&DAT_004dc058) = FUN_0027b020("apache_leader");
}

} // namespace fn_f1ddef39

// 0x0035c7e0 FUN_0035c7e0 (25 B): matches/0x0035c7e0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035c7e0@fn_0035c7e0@@YAXXZ
namespace fn_0035c7e0 {

struct Pair_35c7e0 {
    unsigned int lo;
    unsigned int hi;
};
extern "C++" __declspec(nothrow) Pair_35c7e0 __cdecl FUN_0027b020(const char*);

void FUN_0035c7e0() {
    Pair_35c7e0 p = FUN_0027b020("blackhawk_leader");
    (*(unsigned int*)&DAT_004dc070) = p.lo;
    (*(unsigned int*)&DAT_004dc074) = p.hi;
}
} // namespace fn_0035c7e0

namespace fn_f1ddef39 {

// 0x0035c800 FUN_0035c800 (25 B): matches/0x0035c800.cpp
// sym: ?FUN_0035c800@fn_f1ddef39@@YAXXZ
// data: gGlobal2 = DAT_004dc04c, gGlobal_35c800 = DAT_004dc048
void FUN_0035c800() {
    unsigned long long v = FUN_0027b020("commanche");
    *(unsigned int*)((char*)&DAT_004dc048) = (unsigned int)v;
    *(unsigned int*)((char*)&DAT_004dc04c) = (unsigned int)(v >> 32);
}


// 0x0035c820 FUN_0035c820 (25 B): matches/0x0035c820.cpp
// sym: ?FUN_0035c820@fn_f1ddef39@@YAXXZ
// data: gHash_35c820 = DAT_004dc050
void FUN_0035c820() {
    unsigned long long h = FUN_0027b020("harrier");
    ((unsigned int*)&DAT_004dc050)[0] = (unsigned int)h;
    ((unsigned int*)&DAT_004dc050)[1] = (unsigned int)(h >> 32);
}

} // namespace fn_f1ddef39

// 0x0035c840 FUN_0035c840 (25 B): matches/0x0035c840.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035c840@fn_0035c840@@YAXXZ
namespace fn_0035c840 {

extern "C" {
struct Pair {
    unsigned a, b;
};
extern "C++" { __declspec(nothrow) Pair FUN_0027b020(const char*); }
}
void FUN_0035c840() {
    (*(Pair*)&DAT_004dc0c0) = FUN_0027b020("tank");
}
} // namespace fn_0035c840

namespace fn_f1ddef39 {

// 0x0035c860 FUN_0035c860 (25 B): matches/0x0035c860.cpp
// sym: ?FUN_0035c860@fn_f1ddef39@@YAXXZ
void FUN_0035c860() {
    unsigned long long r = FUN_0027b020("bradley");
    (*(unsigned int*)&DAT_004dc098) = (unsigned int)r;
    (*(unsigned int*)((char*)&DAT_004dc098 + 4)) = (unsigned int)(r >> 32);
}

} // namespace fn_f1ddef39

// 0x0035c880 FUN_0035c880 (25 B): matches/0x0035c880.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035c880@fn_0035c880@@YAXXZ
namespace fn_0035c880 {
// data: result = DAT_004dc078

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035c880() {
    (*(Pair*)&DAT_004dc078) = FUN_0027b020("mlrs");
}
} // namespace fn_0035c880

namespace fn_f1ddef39 {

// 0x0035c8a0 FUN_0035c8a0 (25 B): matches/0x0035c8a0.cpp
// sym: ?FUN_0035c8a0@fn_f1ddef39@@YAXXZ
// data: gHash = DAT_004dc0c8
void FUN_0035c8a0() {
    DAT_004dc0c8 = FUN_0027b020("combat_warden");
}


// 0x0035c8c0 FUN_0035c8c0 (25 B): matches/0x0035c8c0.cpp
// sym: ?FUN_0035c8c0@fn_f1ddef39@@YAXXZ
void FUN_0035c8c0() {
    unsigned long long r = FUN_0027b020("devil_hulk");
    (*(unsigned int*)&DAT_004dc090) = (unsigned int)r;
    (*(unsigned int*)((char*)&DAT_004dc090 + 4)) = (unsigned int)(r >> 32);
}


// 0x0035c8e0 FUN_0035c8e0 (25 B): matches/0x0035c8e0.cpp
// sym: ?FUN_0035c8e0@fn_f1ddef39@@YAXXZ
void FUN_0035c8e0() {
    unsigned long long r = FUN_0027b020("samson_car");
    g_hash_lo = (unsigned int)r;
    g_hash_hi = (unsigned int)(r >> 32);
}


// 0x0035c900 FUN_0035c900 (25 B): matches/0x0035c900.cpp
// sym: ?FUN_0035c900@fn_f1ddef39@@YAXXZ
// data: hulk_at_003f3fd8 = DAT_003f3fd8
void FUN_0035c900() {
    U64_35c900 r = FUN_0027b020((const char*)((hulk_intptr)((char*)&DAT_003f3fd8)));
    (*(int*)&DAT_004dc0b8) = (int)r;
    (*(int*)((char*)&DAT_004dc0b8 + 4)) = (int)(r >> 32);
}

} // namespace fn_f1ddef39

// 0x0035c920 FUN_0035c920 (25 B): matches/0x0035c920.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035c920@fn_0035c920@@YAXXZ
namespace fn_0035c920 {
// data: globalPair = DAT_004dc0a8

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035c920() {
    (*(Pair*)&DAT_004dc0a8) = FUN_0027b020("destroyer");
}
} // namespace fn_0035c920


// 0x0035c940 FUN_0035c940 (25 B): matches/0x0035c940.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035c940@fn_0035c940@@YAXXZ
namespace fn_0035c940 {
// data: gValue = DAT_004dc068

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
void __cdecl FUN_0035c940() {
    DAT_004dc068 = FUN_0027b020("titan");
}
} // namespace fn_0035c940

namespace fn_f1ddef39 {

// 0x0035c960 FUN_0035c960 (25 B): matches/0x0035c960.cpp
// sym: ?FUN_0035c960@fn_f1ddef39@@YAXXZ
// data: g_result_35c960 = DAT_004dc0d0
void FUN_0035c960() {
    (*(unsigned __int64*)&DAT_004dc0d0) = FUN_0027b020("cargo_truck");
}

} // namespace fn_f1ddef39

// 0x0035c980 FUN_0035c980 (25 B): matches/0x0035c980.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035c980@fn_0035c980@@YAXXZ
namespace fn_0035c980 {

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035c980() {
    (*(Pair*)&DAT_004dc080) = FUN_0027b020("mercy");
}
} // namespace fn_0035c980

namespace fn_f1ddef39 {

// 0x0035c9a0 FUN_0035c9a0 (11 B): matches/0x0035c9a0.cpp
// sym: ?FUN_0035c9a0@fn_f1ddef39@@YAXXZ
// data: gValue = DAT_004dc0d8
void FUN_0035c9a0() {
    (*(float*)&DAT_004dc0d8) = 8.0f;
}

} // namespace fn_f1ddef39

// 0x0035c9b0 FUN_0035c9b0 (25 B): matches/0x0035c9b0.cpp [wrapped: conflict: FUN_0027b020; Pair]
// sym: ?FUN_0035c9b0@fn_0035c9b0@@YAXXZ
namespace fn_0035c9b0 {
// data: result = DAT_004dc2a0

struct Pair {
    int a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void __cdecl FUN_0035c9b0() {
    (*(Pair*)&DAT_004dc2a0) = FUN_0027b020("golfBall_golfBall");
}
} // namespace fn_0035c9b0


// 0x0035c9d0 FUN_0035c9d0 (29 B): matches/0x0035c9d0.cpp [wrapped: conflict: Reg]
// sym: ?FUN_0035c9d0@fn_0035c9d0@@YAXXZ
namespace fn_0035c9d0 {

extern void Reg(const char* name, int a);
extern "C++" __declspec(nothrow) void FUN_00363b80();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int atexit(void (*)());
#endif

struct G {
    void Reg(const char* name, int a);
};
void FUN_0035c9d0() {
    ((owners::String_23fc40 *)&DAT_004dc294)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363b80);
}
} // namespace fn_0035c9d0

namespace fn_f1ddef39 {

// 0x0035c9f0 FUN_0035c9f0 (25 B): matches/0x0035c9f0.cpp
// sym: ?FUN_0035c9f0@fn_f1ddef39@@YAXXZ
void FUN_0035c9f0() {
    (*(unsigned long long*)&DAT_004dc3f0) = FUN_0027b020("golfBall_golfBall");
}

} // namespace fn_f1ddef39

// 0x0035ca10 FUN_0035ca10 (25 B): matches/0x0035ca10.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035ca10@fn_0035ca10@@YAXXZ
namespace fn_0035ca10 {
// data: gValue = DAT_004dc588

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035ca10() {
    (*(__int64*)&DAT_004dc588) = FUN_0027b020("golfBall_golfBall");
}
} // namespace fn_0035ca10


// 0x0035ca30 FUN_0035ca30 (25 B): matches/0x0035ca30.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035ca30@fn_0035ca30@@YAXXZ
namespace fn_0035ca30 {
// data: result = DAT_004dcee0

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void __cdecl FUN_0035ca30() {
    (*(Pair*)&DAT_004dcee0) = FUN_0027b020("squad");
}
} // namespace fn_0035ca30


// 0x0035ca50 FUN_0035ca50 (25 B): matches/0x0035ca50.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035ca50@fn_0035ca50@@YAXXZ
namespace fn_0035ca50 {
// data: g_hash_35ca50 = DAT_004dced0

struct Pair_35ca50 {
    int a;
    int b;
};
extern "C++" __declspec(nothrow) Pair_35ca50 __cdecl FUN_0027b020(const char*);
void __cdecl FUN_0035ca50() {
    (*(Pair_35ca50*)&DAT_004dced0) = FUN_0027b020("jumping");
}
} // namespace fn_0035ca50

namespace fn_f1ddef39 {

// 0x0035ca70 FUN_0035ca70 (25 B): matches/0x0035ca70.cpp
// sym: ?FUN_0035ca70@fn_f1ddef39@@YAXXZ
void FUN_0035ca70() {
    unsigned long long h = FUN_0027b020("punching");
    (*(unsigned int*)&DAT_004dcef8) = (unsigned int)h;
    (*(unsigned int*)&DAT_004dcefc) = (unsigned int)(h >> 32);
}

} // namespace fn_f1ddef39

// 0x0035ca90 FUN_0035ca90 (25 B): matches/0x0035ca90.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035ca90@fn_0035ca90@@YAXXZ
namespace fn_0035ca90 {

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035ca90() {
    (*(__int64*)&DAT_004dced8) = FUN_0027b020("running");
}
} // namespace fn_0035ca90

namespace fn_f1ddef39 {

// 0x0035cab0 FUN_0035cab0 (25 B): matches/0x0035cab0.cpp
// sym: ?FUN_0035cab0@fn_f1ddef39@@YAXXZ
// data: g4dcec8_1 = DAT_004dcecc
void __cdecl FUN_0035cab0() {
    unsigned long long r = FUN_0027b020("throwing");
    (*(unsigned int*)&DAT_004dcec8) = (unsigned int)r;
    (*(unsigned int*)&DAT_004dcecc) = (unsigned int)(r >> 32);
}


// 0x0035cad0 FUN_0035cad0 (25 B): matches/0x0035cad0.cpp
// sym: ?FUN_0035cad0@fn_f1ddef39@@YAXXZ
// data: g1_35cad0 = DAT_004dcef0, g2_35cad0 = DAT_004dcef4
void FUN_0035cad0() {
    unsigned long long r = FUN_0027b020("airsmash");
    (*(unsigned int*)&DAT_004dcef0) = (unsigned int)r;
    (*(unsigned int*)&DAT_004dcef4) = (unsigned int)(r >> 32);
}


// 0x0035caf0 FUN_0035caf0 (25 B): matches/0x0035caf0.cpp
// sym: ?FUN_0035caf0@fn_f1ddef39@@YAXXZ
// data: g_hashHi = DAT_004dceec, g_hashLo = DAT_004dcee8
void FUN_0035caf0() {
    unsigned long long h = FUN_0027b020("climbing");
    (*(unsigned int*)&DAT_004dcee8) = (unsigned int)h;
    (*(unsigned int*)&DAT_004dceec) = (unsigned int)(h >> 32);
}


// 0x0035cb10 FUN_0035cb10 (22 B): matches/0x0035cb10.cpp
// sym: ?FUN_0035cb10@fn_f1ddef39@@YAXXZ
// data: gGlobal_35cb10 = DAT_004dcf00
void FUN_0035cb10() {
    (*(Global*)&DAT_004dcf00).FUN_0027af00();
    _atexit(FUN_00363c30);
}


// 0x0035cb30 FUN_0035cb30 (15 B): matches/0x0035cb30.cpp
// sym: ?FUN_0035cb30@fn_f1ddef39@@YAXXZ
// data: result = DAT_004dd048
void FUN_0035cb30() {
    DAT_004dd048 = (float)cos(0.5235987901687622);
}


// 0x0035cb40 FUN_0035cb40 (15 B): matches/0x0035cb40.cpp
// sym: ?FUN_0035cb40@fn_f1ddef39@@YAXXZ
// data: gValue = DAT_004de6f8
void FUN_0035cb40() {
    (*(float*)&DAT_004dd04c) = (float)sin(0.5235987901687622);
}

} // namespace fn_f1ddef39

// 0x0035cb50 FUN_0035cb50 (29 B): matches/0x0035cb50.cpp [wrapped: conflict: Reg]
// sym: ?Reg@fn_0035cb50@@YAXXZ
namespace fn_0035cb50 {
struct Obj {
};
extern Obj hulk_at_004dd080;

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
int atexit(void (*)(void));
#endif

extern "C++" __declspec(nothrow) void FUN_00363c50();

void Reg() {
    ((owners::String_23fc40 *)&hulk_at_004dd080)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363c50);
}
} // namespace fn_0035cb50

namespace fn_f1ddef39 {

// 0x0035cb70 FUN_0035cb70 (807 B): matches/0x0035cb70.cpp
// sym: ?FUN_0035cb70@fn_f1ddef39@@YAXXZ
// FUN_0035cb70 @ 0x0035cb70
void __cdecl FUN_0035cb70() {
    (*(Ent_35cb70*)&DAT_004dd090).id = FUN_0027b020("pma_amb_idle");
    (*(Ent_35cb70*)&DAT_004dd090).flag = true;
    (*(Ent_35cb70*)&DAT_004dd0a0).id = FUN_0027b020("sbs_rif_amb_patrol_3");
    (*(Ent_35cb70*)&DAT_004dd0a0).flag = true;
    (*(Ent_35cb70*)&DAT_004dd0b0).id = FUN_0027b020("pfa_amb_idle");
    (*(Ent_35cb70*)&DAT_004dd0b0).flag = true;
    (*(Ent_35cb70*)&DAT_004dd0c0).id = FUN_0027b020("pma_loco_walk_n");
    (*(Ent_35cb70*)&DAT_004dd0c0).flag = true;
    (*(Ent_35cb70*)&DAT_004dd0d0).id = FUN_0027b020("sbs_ped_loco_walk_n_b");
    (*(Ent_35cb70*)&DAT_004dd0d0).flag = true;
    (*(Ent_35cb70*)&DAT_004dd0e0).id = FUN_0027b020("pfa_loco_walk_n");
    (*(Ent_35cb70*)&DAT_004dd0e0).flag = true;
    (*(Ent_35cb70*)&DAT_004dd0f0).id = FUN_0027b020("pma_act_explosion");
    (*(Ent_35cb70*)&DAT_004dd0f0).flag = false;
    (*(Ent_35cb70*)&DAT_004dd100).id = FUN_0027b020("pma_loco_frantic_run_stop");
    (*(Ent_35cb70*)&DAT_004dd100).flag = false;
    (*(Ent_35cb70*)&DAT_004dd110).id = FUN_0027b020("pma_act_scared");
    (*(Ent_35cb70*)&DAT_004dd110).flag = true;
    (*(Ent_35cb70*)&DAT_004dd120).id = FUN_0027b020("sbs_act_surprised_scared");
    (*(Ent_35cb70*)&DAT_004dd120).flag = true;
    (*(Ent_35cb70*)&DAT_004dd130).id = FUN_0027b020("pfa_act_explosion");
    (*(Ent_35cb70*)&DAT_004dd130).flag = false;
    (*(Ent_35cb70*)&DAT_004dd140).id = FUN_0027b020("pma_loco_run_crazy_n");
    (*(Ent_35cb70*)&DAT_004dd140).flag = true;
    (*(Ent_35cb70*)&DAT_004dd150).id = FUN_0027b020("pma_loco_run_n");
    (*(Ent_35cb70*)&DAT_004dd150).flag = true;
    (*(Ent_35cb70*)&DAT_004dd160).id = FUN_0027b020("sbs_loco_run_n");
    (*(Ent_35cb70*)&DAT_004dd160).flag = true;
    (*(Ent_35cb70*)&DAT_004dd170).id = FUN_0027b020("sbs_act_panic_c");
    (*(Ent_35cb70*)&DAT_004dd170).flag = true;
    (*(Ent_35cb70*)&DAT_004dd180).id = FUN_0027b020("sbs_grap_hmn_amb_rcv");
    (*(Ent_35cb70*)&DAT_004dd180).flag = true;
    (*(Ent_35cb70*)&DAT_004dd190).id = FUN_0027b020("sbs_gethit_float_spin_e");
    (*(Ent_35cb70*)&DAT_004dd190).flag = false;
    (*(Ent_35cb70*)&DAT_004dd1a0).id = FUN_0027b020("sbs_gethit_float_flip_n");
    (*(Ent_35cb70*)&DAT_004dd1a0).flag = false;
    (*(Ent_35cb70*)&DAT_004dd1b0).id = FUN_0027b020("sbs_gethit_float_back_n");
    (*(Ent_35cb70*)&DAT_004dd1b0).flag = false;
    (*(Ent_35cb70*)&DAT_004dd1c0).id = FUN_0027b020("sbs_gethit_float_vert");
    (*(Ent_35cb70*)&DAT_004dd1c0).flag = false;
    (*(Ent_35cb70*)&DAT_004dd1d0).id = FUN_0027b020("sbs_gethit_float_fall_f_dwn");
    (*(Ent_35cb70*)&DAT_004dd1d0).flag = true;
    (*(Ent_35cb70*)&DAT_004dd1e0).id = FUN_0027b020("sbs_gethit_csm_wall_float_n");
    (*(Ent_35cb70*)&DAT_004dd1e0).flag = false;
    (*(Ent_35cb70*)&DAT_004dd1f0).id = FUN_0027b020("sbs_gethit_float_fall_grnd_hit_n");
    (*(Ent_35cb70*)&DAT_004dd1f0).flag = false;
    (*(Ent_35cb70*)&DAT_004dd200).id = FUN_0027b020("sbs_gethit_knckbck_grnd_roll");
    (*(Ent_35cb70*)&DAT_004dd200).flag = true;
    (*(Ent_35cb70*)&DAT_004dd210).id = FUN_0027b020("sbs_gethit_amb_grnd");
    (*(Ent_35cb70*)&DAT_004dd210).flag = true;
    (*(Ent_35cb70*)&DAT_004dd220).id = FUN_0027b020("sbs_gethit_getup_n");
    (*(Ent_35cb70*)&DAT_004dd220).flag = false;
    (*(Ent_35cb70*)&DAT_004dd230).id = FUN_0027b020("pma_loco_turn_180");
    (*(Ent_35cb70*)&DAT_004dd230).flag = false;
    (*(Ent_35cb70*)&DAT_004dd240).id = FUN_0027b020("pfa_loco_turn_180");
    (*(Ent_35cb70*)&DAT_004dd240).flag = false;
    (*(Ent_35cb70*)&DAT_004dd250).id = FUN_0027b020("sbs_gethit_knckbck_grnd_slide");
    (*(Ent_35cb70*)&DAT_004dd250).flag = false;
}

} // namespace fn_f1ddef39

// 0x0035cea0 FUN_0035cea0 (29 B): matches/0x0035cea0.cpp [wrapped: conflict: G]
// sym: ?FUN_0035cea0@fn_0035cea0@@YAXXZ
namespace fn_0035cea0 {
extern "C++" __declspec(nothrow) void __cdecl FUN_00363c60();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void (*f)());
#endif

extern "C" void __cdecl FUN_0023fc40(const char*, int);

struct G {
} g;

void __cdecl FUN_0035cea0() {
    ((owners::String_23fc40 *)&g)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit((void (*)())FUN_00363c60);
}
} // namespace fn_0035cea0

namespace fn_f1ddef39 {

// 0x0035cec0 FUN_0035cec0 (172 B): matches/0x0035cec0.cpp
// sym: ?FUN_0035cec0@fn_f1ddef39@@YAXXZ
// FUN_0035cec0 @ 0x0035cec0
// Static init: hash the cow animation names and record whether each loops.
void FUN_0035cec0() {
    (*(AnimKey*)&DAT_004dd270).key = FUN_0027b020("cow_amb_idle");
    (*(AnimKey*)&DAT_004dd270).loops = 1;
    (*(AnimKey*)&DAT_004dd280).key = FUN_0027b020("cow_loco_walk_n");
    (*(AnimKey*)&DAT_004dd280).loops = 1;
    (*(AnimKey*)&DAT_004dd290).key = FUN_0027b020("cow_loco_180_turn");
    (*(AnimKey*)&DAT_004dd290).loops = 0;
    (*(AnimKey*)&DAT_004dd2a0).key = FUN_0027b020("cow_loco_run_n");
    (*(AnimKey*)&DAT_004dd2a0).loops = 1;
    (*(AnimKey*)&DAT_004dd2b0).key = FUN_0027b020("cow_amb_flail");
    (*(AnimKey*)&DAT_004dd2b0).loops = 1;
    (*(AnimKey*)&DAT_004dd2c0).key = FUN_0027b020("cow_loco_getup");
    (*(AnimKey*)&DAT_004dd2c0).loops = 0;
}

} // namespace fn_f1ddef39

// 0x0035cf70 FUN_0035cf70 (29 B): matches/0x0035cf70.cpp [wrapped: conflict: _atexit]
// sym: ?FUN_0035cf70@fn_0035cf70@@YAXXZ
namespace fn_0035cf70 {
// data: g_thing = DAT_004dd2d0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void _atexit(void (*)(void));
#endif

class Thing {
  public:
};
extern "C++" __declspec(nothrow) void __cdecl FUN_00363c70(void);
void __cdecl FUN_0035cf70(void) {
    ((owners::String_23fc40 *)&((*(Thing*)&DAT_004dd2d0)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    _atexit(FUN_00363c70);
}
} // namespace fn_0035cf70


// 0x0035cf90 FUN_0035cf90 (29 B): matches/0x0035cf90.cpp [wrapped: conflict: Reg]
// sym: ?Reg@fn_0035cf90@@YAXXZ
namespace fn_0035cf90 {
extern "C++" __declspec(nothrow) void __cdecl FUN_00363c80();
class G {
  public:
};
G g_obj;
void __cdecl Reg() {
    ((owners::String_23fc40 *)&g_obj)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363c80);
}
} // namespace fn_0035cf90

namespace fn_f1ddef39 {

// 0x0035cfb0 FUN_0035cfb0 (29 B): matches/0x0035cfb0.cpp
// sym: ?FUN_0035cfb0@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035cfb0() {
    ((owners::String_23fc40 *)&gSound)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363c90);
}


// 0x0035cfd0 FUN_0035cfd0 (29 B): matches/0x0035cfd0.cpp
// sym: ?FUN_0035cfd0@fn_f1ddef39@@YGXXZ
void __stdcall FUN_0035cfd0(void) {
    ((owners::String_23fc40 *)&((*(Obj*)&DAT_004dd738)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit((void (*)(void))FUN_00363ca0);
}


// 0x0035cff0 FUN_0035cff0 (25 B): matches/0x0035cff0.cpp
// sym: ?FUN_0035cff0@fn_f1ddef39@@YAXXZ
// data: gResultHi = DAT_004dd75c, gResultLo = DAT_004dd758
void __cdecl FUN_0035cff0() {
    extern const char hulk_at_00400488[];
    __int64 r = FUN_0027b020(hulk_at_00400488);
    (*(int*)&DAT_004dd758) = (int)r;
    (*(int*)&DAT_004dd75c) = (int)((unsigned __int64)r >> 32);
}


// 0x0035d010 FUN_0035d010 (25 B): matches/0x0035d010.cpp
// sym: ?FUN_0035d010@fn_f1ddef39@@YAXXZ
// data: gHash_35d010 = DAT_004dd760, gName = DAT_0040048c
void FUN_0035d010() {
    (*(unsigned __int64*)&DAT_004dd760) = FUN_0027b020(((unsigned int*)&DAT_0040048c));
}


// 0x0035d030 FUN_0035d030 (25 B): matches/0x0035d030.cpp
// sym: ?FUN_0035d030@fn_f1ddef39@@YAXXZ
void FUN_0035d030() {
    unsigned __int64 p = FUN_0027b020("$MACRO_DEFINE");
    *(unsigned int*)&hulk_at_004dd750 = (unsigned int)p;
    *(unsigned int*)&hulk_at_004dd754 = (unsigned int)(p >> 32);
}


// 0x0035d050 FUN_0035d050 (25 B): matches/0x0035d050.cpp
// sym: ?FUN_0035d050@fn_f1ddef39@@YAXXZ
// data: gFirst_35d050 = DAT_004dd748, gSecond_35d050 = DAT_004dd74c
void __cdecl FUN_0035d050() {
    unsigned long long v = FUN_0027b020("$MACRO_INSERT");
    *(unsigned int*)((char*)&DAT_004dd748) = (unsigned int)v;
    *(unsigned int*)((char*)&DAT_004dd74c) = (unsigned int)(v >> 32);
}

} // namespace fn_f1ddef39

// 0x0035d070 FUN_0035d070 (29 B): matches/0x0035d070.cpp [wrapped: conflict: Sound]
// sym: ?initSound@fn_0035d070@@YAXXZ
namespace fn_0035d070 {
// data: gSound = DAT_004dd768

class Sound {
  public:
    Sound(const char*, int);
    ~Sound();
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00363cb0();
void initSound() {
    ((owners::String_23fc40 *)&DAT_004dd768)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363cb0);
}
} // namespace fn_0035d070

namespace fn_f1ddef39 {

// 0x0035d090 FUN_0035d090 (109 B): equivalent/0x0035d090.cpp
// sym: ?FUN_0035d090@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0035d090 @ 0x0035d090
void FUN_0035d090()
{
    DAT_004dd780.heaps[0] = 0;
    DAT_004dd780.heaps[1] = 0;
    DAT_004dd780.heaps[2] = 0;
    DAT_004dd780.heaps[3] = 0;
    DAT_004dd780.heaps[4] = 0;
    DAT_004dd780.heaps[5] = 0;
    DAT_004dd780.heaps[6] = 0;
    DAT_004dd780.heaps[7] = 0;
    DAT_004dd780.heaps[8] = 0;
    DAT_004dd780.heaps[9] = 0;
    DAT_004dd780.heaps[10] = 0;
    DAT_004dd780.heaps[11] = 0;
    DAT_004dd780.heaps[12] = 0;
    DAT_004dd780.heaps[13] = 0;
    DAT_004dd780.heaps[14] = 0;
    DAT_004dd780.heaps[15] = 0;
    DAT_004dd780.heaps[16] = 0;
    DAT_004dd780.heaps[17] = 0;
    DAT_004dd780.heaps[18] = 0;
    atexit(FUN_00363cc0);
}

} // namespace fn_f1ddef39

// 0x0035d100 FUN_0035d100 (25 B): matches/0x0035d100.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d100@fn_0035d100@@YAXXZ
namespace fn_0035d100 {
// data: gResult = DAT_004dd828

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035d100() {
    (*(__int64*)&DAT_004dd828) = FUN_0027b020("golfBall_golfBall");
}
} // namespace fn_0035d100

namespace fn_f1ddef39 {

// 0x0035d120 FUN_0035d120 (29 B): matches/0x0035d120.cpp
// sym: ?InitSound@fn_f1ddef39@@YAXXZ
void InitSound() {
    ((owners::String_23fc40 *)&((*(Reg*)&DAT_004dd818)))->FUN_0023fc40((const char *)(((char*)&DAT_003f3ea0)), (hulk_intptr)0);
    atexit(FUN_00363cd0);
}


// 0x0035d140 FUN_0035d140 (10 B): matches/0x0035d140.cpp
// sym: ?FUN_0035d140@fn_f1ddef39@@YIXXZ
void __fastcall FUN_0035d140() {
    (*(Obj_35d140*)&DAT_004dd7e4).FUN_002923b0();
}


// 0x0035d150 FUN_0035d150 (12 B): matches/0x0035d150.cpp
// sym: _FUN_0035d150
extern "C" void __cdecl FUN_0035d150() {
    atexit(FUN_00363ce0);
}


// 0x0035d160 FUN_0035d160 (25 B): matches/0x0035d160.cpp
// sym: ?FUN_0035d160@fn_f1ddef39@@YAXXZ
// data: hulk_at_00400488 = DAT_00400488
void __cdecl FUN_0035d160() {
    uint64 r = FUN_0027b020((const char*)((hulk_intptr)((char*)&DAT_00400488)));
    (*(uint32*)&DAT_004dd8f8) = (uint32)r;
    (*(uint32*)&DAT_004dd8fc) = (uint32)(r >> 32);
}


// 0x0035d180 FUN_0035d180 (25 B): matches/0x0035d180.cpp
// sym: ?FUN_0035d180@fn_f1ddef39@@YAXXZ
// data: hulk_at_0040048c = DAT_0040048c
void __cdecl FUN_0035d180() {
    Pair_35d180 p = FUN_0027b020((void*)((hulk_intptr)((char*)&DAT_0040048c)));
    (*(unsigned int*)&DAT_004dd900) = p.lo;
    (*(unsigned int*)&DAT_004dd904) = p.hi;
}


// 0x0035d1a0 FUN_0035d1a0 (25 B): matches/0x0035d1a0.cpp
// sym: ?FUN_0035d1a0@fn_f1ddef39@@YAXXZ
void FUN_0035d1a0() {
    unsigned __int64 v = FUN_0027b020(((char*)&DAT_00400490));
    (*(unsigned int*)&DAT_004dd908) = (unsigned int)v;
    (*(unsigned int*)&DAT_004dd90c) = (unsigned int)(v >> 32);
}


// 0x0035d1c0 FUN_0035d1c0 (25 B): matches/0x0035d1c0.cpp
// sym: ?FUN_0035d1c0@fn_f1ddef39@@YAXXZ
void FUN_0035d1c0() {
    long long r = FUN_0027b020("$MACRO_INSERT");
    *(int*)&r = *(int*)&r;
    (*(int*)&DAT_004dd8f0) = *(int*)&r;
    (*(int*)&DAT_004dd8f4) = *(int*)((char*)&r + 4);
}


// 0x0035d1e0 FUN_0035d1e0 (25 B): matches/0x0035d1e0.cpp
// sym: ?FUN_0035d1e0@fn_f1ddef39@@YAXXZ
// data: gHash2 = DAT_004dd93c, gHash_35d1e0 = DAT_004dd938
void FUN_0035d1e0() {
    unsigned long long h = FUN_0027b020("golfBall_golfBall");
    (*(unsigned int*)&DAT_004dd938) = (unsigned int)h;
    (*(unsigned int*)&DAT_004dd93c) = (unsigned int)(h >> 32);
}


// 0x0035d200 FUN_0035d200 (21 B): matches/0x0035d200.cpp
// sym: _FUN_0035d200
// data: hulk_at_004dd940 = DAT_004dd940
extern "C" void __cdecl FUN_0035d200() {
    double r = cos(0.017453293005625408);
    *(volatile float*)((hulk_intptr)((char*)&DAT_004dd940)) = 1.0f - (hulk_freg)r;
}


// 0x0035d220 FUN_0035d220 (29 B): matches/0x0035d220.cpp
// sym: ?f@fn_f1ddef39@@YAXXZ
void f() {
    ((owners::String_23fc40 *)&DAT_004dd9d0)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363cf0);
}


// 0x0035d240 FUN_0035d240 (25 B): matches/0x0035d240.cpp
// sym: ?FUN_0035d240@fn_f1ddef39@@YAXXZ
// data: g_golfBall_golfBall = DAT_004dd9e8
void FUN_0035d240() {
    (*(U64_35d240*)&DAT_004dd9e8) = FUN_0027b020("golfBall_golfBall");
}


// 0x0035d260 FUN_0035d260 (25 B): matches/0x0035d260.cpp
// sym: ?FUN_0035d260@fn_f1ddef39@@YAXXZ
void FUN_0035d260() {
    unsigned long long r = FUN_0027b020("golfBall_golfBall");
    (*(int*)&DAT_004dda00) = (int)r;
    (*(int*)&DAT_004dda04) = (int)(r >> 32);
}

} // namespace fn_f1ddef39

// 0x0035d280 FUN_0035d280 (29 B): matches/0x0035d280.cpp [wrapped: conflict: g]
// sym: ?Init@fn_0035d280@@YAXXZ
namespace fn_0035d280 {
extern "C++" __declspec(nothrow) void __cdecl FUN_00363d00();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int atexit(void (*)(void));
#endif

struct G {
    void Init(const char*, int);
};
extern G hulk_at_004dda08;
void Init() {
    ((owners::String_23fc40 *)&hulk_at_004dda08)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363d00);
}
} // namespace fn_0035d280


// 0x0035d2a0 FUN_0035d2a0 (39 B): matches/0x0035d2a0.cpp [wrapped: conflict: Pair; g]
// sym: ?init@fn_0035d2a0@@YAXXZ
namespace fn_0035d2a0 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00363d10();
struct Pair {
    int a, b;
};
volatile Pair g[11];
void init() {
    volatile Pair* p = g;
    int n = 11;
    int z = 0;
    do {
        p->a = z;
        p->b = z;
        ++p;
    } while (--n);
    atexit(FUN_00363d10);
}
} // namespace fn_0035d2a0

namespace fn_f1ddef39 {

// 0x0035d2d0 FUN_0035d2d0 (53 B): matches/0x0035d2d0.cpp
// sym: ?FUN_0035d2d0@fn_f1ddef39@@YAXXZ
// data: items = DAT_004ddb68 (two rows of six 8-byte objects built by 0x000b06e0)
void __cdecl FUN_0035d2d0() {
    Obj_b06e0* p = (Obj_b06e0*)DAT_004ddb68;
    int n = 2;
    do {
        FUN_00011520(p, 8, 6, FUN_000b06e0);
        p += 6;
    } while (--n);
    atexit(FUN_00363dc0);
}

} // namespace fn_f1ddef39

// 0x0035d310 FUN_0035d310 (39 B): matches/0x0035d310.cpp [wrapped: conflict: Pair]
// sym: ?init@fn_0035d310@@YAXXZ
namespace fn_0035d310 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C" void __cdecl FUN_00363d50();
struct Pair {
    int a, b;
};
Pair values[13];
void init() {
    Pair* p = values;
    int n = 13;
    do {
        p->a = 0;
        p->b = 0;
        ++p;
    } while (--n);
    atexit(FUN_00363d50);
}
} // namespace fn_0035d310

namespace fn_f1ddef39 {

// 0x0035d340 FUN_0035d340 (53 B): matches/0x0035d340.cpp
// sym: ?FUN_0035d340@fn_f1ddef39@@YAXXZ
// data: items = DAT_004ddab0 (two rows of six 8-byte objects built by 0x000b06e0); cleanup = 0x00363d90 (an atexit handler: its invented name stays, see docs/native-build.md "Start-up stops 67 to 216")
void FUN_0035d340() {
    Obj_b06e0* p = (Obj_b06e0*)DAT_004ddab0;
    int n = 2;
    do {
        FUN_00011520(p, 8, 6, FUN_000b06e0);
        p += 6;
    } while (--n);
    atexit(cleanup);
}


// 0x0035d380 FUN_0035d380 (25 B): matches/0x0035d380.cpp
// sym: ?FUN_0035d380@fn_f1ddef39@@YAXXZ
// data: result = DAT_004ddbf8, text = DAT_00400488
void FUN_0035d380() {
    (*(__int64*)&DAT_004ddbf8) = FUN_0027b020(DAT_00400488);
}


// 0x0035d3a0 FUN_0035d3a0 (25 B): matches/0x0035d3a0.cpp
// sym: ?FUN_0035d3a0@fn_f1ddef39@@YAXXZ
// data: g_hash_35d3a0 = DAT_004ddc00, g_size_35d3a0 = DAT_004ddc04, hulk_at_0040048c = DAT_0040048c
void __cdecl FUN_0035d3a0() {
    unsigned __int64 h = FUN_0027b020((const char*)((char*)&DAT_0040048c));
    (*(unsigned int*)&DAT_004ddc00) = (unsigned int)h;
    (*(unsigned int*)&DAT_004ddc04) = (unsigned int)(h >> 32);
}


// 0x0035d3c0 FUN_0035d3c0 (25 B): matches/0x0035d3c0.cpp
// sym: ?FUN_0035d3c0@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035d3c0() {
    U64_35d3c0 r = FUN_0027b020("$MACRO_DEFINE");
    (*(int*)&DAT_004ddc10) = (int)r;
    (*(int*)&DAT_004ddc14) = (int)(r >> 32);
}

} // namespace fn_f1ddef39

// 0x0035d3e0 FUN_0035d3e0 (25 B): matches/0x0035d3e0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d3e0@fn_0035d3e0@@YAXXZ
namespace fn_0035d3e0 {
// data: gResult = DAT_004ddbf0

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035d3e0() {
    (*(__int64*)&DAT_004ddbf0) = FUN_0027b020("$MACRO_INSERT");
}
} // namespace fn_0035d3e0

namespace fn_f1ddef39 {

// 0x0035d400 FUN_0035d400 (29 B): matches/0x0035d400.cpp
// sym: ?FUN_0035d400@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035d400() {
    ((owners::String_23fc40 *)&((*(Reg*)&DAT_004ddbe4)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    _atexit(FUN_00363df0);
}

} // namespace fn_f1ddef39

// 0x0035d420 FUN_0035d420 (25 B): matches/0x0035d420.cpp [wrapped: compile error C2440: 'initializing' : cannot convert from 'fn_f1ddef39::Pair' to 'unsigned __int64']
// sym: ?FUN_0035d420@fn_0035d420@@YAXXZ
namespace fn_0035d420 {
// data: hulk_at_00400488 = DAT_00400488

extern "C++" __declspec(nothrow) unsigned __int64 FUN_0027b020(hulk_uintptr);
void FUN_0035d420() {
    unsigned __int64 v = FUN_0027b020(((hulk_intptr)((char*)&DAT_00400488)));
    (*(unsigned int*)&DAT_004dde50) = (unsigned int)v;
    (*(unsigned int*)&DAT_004dde54) = (unsigned int)(v >> 32);
}
} // namespace fn_0035d420

namespace fn_f1ddef39 {

// 0x0035d440 FUN_0035d440 (25 B): matches/0x0035d440.cpp
// sym: ?FUN_0035d440@fn_f1ddef39@@YAXXZ
// data: hulk_at_0040048c = DAT_0040048c
void FUN_0035d440() {
    (*(unsigned long long*)&DAT_004dde58) = FUN_0027b020(((const char*)((char*)&DAT_0040048c)));
}

} // namespace fn_f1ddef39

// 0x0035d460 FUN_0035d460 (25 B): matches/0x0035d460.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d460@fn_0035d460@@YAXXZ
namespace fn_0035d460 {
// data: gResult = DAT_004dde60

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035d460() {
    (*(__int64*)&DAT_004dde60) = FUN_0027b020("$MACRO_DEFINE");
}
} // namespace fn_0035d460

namespace fn_f1ddef39 {

// 0x0035d480 FUN_0035d480 (25 B): matches/0x0035d480.cpp
// sym: ?FUN_0035d480@fn_f1ddef39@@YAXXZ
// data: gValue_35d480 = DAT_004dde48
void FUN_0035d480() {
    (*(unsigned __int64*)&DAT_004dde48) = FUN_0027b020("$MACRO_INSERT");
}


// 0x0035d4a0 FUN_0035d4a0 (29 B): matches/0x0035d4a0.cpp
// sym: ?FUN_0035d4a0@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035d4a0() {
    ((owners::String_23fc40 *)&gSound)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(Shutdown_00363e00);
}


// 0x0035d4c0 FUN_0035d4c0 (29 B): matches/0x0035d4c0.cpp
// sym: ?FUN_0035d4c0@fn_f1ddef39@@YAXXZ
// data: hulk_at_004dde6c = DAT_004dde6c
void FUN_0035d4c0() {
    ((owners::String_23fc40 *)(((Obj*)((hulk_intptr)((char*)&DAT_004dde6c)))))->FUN_0023fc40(((char*)&DAT_003f3ea0), (hulk_intptr)0);
    atexit((void (*)(void))((hulk_intptr)((hulk_intptr)(void (__cdecl*)())&FUN_00363e10)));
}


// 0x0035d4e0 FUN_0035d4e0 (25 B): matches/0x0035d4e0.cpp
// sym: ?FUN_0035d4e0@fn_f1ddef39@@YAXXZ
// data: hashA = DAT_004ddee0, hashB = DAT_004ddee4, hulk_at_00400488 = DAT_00400488
void FUN_0035d4e0() {
    unsigned long long result = FUN_0027b020((const void*)((hulk_intptr)((char*)&DAT_00400488)));
    (*(unsigned int*)&DAT_004ddee0) = (unsigned int)result;
    (*(unsigned int*)&DAT_004ddee4) = (unsigned int)(result >> 32);
}


// 0x0035d500 FUN_0035d500 (25 B): matches/0x0035d500.cpp
// sym: ?FUN_0035d500@fn_f1ddef39@@YAXXZ
// data: hulk_at_0040048c = DAT_0040048c
void FUN_0035d500() {
    g = FUN_0027b020(((hulk_intptr)((char*)&DAT_0040048c)));
}


// 0x0035d520 FUN_0035d520 (25 B): matches/0x0035d520.cpp
// sym: _FUN_0035d520
// data: g_hash0 = DAT_004ddf28, g_hash1 = DAT_004ddf2c
extern "C" void __cdecl FUN_0035d520() throw() {
    unsigned long long r = FUN_0027b020("$MACRO_DEFINE");
    (*(unsigned int*)&DAT_004ddf28) = (unsigned int)r;
    (*(unsigned int*)&DAT_004ddf2c) = (unsigned int)(r >> 32);
}


// 0x0035d540 FUN_0035d540 (25 B): matches/0x0035d540.cpp
// sym: ?FUN_0035d540@fn_f1ddef39@@YAXPBD@Z
void __cdecl FUN_0035d540(const char* s) {
    (void)s;
    unsigned long long v = FUN_0027b020("$MACRO_INSERT");
    g_hash_lo = (unsigned int)v;
    g_hash_hi = (unsigned int)(v >> 32);
}


// 0x0035d560 FUN_0035d560 (25 B): matches/0x0035d560.cpp
// sym: ?init@fn_f1ddef39@@YAXXZ
void init() {
    (*(unsigned __int64*)&DAT_004dde90) = FUN_0027b020("golfBall_golfBall");
}


// 0x0035d580 FUN_0035d580 (19 B): matches/0x0035d580.cpp
// sym: ?FUN_0035d580@fn_f1ddef39@@YAXXZ
void FUN_0035d580() {
    (*(float*)&DAT_004ddef0) = (*(const float*)&DAT_0049fca8) * 0.5f;
}

} // namespace fn_f1ddef39

// 0x0035d5a0 FUN_0035d5a0 (25 B): matches/0x0035d5a0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d5a0@fn_0035d5a0@@YAXXZ
namespace fn_0035d5a0 {
// data: result = DAT_004ddf40

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035d5a0() {
    (*(__int64*)&DAT_004ddf40) = FUN_0027b020("{");
}
} // namespace fn_0035d5a0

namespace fn_f1ddef39 {

// 0x0035d5c0 FUN_0035d5c0 (25 B): matches/0x0035d5c0.cpp
// sym: ?FUN_0035d5c0@fn_f1ddef39@@YAXXZ
// data: gFirst_35d5c0 = DAT_004ddf48, gSecond_35d5c0 = DAT_004ddf4c, hulk_at_0040048c = DAT_0040048c
void FUN_0035d5c0() {
    Pair_35d5c0 p = FUN_0027b020((int*)((hulk_intptr)((char*)&DAT_0040048c)));
    (*(int*)&DAT_004ddf48) = p.a;
    (*(int*)&DAT_004ddf4c) = p.b;
}

} // namespace fn_f1ddef39

// 0x0035d5e0 FUN_0035d5e0 (25 B): matches/0x0035d5e0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d5e0@fn_0035d5e0@@YAXXZ
namespace fn_0035d5e0 {
// data: result = DAT_004ddf60

extern __int64 FUN_0027b020(const char*);
void FUN_0035d5e0() {
    (*(__int64*)&DAT_004ddf60) = FUN_0027b020("$MACRO_DEFINE");
}
} // namespace fn_0035d5e0


// 0x0035d600 FUN_0035d600 (25 B): matches/0x0035d600.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d600@fn_0035d600@@YAXXZ
namespace fn_0035d600 {

struct Pair_35d600 {
    int a;
    int b;
};
extern "C++" __declspec(nothrow) Pair_35d600 __cdecl FUN_0027b020(const char*);
void FUN_0035d600() {
    Pair_35d600 r = FUN_0027b020(((char*)&DAT_004004a0));
    *(int*)((char*)&DAT_004ddf38) = r.a;
    *(int*)((char*)&DAT_004ddf3c) = r.b;
}
} // namespace fn_0035d600


// 0x0035d620 FUN_0035d620 (25 B): matches/0x0035d620.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d620@fn_0035d620@@YAXXZ
namespace fn_0035d620 {

struct Pair_35d620 {
    int a;
    int b;
};
extern Pair_35d620 __cdecl FUN_0027b020(const char*);
void __cdecl FUN_0035d620() {
    Pair_35d620 p = FUN_0027b020("AddBackground");
    (*(int*)&DAT_004ddf30) = p.a;
    (*(int*)((char*)&DAT_004ddf30 + 4)) = p.b;
}
} // namespace fn_0035d620

namespace fn_f1ddef39 {

// 0x0035d640 FUN_0035d640 (25 B): matches/0x0035d640.cpp
// sym: ?FUN_0035d640@fn_f1ddef39@@YAXXZ
// data: gMemCardControl = DAT_004ddf54, gMemCardName = DAT_004ddf50
void FUN_0035d640() {
    unsigned long long h = FUN_0027b020("AddMemCardControl");
    (*(unsigned int*)&DAT_004ddf50) = (unsigned int)h;
    (*(unsigned int*)((char*)&DAT_004ddf50 + 4)) = (unsigned int)(h >> 32);
}

} // namespace fn_f1ddef39

// 0x0035d660 FUN_0035d660 (25 B): matches/0x0035d660.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d660@fn_0035d660@@YAXXZ
namespace fn_0035d660 {
// data: result = DAT_004ddf58

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035d660() {
    (*(Pair*)&DAT_004ddf58) = FUN_0027b020("AddTextInput");
}
} // namespace fn_0035d660


// 0x0035d680 FUN_0035d680 (25 B): matches/0x0035d680.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d680@fn_0035d680@@YAXXZ
namespace fn_0035d680 {
// data: hulk_at_00400488 = DAT_00400488, result = DAT_004ddf80

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(hulk_intptr);
void FUN_0035d680() {
    (*(__int64*)&DAT_004ddf80) = FUN_0027b020(((hulk_intptr)((char*)&DAT_00400488)));
}
} // namespace fn_0035d680


// 0x0035d6a0 FUN_0035d6a0 (25 B): matches/0x0035d6a0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d6a0@fn_0035d6a0@@YAXXZ
namespace fn_0035d6a0 {
// data: gResult = DAT_004ddf88, gValue = DAT_0040048c

extern __int64 __cdecl FUN_0027b020(int*);
void FUN_0035d6a0() {
    (*(__int64*)&DAT_004ddf88) = FUN_0027b020(((int*)&DAT_0040048c));
}
} // namespace fn_0035d6a0

namespace fn_f1ddef39 {

// 0x0035d6c0 FUN_0035d6c0 (25 B): matches/0x0035d6c0.cpp
// sym: _FUN_0035d6c0
// data: macroValue = DAT_004ddf90
extern "C" void __cdecl FUN_0035d6c0() {
    (*(__int64*)&DAT_004ddf90) = FUN_0027b020("$MACRO_DEFINE");
}

} // namespace fn_f1ddef39

// 0x0035d6e0 FUN_0035d6e0 (25 B): matches/0x0035d6e0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d6e0@fn_0035d6e0@@YAXXZ
namespace fn_0035d6e0 {
// data: gPair = DAT_004ddf78

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035d6e0() {
    (*(Pair*)&DAT_004ddf78) = FUN_0027b020("$MACRO_INSERT");
}
} // namespace fn_0035d6e0


// 0x0035d700 FUN_0035d700 (29 B): matches/0x0035d700.cpp [wrapped: conflict: _atexit]
// sym: ?FUN_0035d700@fn_0035d700@@YAXXZ
namespace fn_0035d700 {
// data: hulk_at_004ddf68 = DAT_004ddf68

extern "C++" __declspec(nothrow) void __cdecl FUN_00363e20();
// cl-flags: /O1

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void _atexit(void (*)(void));
#endif

struct Mgr {
};
void __cdecl FUN_0035d700() {
    ((owners::String_23fc40 *)(((Mgr*)((hulk_intptr)((char*)&DAT_004ddf68)))))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    _atexit(FUN_00363e20);
}
} // namespace fn_0035d700

namespace fn_f1ddef39 {

// 0x0035d720 FUN_0035d720 (25 B): matches/0x0035d720.cpp
// sym: ?FUN_0035d720@fn_f1ddef39@@YAXXZ
// data: the hash of "{" = DAT_004ddfb0 (low word) / DAT_004ddfb4 (high word)
void FUN_0035d720() {
    unsigned __int64 r = FUN_0027b020("{");
    (*(unsigned int*)&DAT_004ddfb0) = (unsigned int)r;
    (*(unsigned int*)&DAT_004ddfb4) = (unsigned int)(r >> 32);
}

} // namespace fn_f1ddef39

// 0x0035d740 FUN_0035d740 (25 B): matches/0x0035d740.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d740@fn_0035d740@@YAXXZ
namespace fn_0035d740 {
// data: gValue = DAT_004ddfb8, hulk_at_0040048c = DAT_0040048c

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(hulk_intptr);
void __cdecl FUN_0035d740() {
    (*(__int64*)&DAT_004ddfb8) = FUN_0027b020(((hulk_intptr)((char*)&DAT_0040048c)));
}
} // namespace fn_0035d740

namespace fn_f1ddef39 {

// 0x0035d760 FUN_0035d760 (25 B): matches/0x0035d760.cpp
// sym: ?FUN_0035d760@fn_f1ddef39@@YAXXZ
// data: gFirst_35d760 = DAT_004ddff8, gSecond_35d760 = DAT_004ddffc
void __cdecl FUN_0035d760() {
    unsigned long long r = FUN_0027b020("$MACRO_DEFINE");
    (*(unsigned int*)&DAT_004ddff8) = (unsigned int)r;
    (*(unsigned int*)&DAT_004ddffc) = (unsigned int)(r >> 32);
}


// 0x0035d780 FUN_0035d780 (25 B): matches/0x0035d780.cpp
// sym: ?FUN_0035d780@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035d780() {
    (*(uint64*)&DAT_004ddfa8) = FUN_0027b020("$MACRO_INSERT");
}

} // namespace fn_f1ddef39

// 0x0035d7a0 FUN_0035d7a0 (29 B): matches/0x0035d7a0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_0035d7a0@fn_0035d7a0@@YAXXZ
namespace fn_0035d7a0 {
// data: hulk_at_004ddf9c = DAT_004ddf9c


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int atexit(void (*)());
#endif

struct Module {
};
void FUN_00363e30() {}
void FUN_0035d7a0() {
    Module* m = (Module*)((hulk_intptr)((char*)&DAT_004ddf9c));
    ((void *)((owners::String_23fc40 *)m)->FUN_0023fc40("sound/rsd", (hulk_intptr)0));
    atexit(FUN_00363e30);
}
} // namespace fn_0035d7a0

namespace fn_f1ddef39 {

// 0x0035d7c0 FUN_0035d7c0 (11 B): matches/0x0035d7c0.cpp
// sym: ?FUN_0035d7c0@fn_f1ddef39@@YAXXZ
// data: gConstant_35d7c0 = DAT_004ddff0
void FUN_0035d7c0() {
    (*(float*)&DAT_004ddff0) = 3.5f;
}

} // namespace fn_f1ddef39

// 0x0035d7d0 FUN_0035d7d0 (29 B): matches/0x0035d7d0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?Init@fn_0035d7d0@@YAXXZ
namespace fn_0035d7d0 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl _atexit(void (*)());
#endif

struct Sound {
};
Sound gSound;
void FUN_00363e40() {}
void Init() {
    ((owners::String_23fc40 *)&gSound)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    _atexit(FUN_00363e40);
}
} // namespace fn_0035d7d0

namespace fn_f1ddef39 {

// 0x0035d7f0 FUN_0035d7f0 (25 B): matches/0x0035d7f0.cpp
// sym: ?FUN_0035d7f0@fn_f1ddef39@@YAXXZ
// data: result = DAT_004de620
void FUN_0035d7f0() {
    (*(__int64*)&DAT_004de620) = FUN_0027b020(((const int*)&DAT_00400488));
}


// 0x0035d810 FUN_0035d810 (25 B): matches/0x0035d810.cpp
// sym: ?FUN_0035d810@fn_f1ddef39@@YAXXZ
// data: gPair = DAT_004de628, hulk_at_0040048c = DAT_0040048c
void FUN_0035d810() {
    (*(Pair*)&DAT_004de628) = FUN_0027b020(((hulk_intptr)((char*)&DAT_0040048c)));
}

} // namespace fn_f1ddef39

// 0x0035d830 FUN_0035d830 (25 B): matches/0x0035d830.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d830@fn_0035d830@@YAXXZ
namespace fn_0035d830 {

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035d830() {
    (*(__int64*)&DAT_004de630) = FUN_0027b020("$MACRO_DEFINE");
}
} // namespace fn_0035d830

namespace fn_f1ddef39 {

// 0x0035d850 FUN_0035d850 (25 B): matches/0x0035d850.cpp
// sym: ?FUN_0035d850@fn_f1ddef39@@YAXXZ
// data: g_result_35d850 = DAT_004de618
void FUN_0035d850() {
    (*(int64_35d850*)&DAT_004de618) = FUN_0027b020("$MACRO_INSERT");
}

} // namespace fn_f1ddef39

// 0x0035d870 FUN_0035d870 (25 B): matches/0x0035d870.cpp [wrapped: compile error C2440: '=' : cannot convert from 'fn_f1ddef39::Pair' to 'unsigned __int64']
// sym: ?FUN_0035d870@fn_0035d870@@YAXXZ
namespace fn_0035d870 {
// data: hulk_at_00400488 = DAT_00400488

extern "C++" __declspec(nothrow) unsigned __int64 __cdecl FUN_0027b020(hulk_uintptr);
void FUN_0035d870() {
    (*(unsigned __int64*)&DAT_004de6b0) = FUN_0027b020(((hulk_intptr)((char*)&DAT_00400488)));
}
} // namespace fn_0035d870

namespace fn_f1ddef39 {

// 0x0035d890 FUN_0035d890 (25 B): matches/0x0035d890.cpp
// sym: ?FUN_0035d890@fn_f1ddef39@@YAXXZ
// data: result = DAT_004de6b8
void FUN_0035d890() {
    (*(__int64*)&DAT_004de6b8) = FUN_0027b020(((const char*)&DAT_0040048c));
}


// 0x0035d8b0 FUN_0035d8b0 (25 B): matches/0x0035d8b0.cpp
// sym: ?FUN_0035d8b0@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035d8b0() {
    unsigned long long r = FUN_0027b020("$MACRO_DEFINE");
    (*(unsigned int*)&DAT_004de6d0) = (unsigned int)r;
    (*(unsigned int*)&DAT_004de6d4) = (unsigned int)(r >> 32);
}


// 0x0035d8d0 FUN_0035d8d0 (25 B): matches/0x0035d8d0.cpp
// sym: ?FUN_0035d8d0@fn_f1ddef39@@YAXXZ
// data: gLower = DAT_004de6a8, gUpper = DAT_004de6ac
void FUN_0035d8d0() {
    unsigned long long v = FUN_0027b020("$MACRO_INSERT");
    (*(unsigned int*)&DAT_004de6a8) = (unsigned int)v;
    (*(unsigned int*)&DAT_004de6ac) = (unsigned int)(v >> 32);
}

} // namespace fn_f1ddef39

// 0x0035d8f0 FUN_0035d8f0 (25 B): matches/0x0035d8f0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d8f0@fn_0035d8f0@@YAXXZ
namespace fn_0035d8f0 {

struct Pair_35d8f0 {
    int lo;
    int hi;
};

extern Pair_35d8f0 __cdecl FUN_0027b020(const char*);


void __cdecl FUN_0035d8f0() {
    Pair_35d8f0 p = FUN_0027b020("Header");
    (*(int*)&DAT_004de670) = p.lo;
    (*(int*)((char*)&DAT_004de670 + 4)) = p.hi;
}
} // namespace fn_0035d8f0


// 0x0035d910 FUN_0035d910 (25 B): matches/0x0035d910.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d910@fn_0035d910@@YAXXZ
namespace fn_0035d910 {
// data: gPair = DAT_004de6c0

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035d910() {
    (*(Pair*)&DAT_004de6c0) = FUN_0027b020("Mode");
}
} // namespace fn_0035d910

namespace fn_f1ddef39 {

// 0x0035d930 FUN_0035d930 (25 B): matches/0x0035d930.cpp
// sym: ?FUN_0035d930@fn_f1ddef39@@YAXXZ
// data: globalValue = DAT_004de688
void FUN_0035d930() {
    (*(__int64*)&DAT_004de688) = FUN_0027b020("load");
}

} // namespace fn_f1ddef39

// 0x0035d950 FUN_0035d950 (25 B): matches/0x0035d950.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d950@fn_0035d950@@YAXXZ
namespace fn_0035d950 {
// data: gResult = DAT_004de690

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035d950() {
    (*(__int64*)&DAT_004de690) = FUN_0027b020("bootChecks");
}
} // namespace fn_0035d950

namespace fn_f1ddef39 {

// 0x0035d970 FUN_0035d970 (25 B): matches/0x0035d970.cpp
// sym: ?FUN_0035d970@fn_f1ddef39@@YAXXZ
// data: g_row = DAT_004de678
void FUN_0035d970() {
    (*(unsigned __int64*)&DAT_004de678) = FUN_0027b020("RowBackgrounds");
}

} // namespace fn_f1ddef39

// 0x0035d990 FUN_0035d990 (25 B): matches/0x0035d990.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d990@fn_0035d990@@YAXXZ
namespace fn_0035d990 {
// data: gPair = DAT_004de6c8

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035d990() {
    (*(Pair*)&DAT_004de6c8) = FUN_0027b020("MemcardSelectLocators");
}
} // namespace fn_0035d990


// 0x0035d9b0 FUN_0035d9b0 (25 B): matches/0x0035d9b0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d9b0@fn_0035d9b0@@YAXXZ
namespace fn_0035d9b0 {
// data: gResult = DAT_004de6a0

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035d9b0() {
    (*(__int64*)&DAT_004de6a0) = FUN_0027b020("MemcardInfoLocators");
}
} // namespace fn_0035d9b0


// 0x0035d9d0 FUN_0035d9d0 (25 B): matches/0x0035d9d0.cpp [wrapped: conflict: FUN_0027b020; Pair]
// sym: ?FUN_0035d9d0@fn_0035d9d0@@YAXXZ
namespace fn_0035d9d0 {
// data: result = DAT_004de698

struct Pair {
    int a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035d9d0() {
    (*(Pair*)&DAT_004de698) = FUN_0027b020("GameInstaceLocators");
}
} // namespace fn_0035d9d0


// 0x0035d9f0 FUN_0035d9f0 (25 B): matches/0x0035d9f0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035d9f0@fn_0035d9f0@@YAXXZ
namespace fn_0035d9f0 {
// data: result = DAT_004de680

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035d9f0() {
    (*(Pair*)&DAT_004de680) = FUN_0027b020("GoToSim");
}
} // namespace fn_0035d9f0


// 0x0035da10 FUN_0035da10 (25 B): matches/0x0035da10.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035da10@fn_0035da10@@YAXXZ
namespace fn_0035da10 {
// data: hulk_at_00400488 = DAT_00400488

typedef unsigned int u32;
typedef unsigned long long u64_35da10;
extern "C++" __declspec(nothrow) u64_35da10 __cdecl FUN_0027b020(const void*);
void FUN_0035da10() {
    u64_35da10 r = FUN_0027b020((const void*)((hulk_intptr)((char*)&DAT_00400488)));
    (*(u32*)&DAT_004de6f0) = (u32)r;
    (*(u32*)&DAT_004de6f4) = (u32)(r >> 32);
}
} // namespace fn_0035da10

namespace fn_f1ddef39 {

// 0x0035da30 FUN_0035da30 (25 B): matches/0x0035da30.cpp
// sym: ?FUN_0035da30@fn_f1ddef39@@YAXXZ
// data: gValue = DAT_004de6f8
void FUN_0035da30() {
    (*(__int64*)&DAT_004de6f8) = FUN_0027b020(((const int*)&DAT_0040048c));
}

} // namespace fn_f1ddef39

// 0x0035da50 FUN_0035da50 (25 B): matches/0x0035da50.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035da50@fn_0035da50@@YAXXZ
namespace fn_0035da50 {
// data: gPair = DAT_004de710

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035da50() {
    (*(Pair*)&DAT_004de710) = FUN_0027b020("$MACRO_DEFINE");
}
} // namespace fn_0035da50


// 0x0035da70 FUN_0035da70 (25 B): matches/0x0035da70.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035da70@fn_0035da70@@YAXXZ
namespace fn_0035da70 {
// data: gPair = DAT_004de6e8

struct Pair {
    unsigned a;
    unsigned b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035da70() {
    (*(Pair*)&DAT_004de6e8) = FUN_0027b020("$MACRO_INSERT");
}
} // namespace fn_0035da70


// 0x0035da90 FUN_0035da90 (25 B): matches/0x0035da90.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035da90@fn_0035da90@@YAXXZ
namespace fn_0035da90 {

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035da90() {
    (*(__int64*)&DAT_004de6e0) = FUN_0027b020("TextInputNumEntries");
}
} // namespace fn_0035da90

namespace fn_f1ddef39 {

// 0x0035dab0 FUN_0035dab0 (25 B): matches/0x0035dab0.cpp
// sym: ?FUN_0035dab0@fn_f1ddef39@@YAXXZ
// data: g_hash_35dab0 = DAT_004de700
void FUN_0035dab0() {
    unsigned long long r = FUN_0027b020("TextInputEntryLocators");
    (*(unsigned int*)&DAT_004de700) = (unsigned int)r;
    g_hash_hi = (unsigned int)(r >> 32);
}


// 0x0035dad0 FUN_0035dad0 (25 B): matches/0x0035dad0.cpp
// sym: ?FUN_0035dad0@fn_f1ddef39@@YAXXZ
// data: gCursorLocators = DAT_004de708
void FUN_0035dad0() {
    unsigned long long r = FUN_0027b020("TextInputCursorLocators");
    ((void**)&DAT_004de708)[0] = (void*)((hulk_uintptr)r);
    ((void**)&DAT_004de708)[1] = (void*)((hulk_uintptr)(r >> 32));
}

} // namespace fn_f1ddef39

// 0x0035daf0 FUN_0035daf0 (25 B): matches/0x0035daf0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035daf0@fn_0035daf0@@YAXXZ
namespace fn_0035daf0 {
// data: result = DAT_004de6d8

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035daf0() {
    (*(Pair*)&DAT_004de6d8) = FUN_0027b020("ClearAfterEntry");
}
} // namespace fn_0035daf0

namespace fn_f1ddef39 {

// 0x0035db10 FUN_0035db10 (25 B): matches/0x0035db10.cpp
// sym: ?FUN_0035db10@fn_f1ddef39@@YAXXZ
// data: gHashHigh = DAT_004de724, gHashLow = DAT_004de720, hulk_at_00400488 = DAT_00400488
void FUN_0035db10() {
    unsigned __int64 h = FUN_0027b020((const char*)((hulk_intptr)((char*)&DAT_00400488)));
    (*(unsigned int*)&DAT_004de720) = (unsigned int)h;
    (*(unsigned int*)&DAT_004de724) = (unsigned int)(h >> 32);
}

} // namespace fn_f1ddef39

// 0x0035db30 FUN_0035db30 (25 B): matches/0x0035db30.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035db30@fn_0035db30@@YAXXZ
namespace fn_0035db30 {

struct Hash_35db30 {
    unsigned int lo;
    unsigned int hi;
};

Hash_35db30 __cdecl FUN_0027b020(const void* p);

void FUN_0035db30() {
    Hash_35db30 h = FUN_0027b020(((unsigned char*)&DAT_0040048c));
    (*(unsigned int*)&DAT_004de728) = h.lo;
    (*(unsigned int*)&DAT_004de72c) = h.hi;
}
} // namespace fn_0035db30

namespace fn_f1ddef39 {

// 0x0035db50 FUN_0035db50 (25 B): matches/0x0035db50.cpp
// sym: ?FUN_0035db50@fn_f1ddef39@@YAXXZ
// data: gMacro = DAT_004de730
void FUN_0035db50() {
    (*(U64_35db50*)&DAT_004de730) = FUN_0027b020("$MACRO_DEFINE");
}

} // namespace fn_f1ddef39

// 0x0035db70 FUN_0035db70 (25 B): matches/0x0035db70.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035db70@fn_0035db70@@YAXXZ
namespace fn_0035db70 {
// data: gValue = DAT_004de718

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035db70() {
    (*(__int64*)&DAT_004de718) = FUN_0027b020("$MACRO_INSERT");
}
} // namespace fn_0035db70


// 0x0035db90 FUN_0035db90 (25 B): matches/0x0035db90.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035db90@fn_0035db90@@YAXXZ
namespace fn_0035db90 {

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const int*);
void FUN_0035db90() {
    (*(Pair*)&DAT_004de750) = FUN_0027b020(((const int*)&DAT_00400488));
}
} // namespace fn_0035db90

namespace fn_f1ddef39 {

// 0x0035dbb0 FUN_0035dbb0 (25 B): matches/0x0035dbb0.cpp
// sym: ?FUN_0035dbb0@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035dbb0() {
    unsigned long long v = FUN_0027b020(((char*)&DAT_0040048c));
    *(unsigned int*)&v;
    (*(unsigned int*)&DAT_004de758) = (unsigned int)v;
    (*(unsigned int*)&DAT_004de75c) = (unsigned int)(v >> 32);
}


// 0x0035dbd0 FUN_0035dbd0 (25 B): matches/0x0035dbd0.cpp
// sym: ?FUN_0035dbd0@fn_f1ddef39@@YAXXZ
// data: g_result_35dbd0 = DAT_004de760
void FUN_0035dbd0() {
    (*(U64_35dbd0*)&DAT_004de760) = FUN_0027b020("$MACRO_DEFINE");
}


// 0x0035dbf0 FUN_0035dbf0 (25 B): matches/0x0035dbf0.cpp
// sym: ?FUN_0035dbf0@fn_f1ddef39@@YAXXZ
// data: g1_35dbf0 = DAT_004de74c
void FUN_0035dbf0() {
    int64_35dbf0 r = FUN_0027b020("$MACRO_INSERT");
    g0 = (int)r;
    (*(int*)&DAT_004de74c) = (int)(r >> 32);
}


// 0x0035dc10 FUN_0035dc10 (29 B): matches/0x0035dc10.cpp
// sym: ?initSound@fn_f1ddef39@@YAXXZ
void initSound() {
    ((owners::String_23fc40 *)&gObj)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363e50);
}


// 0x0035dc30 FUN_0035dc30 (25 B): matches/0x0035dc30.cpp
// sym: ?FUN_0035dc30@fn_f1ddef39@@YAXXZ
// data: gResult_35dc30 = DAT_004de7f0, hulk_at_00400488 = DAT_00400488
void __cdecl FUN_0035dc30() {
    (*(unsigned __int64*)&DAT_004de7f0) = FUN_0027b020((const void*)((hulk_intptr)((char*)&DAT_00400488)));
}


// 0x0035dc50 FUN_0035dc50 (25 B): matches/0x0035dc50.cpp
// sym: ?FUN_0035dc50@fn_f1ddef39@@YAXXZ
// data: hulk_at_0040048c = DAT_0040048c
void FUN_0035dc50() {
    g = FUN_0027b020(((hulk_intptr)((char*)&DAT_0040048c)));
}


// 0x0035dc70 FUN_0035dc70 (25 B): matches/0x0035dc70.cpp
// sym: ?FUN_0035dc70@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035dc70() {
    unsigned long long r = FUN_0027b020("$MACRO_DEFINE");
    g_a = (int)r;
    g_b = (int)(r >> 32);
}


// 0x0035dc90 FUN_0035dc90 (25 B): matches/0x0035dc90.cpp
// sym: ?target@fn_f1ddef39@@YAXXZ
// data: globalPair = DAT_004de7e8
void target() {
    (*(unsigned __int64*)&DAT_004de7e8) = FUN_0027b020("$MACRO_INSERT");
}


// 0x0035dcb0 FUN_0035dcb0 (266 B): matches/0x0035dcb0.cpp
// sym: ?FUN_0035dcb0@fn_f1ddef39@@YAXXZ
// FUN_0035dcb0 @ 0x0035dcb0
// Static initialiser for a table of nine {lo, hi, level} bands.
void FUN_0035dcb0()
{
    ((Band*)&DAT_004de8d0)[0].lo = 1.0471975803375244f;
    ((Band*)&DAT_004de8d0)[0].hi = 2.094395160675049f;
    ((Band*)&DAT_004de8d0)[0].level = 0;
    ((Band*)&DAT_004de8d0)[1].lo = 2.094395160675049f;
    ((Band*)&DAT_004de8d0)[1].hi = 2.6179938316345215f;
    ((Band*)&DAT_004de8d0)[1].level = 7;
    ((Band*)&DAT_004de8d0)[2].lo = 2.6179938316345215f;
    ((Band*)&DAT_004de8d0)[2].hi = 3.665191650390625f;
    ((Band*)&DAT_004de8d0)[2].level = 6;
    ((Band*)&DAT_004de8d0)[3].lo = 3.665191650390625f;
    ((Band*)&DAT_004de8d0)[3].hi = 4.188790321350098f;
    ((Band*)&DAT_004de8d0)[3].level = 5;
    ((Band*)&DAT_004de8d0)[4].lo = 4.188790321350098f;
    ((Band*)&DAT_004de8d0)[4].hi = 5.235987663269043f;
    ((Band*)&DAT_004de8d0)[4].level = 4;
    ((Band*)&DAT_004de8d0)[5].lo = 5.235987663269043f;
    ((Band*)&DAT_004de8d0)[5].hi = 5.759586811065674f;
    ((Band*)&DAT_004de8d0)[5].level = 3;
    ((Band*)&DAT_004de8d0)[6].lo = 5.759586811065674f;
    ((Band*)&DAT_004de8d0)[6].hi = 6.28493070602417f;
    ((Band*)&DAT_004de8d0)[6].level = 2;
    ((Band*)&DAT_004de8d0)[7].lo = 0.0f;
    ((Band*)&DAT_004de8d0)[7].hi = 0.5235987901687622f;
    ((Band*)&DAT_004de8d0)[7].level = 2;
    ((Band*)&DAT_004de8d0)[8].lo = 0.5235987901687622f;
    ((Band*)&DAT_004de8d0)[8].hi = 1.0471975803375244f;
    ((Band*)&DAT_004de8d0)[8].level = 1;
}

} // namespace fn_f1ddef39

// 0x0035ddc0 FUN_0035ddc0 (25 B): matches/0x0035ddc0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035ddc0@fn_0035ddc0@@YAXXZ
namespace fn_0035ddc0 {
// data: gName = DAT_00400488, gResult = DAT_004de970

extern __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035ddc0() {
    (*(__int64*)&DAT_004de970) = FUN_0027b020(DAT_00400488);
}
} // namespace fn_0035ddc0

namespace fn_f1ddef39 {

// 0x0035dde0 FUN_0035dde0 (25 B): matches/0x0035dde0.cpp
// sym: ?FUN_0035dde0@fn_f1ddef39@@YAXXZ
// data: gA_35dde0 = DAT_004de978, gB_35dde0 = DAT_004de97c, hulk_at_0040048c = DAT_0040048c
void __cdecl FUN_0035dde0() {
    unsigned long long p = FUN_0027b020(((const char*)((char*)&DAT_0040048c)));
    (*(unsigned int*)&DAT_004de978) = (unsigned int)p;
    (*(unsigned int*)&DAT_004de97c) = (unsigned int)((unsigned long long)p >> 32);
}


// 0x0035de00 FUN_0035de00 (25 B): matches/0x0035de00.cpp
// sym: ?FUN_0035de00@fn_f1ddef39@@YAXXZ
// data: gResult_35de00 = DAT_004de980
void __cdecl FUN_0035de00() {
    long long r = FUN_0027b020("$MACRO_DEFINE");
    (*(long long*)&DAT_004de980) = r;
}

} // namespace fn_f1ddef39

// 0x0035de20 FUN_0035de20 (25 B): matches/0x0035de20.cpp [wrapped: conflict: FUN_0027b020]
// sym: _FUN_0035de20
namespace fn_0035de20 {
// data: gValue = DAT_004de968

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
extern "C" void __cdecl FUN_0035de20() {
    (*(__int64*)&DAT_004de968) = FUN_0027b020("$MACRO_INSERT");
}
} // namespace fn_0035de20


// 0x0035de60 FUN_0035de60 (25 B): matches/0x0035de60.cpp [wrapped: compile error C2440: 'initializing' : cannot convert from 'fn_f1ddef39::Pair' to 'unsigned __int64']
// sym: ?FUN_0035de60@fn_0035de60@@YAXXZ
namespace fn_0035de60 {
// data: hulk_at_00400488 = DAT_00400488

extern "C++" __declspec(nothrow) unsigned long long __cdecl FUN_0027b020(hulk_uintptr seed);

unsigned int g_hash_low;
unsigned int g_hash_high;

void FUN_0035de60() {
    unsigned long long h = FUN_0027b020(((hulk_intptr)((char*)&DAT_00400488)));
    g_hash_low = (unsigned int)h;
    g_hash_high = (unsigned int)(h >> 32);
}
} // namespace fn_0035de60


// 0x0035de80 FUN_0035de80 (25 B): matches/0x0035de80.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035de80@fn_0035de80@@YAXXZ
namespace fn_0035de80 {
// data: hulk_at_0040048c = DAT_0040048c, result = DAT_004de9a0

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(hulk_intptr);
void FUN_0035de80() {
    (*(__int64*)&DAT_004de9a0) = FUN_0027b020(((hulk_intptr)((char*)&DAT_0040048c)));
}
} // namespace fn_0035de80

namespace fn_f1ddef39 {

// 0x0035dea0 FUN_0035dea0 (25 B): matches/0x0035dea0.cpp
// sym: ?FUN_0035dea0@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035dea0() {
    long long v = FUN_0027b020("$MACRO_DEFINE");
    *(unsigned long long*)((unsigned char*)&DAT_004de9a8) = (unsigned long long)v;
}

} // namespace fn_f1ddef39

// 0x0035dec0 FUN_0035dec0 (25 B): matches/0x0035dec0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035dec0@fn_0035dec0@@YAXXZ
namespace fn_0035dec0 {
// data: g_value = DAT_004de990

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035dec0() {
    (*(__int64*)&DAT_004de990) = FUN_0027b020("$MACRO_INSERT");
}
} // namespace fn_0035dec0


// 0x0035dee0 FUN_0035dee0 (25 B): matches/0x0035dee0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035dee0@fn_0035dee0@@YAXXZ
namespace fn_0035dee0 {
// data: gData = DAT_00400488, gResult = DAT_004e09b8

extern __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035dee0() {
    (*(__int64*)&DAT_004e09b8) = FUN_0027b020(((char*)&DAT_00400488));
}
} // namespace fn_0035dee0

namespace fn_f1ddef39 {

// 0x0035df00 FUN_0035df00 (25 B): matches/0x0035df00.cpp
// sym: ?FUN_0035df00@fn_f1ddef39@@YAXXZ
// data: result = DAT_004e09c0
void FUN_0035df00() {
    (*(__int64*)&DAT_004e09c0) = FUN_0027b020(text);
}


// 0x0035df20 FUN_0035df20 (25 B): matches/0x0035df20.cpp
// sym: ?FUN_0035df20@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035df20() {
    unsigned __int64 r = FUN_0027b020("$MACRO_DEFINE");
    *(int*)((char*)&DAT_004e09c8) = (int)r;
    *(int*)((char*)&DAT_004e09cc) = (int)(r >> 32);
}

} // namespace fn_f1ddef39

// 0x0035df40 FUN_0035df40 (25 B): matches/0x0035df40.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035df40@fn_0035df40@@YAXXZ
namespace fn_0035df40 {
// data: g_pair = DAT_004e09b0

extern "C" struct Pair {
    unsigned a;
    unsigned b;
};
extern "C++" __declspec(nothrow) Pair __cdecl FUN_0027b020(const char*);
void FUN_0035df40() {
    (*(Pair*)&DAT_004e09b0) = FUN_0027b020("$MACRO_INSERT");
}
} // namespace fn_0035df40


// 0x0035df60 FUN_0035df60 (25 B): matches/0x0035df60.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?target@fn_0035df60@@YAXXZ
namespace fn_0035df60 {
// data: result = DAT_004e09d8, text = DAT_00400488

extern "C++" __declspec(nothrow) __int64 FUN_0027b020(const char*);
void target() {
    (*(__int64*)&DAT_004e09d8) = FUN_0027b020(DAT_00400488);
}
} // namespace fn_0035df60


// 0x0035df80 FUN_0035df80 (25 B): matches/0x0035df80.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035df80@fn_0035df80@@YAXXZ
namespace fn_0035df80 {
// data: text = DAT_0040048c

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035df80() {
    (*(__int64*)&DAT_004e09e0) = FUN_0027b020(DAT_0040048c);
}
} // namespace fn_0035df80

namespace fn_f1ddef39 {

// 0x0035dfa0 FUN_0035dfa0 (25 B): matches/0x0035dfa0.cpp
// sym: ?FUN_0035dfa0@fn_f1ddef39@@YAXXZ
// data: gValue = DAT_004e09ec
void FUN_0035dfa0() {
    unsigned long long v = FUN_0027b020("$MACRO_DEFINE");
    (*(unsigned int*)&DAT_004e09e8) = (unsigned int)v;
    (*(unsigned int*)&DAT_004e09ec) = (unsigned int)(v >> 32);
}


// 0x0035dfc0 FUN_0035dfc0 (25 B): matches/0x0035dfc0.cpp
// sym: ?FUN_0035dfc0@fn_f1ddef39@@YAXXZ
// data: gHi_35dfc0 = DAT_004e09d0
void FUN_0035dfc0() {
    unsigned long long r = FUN_0027b020("$MACRO_INSERT");
    (*(uint*)&DAT_004e09d0) = (uint)r;
    (*(uint*)&DAT_004e09d4) = (uint)(r >> 32);
}

} // namespace fn_f1ddef39

// 0x0035dfe0 FUN_0035dfe0 (25 B): matches/0x0035dfe0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035dfe0@fn_0035dfe0@@YAXXZ
namespace fn_0035dfe0 {
// data: g_lo_35dfe0 = DAT_004e0a08, hulk_at_00400488 = DAT_00400488

struct Hash_35dfe0 {
    unsigned int lo;
    unsigned int hi;
};
extern "C++" __declspec(nothrow) Hash_35dfe0 __cdecl FUN_0027b020(const char*);

void __cdecl FUN_0035dfe0() {
    Hash_35dfe0 h = FUN_0027b020((const char*)((hulk_intptr)((char*)&DAT_00400488)));
    (*(unsigned int*)&DAT_004e0a08) = h.lo;
    (*(unsigned int*)((char*)&DAT_004e0a08 + 4)) = h.hi;
}
} // namespace fn_0035dfe0

namespace fn_f1ddef39 {

// 0x0035e000 FUN_0035e000 (25 B): matches/0x0035e000.cpp
// sym: ?FUN_0035e000@fn_f1ddef39@@YAXXZ
// data: g_guid = DAT_004e0a10, hulk_at_0040048c = DAT_0040048c
void FUN_0035e000() {
    (*(G*)&DAT_004e0a10).v = FUN_0027b020((const char*)((hulk_intptr)((char*)&DAT_0040048c)));
}

} // namespace fn_f1ddef39

// 0x0035e020 FUN_0035e020 (25 B): matches/0x0035e020.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035e020@fn_0035e020@@YAXXZ
namespace fn_0035e020 {
// data: gResult = DAT_004e0a18

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e020() {
    (*(Pair*)&DAT_004e0a18) = FUN_0027b020("$MACRO_DEFINE");
}
} // namespace fn_0035e020

namespace fn_f1ddef39 {

// 0x0035e040 FUN_0035e040 (25 B): matches/0x0035e040.cpp
// sym: ?FUN_0035e040@fn_f1ddef39@@YAXXZ
// data: k_string = DAT_004004a0
void __cdecl FUN_0035e040() {
    unsigned long long r = FUN_0027b020(DAT_004004a0);
    g_result_lo = (unsigned int)r;
    g_result_hi = (unsigned int)(r >> 32);
}

} // namespace fn_f1ddef39

// 0x0035e060 FUN_0035e060 (25 B): matches/0x0035e060.cpp [wrapped: same definition as 0x0035dc90 in this TU]
// sym: ?target@fn_0035e060@@YAXXZ
namespace fn_0035e060 {
// data: result = DAT_004e0a28

extern __int64 __cdecl FUN_0027b020(const char*);
void target() {
    (*(__int64*)&DAT_004e0a28) = FUN_0027b020(((char*)&DAT_00400488));
}
} // namespace fn_0035e060

namespace fn_f1ddef39 {

// 0x0035e080 FUN_0035e080 (25 B): matches/0x0035e080.cpp
// sym: ?FUN_0035e080@fn_f1ddef39@@YAXXZ
// data: result = DAT_004e0a30
void FUN_0035e080() {
    (*(__int64*)&DAT_004e0a30) = FUN_0027b020(DAT_0040048c);
}


// 0x0035e0a0 FUN_0035e0a0 (25 B): matches/0x0035e0a0.cpp
// sym: ?FUN_0035e0a0@fn_f1ddef39@@YAXXZ
void FUN_0035e0a0() {
    (*(unsigned long long*)&DAT_004e0a38) = FUN_0027b020("$MACRO_DEFINE");
}


// 0x0035e0c0 FUN_0035e0c0 (25 B): matches/0x0035e0c0.cpp
// sym: ?FUN_0035e0c0@fn_f1ddef39@@YAXXZ
// data: g_macro_value = DAT_004e0a20
void FUN_0035e0c0() {
    (*(unsigned __int64*)&DAT_004e0a20) = FUN_0027b020("$MACRO_INSERT");
}


// 0x0035e0e0 FUN_0035e0e0 (25 B): matches/0x0035e0e0.cpp
// sym: ?FUN_0035e0e0@fn_f1ddef39@@YAXXZ
// data: hulk_at_00400488 = DAT_00400488
void FUN_0035e0e0() {
    (*(unsigned long long*)&DAT_004e0a48) = FUN_0027b020((const void*)((hulk_intptr)((char*)&DAT_00400488)));
}

} // namespace fn_f1ddef39

// 0x0035e100 FUN_0035e100 (25 B): matches/0x0035e100.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035e100@fn_0035e100@@YAXXZ
namespace fn_0035e100 {
// data: hulk_at_0040048c = DAT_0040048c

struct Pair_35e100 {
    int a, b;
};
extern "C++" __declspec(nothrow) Pair_35e100 __cdecl FUN_0027b020(hulk_intptr);
void __cdecl FUN_0035e100() {
    Pair_35e100 r = FUN_0027b020(((hulk_intptr)((char*)&DAT_0040048c)));
    (*(int*)&DAT_004e0a50) = r.a;
    (*(int*)&DAT_004e0a54) = r.b;
}
} // namespace fn_0035e100


// 0x0035e120 FUN_0035e120 (25 B): matches/0x0035e120.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035e120@fn_0035e120@@YAXXZ
namespace fn_0035e120 {

typedef struct {
    unsigned lo;
    unsigned hi;
} Pair_35e120;
extern Pair_35e120 __cdecl FUN_0027b020(const char*);
void __cdecl FUN_0035e120() {
    Pair_35e120 r = FUN_0027b020("$MACRO_DEFINE");
    (*(unsigned*)&DAT_004e0a58) = r.lo;
    (*(unsigned*)&DAT_004e0a5c) = r.hi;
}
} // namespace fn_0035e120

namespace fn_f1ddef39 {

// 0x0035e140 FUN_0035e140 (25 B): matches/0x0035e140.cpp
// sym: ?FUN_0035e140@fn_f1ddef39@@YAXXZ
// data: g_first_35e140 = DAT_004e0a40, g_second_35e140 = DAT_004e0a44
void FUN_0035e140() {
    unsigned __int64 result = FUN_0027b020("$MACRO_INSERT");
    (*(unsigned int*)&DAT_004e0a40) = (unsigned int)result;
    (*(unsigned int*)&DAT_004e0a44) = (unsigned int)(result >> 32);
}

} // namespace fn_f1ddef39

// 0x0035e160 FUN_0035e160 (25 B): matches/0x0035e160.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035e160@fn_0035e160@@YAXXZ
namespace fn_0035e160 {
// data: input = DAT_00400488, result = DAT_004e0a78

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const void*);
void FUN_0035e160() {
    (*(__int64*)&DAT_004e0a78) = FUN_0027b020(((char*)&DAT_00400488));
}
} // namespace fn_0035e160

namespace fn_f1ddef39 {

// 0x0035e180 FUN_0035e180 (25 B): matches/0x0035e180.cpp
// sym: ?FUN_0035e180@fn_f1ddef39@@YAXXZ
// data: result = DAT_004e0a80, text = DAT_0040048c
void FUN_0035e180() {
    (*(__int64*)&DAT_004e0a80) = FUN_0027b020(DAT_0040048c);
}


// 0x0035e1a0 FUN_0035e1a0 (25 B): matches/0x0035e1a0.cpp
// sym: ?FUN_0035e1a0@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035e1a0() {
    unsigned long long r = FUN_0027b020(DAT_00400490);
    g_a = (int)r;
    g_b = (int)(r >> 32);
}

} // namespace fn_f1ddef39

// 0x0035e1c0 FUN_0035e1c0 (25 B): matches/0x0035e1c0.cpp [wrapped: conflict: FUN_0027b020]
// sym: _FUN_0035e1c0
namespace fn_0035e1c0 {
// data: gValue = DAT_004e0a70

struct Pair {
    unsigned a;
    unsigned b;
};
extern "C++" __declspec(nothrow) Pair __cdecl FUN_0027b020(const char*);
extern "C" void __cdecl FUN_0035e1c0() {
    (*(Pair*)&DAT_004e0a70) = FUN_0027b020("$MACRO_INSERT");
}
} // namespace fn_0035e1c0

namespace fn_f1ddef39 {

// 0x0035e1e0 FUN_0035e1e0 (25 B): matches/0x0035e1e0.cpp
// sym: ?FUN_0035e1e0@fn_f1ddef39@@YAXXZ
void FUN_0035e1e0() {
    *(unsigned __int64*)&result = FUN_0027b020("golfBall_golfBall");
}


// 0x0035e200 FUN_0035e200 (25 B): matches/0x0035e200.cpp
// sym: ?FUN_0035e200@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035e200() {
    (*(unsigned __int64*)&DAT_004e0ba8) = FUN_0027b020("golfBall_golfBall");
}


// 0x0035e220 FUN_0035e220 (25 B): matches/0x0035e220.cpp
// sym: ?FUN_0035e220@fn_f1ddef39@@YAXXZ
// data: g_seek = DAT_004e0cf8
void FUN_0035e220() {
    (*(__int64*)&DAT_004e0cf8) = FUN_0027b020("seek");
}

} // namespace fn_f1ddef39

// 0x0035e240 FUN_0035e240 (25 B): matches/0x0035e240.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035e240@fn_0035e240@@YAXXZ
namespace fn_0035e240 {

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035e240() {
    (*(__int64*)&DAT_004e0d10) = FUN_0027b020("retreat");
}
} // namespace fn_0035e240


// 0x0035e260 FUN_0035e260 (25 B): matches/0x0035e260.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035e260@fn_0035e260@@YAXXZ
namespace fn_0035e260 {
// data: gPair = DAT_004e0d28

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e260() {
    (*(Pair*)&DAT_004e0d28) = FUN_0027b020("routing");
}
} // namespace fn_0035e260


// 0x0035e280 FUN_0035e280 (25 B): matches/0x0035e280.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035e280@fn_0035e280@@YAXXZ
namespace fn_0035e280 {
// data: g_result = DAT_004e0d18

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035e280() {
    (*(__int64*)&DAT_004e0d18) = FUN_0027b020("flank");
}
} // namespace fn_0035e280


// 0x0035e2a0 FUN_0035e2a0 (25 B): matches/0x0035e2a0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?InitWaypoint@fn_0035e2a0@@YAXXZ
namespace fn_0035e2a0 {
// data: gPair = DAT_004e0d08

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void InitWaypoint() {
    (*(Pair*)&DAT_004e0d08) = FUN_0027b020("waypoint");
}
} // namespace fn_0035e2a0


// 0x0035e2c0 FUN_0035e2c0 (25 B): matches/0x0035e2c0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035e2c0@fn_0035e2c0@@YAXXZ
namespace fn_0035e2c0 {
// data: result = DAT_004e0cf0

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void __cdecl FUN_0035e2c0() {
    (*(Pair*)&DAT_004e0cf0) = FUN_0027b020("locator");
}
} // namespace fn_0035e2c0


// 0x0035e2e0 FUN_0035e2e0 (25 B): matches/0x0035e2e0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035e2e0@fn_0035e2e0@@YAXXZ
namespace fn_0035e2e0 {
// data: g_result = DAT_004e0ce8

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e2e0() {
    (*(Pair*)&DAT_004e0ce8) = FUN_0027b020("closest_intersect");
}
} // namespace fn_0035e2e0


// 0x0035e300 FUN_0035e300 (25 B): matches/0x0035e300.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035e300@fn_0035e300@@YAXXZ
namespace fn_0035e300 {
// data: result = DAT_004e0d20

struct Pair {
    unsigned a;
    unsigned b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e300() {
    (*(Pair*)&DAT_004e0d20) = FUN_0027b020("closest_intersect_enemy");
}
} // namespace fn_0035e300


// 0x0035e320 FUN_0035e320 (25 B): matches/0x0035e320.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035e320@fn_0035e320@@YAXXZ
namespace fn_0035e320 {
// data: result = DAT_004e0d00

extern "C" struct Pair {
    unsigned a;
    unsigned b;
};
extern "C++" __declspec(nothrow) Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e320() {
    (*(Pair*)&DAT_004e0d00) = FUN_0027b020("random_intersect");
}
} // namespace fn_0035e320

namespace fn_f1ddef39 {

// 0x0035e340 FUN_0035e340 (29 B): matches/0x0035e340.cpp
// sym: ?FUN_0035e340@fn_f1ddef39@@YAXXZ
void FUN_0035e340() {
    ((owners::String_23fc40 *)&gObj)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    _atexit(FUN_00363f30);
}


// 0x0035e360 FUN_0035e360 (25 B): matches/0x0035e360.cpp
// sym: ?FUN_0035e360@fn_f1ddef39@@YAXXZ
// data: gNamePair = DAT_004e0f70
void FUN_0035e360() {
    (*(U64_35e360*)&DAT_004e0f70) = FUN_0027b020("golfBall_golfBall");
}

} // namespace fn_f1ddef39

// 0x0035e380 FUN_0035e380 (29 B): matches/0x0035e380.cpp [wrapped: conflict: _atexit]
// sym: ?FUN_0035e380@fn_0035e380@@YAXXZ
namespace fn_0035e380 {
// data: g_sound = DAT_004e0f60, g_sound_rsd = DAT_003f3ea0

extern "C++" __declspec(nothrow) void __cdecl FUN_00363f40();
extern char* g_bss;

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern void __cdecl _atexit(void (*)());
#endif

class Sound {
  public:
};
void FUN_0035e380() {
    ((owners::String_23fc40 *)&((*(Sound*)&DAT_004e0f60)))->FUN_0023fc40(((char*)&DAT_003f3ea0), (hulk_intptr)0);
    _atexit(FUN_00363f40);
}
} // namespace fn_0035e380

namespace fn_f1ddef39 {

// 0x0035e3a0 FUN_0035e3a0 (29 B): matches/0x0035e3a0.cpp
// sym: ?FUN_0035e3a0@fn_f1ddef39@@YAXXZ
// data: gDevice = DAT_004e0fb0
void __cdecl FUN_0035e3a0() {
    ((owners::String_23fc40 *)&((*(Device*)&DAT_004e0fb0)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363f50);
}

} // namespace fn_f1ddef39

// 0x0035e3c0 FUN_0035e3c0 (25 B): matches/0x0035e3c0.cpp [wrapped: conflict: FUN_0027b020; Pair]
// sym: ?FUN_0035e3c0@fn_0035e3c0@@YAXXZ
namespace fn_0035e3c0 {
// data: result = DAT_004e1150

struct Pair {
    int a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e3c0() {
    (*(Pair*)&DAT_004e1150) = FUN_0027b020("golfBall_golfBall");
}
} // namespace fn_0035e3c0

namespace fn_f1ddef39 {

// 0x0035e3e0 FUN_0035e3e0 (25 B): matches/0x0035e3e0.cpp
// sym: ?FUN_0035e3e0@fn_f1ddef39@@YAXXZ
// data: g_hash_35e3e0 = DAT_004e12c8
void FUN_0035e3e0() {
    unsigned long long result = FUN_0027b020("golfBall_golfBall");
    (*(Hash_35e3e0*)&DAT_004e12c8).lo = (unsigned int)result;
    (*(Hash_35e3e0*)&DAT_004e12c8).hi = (unsigned int)(result >> 32);
}

} // namespace fn_f1ddef39

// 0x0035e400 FUN_0035e400 (25 B): matches/0x0035e400.cpp [wrapped: conflict: FUN_0027b020; Pair]
// sym: ?target@fn_0035e400@@YAXXZ
namespace fn_0035e400 {
// data: result = DAT_004e13d8

struct Pair {
    int a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void target() {
    (*(Pair*)&DAT_004e13d8) = FUN_0027b020("golfBall_golfBall");
}
} // namespace fn_0035e400


// 0x0035e420 FUN_0035e420 (25 B): matches/0x0035e420.cpp [wrapped: conflict: FUN_0027b020; Pair]
// sym: ?FUN_0035e420@fn_0035e420@@YAXXZ
namespace fn_0035e420 {

struct Pair {
    int a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e420() {
    (*(Pair*)&DAT_004e13d0) = FUN_0027b020("boost");
}
} // namespace fn_0035e420

namespace fn_f1ddef39 {

// 0x0035e440 FUN_0035e440 (25 B): matches/0x0035e440.cpp
// sym: ?FUN_0035e440@fn_f1ddef39@@YAXXZ
void FUN_0035e440() {
    U64_35e440 r = FUN_0027b020("drop");
    (*(int*)&DAT_004e13e0) = (int)r;
    (*(int*)((char*)&DAT_004e13e0 + 4)) = (int)(r >> 32);
}


// 0x0035e460 FUN_0035e460 (25 B): matches/0x0035e460.cpp
// sym: ?FUN_0035e460@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035e460() {
    unsigned long long r = FUN_0027b020("waypoint");
    g_a = (int)r;
    g_b = (int)(r >> 32);
}

} // namespace fn_f1ddef39

// 0x0035e480 FUN_0035e480 (25 B): matches/0x0035e480.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035e480@fn_0035e480@@YAXXZ
namespace fn_0035e480 {

extern "C" {
struct Pair {
    int a;
    int b;
};
extern "C++" { __declspec(nothrow) Pair __cdecl FUN_0027b020(const char*); }
}
void FUN_0035e480() {
    (*(Pair*)&DAT_004e13c8) = FUN_0027b020("none");
}
} // namespace fn_0035e480

namespace fn_f1ddef39 {

// 0x0035e4a0 FUN_0035e4a0 (25 B): matches/0x0035e4a0.cpp
// sym: ?FUN_0035e4a0@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035e4a0() {
    unsigned long long hash = FUN_0027b020("golfBall_golfBall");
    g_result_lo = (unsigned int)hash;
    g_result_hi = (unsigned int)(hash >> 32);
}

} // namespace fn_f1ddef39

// 0x0035e4c0 FUN_0035e4c0 (29 B): matches/0x0035e4c0.cpp [wrapped: conflict: Sound]
// sym: ?init@fn_0035e4c0@@YAXXZ
namespace fn_0035e4c0 {
// data: sound = DAT_004e14f8

class Sound {
  public:
    Sound(const char*, int);
    ~Sound();
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00363f80();
void init() {
    ((owners::String_23fc40 *)&DAT_004e14f8)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363f80);
}
} // namespace fn_0035e4c0


// 0x0035e4e0 FUN_0035e4e0 (25 B): matches/0x0035e4e0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?init@fn_0035e4e0@@YAXXZ
namespace fn_0035e4e0 {
// data: result = DAT_004e15a8

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void init() {
    (*(Pair*)&DAT_004e15a8) = FUN_0027b020("golfBall_golfBall");
}
} // namespace fn_0035e4e0

namespace fn_f1ddef39 {

// 0x0035e500 FUN_0035e500 (29 B): matches/0x0035e500.cpp
// sym: ?FUN_0035e500@fn_f1ddef39@@YAXXZ
// data: hulk_at_004e159c = DAT_004e159c
void FUN_0035e500() {
    ((owners::String_23fc40 *)(((Reg*)((hulk_intptr)((char*)&DAT_004e159c)))))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    _atexit(FUN_00363f90);
}


// 0x0035e520 FUN_0035e520 (25 B): matches/0x0035e520.cpp
// sym: ?FUN_0035e520@fn_f1ddef39@@YAXXZ
void FUN_0035e520() {
    unsigned long long h = FUN_0027b020("golfBall_golfBall");
    (*(unsigned int*)&DAT_004e1778) = (unsigned int)h;
    (*(unsigned int*)&DAT_004e177c) = (unsigned int)(h >> 32);
}

} // namespace fn_f1ddef39

// 0x0035e540 FUN_0035e540 (29 B): matches/0x0035e540.cpp [wrapped: conflict: _atexit]
// sym: ?Hook@fn_0035e540@@YAXXZ
namespace fn_0035e540 {
// data: hulk_at_004e1768 = DAT_004e1768


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void _atexit(void (*)());
#endif

class C {
  public:
};
void __cdecl FUN_00363fb0() throw();
void __cdecl Hook() {
    ((owners::String_23fc40 *)(((C*)((hulk_intptr)((char*)&DAT_004e1768)))))->FUN_0023fc40(((char*)&DAT_003f3ea0), (hulk_intptr)0);
    _atexit(FUN_00363fb0);
}
} // namespace fn_0035e540

namespace fn_f1ddef39 {

// 0x0035e560 FUN_0035e560 (29 B): matches/0x0035e560.cpp
// sym: ?Target@fn_f1ddef39@@YAXXZ
void Target() {
    ((owners::String_23fc40 *)&((*(Reg*)&DAT_004e1818)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363fc0);
}

} // namespace fn_f1ddef39

// 0x0035e580 FUN_0035e580 (25 B): matches/0x0035e580.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035e580@fn_0035e580@@YAXXZ
namespace fn_0035e580 {
// data: gPair = DAT_004e1828

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e580() {
    (*(Pair*)&DAT_004e1828) = FUN_0027b020("golfBall_golfBall");
}
} // namespace fn_0035e580

namespace fn_f1ddef39 {

// 0x0035e5a0 FUN_0035e5a0 (25 B): matches/0x0035e5a0.cpp
// sym: ?FUN_0035e5a0@fn_f1ddef39@@YAXXZ
void FUN_0035e5a0() {
    unsigned __int64 result = FUN_0027b020("flux");
    g_hash_lo = (unsigned int)result;
    g_hash_hi = (unsigned int)(result >> 32);
}

} // namespace fn_f1ddef39

// 0x0035e5c0 FUN_0035e5c0 (25 B): matches/0x0035e5c0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035e5c0@fn_0035e5c0@@YAXXZ
namespace fn_0035e5c0 {

extern "C" struct Pair_35e5c0 {
    int lo;
    int hi;
};
extern "C++" __declspec(nothrow) Pair_35e5c0 __cdecl FUN_0027b020(const char* s);
void FUN_0035e5c0() {
    Pair_35e5c0 r = FUN_0027b020("electric");
    (*(int*)&DAT_004e1808) = r.lo;
    (*(int*)&DAT_004e180c) = r.hi;
}
} // namespace fn_0035e5c0

namespace fn_f1ddef39 {

// 0x0035e5e0 FUN_0035e5e0 (25 B): matches/0x0035e5e0.cpp
// sym: ?FUN_0035e5e0@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035e5e0() {
    *(unsigned __int64*)&result = FUN_0027b020("golfBall_golfBall");
}


// 0x0035e620 FUN_0035e620 (25 B): matches/0x0035e620.cpp
// sym: ?FUN_0035e620@fn_f1ddef39@@YAXXZ
void FUN_0035e620() {
    unsigned __int64 id = FUN_0027b020("ATGWorldCollision");
    DAT_004e2198 = (unsigned int)id;
    (*(unsigned int*)&DAT_004e219c) = (unsigned int)(id >> 32);
}

} // namespace fn_f1ddef39

// 0x0035e640 FUN_0035e640 (37 B): matches/0x0035e640.cpp [wrapped: same definition as 0x0035dc90 in this TU]
// sym: ?target@fn_0035e640@@YAXXZ
namespace fn_0035e640 {
// data: globalObj = DAT_004e216c

struct Obj {
    void FUN_002fb160(unsigned short, unsigned short, unsigned short);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00363ff0();
void __cdecl target() {
    (*(Obj*)((char*)&DAT_004e215c + 16)).FUN_002fb160(0xffff, 0xffff, 0xffff);
    atexit(FUN_00363ff0);
}
} // namespace fn_0035e640


// 0x0035e670 FUN_0035e670 (25 B): matches/0x0035e670.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035e670@fn_0035e670@@YAXXZ
namespace fn_0035e670 {
// data: gPair = DAT_004e2208

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e670() {
    (*(Pair*)&DAT_004e2208) = FUN_0027b020("golfBall_golfBall");
}
} // namespace fn_0035e670

namespace fn_f1ddef39 {

// 0x0035e690 FUN_0035e690 (29 B): matches/0x0035e690.cpp
// sym: ?FUN_0035e690@fn_f1ddef39@@YAXXZ
// data: g_mgr = DAT_004e21f8, k_path = DAT_003f3ea0
void __cdecl FUN_0035e690() {
    ((owners::String_23fc40 *)&((*(Mgr*)&DAT_004e21f8)))->FUN_0023fc40(DAT_003f3ea0, (hulk_intptr)0);
    _atexit(FUN_00364000);
}


// 0x0035e6b0 FUN_0035e6b0 (33 B): matches/0x0035e6b0.cpp
// sym: ?FUN_0035e6b0@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035e6b0() {
    (*(CStaticAllocator_35e6b0*)&DAT_004e2210).FUN_0008fde0(0x100, 0x20, 0xd, 0);
    atexit(FUN_00364010);
}

} // namespace fn_f1ddef39

// 0x0035e6e0 FUN_0035e6e0 (29 B): matches/0x0035e6e0.cpp [wrapped: conflict: g_obj]
// sym: ?FUN_0035e6e0@fn_0035e6e0@@YAXXZ
namespace fn_0035e6e0 {
// data: hulk_at_004e222d = DAT_004e222d

extern void* g_obj;

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern int atexit(void (*fn)());
#endif

extern "C++" __declspec(nothrow) void FUN_00364020();
class G {
  public:
};
void __cdecl FUN_0035e6e0() {
    ((owners::String_23fc40 *)(((G*)((hulk_intptr)(((char*)&DAT_004e222d) + 0x3)))))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00364020);
}
} // namespace fn_0035e6e0


// 0x0035e700 FUN_0035e700 (29 B): matches/0x0035e700.cpp [wrapped: conflict: Sound]
// sym: ?FUN_0035e700@fn_0035e700@@YAXXZ
namespace fn_0035e700 {
// data: gSound = DAT_004e2270

class Sound {
  public:
    Sound(const char*, int);
    ~Sound();
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364030();
void __cdecl FUN_0035e700() {
    ((owners::String_23fc40 *)((char*)&DAT_004e226c + 4))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00364030);
}
} // namespace fn_0035e700

namespace fn_f1ddef39 {

// 0x0035e720 FUN_0035e720 (25 B): matches/0x0035e720.cpp
// sym: ?FUN_0035e720@fn_f1ddef39@@YAXXZ
// data: input = DAT_00400488, result = DAT_004e2290
void FUN_0035e720() {
    (*(__int64*)&DAT_004e2290) = FUN_0027b020(((char*)&DAT_00400488));
}

} // namespace fn_f1ddef39

// 0x0035e740 FUN_0035e740 (25 B): matches/0x0035e740.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035e740@fn_0035e740@@YAXXZ
namespace fn_0035e740 {
// data: gPair = DAT_004e2298

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e740() {
    (*(Pair*)&DAT_004e2298) = FUN_0027b020("}");
}
} // namespace fn_0035e740

namespace fn_f1ddef39 {

// 0x0035e760 FUN_0035e760 (25 B): matches/0x0035e760.cpp
// sym: ?FUN_0035e760@fn_f1ddef39@@YAXXZ
void FUN_0035e760() {
    unsigned long long r = FUN_0027b020("$MACRO_DEFINE");
    (*(int*)&DAT_004e2288) = (int)r;
    (*(int*)&DAT_004e228c) = (int)(r >> 32);
}


// 0x0035e780 FUN_0035e780 (25 B): matches/0x0035e780.cpp
// sym: ?FUN_0035e780@fn_f1ddef39@@YAXXZ
// data: g_result_35e780 = DAT_004e2280
void FUN_0035e780() {
    (*(U64_35e780*)&DAT_004e2280) = FUN_0027b020("$MACRO_INSERT");
}

} // namespace fn_f1ddef39

// 0x0035e7a0 FUN_0035e7a0 (25 B): matches/0x0035e7a0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035e7a0@fn_0035e7a0@@YAXXZ
namespace fn_0035e7a0 {
struct Pair_35e7a0 {
    int lo, hi;
};
extern "C++" __declspec(nothrow) Pair_35e7a0 __cdecl FUN_0027b020(const char*);
struct Obj_35e7a0 {
    int a;
    int b;
};
Obj_35e7a0 g_b004e22e8;
void FUN_0035e7a0() {
    Pair_35e7a0 r = FUN_0027b020("golfBall_golfBall");
    g_b004e22e8.a = r.lo;
    g_b004e22e8.b = r.hi;
}
} // namespace fn_0035e7a0


// 0x0035e7c0 FUN_0035e7c0 (29 B): matches/0x0035e7c0.cpp [wrapped: same definition as 0x0035dc90 in this TU]
// sym: ?target@fn_0035e7c0@@YAXXZ
namespace fn_0035e7c0 {
// data: gRegistry = DAT_004e22fc

class Registry {
  public:
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364040();
void __cdecl target() {
    ((owners::String_23fc40 *)&((*(Registry*)&DAT_004e22fc)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00364040);
}
} // namespace fn_0035e7c0

namespace fn_f1ddef39 {

// 0x0035e7e0 FUN_0035e7e0 (25 B): matches/0x0035e7e0.cpp
// sym: ?FUN_0035e7e0@fn_f1ddef39@@YAXXZ
// data: gHigh_35e7e0 = DAT_004e233c
void FUN_0035e7e0() {
    unsigned long long r = FUN_0027b020("golfBall_golfBall");
    (*(unsigned int*)&DAT_004e2338) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e233c) = (unsigned int)(r >> 32);
}

} // namespace fn_f1ddef39

// 0x0035e800 FUN_0035e800 (25 B): matches/0x0035e800.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035e800@fn_0035e800@@YAXXZ
namespace fn_0035e800 {

struct Pair_35e800 {
    unsigned int lo;
    unsigned int hi;
};
extern "C++" __declspec(nothrow) Pair_35e800 __cdecl FUN_0027b020(const char*);
void FUN_0035e800() {
    struct Pair_35e800 r = FUN_0027b020("hulk");
    (*(unsigned int*)&DAT_004e2330) = r.lo;
    (*(unsigned int*)&DAT_004e2334) = r.hi;
}
} // namespace fn_0035e800


// 0x0035e820 FUN_0035e820 (29 B): matches/0x0035e820.cpp [wrapped: same definition as 0x0035d560 in this TU]
// sym: ?init@fn_0035e820@@YAXXZ
namespace fn_0035e820 {
// data: gSound = DAT_004e23b8

class Sound {
  public:
    Sound(const char*, int);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364050();
void init() {
    ((owners::String_23fc40 *)&DAT_004e23b8)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00364050);
}
} // namespace fn_0035e820

namespace fn_f1ddef39 {

// 0x0035e840 FUN_0035e840 (25 B): matches/0x0035e840.cpp
// sym: ?FUN_0035e840@fn_f1ddef39@@YAXXZ
// data: gHandle = DAT_004e2440
void FUN_0035e840() {
    (*(unsigned __int64*)&DAT_004e2440) = FUN_0027b020("golfBall_golfBall");
}


// 0x0035e860 FUN_0035e860 (319 B): matches/0x0035e860.cpp
// sym: ?FUN_0035e860@fn_f1ddef39@@YAXXZ
// FUN_0035e860 @ 0x0035e860
void FUN_0035e860() {
    (*(unsigned __int64*)&DAT_004e2448) = FUN_0027afb0("object_class");
    (*(unsigned __int64*)&DAT_004e2450) = FUN_0027afb0("base_name");
    (*(unsigned __int64*)&DAT_004e2458) = FUN_0027afb0("material");
    (*(unsigned __int64*)&DAT_004e2460) = FUN_0027afb0("collision_type");
    (*(unsigned __int64*)&DAT_004e2468) = FUN_0027afb0("can_turn_transparent");
    (*(unsigned __int64*)&DAT_004e2470) = FUN_0027afb0("held_damage_factor");
    (*(unsigned __int64*)&DAT_004e2478) = FUN_0027afb0("collectable");
    (*(unsigned __int64*)&DAT_004e2480) = FUN_0027afb0("ers_increase");
    (*(unsigned __int64*)&DAT_004e2488) = FUN_0027afb0("target_offset");
    (*(unsigned __int64*)&DAT_004e2490) = FUN_0027afb0("cargo");
    (*(unsigned __int64*)&DAT_004e2498) = FUN_0027afb0("invulnerable_to_tank_bumper");
    (*(unsigned __int64*)&DAT_004e24a0) = FUN_0027afb0("mission_critical");
    (*(unsigned __int64*)&DAT_004e24a8) = FUN_0027afb0("draw_last");
    (*(unsigned __int64*)&DAT_004e24b0) = FUN_0027afb0("opaque_while_held");
    (*(unsigned __int64*)&DAT_004e24b8) = FUN_0027afb0("opaque_while_occluding");
}


// 0x0035e9a0 FUN_0035e9a0 (235 B): matches/0x0035e9a0.cpp
// sym: ?FUN_0035e9a0@fn_f1ddef39@@YAXXZ
// FUN_0035e9a0 @ 0x0035e9a0
void FUN_0035e9a0() {
    (*(unsigned __int64*)&DAT_004e24c0) = FUN_0027afb0("none");
    (*(unsigned __int64*)&DAT_004e24c8) = FUN_0027afb0("glass");
    (*(unsigned __int64*)&DAT_004e24d0) = FUN_0027afb0("hardwood");
    (*(unsigned __int64*)&DAT_004e24d8) = FUN_0027afb0("softwood");
    (*(unsigned __int64*)&DAT_004e24e0) = FUN_0027afb0("hardrubber");
    (*(unsigned __int64*)&DAT_004e24e8) = FUN_0027afb0("softrubber");
    (*(unsigned __int64*)&DAT_004e24f0) = FUN_0027afb0("hardmetal");
    (*(unsigned __int64*)&DAT_004e24f8) = FUN_0027afb0("softmetal");
    (*(unsigned __int64*)&DAT_004e2500) = FUN_0027afb0("concrete");
    (*(unsigned __int64*)&DAT_004e2508) = FUN_0027afb0("sticky");
    (*(unsigned __int64*)&DAT_004e2510) = FUN_0027afb0("icy");
}


// 0x0035ea90 FUN_0035ea90 (25 B): matches/0x0035ea90.cpp
// sym: ?FUN_0035ea90@fn_f1ddef39@@YAXXZ
// data: gClass = DAT_004e2430, gClassNext = DAT_004e2434
void FUN_0035ea90() {
    unsigned __int64 r = FUN_0027b020("mass_class");
    (*(unsigned int*)&DAT_004e2430) = (unsigned int)r;
    (*(unsigned int*)((char*)&DAT_004e2430 + 4)) = (unsigned int)((r >> 32));
}


// 0x0035eab0 FUN_0035eab0 (25 B): matches/0x0035eab0.cpp
// sym: ?FUN_0035eab0@fn_f1ddef39@@YAXXZ
// data: g_mass_multiplier_hi = DAT_004e243c, g_mass_multiplier_lo = DAT_004e2438
void __cdecl FUN_0035eab0() {
    unsigned long long result = FUN_0027b020("mass_multiplier");
    (*(unsigned int*)&DAT_004e2438) = (unsigned int)result;
    (*(unsigned int*)((char*)&DAT_004e2438 + 4)) = (unsigned int)(result >> 32);
}

} // namespace fn_f1ddef39

// 0x0035ead0 FUN_0035ead0 (29 B): matches/0x0035ead0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?RegF@fn_0035ead0@@YAXXZ
namespace fn_0035ead0 {
// data: g_reg = DAT_004e2538


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void (*)(void));
#endif

class Reg {
  public:
};
void FUN_00364060() {}
void RegF() {
    ((owners::String_23fc40 *)&((*(Reg*)((char*)&DAT_004e2530 + 8))))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00364060);
}
} // namespace fn_0035ead0

namespace fn_f1ddef39 {

// 0x0035eaf0 FUN_0035eaf0 (25 B): matches/0x0035eaf0.cpp
// sym: ?Register@fn_f1ddef39@@YAXXZ
void Register() {
    unsigned long long h = FUN_0027b020("golfBall_golfBall");
    g_hash_lo = (unsigned int)h;
    g_hash_hi = (unsigned int)(h >> 32);
}


// 0x0035eb10 FUN_0035eb10 (25 B): matches/0x0035eb10.cpp
// sym: ?FUN_0035eb10@fn_f1ddef39@@YAXXZ
// data: g_lookup = DAT_004e2530
void FUN_0035eb10() {
    (*(u64_35eb10*)&DAT_004e2530) = FUN_0027b020("mercyFuelRod_mercyFuelRod");
}

} // namespace fn_f1ddef39

// 0x0035eb30 FUN_0035eb30 (25 B): matches/0x0035eb30.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035eb30@fn_0035eb30@@YAXXZ
namespace fn_0035eb30 {
// data: gValue = DAT_004e2528

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035eb30() {
    (*(__int64*)&DAT_004e2528) = FUN_0027b020("mercyFuelRod");
}
} // namespace fn_0035eb30

namespace fn_f1ddef39 {

// 0x0035eb50 FUN_0035eb50 (25 B): matches/0x0035eb50.cpp
// sym: ?FUN_0035eb50@fn_f1ddef39@@YAXXZ
// data: gPair = DAT_004e2550
void __cdecl FUN_0035eb50() {
    __int64 v = FUN_0027b020("mercyFuelRod2");
    (*(Pair_35eb50*)&DAT_004e2550) = *(Pair_35eb50*)&v;
}

} // namespace fn_f1ddef39

// 0x0035eb70 FUN_0035eb70 (25 B): matches/0x0035eb70.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035eb70@fn_0035eb70@@YAXXZ
namespace fn_0035eb70 {
// data: g_pair = DAT_004e2558

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035eb70() {
    (*(Pair*)&DAT_004e2558) = FUN_0027b020("mercyFuelRod3");
}
} // namespace fn_0035eb70


// 0x0035eb90 FUN_0035eb90 (25 B): matches/0x0035eb90.cpp [wrapped: conflict: FUN_0027b020]
// sym: _FUN_0035eb90
namespace fn_0035eb90 {
// data: gPair = DAT_004e2520

struct Pair {
    unsigned a, b;
};
extern "C++" __declspec(nothrow) Pair __cdecl FUN_0027b020(const char*);
extern "C" void FUN_0035eb90() {
    (*(Pair*)&DAT_004e2520) = FUN_0027b020("mercyFuelRod4");
}
} // namespace fn_0035eb90

namespace fn_f1ddef39 {

// 0x0035ebb0 FUN_0035ebb0 (172 B): matches/0x0035ebb0.cpp
// sym: ?FUN_0035ebb0@fn_f1ddef39@@YAXXZ
// FUN_0035ebb0 @ 0x0035ebb0
// Static init: hash the eight door/switch state names.
void FUN_0035ebb0() {
    (*(unsigned __int64*)&DAT_004e2560) = FUN_0027afb0("clean");
    (*(unsigned __int64*)&DAT_004e2568) = FUN_0027afb0("opening");
    (*(unsigned __int64*)&DAT_004e2570) = FUN_0027afb0("open");
    (*(unsigned __int64*)&DAT_004e2578) = FUN_0027afb0("closing");
    (*(unsigned __int64*)&DAT_004e2580) = FUN_0027afb0("closed");
    (*(unsigned __int64*)&DAT_004e2588) = FUN_0027afb0("on");
    (*(unsigned __int64*)&DAT_004e2590) = FUN_0027afb0("off");
    (*(unsigned __int64*)&DAT_004e2598) = FUN_0027afb0("destroyed");
}


// 0x0035ec60 FUN_0035ec60 (130 B): matches/0x0035ec60.cpp
// sym: ?FUN_0035ec60@fn_f1ddef39@@YAXXZ
// FUN_0035ec60 @ 0x0035ec60
void FUN_0035ec60()
{
    (*(Key_35ec60*)&DAT_004e25a0) = FUN_0027b020("0 - Small");
    (*(Key_35ec60*)&DAT_004e25a8) = FUN_0027b020("1 - Medium");
    (*(Key_35ec60*)&DAT_004e25b0) = FUN_0027b020("2 - Large");
    (*(Key_35ec60*)&DAT_004e25b8) = FUN_0027b020("3 - Tiny");
    (*(Key_35ec60*)&DAT_004e25c0) = FUN_0027b020("4 - Hulk Small");
    (*(Key_35ec60*)&DAT_004e25c8) = FUN_0027b020("5 - Hulk Medium");
}

} // namespace fn_f1ddef39

// 0x0035ecf0 FUN_0035ecf0 (25 B): matches/0x0035ecf0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035ecf0@fn_0035ecf0@@YAXXZ
namespace fn_0035ecf0 {

struct Handle_35ecf0 {
    int lo, hi;
};
extern "C++" __declspec(nothrow) Handle_35ecf0 __cdecl FUN_0027b020(const char*);
void __cdecl FUN_0035ecf0() {
    Handle_35ecf0 h = FUN_0027b020("golfBall_golfBall");
    (*(int*)&DAT_004e2640) = h.lo;
    (*(int*)&DAT_004e2644) = h.hi;
}
} // namespace fn_0035ecf0


// 0x0035ed10 FUN_0035ed10 (29 B): matches/0x0035ed10.cpp [wrapped: conflict: _atexit]
// sym: ?FUN_0035ed10@fn_0035ed10@@YAXXZ
namespace fn_0035ed10 {

extern "C++" __declspec(nothrow) void __cdecl FUN_00364070();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void _atexit(void (*)());
#endif

void __cdecl FUN_0023fc40(const char*, int);
struct G {
};
void __cdecl FUN_0035ed10() {
    ((owners::String_23fc40 *)&((*(G*)((char*)&DAT_004e2644 + 4))))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    _atexit(FUN_00364070);
}
} // namespace fn_0035ed10


// 0x0035ed30 FUN_0035ed30 (25 B): matches/0x0035ed30.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035ed30@fn_0035ed30@@YAXXZ
namespace fn_0035ed30 {

extern "C" struct Result_35ed30 {
    unsigned int lo;
    unsigned int hi;
};
extern "C++" __declspec(nothrow) Result_35ed30 FUN_0027b020(const char*);

void FUN_0035ed30() {
    (*(Result_35ed30*)&DAT_004e2768) = FUN_0027b020("golfBall_golfBall");
}
} // namespace fn_0035ed30

namespace fn_f1ddef39 {

// 0x0035ed50 FUN_0035ed50 (29 B): matches/0x0035ed50.cpp
// sym: ?Init@fn_f1ddef39@@YAXXZ
void Init() {
    ((owners::String_23fc40 *)&hulk_at_004e2778)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00364080);
}


// 0x0035ed70 FUN_0035ed70 (29 B): matches/0x0035ed70.cpp
// sym: ?FUN_0035ed70@fn_f1ddef39@@YAXXZ
// data: g_result = DAT_004e2770
void FUN_0035ed70() {
    (*(U64*)&DAT_004e2770) = FUN_002672f0("armory_armory", 0, 0);
}


// 0x0035ed90 FUN_0035ed90 (29 B): matches/0x0035ed90.cpp
// sym: ?InitSub@fn_f1ddef39@@YAXXZ
// data: g_sub = DAT_004e36bc
void __cdecl InitSub() {
    ((owners::String_23fc40 *)&((*(Sub*)&DAT_004e36bc)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_003640a0);
}


// 0x0035edb0 FUN_0035edb0 (32 B): matches/0x0035edb0.cpp
// sym: ?FUN_0035edb0@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035edb0() {
    (*(Allocator_35edb0*)&DAT_004e36c8).FUN_002475c0((void*)FUN_001e8800, (void*)FUN_001e8830);
    _atexit((void (*)())FUN_003640b0);
}

} // namespace fn_f1ddef39

// 0x0035edd0 FUN_0035edd0 (29 B): matches/0x0035edd0.cpp [wrapped: conflict: _atexit]
// sym: ?FUN_0035edd0@fn_0035edd0@@YAXXZ
namespace fn_0035edd0 {
// data: gSound = DAT_004e36f0

extern "C++" __declspec(nothrow) void __cdecl FUN_003640c0();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl _atexit(void (*func)(void));
#endif

struct Sound {
};
void __cdecl FUN_0035edd0() {
    ((owners::String_23fc40 *)&((*(Sound*)&DAT_004e36f0)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    _atexit(FUN_003640c0);
}
} // namespace fn_0035edd0


// 0x0035edf0 FUN_0035edf0 (25 B): matches/0x0035edf0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0035edf0@fn_0035edf0@@YAXXZ
namespace fn_0035edf0 {
// data: gPair = DAT_004e3700

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void __cdecl FUN_0035edf0() {
    (*(Pair*)&DAT_004e3700) = FUN_0027b020("golfBall_golfBall");
}
} // namespace fn_0035edf0


// 0x0035ee10 FUN_0035ee10 (29 B): matches/0x0035ee10.cpp [wrapped: same definition as 0x0035dc90 in this TU]
// sym: ?target@fn_0035ee10@@YAXXZ
namespace fn_0035ee10 {

class Obj {
  public:
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_003640d0();
void __cdecl target() {
    ((owners::String_23fc40 *)&((*(Obj*)((char*)&DAT_004e3748 + 4))))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_003640d0);
}
} // namespace fn_0035ee10

namespace fn_f1ddef39 {

// 0x0035ee30 FUN_0035ee30 (29 B): matches/0x0035ee30.cpp
// sym: ?initResource@fn_f1ddef39@@YAXXZ
// data: g_resource = DAT_004e58b8
void __cdecl initResource() {
    ((owners::String_23fc40 *)&DAT_004e58b8)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_003640e0);
}


// 0x0035ee50 FUN_0035ee50 (61 B): matches/0x0035ee50.cpp
// sym: ?FUN_0035ee50@fn_f1ddef39@@YAXXZ
// data: entries = DAT_004e37b8 (264 entries of three 8-byte objects built by 0x0027af00)
void __cdecl FUN_0035ee50() {
    Entry_35ee50* p = (Entry_35ee50*)DAT_004e37b8;
    for (int i = 264; i; --i, ++p) {
        p->a.FUN_0027af00();
        p->b.FUN_0027af00();
        p->c.FUN_0027af00();
    }
    atexit(FUN_003640f0);
}


// 0x0035ee90 FUN_0035ee90 (29 B): matches/0x0035ee90.cpp
// sym: ?FUN_0035ee90@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035ee90() {
    unsigned __int64 p = FUN_002672f0("Template", 0, 0);
    g_lo = (int)p;
    g_hi = (int)(p >> 32);
}


// 0x0035eeb0 FUN_0035eeb0 (35 B): matches/0x0035eeb0.cpp
// sym: ?FUN_0035eeb0@fn_f1ddef39@@YAXXZ
// data: the type descriptor DAT_004c8040 (typeid(...); its name() is type_info::name, 0x003469f5), result = DAT_004e58d0
void FUN_0035eeb0() {
    const char* n = DAT_004c8040.FUN_003469f5();
    unsigned __int64 r = FUN_002672f0(n, 0, 0);
    (*(unsigned int*)&DAT_004e58d0) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e58d4) = (unsigned int)(r >> 32);
}


// 0x0035eee0 FUN_0035eee0 (129 B): matches/0x0035eee0.cpp
// sym: ?FUN_0035eee0@fn_f1ddef39@@YAXXZ
// FUN_0035eee0 @ 0x0035eee0
// Static initialiser: hashes the property names into global keys.
void FUN_0035eee0()
{
    (*(unsigned __int64*)&DAT_004e5928) = FUN_002672f0("ignoredByNPCs", 0, 0);
    (*(unsigned __int64*)&DAT_004e5930) = FUN_002672f0("unclimbable", 0, 0);
    (*(unsigned __int64*)&DAT_004e5938) = FUN_002672f0("material", 0, 0);
    (*(unsigned __int64*)&DAT_004e5940) = FUN_002672f0("maxsize", 0, 0);
    (*(unsigned __int64*)&DAT_004e5948) = FUN_002672f0("propindex", 0, 0);
}

} // namespace fn_f1ddef39

// 0x0035ef70 FUN_0035ef70 (29 B): matches/0x0035ef70.cpp [wrapped: same definition as 0x0035dc90 in this TU]
// sym: ?target@fn_0035ef70@@YAXXZ
namespace fn_0035ef70 {
// data: gSound = DAT_004e5a5c

class Sound {
  public:
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364120();
void __cdecl target() {
    ((owners::String_23fc40 *)&((*(Sound*)((char*)&DAT_004e5a58 + 4))))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00364120);
}
} // namespace fn_0035ef70


// 0x0035ef90 FUN_0035ef90 (13 B): matches/0x0035ef90.cpp [wrapped: conflict: Target]
// sym: ?Target@fn_0035ef90@@YGXXZ
namespace fn_0035ef90 {
// data: g_obj_35ef90 = DAT_004e5ad0

class Obj_35ef90 {
  public:
};
void __stdcall Target() {
    ((owners::Random_22aba0 *)&((*(Obj_35ef90*)&DAT_004e5ad0)))->FUN_0022aba0(0);
}
} // namespace fn_0035ef90

namespace fn_f1ddef39 {

// 0x0035efa0 FUN_0035efa0 (11 B): matches/0x0035efa0.cpp
// sym: ?FUN_0035efa0@fn_f1ddef39@@YAXXZ
// data: gA_35efa0 = DAT_004e5acc, gB_35efa0 = DAT_004e5ad0
void FUN_0035efa0() {
    *(void**)DAT_004e5acc = ((void**)&DAT_004e5ad0);
}


// 0x0035efb0 FUN_0035efb0 (30 B): matches/0x0035efb0.cpp
// sym: ?FUN_0035efb0@fn_f1ddef39@@YAXXZ
void FUN_0035efb0() {
    unsigned long long r = FUN_002672f0((*(const void**)&DAT_004ca248), 0, 0);
    (*(unsigned int*)&DAT_004e5b68) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b6c) = (unsigned int)(r >> 32);
}


// 0x0035efd0 FUN_0035efd0 (30 B): matches/0x0035efd0.cpp
// sym: ?FUN_0035efd0@fn_f1ddef39@@YAXXZ
void FUN_0035efd0() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca24c), 0, 0);
    (*(unsigned int*)&DAT_004e5b28) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b2c) = (unsigned int)(r >> 32);
}


// 0x0035eff0 FUN_0035eff0 (30 B): matches/0x0035eff0.cpp
// sym: ?FUN_0035eff0@fn_f1ddef39@@YAXXZ
void FUN_0035eff0() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca250), 0, 0);
    (*(unsigned int*)&DAT_004e5b00) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b04) = (unsigned int)(r >> 32);
}


// 0x0035f010 FUN_0035f010 (30 B): matches/0x0035f010.cpp
// sym: ?FUN_0035f010@fn_f1ddef39@@YAXXZ
// data: g_result = DAT_004e5b48
void FUN_0035f010() {
    (*(u64*)&DAT_004e5b48) = FUN_002672f0((*(const char**)&DAT_004ca254), 0, 0);
}


// 0x0035f030 FUN_0035f030 (30 B): matches/0x0035f030.cpp
// sym: ?FUN_0035f030@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035f030() {
    (*(unsigned __int64*)&DAT_004e5b70) = FUN_002672f0((*(const char**)&DAT_004ca258), 0, 0);
}


// 0x0035f050 FUN_0035f050 (30 B): matches/0x0035f050.cpp
// sym: ?FUN_0035f050@fn_f1ddef39@@YAXXZ
// data: gInput = DAT_004ca25c, gOutput = DAT_004e5b30
void FUN_0035f050() {
    (*(unsigned __int64*)&DAT_004e5b30) = FUN_002672f0((*(const char**)&DAT_004ca25c), 0, 0);
}


// 0x0035f070 FUN_0035f070 (30 B): matches/0x0035f070.cpp
// sym: ?FUN_0035f070@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035f070() {
    (*(unsigned __int64*)&DAT_004e5ba8) = FUN_002672f0((*(const char**)&DAT_004ca260), 0, 0);
}


// 0x0035f090 FUN_0035f090 (30 B): matches/0x0035f090.cpp
// sym: ?FUN_0035f090@fn_f1ddef39@@YAXXZ
void FUN_0035f090() {
    (*(unsigned __int64*)&DAT_004e5b18) = FUN_002672f0((*(const char**)&DAT_004ca264), 0, 0);
}


// 0x0035f0b0 FUN_0035f0b0 (30 B): matches/0x0035f0b0.cpp
// sym: ?FUN_0035f0b0@fn_f1ddef39@@YAXXZ
// data: gInput = DAT_004ca268, gOutput = DAT_004e5b10
void FUN_0035f0b0() {
    (*(unsigned __int64*)&DAT_004e5b10) = FUN_002672f0((*(const char**)&DAT_004ca268), 0, 0);
}


// 0x0035f0d0 FUN_0035f0d0 (30 B): matches/0x0035f0d0.cpp
// sym: ?FUN_0035f0d0@fn_f1ddef39@@YAXXZ
// data: input = DAT_004ca26c, output = DAT_004e5b90
void __cdecl FUN_0035f0d0() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca26c), 0, 0);
    (*(unsigned int*)&DAT_004e5b90) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b94) = (unsigned int)(r >> 32);
}


// 0x0035f0f0 FUN_0035f0f0 (30 B): matches/0x0035f0f0.cpp
// sym: ?FUN_0035f0f0@fn_f1ddef39@@YAXXZ
// data: gInput = DAT_004ca270, gOutput = DAT_004e5b58
void FUN_0035f0f0() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca270), 0, 0);
    (*(unsigned int*)&DAT_004e5b58) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b5c) = (unsigned int)(r >> 32);
}


// 0x0035f110 FUN_0035f110 (30 B): matches/0x0035f110.cpp
// sym: ?FUN_0035f110@fn_f1ddef39@@YA_KXZ
// data: gLoader = DAT_004ca274, gResult = DAT_004e5b38
unsigned __int64 __cdecl FUN_0035f110() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca274), 0, 0);
    (*(unsigned int*)&DAT_004e5b38) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b3c) = (unsigned int)(r >> 32);
    return r;
}


// 0x0035f130 FUN_0035f130 (30 B): matches/0x0035f130.cpp
// sym: ?FUN_0035f130@fn_f1ddef39@@YAXXZ
// data: result = DAT_004e5b40, source = DAT_004ca278
void __cdecl FUN_0035f130() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca278), 0, 0);
    (*(unsigned int*)&DAT_004e5b40) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b44) = (unsigned int)(r >> 32);
}


// 0x0035f150 FUN_0035f150 (30 B): matches/0x0035f150.cpp
// sym: ?FUN_0035f150@fn_f1ddef39@@YAXXZ
// data: gGlobal = DAT_004ca27c
void __cdecl FUN_0035f150() {
    unsigned long long v = FUN_002672f0((*(const char**)&DAT_004ca27c), 0, 0);
    hulk_at_004e5b50 = (int)v;
    hulk_at_004e5b54 = (int)(v >> 32);
}


// 0x0035f170 FUN_0035f170 (30 B): matches/0x0035f170.cpp
// sym: ?FUN_0035f170@fn_f1ddef39@@YAXXZ
// data: gInput = DAT_004ca280 (a name pointer), gResult = DAT_004e5b08
void FUN_0035f170() {
    unsigned __int64 r = FUN_002672f0(DAT_004ca280, 0, 0);
    (*(unsigned int*)&DAT_004e5b08) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b0c) = (unsigned int)(r >> 32);
}


// 0x0035f190 FUN_0035f190 (30 B): matches/0x0035f190.cpp
// sym: ?FUN_0035f190@fn_f1ddef39@@YAXXZ
void FUN_0035f190() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca284), 0, 0);
    (*(unsigned int*)&DAT_004e5b80) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b84) = (unsigned int)(r >> 32);
}


// 0x0035f1b0 FUN_0035f1b0 (30 B): matches/0x0035f1b0.cpp
// sym: ?FUN_0035f1b0@fn_f1ddef39@@YAXXZ
// data: gInput = DAT_004ca288 (a name pointer), gResult = DAT_004e5b20
void FUN_0035f1b0() {
    (*(unsigned __int64*)&DAT_004e5b20) = FUN_002672f0(DAT_004ca288, 0, 0);
}


// 0x0035f1d0 FUN_0035f1d0 (30 B): matches/0x0035f1d0.cpp
// sym: ?FUN_0035f1d0@fn_f1ddef39@@YA_JXZ
long long FUN_0035f1d0() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca28c), 0, 0);
    (*(unsigned int*)&DAT_004e5ba0) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5ba4) = (unsigned int)(r >> 32);
    return r;
}


// 0x0035f1f0 FUN_0035f1f0 (30 B): matches/0x0035f1f0.cpp
// sym: ?FUN_0035f1f0@fn_f1ddef39@@YAXXZ
// data: gInput = DAT_004ca290, gResult = DAT_004e5b78
void FUN_0035f1f0() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca290), 0, 0);
    (*(unsigned int*)&DAT_004e5b78) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b7c) = (unsigned int)(r >> 32);
}


// 0x0035f210 FUN_0035f210 (30 B): matches/0x0035f210.cpp
// sym: ?FUN_0035f210@fn_f1ddef39@@YAXXZ
// data: gInput = DAT_004ca294, gOutput = DAT_004e5b60
void FUN_0035f210() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca294), 0, 0);
    (*(unsigned int*)&DAT_004e5b60) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b64) = (unsigned int)(r >> 32);
}


// 0x0035f230 FUN_0035f230 (30 B): matches/0x0035f230.cpp
// sym: ?FUN_0035f230@fn_f1ddef39@@YAXXZ
// data: gValue = DAT_004ca298 (a name pointer: const char*), result = DAT_004e5b98
void FUN_0035f230() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca298), 0, 0);
    (*(unsigned int*)&DAT_004e5b98) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b9c) = (unsigned int)(r >> 32);
}

} // namespace fn_f1ddef39

// 0x0035f250 FUN_0035f250 (30 B): matches/0x0035f250.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?FUN_0035f250@fn_0035f250@@YAXXZ
namespace fn_0035f250 {
// data: result = DAT_004e5b88

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_002672f0(const char*, int, int);
void FUN_0035f250() {
    (*(__int64*)&DAT_004e5b88) = FUN_002672f0((*(char**)&DAT_004ca29c), 0, 0);
}
} // namespace fn_0035f250


// 0x0035f2c0 FUN_0035f2c0 (29 B): matches/0x0035f2c0.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?init@fn_0035f2c0@@YAXXZ
namespace fn_0035f2c0 {
// data: result = DAT_004e5ce8

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_002672f0(const char*, int, int);
void init() {
    (*(__int64*)&DAT_004e5ce8) = FUN_002672f0("HalSystem", 0, 0);
}
} // namespace fn_0035f2c0

namespace fn_f1ddef39 {

// 0x0035f2e0 FUN_0035f2e0 (29 B): matches/0x0035f2e0.cpp
// sym: ?FUN_0035f2e0@fn_f1ddef39@@YAXXZ
void FUN_0035f2e0() {
    unsigned __int64 v = FUN_002672f0("Runtime_Hal", 0, 0);
    g_lo = (int)v;
    g_hi = (int)(v >> 32);
}


// 0x0035f300 FUN_0035f300 (22 B): matches/0x0035f300.cpp
// sym: ?FUN_0035f300@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035f300() {
    (*(MixType_35f300*)&DAT_004e5cf8).FUN_00242010();
    atexit((void (*)())(hulk_ulongptr)FUN_003641a0);
}

} // namespace fn_f1ddef39

// 0x0035f320 FUN_0035f320 (88 B): matches/0x0035f320.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?FUN_0035f320@fn_0035f320@@YAXXZ
namespace fn_0035f320 {

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_002672f0(const char*, int, int);
struct Registry {
    char space[0x80];
    void FUN_002584d0(const __int64*, const __int64*, int, int);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl _atexit(void(__cdecl*)());
#endif

extern "C" void FUN_00364150();
void __cdecl FUN_0035f320() {
    HULK_SIZE32(AudioMixBuss, 0x2c);
    __int64 mixBuss = FUN_002672f0("MixBuss", 0, 0);
    __int64 dataMix = FUN_002672f0("Data_Mix", 0, 0);
    (*(Registry*)((char*)&DAT_004e5d68)).FUN_002584d0(&dataMix, &mixBuss, (int)sizeof(AudioMixBuss), (int)__alignof(AudioMixBuss));
    _atexit(FUN_00364150);
}
} // namespace fn_0035f320


// 0x0035f380 FUN_0035f380 (88 B): matches/0x0035f380.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?target@fn_0035f380@@YAXXZ
namespace fn_0035f380 {
// data: Mixer = DAT_004290e4, Runtime_Mix = DAT_004290d8

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364160();
class Manager_35f380 {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
Manager_35f380 gManager_35f380;
void target() {
    HULK_SIZE32(AudioMixer, 0x30);
    __int64 a = FUN_002672f0(((char*)&DAT_004290e4), 0, 0);
    __int64 b = FUN_002672f0(((char*)&DAT_004290d8), 0, 0);
    gManager_35f380.FUN_002584d0(&b, &a, (int)sizeof(AudioMixer), (int)__alignof(AudioMixer));
    atexit(FUN_00364160);
}
} // namespace fn_0035f380


// 0x0035f3e0 FUN_0035f3e0 (88 B): matches/0x0035f3e0.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?init@fn_0035f3e0@@YAXXZ
namespace fn_0035f3e0 {
// data: registry_35f3e0 = DAT_004e5df8

typedef unsigned __int64 U64_35f3e0;
extern U64_35f3e0 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364170();
class Registry_35f3e0 {
  public:
    void FUN_002584d0(U64_35f3e0*, U64_35f3e0*, int, int);
};
void init() {
    HULK_SIZE32(AudioMixerMix, 0x38);
    U64_35f3e0 a = FUN_002672f0("MixerMix", 0, 0);
    U64_35f3e0 b = FUN_002672f0("Runtime_Mix", 0, 0);
    (*(Registry_35f3e0*)&DAT_004e5df8).FUN_002584d0(&b, &a, (int)sizeof(AudioMixerMix), (int)__alignof(AudioMixerMix));
    atexit(FUN_00364170);
}
} // namespace fn_0035f3e0


// 0x0035f440 FUN_0035f440 (88 B): matches/0x0035f440.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?FUN_0035f440@fn_0035f440@@YAXXZ
namespace fn_0035f440 {
// data: mixerName = DAT_004290f8, registry = DAT_004e5e40, runtimeName = DAT_004290d8

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364180();
class Registry {
  public:
    void FUN_002584d0(const __int64*, const __int64*, int, int);
};
void __cdecl FUN_0035f440() {
    HULK_SIZE32(AudioMixerFader, 0x1c);
    __int64 mixer = FUN_002672f0(DAT_004290f8, 0, 0);
    __int64 runtime = FUN_002672f0(DAT_004290d8, 0, 0);
    (*(Registry*)((char*)&DAT_004e5e40)).FUN_002584d0(&runtime, &mixer, (int)sizeof(AudioMixerFader), (int)__alignof(AudioMixerFader));
    atexit(FUN_00364180);
}
} // namespace fn_0035f440


// 0x0035f4a0 FUN_0035f4a0 (88 B): matches/0x0035f4a0.cpp [wrapped: same definition as 0x0035d560 in this TU]
// sym: ?init@fn_0035f4a0@@YAXXZ
namespace fn_0035f4a0 {
// data: globalObj = DAT_004e5e88

typedef unsigned __int64 U64;
extern "C++" __declspec(nothrow) U64 __cdecl FUN_002672f0(const char*, int, int);
struct Obj {
    void FUN_002584d0(U64*, U64*, int, int);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364190();
void init() {
    HULK_SIZE32(AudioMixerBuss, 0x28);
    U64 a = FUN_002672f0("MixerBuss", 0, 0);
    U64 b = FUN_002672f0("Runtime_Mix", 0, 0);
    (*(Obj*)&DAT_004e5e88).FUN_002584d0(&b, &a, (int)sizeof(AudioMixerBuss), (int)__alignof(AudioMixerBuss));
    atexit(FUN_00364190);
}
} // namespace fn_0035f4a0


// 0x0035f500 FUN_0035f500 (22 B): matches/0x0035f500.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_0035f500@fn_0035f500@@YAXXZ
namespace fn_0035f500 {

class Obj {
  public:
    void FUN_002455e0();
    Obj();
    ~Obj();
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

void __cdecl FUN_003641b0() {
    (*(Obj*)&DAT_004e5f18).~Obj();
}
void FUN_0035f500() {
    ((Obj*)&DAT_004e5f18)->FUN_002455e0();
    atexit(FUN_003641b0);
}
} // namespace fn_0035f500


// 0x0035f520 FUN_0035f520 (12 B): matches/0x0035f520.cpp [wrapped: same definition as 0x0035eaf0 in this TU]
// sym: ?Register@fn_0035f520@@YAXXZ
namespace fn_0035f520 {
void FUN_003641c0();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl _atexit(void(__cdecl* f)());
#endif


void Register() {
    _atexit(FUN_003641c0);
}
} // namespace fn_0035f520

namespace fn_f1ddef39 {

// 0x0035f530 FUN_0035f530 (12 B): matches/0x0035f530.cpp
// sym: ?FUN_0035f530@fn_f1ddef39@@YAXXZ
extern void __cdecl FUN_0035f530() {
    atexit((void (*)(void))FUN_003641d0);
}

} // namespace fn_f1ddef39

// 0x0035f540 FUN_0035f540 (29 B): matches/0x0035f540.cpp [wrapped: conflict: FUN_002672f0; Pair]
// sym: ?FUN_0035f540@fn_0035f540@@YAXXZ
namespace fn_0035f540 {
// data: gPair = DAT_004e5f88

struct Pair {
    int a, b;
};
extern Pair __cdecl FUN_002672f0(const char*, int, int);
void FUN_0035f540() {
    (*(Pair*)&DAT_004e5f88) = FUN_002672f0("Unknown", 0, 0);
}
} // namespace fn_0035f540


// 0x0035f560 FUN_0035f560 (29 B): matches/0x0035f560.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?FUN_0035f560@fn_0035f560@@YAXXZ
namespace fn_0035f560 {
// data: gPair = DAT_004e5f90

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_002672f0(const char*, int, int);
void FUN_0035f560() {
    (*(Pair*)&DAT_004e5f90) = FUN_002672f0("Unknown", 0, 0);
}
} // namespace fn_0035f560


// 0x0035f580 FUN_0035f580 (91 B): matches/0x0035f580.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?target@fn_0035f580@@YAXXZ
namespace fn_0035f580 {
// data: gManager_35f580 = DAT_004e5fa8

extern "C++" __declspec(nothrow) __int64 FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_003641e0();
struct Manager_35f580 {
    void FUN_002584d0(__int64*, __int64*, int, int);
};
void __cdecl target() {
    HULK_SIZE32(AudioSeqPlayer, 0xb8);
    __int64 a = FUN_002672f0("SeqPlayer", 0, 0);
    __int64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Manager_35f580*)&DAT_004e5fa8).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqPlayer), (int)__alignof(AudioSeqPlayer));
    atexit(FUN_003641e0);
}
} // namespace fn_0035f580

namespace fn_f1ddef39 {

// 0x0035f5e0 FUN_0035f5e0 (88 B): matches/0x0035f5e0.cpp
// sym: ?FUN_0035f5e0@fn_f1ddef39@@YAXXZ
// data: sequenceName = DAT_00429270, trackName = DAT_00429290
void __cdecl FUN_0035f5e0() {
    HULK_SIZE32(AudioSeqPlayerTrack, 0x20);
    __int64 track = FUN_002672f0(((char*)&DAT_00429290), 0, 0);
    __int64 sequence = FUN_002672f0(((char*)&DAT_00429270), 0, 0);
    registry.FUN_002584d0(&sequence, &track, (int)sizeof(AudioSeqPlayerTrack), (int)__alignof(AudioSeqPlayerTrack));
    atexit(cleanup);
}


// 0x0035f640 FUN_0035f640 (88 B): matches/0x0035f640.cpp
// sym: ?function@fn_f1ddef39@@YAXXZ
// data: name1 = DAT_004292a0, name2 = DAT_00429270, registry = DAT_004e6038
void function() {
    HULK_SIZE32(AudioSeqPlayerTrackChannel, 0x40);
    unsigned __int64 a = FUN_002672f0(DAT_004292a0, 0, 0);
    unsigned __int64 b = FUN_002672f0(DAT_00429270, 0, 0);
    (*(Registry*)((char*)&DAT_004e6038)).FUN_002584d0((__int64*)&b, (__int64*)&a, (int)sizeof(AudioSeqPlayerTrackChannel), (int)__alignof(AudioSeqPlayerTrackChannel));
    atexit(FUN_00364200);
}

} // namespace fn_f1ddef39

// 0x0035f6a0 FUN_0035f6a0 (88 B): matches/0x0035f6a0.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?init@fn_0035f6a0@@YAXXZ
namespace fn_0035f6a0 {
// data: busName = DAT_004292b8, registry = DAT_004e6080, seqName = DAT_00429270

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_002672f0(const char*, int, int);
class Registry {
  public:
    void FUN_002584d0(Pair*, Pair*, int, int);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364210();
void __cdecl init() {
    HULK_SIZE32(AudioSeqPlayerBuss, 0x8);
    Pair a = FUN_002672f0(DAT_004292b8, 0, 0);
    Pair b = FUN_002672f0(DAT_00429270, 0, 0);
    (*(Registry*)&DAT_004e6080).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqPlayerBuss), (int)__alignof(AudioSeqPlayerBuss));
    atexit(FUN_00364210);
}
} // namespace fn_0035f6a0


// 0x0035f700 FUN_0035f700 (88 B): matches/0x0035f700.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?init@fn_0035f700@@YAXXZ
namespace fn_0035f700 {
// data: reg = DAT_004e60c8

typedef unsigned __int64 U64;
extern U64 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364220();
class Registry {
  public:
    void FUN_002584d0(const U64*, const U64*, int, int);
};
void init() {
    HULK_SIZE32(AudioSeqPlayerLayer, 0x78);
    U64 a = FUN_002672f0("SeqPlayerLayer", 0, 0);
    U64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e60c8).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqPlayerLayer), (int)__alignof(AudioSeqPlayerLayer));
    atexit(FUN_00364220);
}
} // namespace fn_0035f700


// 0x0035f760 FUN_0035f760 (88 B): matches/0x0035f760.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?FUN_0035f760@fn_0035f760@@YAXXZ
namespace fn_0035f760 {
// data: registry = DAT_004e6110

typedef unsigned __int64 U64;
extern U64 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364230();
class Registry {
  public:
    void FUN_002584d0(U64*, U64*, int, int);
};
void __cdecl FUN_0035f760() {
    HULK_SIZE32(AudioChannelVolumeArray, 0x40);
    U64 x = FUN_002672f0("ChannelVolumeArray", 0, 0);
    U64 y = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e6110).FUN_002584d0(&y, &x, (int)sizeof(AudioChannelVolumeArray), (int)__alignof(AudioChannelVolumeArray));
    atexit(FUN_00364230);
}
} // namespace fn_0035f760


// 0x0035f7c0 FUN_0035f7c0 (91 B): matches/0x0035f7c0.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?target@fn_0035f7c0@@YAXXZ
namespace fn_0035f7c0 {
// data: manager_35f7c0 = DAT_004e6158

typedef unsigned __int64 U64_35f7c0;
extern "C++" __declspec(nothrow) U64_35f7c0 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364240();
class Manager_35f7c0 {
  public:
    void FUN_002584d0(U64_35f7c0*, U64_35f7c0*, int, int);
};
void __cdecl target() {
    HULK_SIZE32(AudioChannelSendVolumeArray, 0x100);
    U64_35f7c0 a = FUN_002672f0("ChannelSendVolumeArray", 0, 0);
    U64_35f7c0 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Manager_35f7c0*)((char*)&DAT_004e6158)).FUN_002584d0(&b, &a, (int)sizeof(AudioChannelSendVolumeArray), (int)__alignof(AudioChannelSendVolumeArray));
    atexit(FUN_00364240);
}
} // namespace fn_0035f7c0


// 0x0035f870 FUN_0035f870 (91 B): matches/0x0035f870.cpp [wrapped: conflict: FUN_002672f0; cleanup]
// sym: ?FUN_0035f870@fn_0035f870@@YAXXZ
namespace fn_0035f870 {
// data: manager_35f870 = DAT_004e61a0

typedef unsigned __int64 U64_35f870;
extern U64_35f870 __cdecl FUN_002672f0(const char*, int, int);
struct Manager_35f870 {
    void FUN_002584d0(U64_35f870*, U64_35f870*, int, int);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern void __cdecl cleanup_00364250();
void __cdecl FUN_0035f870() {
    HULK_SIZE32(AudioHalStreamPlayer, 0xd8);
    U64_35f870 first = FUN_002672f0("HalStreamPlayer", 0, 0);
    U64_35f870 second = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Manager_35f870*)&DAT_004e61a0).FUN_002584d0(&second, &first, (int)sizeof(AudioHalStreamPlayer), (int)__alignof(AudioHalStreamPlayer));
    atexit(cleanup_00364250);
}
} // namespace fn_0035f870

namespace fn_f1ddef39 {

// 0x0035f8d0 FUN_0035f8d0 (12 B): matches/0x0035f8d0.cpp
// sym: ?FUN_0035f8d0@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035f8d0(void) {
    atexit(FUN_00364260);
}

} // namespace fn_f1ddef39

// 0x0035f8e0 FUN_0035f8e0 (29 B): matches/0x0035f8e0.cpp [wrapped: same definition as 0x0035d560 in this TU]
// sym: ?init@fn_0035f8e0@@YAXXZ
namespace fn_0035f8e0 {
// data: gName = DAT_004e61f0

class Name {
  public:
    Name(const char*, int);
    ~Name();
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364270();
void init() {
    ((owners::String_23fc40 *)&DAT_004e61f0)->FUN_0023fc40("?Name?", (hulk_intptr)0);
    atexit(FUN_00364270);
}
} // namespace fn_0035f8e0

namespace fn_f1ddef39 {

// 0x0035f900 FUN_0035f900 (88 B): matches/0x0035f900.cpp
// sym: ?FUN_0035f900@fn_f1ddef39@@YAXXZ
// data: holder = DAT_004e6208
void __cdecl FUN_0035f900() {
    HULK_SIZE32(AudioHalPositionalInfo, 0x64);
    I64 a = FUN_002672f0("HalPositionalInfo", 0, 0);
    I64 b = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Holder*)&DAT_004e6208).FUN_002584d0(&b, &a, (int)sizeof(AudioHalPositionalInfo), (int)__alignof(AudioHalPositionalInfo));
    atexit(cleanup);
}

} // namespace fn_f1ddef39

// 0x0035f960 FUN_0035f960 (88 B): matches/0x0035f960.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?FUN_0035f960@fn_0035f960@@YAXXZ
namespace fn_0035f960 {
// data: registry = DAT_004e6250

typedef unsigned __int64 U64;
extern U64 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364290();
class Registry {
  public:
    void FUN_002584d0(U64*, U64*, int, int);
};
void __cdecl FUN_0035f960() {
    U64 a = FUN_002672f0("HalListener", 0, 0);
    U64 b = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Registry*)((char*)&DAT_004e6250)).FUN_002584d0(&b, &a, 64, 4);
    atexit(FUN_00364290);
}
} // namespace fn_0035f960


// 0x0035f9c0 FUN_0035f9c0 (88 B): matches/0x0035f9c0.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?target@fn_0035f9c0@@YAXXZ
namespace fn_0035f9c0 {
// data: label = DAT_004293a4, registry = DAT_004e62d8

typedef __int64 I64;
extern "C++" __declspec(nothrow) I64 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_003642a0();
class Registry {
  public:
    void FUN_002584d0(I64*, I64*, int, int);
};
void __cdecl target() {
    HULK_SIZE32(OmEntityLoader, 0xc);
    I64 a = FUN_002672f0(((char*)&DAT_004293a4), 0, 0);
    I64 b = FUN_002672f0(((char*)&DAT_004293a4), 0, 0);
    (*(Registry*)&DAT_004e62d8).FUN_002584d0(&b, &a, (int)sizeof(OmEntityLoader), (int)__alignof(OmEntityLoader));
    atexit(FUN_003642a0);
}
} // namespace fn_0035f9c0

namespace fn_f1ddef39 {

// 0x0035fa20 FUN_0035fa20 (29 B): matches/0x0035fa20.cpp
// sym: ?initEffect@fn_f1ddef39@@YAXXZ
// data: gEffect = DAT_004e6360 (records.h), gName = DAT_00429490
void __cdecl initEffect() {
    (*(MetaType_35fa20*)&DAT_004e6360).FUN_0025fa00(DAT_00429490, 0);
    atexit(FUN_003642b0);
}


// 0x0035fa40 FUN_0035fa40 (29 B): matches/0x0035fa40.cpp
// sym: ?RegisterEffect@fn_f1ddef39@@YAXXZ
// data: gRegistry = DAT_004e6394
void __cdecl RegisterEffect() {
    (*(Registry*)&DAT_004e6394).FUN_0025fa00("ListenerEffectWin32", 0);
    _atexit((AtExitFn)FUN_003642c0);
}

} // namespace fn_f1ddef39

// 0x0035fa60 FUN_0035fa60 (29 B): matches/0x0035fa60.cpp [wrapped: same definition as 0x0035d560 in this TU]
// sym: ?init@fn_0035fa60@@YAXXZ
namespace fn_0035fa60 {
// data: gEffect = DAT_004e63c8

class Effect {
  public:
    void FUN_0025fa00(const char*, int);
    Effect(const char*, int);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_003642d0();
void init() {
    ((Effect*)&DAT_004e63c8)->FUN_0025fa00("ListenerEffectPs2", 0);
    atexit(FUN_003642d0);
}
} // namespace fn_0035fa60

namespace fn_f1ddef39 {

// 0x0035fa80 FUN_0035fa80 (29 B): matches/0x0035fa80.cpp
// sym: ?FUN_0035fa80@fn_f1ddef39@@YAXXZ
// data: the ListenerEffectGc meta type DAT_004e63fc
void __cdecl FUN_0035fa80() {
    (*(Obj*)&DAT_004e63fc).FUN_0025fa00("ListenerEffectGc", 0);
    atexit(FUN_003642e0);
}


// 0x0035faa0 FUN_0035faa0 (29 B): matches/0x0035faa0.cpp
// sym: ?FUN_0035faa0@fn_f1ddef39@@YAXXZ
// data: globalObj = DAT_004e6430, name = DAT_004295d0
void __cdecl FUN_0035faa0() {
    (*(MetaType_35faa0*)&DAT_004e6430).FUN_0025fa00(DAT_004295d0, 0);
    atexit(FUN_003642f0);
}


// 0x0035fac0 FUN_0035fac0 (22 B): matches/0x0035fac0.cpp
// sym: ?FUN_0035fac0@fn_f1ddef39@@YAXXZ
// data: g_mgr_35fac0 = DAT_004e6468
void FUN_0035fac0() {
    (*(ListenerEffectXBoxType_35fac0*)&DAT_004e6468).FUN_0024d7d0();
    atexit(FUN_00364340);
}


// 0x0035fae0 FUN_0035fae0 (22 B): matches/0x0035fae0.cpp
// sym: ?FUN_0035fae0@fn_f1ddef39@@YAXXZ
// data: hulk_at_004e64d8 = DAT_004e64d8
void __cdecl FUN_0035fae0() {
    ((ListenerEffectGcType_nv_35fae0*)(((audio::ListenerEffectGcType*)(((audio::ListenerEffectGcType*)((hulk_intptr)((char*)&DAT_004e64d8)))))))->FUN_0024d8e0();
    atexit((void (*)(void))FUN_00364300);
}


// 0x0035fb00 FUN_0035fb00 (22 B): matches/0x0035fb00.cpp
// sym: ?FUN_0035fb00@fn_f1ddef39@@YAXXZ
void FUN_0035fb00() {
    (*(ListenerEffectPs2Type_35fb00*)&DAT_004e6548).FUN_0024d9e0();
    atexit(FUN_00364310);
}

} // namespace fn_f1ddef39

// 0x0035fb40 FUN_0035fb40 (22 B): matches/0x0035fb40.cpp [wrapped: conflict: _atexit]
// sym: ?FUN_0035fb40@fn_0035fb40@@YAXXZ
namespace fn_0035fb40 {

extern "C++" __declspec(nothrow) void __cdecl FUN_00364330();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern void __cdecl _atexit(void (*)(void));
#endif

class ListenerEffectPspType_35fb40 {
  public:
    void FUN_0024dbe0();
};
void __cdecl FUN_0035fb40() {
    (*(ListenerEffectPspType_35fb40*)&DAT_004e6628).FUN_0024dbe0();
    _atexit(FUN_00364330);
}
} // namespace fn_0035fb40


// 0x0035fb60 FUN_0035fb60 (29 B): matches/0x0035fb60.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?FUN_0035fb60@fn_0035fb60@@YAXXZ
namespace fn_0035fb60 {

extern "C" struct Pairs {
    int a;
    int b;
};
extern Pairs __cdecl FUN_002672f0(const char* s, int a, int b);
void __cdecl FUN_0035fb60() {
    Pairs r = FUN_002672f0("Template", 0, 0);
    (*(int*)&DAT_004e6320) = r.a;
    (*(int*)&DAT_004e6324) = r.b;
}
} // namespace fn_0035fb60

namespace fn_f1ddef39 {

// 0x0035fb80 FUN_0035fb80 (35 B): matches/0x0035fb80.cpp
// sym: ?FUN_0035fb80@fn_f1ddef39@@YAXXZ
// data: the type descriptor DAT_004cc58c (typeid(...); its name() is type_info::name, 0x003469f5), result = DAT_004e6328
void FUN_0035fb80() {
    const char* x = DAT_004cc58c.FUN_003469f5();
    _ReadWriteBarrier();
    unsigned __int64 r = FUN_002672f0(x, 0, 0);
    (*(unsigned int*)&DAT_004e6328) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e632c) = (unsigned int)(r >> 32);
}


// 0x0035fbb0 FUN_0035fbb0 (29 B): matches/0x0035fbb0.cpp
// sym: ?FUN_0035fbb0@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035fbb0() {
    (*(unsigned long long*)&DAT_004e6330) = FUN_002672f0("Template", 0, 0);
}


// 0x0035fbd0 FUN_0035fbd0 (35 B): matches/0x0035fbd0.cpp
// sym: ?FUN_0035fbd0@fn_f1ddef39@@YAXXZ
// data: the type descriptor DAT_004cc5b8 (typeid(...); its name() is type_info::name, 0x003469f5), result = DAT_004e6338
void FUN_0035fbd0() {
    const char* n = DAT_004cc5b8.FUN_003469f5();
    unsigned __int64 r = FUN_002672f0(n, 0, 0);
    (*(unsigned int*)&DAT_004e6338) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e633c) = (unsigned int)(r >> 32);
}

} // namespace fn_f1ddef39

// 0x0035fc00 FUN_0035fc00 (29 B): matches/0x0035fc00.cpp [wrapped: conflict: FUN_002672f0; Pair]
// sym: ?FUN_0035fc00@fn_0035fc00@@YAXXZ
namespace fn_0035fc00 {

struct Pair {
    int a, b;
};
extern Pair __cdecl FUN_002672f0(const char*, int, int);
void FUN_0035fc00() {
    (*(Pair*)&DAT_004e6340) = FUN_002672f0("Template", 0, 0);
}
} // namespace fn_0035fc00

namespace fn_f1ddef39 {

// 0x0035fc20 FUN_0035fc20 (35 B): matches/0x0035fc20.cpp
// sym: ?FUN_0035fc20@fn_f1ddef39@@YAXXZ
// data: the type descriptor DAT_004cc38c (typeid(...); its name() is type_info::name, 0x003469f5), result = DAT_004e6348
void FUN_0035fc20() {
    const char* n = DAT_004cc38c.FUN_003469f5();
    unsigned __int64 r = FUN_002672f0(n, 0, 0);
    (*(unsigned int*)&DAT_004e6348) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e634c) = (unsigned int)(r >> 32);
}


// 0x0035fc50 FUN_0035fc50 (29 B): matches/0x0035fc50.cpp
// sym: ?FUN_0035fc50@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035fc50() {
    unsigned __int64 p = FUN_002672f0("Template", 0, 0);
    (*(unsigned int*)&DAT_004e6350) = (unsigned int)p;
    (*(unsigned int*)&DAT_004e6354) = (unsigned int)(p >> 32);
}


// 0x0035fc70 FUN_0035fc70 (35 B): matches/0x0035fc70.cpp
// sym: ?FUN_0035fc70@fn_f1ddef39@@YAXXZ
// data: the type descriptor DAT_004cc3b0 (typeid(...); its name() is type_info::name, 0x003469f5), result = DAT_004e6358
void FUN_0035fc70() {
    const char* id = DAT_004cc3b0.FUN_003469f5();
    unsigned __int64 r = FUN_002672f0(id, 0, 0);
    (*(unsigned int*)&DAT_004e6358) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e635c) = (unsigned int)(r >> 32);
}


// 0x0035fca0 FUN_0035fca0 (22 B): matches/0x0035fca0.cpp
// sym: ?FUN_0035fca0@fn_f1ddef39@@YAXXZ
void FUN_0035fca0() {
    gObj.FUN_0024e670();
    atexit(FUN_00364350);
}

} // namespace fn_f1ddef39

// 0x0035fd10 FUN_0035fd10 (88 B): matches/0x0035fd10.cpp [wrapped: conflict: FUN_002672f0; cleanup]
// sym: ?target@fn_0035fd10@@YAXXZ
namespace fn_0035fd10 {
// data: name1 = DAT_004299d4, name2 = DAT_00429270, registry = DAT_004e6700

typedef unsigned __int64 U64;
extern U64 __cdecl FUN_002672f0(const char*, int, int);
class Registry {
  public:
    void FUN_002584d0(U64*, U64*, int, int);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern void __cdecl cleanup_00364360();
void __cdecl target() {
    HULK_SIZE32(AudioSeqActionChannelSendVolumes, 0x10);
    U64 a = FUN_002672f0(DAT_004299d4, 0, 0);
    U64 b = FUN_002672f0(DAT_00429270, 0, 0);
    (*(Registry*)&DAT_004e6700).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqActionChannelSendVolumes), (int)__alignof(AudioSeqActionChannelSendVolumes));
    atexit(cleanup_00364360);
}
} // namespace fn_0035fd10

namespace fn_f1ddef39 {

// 0x0035fd70 FUN_0035fd70 (21 B): matches/0x0035fd70.cpp
// sym: ?FUN_0035fd70@fn_f1ddef39@@YAXXZ
void __cdecl FUN_0035fd70(void) {
    (*(int*)&DAT_004e6748) = FUN_002673a0("ChannelSendVolumeFade", 0);
}


// 0x0035fd90 FUN_0035fd90 (22 B): matches/0x0035fd90.cpp
// sym: ?FUN_0035fd90@fn_f1ddef39@@YAXXZ
// data: gThing = DAT_004e6750
void FUN_0035fd90() {
    (*(Thing*)((char*)&DAT_004e6750)).FUN_0024ed10();
    atexit(FUN_00364380);
}

} // namespace fn_f1ddef39

// 0x0035fdb0 FUN_0035fdb0 (88 B): matches/0x0035fdb0.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?target@fn_0035fdb0@@YAXXZ
namespace fn_0035fdb0 {
// data: registry = DAT_004e67b8

typedef unsigned __int64 U64;
extern U64 __cdecl FUN_002672f0(const char*, int, int);
class Registry {
  public:
    void FUN_002584d0(U64*, U64*, int, int);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

void __cdecl FUN_00364370();
void __cdecl target() {
    HULK_SIZE32(AudioChannelSendVolumeFadeBehaviour, 0x24);
    U64 a = FUN_002672f0("ChannelSendVolumeFadeBehaviour", 0, 0);
    U64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e67b8).FUN_002584d0(&b, &a, (int)sizeof(AudioChannelSendVolumeFadeBehaviour), (int)__alignof(AudioChannelSendVolumeFadeBehaviour));
    atexit(FUN_00364370);
}
} // namespace fn_0035fdb0


// 0x0035fe60 FUN_0035fe60 (88 B): matches/0x0035fe60.cpp [wrapped: same definition as 0x0035dc90 in this TU]
// sym: ?target@fn_0035fe60@@YAXXZ
namespace fn_0035fe60 {
// data: first = DAT_00429aac, registry = DAT_004e6800, second = DAT_00429270

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

typedef __int64 I64;

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364390();
class Registry {
  public:
    void FUN_002584d0(I64*, I64*, int, int);
};
void __cdecl target() {
    HULK_SIZE32(AudioSeqActionChannelSends, 0x10);
    I64 a = FUN_002672f0(DAT_00429aac, 0, 0);
    I64 b = FUN_002672f0(DAT_00429270, 0, 0);
    (*(Registry*)&DAT_004e6800).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqActionChannelSends), (int)__alignof(AudioSeqActionChannelSends));
    atexit(FUN_00364390);
}
} // namespace fn_0035fe60
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0035fec0 FUN_0035fec0 (22 B): matches/0x0035fec0.cpp [wrapped: same definition as 0x0035d560 in this TU]
// sym: ?init@fn_0035fec0@@YAXXZ
namespace fn_0035fec0 {
// data: gThing = DAT_004e6848

class Thing {
  public:
    void FUN_0024f950();
    Thing();
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_003643a0();
void init() {
    ((Thing*)((char*)&DAT_004e6848))->FUN_0024f950();
    atexit(FUN_003643a0);
}
} // namespace fn_0035fec0

namespace fn_f1ddef39 {

// 0x0035ff30 FUN_0035ff30 (88 B): matches/0x0035ff30.cpp
// sym: ?FUN_0035ff30@fn_f1ddef39@@YAXXZ
// data: manager = DAT_004e68b0, runtimeSequence = DAT_00429270, seqCondition = DAT_00429b54
void __cdecl FUN_0035ff30() {
    HULK_SIZE32(AudioSeqCommandCondition, 0x10);
    __int64 first = FUN_002672f0(((char*)&DAT_00429b54), 0, 0);
    __int64 second = FUN_002672f0(((char*)&DAT_00429270), 0, 0);
    (*(Manager*)&DAT_004e68b0).FUN_002584d0(&second, &first, (int)sizeof(AudioSeqCommandCondition), (int)__alignof(AudioSeqCommandCondition));
    atexit(FUN_003643b0);
}


// 0x0035ff90 FUN_0035ff90 (22 B): matches/0x0035ff90.cpp
// sym: _FUN_0035ff90
// data: hulk_at_004e68f8 = DAT_004e68f8
extern "C" void __cdecl FUN_0035ff90() {
    ((Holder_35ff90*)((hulk_intptr)((char*)&DAT_004e68f8)))->FUN_0024fd10();
    atexit(FUN_003643c0);
}

} // namespace fn_f1ddef39

// 0x00360000 FUN_00360000 (88 B): matches/0x00360000.cpp [wrapped: conflict: Pair; Reg]
// sym: ?target@fn_00360000@@YAXXZ
namespace fn_00360000 {

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

struct Pair {
    unsigned __int64 v;
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_003643d0();
class Reg {
  public:
    void FUN_002584d0(Pair*, Pair*, int, int);
};
void __cdecl target() {
    HULK_SIZE32(AudioSeqActionWait, 0x10);
    Pair a, b;
    a.v = FUN_002672f0("SeqActionWait", 0, 0);
    b.v = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Reg*)((char*)&DAT_004e6960)).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqActionWait), (int)__alignof(AudioSeqActionWait));
    atexit(FUN_003643d0);
}
} // namespace fn_00360000
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f1ddef39 {

// 0x00360060 FUN_00360060 (21 B): matches/0x00360060.cpp
// sym: ?FUN_00360060@fn_f1ddef39@@YAXXZ
void FUN_00360060() {
    *(int*)((hulk_intptr)DAT_004e69a8) = FUN_002673a0("ChannelVolumeFade", 0);
}

} // namespace fn_f1ddef39

// 0x00360080 FUN_00360080 (22 B): matches/0x00360080.cpp [wrapped: same definition as 0x0035e560 in this TU]
// sym: ?Target@fn_00360080@@YAXXZ
namespace fn_00360080 {


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void _atexit(void (*)(void));
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_003643e0(void);
class SeqEventWaitType_360080 {
  public:
    void FUN_00250290();
};
void __cdecl Target() {
    (*(SeqEventWaitType_360080*)&DAT_004e69b0).FUN_00250290();
    _atexit(FUN_003643e0);
}
} // namespace fn_00360080


// 0x003600f0 FUN_003600f0 (88 B): matches/0x003600f0.cpp [wrapped: same definition as 0x0035d560 in this TU]
// sym: ?init@fn_003600f0@@YAXXZ
namespace fn_003600f0 {
// data: name1 = DAT_00429c74, name2 = DAT_00429270, registry = DAT_004e6a18

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
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl cleanup_003643f0();
class Registry {
  public:
    void FUN_002584d0(unsigned __int64*, unsigned __int64*, int, int);
};
void init() {
    HULK_SIZE32(AudioSeqActionWaitBeat, 0x18);
    unsigned __int64 a = FUN_002672f0(DAT_00429c74, 0, 0);
    unsigned __int64 b = FUN_002672f0(DAT_00429270, 0, 0);
    (*(Registry*)&DAT_004e6a18).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqActionWaitBeat), (int)__alignof(AudioSeqActionWaitBeat));
    atexit(cleanup_003643f0);
}
} // namespace fn_003600f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f1ddef39 {

// 0x00360150 FUN_00360150 (21 B): matches/0x00360150.cpp
// sym: ?FUN_00360150@fn_f1ddef39@@YAXXZ
void FUN_00360150() {
    (*(int*)&DAT_004e6a60) = FUN_002673a0("ChannelVolumeFade", 0);
}


// 0x00360170 FUN_00360170 (22 B): matches/0x00360170.cpp
// sym: ?FUN_00360170@fn_f1ddef39@@YAXXZ
// data: hulk_at_004e6a60 = DAT_004e6a60
void __cdecl FUN_00360170() {
    ((SeqEventWaitBeatType_nv_360170*)(((audio::SeqEventWaitBeatType*)(((audio::SeqEventWaitBeatType*)((hulk_intptr)(((char*)&DAT_004e6a68))))))))->FUN_002506d0();
    _atexit((void(__cdecl*)(void))(hulk_longptr)FUN_00364400);
}

} // namespace fn_f1ddef39

// 0x003601e0 FUN_003601e0 (88 B): matches/0x003601e0.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?FUN_003601e0@fn_003601e0@@YAXXZ
namespace fn_003601e0 {
// data: registry = DAT_004e6ad0

typedef __int64 I64;
extern "C++" __declspec(nothrow) I64 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364410();
class Registry {
  public:
    void FUN_002584d0(I64*, I64*, int, int);
};
void __cdecl FUN_003601e0() {
    HULK_SIZE32(AudioSeqActionExpression, 0x10);
    I64 first = FUN_002672f0("SeqActionExpression", 0, 0);
    I64 second = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e6ad0).FUN_002584d0(&second, &first, (int)sizeof(AudioSeqActionExpression), (int)__alignof(AudioSeqActionExpression));
    atexit(FUN_00364410);
}
} // namespace fn_003601e0


// 0x00360240 FUN_00360240 (22 B): matches/0x00360240.cpp [wrapped: conflict: Obj]
// sym: ?target@fn_00360240@@YAXXZ
namespace fn_00360240 {

struct Obj {
    void FUN_00250b20();
    Obj();
    ~Obj();
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364420();
void target() {
    ((Obj*)&DAT_004e6b18)->FUN_00250b20();
    atexit(FUN_00364420);
}
} // namespace fn_00360240

namespace fn_f1ddef39 {

// 0x003602b0 FUN_003602b0 (88 B): matches/0x003602b0.cpp
// sym: ?FUN_003602b0@fn_f1ddef39@@YAXXZ
// data: reg = DAT_004e6b80
void __cdecl FUN_003602b0() {
    HULK_SIZE32(AudioSeqActionStopTrack, 0x10);
    unsigned __int64 x = FUN_002672f0(DAT_00429db4, 0, 0);
    unsigned __int64 y = FUN_002672f0(DAT_00429270, 0, 0);
    (*(Registry*)&DAT_004e6b80).FUN_002584d0((__int64*)&y, (__int64*)&x, (int)sizeof(AudioSeqActionStopTrack), (int)__alignof(AudioSeqActionStopTrack));
    atexit(FUN_00364430);
}

} // namespace fn_f1ddef39

// 0x00360310 FUN_00360310 (22 B): matches/0x00360310.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_00360310@fn_00360310@@YAXXZ
namespace fn_00360310 {
// data: g_mgr_360310 = DAT_004e6bc8

class SeqEventStopTrackType_360310 {
  public:
    void FUN_00250f60();
};


void FUN_00364440() throw() {}


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
int atexit(void (*)(void));
#endif


void FUN_00360310() {
    (*(SeqEventStopTrackType_360310*)&DAT_004e6bc8).FUN_00250f60();
    atexit(FUN_00364440);
}
} // namespace fn_00360310


// 0x00360380 FUN_00360380 (88 B): matches/0x00360380.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?FUN_00360380@fn_00360380@@YAXXZ
namespace fn_00360380 {
// data: globalManager = DAT_004e6c30, nameA = DAT_00429e44, nameB = DAT_00429270

typedef __int64 I64;
extern I64 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364450();
struct Manager {
    void FUN_002584d0(I64*, I64*, int, int);
};
void __cdecl FUN_00360380() {
    HULK_SIZE32(AudioSeqActionPlayTrack, 0x10);
    I64 a = FUN_002672f0(DAT_00429e44, 0, 0);
    I64 b = FUN_002672f0(DAT_00429270, 0, 0);
    (*(Manager*)((char*)&DAT_004e6c30)).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqActionPlayTrack), (int)__alignof(AudioSeqActionPlayTrack));
    atexit(FUN_00364450);
}
} // namespace fn_00360380

namespace fn_f1ddef39 {

// 0x003603e0 FUN_003603e0 (22 B): matches/0x003603e0.cpp
// sym: ?FUN_003603e0@fn_f1ddef39@@YAXXZ
// data: gGlobal_3603e0 = DAT_004e6c78
void __cdecl FUN_003603e0() {
    (*(SeqEventPlayTrackType_3603e0*)((char*)&DAT_004e6c78)).FUN_00251510();
    _atexit(FUN_00364460);
}

} // namespace fn_f1ddef39

// 0x00360450 FUN_00360450 (88 B): matches/0x00360450.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?FUN_00360450@fn_00360450@@YAXXZ
namespace fn_00360450 {
// data: gRegistry = DAT_004e6ce0

typedef __int64 I64;
extern "C++" __declspec(nothrow) I64 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364470();
class Registry {
  public:
    void FUN_002584d0(I64*, I64*, int, int);
};
void __cdecl FUN_00360450() {
    HULK_SIZE32(AudioSeqActionChannelVolumes, 0x10);
    I64 a = FUN_002672f0("SeqActionChannelVolumes", 0, 0);
    I64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e6ce0).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqActionChannelVolumes), (int)__alignof(AudioSeqActionChannelVolumes));
    atexit(FUN_00364470);
}
} // namespace fn_00360450

namespace fn_f1ddef39 {

// 0x003604b0 FUN_003604b0 (21 B): matches/0x003604b0.cpp
// sym: ?FUN_003604b0@fn_f1ddef39@@YAXXZ
// the name's hash (0x002673a0, an int)
void FUN_003604b0() {
    (*(int*)&DAT_004e6d28) = FUN_002673a0("ChannelVolumeFade", 0);
}

} // namespace fn_f1ddef39

// 0x003604d0 FUN_003604d0 (22 B): matches/0x003604d0.cpp [wrapped: same definition as 0x0035eaf0 in this TU]
// sym: ?Register@fn_003604d0@@YAXXZ
namespace fn_003604d0 {
// data: g_mgr_3604d0 = DAT_004e6d30

extern "C++" __declspec(nothrow) void __cdecl FUN_00364490();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void (*)());
#endif

struct SeqEventChannelVolumesType_3604d0 {
    void FUN_00251b40();
};
void Register() {
    (*(SeqEventChannelVolumesType_3604d0*)((char*)&DAT_004e6d30)).FUN_00251b40();
    atexit(FUN_00364490);
}
} // namespace fn_003604d0


// 0x003604f0 FUN_003604f0 (88 B): matches/0x003604f0.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?target@fn_003604f0@@YAXXZ
namespace fn_003604f0 {
// data: gRegistry = DAT_004e6d98

typedef unsigned __int64 U64;
extern U64 __cdecl FUN_002672f0(const char*, int, int);
class Registry {
  public:
    void FUN_002584d0(U64*, U64*, int, int);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364480();
void __cdecl target() {
    HULK_SIZE32(AudioChannelVolumeFadeBehaviour, 0x24);
    U64 a = FUN_002672f0("ChannelVolumeFadeBehaviour", 0, 0);
    U64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e6d98).FUN_002584d0(&b, &a, (int)sizeof(AudioChannelVolumeFadeBehaviour), (int)__alignof(AudioChannelVolumeFadeBehaviour));
    atexit(FUN_00364480);
}
} // namespace fn_003604f0

namespace fn_f1ddef39 {

// 0x003605a0 FUN_003605a0 (88 B): matches/0x003605a0.cpp
// sym: ?FUN_003605a0@fn_f1ddef39@@YAXXZ
// data: name1 = DAT_00429f90, name2 = DAT_00429270, registry = DAT_004e6de0
void __cdecl FUN_003605a0() {
    HULK_SIZE32(AudioSeqActionVarVolumeRand, 0x10);
    unsigned __int64 a = FUN_002672f0(((char*)&DAT_00429f90), 0, 0);
    unsigned __int64 b = FUN_002672f0(((char*)&DAT_00429270), 0, 0);
    (*(Registry*)&DAT_004e6de0).FUN_002584d0((__int64*)&b, (__int64*)&a, (int)sizeof(AudioSeqActionVarVolumeRand), (int)__alignof(AudioSeqActionVarVolumeRand));
    atexit(FUN_003644a0);
}


// 0x00360600 FUN_00360600 (22 B): matches/0x00360600.cpp
// sym: ?FUN_00360600@fn_f1ddef39@@YAXXZ
void __cdecl FUN_00360600() {
    gObj.FUN_002524e0();
    atexit(FUN_003644b0);
}


// 0x00360670 FUN_00360670 (88 B): matches/0x00360670.cpp
// sym: ?FUN_00360670@fn_f1ddef39@@YAXXZ
// data: registry = DAT_004e6e90
void FUN_00360670() {
    HULK_SIZE32(AudioSeqActionVarVolume, 0x10);
    unsigned __int64 a = FUN_002672f0("SeqActionVarVolume", 0, 0);
    unsigned __int64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e6e90).FUN_002584d0((__int64*)&b, (__int64*)&a, (int)sizeof(AudioSeqActionVarVolume), (int)__alignof(AudioSeqActionVarVolume));
    atexit(cleanup);
}


// 0x003606d0 FUN_003606d0 (22 B): matches/0x003606d0.cpp
// sym: ?FUN_003606d0@fn_f1ddef39@@YAXXZ
// data: gTarget = DAT_004e6ed8
void __cdecl FUN_003606d0() {
    (*(SeqEventVarVolumeType_3606d0*)&DAT_004e6ed8).FUN_002528b0();
    atexit(FUN_003644d0);
}

} // namespace fn_f1ddef39

// 0x00360740 FUN_00360740 (88 B): matches/0x00360740.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?init@fn_00360740@@YAXXZ
namespace fn_00360740 {
// data: registry = DAT_004e6f40

extern "C++" __declspec(nothrow) __int64 FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void FUN_003644e0();
class Registry {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
void init() {
    HULK_SIZE32(AudioSeqActionVarTempo, 0x10);
    __int64 a = FUN_002672f0("SeqActionVarTempo", 0, 0);
    __int64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)((char*)&DAT_004e6f40)).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqActionVarTempo), (int)__alignof(AudioSeqActionVarTempo));
    atexit(FUN_003644e0);
}
} // namespace fn_00360740

namespace fn_f1ddef39 {

// 0x003607a0 FUN_003607a0 (22 B): matches/0x003607a0.cpp
// sym: ?FUN_003607a0@fn_f1ddef39@@YAXXZ
void __cdecl FUN_003607a0() {
    (*(SeqEventVarTempoType_3607a0*)&DAT_004e6f88).FUN_00252d00();
    _atexit(FUN_003644f0);
}

} // namespace fn_f1ddef39

// 0x00360810 FUN_00360810 (88 B): matches/0x00360810.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?FUN_00360810@fn_00360810@@YAXXZ
namespace fn_00360810 {

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_002672f0(const char*, int, int);
struct Registry {
    void FUN_002584d0(const __int64*, const __int64*, int, int);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl _atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void FUN_00364500();
void __cdecl FUN_00360810() {
    HULK_SIZE32(AudioSeqActionVarPosDist, 0x10);
    __int64 action = FUN_002672f0("SeqActionVarPosDist", 0, 0);
    __int64 runtime = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e6ff0).FUN_002584d0(&runtime, &action, (int)sizeof(AudioSeqActionVarPosDist), (int)__alignof(AudioSeqActionVarPosDist));
    _atexit(FUN_00364500);
}
} // namespace fn_00360810

namespace fn_f1ddef39 {

// 0x003608e0 FUN_003608e0 (88 B): matches/0x003608e0.cpp
// sym: ?FUN_003608e0@fn_f1ddef39@@YAXXZ
void __cdecl FUN_003608e0() {
    HULK_SIZE32(AudioSeqActionVarPitchRand, 0x10);
    U64 a = FUN_002672f0("SeqActionVarPitchRand", 0, 0);
    U64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    registry.FUN_002584d0((__int64*)&b, (__int64*)&a, (int)sizeof(AudioSeqActionVarPitchRand), (int)__alignof(AudioSeqActionVarPitchRand));
    atexit(cleanup);
}


// 0x00360940 FUN_00360940 (22 B): matches/0x00360940.cpp
// sym: ?FUN_00360940@fn_f1ddef39@@YAXXZ
// data: g_cleanup = DAT_004e70e8
void FUN_00360940() {
    (*(SeqEventVarPitchRandType_360940*)&DAT_004e70e8).FUN_002534b0();
    _atexit(FUN_00364530);
}

} // namespace fn_f1ddef39

// 0x003609b0 FUN_003609b0 (88 B): matches/0x003609b0.cpp [wrapped: conflict: FUN_002672f0; Pair]
// sym: ?FUN_003609b0@fn_003609b0@@YAXXZ
namespace fn_003609b0 {
// data: registry = DAT_004e7150

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364540();
class Registry {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
struct Pair {
    __int64 a, b;
};
void __cdecl FUN_003609b0() {
    HULK_SIZE32(AudioSeqActionVarPitch, 0x10);
    Pair p;
    p.a = FUN_002672f0("SeqActionVarPitch", 0, 0);
    p.b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)((char*)&DAT_004e7150)).FUN_002584d0(&p.b, &p.a, (int)sizeof(AudioSeqActionVarPitch), (int)__alignof(AudioSeqActionVarPitch));
    atexit(FUN_00364540);
}
} // namespace fn_003609b0

namespace fn_f1ddef39 {

// 0x00360a10 FUN_00360a10 (22 B): matches/0x00360a10.cpp
// sym: ?FUN_00360a10@fn_f1ddef39@@YAXXZ
void __cdecl FUN_00360a10() {
    (*(SeqEventVarPitchType_360a10*)&DAT_004e7198).FUN_002538a0();
    atexit((void (*)(void))FUN_00364550);
}


// 0x00360a80 FUN_00360a80 (22 B): matches/0x00360a80.cpp
// sym: ?FUN_00360a80@fn_f1ddef39@@YAXXZ
// data: gHelper_360a80 = DAT_004e7200
void __cdecl FUN_00360a80() {
    (*(SeqEventStreamType_360a80*)&DAT_004e7200).FUN_002540a0();
    _atexit((void (*)())FUN_00364570);
}


// 0x00360aa0 FUN_00360aa0 (88 B): matches/0x00360aa0.cpp
// sym: ?FUN_00360aa0@fn_f1ddef39@@YAXXZ
void __cdecl FUN_00360aa0() {
    HULK_SIZE32(AudioSeqActionStream, 0x2c);
    __int64 a = FUN_002672f0("SeqActionStream", 0, 0);
    __int64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    registry.FUN_002584d0(&b, &a, (int)sizeof(AudioSeqActionStream), (int)__alignof(AudioSeqActionStream));
    atexit(cleanup);
}

} // namespace fn_f1ddef39

// 0x00360b50 FUN_00360b50 (88 B): matches/0x00360b50.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?Target@fn_00360b50@@YAXXZ
namespace fn_00360b50 {
// data: gRegistry = DAT_004e72b0

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl Finish_00364580();
class Registry {
  public:
    void FUN_002584d0(const __int64*, const __int64*, int, int);
};
void __cdecl Target() {
    HULK_SIZE32(AudioSeqActionSilence, 0x1c);
    __int64 a = FUN_002672f0("SeqActionSilence", 0, 0);
    __int64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e72b0).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqActionSilence), (int)__alignof(AudioSeqActionSilence));
    atexit(Finish_00364580);
}
} // namespace fn_00360b50

namespace fn_f1ddef39 {

// 0x00360bb0 FUN_00360bb0 (22 B): matches/0x00360bb0.cpp
// sym: _FUN_00360bb0
extern "C" void __cdecl FUN_00360bb0() {
    ((audio::SeqEventSilenceType *)&((*(G_360bb0*)&DAT_004e72f8)))->FUN_00254760();
    atexit(FUN_00364590);
}

} // namespace fn_f1ddef39

// 0x00360c20 FUN_00360c20 (88 B): matches/0x00360c20.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?Init@fn_00360c20@@YAXXZ
namespace fn_00360c20 {
// data: gRegistry = DAT_004e7360

typedef unsigned __int64 U64;
extern U64 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_003645a0();
struct Registry {
    void FUN_002584d0(U64*, U64*, int, int);
};
void Init() {
    HULK_SIZE32(AudioSeqCommandLogicRepeat, 0x18);
    U64 a = FUN_002672f0("SeqCommandLogicRepeat", 0, 0);
    U64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)((char*)&DAT_004e7360)).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqCommandLogicRepeat), (int)__alignof(AudioSeqCommandLogicRepeat));
    atexit(FUN_003645a0);
}
} // namespace fn_00360c20

namespace fn_f1ddef39 {

// 0x00360c80 FUN_00360c80 (22 B): matches/0x00360c80.cpp
// sym: ?FUN_00360c80@fn_f1ddef39@@YAXXZ
void FUN_00360c80() {
    (*(SeqEventLogicRepeatType_360c80*)&DAT_004e73a8).FUN_00254b10();
    atexit((void (*)())FUN_003645b0);
}

} // namespace fn_f1ddef39

// 0x00360cf0 FUN_00360cf0 (88 B): matches/0x00360cf0.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?Init@fn_00360cf0@@YAXXZ
namespace fn_00360cf0 {
// data: gRegistry = DAT_004e7410

typedef unsigned __int64 U64;
extern U64 __cdecl FUN_002672f0(const char*, int, int);
class Registry {
  public:
    void FUN_002584d0(U64*, U64*, int, int);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_003645c0();
void __cdecl Init() {
    HULK_SIZE32(AudioSeqCommandLogicOr, 0xc);
    U64 first = FUN_002672f0("SeqCommandLogicOr", 0, 0);
    U64 second = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e7410).FUN_002584d0(&second, &first, (int)sizeof(AudioSeqCommandLogicOr), (int)__alignof(AudioSeqCommandLogicOr));
    atexit(FUN_003645c0);
}
} // namespace fn_00360cf0


// 0x00360d50 FUN_00360d50 (22 B): matches/0x00360d50.cpp [wrapped: conflict: _atexit]
// sym: ?FUN_00360d50@fn_00360d50@@YAXXZ
namespace fn_00360d50 {


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void __cdecl _atexit(void (*)());
#endif

struct SeqEventLogicOrType_360d50 {
    void FUN_00254f40();
};
extern "C++" __declspec(nothrow) void FUN_003645d0();
void __cdecl FUN_00360d50() {
    (*(SeqEventLogicOrType_360d50*)((char*)&DAT_004e7458)).FUN_00254f40();
    _atexit(FUN_003645d0);
}
} // namespace fn_00360d50


// 0x00360dc0 FUN_00360dc0 (88 B): matches/0x00360dc0.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?FUN_00360dc0@fn_00360dc0@@YAXXZ
namespace fn_00360dc0 {
// FUN_00360dc0 @ 0x00360dc0
// FUN_00360dc0 @ 0x00360dc0

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_002672f0(const char*, int, int);
struct ThisNote_002584d0 {
    void FUN_002584d0(const __int64*, const __int64*, int, int);
};
extern void __cdecl FUN_003645e0();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif


void __cdecl FUN_00360dc0() {
    HULK_SIZE32(AudioSeqActionCrossFade, 0x1c);
    __int64 action = FUN_002672f0("SeqActionCrossFade", 0, 0);
    __int64 sequence = FUN_002672f0("Runtime_Sequence", 0, 0);
    ((ThisNote_002584d0*)(((char*)&DAT_004e74c0)))
        ->FUN_002584d0(&sequence, &action, (int)sizeof(AudioSeqActionCrossFade),
                       (int)__alignof(AudioSeqActionCrossFade));
    atexit(FUN_003645e0);
}
} // namespace fn_00360dc0


// 0x00360e20 FUN_00360e20 (22 B): matches/0x00360e20.cpp [wrapped: same definition as 0x0035ed50 in this TU]
// sym: ?Init@fn_00360e20@@YAXXZ
namespace fn_00360e20 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl* f)());
#endif

class SeqEventCrossFadeType_360e20 {
  public:
    virtual void FUN_002555c0();
};
extern SeqEventCrossFadeType_360e20 hulk_at_004e7508;
extern "C++" __declspec(nothrow) void __cdecl FUN_003645f0();
void __cdecl Init() {
    hulk_at_004e7508.FUN_002555c0();
    atexit(FUN_003645f0);
}
} // namespace fn_00360e20

namespace fn_f1ddef39 {

// 0x00360e90 FUN_00360e90 (88 B): matches/0x00360e90.cpp
// sym: ?FUN_00360e90@fn_f1ddef39@@YAXXZ
// data: global = DAT_004e7570
void __cdecl FUN_00360e90() {
    HULK_SIZE32(AudioSeqActionClip, 0x1c);
    __int64 a = FUN_002672f0("SeqActionClip", 0, 0);
    __int64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Global*)((char*)&DAT_004e7570)).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqActionClip), (int)__alignof(AudioSeqActionClip));
    atexit(cleanup);
}

} // namespace fn_f1ddef39

// 0x00360ef0 FUN_00360ef0 (22 B): matches/0x00360ef0.cpp [wrapped: same definition as 0x0035ed50 in this TU]
// sym: ?Init@fn_00360ef0@@YAXXZ
namespace fn_00360ef0 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void (*)(void));
#endif

class SeqEventClipType_360ef0 {
  public:
    void FUN_00255f70();
};
SeqEventClipType_360ef0 g_360ef0;
extern "C++" __declspec(nothrow) void FUN_00364610();
void Init() {
    g_360ef0.FUN_00255f70();
    atexit(FUN_00364610);
}
} // namespace fn_00360ef0


// 0x00360f60 FUN_00360f60 (22 B): matches/0x00360f60.cpp [wrapped: conflict: Thing]
// sym: ?FUN_00360f60@fn_00360f60@@YAXXZ
namespace fn_00360f60 {
// data: gThing = DAT_004e7620

class Thing {
  public:
    void FUN_00256c20();
    Thing();
    ~Thing();
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364630();
void __cdecl FUN_00360f60() {
    ((Thing*)((char*)&DAT_004e7620))->FUN_00256c20();
    atexit(FUN_00364630);
}
} // namespace fn_00360f60


// 0x00360f80 FUN_00360f80 (88 B): matches/0x00360f80.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?FUN_00360f80@fn_00360f80@@YAXXZ
namespace fn_00360f80 {
// data: gRegistry = DAT_004e7690

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl Cleanup_00364620();
class Registry {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
void __cdecl FUN_00360f80() {
    HULK_SIZE32(AudioSeqBuss, 0x14);
    __int64 b = FUN_002672f0("SeqBuss", 0, 0);
    __int64 a = FUN_002672f0("Data_Sequence", 0, 0);
    (*(Registry*)&DAT_004e7690).FUN_002584d0(&a, &b, (int)sizeof(AudioSeqBuss), (int)__alignof(AudioSeqBuss));
    atexit(Cleanup_00364620);
}
} // namespace fn_00360f80


// 0x00360fe0 FUN_00360fe0 (12 B): matches/0x00360fe0.cpp [wrapped: conflict: _atexit]
// sym: ?FUN_00360fe0@fn_00360fe0@@YAXXZ
namespace fn_00360fe0 {
extern "C++" __declspec(nothrow) void __cdecl FUN_00364640();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
int __cdecl _atexit(void(__cdecl* func)());
#endif


void __cdecl FUN_00360fe0() {
    _atexit(FUN_00364640);
}
} // namespace fn_00360fe0

namespace fn_f1ddef39 {

// 0x00360ff0 FUN_00360ff0 (91 B): matches/0x00360ff0.cpp
// sym: ?FUN_00360ff0@fn_f1ddef39@@YAXXZ
// data: mgr = DAT_004e76e8
void __cdecl FUN_00360ff0() {
    HULK_SIZE32(AudioHalVoice, 0x88);
    __int64 a;
    __int64 b = FUN_002672f0("HalVoice", 0, 0);
    a = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Mgr_360ff0*)&DAT_004e76e8).FUN_002584d0(&a, &b, (int)sizeof(AudioHalVoice), (int)__alignof(AudioHalVoice));
    atexit(cleanup);
}

} // namespace fn_f1ddef39

// 0x00361050 FUN_00361050 (91 B): matches/0x00361050.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?FUN_00361050@fn_00361050@@YAXXZ
namespace fn_00361050 {
// data: global_361050 = DAT_004e7730

struct Pair_361050 {
    int a, b;
};
extern "C++" __declspec(nothrow) Pair_361050 __cdecl FUN_002672f0(const char*, int, int);
struct Obj_361050 {
    void FUN_002584d0(Pair_361050*, Pair_361050*, int, int);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364660();
void __cdecl FUN_00361050() {
    HULK_SIZE32(AudioHalVoiceChannel, 0x80);
    Pair_361050 a = FUN_002672f0("HalVoiceChannel", 0, 0);
    Pair_361050 b = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Obj_361050*)((char*)&DAT_004e7730)).FUN_002584d0(&b, &a, (int)sizeof(AudioHalVoiceChannel), (int)__alignof(AudioHalVoiceChannel));
    atexit(FUN_00364660);
}
} // namespace fn_00361050


// 0x003610b0 FUN_003610b0 (91 B): matches/0x003610b0.cpp [wrapped: conflict: FUN_002672f0; cleanup]
// sym: ?FUN_003610b0@fn_003610b0@@YAXXZ
namespace fn_003610b0 {
// data: manager_3610b0 = DAT_004e7778

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

void __cdecl cleanup_00364670();
struct Manager_3610b0 {
    void FUN_002584d0(__int64*, __int64*, int, int);
};
struct Pair_3610b0 {
    __int64 property, meta;
};
void __cdecl FUN_003610b0() {
    HULK_SIZE32(OmMetaProperty, 0xa0);
    Pair_3610b0 p;
    p.property = FUN_002672f0("Property", 0, 0);
    p.meta = FUN_002672f0("Meta", 0, 0);
    (*(Manager_3610b0*)((char*)&DAT_004e7778)).FUN_002584d0(&p.meta, &p.property, (int)sizeof(OmMetaProperty), (int)__alignof(OmMetaProperty));
    atexit(cleanup_00364670);
}
} // namespace fn_003610b0


// 0x00361110 FUN_00361110 (88 B): matches/0x00361110.cpp [wrapped: conflict: FUN_002672f0; Pair; cleanup]
// sym: ?FUN_00361110@fn_00361110@@YAXXZ
namespace fn_00361110 {
// data: store = DAT_004e77c0

struct Pair {
    int a, b;
};
extern Pair __cdecl FUN_002672f0(const char*, int, int);
class Store {
  public:
    void FUN_002584d0(Pair*, Pair*, int, int);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern void __cdecl cleanup_00364680();
void __cdecl FUN_00361110() {
    Pair a = FUN_002672f0("Properties", 0, 0);
    Pair b = FUN_002672f0("Meta", 0, 0);
    (*(Store*)&DAT_004e77c0).FUN_002584d0(&b, &a, 16, 8);
    atexit(cleanup_00364680);
}
} // namespace fn_00361110


// 0x00361170 FUN_00361170 (91 B): matches/0x00361170.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?Init@fn_00361170@@YAXXZ
namespace fn_00361170 {
// data: gRegistry_361170 = DAT_004e7808

extern "C++" __declspec(nothrow) __int64 FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364690();
class Registry_361170 {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
void Init() {
    HULK_SIZE32(AudioOmHalStream, 0x1c8);
    __int64 a = FUN_002672f0("OmHalStream", 0, 0);
    __int64 b = FUN_002672f0("Transient", 0, 0);
    (*(Registry_361170*)&DAT_004e7808).FUN_002584d0(&b, &a, (int)sizeof(AudioOmHalStream), (int)__alignof(AudioOmHalStream));
    atexit(FUN_00364690);
}
} // namespace fn_00361170


// 0x003611d0 FUN_003611d0 (94 B): matches/0x003611d0.cpp [wrapped: same definition as 0x0035dc90 in this TU]
// sym: ?target@fn_003611d0@@YAXXZ
namespace fn_003611d0 {
// data: globalObj_3611d0 = DAT_004e7850

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
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_003646a0();
class Obj_3611d0 {
  public:
    void FUN_002584d0(unsigned __int64*, unsigned __int64*, int, int);
};
void target() {
    unsigned __int64 a = FUN_002672f0("OmHalStream Temp Aligned Stream Mem", 0, 0);
    unsigned __int64 b = FUN_002672f0("Temp", 0, 0);
    (*(Obj_3611d0*)((char*)&DAT_004e7850)).FUN_002584d0(&b, &a, 0x4000, 0x80);
    atexit(FUN_003646a0);
}
} // namespace fn_003611d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00361230 FUN_00361230 (88 B): matches/0x00361230.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?Target@fn_00361230@@YAXXZ
namespace fn_00361230 {
// data: gManager = DAT_004e7898

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_003646b0();
class Manager {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
void __cdecl Target() {
    HULK_SIZE32(AudioHalBuffer, 0x28);
    __int64 a = FUN_002672f0("HalBuffer", 0, 0);
    __int64 b = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Manager*)&DAT_004e7898).FUN_002584d0(&b, &a, (int)sizeof(AudioHalBuffer), (int)__alignof(AudioHalBuffer));
    atexit(FUN_003646b0);
}
} // namespace fn_00361230


// 0x00361290 FUN_00361290 (88 B): matches/0x00361290.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?target@fn_00361290@@YAXXZ
namespace fn_00361290 {
// data: gHolder = DAT_004e78e0

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_003646c0();
class Holder {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
void target() {
    HULK_SIZE32(AudioSeqTrackPlayer, 0x60);
    __int64 a = FUN_002672f0("SeqTrackPlayer", 0, 0);
    __int64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Holder*)&DAT_004e78e0).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqTrackPlayer), (int)__alignof(AudioSeqTrackPlayer));
    atexit(FUN_003646c0);
}
} // namespace fn_00361290


// 0x00361340 FUN_00361340 (88 B): matches/0x00361340.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?Target@fn_00361340@@YAXXZ
namespace fn_00361340 {
// data: gManager = DAT_004e7928

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

void __cdecl FUN_003646d0();
struct Manager {
    void FUN_002584d0(const __int64*, const __int64*, int, int);
};
void __cdecl Target() {
    HULK_SIZE32(AudioCircBuf, 0x30);
    __int64 a = FUN_002672f0("CircBuf", 0, 0);
    __int64 b = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Manager*)((char*)&DAT_004e7928)).FUN_002584d0(&b, &a, (int)sizeof(AudioCircBuf), (int)__alignof(AudioCircBuf));
    atexit(FUN_003646d0);
}
} // namespace fn_00361340


// 0x003613a0 FUN_003613a0 (88 B): matches/0x003613a0.cpp [wrapped: conflict: FUN_002672f0; Pair]
// sym: ?FUN_003613a0@fn_003613a0@@YAXXZ
namespace fn_003613a0 {
// data: name1 = DAT_0042a9e8, name2 = DAT_004290a8, registry = DAT_004e7970

struct Pair {
    int a, b;
};
struct Registry {
    void FUN_002584d0(Pair*, Pair*, int, int);
};
extern Pair __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_003646e0();
void FUN_003613a0() {
    HULK_SIZE32(AudioCircBufGarbageRegion, 0xc);
    Pair p = FUN_002672f0(DAT_0042a9e8, 0, 0);
    Pair q = FUN_002672f0(DAT_004290a8, 0, 0);
    (*(Registry*)((char*)&DAT_004e7970)).FUN_002584d0(&q, &p, (int)sizeof(AudioCircBufGarbageRegion), (int)__alignof(AudioCircBufGarbageRegion));
    atexit(FUN_003646e0);
}
} // namespace fn_003613a0


// 0x00361400 FUN_00361400 (88 B): matches/0x00361400.cpp [wrapped: same definition as 0x0035ed50 in this TU]
// sym: ?Init@fn_00361400@@YAXXZ
namespace fn_00361400 {
// data: gRegistry = DAT_004e79d0

struct Pair {
    unsigned a, b;
};
extern "C++" __declspec(nothrow) Pair __cdecl FUN_002672f0(const char*, int, int);
struct Registry {
    void FUN_002584d0(Pair*, Pair*, int, int);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl Cleanup_003646f0();
void __cdecl Init() {
    HULK_SIZE32(OmMetaType, 0x34);
    Pair first = FUN_002672f0("MetaType", 0, 0);
    Pair second = FUN_002672f0("om", 0, 0);
    (*(Registry*)&DAT_004e79d0).FUN_002584d0(&second, &first, (int)sizeof(OmMetaType), (int)__alignof(OmMetaType));
    atexit(Cleanup_003646f0);
}
} // namespace fn_00361400


// 0x003614b0 FUN_003614b0 (88 B): matches/0x003614b0.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?target@fn_003614b0@@YAXXZ
namespace fn_003614b0 {
// data: beat = DAT_0042ab20, global = DAT_004e7a30, sequence = DAT_0042a620

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_002672f0(const char*, int, int);
class Object {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364700();
void __cdecl target() {
    HULK_SIZE32(AudioBeatSetBeat, 0x8);
    __int64 a = FUN_002672f0(DAT_0042ab20, 0, 0);
    __int64 b = FUN_002672f0(DAT_0042a620, 0, 0);
    (*(Object*)&DAT_004e7a30).FUN_002584d0(&b, &a, (int)sizeof(AudioBeatSetBeat), (int)__alignof(AudioBeatSetBeat));
    atexit(FUN_00364700);
}
} // namespace fn_003614b0


// 0x00361510 FUN_00361510 (88 B): matches/0x00361510.cpp [wrapped: conflict: Pair]
// sym: ?Target@fn_00361510@@YAXXZ
namespace fn_00361510 {
// data: BeatSet = DAT_0042ab2c, Data_Sequence = DAT_0042a620, gManager = DAT_004e7a78

struct Pair {
    int a, b;
};
extern "C++" __declspec(nothrow) Pair __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C" void __cdecl FUN_00364710();
class Manager {
  public:
    void FUN_002584d0(Pair*, Pair*, int, int);
};
void __cdecl Target() {
    HULK_SIZE32(AudioBeatSet, 0x8);
    Pair a = FUN_002672f0(((char*)&DAT_0042ab2c), 0, 0);
    Pair b = FUN_002672f0(((char*)&DAT_0042a620), 0, 0);
    (*(Manager*)&DAT_004e7a78).FUN_002584d0(&b, &a, (int)sizeof(AudioBeatSet), (int)__alignof(AudioBeatSet));
    atexit(FUN_00364710);
}
} // namespace fn_00361510

namespace fn_f1ddef39 {

// 0x00361570 FUN_00361570 (88 B): matches/0x00361570.cpp
// sym: ?FUN_00361570@fn_f1ddef39@@YAXXZ
// data: dataSequence = DAT_0042a620, mgr = DAT_004e7ac0, seqTrack = DAT_0042ab44
void FUN_00361570() {
    HULK_SIZE32(AudioSeqTrack, 0x48);
    __int64 a = FUN_002672f0(DAT_0042ab44, 0, 0);
    __int64 b = FUN_002672f0(DAT_0042a620, 0, 0);
    (*(Manager*)&DAT_004e7ac0).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqTrack), (int)__alignof(AudioSeqTrack));
    atexit(Done_00364720);
}


// 0x003615d0 FUN_003615d0 (88 B): matches/0x003615d0.cpp
// sym: ?FUN_003615d0@fn_f1ddef39@@YAXXZ
// data: global = DAT_004e7b08
void __cdecl FUN_003615d0() {
    HULK_SIZE32(AudioHalRadicalAdpcmDecodeStream, 0x20);
    struct Pair {
        __int64 a;
        __int64 b;
    } p;
    p.a = FUN_002672f0("HalRadicalAdpcmDecodeStream", 0, 0);
    p.b = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Manager*)&DAT_004e7b08).FUN_002584d0(&p.b, &p.a, (int)sizeof(AudioHalRadicalAdpcmDecodeStream), (int)__alignof(AudioHalRadicalAdpcmDecodeStream));
    atexit(FUN_00364730);
}


// 0x00361630 FUN_00361630 (91 B): matches/0x00361630.cpp
// sym: ?FUN_00361630@fn_f1ddef39@@YAXXZ
// data: gRegistry_361630 = DAT_004e7b50
void __cdecl FUN_00361630() {
    HULK_SIZE32(AudioHalRsdFileHeader, 0x1a4);
    U64_361630 a = FUN_002672f0("HalRsdFileHeader", 0, 0);
    U64_361630 b = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Registry_361630*)((char*)&DAT_004e7b50)).FUN_002584d0(&b, &a, (int)sizeof(AudioHalRsdFileHeader), (int)__alignof(AudioHalRsdFileHeader));
    atexit(FUN_00364740);
}

} // namespace fn_f1ddef39

// 0x00361690 FUN_00361690 (88 B): matches/0x00361690.cpp [wrapped: conflict: Cleanup]
// sym: ?FUN_00361690@fn_00361690@@YAXXZ
namespace fn_00361690 {
// data: gRegistry = DAT_004e7b98

typedef unsigned __int64 U64;
extern "C++" __declspec(nothrow) U64 __cdecl FUN_002672f0(const char*, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

void __cdecl Cleanup_00364750();
class Registry {
  public:
    void FUN_002584d0(U64*, U64*, int, int);
};
void FUN_00361690() {
    HULK_SIZE32(AudioHalRsdFileStream, 0x48);
    U64 a = FUN_002672f0("HalRsdFileStream", 0, 0);
    U64 b = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Registry*)&DAT_004e7b98).FUN_002584d0(&b, &a, (int)sizeof(AudioHalRsdFileStream), (int)__alignof(AudioHalRsdFileStream));
    atexit(Cleanup_00364750);
}
} // namespace fn_00361690

namespace fn_f1ddef39 {

// 0x003616f0 FUN_003616f0 (12 B): matches/0x003616f0.cpp
// sym: ?FUN_003616f0@fn_f1ddef39@@YAXXZ
void __cdecl FUN_003616f0() {
    atexit(FUN_00364770);
}

} // namespace fn_f1ddef39

// 0x00361700 FUN_00361700 (88 B): matches/0x00361700.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?target@fn_00361700@@YAXXZ
namespace fn_00361700 {

extern "C++" __declspec(nothrow) __int64 __cdecl FUN_002672f0(const char*, int, int);
class Table {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364760();
void __cdecl target() {
    __int64 a;
    __int64 b = FUN_002672f0("PointerUid", 0, 0);
    a = FUN_002672f0("Om", 0, 0);
    (*(Table*)&DAT_004e7be0).FUN_002584d0(&a, &b, 32, 8);
    atexit(FUN_00364760);
}
} // namespace fn_00361700

namespace fn_f1ddef39 {

// 0x00361760 FUN_00361760 (124 B): matches/0x00361760.cpp
// sym: ?FUN_00361760@fn_f1ddef39@@YAXXZ
// FUN_00361760 @ 0x00361760
void FUN_00361760()
{
    void* first = (*(void**)&DAT_004cd698);
    void* fourth = (*(void**)&DAT_004cd6a4);
    for (int i = 0; i < 8; i++) {
        ((Slot_361760*)&DAT_004cd6a8)[i].p = first;
    }
    void* second = (*(void**)&DAT_004cd69c);
    for (int i = 8; i < 16; i++) {
        ((Slot_361760*)&DAT_004cd6a8)[i].p = second;
    }
    void* third = (*(void**)&DAT_004cd6a0);
    ((Slot_361760*)&DAT_004cd6a8)[16].p = third;
    ((Slot_361760*)&DAT_004cd6a8)[17].p = fourth;
    ((Slot_361760*)&DAT_004cd6a8)[18].p = third;
    ((Slot_361760*)&DAT_004cd6a8)[19].p = fourth;
}


// 0x003617e0 FUN_003617e0 (17 B): matches/0x003617e0.cpp
// sym: ?FUN_003617e0@fn_f1ddef39@@YAXXZ
void FUN_003617e0() {
    FUN_002705f0();
    atexit(FUN_00364780);
}


// 0x00361800 FUN_00361800 (12 B): matches/0x00361800.cpp
// sym: ?FUN_00361800@fn_f1ddef39@@YAXXZ
void FUN_00361800() {
    atexit(FUN_00364790);
}


// 0x00361810 FUN_00361810 (13 B): matches/0x00361810.cpp
// sym: ?FUN_00361810@fn_f1ddef39@@YAXXZ
void FUN_00361810() {
    ((owners::Random_22aba0 *)&((*(G_361810*)&DAT_00554bfc)))->FUN_0022aba0(0);
}


// 0x00361820 FUN_00361820 (13 B): matches/0x00361820.cpp
// sym: ?FUN_00361820@fn_f1ddef39@@YAXXZ
void FUN_00361820() {
    ((owners::Random_22aba0 *)&((*(Obj_361820*)&DAT_00554c04)))->FUN_0022aba0(0);
}

} // namespace fn_f1ddef39

// 0x00361830 FUN_00361830 (12 B): matches/0x00361830.cpp [wrapped: conflict: _atexit]
// sym: ?FUN_00361830@fn_00361830@@YAXXZ
namespace fn_00361830 {
void __cdecl FUN_003647c0();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void __cdecl _atexit(void (*)());
#endif

void __cdecl FUN_00361830() {
    _atexit(FUN_003647c0);
}
} // namespace fn_00361830

namespace fn_f1ddef39 {

// 0x00361840 FUN_00361840 (12 B): matches/0x00361840.cpp
// sym: ?RegisterCleanup@fn_f1ddef39@@YAXXZ
void RegisterCleanup() {
    atexit(FUN_00364800);
}

} // namespace fn_f1ddef39

// 0x00361850 FUN_00361850 (65 B): equivalent/0x00361850.cpp [wrapped: conflict: DAT_004d4d80; DAT_004d4d84; DAT_004d4d88; DAT_004d4d8c (+4)]
// sym: ?FUN_00361850@fn_00361850@@YAXXZ
namespace fn_00361850 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00361850 @ 0x00361850
extern "C" void FUN_003285c0();
extern "C++" { extern void (*DAT_004d4d80)(); }
extern "C" int DAT_004d4d84;
extern "C" int DAT_004d4d88;
extern "C" int DAT_004d4d8c;
extern "C" int DAT_004d4d98;
extern "C" int DAT_004d4d9c;
extern "C" int DAT_004d4da0;
extern "C" int DAT_004d4da4;
void FUN_00361850() {
    DAT_004d4d8c = 0;
    DAT_004d4d80 = &FUN_003285c0;
    DAT_004d4da4 = -1;
    DAT_004d4d84 = 0;
    DAT_004d4d88 = 0;
    DAT_004d4d98 = 0;
    DAT_004d4d9c = 0;
    DAT_004d4da0 = 0;
}
} // namespace fn_00361850

namespace fn_f1ddef39 {

// 0x003618a0 FUN_003618a0 (149 B): equivalent/0x003618a0.cpp
// sym: ?FUN_003618a0@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003618a0 @ 0x003618a0
void FUN_003618a0()
{
    ((Entry_3618a0*)&DAT_004d4d08)[0].fn = FUN_00328580;
    ((Entry_3618a0*)&DAT_004d4d08)[0].a = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[0].b = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[0].c = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[1].fn = FUN_00328590;
    ((Entry_3618a0*)&DAT_004d4d08)[1].a = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[1].b = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[1].c = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[2].fn = FUN_003285a0;
    ((Entry_3618a0*)&DAT_004d4d08)[2].a = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[2].b = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[2].c = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[3].fn = FUN_003285b0;
    ((Entry_3618a0*)&DAT_004d4d08)[3].a = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[3].b = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[3].c = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[4].fn = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[4].a = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[4].b = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[4].c = -1;
}

} // namespace fn_f1ddef39

// 0x00361940 FUN_00361940 (93 B): equivalent/0x00361940.cpp [wrapped: conflict: DAT_004d4db0; DAT_004d4db4; DAT_004d4db8; DAT_004d4dbc (+8)]
// sym: ?FUN_00361940@fn_00361940@@YAXXZ
namespace fn_00361940 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00361940 @ 0x00361940
void FUN_00328560();
void FUN_003285d0();
extern void (*DAT_004d4db0)();
extern int DAT_004d4db4;
extern int DAT_004d4db8;
extern int DAT_004d4dbc;
extern void (*DAT_004d4dc8)();
extern int DAT_004d4dcc;
extern int DAT_004d4dd0;
extern int DAT_004d4dd4;
extern int DAT_004d4de0;
extern int DAT_004d4de4;
extern int DAT_004d4de8;
extern int DAT_004d4dec;
void FUN_00361940() {
    DAT_004d4db0 = &FUN_00328560;
    DAT_004d4dbc = 0;
    DAT_004d4dd4 = 0;
    DAT_004d4dc8 = &FUN_003285d0;
    DAT_004d4dec = -1;
    DAT_004d4db4 = 0;
    DAT_004d4db8 = 0;
    DAT_004d4dcc = 0;
    DAT_004d4dd0 = 0;
    DAT_004d4de0 = 0;
    DAT_004d4de4 = 0;
    DAT_004d4de8 = 0;
}
} // namespace fn_00361940

namespace fn_f1ddef39 {

// 0x003619a0 FUN_003619a0 (149 B): equivalent/0x003619a0.cpp
// sym: ?FUN_003619a0@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003619a0 @ 0x003619a0
// Static initialiser for a global table of 4 handler slots followed by a terminator.
void FUN_003619a0()
{
    (*(HandlerTable_3619a0*)&DAT_004d7a38).slot[0].fn = FUN_003337f0;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).slot[0].a = 0;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).slot[0].b = 0;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).slot[0].c = 0;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).slot[1].fn = FUN_00333800;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).slot[1].a = 0;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).slot[1].b = 0;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).slot[1].c = 0;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).slot[2].fn = FUN_00333820;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).slot[2].a = 0;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).slot[2].b = 0;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).slot[2].c = 0;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).slot[3].fn = FUN_00333810;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).slot[3].a = 0;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).slot[3].b = 0;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).slot[3].c = 0;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).end.a = 0;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).end.b = 0;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).end.c = 0;
    (*(HandlerTable_3619a0*)&DAT_004d7a38).end.last = -1;
}

} // namespace fn_f1ddef39

// 0x00361a40 FUN_00361a40 (65 B): equivalent/0x00361a40.cpp [wrapped: conflict: DAT_004d7990; DAT_004d7994; DAT_004d79a8]
// sym: ?FUN_00361a40@fn_00361a40@@YAXXZ
namespace fn_00361a40 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00361a40 @ 0x00361a40
void FUN_0032a4c0();
extern void (*DAT_004d7990)();
extern int DAT_004d7994, DAT_004d7998, DAT_004d799c;
extern int DAT_004d79a8, DAT_004d79ac, DAT_004d79b0, DAT_004d79b4;
void FUN_00361a40()
{
    DAT_004d799c = 0;
    DAT_004d7990 = &FUN_0032a4c0;
    DAT_004d79b4 = -1;
    DAT_004d7994 = 0;
    DAT_004d7998 = 0;
    DAT_004d79a8 = 0;
    DAT_004d79ac = 0;
    DAT_004d79b0 = 0;
}
} // namespace fn_00361a40

namespace fn_f1ddef39 {

// 0x00361a90 FUN_00361a90 (345 B): equivalent/0x00361a90.cpp
// sym: ?FUN_00361a90@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00361a90 @ 0x00361a90
void FUN_00361a90() {
    ((Entry_361a90*)&DAT_004d7ab0)[0].fn = FUN_003333c0;
    ((Entry_361a90*)&DAT_004d7ab0)[0].a = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[0].b = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[0].c = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[1].fn = FUN_003333e0;
    ((Entry_361a90*)&DAT_004d7ab0)[1].a = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[1].b = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[1].c = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[2].fn = FUN_003333f0;
    ((Entry_361a90*)&DAT_004d7ab0)[2].a = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[2].b = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[2].c = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[3].fn = FUN_003337d0;
    ((Entry_361a90*)&DAT_004d7ab0)[3].a = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[3].b = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[3].c = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[4].fn = FUN_00333770;
    ((Entry_361a90*)&DAT_004d7ab0)[4].a = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[4].b = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[4].c = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[5].fn = FUN_003333a0;
    ((Entry_361a90*)&DAT_004d7ab0)[5].a = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[5].b = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[5].c = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[6].fn = FUN_003333b0;
    ((Entry_361a90*)&DAT_004d7ab0)[6].a = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[6].b = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[6].c = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[7].fn = FUN_00333400;
    ((Entry_361a90*)&DAT_004d7ab0)[7].a = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[7].b = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[7].c = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[8].fn = FUN_0032a4f0;
    ((Entry_361a90*)&DAT_004d7ab0)[8].a = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[8].b = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[8].c = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[9].fn = FUN_0032a510;
    ((Entry_361a90*)&DAT_004d7ab0)[9].a = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[9].b = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[9].c = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[10].fn = FUN_0032a530;
    ((Entry_361a90*)&DAT_004d7ab0)[10].a = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[10].b = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[10].c = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[11].fn = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[11].a = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[11].b = 0;
    ((Entry_361a90*)&DAT_004d7ab0)[11].c = -1;
}


// 0x00361bf0 FUN_00361bf0 (149 B): equivalent/0x00361bf0.cpp
// sym: ?FUN_00361bf0@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00361bf0 @ 0x00361bf0
void FUN_00361bf0()
{
    ((Entry_361bf0*)&DAT_004d79c0)[0].fn = FUN_00333410;
    ((Entry_361bf0*)&DAT_004d79c0)[0].a = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[0].b = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[0].c = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[1].fn = FUN_00333780;
    ((Entry_361bf0*)&DAT_004d79c0)[1].a = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[1].b = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[1].c = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[2].fn = FUN_00333830;
    ((Entry_361bf0*)&DAT_004d79c0)[2].a = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[2].b = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[2].c = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[3].fn = FUN_0032ac50;
    ((Entry_361bf0*)&DAT_004d79c0)[3].a = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[3].b = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[3].c = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[4].fn = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[4].a = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[4].b = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[4].c = -1;
}

} // namespace fn_f1ddef39

// 0x00361c90 FUN_00361c90 (93 B): equivalent/0x00361c90.cpp [wrapped: conflict: DAT_004d7d68; DAT_004d7d6c; DAT_004d7d80; DAT_004d7d84 (+1)]
// sym: ?FUN_00361c90@fn_00361c90@@YAXXZ
namespace fn_00361c90 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00361c90 @ 0x00361c90
void FUN_0032b8e0();
void FUN_0032b910();
extern void (*DAT_004d7d68)();
extern int DAT_004d7d6c, DAT_004d7d70, DAT_004d7d74;
extern void (*DAT_004d7d80)();
extern int DAT_004d7d84, DAT_004d7d88, DAT_004d7d8c;
extern int DAT_004d7d98, DAT_004d7d9c, DAT_004d7da0, DAT_004d7da4;
void FUN_00361c90()
{
    DAT_004d7d68 = &FUN_0032b8e0;
    DAT_004d7d74 = 0;
    DAT_004d7d8c = 0;
    DAT_004d7d80 = &FUN_0032b910;
    DAT_004d7da4 = -1;
    DAT_004d7d6c = 0;
    DAT_004d7d70 = 0;
    DAT_004d7d84 = 0;
    DAT_004d7d88 = 0;
    DAT_004d7d98 = 0;
    DAT_004d7d9c = 0;
    DAT_004d7da0 = 0;
}
} // namespace fn_00361c90

namespace fn_f1ddef39 {

// 0x00361cf0 FUN_00361cf0 (345 B): equivalent/0x00361cf0.cpp
// sym: ?FUN_00361cf0@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00361cf0 @ 0x00361cf0
void FUN_00361cf0()
{
    (*(Entry_361cf0*)&DAT_004d7c48).fn = FUN_003333c0;
    (*(Entry_361cf0*)&DAT_004d7c60).fn = FUN_003333e0;
    (*(Entry_361cf0*)&DAT_004d7c78).fn = FUN_003333f0;
    (*(Entry_361cf0*)&DAT_004d7c90).fn = FUN_003337d0;
    (*(Entry_361cf0*)&DAT_004d7ca8).fn = FUN_00333770;
    (*(Entry_361cf0*)&DAT_004d7cc0).fn = FUN_003333a0;
    (*(Entry_361cf0*)&DAT_004d7cd8).fn = FUN_003333b0;
    (*(Entry_361cf0*)&DAT_004d7cf0).fn = FUN_00333400;
    (*(Entry_361cf0*)&DAT_004d7d08).fn = FUN_0032b940;
    (*(Entry_361cf0*)&DAT_004d7d20).fn = FUN_0032b960;
    (*(Entry_361cf0*)&DAT_004d7d38).fn = FUN_0032b980;
    (*(Entry_361cf0*)&DAT_004d7c48).a = 0;
    (*(Entry_361cf0*)&DAT_004d7c48).b = 0;
    (*(Entry_361cf0*)&DAT_004d7c48).c = 0;
    (*(Entry_361cf0*)&DAT_004d7c60).a = 0;
    (*(Entry_361cf0*)&DAT_004d7c60).b = 0;
    (*(Entry_361cf0*)&DAT_004d7c60).c = 0;
    (*(Entry_361cf0*)&DAT_004d7c78).a = 0;
    (*(Entry_361cf0*)&DAT_004d7c78).b = 0;
    (*(Entry_361cf0*)&DAT_004d7c78).c = 0;
    (*(Entry_361cf0*)&DAT_004d7c90).a = 0;
    (*(Entry_361cf0*)&DAT_004d7c90).b = 0;
    (*(Entry_361cf0*)&DAT_004d7c90).c = 0;
    (*(Entry_361cf0*)&DAT_004d7ca8).a = 0;
    (*(Entry_361cf0*)&DAT_004d7ca8).b = 0;
    (*(Entry_361cf0*)&DAT_004d7ca8).c = 0;
    (*(Entry_361cf0*)&DAT_004d7cc0).a = 0;
    (*(Entry_361cf0*)&DAT_004d7cc0).b = 0;
    (*(Entry_361cf0*)&DAT_004d7cc0).c = 0;
    (*(Entry_361cf0*)&DAT_004d7cd8).a = 0;
    (*(Entry_361cf0*)&DAT_004d7cd8).b = 0;
    (*(Entry_361cf0*)&DAT_004d7cd8).c = 0;
    (*(Entry_361cf0*)&DAT_004d7cf0).a = 0;
    (*(Entry_361cf0*)&DAT_004d7cf0).b = 0;
    (*(Entry_361cf0*)&DAT_004d7cf0).c = 0;
    (*(Entry_361cf0*)&DAT_004d7d08).a = 0;
    (*(Entry_361cf0*)&DAT_004d7d08).b = 0;
    (*(Entry_361cf0*)&DAT_004d7d08).c = 0;
    (*(Entry_361cf0*)&DAT_004d7d20).a = 0;
    (*(Entry_361cf0*)&DAT_004d7d20).b = 0;
    (*(Entry_361cf0*)&DAT_004d7d20).c = 0;
    (*(Entry_361cf0*)&DAT_004d7d38).a = 0;
    (*(Entry_361cf0*)&DAT_004d7d38).b = 0;
    (*(Entry_361cf0*)&DAT_004d7d38).c = 0;
    (*(LastEntry*)&DAT_004d7d50).a = 0;
    (*(LastEntry*)&DAT_004d7d50).b = 0;
    (*(LastEntry*)&DAT_004d7d50).c = 0;
    (*(LastEntry*)&DAT_004d7d50).d = -1;
}


// 0x00361e50 FUN_00361e50 (149 B): equivalent/0x00361e50.cpp
// sym: ?FUN_00361e50@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00361e50 @ 0x00361e50
// Static initialiser for a global table of 4 handler slots followed by a terminator.
void FUN_00361e50()
{
    (*(HandlerTable_361e50*)&DAT_004d7db0).slot[0].fn = FUN_00333410;
    (*(HandlerTable_361e50*)&DAT_004d7db0).slot[0].a = 0;
    (*(HandlerTable_361e50*)&DAT_004d7db0).slot[0].b = 0;
    (*(HandlerTable_361e50*)&DAT_004d7db0).slot[0].c = 0;
    (*(HandlerTable_361e50*)&DAT_004d7db0).slot[1].fn = FUN_00333780;
    (*(HandlerTable_361e50*)&DAT_004d7db0).slot[1].a = 0;
    (*(HandlerTable_361e50*)&DAT_004d7db0).slot[1].b = 0;
    (*(HandlerTable_361e50*)&DAT_004d7db0).slot[1].c = 0;
    (*(HandlerTable_361e50*)&DAT_004d7db0).slot[2].fn = FUN_00333830;
    (*(HandlerTable_361e50*)&DAT_004d7db0).slot[2].a = 0;
    (*(HandlerTable_361e50*)&DAT_004d7db0).slot[2].b = 0;
    (*(HandlerTable_361e50*)&DAT_004d7db0).slot[2].c = 0;
    (*(HandlerTable_361e50*)&DAT_004d7db0).slot[3].fn = FUN_0032bac0;
    (*(HandlerTable_361e50*)&DAT_004d7db0).slot[3].a = 0;
    (*(HandlerTable_361e50*)&DAT_004d7db0).slot[3].b = 0;
    (*(HandlerTable_361e50*)&DAT_004d7db0).slot[3].c = 0;
    (*(HandlerTable_361e50*)&DAT_004d7db0).end.a = 0;
    (*(HandlerTable_361e50*)&DAT_004d7db0).end.b = 0;
    (*(HandlerTable_361e50*)&DAT_004d7db0).end.c = 0;
    (*(HandlerTable_361e50*)&DAT_004d7db0).end.last = -1;
}

} // namespace fn_f1ddef39

// 0x00361ef0 FUN_00361ef0 (93 B): equivalent/0x00361ef0.cpp [wrapped: conflict: DAT_004d7f58; DAT_004d7f5c; DAT_004d7f70; DAT_004d7f74 (+1)]
// sym: ?FUN_00361ef0@fn_00361ef0@@YAXXZ
namespace fn_00361ef0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00361ef0 @ 0x00361ef0
void FUN_0032c420();
void FUN_0032c450();
extern void (*DAT_004d7f58)();
extern int DAT_004d7f5c, DAT_004d7f60, DAT_004d7f64;
extern void (*DAT_004d7f70)();
extern int DAT_004d7f74, DAT_004d7f78, DAT_004d7f7c;
extern int DAT_004d7f88, DAT_004d7f8c, DAT_004d7f90, DAT_004d7f94;
void FUN_00361ef0() {
    DAT_004d7f58 = FUN_0032c420;
    DAT_004d7f64 = 0;
    DAT_004d7f7c = 0;
    DAT_004d7f70 = FUN_0032c450;
    DAT_004d7f94 = -1;
    DAT_004d7f5c = 0;
    DAT_004d7f60 = 0;
    DAT_004d7f74 = 0;
    DAT_004d7f78 = 0;
    DAT_004d7f88 = 0;
    DAT_004d7f8c = 0;
    DAT_004d7f90 = 0;
}
} // namespace fn_00361ef0

namespace fn_f1ddef39 {

// 0x00361f50 FUN_00361f50 (177 B): equivalent/0x00361f50.cpp
// sym: ?FUN_00361f50@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00361f50 @ 0x00361f50
// Static init of a six-entry handler table (shared callbacks; entry 4 gets its own).
void FUN_00361f50() {
    Slot_361f50 *t = ((Slot_361f50*)&DAT_004d7ec8);
    t[0].handler = FUN_003337f0;
    t[1].handler = FUN_00333800;
    t[2].handler = FUN_00333820;
    t[3].handler = FUN_00333810;
    t[4].handler = FUN_0032c480;
    for (int i = 0; i < 5; i++) {
        t[i].a = 0;
        t[i].b = 0;
        t[i].c = 0;
    }
    t[5].handler = 0;
    t[5].a = 0;
    t[5].b = 0;
    t[5].c = -1;
}


// 0x00362010 FUN_00362010 (261 B): equivalent/0x00362010.cpp
// sym: ?FUN_00362010@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362010 @ 0x00362010
// Static initialiser for a global table of 8 handler slots followed by a terminator.
void FUN_00362010()
{
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[0].fn = FUN_003333c0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[0].a = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[0].b = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[0].c = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[1].fn = FUN_003333e0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[1].a = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[1].b = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[1].c = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[2].fn = FUN_003333f0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[2].a = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[2].b = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[2].c = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[3].fn = FUN_003337d0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[3].a = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[3].b = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[3].c = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[4].fn = FUN_00333770;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[4].a = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[4].b = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[4].c = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[5].fn = FUN_003333a0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[5].a = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[5].b = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[5].c = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[6].fn = FUN_003333b0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[6].a = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[6].b = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[6].c = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[7].fn = FUN_00333400;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[7].a = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[7].b = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).slot[7].c = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).end.a = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).end.b = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).end.c = 0;
    (*(HandlerTable_362010*)&DAT_004d7fa0).end.last = -1;
}


// 0x00362120 FUN_00362120 (121 B): equivalent/0x00362120.cpp
// sym: ?FUN_00362120@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362120 @ 0x00362120
void FUN_00362120()
{
    ((Entry_362120*)&DAT_004d7e68)[0].fn = FUN_00333410;
    ((Entry_362120*)&DAT_004d7e68)[0].a = 0;
    ((Entry_362120*)&DAT_004d7e68)[0].b = 0;
    ((Entry_362120*)&DAT_004d7e68)[0].c = 0;
    ((Entry_362120*)&DAT_004d7e68)[1].fn = FUN_00333780;
    ((Entry_362120*)&DAT_004d7e68)[1].a = 0;
    ((Entry_362120*)&DAT_004d7e68)[1].b = 0;
    ((Entry_362120*)&DAT_004d7e68)[1].c = 0;
    ((Entry_362120*)&DAT_004d7e68)[2].fn = FUN_00333830;
    ((Entry_362120*)&DAT_004d7e68)[2].a = 0;
    ((Entry_362120*)&DAT_004d7e68)[2].b = 0;
    ((Entry_362120*)&DAT_004d7e68)[2].c = 0;
    ((Entry_362120*)&DAT_004d7e68)[3].fn = 0;
    ((Entry_362120*)&DAT_004d7e68)[3].a = 0;
    ((Entry_362120*)&DAT_004d7e68)[3].b = 0;
    ((Entry_362120*)&DAT_004d7e68)[3].c = -1;
}


// 0x003621a0 FUN_003621a0 (149 B): equivalent/0x003621a0.cpp
// sym: ?FUN_003621a0@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003621a0 @ 0x003621a0
void FUN_003621a0()
{
    ((Entry_3621a0*)&DAT_004d8198)[0].fn = FUN_003337f0;
    ((Entry_3621a0*)&DAT_004d8198)[0].a = 0;
    ((Entry_3621a0*)&DAT_004d8198)[0].b = 0;
    ((Entry_3621a0*)&DAT_004d8198)[0].c = 0;
    ((Entry_3621a0*)&DAT_004d8198)[1].fn = FUN_00333800;
    ((Entry_3621a0*)&DAT_004d8198)[1].a = 0;
    ((Entry_3621a0*)&DAT_004d8198)[1].b = 0;
    ((Entry_3621a0*)&DAT_004d8198)[1].c = 0;
    ((Entry_3621a0*)&DAT_004d8198)[2].fn = FUN_00333820;
    ((Entry_3621a0*)&DAT_004d8198)[2].a = 0;
    ((Entry_3621a0*)&DAT_004d8198)[2].b = 0;
    ((Entry_3621a0*)&DAT_004d8198)[2].c = 0;
    ((Entry_3621a0*)&DAT_004d8198)[3].fn = FUN_00333810;
    ((Entry_3621a0*)&DAT_004d8198)[3].a = 0;
    ((Entry_3621a0*)&DAT_004d8198)[3].b = 0;
    ((Entry_3621a0*)&DAT_004d8198)[3].c = 0;
    ((Entry_3621a0*)&DAT_004d8198)[4].fn = 0;
    ((Entry_3621a0*)&DAT_004d8198)[4].a = 0;
    ((Entry_3621a0*)&DAT_004d8198)[4].b = 0;
    ((Entry_3621a0*)&DAT_004d8198)[4].c = -1;
}


// 0x00362240 FUN_00362240 (93 B): equivalent/0x00362240.cpp
// sym: ?FUN_00362240@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362240 @ 0x00362240
void FUN_00362240() {
    (*(StateA*)&DAT_004d8150).callback = FUN_0032cb40;
    (*(StateA*)&DAT_004d8150).first = 0;
    (*(StateA*)&DAT_004d8150).second = 0;
    (*(StateA*)&DAT_004d8150).third = 0;
    (*(StateB*)&DAT_004d8168).callback = FUN_0032cb70;
    (*(StateB*)&DAT_004d8168).first = 0;
    (*(StateB*)&DAT_004d8168).second = 0;
    (*(StateB*)&DAT_004d8168).third = 0;
    (*(StateC*)&DAT_004d8180).first = 0;
    (*(StateC*)&DAT_004d8180).second = 0;
    (*(StateC*)&DAT_004d8180).third = 0;
    (*(StateC*)&DAT_004d8180).fourth = -1;
}


// 0x003622a0 FUN_003622a0 (261 B): equivalent/0x003622a0.cpp
// sym: ?FUN_003622a0@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003622a0 @ 0x003622a0
// Static initialiser for a global table of 8 handler slots followed by a terminator.
void FUN_003622a0()
{
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[0].fn = FUN_003333c0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[0].a = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[0].b = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[0].c = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[1].fn = FUN_003333e0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[1].a = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[1].b = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[1].c = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[2].fn = FUN_003333f0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[2].a = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[2].b = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[2].c = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[3].fn = FUN_003337d0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[3].a = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[3].b = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[3].c = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[4].fn = FUN_00333770;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[4].a = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[4].b = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[4].c = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[5].fn = FUN_003333a0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[5].a = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[5].b = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[5].c = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[6].fn = FUN_003333b0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[6].a = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[6].b = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[6].c = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[7].fn = FUN_00333400;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[7].a = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[7].b = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).slot[7].c = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).end.a = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).end.b = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).end.c = 0;
    (*(HandlerTable_3622a0*)&DAT_004d8210).end.last = -1;
}


// 0x003623b0 FUN_003623b0 (121 B): equivalent/0x003623b0.cpp
// sym: ?FUN_003623b0@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003623b0 @ 0x003623b0
// Static initialiser for a global table of 3 handler slots followed by a terminator.
void FUN_003623b0()
{
    (*(HandlerTable_3623b0*)&DAT_004d80f0).slot[0].fn = FUN_00333410;
    (*(HandlerTable_3623b0*)&DAT_004d80f0).slot[0].a = 0;
    (*(HandlerTable_3623b0*)&DAT_004d80f0).slot[0].b = 0;
    (*(HandlerTable_3623b0*)&DAT_004d80f0).slot[0].c = 0;
    (*(HandlerTable_3623b0*)&DAT_004d80f0).slot[1].fn = FUN_00333780;
    (*(HandlerTable_3623b0*)&DAT_004d80f0).slot[1].a = 0;
    (*(HandlerTable_3623b0*)&DAT_004d80f0).slot[1].b = 0;
    (*(HandlerTable_3623b0*)&DAT_004d80f0).slot[1].c = 0;
    (*(HandlerTable_3623b0*)&DAT_004d80f0).slot[2].fn = FUN_00333830;
    (*(HandlerTable_3623b0*)&DAT_004d80f0).slot[2].a = 0;
    (*(HandlerTable_3623b0*)&DAT_004d80f0).slot[2].b = 0;
    (*(HandlerTable_3623b0*)&DAT_004d80f0).slot[2].c = 0;
    (*(HandlerTable_3623b0*)&DAT_004d80f0).end.a = 0;
    (*(HandlerTable_3623b0*)&DAT_004d80f0).end.b = 0;
    (*(HandlerTable_3623b0*)&DAT_004d80f0).end.c = 0;
    (*(HandlerTable_3623b0*)&DAT_004d80f0).end.last = -1;
}

} // namespace fn_f1ddef39

// 0x00362430 FUN_00362430 (65 B): equivalent/0x00362430.cpp [wrapped: conflict: DAT_004d80c0; DAT_004d80c4; DAT_004d80c8; DAT_004d80cc (+4)]
// sym: ?FUN_00362430@fn_00362430@@YAXXZ
namespace fn_00362430 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362430 @ 0x00362430
void FUN_0032cba0();
extern void (*DAT_004d80c0)();
extern int DAT_004d80c4;
extern int DAT_004d80c8;
extern int DAT_004d80cc;
extern int DAT_004d80d8;
extern int DAT_004d80dc;
extern int DAT_004d80e0;
extern int DAT_004d80e4;
void FUN_00362430() {
    DAT_004d80cc = 0;
    DAT_004d80c0 = FUN_0032cba0;
    DAT_004d80e4 = -1;
    DAT_004d80c4 = 0;
    DAT_004d80c8 = 0;
    DAT_004d80d8 = 0;
    DAT_004d80dc = 0;
    DAT_004d80e0 = 0;
}
} // namespace fn_00362430


// 0x00362480 FUN_00362480 (65 B): equivalent/0x00362480.cpp [wrapped: conflict: DAT_004d83a8; DAT_004d83ac; DAT_004d83b0; DAT_004d83b4 (+4)]
// sym: ?FUN_00362480@fn_00362480@@YAXXZ
namespace fn_00362480 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362480 @ 0x00362480
void FUN_0032d260();
extern void (*DAT_004d83a8)();
extern int DAT_004d83ac;
extern int DAT_004d83b0;
extern int DAT_004d83b4;
extern int DAT_004d83c0;
extern int DAT_004d83c4;
extern int DAT_004d83c8;
extern int DAT_004d83cc;
void FUN_00362480() {
    DAT_004d83b4 = 0;
    DAT_004d83a8 = FUN_0032d260;
    DAT_004d83cc = -1;
    DAT_004d83ac = 0;
    DAT_004d83b0 = 0;
    DAT_004d83c0 = 0;
    DAT_004d83c4 = 0;
    DAT_004d83c8 = 0;
}
} // namespace fn_00362480

namespace fn_f1ddef39 {

// 0x003624d0 FUN_003624d0 (149 B): equivalent/0x003624d0.cpp
// sym: ?FUN_003624d0@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003624d0 @ 0x003624d0
// Static initialiser for a global table of 4 handler slots followed by a terminator.
void FUN_003624d0()
{
    (*(HandlerTable_3624d0*)&DAT_004d8330).slot[0].fn = FUN_0032d290;
    (*(HandlerTable_3624d0*)&DAT_004d8330).slot[0].a = 0;
    (*(HandlerTable_3624d0*)&DAT_004d8330).slot[0].b = 0;
    (*(HandlerTable_3624d0*)&DAT_004d8330).slot[0].c = 0;
    (*(HandlerTable_3624d0*)&DAT_004d8330).slot[1].fn = FUN_00333770;
    (*(HandlerTable_3624d0*)&DAT_004d8330).slot[1].a = 0;
    (*(HandlerTable_3624d0*)&DAT_004d8330).slot[1].b = 0;
    (*(HandlerTable_3624d0*)&DAT_004d8330).slot[1].c = 0;
    (*(HandlerTable_3624d0*)&DAT_004d8330).slot[2].fn = FUN_003333a0;
    (*(HandlerTable_3624d0*)&DAT_004d8330).slot[2].a = 0;
    (*(HandlerTable_3624d0*)&DAT_004d8330).slot[2].b = 0;
    (*(HandlerTable_3624d0*)&DAT_004d8330).slot[2].c = 0;
    (*(HandlerTable_3624d0*)&DAT_004d8330).slot[3].fn = FUN_003333b0;
    (*(HandlerTable_3624d0*)&DAT_004d8330).slot[3].a = 0;
    (*(HandlerTable_3624d0*)&DAT_004d8330).slot[3].b = 0;
    (*(HandlerTable_3624d0*)&DAT_004d8330).slot[3].c = 0;
    (*(HandlerTable_3624d0*)&DAT_004d8330).end.a = 0;
    (*(HandlerTable_3624d0*)&DAT_004d8330).end.b = 0;
    (*(HandlerTable_3624d0*)&DAT_004d8330).end.c = 0;
    (*(HandlerTable_3624d0*)&DAT_004d8330).end.last = -1;
}


// 0x00362570 FUN_00362570 (233 B): equivalent/0x00362570.cpp
// sym: ?FUN_00362570@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362570 @ 0x00362570
// Static initialiser for a global table of 7 handler slots followed by a terminator.
void FUN_00362570()
{
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[0].fn = FUN_0032d2b0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[0].a = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[0].b = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[0].c = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[1].fn = FUN_0032d2c0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[1].a = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[1].b = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[1].c = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[2].fn = FUN_0032d2d0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[2].a = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[2].b = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[2].c = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[3].fn = FUN_0032d2e0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[3].a = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[3].b = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[3].c = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[4].fn = FUN_0032d2f0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[4].a = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[4].b = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[4].c = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[5].fn = FUN_0032d300;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[5].a = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[5].b = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[5].c = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[6].fn = FUN_0032d310;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[6].a = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[6].b = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).slot[6].c = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).end.a = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).end.b = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).end.c = 0;
    (*(HandlerTable_362570*)&DAT_004d83d8).end.last = -1;
}

} // namespace fn_f1ddef39

// 0x00362660 FUN_00362660 (93 B): equivalent/0x00362660.cpp [wrapped: conflict: DAT_004d8698; DAT_004d869c; DAT_004d86b0; DAT_004d86b4 (+1)]
// sym: ?FUN_00362660@fn_00362660@@YAXXZ
namespace fn_00362660 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362660 @ 0x00362660
void FUN_0032d9d0();
void FUN_0032da00();
extern void (*DAT_004d8698)();
extern int DAT_004d869c, DAT_004d86a0, DAT_004d86a4;
extern void (*DAT_004d86b0)();
extern int DAT_004d86b4, DAT_004d86b8, DAT_004d86bc;
extern int DAT_004d86c8, DAT_004d86cc, DAT_004d86d0, DAT_004d86d4;
void FUN_00362660() {
    DAT_004d8698 = FUN_0032d9d0;
    DAT_004d86a4 = 0;
    DAT_004d86bc = 0;
    DAT_004d86b0 = FUN_0032da00;
    DAT_004d86d4 = -1;
    DAT_004d869c = 0;
    DAT_004d86a0 = 0;
    DAT_004d86b4 = 0;
    DAT_004d86b8 = 0;
    DAT_004d86c8 = 0;
    DAT_004d86cc = 0;
    DAT_004d86d0 = 0;
}
} // namespace fn_00362660

namespace fn_f1ddef39 {

// 0x003626c0 FUN_003626c0 (401 B): equivalent/0x003626c0.cpp
// sym: ?FUN_003626c0@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003626c0 @ 0x003626c0
void FUN_003626c0()
{
    (*(Entry_3626c0*)&DAT_004d84d0).fn = FUN_003333c0;
    (*(Entry_3626c0*)&DAT_004d84e8).fn = FUN_003333e0;
    (*(Entry_3626c0*)&DAT_004d8500).fn = FUN_003333f0;
    (*(Entry_3626c0*)&DAT_004d8518).fn = FUN_003337d0;
    (*(Entry_3626c0*)&DAT_004d8530).fn = FUN_00333770;
    (*(Entry_3626c0*)&DAT_004d8548).fn = FUN_003333a0;
    (*(Entry_3626c0*)&DAT_004d8560).fn = FUN_003333b0;
    (*(Entry_3626c0*)&DAT_004d8578).fn = FUN_00333400;
    (*(Entry_3626c0*)&DAT_004d8590).fn = FUN_0032da30;
    (*(Entry_3626c0*)&DAT_004d85a8).fn = FUN_0032d8d0;
    (*(Entry_3626c0*)&DAT_004d85c0).fn = FUN_0032dab0;
    (*(Entry_3626c0*)&DAT_004d85d8).fn = FUN_0032dad0;
    (*(Entry_3626c0*)&DAT_004d85f0).fn = FUN_0032daf0;
    (*(Entry_3626c0*)&DAT_004d84d0).a = 0;
    (*(Entry_3626c0*)&DAT_004d84d0).b = 0;
    (*(Entry_3626c0*)&DAT_004d84d0).c = 0;
    (*(Entry_3626c0*)&DAT_004d84e8).a = 0;
    (*(Entry_3626c0*)&DAT_004d84e8).b = 0;
    (*(Entry_3626c0*)&DAT_004d84e8).c = 0;
    (*(Entry_3626c0*)&DAT_004d8500).a = 0;
    (*(Entry_3626c0*)&DAT_004d8500).b = 0;
    (*(Entry_3626c0*)&DAT_004d8500).c = 0;
    (*(Entry_3626c0*)&DAT_004d8518).a = 0;
    (*(Entry_3626c0*)&DAT_004d8518).b = 0;
    (*(Entry_3626c0*)&DAT_004d8518).c = 0;
    (*(Entry_3626c0*)&DAT_004d8530).a = 0;
    (*(Entry_3626c0*)&DAT_004d8530).b = 0;
    (*(Entry_3626c0*)&DAT_004d8530).c = 0;
    (*(Entry_3626c0*)&DAT_004d8548).a = 0;
    (*(Entry_3626c0*)&DAT_004d8548).b = 0;
    (*(Entry_3626c0*)&DAT_004d8548).c = 0;
    (*(Entry_3626c0*)&DAT_004d8560).a = 0;
    (*(Entry_3626c0*)&DAT_004d8560).b = 0;
    (*(Entry_3626c0*)&DAT_004d8560).c = 0;
    (*(Entry_3626c0*)&DAT_004d8578).a = 0;
    (*(Entry_3626c0*)&DAT_004d8578).b = 0;
    (*(Entry_3626c0*)&DAT_004d8578).c = 0;
    (*(Entry_3626c0*)&DAT_004d8590).a = 0;
    (*(Entry_3626c0*)&DAT_004d8590).b = 0;
    (*(Entry_3626c0*)&DAT_004d8590).c = 0;
    (*(Entry_3626c0*)&DAT_004d85a8).a = 0;
    (*(Entry_3626c0*)&DAT_004d85a8).b = 0;
    (*(Entry_3626c0*)&DAT_004d85a8).c = 0;
    (*(Entry_3626c0*)&DAT_004d85c0).a = 0;
    (*(Entry_3626c0*)&DAT_004d85c0).b = 0;
    (*(Entry_3626c0*)&DAT_004d85c0).c = 0;
    (*(Entry_3626c0*)&DAT_004d85d8).a = 0;
    (*(Entry_3626c0*)&DAT_004d85d8).b = 0;
    (*(Entry_3626c0*)&DAT_004d85d8).c = 0;
    (*(Entry_3626c0*)&DAT_004d85f0).a = 0;
    (*(Entry_3626c0*)&DAT_004d85f0).b = 0;
    (*(Entry_3626c0*)&DAT_004d85f0).c = 0;
    (*(LastEntry*)&DAT_004d8608).a = 0;
    (*(LastEntry*)&DAT_004d8608).b = 0;
    (*(LastEntry*)&DAT_004d8608).c = 0;
    (*(LastEntry*)&DAT_004d8608).d = -1;
}


// 0x00362860 FUN_00362860 (149 B): equivalent/0x00362860.cpp
// sym: ?FUN_00362860@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362860 @ 0x00362860
void FUN_00362860()
{
    ((Entry_362860*)&DAT_004d86e0)[0].fn = FUN_003337f0;
    ((Entry_362860*)&DAT_004d86e0)[0].a = 0;
    ((Entry_362860*)&DAT_004d86e0)[0].b = 0;
    ((Entry_362860*)&DAT_004d86e0)[0].c = 0;
    ((Entry_362860*)&DAT_004d86e0)[1].fn = FUN_00333800;
    ((Entry_362860*)&DAT_004d86e0)[1].a = 0;
    ((Entry_362860*)&DAT_004d86e0)[1].b = 0;
    ((Entry_362860*)&DAT_004d86e0)[1].c = 0;
    ((Entry_362860*)&DAT_004d86e0)[2].fn = FUN_00333820;
    ((Entry_362860*)&DAT_004d86e0)[2].a = 0;
    ((Entry_362860*)&DAT_004d86e0)[2].b = 0;
    ((Entry_362860*)&DAT_004d86e0)[2].c = 0;
    ((Entry_362860*)&DAT_004d86e0)[3].fn = FUN_00333810;
    ((Entry_362860*)&DAT_004d86e0)[3].a = 0;
    ((Entry_362860*)&DAT_004d86e0)[3].b = 0;
    ((Entry_362860*)&DAT_004d86e0)[3].c = 0;
    ((Entry_362860*)&DAT_004d86e0)[4].fn = 0;
    ((Entry_362860*)&DAT_004d86e0)[4].a = 0;
    ((Entry_362860*)&DAT_004d86e0)[4].b = 0;
    ((Entry_362860*)&DAT_004d86e0)[4].c = -1;
}


// 0x00362900 FUN_00362900 (149 B): equivalent/0x00362900.cpp
// sym: ?FUN_00362900@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362900 @ 0x00362900
// Static initialiser for a global table of 4 handler slots followed by a terminator.
void FUN_00362900()
{
    (*(HandlerTable_362900*)&DAT_004d8620).slot[0].fn = FUN_00333410;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[0].a = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[0].b = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[0].c = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[1].fn = FUN_00333780;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[1].a = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[1].b = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[1].c = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[2].fn = FUN_00333830;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[2].a = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[2].b = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[2].c = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[3].fn = FUN_0032e090;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[3].a = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[3].b = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[3].c = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).end.a = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).end.b = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).end.c = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).end.last = -1;
}


// 0x003629a0 FUN_003629a0 (121 B): equivalent/0x003629a0.cpp
// sym: ?FUN_003629a0@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003629a0 @ 0x003629a0
void FUN_003629a0()
{
    ((Entry_3629a0*)&DAT_004d87a0)[0].fn = FUN_0032d9d0;
    ((Entry_3629a0*)&DAT_004d87a0)[0].a = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[0].b = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[0].c = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[1].fn = FUN_0032da00;
    ((Entry_3629a0*)&DAT_004d87a0)[1].a = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[1].b = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[1].c = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[2].fn = FUN_0032eb10;
    ((Entry_3629a0*)&DAT_004d87a0)[2].a = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[2].b = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[2].c = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[3].fn = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[3].a = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[3].b = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[3].c = -1;
}


// 0x00362a20 FUN_00362a20 (177 B): equivalent/0x00362a20.cpp
// sym: ?FUN_00362a20@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362a20 @ 0x00362a20
// Static init of a six-entry handler table (shared callbacks; entry 4 gets its own).
void FUN_00362a20() {
    Slot_362a20 *t = ((Slot_362a20*)&DAT_004d88f0);
    t[0].handler = FUN_003337f0;
    t[1].handler = FUN_00333800;
    t[2].handler = FUN_00333820;
    t[3].handler = FUN_00333810;
    t[4].handler = FUN_0032ef00;
    for (int i = 0; i < 5; i++) {
        t[i].a = 0;
        t[i].b = 0;
        t[i].c = 0;
    }
    t[5].handler = 0;
    t[5].a = 0;
    t[5].b = 0;
    t[5].c = -1;
}

} // namespace fn_f1ddef39

// 0x00362ae0 FUN_00362ae0 (65 B): equivalent/0x00362ae0.cpp [wrapped: conflict: DAT_004d88c0; DAT_004d88c4; DAT_004d88d8]
// sym: ?FUN_00362ae0@fn_00362ae0@@YAXXZ
namespace fn_00362ae0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362ae0 @ 0x00362ae0
void FUN_0032f210();
extern void (*DAT_004d88c0)();
extern int DAT_004d88c4, DAT_004d88c8, DAT_004d88cc;
extern int DAT_004d88d8, DAT_004d88dc, DAT_004d88e0, DAT_004d88e4;
void FUN_00362ae0() {
    DAT_004d88cc = 0;
    DAT_004d88c0 = FUN_0032f210;
    DAT_004d88e4 = -1;
    DAT_004d88c4 = 0;
    DAT_004d88c8 = 0;
    DAT_004d88d8 = 0;
    DAT_004d88dc = 0;
    DAT_004d88e0 = 0;
}
} // namespace fn_00362ae0

namespace fn_f1ddef39 {

// 0x00362b30 FUN_00362b30 (261 B): equivalent/0x00362b30.cpp
// sym: ?FUN_00362b30@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362b30 @ 0x00362b30
// Static initialiser for a global table of 8 handler slots followed by a terminator.
void FUN_00362b30()
{
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[0].fn = FUN_003333c0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[0].a = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[0].b = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[0].c = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[1].fn = FUN_003333e0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[1].a = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[1].b = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[1].c = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[2].fn = FUN_003333f0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[2].a = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[2].b = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[2].c = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[3].fn = FUN_003337d0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[3].a = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[3].b = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[3].c = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[4].fn = FUN_00333770;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[4].a = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[4].b = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[4].c = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[5].fn = FUN_003333a0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[5].a = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[5].b = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[5].c = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[6].fn = FUN_003333b0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[6].a = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[6].b = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[6].c = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[7].fn = FUN_00333400;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[7].a = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[7].b = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[7].c = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).end.a = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).end.b = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).end.c = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).end.last = -1;
}


// 0x00362c40 FUN_00362c40 (149 B): equivalent/0x00362c40.cpp
// sym: ?FUN_00362c40@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362c40 @ 0x00362c40
void FUN_00362c40()
{
    ((Entry_362c40*)&DAT_004d8848)[0].fn = FUN_00333410;
    ((Entry_362c40*)&DAT_004d8848)[0].a = 0;
    ((Entry_362c40*)&DAT_004d8848)[0].b = 0;
    ((Entry_362c40*)&DAT_004d8848)[0].c = 0;
    ((Entry_362c40*)&DAT_004d8848)[1].fn = FUN_00333780;
    ((Entry_362c40*)&DAT_004d8848)[1].a = 0;
    ((Entry_362c40*)&DAT_004d8848)[1].b = 0;
    ((Entry_362c40*)&DAT_004d8848)[1].c = 0;
    ((Entry_362c40*)&DAT_004d8848)[2].fn = FUN_00333830;
    ((Entry_362c40*)&DAT_004d8848)[2].a = 0;
    ((Entry_362c40*)&DAT_004d8848)[2].b = 0;
    ((Entry_362c40*)&DAT_004d8848)[2].c = 0;
    ((Entry_362c40*)&DAT_004d8848)[3].fn = FUN_0032eee0;
    ((Entry_362c40*)&DAT_004d8848)[3].a = 0;
    ((Entry_362c40*)&DAT_004d8848)[3].b = 0;
    ((Entry_362c40*)&DAT_004d8848)[3].c = 0;
    ((Entry_362c40*)&DAT_004d8848)[4].fn = FUN_0032eef0;
    ((Entry_362c40*)&DAT_004d8848)[4].a = 0;
    ((Entry_362c40*)&DAT_004d8848)[4].b = 0;
    ((Entry_362c40*)&DAT_004d8848)[4].c = 0;
}

} // namespace fn_f1ddef39

// 0x00362ce0 FUN_00362ce0 (65 B): equivalent/0x00362ce0.cpp [wrapped: conflict: DAT_004d8b48; DAT_004d8b4c; DAT_004d8b60]
// sym: ?FUN_00362ce0@fn_00362ce0@@YAXXZ
namespace fn_00362ce0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362ce0 @ 0x00362ce0
void FUN_0032ff60();
extern void (*DAT_004d8b48)();
extern int DAT_004d8b4c, DAT_004d8b50, DAT_004d8b54;
extern int DAT_004d8b60, DAT_004d8b64, DAT_004d8b68, DAT_004d8b6c;
void FUN_00362ce0() {
    DAT_004d8b54 = 0;
    DAT_004d8b48 = FUN_0032ff60;
    DAT_004d8b6c = -1;
    DAT_004d8b4c = 0;
    DAT_004d8b50 = 0;
    DAT_004d8b60 = 0;
    DAT_004d8b64 = 0;
    DAT_004d8b68 = 0;
}
} // namespace fn_00362ce0


// 0x00362d30 FUN_00362d30 (65 B): equivalent/0x00362d30.cpp [wrapped: conflict: DAT_004d8b18; DAT_004d8b1c; DAT_004d8b20; DAT_004d8b24 (+4)]
// sym: ?FUN_00362d30@fn_00362d30@@YAXXZ
namespace fn_00362d30 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362d30 @ 0x00362d30
void FUN_00333800();
extern void (*DAT_004d8b18)();
extern int DAT_004d8b1c;
extern int DAT_004d8b20;
extern int DAT_004d8b24;
extern int DAT_004d8b30;
extern int DAT_004d8b34;
extern int DAT_004d8b38;
extern int DAT_004d8b3c;
void FUN_00362d30() {
    DAT_004d8b24 = 0;
    DAT_004d8b18 = FUN_00333800;
    DAT_004d8b3c = -1;
    DAT_004d8b1c = 0;
    DAT_004d8b20 = 0;
    DAT_004d8b30 = 0;
    DAT_004d8b34 = 0;
    DAT_004d8b38 = 0;
}
} // namespace fn_00362d30

namespace fn_f1ddef39 {

// 0x00362d80 FUN_00362d80 (317 B): equivalent/0x00362d80.cpp
// sym: ?FUN_00362d80@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362d80 @ 0x00362d80
void FUN_00362d80() {
    ((Entry_362d80*)&DAT_004d8b78)[0].fn = FUN_003333c0;
    ((Entry_362d80*)&DAT_004d8b78)[0].a = 0;
    ((Entry_362d80*)&DAT_004d8b78)[0].b = 0;
    ((Entry_362d80*)&DAT_004d8b78)[0].c = 0;
    ((Entry_362d80*)&DAT_004d8b78)[1].fn = FUN_003333e0;
    ((Entry_362d80*)&DAT_004d8b78)[1].a = 0;
    ((Entry_362d80*)&DAT_004d8b78)[1].b = 0;
    ((Entry_362d80*)&DAT_004d8b78)[1].c = 0;
    ((Entry_362d80*)&DAT_004d8b78)[2].fn = FUN_003333f0;
    ((Entry_362d80*)&DAT_004d8b78)[2].a = 0;
    ((Entry_362d80*)&DAT_004d8b78)[2].b = 0;
    ((Entry_362d80*)&DAT_004d8b78)[2].c = 0;
    ((Entry_362d80*)&DAT_004d8b78)[3].fn = FUN_003337d0;
    ((Entry_362d80*)&DAT_004d8b78)[3].a = 0;
    ((Entry_362d80*)&DAT_004d8b78)[3].b = 0;
    ((Entry_362d80*)&DAT_004d8b78)[3].c = 0;
    ((Entry_362d80*)&DAT_004d8b78)[4].fn = FUN_00333770;
    ((Entry_362d80*)&DAT_004d8b78)[4].a = 0;
    ((Entry_362d80*)&DAT_004d8b78)[4].b = 0;
    ((Entry_362d80*)&DAT_004d8b78)[4].c = 0;
    ((Entry_362d80*)&DAT_004d8b78)[5].fn = FUN_003333a0;
    ((Entry_362d80*)&DAT_004d8b78)[5].a = 0;
    ((Entry_362d80*)&DAT_004d8b78)[5].b = 0;
    ((Entry_362d80*)&DAT_004d8b78)[5].c = 0;
    ((Entry_362d80*)&DAT_004d8b78)[6].fn = FUN_003333b0;
    ((Entry_362d80*)&DAT_004d8b78)[6].a = 0;
    ((Entry_362d80*)&DAT_004d8b78)[6].b = 0;
    ((Entry_362d80*)&DAT_004d8b78)[6].c = 0;
    ((Entry_362d80*)&DAT_004d8b78)[7].fn = FUN_00333400;
    ((Entry_362d80*)&DAT_004d8b78)[7].a = 0;
    ((Entry_362d80*)&DAT_004d8b78)[7].b = 0;
    ((Entry_362d80*)&DAT_004d8b78)[7].c = 0;
    ((Entry_362d80*)&DAT_004d8b78)[8].fn = FUN_0032fd10;
    ((Entry_362d80*)&DAT_004d8b78)[8].a = 0;
    ((Entry_362d80*)&DAT_004d8b78)[8].b = 0;
    ((Entry_362d80*)&DAT_004d8b78)[8].c = 0;
    ((Entry_362d80*)&DAT_004d8b78)[9].fn = FUN_00330470;
    ((Entry_362d80*)&DAT_004d8b78)[9].a = 0;
    ((Entry_362d80*)&DAT_004d8b78)[9].b = 0;
    ((Entry_362d80*)&DAT_004d8b78)[9].c = 0;
    ((Entry_362d80*)&DAT_004d8b78)[10].fn = 0;
    ((Entry_362d80*)&DAT_004d8b78)[10].a = 0;
    ((Entry_362d80*)&DAT_004d8b78)[10].b = 0;
    ((Entry_362d80*)&DAT_004d8b78)[10].c = -1;
}


// 0x00362ec0 FUN_00362ec0 (149 B): equivalent/0x00362ec0.cpp
// sym: ?FUN_00362ec0@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362ec0 @ 0x00362ec0
// Static initialiser for a global table of 4 handler slots followed by a terminator.
void FUN_00362ec0()
{
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).slot[0].fn = FUN_00333410;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).slot[0].a = 0;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).slot[0].b = 0;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).slot[0].c = 0;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).slot[1].fn = FUN_00333780;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).slot[1].a = 0;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).slot[1].b = 0;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).slot[1].c = 0;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).slot[2].fn = FUN_00333830;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).slot[2].a = 0;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).slot[2].b = 0;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).slot[2].c = 0;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).slot[3].fn = FUN_003304b0;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).slot[3].a = 0;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).slot[3].b = 0;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).slot[3].c = 0;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).end.a = 0;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).end.b = 0;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).end.c = 0;
    (*(HandlerTable_362ec0*)&DAT_004d8aa0).end.last = -1;
}


// 0x00362f60 FUN_00362f60 (373 B): equivalent/0x00362f60.cpp
// sym: ?FUN_00362f60@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362f60 @ 0x00362f60
void FUN_00362f60()
{
    (*(Entry_362f60*)&DAT_004d8d70).fn = FUN_003333c0;
    (*(Entry_362f60*)&DAT_004d8d88).fn = FUN_003333e0;
    (*(Entry_362f60*)&DAT_004d8da0).fn = FUN_003333f0;
    (*(Entry_362f60*)&DAT_004d8db8).fn = FUN_003337d0;
    (*(Entry_362f60*)&DAT_004d8dd0).fn = FUN_00333770;
    (*(Entry_362f60*)&DAT_004d8de8).fn = FUN_003333a0;
    (*(Entry_362f60*)&DAT_004d8e00).fn = FUN_003333b0;
    (*(Entry_362f60*)&DAT_004d8e18).fn = FUN_00333400;
    (*(Entry_362f60*)&DAT_004d8e30).fn = FUN_003333a0;
    (*(Entry_362f60*)&DAT_004d8e48).fn = FUN_003333b0;
    (*(Entry_362f60*)&DAT_004d8e60).fn = FUN_00330ca0;
    (*(Entry_362f60*)&DAT_004d8e78).fn = FUN_00330cc0;
    (*(Entry_362f60*)&DAT_004d8d70).a = 0;
    (*(Entry_362f60*)&DAT_004d8d70).b = 0;
    (*(Entry_362f60*)&DAT_004d8d70).c = 0;
    (*(Entry_362f60*)&DAT_004d8d88).a = 0;
    (*(Entry_362f60*)&DAT_004d8d88).b = 0;
    (*(Entry_362f60*)&DAT_004d8d88).c = 0;
    (*(Entry_362f60*)&DAT_004d8da0).a = 0;
    (*(Entry_362f60*)&DAT_004d8da0).b = 0;
    (*(Entry_362f60*)&DAT_004d8da0).c = 0;
    (*(Entry_362f60*)&DAT_004d8db8).a = 0;
    (*(Entry_362f60*)&DAT_004d8db8).b = 0;
    (*(Entry_362f60*)&DAT_004d8db8).c = 0;
    (*(Entry_362f60*)&DAT_004d8dd0).a = 0;
    (*(Entry_362f60*)&DAT_004d8dd0).b = 0;
    (*(Entry_362f60*)&DAT_004d8dd0).c = 0;
    (*(Entry_362f60*)&DAT_004d8de8).a = 0;
    (*(Entry_362f60*)&DAT_004d8de8).b = 0;
    (*(Entry_362f60*)&DAT_004d8de8).c = 0;
    (*(Entry_362f60*)&DAT_004d8e00).a = 0;
    (*(Entry_362f60*)&DAT_004d8e00).b = 0;
    (*(Entry_362f60*)&DAT_004d8e00).c = 0;
    (*(Entry_362f60*)&DAT_004d8e18).a = 0;
    (*(Entry_362f60*)&DAT_004d8e18).b = 0;
    (*(Entry_362f60*)&DAT_004d8e18).c = 0;
    (*(Entry_362f60*)&DAT_004d8e30).a = 0;
    (*(Entry_362f60*)&DAT_004d8e30).b = 0;
    (*(Entry_362f60*)&DAT_004d8e30).c = 0;
    (*(Entry_362f60*)&DAT_004d8e48).a = 0;
    (*(Entry_362f60*)&DAT_004d8e48).b = 0;
    (*(Entry_362f60*)&DAT_004d8e48).c = 0;
    (*(Entry_362f60*)&DAT_004d8e60).a = 0;
    (*(Entry_362f60*)&DAT_004d8e60).b = 0;
    (*(Entry_362f60*)&DAT_004d8e60).c = 0;
    (*(Entry_362f60*)&DAT_004d8e78).a = 0;
    (*(Entry_362f60*)&DAT_004d8e78).b = 0;
    (*(Entry_362f60*)&DAT_004d8e78).c = 0;
    (*(LastEntry*)&DAT_004d8e90).a = 0;
    (*(LastEntry*)&DAT_004d8e90).b = 0;
    (*(LastEntry*)&DAT_004d8e90).c = 0;
    (*(LastEntry*)&DAT_004d8e90).d = -1;
}

} // namespace fn_f1ddef39

// 0x003630e0 FUN_003630e0 (65 B): equivalent/0x003630e0.cpp [wrapped: conflict: DAT_004d8d40; DAT_004d8d44; DAT_004d8d48; DAT_004d8d4c (+4)]
// sym: ?FUN_003630e0@fn_003630e0@@YAXXZ
namespace fn_003630e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003630e0 @ 0x003630e0
extern "C" void FUN_00330d00();
extern "C++" { extern void (*DAT_004d8d40)(); }
extern "C" int DAT_004d8d44;
extern "C" int DAT_004d8d48;
extern "C" int DAT_004d8d4c;
extern "C" int DAT_004d8d58;
extern "C" int DAT_004d8d5c;
extern "C" int DAT_004d8d60;
extern "C" int DAT_004d8d64;

void FUN_003630e0()
{
    DAT_004d8d4c = 0;
    DAT_004d8d40 = &FUN_00330d00;
    DAT_004d8d64 = -1;
    DAT_004d8d44 = 0;
    DAT_004d8d48 = 0;
    DAT_004d8d58 = 0;
    DAT_004d8d5c = 0;
    DAT_004d8d60 = 0;
}
} // namespace fn_003630e0


// 0x00363130 FUN_00363130 (93 B): equivalent/0x00363130.cpp [wrapped: conflict: DAT_004d8ea8; DAT_004d8eac; DAT_004d8eb0; DAT_004d8eb4 (+8)]
// sym: ?FUN_00363130@fn_00363130@@YAXXZ
namespace fn_00363130 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00363130 @ 0x00363130
void FUN_00333800();
void FUN_00330cb0();
extern void (*DAT_004d8ea8)();
extern int DAT_004d8eac;
extern int DAT_004d8eb0;
extern int DAT_004d8eb4;
extern void (*DAT_004d8ec0)();
extern int DAT_004d8ec4;
extern int DAT_004d8ec8;
extern int DAT_004d8ecc;
extern int DAT_004d8ed8;
extern int DAT_004d8edc;
extern int DAT_004d8ee0;
extern int DAT_004d8ee4;
void FUN_00363130() {
 DAT_004d8ea8 = FUN_00333800;
 DAT_004d8eb4 = 0;
 DAT_004d8ecc = 0;
 DAT_004d8ec0 = FUN_00330cb0;
 DAT_004d8ee4 = -1;
 DAT_004d8eac = 0;
 DAT_004d8eb0 = 0;
 DAT_004d8ec4 = 0;
 DAT_004d8ec8 = 0;
 DAT_004d8ed8 = 0;
 DAT_004d8edc = 0;
 DAT_004d8ee0 = 0;
}
} // namespace fn_00363130

namespace fn_f1ddef39 {

// 0x00363190 FUN_00363190 (149 B): equivalent/0x00363190.cpp
// sym: ?FUN_00363190@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00363190 @ 0x00363190
void FUN_00363190()
{
    ((Entry_363190*)&DAT_004d8cc8)[0].fn = FUN_00333410;
    ((Entry_363190*)&DAT_004d8cc8)[0].a = 0;
    ((Entry_363190*)&DAT_004d8cc8)[0].b = 0;
    ((Entry_363190*)&DAT_004d8cc8)[0].c = 0;
    ((Entry_363190*)&DAT_004d8cc8)[1].fn = FUN_00333780;
    ((Entry_363190*)&DAT_004d8cc8)[1].a = 0;
    ((Entry_363190*)&DAT_004d8cc8)[1].b = 0;
    ((Entry_363190*)&DAT_004d8cc8)[1].c = 0;
    ((Entry_363190*)&DAT_004d8cc8)[2].fn = FUN_00333830;
    ((Entry_363190*)&DAT_004d8cc8)[2].a = 0;
    ((Entry_363190*)&DAT_004d8cc8)[2].b = 0;
    ((Entry_363190*)&DAT_004d8cc8)[2].c = 0;
    ((Entry_363190*)&DAT_004d8cc8)[3].fn = FUN_00330d30;
    ((Entry_363190*)&DAT_004d8cc8)[3].a = 0;
    ((Entry_363190*)&DAT_004d8cc8)[3].b = 0;
    ((Entry_363190*)&DAT_004d8cc8)[3].c = 0;
    ((Entry_363190*)&DAT_004d8cc8)[4].fn = 0;
    ((Entry_363190*)&DAT_004d8cc8)[4].a = 0;
    ((Entry_363190*)&DAT_004d8cc8)[4].b = 0;
    ((Entry_363190*)&DAT_004d8cc8)[4].c = -1;
}


// 0x00363230 FUN_00363230 (93 B): equivalent/0x00363230.cpp
// sym: ?FUN_00363230@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00363230 @ 0x00363230
void FUN_00363230() {
    (*(StateBlock*)&DAT_004d9060).entries[0].callback = FUN_00331b90;
    (*(StateBlock*)&DAT_004d9060).entries[0].a = 0;
    (*(StateBlock*)&DAT_004d9060).entries[0].b = 0;
    (*(StateBlock*)&DAT_004d9060).entries[0].c = 0;
    (*(StateBlock*)&DAT_004d9060).entries[1].callback = FUN_00331bc0;
    (*(StateBlock*)&DAT_004d9060).entries[1].a = 0;
    (*(StateBlock*)&DAT_004d9060).entries[1].b = 0;
    (*(StateBlock*)&DAT_004d9060).entries[1].c = 0;
    (*(StateBlock*)&DAT_004d9060).entries[2].callback = 0;
    (*(StateBlock*)&DAT_004d9060).entries[2].a = 0;
    (*(StateBlock*)&DAT_004d9060).entries[2].b = 0;
    (*(StateBlock*)&DAT_004d9060).entries[2].c = -1;
}


// 0x00363290 FUN_00363290 (177 B): equivalent/0x00363290.cpp
// sym: ?FUN_00363290@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00363290 @ 0x00363290
// Static init of a six-entry handler table (shared callbacks; entry 4 gets its own).
void FUN_00363290() {
    Slot_363290 *t = ((Slot_363290*)&DAT_004d8fd0);
    t[0].handler = FUN_003337f0;
    t[1].handler = FUN_00333800;
    t[2].handler = FUN_00333820;
    t[3].handler = FUN_00333810;
    t[4].handler = FUN_00331bf0;
    for (int i = 0; i < 5; i++) {
        t[i].a = 0;
        t[i].b = 0;
        t[i].c = 0;
    }
    t[5].handler = 0;
    t[5].a = 0;
    t[5].b = 0;
    t[5].c = -1;
}


// 0x00363350 FUN_00363350 (261 B): equivalent/0x00363350.cpp
// sym: ?FUN_00363350@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00363350 @ 0x00363350
// Static initialiser for a global table of 8 handler slots followed by a terminator.
void FUN_00363350()
{
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[0].fn = FUN_003333c0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[0].a = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[0].b = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[0].c = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[1].fn = FUN_003333e0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[1].a = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[1].b = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[1].c = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[2].fn = FUN_003333f0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[2].a = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[2].b = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[2].c = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[3].fn = FUN_003337d0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[3].a = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[3].b = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[3].c = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[4].fn = FUN_00333770;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[4].a = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[4].b = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[4].c = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[5].fn = FUN_003333a0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[5].a = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[5].b = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[5].c = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[6].fn = FUN_003333b0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[6].a = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[6].b = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[6].c = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[7].fn = FUN_00333400;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[7].a = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[7].b = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).slot[7].c = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).end.a = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).end.b = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).end.c = 0;
    (*(HandlerTable_363350*)&DAT_004d90a8).end.last = -1;
}


// 0x00363460 FUN_00363460 (121 B): equivalent/0x00363460.cpp
// sym: ?FUN_00363460@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00363460 @ 0x00363460
// Static initialiser for a global table of 3 handler slots followed by a terminator.
void FUN_00363460()
{
    (*(HandlerTable_363460*)&DAT_004d8f70).slot[0].fn = FUN_00333410;
    (*(HandlerTable_363460*)&DAT_004d8f70).slot[0].a = 0;
    (*(HandlerTable_363460*)&DAT_004d8f70).slot[0].b = 0;
    (*(HandlerTable_363460*)&DAT_004d8f70).slot[0].c = 0;
    (*(HandlerTable_363460*)&DAT_004d8f70).slot[1].fn = FUN_00333780;
    (*(HandlerTable_363460*)&DAT_004d8f70).slot[1].a = 0;
    (*(HandlerTable_363460*)&DAT_004d8f70).slot[1].b = 0;
    (*(HandlerTable_363460*)&DAT_004d8f70).slot[1].c = 0;
    (*(HandlerTable_363460*)&DAT_004d8f70).slot[2].fn = FUN_00333830;
    (*(HandlerTable_363460*)&DAT_004d8f70).slot[2].a = 0;
    (*(HandlerTable_363460*)&DAT_004d8f70).slot[2].b = 0;
    (*(HandlerTable_363460*)&DAT_004d8f70).slot[2].c = 0;
    (*(HandlerTable_363460*)&DAT_004d8f70).end.a = 0;
    (*(HandlerTable_363460*)&DAT_004d8f70).end.b = 0;
    (*(HandlerTable_363460*)&DAT_004d8f70).end.c = 0;
    (*(HandlerTable_363460*)&DAT_004d8f70).end.last = -1;
}

} // namespace fn_f1ddef39

// 0x003634e0 FUN_003634e0 (65 B): equivalent/0x003634e0.cpp [wrapped: conflict: DAT_004d8f40; DAT_004d8f44; DAT_004d8f48; DAT_004d8f4c (+4)]
// sym: ?FUN_003634e0@fn_003634e0@@YAXXZ
namespace fn_003634e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003634e0 @ 0x003634e0
void FUN_00331c00();
extern void (*DAT_004d8f40)();
extern int DAT_004d8f44;
extern int DAT_004d8f48;
extern int DAT_004d8f4c;
extern int DAT_004d8f58;
extern int DAT_004d8f5c;
extern int DAT_004d8f60;
extern int DAT_004d8f64;

void FUN_003634e0() {
    DAT_004d8f4c = 0;
    DAT_004d8f40 = &FUN_00331c00;
    DAT_004d8f64 = -1;
    DAT_004d8f44 = 0;
    DAT_004d8f48 = 0;
    DAT_004d8f58 = 0;
    DAT_004d8f5c = 0;
    DAT_004d8f60 = 0;
}
} // namespace fn_003634e0

namespace fn_f1ddef39 {

// 0x00363530 FUN_00363530 (121 B): equivalent/0x00363530.cpp
// sym: ?FUN_00363530@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00363530 @ 0x00363530
void FUN_00363530()
{
    ((Entry_363530*)&DAT_004d9330)[0].fn = FUN_00332750;
    ((Entry_363530*)&DAT_004d9330)[0].a = 0;
    ((Entry_363530*)&DAT_004d9330)[0].b = 0;
    ((Entry_363530*)&DAT_004d9330)[0].c = 0;
    ((Entry_363530*)&DAT_004d9330)[1].fn = FUN_003327b0;
    ((Entry_363530*)&DAT_004d9330)[1].a = 0;
    ((Entry_363530*)&DAT_004d9330)[1].b = 0;
    ((Entry_363530*)&DAT_004d9330)[1].c = 0;
    ((Entry_363530*)&DAT_004d9330)[2].fn = FUN_00332780;
    ((Entry_363530*)&DAT_004d9330)[2].a = 0;
    ((Entry_363530*)&DAT_004d9330)[2].b = 0;
    ((Entry_363530*)&DAT_004d9330)[2].c = 0;
    ((Entry_363530*)&DAT_004d9330)[3].fn = 0;
    ((Entry_363530*)&DAT_004d9330)[3].a = 0;
    ((Entry_363530*)&DAT_004d9330)[3].b = 0;
    ((Entry_363530*)&DAT_004d9330)[3].c = -1;
}


// 0x003635b0 FUN_003635b0 (289 B): equivalent/0x003635b0.cpp
// sym: ?FUN_003635b0@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003635b0 @ 0x003635b0
// Static initialiser for a global table of 9 handler slots followed by a terminator.
void FUN_003635b0()
{
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[0].fn = FUN_003333c0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[0].a = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[0].b = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[0].c = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[1].fn = FUN_003333e0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[1].a = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[1].b = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[1].c = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[2].fn = FUN_003333f0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[2].a = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[2].b = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[2].c = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[3].fn = FUN_003337d0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[3].a = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[3].b = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[3].c = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[4].fn = FUN_00333770;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[4].a = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[4].b = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[4].c = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[5].fn = FUN_003333a0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[5].a = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[5].b = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[5].c = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[6].fn = FUN_003333b0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[6].a = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[6].b = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[6].c = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[7].fn = FUN_00333400;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[7].a = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[7].b = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[7].c = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[8].fn = FUN_003327e0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[8].a = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[8].b = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).slot[8].c = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).end.a = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).end.b = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).end.c = 0;
    (*(HandlerTable_3635b0*)&DAT_004d9240).end.last = -1;
}


// 0x003636e0 FUN_003636e0 (121 B): equivalent/0x003636e0.cpp
// sym: ?FUN_003636e0@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003636e0 @ 0x003636e0
// Static initialiser for a global table of 3 handler slots followed by a terminator.
void FUN_003636e0()
{
    (*(HandlerTable_3636e0*)&DAT_004d9390).slot[0].fn = FUN_00333410;
    (*(HandlerTable_3636e0*)&DAT_004d9390).slot[0].a = 0;
    (*(HandlerTable_3636e0*)&DAT_004d9390).slot[0].b = 0;
    (*(HandlerTable_3636e0*)&DAT_004d9390).slot[0].c = 0;
    (*(HandlerTable_3636e0*)&DAT_004d9390).slot[1].fn = FUN_00333780;
    (*(HandlerTable_3636e0*)&DAT_004d9390).slot[1].a = 0;
    (*(HandlerTable_3636e0*)&DAT_004d9390).slot[1].b = 0;
    (*(HandlerTable_3636e0*)&DAT_004d9390).slot[1].c = 0;
    (*(HandlerTable_3636e0*)&DAT_004d9390).slot[2].fn = FUN_00333830;
    (*(HandlerTable_3636e0*)&DAT_004d9390).slot[2].a = 0;
    (*(HandlerTable_3636e0*)&DAT_004d9390).slot[2].b = 0;
    (*(HandlerTable_3636e0*)&DAT_004d9390).slot[2].c = 0;
    (*(HandlerTable_3636e0*)&DAT_004d9390).end.a = 0;
    (*(HandlerTable_3636e0*)&DAT_004d9390).end.b = 0;
    (*(HandlerTable_3636e0*)&DAT_004d9390).end.c = 0;
    (*(HandlerTable_3636e0*)&DAT_004d9390).end.last = -1;
}


// 0x00363760 FUN_00363760 (149 B): equivalent/0x00363760.cpp
// sym: ?FUN_00363760@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00363760 @ 0x00363760
// Static initialiser for a global table of 4 handler slots followed by a terminator.
void FUN_00363760()
{
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[0].fn = FUN_003337f0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[0].a = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[0].b = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[0].c = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[1].fn = FUN_00333800;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[1].a = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[1].b = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[1].c = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[2].fn = FUN_00333820;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[2].a = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[2].b = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[2].c = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[3].fn = FUN_00333810;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[3].a = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[3].b = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[3].c = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).end.a = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).end.b = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).end.c = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).end.last = -1;
}


// 0x00363800 FUN_00363800 (93 B): equivalent/0x00363800.cpp
// sym: ?FUN_00363800@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00363800 @ 0x00363800
void FUN_00363800()
{
    (*(Entry*)&DAT_004d9660).callback = FUN_00332e60;
    (*(Entry*)&DAT_004d9660).a = 0;
    (*(Entry*)&DAT_004d9660).b = 0;
    (*(Entry*)&DAT_004d9660).c = 0;
    (*(Entry*)&DAT_004d9678).callback = FUN_00332e90;
    (*(Entry*)&DAT_004d9678).a = 0;
    (*(Entry*)&DAT_004d9678).b = 0;
    (*(Entry*)&DAT_004d9678).c = 0;
    (*(Entry*)&DAT_004d9690).callback = 0;
    (*(Entry*)&DAT_004d9690).a = 0;
    (*(Entry*)&DAT_004d9690).b = 0;
    (*(Entry*)&DAT_004d9690).c = -1;
}


// 0x00363860 FUN_00363860 (289 B): equivalent/0x00363860.cpp
// sym: ?FUN_00363860@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00363860 @ 0x00363860
// Static initialiser for a global table of 9 handler slots followed by a terminator.
void FUN_00363860()
{
    (*(HandlerTable_363860*)&DAT_004d9570).slot[0].fn = FUN_003333c0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[0].a = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[0].b = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[0].c = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[1].fn = FUN_003333e0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[1].a = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[1].b = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[1].c = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[2].fn = FUN_003333f0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[2].a = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[2].b = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[2].c = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[3].fn = FUN_003337d0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[3].a = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[3].b = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[3].c = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[4].fn = FUN_00333770;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[4].a = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[4].b = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[4].c = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[5].fn = FUN_003333a0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[5].a = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[5].b = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[5].c = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[6].fn = FUN_003333b0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[6].a = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[6].b = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[6].c = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[7].fn = FUN_00333400;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[7].a = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[7].b = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[7].c = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[8].fn = FUN_00332ba0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[8].a = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[8].b = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).slot[8].c = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).end.a = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).end.b = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).end.c = 0;
    (*(HandlerTable_363860*)&DAT_004d9570).end.last = -1;
}


// 0x00363990 FUN_00363990 (121 B): equivalent/0x00363990.cpp
// sym: ?FUN_00363990@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00363990 @ 0x00363990
void FUN_00363990()
{
    ((Entry_363990*)&DAT_004d96a8)[0].fn = FUN_00333410;
    ((Entry_363990*)&DAT_004d96a8)[0].a = 0;
    ((Entry_363990*)&DAT_004d96a8)[0].b = 0;
    ((Entry_363990*)&DAT_004d96a8)[0].c = 0;
    ((Entry_363990*)&DAT_004d96a8)[1].fn = FUN_00333780;
    ((Entry_363990*)&DAT_004d96a8)[1].a = 0;
    ((Entry_363990*)&DAT_004d96a8)[1].b = 0;
    ((Entry_363990*)&DAT_004d96a8)[1].c = 0;
    ((Entry_363990*)&DAT_004d96a8)[2].fn = FUN_00333830;
    ((Entry_363990*)&DAT_004d96a8)[2].a = 0;
    ((Entry_363990*)&DAT_004d96a8)[2].b = 0;
    ((Entry_363990*)&DAT_004d96a8)[2].c = 0;
    ((Entry_363990*)&DAT_004d96a8)[3].fn = 0;
    ((Entry_363990*)&DAT_004d96a8)[3].a = 0;
    ((Entry_363990*)&DAT_004d96a8)[3].b = 0;
    ((Entry_363990*)&DAT_004d96a8)[3].c = -1;
}


// 0x00363a10 FUN_00363a10 (149 B): equivalent/0x00363a10.cpp
// sym: ?FUN_00363a10@fn_f1ddef39@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00363a10 @ 0x00363a10
void FUN_00363a10()
{
    ((Entry_363a10*)&DAT_004d94f8)[0].fn = FUN_003337f0;
    ((Entry_363a10*)&DAT_004d94f8)[0].a = 0;
    ((Entry_363a10*)&DAT_004d94f8)[0].b = 0;
    ((Entry_363a10*)&DAT_004d94f8)[0].c = 0;
    ((Entry_363a10*)&DAT_004d94f8)[1].fn = FUN_00333800;
    ((Entry_363a10*)&DAT_004d94f8)[1].a = 0;
    ((Entry_363a10*)&DAT_004d94f8)[1].b = 0;
    ((Entry_363a10*)&DAT_004d94f8)[1].c = 0;
    ((Entry_363a10*)&DAT_004d94f8)[2].fn = FUN_00333820;
    ((Entry_363a10*)&DAT_004d94f8)[2].a = 0;
    ((Entry_363a10*)&DAT_004d94f8)[2].b = 0;
    ((Entry_363a10*)&DAT_004d94f8)[2].c = 0;
    ((Entry_363a10*)&DAT_004d94f8)[3].fn = FUN_00333810;
    ((Entry_363a10*)&DAT_004d94f8)[3].a = 0;
    ((Entry_363a10*)&DAT_004d94f8)[3].b = 0;
    ((Entry_363a10*)&DAT_004d94f8)[3].c = 0;
    ((Entry_363a10*)&DAT_004d94f8)[4].fn = 0;
    ((Entry_363a10*)&DAT_004d94f8)[4].a = 0;
    ((Entry_363a10*)&DAT_004d94f8)[4].b = 0;
    ((Entry_363a10*)&DAT_004d94f8)[4].c = -1;
}

} // namespace fn_f1ddef39

// 0x00363ab0 FUN_00363ab0 (32 B): matches/0x00363ab0.cpp [wrapped: same definition as 0x0035dc90 in this TU]
// sym: ?target@fn_00363ab0@@YAXXZ
namespace fn_00363ab0 {

/* size_t: tree_prelude.h */
class Obj {
  public:
    void FUN_00337d20(void*, int);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void(__cdecl*)());
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_00364810();
void __cdecl target() {
    (*(Obj*)&DAT_0055dbb0).FUN_00337d20(((char*)&DAT_00555bb0), 0x8000);
    atexit(FUN_00364810);
}
} // namespace fn_00363ab0


// 0x00363ad0 FUN_00363ad0 (32 B): matches/0x00363ad0.cpp [wrapped: conflict: _atexit]
// sym: ?FUN_00363ad0@fn_00363ad0@@YAXXZ
namespace fn_00363ad0 {
// data: hulk_at_0055dfc0 = DAT_0055dfc0

class Obj {
  public:
    void FUN_00337d20(void* a, int b);
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern void __cdecl _atexit(void (*f)());
#endif

extern "C++" __declspec(nothrow) void FUN_00364820();

void FUN_00363ad0() {
    (*(Obj*)&DAT_00565fc0).FUN_00337d20((void*)((hulk_intptr)((char*)&DAT_0055dfc0)), 0x8000);
    _atexit(FUN_00364820);
}
} // namespace fn_00363ad0

namespace fn_f1ddef39 {

// 0x00363af0 FUN_00363af0 (10 B): matches/0x00363af0.cpp
// sym: _FUN_00363af0
extern "C" void FUN_00363af0() {
    ((owners::Str_240060 *)&((*(Obj_363af0*)&DAT_004dc020)))->FUN_00240060();
}


// 0x00363b00 FUN_00363b00 (10 B): matches/0x00363b00.cpp
// sym: _FUN_00363b00
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363b00() {
    (*(Obj_363b00*)&DAT_004dc0e8).Fnf_0027af50();
}


// 0x00363b10 FUN_00363b10 (10 B): matches/0x00363b10.cpp
// sym: _FUN_00363b10
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363b10() {
    (*(Obj_363b10*)&DAT_004dc0f8).Fnf_0027af50();
}


// 0x00363b20 FUN_00363b20 (10 B): matches/0x00363b20.cpp
// sym: _FUN_00363b20
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363b20() {
    (*(Obj_363b20*)&DAT_004dc108).Fnf_0027af50();
}


// 0x00363b30 FUN_00363b30 (10 B): matches/0x00363b30.cpp
// sym: _FUN_00363b30
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363b30() {
    (*(Obj_363b30*)&DAT_004dc118).Fnf_0027af50();
}


// 0x00363b40 FUN_00363b40 (10 B): matches/0x00363b40.cpp
// sym: _FUN_00363b40
extern "C" void FUN_00363b40() {
    (*(A_363b40*)&DAT_004dc128).Fn_0027af50();
}


// 0x00363b50 FUN_00363b50 (10 B): matches/0x00363b50.cpp
// sym: _FUN_00363b50
extern "C" void __cdecl FUN_00363b50() {
    FUN_0027af50(((char*)&DAT_004dc138));
}


// 0x00363b60 FUN_00363b60 (10 B): matches/0x00363b60.cpp
// sym: _FUN_00363b60
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363b60() {
    (*(Obj_363b60*)&DAT_004dc148).Fnf_0027af50();
}


// 0x00363b70 FUN_00363b70 (10 B): matches/0x00363b70.cpp
// sym: _FUN_00363b70
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363b70() {
    (*(Obj_363b70*)&DAT_004dc158).Fnf_0027af50();
}


// 0x00363b80 FUN_00363b80 (10 B): matches/0x00363b80.cpp
// sym: _FUN_00363b80
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363b80() {
    ((owners::Str_240060 *)&((*(Obj_363b80*)&DAT_004dc294)))->FUN_00240060();
}


// 0x00363b90 FUN_00363b90 (10 B): matches/0x00363b90.cpp
// sym: _FUN_00363b90
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363b90() {
    (*(Obj_363b90*)&DAT_004dc310).Fnf_0027af50();
}


// 0x00363ba0 FUN_00363ba0 (10 B): matches/0x00363ba0.cpp
// sym: _FUN_00363ba0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363ba0() {
    (*(Obj_363ba0*)&DAT_004dc2c8).Fnf_0027af50();
}


// 0x00363bb0 FUN_00363bb0 (10 B): matches/0x00363bb0.cpp
// sym: _FUN_00363bb0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363bb0() {
    (*(Obj_363bb0*)&DAT_004dc2d8).Fnf_0027af50();
}


// 0x00363bc0 FUN_00363bc0 (10 B): matches/0x00363bc0.cpp
// sym: _FUN_00363bc0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363bc0() {
    (*(Obj_363bc0*)&DAT_004dc350).Fnf_0027af50();
}


// 0x00363bd0 FUN_00363bd0 (10 B): matches/0x00363bd0.cpp
// sym: _FUN_00363bd0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363bd0() {
    (*(Obj_363bd0*)&DAT_004dc330).Fnf_0027af50();
}


// 0x00363be0 FUN_00363be0 (10 B): matches/0x00363be0.cpp
// sym: _FUN_00363be0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363be0() {
    (*(Obj_363be0*)&DAT_004dc340).Fnf_0027af50();
}


// 0x00363bf0 FUN_00363bf0 (61 B): matches/0x00363bf0.cpp
// sym: _FUN_00363bf0
extern "C" void __cdecl FUN_00363bf0(void) {
    ((C_363bf0*)((hulk_intptr)DAT_004dc988))->init_00230f50((void*)((hulk_intptr)(void (__cdecl*)())&FUN_00066930), (void*)((hulk_intptr)DAT_004dc988));
    ((C_363bf0*)((hulk_intptr)DAT_004dc96c))->init_00230f50((void*)((hulk_intptr)(void (__cdecl*)())&FUN_00066a00), (void*)((hulk_intptr)DAT_004dc96c));
    ((C_363bf0*)((hulk_intptr)DAT_004dc950))->init_00230f50((void*)((hulk_intptr)(void (__cdecl*)())&FUN_00066930), (void*)((hulk_intptr)DAT_004dc950));
}


// 0x00363c30 FUN_00363c30 (10 B): matches/0x00363c30.cpp
// sym: ?wrapper@fn_f1ddef39@@YAXXZ
// Same code shape as 0x00363af0 (propagated; names are from that function)
void wrapper() {
    (*(Obj_363c30*)&DAT_004dcf00).Fnf_0027af50();
}


// 0x00363c40 FUN_00363c40 (10 B): matches/0x00363c40.cpp
// sym: _FUN_00363c40
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363c40() {
    (*(Obj_363c40*)&DAT_004dd068).Fnf_0027af50();
}


// 0x00363c50 FUN_00363c50 (10 B): matches/0x00363c50.cpp
// sym: _FUN_00363c50
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363c50() {
    ((owners::Str_240060 *)&((*(Obj_363c50*)&DAT_004dd080)))->FUN_00240060();
}


// 0x00363c60 FUN_00363c60 (10 B): matches/0x00363c60.cpp
// sym: _FUN_00363c60
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363c60() {
    ((owners::Str_240060 *)&((*(Obj_363c60*)&DAT_004dd260)))->FUN_00240060();
}


// 0x00363c70 FUN_00363c70 (10 B): matches/0x00363c70.cpp
// sym: _FUN_00363c70
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363c70() {
    ((owners::Str_240060 *)&((*(Obj_363c70*)&DAT_004dd2d0)))->FUN_00240060();
}


// 0x00363c80 FUN_00363c80 (10 B): matches/0x00363c80.cpp
// sym: _FUN_00363c80
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363c80() {
    ((owners::Str_240060 *)&((*(Obj_363c80*)&DAT_004dd6f4)))->FUN_00240060();
}

} // namespace fn_f1ddef39

// 0x00363c90 FUN_00363c90 (10 B): matches/0x00363c90.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_00363c90@@YAXXZ
namespace fn_00363c90 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_363c90 {
};
void wrapper() {
    ((owners::Str_240060 *)&((*(Obj_363c90*)&DAT_004dd704)))->FUN_00240060();
}
} // namespace fn_00363c90

namespace fn_f1ddef39 {

// 0x00363ca0 FUN_00363ca0 (10 B): matches/0x00363ca0.cpp
// sym: _FUN_00363ca0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363ca0() {
    ((owners::Str_240060 *)&((*(Obj_363ca0*)&DAT_004dd738)))->FUN_00240060();
}


// 0x00363cb0 FUN_00363cb0 (10 B): matches/0x00363cb0.cpp
// sym: _FUN_00363cb0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363cb0() {
    ((owners::Str_240060 *)&((*(Obj_363cb0*)&DAT_004dd768)))->FUN_00240060();
}


// 0x00363cc0 FUN_00363cc0 (1 B): matches/0x00363cc0.cpp
// sym: _FUN_00363cc0
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_00363cc0() {}


// 0x00363cd0 FUN_00363cd0 (10 B): matches/0x00363cd0.cpp
// sym: _FUN_00363cd0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363cd0() {
    ((owners::Str_240060 *)&((*(Obj_363cd0*)&DAT_004dd818)))->FUN_00240060();
}


// 0x00363ce0 FUN_00363ce0 (15 B): matches/0x00363ce0.cpp
// sym: _FUN_00363ce0
extern "C" void __cdecl FUN_00363ce0() {
    if (FUN_00085cd0())
        FUN_00085d70();
}

} // namespace fn_f1ddef39

// 0x00363cf0 FUN_00363cf0 (10 B): matches/0x00363cf0.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_00363cf0@@YAXXZ
namespace fn_00363cf0 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_363cf0 {
};
void wrapper() {
    ((owners::Str_240060 *)&((*(Obj_363cf0*)&DAT_004dd9d0)))->FUN_00240060();
}
} // namespace fn_00363cf0

namespace fn_f1ddef39 {

// 0x00363d00 FUN_00363d00 (10 B): matches/0x00363d00.cpp
// sym: _FUN_00363d00
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363d00() {
    ((owners::Str_240060 *)&((*(Obj_363d00*)&DAT_004dda08)))->FUN_00240060();
}


// 0x00363d10 FUN_00363d10 (54 B): matches/0x00363d10.cpp
// sym: _FUN_00363d10
extern "C" void FUN_00363d10() {
    Item* it = hulk_at_004ddb10 + 11;
    int n = 11;
    do {
        --it;
        if (it->p) {
            release(it->p);
            it->a = 0;
            it->p = 0;
        }
    } while (--n);
}

} // namespace fn_f1ddef39

// 0x00363d50 FUN_00363d50 (54 B): matches/0x00363d50.cpp [wrapped: conflict: Pair]
// sym: ?FUN_00363d50@fn_00363d50@@YAXXZ
namespace fn_00363d50 {

extern "C++" __declspec(nothrow) void __cdecl freeItem_0008d330(void*);
struct Pair {
    int a, b;
};
void FUN_00363d50() {
    Pair* p = ((Pair*)((char*)&DAT_004ddab0 + 4));
    int n = 13;
    do {
        --p;
        hulk_intptr v = p[0].a;
        if (v) {
            freeItem_0008d330((void*)v);
            p[-1].b = 0;
            p[0].a = 0;
        }
    } while (--n);
}
} // namespace fn_00363d50

namespace fn_f1ddef39 {

// 0x00363d90 FUN_00363d90 (40 B): matches/0x00363d90.cpp
// sym: ?FUN_00363d90@fn_f1ddef39@@YAXXZ
void FUN_00363d90() {
    char* p = (char*)((hulk_intptr)((char*)&DAT_004ddb10));
    int i = 2;
    do {
        p -= 0x30;
        FUN_00013420(p, 8, 6, (void*)((hulk_intptr)(void (__cdecl*)())&FUN_000b0ff0));
        --i;
    } while (i);
}

} // namespace fn_f1ddef39

// 0x00363dc0 FUN_00363dc0 (40 B): matches/0x00363dc0.cpp [wrapped: same definition as 0x0035dc90 in this TU]
// sym: ?target@fn_00363dc0@@YAXXZ
namespace fn_00363dc0 {

extern "C" void __cdecl FUN_000b0ff0();
extern void __stdcall FUN_00013420(void*, int, int, void*);
void target() {
    char* p = (char*)((hulk_intptr)DAT_004ddbc8);
    int i = 2;
    do {
        FUN_00013420(p, ((p -= 0x30), 8), 6, (void*)((hulk_intptr)(void (__cdecl*)())&FUN_000b0ff0));
    } while (--i);
}
} // namespace fn_00363dc0

namespace fn_f1ddef39 {

// 0x00363df0 FUN_00363df0 (10 B): matches/0x00363df0.cpp
// sym: _FUN_00363df0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363df0() {
    ((owners::Str_240060 *)&((*(Obj_363df0*)&DAT_004ddbe4)))->FUN_00240060();
}


// 0x00363e00 FUN_00363e00 (10 B): matches/0x00363e00.cpp
// sym: _FUN_00363e00
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363e00() {
    ((owners::Str_240060 *)&((*(Obj_363e00*)&DAT_004dde38)))->FUN_00240060();
}


// 0x00363e10 FUN_00363e10 (10 B): matches/0x00363e10.cpp
// sym: _FUN_00363e10
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363e10() {
    ((owners::Str_240060 *)&((*(Obj_363e10*)&DAT_004dde6c)))->FUN_00240060();
}


// 0x00363e20 FUN_00363e20 (10 B): matches/0x00363e20.cpp
// sym: _FUN_00363e20
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363e20() {
    ((owners::Str_240060 *)&((*(Obj_363e20*)&DAT_004ddf68)))->FUN_00240060();
}

} // namespace fn_f1ddef39

// 0x00363e30 FUN_00363e30 (10 B): matches/0x00363e30.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_00363e30@@YAXXZ
namespace fn_00363e30 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_363e30 {
};
void wrapper() {
    ((owners::Str_240060 *)&((*(Obj_363e30*)&DAT_004ddf9c)))->FUN_00240060();
}
} // namespace fn_00363e30


// 0x00363e40 FUN_00363e40 (10 B): matches/0x00363e40.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_00363e40@@YAXXZ
namespace fn_00363e40 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_363e40 {
};
void wrapper() {
    ((owners::Str_240060 *)&((*(Obj_363e40*)&DAT_004de608)))->FUN_00240060();
}
} // namespace fn_00363e40


// 0x00363e50 FUN_00363e50 (10 B): matches/0x00363e50.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_00363e50@@YAXXZ
namespace fn_00363e50 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_363e50 {
};
void wrapper() {
    ((owners::Str_240060 *)&((*(Obj_363e50*)&DAT_004de738)))->FUN_00240060();
}
} // namespace fn_00363e50


// 0x00363e60 FUN_00363e60 (10 B): matches/0x00363e60.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_00363e60@@YAXXZ
namespace fn_00363e60 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_363e60 {
};
void wrapper() {
    ((owners::Str_240060 *)&((*(Obj_363e60*)&DAT_004de958)))->FUN_00240060();
}
} // namespace fn_00363e60

namespace fn_f1ddef39 {

// 0x00363e70 FUN_00363e70 (10 B): matches/0x00363e70.cpp
// sym: _FUN_00363e70
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363e70() {
    (*(Obj_363e70*)&DAT_004e0bb0).Fnf_0027af50();
}


// 0x00363e80 FUN_00363e80 (10 B): matches/0x00363e80.cpp
// sym: _FUN_00363e80
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363e80() {
    (*(Obj_363e80*)&DAT_004e0bc0).Fnf_0027af50();
}


// 0x00363e90 FUN_00363e90 (10 B): matches/0x00363e90.cpp
// sym: _FUN_00363e90
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363e90() {
    (*(Obj_363e90*)&DAT_004e0bc8).Fnf_0027af50();
}


// 0x00363ea0 FUN_00363ea0 (10 B): matches/0x00363ea0.cpp
// sym: _FUN_00363ea0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363ea0() {
    (*(Obj_363ea0*)&DAT_004e0bd8).Fnf_0027af50();
}


// 0x00363eb0 FUN_00363eb0 (10 B): matches/0x00363eb0.cpp
// sym: _FUN_00363eb0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363eb0() {
    (*(Obj_363eb0*)&DAT_004e0be0).Fnf_0027af50();
}


// 0x00363ec0 FUN_00363ec0 (10 B): matches/0x00363ec0.cpp
// sym: _FUN_00363ec0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363ec0() {
    (*(Obj_363ec0*)&DAT_004e0bf0).Fnf_0027af50();
}


// 0x00363ed0 FUN_00363ed0 (10 B): matches/0x00363ed0.cpp
// sym: _FUN_00363ed0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363ed0() {
    (*(Obj_363ed0*)&DAT_004e0c00).Fnf_0027af50();
}


// 0x00363ee0 FUN_00363ee0 (10 B): matches/0x00363ee0.cpp
// sym: _FUN_00363ee0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363ee0() {
    (*(Obj_363ee0*)&DAT_004e0c08).Fnf_0027af50();
}


// 0x00363ef0 FUN_00363ef0 (10 B): matches/0x00363ef0.cpp
// sym: _FUN_00363ef0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363ef0() {
    (*(Obj_363ef0*)&DAT_004e0c18).Fnf_0027af50();
}


// 0x00363f00 FUN_00363f00 (10 B): matches/0x00363f00.cpp
// sym: _FUN_00363f00
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363f00() {
    (*(Obj_363f00*)((char*)&DAT_004e0d30 + 8)).Fnf_0027af50();
}


// 0x00363f10 FUN_00363f10 (10 B): matches/0x00363f10.cpp
// sym: _FUN_00363f10
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363f10() {
    (*(Obj_363f10*)&DAT_004e0d48).Fnf_0027af50();
}


// 0x00363f20 FUN_00363f20 (10 B): matches/0x00363f20.cpp
// sym: _FUN_00363f20
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363f20() {
    (*(Obj_363f20*)((char*)&DAT_004e0d50 + 8)).Fnf_0027af50();
}


// 0x00363f30 FUN_00363f30 (10 B): matches/0x00363f30.cpp
// sym: _FUN_00363f30
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363f30() {
    ((owners::Str_240060 *)&((*(Obj_363f30*)&DAT_004e0eb4)))->FUN_00240060();
}


// 0x00363f40 FUN_00363f40 (10 B): matches/0x00363f40.cpp
// sym: _FUN_00363f40
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363f40() {
    ((owners::Str_240060 *)&((*(Obj_363f40*)&DAT_004e0f60)))->FUN_00240060();
}


// 0x00363f50 FUN_00363f50 (10 B): matches/0x00363f50.cpp
// sym: _FUN_00363f50
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363f50() {
    ((owners::Str_240060 *)&((*(Obj_363f50*)&DAT_004e0fb0)))->FUN_00240060();
}


// 0x00363f60 FUN_00363f60 (10 B): matches/0x00363f60.cpp
// sym: _FUN_00363f60
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363f60() {
    (*(Obj_363f60*)&DAT_004e11c8).Fnf_0027af50();
}


// 0x00363f70 FUN_00363f70 (10 B): matches/0x00363f70.cpp
// sym: _FUN_00363f70
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363f70() {
    (*(Obj_363f70*)&DAT_004e12d8).Fnf_0027af50();
}


// 0x00363f80 FUN_00363f80 (10 B): matches/0x00363f80.cpp
// sym: _FUN_00363f80
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363f80() {
    ((owners::Str_240060 *)&((*(Obj_363f80*)&DAT_004e14f8)))->FUN_00240060();
}


// 0x00363f90 FUN_00363f90 (10 B): matches/0x00363f90.cpp
// sym: _FUN_00363f90
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363f90() {
    ((owners::Str_240060 *)&((*(Obj_363f90*)&DAT_004e159c)))->FUN_00240060();
}


// 0x00363fa0 FUN_00363fa0 (10 B): matches/0x00363fa0.cpp
// sym: _FUN_00363fa0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363fa0() {
    (*(Obj_363fa0*)&DAT_004e16d8).Fnf_0027af50();
}

} // namespace fn_f1ddef39

// 0x00363fb0 FUN_00363fb0 (10 B): matches/0x00363fb0.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_00363fb0@@YAXXZ
namespace fn_00363fb0 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_363fb0 {
};
void wrapper() {
    ((owners::Str_240060 *)&((*(Obj_363fb0*)&DAT_004e1768)))->FUN_00240060();
}
} // namespace fn_00363fb0

namespace fn_f1ddef39 {

// 0x00363fc0 FUN_00363fc0 (10 B): matches/0x00363fc0.cpp
// sym: _FUN_00363fc0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363fc0() {
    ((owners::Str_240060 *)&((*(Obj_363fc0*)&DAT_004e1818)))->FUN_00240060();
}


// 0x00363fd0 FUN_00363fd0 (10 B): matches/0x00363fd0.cpp
// sym: _FUN_00363fd0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363fd0() {
    (*(Obj_363fd0*)((char*)&DAT_004e17c0 + 56)).Fnf_0027af50();
}

} // namespace fn_f1ddef39

// 0x00363fe0 FUN_00363fe0 (10 B): matches/0x00363fe0.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_00363fe0@@YAXXZ
namespace fn_00363fe0 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_363fe0 {
};
void wrapper() {
    ((owners::Str_240060 *)&((*(Obj_363fe0*)&DAT_004e2184)))->FUN_00240060();
}
} // namespace fn_00363fe0

namespace fn_f1ddef39 {

// 0x00363ff0 FUN_00363ff0 (10 B): matches/0x00363ff0.cpp
// sym: _FUN_00363ff0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00363ff0() {
    (*(Obj_363ff0*)((char*)&DAT_004e215c + 16)).Fnf_002fa750();
}


// 0x00364000 FUN_00364000 (10 B): matches/0x00364000.cpp
// sym: _FUN_00364000
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364000() {
    ((owners::Str_240060 *)&((*(Obj_364000*)&DAT_004e21f8)))->FUN_00240060();
}


// 0x00364010 FUN_00364010 (10 B): matches/0x00364010.cpp
// sym: _FUN_00364010
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364010() {
    (*(CStaticAllocator_364010*)&DAT_004e2210).Fnf_0008ff50();
}


// 0x00364020 FUN_00364020 (10 B): matches/0x00364020.cpp
// sym: _FUN_00364020
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364020() {
    ((owners::Str_240060 *)&((*(Obj_364020*)((char*)&DAT_004e222d + 3))))->FUN_00240060();
}


// 0x00364030 FUN_00364030 (10 B): matches/0x00364030.cpp
// sym: _FUN_00364030
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364030() {
    ((owners::Str_240060 *)&((*(Obj_364030*)((char*)&DAT_004e226c + 4))))->FUN_00240060();
}


// 0x00364040 FUN_00364040 (10 B): matches/0x00364040.cpp
// sym: _FUN_00364040
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364040() {
    ((owners::Str_240060 *)&((*(Obj_364040*)&DAT_004e22fc)))->FUN_00240060();
}


// 0x00364050 FUN_00364050 (10 B): matches/0x00364050.cpp
// sym: _FUN_00364050
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364050() {
    ((owners::Str_240060 *)&((*(Obj_364050*)&DAT_004e23b8)))->FUN_00240060();
}

} // namespace fn_f1ddef39

// 0x00364060 FUN_00364060 (10 B): matches/0x00364060.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_00364060@@YAXXZ
namespace fn_00364060 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_364060 {
};
void wrapper() {
    ((owners::Str_240060 *)&((*(Obj_364060*)((char*)&DAT_004e2530 + 8))))->FUN_00240060();
}
} // namespace fn_00364060

namespace fn_f1ddef39 {

// 0x00364070 FUN_00364070 (10 B): matches/0x00364070.cpp
// sym: _FUN_00364070
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364070() {
    ((owners::Str_240060 *)&((*(Obj_364070*)((char*)&DAT_004e2644 + 4))))->FUN_00240060();
}

} // namespace fn_f1ddef39

// 0x00364080 FUN_00364080 (10 B): matches/0x00364080.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_00364080@@YAXXZ
namespace fn_00364080 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_364080 {
};
void wrapper() {
    ((owners::Str_240060 *)&((*(Obj_364080*)((char*)&DAT_004e2770 + 8))))->FUN_00240060();
}
} // namespace fn_00364080


// 0x00364090 FUN_00364090 (10 B): matches/0x00364090.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_00364090@@YAXXZ
namespace fn_00364090 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_364090 {
    void Fnf_0027af50();
};
void wrapper() {
    (*(Obj_364090*)((char*)&DAT_004e2730 + 8)).Fnf_0027af50();
}
} // namespace fn_00364090

namespace fn_f1ddef39 {

// 0x003640a0 FUN_003640a0 (10 B): matches/0x003640a0.cpp
// sym: ?FUN_003640a0@fn_f1ddef39@@YAXXZ
// Same code shape as 0x00363af0 (propagated; names are from that function)
void FUN_003640a0() {
    ((owners::Str_240060 *)&((*(Obj_3640a0*)&DAT_004e36bc)))->FUN_00240060();
}


// 0x003640b0 FUN_003640b0 (10 B): matches/0x003640b0.cpp
// sym: _FUN_003640b0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_003640b0() {
    (*(Allocator_3640b0*)&DAT_004e36c8).Fnf_002475e0();
}


// 0x003640c0 FUN_003640c0 (10 B): matches/0x003640c0.cpp
// sym: _FUN_003640c0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_003640c0() {
    ((owners::Str_240060 *)&((*(Obj_3640c0*)&DAT_004e36f0)))->FUN_00240060();
}


// 0x003640d0 FUN_003640d0 (10 B): matches/0x003640d0.cpp
// sym: _FUN_003640d0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_003640d0() {
    ((owners::Str_240060 *)&((*(Obj_3640d0*)((char*)&DAT_004e3748 + 4))))->FUN_00240060();
}

} // namespace fn_f1ddef39

// 0x003640e0 FUN_003640e0 (10 B): matches/0x003640e0.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_003640e0@@YAXXZ
namespace fn_003640e0 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_3640e0 {
};
void wrapper() {
    ((owners::Str_240060 *)&((*(Obj_3640e0*)&DAT_004e58b8)))->FUN_00240060();
}
} // namespace fn_003640e0


// 0x003640f0 FUN_003640f0 (48 B): matches/0x003640f0.cpp [wrapped: conflict: DAT_004e58c0]
// sym: ?FUN_003640f0@fn_003640f0@@YAXXZ
namespace fn_003640f0 {
struct Item {
    char bytes[8];
    void FUN_0027af50();
};
extern Item DAT_004e58c0[];
void FUN_003640f0() {
    Item* p = DAT_004e58c0 + 4;
    for (int i = 0; i < 0x108; ++i) {
        p -= 4;
        (p - 3)->FUN_0027af50();
        (p - 4)->FUN_0027af50();
        (p - 5)->FUN_0027af50();
    }
}
} // namespace fn_003640f0

namespace fn_f1ddef39 {

// 0x00364120 FUN_00364120 (10 B): matches/0x00364120.cpp
// sym: _FUN_00364120
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364120() {
    ((owners::Str_240060 *)&((*(Obj_364120*)((char*)&DAT_004e5a58 + 4))))->FUN_00240060();
}


// 0x00364130 FUN_00364130 (10 B): matches/0x00364130.cpp
// sym: _FUN_00364130
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364130() {
    (*(Obj_364130*)&DAT_004e5bc0).Fnf_0027af50();
}


// 0x00364140 FUN_00364140 (10 B): matches/0x00364140.cpp
// sym: _FUN_00364140
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364140() {
    (*(Obj_364140*)&DAT_004e5bd0).Fnf_0027af50();
}

} // namespace fn_f1ddef39

// 0x00364150 FUN_00364150 (10 B): matches/0x00364150.cpp [wrapped: conflict: FUN_00364150]
// sym: ?FUN_00364150@fn_00364150@@YAHXZ
namespace fn_00364150 {
// data: gGlobal_364150 = DAT_004e5d68

struct G_364150 {
    int FnF_002580e0();
};
int __cdecl FUN_00364150() {
    return (*(G_364150*)((char*)&DAT_004e5d68)).FnF_002580e0();
}
} // namespace fn_00364150

namespace fn_f1ddef39 {

// 0x00364160 FUN_00364160 (10 B): matches/0x00364160.cpp
// sym: _FUN_00364160
extern "C" void FUN_00364160() {
    (*(Obj_364160*)&DAT_004e5db0).Run_002580e0();
}


// 0x00364170 FUN_00364170 (10 B): matches/0x00364170.cpp
// sym: _FUN_00364170
extern "C" void __cdecl FUN_00364170() {
    (*(G_364170*)&DAT_004e5df8).Run_002580e0();
}


// 0x00364180 FUN_00364180 (10 B): matches/0x00364180.cpp
// sym: _FUN_00364180
extern "C" void FUN_00364180() {
    (*(T_364180*)((char*)&DAT_004e5e40)).Fn_002580e0();
}


// 0x00364190 FUN_00364190 (10 B): matches/0x00364190.cpp
// sym: _FUN_00364190
extern "C" void FUN_00364190() {
    (*(A_364190*)&DAT_004e5e88).Fn_002580e0();
}


// 0x003641a0 FUN_003641a0 (10 B): matches/0x003641a0.cpp
// sym: _FUN_003641a0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_003641a0() {
    (*(Obj_3641a0*)&DAT_004e5cf8).Fnf_00243350();
}

} // namespace fn_f1ddef39

// 0x003641b0 FUN_003641b0 (10 B): matches/0x003641b0.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_003641b0@@YAXXZ
namespace fn_003641b0 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_3641b0 {
    void Fnf_00243350();
};
void wrapper() {
    (*(Obj_3641b0*)&DAT_004e5f18).Fnf_00243350();
}
} // namespace fn_003641b0


// 0x003641c0 FUN_003641c0 (11 B): matches/0x003641c0.cpp [wrapped: same definition as 0x0035ed50 in this TU]
// sym: ?Init@fn_003641c0@@YAXXZ
namespace fn_003641c0 {

extern "C" char DAT_00423f20[];
class Stream {
  public:
    virtual void Fn();
};
void Init() {
    (*(Stream**)&DAT_004cc0cc) = (Stream*)((hulk_intptr)DAT_00423f20);
}
} // namespace fn_003641c0

namespace fn_f1ddef39 {

// 0x003641d0 FUN_003641d0 (11 B): matches/0x003641d0.cpp
// sym: ?InitAllocator@fn_f1ddef39@@YAXXZ
void InitAllocator() {
    (*(Allocator**)&DAT_004cc200) = (Allocator*)((hulk_intptr)DAT_00429254);
}


// 0x003641e0 FUN_003641e0 (10 B): matches/0x003641e0.cpp
// sym: _FUN_003641e0
extern "C" void FUN_003641e0() {
    (*(Obj_3641e0*)&DAT_004e5fa8).Fn_002580e0();
}


// 0x003641f0 FUN_003641f0 (10 B): matches/0x003641f0.cpp
// sym: ?FUN_003641f0@fn_f1ddef39@@YAXXZ
void FUN_003641f0() {
    (*(Obj_3641f0*)&DAT_004e5ff0).Fn_002580e0();
}


// 0x00364200 FUN_00364200 (10 B): matches/0x00364200.cpp
// sym: ?FUN_00364200@fn_f1ddef39@@YAXXZ
void FUN_00364200() {
    (*(X_364200*)((char*)&DAT_004e6038)).FnA_002580e0();
}


// 0x00364210 FUN_00364210 (10 B): matches/0x00364210.cpp
// sym: _FUN_00364210
extern "C" void FUN_00364210() {
    (*(Obj_364210*)&DAT_004e6080).Run_002580e0();
}


// 0x00364220 FUN_00364220 (10 B): matches/0x00364220.cpp
// sym: _FUN_00364220
extern "C" void __cdecl FUN_00364220() {
    FUN_002580e0(((void**)&DAT_004e60c8));
}


// 0x00364230 FUN_00364230 (10 B): matches/0x00364230.cpp
// sym: _FUN_00364230
extern "C" void __cdecl FUN_00364230() {
    (*(Obj_364230*)&DAT_004e6110).Run_002580e0();
}


// 0x00364240 FUN_00364240 (10 B): matches/0x00364240.cpp
// sym: _FUN_00364240
// data: g_obj_364240 = DAT_004e6158
extern "C" void __cdecl FUN_00364240() {
    (*(Obj_364240*)((char*)&DAT_004e6158)).Run_002580e0();
}


// 0x00364250 FUN_00364250 (10 B): matches/0x00364250.cpp
// sym: ?FUN_00364250@fn_f1ddef39@@YIXXZ
// data: gTargetGlobal = DAT_004e61a0
void __fastcall FUN_00364250() {
    FUN_002580e0(((char*)&DAT_004e61a0));
}


// 0x00364260 FUN_00364260 (1 B): matches/0x00364260.cpp
// sym: _FUN_00364260
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_00364260() {}


// 0x00364270 FUN_00364270 (10 B): matches/0x00364270.cpp
// sym: _FUN_00364270
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364270() {
    ((owners::Str_240060 *)&((*(Obj_364270*)&DAT_004e61f0)))->FUN_00240060();
}


// 0x00364280 FUN_00364280 (10 B): matches/0x00364280.cpp
// sym: ?FUN_00364280@fn_f1ddef39@@YAXXZ
// data: g_obj_364280 = DAT_004e6208
void FUN_00364280() {
    (*(Obj_364280*)&DAT_004e6208).Fn_002580e0();
}


// 0x00364290 FUN_00364290 (10 B): matches/0x00364290.cpp
// sym: _FUN_00364290
extern "C" void FUN_00364290() {
    (*(G_364290*)((char*)&DAT_004e6250)).Target_002580e0();
}


// 0x003642a0 FUN_003642a0 (10 B): matches/0x003642a0.cpp
// sym: _FUN_003642a0
// data: gHelper_3642a0 = DAT_004e62d8
extern "C" void __cdecl FUN_003642a0() {
    (*(Helper_3642a0*)&DAT_004e62d8).Run_002580e0();
}

} // namespace fn_f1ddef39

// 0x003642b0 FUN_003642b0 (10 B): matches/0x003642b0.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_003642b0@@YAXXZ
namespace fn_003642b0 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct MetaType_3642b0 {
    void FUN_0025fa80();
};
void wrapper() {
    (*(MetaType_3642b0*)&DAT_004e6360).FUN_0025fa80();
}
} // namespace fn_003642b0


// 0x003642c0 FUN_003642c0 (10 B): matches/0x003642c0.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_003642c0@@YAXXZ
namespace fn_003642c0 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct MetaType_3642c0 {
    void FUN_0025fa80();
};
void wrapper() {
    (*(MetaType_3642c0*)&DAT_004e6394).FUN_0025fa80();
}
} // namespace fn_003642c0

namespace fn_f1ddef39 {

// 0x003642d0 FUN_003642d0 (10 B): matches/0x003642d0.cpp
// sym: _FUN_003642d0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_003642d0() {
    (*(MetaType_3642d0*)&DAT_004e63c8).FUN_0025fa80();
}

} // namespace fn_f1ddef39

// 0x003642e0 FUN_003642e0 (10 B): matches/0x003642e0.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_003642e0@@YAXXZ
namespace fn_003642e0 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct MetaType_3642e0 {
    void FUN_0025fa80();
};
void wrapper() {
    (*(MetaType_3642e0*)&DAT_004e63fc).FUN_0025fa80();
}
} // namespace fn_003642e0

namespace fn_f1ddef39 {

// 0x003642f0 FUN_003642f0 (10 B): matches/0x003642f0.cpp
// sym: _FUN_003642f0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_003642f0() {
    (*(MetaType_3642f0*)&DAT_004e6430).FUN_0025fa80();
}


// 0x00364300 FUN_00364300 (10 B): matches/0x00364300.cpp
// sym: _FUN_00364300
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364300() {
    (*(Obj_364300*)&DAT_004e64d8).Fnf_00243350();
}

} // namespace fn_f1ddef39

// 0x00364310 FUN_00364310 (10 B): matches/0x00364310.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_00364310@@YAXXZ
namespace fn_00364310 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_364310 {
    void Fnf_00243350();
};
void wrapper() {
    (*(Obj_364310*)&DAT_004e6548).Fnf_00243350();
}
} // namespace fn_00364310


// 0x00364320 FUN_00364320 (10 B): matches/0x00364320.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_00364320@@YAXXZ
namespace fn_00364320 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_364320 {
    void Fnf_00243350();
};
void wrapper() {
    (*(Obj_364320*)&DAT_004e65b8).Fnf_00243350();
}
} // namespace fn_00364320

namespace fn_f1ddef39 {

// 0x00364330 FUN_00364330 (10 B): matches/0x00364330.cpp
// sym: _FUN_00364330
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364330() {
    (*(Obj_364330*)&DAT_004e6628).Fnf_00243350();
}

} // namespace fn_f1ddef39

// 0x00364340 FUN_00364340 (10 B): matches/0x00364340.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_00364340@@YAXXZ
namespace fn_00364340 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_364340 {
    void Fnf_00243350();
};
void wrapper() {
    (*(Obj_364340*)&DAT_004e6468).Fnf_00243350();
}
} // namespace fn_00364340

namespace fn_f1ddef39 {

// 0x00364360 FUN_00364360 (10 B): matches/0x00364360.cpp
// sym: ?FUN_00364360@fn_f1ddef39@@YIXXZ
// data: g_obj_364360 = DAT_004e6700
void __fastcall FUN_00364360() {
    (*(Obj_364360*)&DAT_004e6700).Run_002580e0();
}


// 0x00364370 FUN_00364370 (10 B): matches/0x00364370.cpp
// sym: _FUN_00364370
// data: g_global = DAT_004e67b8
extern "C" void __cdecl FUN_00364370() {
    target_func_002580e0(((void**)&DAT_004e67b8));
}

} // namespace fn_f1ddef39

// 0x00364380 FUN_00364380 (10 B): matches/0x00364380.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_00364380@@YAXXZ
namespace fn_00364380 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_364380 {
    void Fnf_00260680();
};
void wrapper() {
    (*(Obj_364380*)((char*)&DAT_004e6750)).Fnf_00260680();
}
} // namespace fn_00364380

namespace fn_f1ddef39 {

// 0x00364390 FUN_00364390 (10 B): matches/0x00364390.cpp
// sym: _FUN_00364390
extern "C" void FUN_00364390() {
    (*(G_364390*)&DAT_004e6800).Run_002580e0();
}


// 0x003643a0 FUN_003643a0 (10 B): matches/0x003643a0.cpp
// sym: _FUN_003643a0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_003643a0() {
    (*(Obj_3643a0*)((char*)&DAT_004e6848)).Fnf_00260680();
}

} // namespace fn_f1ddef39

// 0x003643b0 FUN_003643b0 (10 B): matches/0x003643b0.cpp [wrapped: conflict: FUN_002580e0; FUN_003643b0]
// sym: _FUN_003643b0@0
namespace fn_003643b0 {

extern "C++" __declspec(nothrow) void __stdcall FUN_002580e0(void*);
struct Obj_3643b0 {
    void Fn_002580e0();
};
extern "C" void __stdcall FUN_003643b0() {
    ((Obj_3643b0*)&(*(int*)&DAT_004e68b0))->Fn_002580e0();
}
} // namespace fn_003643b0

namespace fn_f1ddef39 {

// 0x003643c0 FUN_003643c0 (10 B): matches/0x003643c0.cpp
// sym: _FUN_003643c0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_003643c0() {
    (*(Obj_3643c0*)&DAT_004e68f8).Fnf_00260680();
}


// 0x003643d0 FUN_003643d0 (10 B): matches/0x003643d0.cpp
// sym: _FUN_003643d0
extern "C" void FUN_003643d0() {
    (*(Obj_3643d0*)((char*)&DAT_004e6960)).Fn_002580e0();
}


// 0x003643e0 FUN_003643e0 (10 B): matches/0x003643e0.cpp
// sym: _FUN_003643e0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_003643e0() {
    (*(Obj_3643e0*)&DAT_004e69b0).Fnf_00260680();
}


// 0x003643f0 FUN_003643f0 (10 B): matches/0x003643f0.cpp
// sym: ?FUN_003643f0@fn_f1ddef39@@YAXXZ
// data: hulk_at_004e6a18 = DAT_004e6a18
void __cdecl FUN_003643f0() {
    ((Obj_3643f0*)((hulk_intptr)DAT_004e6a18))->Fn_002580e0();
}


// 0x00364400 FUN_00364400 (10 B): matches/0x00364400.cpp
// sym: _FUN_00364400
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364400() {
    (*(Obj_364400*)((char*)&DAT_004e6a68)).Fnf_00260680();
}


// 0x00364410 FUN_00364410 (10 B): matches/0x00364410.cpp
// sym: _FUN_00364410
extern "C" void __cdecl FUN_00364410() {
    ((Helper_364410*)&(*(void**)&DAT_004e6ad0))->Run_002580e0();
}


// 0x00364420 FUN_00364420 (10 B): matches/0x00364420.cpp
// sym: _FUN_00364420
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364420() {
    (*(Obj_364420*)&DAT_004e6b18).Fnf_00260680();
}


// 0x00364430 FUN_00364430 (10 B): matches/0x00364430.cpp
// sym: _FUN_00364430
extern "C" void __cdecl FUN_00364430() {
    (*(Obj_364430*)&DAT_004e6b80).Fn_002580e0();
}

} // namespace fn_f1ddef39

// 0x00364440 FUN_00364440 (10 B): matches/0x00364440.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_00364440@@YAXXZ
namespace fn_00364440 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_364440 {
    void Fnf_00260680();
};
void wrapper() {
    (*(Obj_364440*)&DAT_004e6bc8).Fnf_00260680();
}
} // namespace fn_00364440

namespace fn_f1ddef39 {

// 0x00364450 FUN_00364450 (10 B): matches/0x00364450.cpp
// sym: _FUN_00364450
// data: g_sub_364450 = DAT_004e6c30
extern "C" void __cdecl FUN_00364450() {
    (*(Sub_364450*)((char*)&DAT_004e6c30)).Fn_002580e0();
}


// 0x00364460 FUN_00364460 (10 B): matches/0x00364460.cpp
// sym: _FUN_00364460
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364460() {
    (*(Obj_364460*)((char*)&DAT_004e6c78)).Fnf_00260680();
}


// 0x00364470 FUN_00364470 (10 B): matches/0x00364470.cpp
// sym: _FUN_00364470
// data: globalThing = DAT_004e6ce0
extern "C" void __cdecl FUN_00364470() {
    (*(SeqEventChannelSendVolumesType_364470*)&DAT_004e6ce0).go_002580e0();
}


// 0x00364480 FUN_00364480 (10 B): matches/0x00364480.cpp
// sym: _FUN_00364480
extern "C" void __cdecl FUN_00364480() {
    (*(Obj_364480*)&DAT_004e6d98).Fn_002580e0();
}


// 0x00364490 FUN_00364490 (10 B): matches/0x00364490.cpp
// sym: _FUN_00364490
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364490() {
    (*(Obj_364490*)((char*)&DAT_004e6d30)).Fnf_00260680();
}


// 0x003644a0 FUN_003644a0 (10 B): matches/0x003644a0.cpp
// sym: _FUN_003644a0
extern "C" void FUN_003644a0() {
    (*(Obj_3644a0*)&DAT_004e6de0).Fn_002580e0();
}

} // namespace fn_f1ddef39

// 0x003644b0 FUN_003644b0 (10 B): matches/0x003644b0.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_003644b0@@YAXXZ
namespace fn_003644b0 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_3644b0 {
    void Fnf_00260680();
};
void wrapper() {
    (*(Obj_3644b0*)((char*)&DAT_004e6e28)).Fnf_00260680();
}
} // namespace fn_003644b0

namespace fn_f1ddef39 {

// 0x003644c0 FUN_003644c0 (10 B): matches/0x003644c0.cpp
// sym: ?FUN_003644c0@fn_f1ddef39@@YAXXZ
// data: hulk_at_004e6e90 = DAT_004e6e90
void __cdecl FUN_003644c0() {
    FUN_002580e0((void*)((hulk_intptr)DAT_004e6e90));
}


// 0x003644d0 FUN_003644d0 (10 B): matches/0x003644d0.cpp
// sym: _FUN_003644d0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_003644d0() {
    (*(Obj_3644d0*)&DAT_004e6ed8).Fnf_00260680();
}


// 0x003644e0 FUN_003644e0 (10 B): matches/0x003644e0.cpp
// sym: _FUN_003644e0
extern "C" void FUN_003644e0() {
    (*(Obj_3644e0*)((char*)&DAT_004e6f40)).Fn_002580e0();
}


// 0x003644f0 FUN_003644f0 (10 B): matches/0x003644f0.cpp
// sym: _FUN_003644f0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_003644f0() {
    (*(Obj_3644f0*)&DAT_004e6f88).Fnf_00260680();
}


// 0x00364500 FUN_00364500 (10 B): matches/0x00364500.cpp
// sym: _FUN_00364500
extern "C" void FUN_00364500() {
    (*(Obj*)&DAT_004e6ff0).Fn_002580e0();
}

} // namespace fn_f1ddef39

// 0x00364510 FUN_00364510 (10 B): matches/0x00364510.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_00364510@@YAXXZ
namespace fn_00364510 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_364510 {
    void Fnf_00260680();
};
void wrapper() {
    (*(Obj_364510*)((char*)&DAT_004e7038)).Fnf_00260680();
}
} // namespace fn_00364510

namespace fn_f1ddef39 {

// 0x00364520 FUN_00364520 (10 B): matches/0x00364520.cpp
// sym: ?FUN_00364520@fn_f1ddef39@@YGXXZ
// data: hulk_at_004e70a0 = DAT_004e70a0
void __stdcall FUN_00364520() {
    ((Obj_364520*)((hulk_intptr)DAT_004e70a0))->Go_002580e0();
}


// 0x00364530 FUN_00364530 (10 B): matches/0x00364530.cpp
// sym: _FUN_00364530
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364530() {
    (*(Obj_364530*)&DAT_004e70e8).Fnf_00260680();
}


// 0x00364540 FUN_00364540 (10 B): matches/0x00364540.cpp
// sym: _FUN_00364540
extern "C" void __cdecl FUN_00364540() {
    (*(Obj_364540*)((char*)&DAT_004e7150)).Run_002580e0();
}


// 0x00364550 FUN_00364550 (10 B): matches/0x00364550.cpp
// sym: _FUN_00364550
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364550() {
    (*(Obj_364550*)&DAT_004e7198).Fnf_00260680();
}


// 0x00364560 FUN_00364560 (10 B): matches/0x00364560.cpp
// sym: ?FUN_00364560@fn_f1ddef39@@YAXXZ
void __cdecl FUN_00364560() {
    (*(Obj_364560*)((char*)&DAT_004e7268)).Fn_002580e0();
}


// 0x00364570 FUN_00364570 (10 B): matches/0x00364570.cpp
// sym: _FUN_00364570
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364570() {
    (*(Obj_364570*)&DAT_004e7200).Fnf_00260680();
}


// 0x00364580 FUN_00364580 (10 B): matches/0x00364580.cpp
// sym: ?FUN_00364580@fn_f1ddef39@@YIXXZ
void __fastcall FUN_00364580() {
    FUN_002580e0(((void**)&DAT_004e72b0));
}


// 0x00364590 FUN_00364590 (10 B): matches/0x00364590.cpp
// sym: _FUN_00364590
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364590() {
    (*(Obj_364590*)&DAT_004e72f8).Fnf_00260680();
}


// 0x003645a0 FUN_003645a0 (10 B): matches/0x003645a0.cpp
// sym: _FUN_003645a0
extern "C" void __cdecl FUN_003645a0() {
    (*(Obj_3645a0*)((char*)&DAT_004e7360)).Fn_002580e0();
}

} // namespace fn_f1ddef39

// 0x003645b0 FUN_003645b0 (10 B): matches/0x003645b0.cpp [wrapped: same definition as 0x00363c30 in this TU]
// sym: ?wrapper@fn_003645b0@@YAXXZ
namespace fn_003645b0 {
// Same code shape as 0x00363af0 (propagated; names are from that function)

struct Obj_3645b0 {
    void Fnf_00260680();
};
void wrapper() {
    (*(Obj_3645b0*)&DAT_004e73a8).Fnf_00260680();
}
} // namespace fn_003645b0

namespace fn_f1ddef39 {

// 0x003645c0 FUN_003645c0 (10 B): matches/0x003645c0.cpp
// sym: _FUN_003645c0
extern "C" void FUN_003645c0() {
    (*(Obj_3645c0*)&DAT_004e7410).Run_002580e0();
}


// 0x003645d0 FUN_003645d0 (10 B): matches/0x003645d0.cpp
// sym: _FUN_003645d0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_003645d0() {
    (*(Obj_3645d0*)((char*)&DAT_004e7458)).Fnf_00260680();
}

} // namespace fn_f1ddef39

// 0x003645e0 FUN_003645e0 (10 B): matches/0x003645e0.cpp [wrapped: conflict: FUN_003645e0]
// sym: ?FUN_003645e0@fn_003645e0@@YGXXZ
namespace fn_003645e0 {

class G_3645e0 {
  public:
    void Run_002580e0();
};
void __stdcall FUN_003645e0() {
    (*(G_3645e0*)&DAT_004e74c0).Run_002580e0();
}
} // namespace fn_003645e0

namespace fn_f1ddef39 {

// 0x003645f0 FUN_003645f0 (10 B): matches/0x003645f0.cpp
// sym: _FUN_003645f0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_003645f0() {
    (*(Obj_3645f0*)&DAT_004e7508).Fnf_00260680();
}


// 0x00364600 FUN_00364600 (10 B): matches/0x00364600.cpp
// sym: ?FUN_00364600@fn_f1ddef39@@YAXXZ
void FUN_00364600() {
    gObj.Run_002580e0();
}


// 0x00364610 FUN_00364610 (10 B): matches/0x00364610.cpp
// sym: _FUN_00364610
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364610() {
    (*(Obj_364610*)&DAT_004e75b8).Fnf_00260680();
}


// 0x00364620 FUN_00364620 (10 B): matches/0x00364620.cpp
// sym: ?FUN_00364620@fn_f1ddef39@@YIXXZ
void __fastcall FUN_00364620() {
    (*(Obj_364620*)&DAT_004e7690).Run_002580e0();
}


// 0x00364630 FUN_00364630 (10 B): matches/0x00364630.cpp
// sym: _FUN_00364630
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364630() {
    (*(Obj_364630*)((char*)&DAT_004e7620)).Fnf_00243350();
}


// 0x00364640 FUN_00364640 (1 B): matches/0x00364640.cpp
// sym: _FUN_00364640
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_00364640() {}


// 0x00364650 FUN_00364650 (10 B): matches/0x00364650.cpp
// sym: ?FUN_00364650@fn_f1ddef39@@YAXXZ
void FUN_00364650() {
    (*(Obj_364650*)&DAT_004e76e8).Fn_002580e0();
}


// 0x00364660 FUN_00364660 (10 B): matches/0x00364660.cpp
// sym: _FUN_00364660
// data: gThing_364660 = DAT_004e7730
extern "C" void FUN_00364660() {
    (*(Thing_364660*)((char*)&DAT_004e7730)).~Thing_364660();
}


// 0x00364670 FUN_00364670 (10 B): matches/0x00364670.cpp
// sym: ?FUN_00364670@fn_f1ddef39@@YIXXZ
void __fastcall FUN_00364670() {
    (*(G_364670*)((char*)&DAT_004e7778)).Run_002580e0();
}


// 0x00364680 FUN_00364680 (10 B): matches/0x00364680.cpp
// sym: ?FUN_00364680@fn_f1ddef39@@YIXXZ
void __fastcall FUN_00364680() throw() {
    FUN_002580e0(((Obj_364680*)&DAT_004e77c0));
}


// 0x00364690 FUN_00364690 (10 B): matches/0x00364690.cpp
// sym: _FUN_00364690
extern "C" void __cdecl FUN_00364690() {
    (*(Obj_364690*)&DAT_004e7808).Fn_002580e0();
}


// 0x003646a0 FUN_003646a0 (10 B): matches/0x003646a0.cpp
// sym: _FUN_003646a0
extern "C" void FUN_003646a0() {
    gObj.Run_002580e0();
}


// 0x003646b0 FUN_003646b0 (10 B): matches/0x003646b0.cpp
// sym: _FUN_003646b0
extern "C" void FUN_003646b0() {
    (*(Obj_3646b0*)&DAT_004e7898).Run_002580e0();
}


// 0x003646c0 FUN_003646c0 (10 B): matches/0x003646c0.cpp
// sym: _FUN_003646c0
extern "C" void FUN_003646c0() {
    (*(Obj_3646c0*)&DAT_004e78e0).Fn_002580e0();
}


// 0x003646d0 FUN_003646d0 (10 B): matches/0x003646d0.cpp
// sym: ?Wrapper@fn_f1ddef39@@YGXXZ
// data: gData_3646d0 = DAT_004e7928
void __stdcall Wrapper() {
    Obj_3646d0* p = (Obj_3646d0*)&(*(int*)((char*)&DAT_004e7928));
    p->Run_002580e0();
}


// 0x003646e0 FUN_003646e0 (10 B): matches/0x003646e0.cpp
// sym: _FUN_003646e0
extern "C" void FUN_003646e0() {
    (*(Obj_3646e0*)((char*)&DAT_004e7970)).Init_002580e0();
}


// 0x003646f0 FUN_003646f0 (10 B): matches/0x003646f0.cpp
// sym: ?FUN_003646f0@fn_f1ddef39@@YIXXZ
void __fastcall FUN_003646f0() {
    (*(Obj_3646f0*)&DAT_004e79d0).Run_002580e0();
}


// 0x00364700 FUN_00364700 (10 B): matches/0x00364700.cpp
// sym: _FUN_00364700
extern "C" void __cdecl FUN_00364700() {
    (*(Obj_364700*)&DAT_004e7a30).Run_002580e0();
}


// 0x00364710 FUN_00364710 (10 B): matches/0x00364710.cpp
// sym: ?Fn@Obj_364710@fn_f1ddef39@@QAEXXZ
// data: g_base_364710 = DAT_004e7a78
void Obj_364710::Fn() {
    ((Base_364710*)&DAT_004e7a78)->Fn_002580e0();
}


// 0x00364720 FUN_00364720 (10 B): matches/0x00364720.cpp
// sym: @FUN_00364720@0
// data: g_obj_364720 = DAT_004e7ac0
extern "C" void __fastcall FUN_00364720() {
    (*(A_364720*)&DAT_004e7ac0).Run_002580e0();
}


// 0x00364730 FUN_00364730 (10 B): matches/0x00364730.cpp
// sym: _FUN_00364730
extern "C" void __cdecl FUN_00364730() {
    (*(Obj_364730*)&DAT_004e7b08).Run_002580e0();
}


// 0x00364750 FUN_00364750 (10 B): matches/0x00364750.cpp
// sym: ?FUN_00364750@fn_f1ddef39@@YIXXZ
void __fastcall FUN_00364750() {
    (*(Obj_364750*)&DAT_004e7b98).Run_002580e0();
}


// 0x00364760 FUN_00364760 (10 B): matches/0x00364760.cpp
// sym: _FUN_00364760
extern "C" void FUN_00364760() {
    (*(Obj_364760*)&DAT_004e7be0).Target_002580e0();
}


// 0x00364770 FUN_00364770 (1 B): matches/0x00364770.cpp
// sym: _FUN_00364770
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_00364770() {}


// 0x00364780 FUN_00364780 (11 B): matches/0x00364780.cpp
// sym: _FUN_00364780
void FUN_00364780() {
    (*(IRefCount**)&DAT_004cdb4c) = (IRefCount*)((hulk_intptr)DAT_003f6098);
}


// 0x00364790 FUN_00364790 (27 B): matches/0x00364790.cpp
// sym: _FUN_00364790
// data: PTR_vftable_004ce400 = DAT_004ce400
void FUN_00364790(void) {
    (*(void**)&DAT_004ce400) = (void*)((hulk_intptr)DAT_0042c1b4);
    if (DAT_004ce410)
        thunk_FUN_00267090((hulk_intptr)DAT_004ce410);
}


// 0x003647b0 FUN_003647b0 (10 B): matches/0x003647b0.cpp
// sym: _FUN_003647b0
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_003647b0() {
    (*(ImageConverter_3647b0*)&DAT_00554bd0).Fnf_002de240();
}


// 0x003647c0 FUN_003647c0 (56 B): matches/0x003647c0.cpp
// sym: _FUN_003647c0
extern "C" {
void __cdecl FUN_003647c0(void) {
    if ((*(int*)&DAT_00555468) != 0)
        thunk_0008d340((*(int*)&DAT_00555468));
    if ((*(int*)&DAT_0055545c) != 0) {
        FUN_002f9fb0((*(int*)&DAT_0055545c), (*(int*)&DAT_00555460));
        thunk_0008d340((*(int*)&DAT_0055545c));
    }
}
}


// 0x00364800 FUN_00364800 (11 B): matches/0x00364800.cpp
// sym: _FUN_00364800
// data: gExtension = DAT_004d3a0c
extern "C" void FUN_00364800() {
    (*(void**)&DAT_004d3a0c) = &hulk_at_0043276c;
}


// 0x00364810 FUN_00364810 (10 B): matches/0x00364810.cpp
// sym: _FUN_00364810
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364810() {
    (*(Obj_364810*)&DAT_0055dbb0).Fnf_00337d40();
}


// 0x00364820 FUN_00364820 (10 B): matches/0x00364820.cpp
// sym: _FUN_00364820
// Same code shape as 0x00363af0 (propagated; names are from that function)
extern "C" void FUN_00364820() {
    (*(Obj_364820*)&DAT_00565fc0).Fnf_00337d40();
}


// 0x00364830 FUN_00364830 (1 B): matches/0x00364830.cpp
// sym: ?FUN_00364830@fn_f1ddef39@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00364830() {}

} // namespace fn_f1ddef39
