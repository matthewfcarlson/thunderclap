// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c7500..0x001c7ca0 (kind game, layer game, confidence medium), dominant class Render::StoreBase
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "gen/Render.h"
#define TREE_TU_BEGIN namespace fn_f6c5dfc0 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
namespace fn_f6c5dfc0 {} using namespace fn_f6c5dfc0;
#include "game/Render.h"

// ---- declarations shared by the functions below
namespace fn_f6c5dfc0 {
extern "C" char DAT_00421a3c[];
void thunk_0008d330(int);
class StoreBase {
  public:
    hulk_intptr vp;
    int a[4];
    int b;
    void Fn();
};
class X_1c7520 {
  public:
    char pad[12];
    int a, b;
    int* p;
};
struct Key_1c7550 {
    int lo, hi;
};
struct Pending_1c7550 {
    int lo, hi;
    int w8, wc;
};
class Result_1c7550 {
public:
    char FUN_0027af90(const Key_1c7550 *key);
};
class Registry_1c7550 {
public:
    virtual void v0();
    virtual Result_1c7550 *Lookup(void *entry);     // slot 1
    char pad04[8];
    int removed;             // 0x0c
    int last;                // 0x10
    void **entries;          // 0x14
    Pending_1c7550 pending[16];     // 0x18
    void FUN_001c7550(const Key_1c7550 *key);
};
struct Key_1c75e0 {
    unsigned int lo;
    unsigned int hi;
};
struct Slot_1c75e0 {
    unsigned int keyLo;
    unsigned int keyHi;
    void *value;
    unsigned int stamp;
};
struct Resolved {
    char FUN_0027af90(Key_1c75e0 *key);
};
class Cache_1c75e0 {
public:
    virtual void v0();
    virtual Resolved *v1(void *source);
    char pad04[0xc];
    int sourceCount;
    void **sources;
    Slot_1c75e0 slots[16];
    unsigned int clock;

    void *FUN_001c75e0(Key_1c75e0 *key);
};
extern void __cdecl thunk_FUN_00267090(void* p);
} // namespace fn_f6c5dfc0
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memset(void*, int, unsigned int);
#endif
namespace fn_f6c5dfc0 {
class StoreBase_1c77e0 {
  public:
    StoreBase_1c77e0(unsigned int, unsigned char);
};
struct StoreBase_nv_1c7870 {
    void FUN_001c7770(int newCapacity);
};
extern "C" char DAT_00421a68[];
class Sub_1c7a00 {
  public:
    void Init_002a30a0();
};
class ShadowGenerator {
  public:
    hulk_intptr mVft;
    int mValue;
    Sub_1c7a00 mSub;
    ShadowGenerator();
};
struct ThisCall_001c6f70 {
    void FUN_001c6f70();
};
extern void thunk_FUN_00267090(CCollisionAction*);
} // namespace fn_f6c5dfc0
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sin(double);
#endif
namespace fn_f6c5dfc0 {
struct Vec3_1c7a60 { float x, y, z; };
struct VertexSink_1c7a60 {
    char pad0[8];
    float *pos;
    char pad0c[4];
    unsigned int *color;
    float *tex;
    void FUN_0008ef00();
};
class Device1 {
public:
    virtual void vfunc_0();
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
    virtual void vfunc_15(int a);
    virtual void vfunc_16(int a);
};
struct Wrapper1 {
    Device1 *dev;
    void FUN_00293d00(Vec3_1c7a60 *origin);
};
} // namespace fn_f6c5dfc0
class Gfx {
public:
    virtual void vfunc_0();
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
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual VertexSink_1c7a60 *vfunc_30(int buffer, int a, int flags, int stride, int b);
    virtual void vfunc_31(VertexSink_1c7a60 *sink);
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62(int a);
};
namespace fn_f6c5dfc0 {
struct Target_1c7a60 {
    char pad0[0x24];
    Vec3_1c7a60 pos;
};
struct Buffer_1c7a60 {
    char pad0[0x10];
    int handle;
};
class Marker_1c7a60 {
public:
    char pad0[0x750];
    Buffer_1c7a60 *buffer;
    void Draw(Target_1c7a60 *target, float radius, unsigned int gray, unsigned int alpha, unsigned int edgeByte);
};
class Store {
  public:
    virtual void* Fnf_001c7dc0(char);
    void Cleanup2_001c7500();
    ~Store();
    int mData;
};


// 0x001c7500 FUN_001c7500 (17 B): matches/0x001c7500.cpp
// sym: ?Fn@StoreBase@fn_f6c5dfc0@@QAEXXZ
void StoreBase::Fn() {
    int t = b;
    vp = ((hulk_intptr)DAT_00421a3c);
    thunk_0008d330(t);
}


// 0x001c7520 FUN_001c7520 (38 B): matches/0x001c7520.cpp
// sym: ?target@fn_f6c5dfc0@@YIHPAVX_1c7520@1@@Z
int __fastcall target(X_1c7520* x) {
    int r;
    if (x->a) {
        int n = x->b;
        r = 0;
        if (n >= 0) {
            int* p = x->p;
            ++n;
            do {
                if (*p)
                    ++r;
                ++p;
                --n;
            } while (n);
        }
        return r;
    }
    return x->b + 1;
}


// 0x001c7550 FUN_001c7550 (143 B): equivalent/0x001c7550.cpp
// sym: ?FUN_001c7550@Registry_1c7550@fn_f6c5dfc0@@QAEXPBUKey_1c7550@2@@Z @58d4c1a93d29 @w764b04e9b5d4
// STATUS: equivalent (tools/equiv.py level 3: 1900 inputs, branch coverage 14/14)
// FUN_001c7550 @ 0x001c7550
// Cancels a pending request for the key, then drops the first entry that resolves it.
void Registry_1c7550::FUN_001c7550(const Key_1c7550 *key) {
    int lo = key->lo;
    int hi = key->hi;
    for (int i = 0; i < 16; i++) {
        if (pending[i].lo == lo && pending[i].hi == hi) {
            pending[i].lo = 0;
            pending[i].hi = 0;
            pending[i].w8 = 0;
            break;
        }
    }
    if (last < 0)
        return;
    int i = 0;
    do {
        void *entry = entries[i];
        if (entry != 0 && Lookup(entry)->FUN_0027af90(key)) {
            entries[i] = 0;
            removed++;
            return;
        }
        i++;
    } while (i <= last);
}


// 0x001c75e0 FUN_001c75e0 (305 B): equivalent/0x001c75e0.cpp
// sym: ?FUN_001c75e0@Cache_1c75e0@fn_f6c5dfc0@@QAEPAXPAUKey_1c75e0@2@@Z @ac20dfcc7ad5 @wcc6be0d2f12f
// STATUS: equivalent (tools/equiv.py level 3: 2964 inputs, branch coverage 22/22)
// FUN_001c75e0 @ 0x001c75e0
void *Cache_1c75e0::FUN_001c75e0(Key_1c75e0 *key)
{
    int i;

    for (i = 0; i < 16; i++) {
        if (slots[i].keyLo == key->lo && slots[i].keyHi == key->hi) {
            slots[i].stamp = clock;
            clock++;
            return slots[i].value;
        }
    }

    for (i = 0; i <= sourceCount; i++) {
        void *src = sources[i];
        if (src == 0)
            continue;
        if (!v1(src)->FUN_0027af90(key))
            continue;

        void *found = sources[i];
        if (found == 0)
            return 0;

        int victim = 0;
        unsigned int oldest = 0xffffffff;
        for (int j = 0; j < 16; j++) {
            if (slots[j].value == 0) {
                victim = j;
                break;
            }
            if (slots[j].stamp < oldest) {
                oldest = slots[j].stamp;
                victim = j;
            }
        }

        slots[victim].stamp = clock;
        clock++;
        slots[victim].value = found;
        slots[victim].keyLo = key->lo;
        slots[victim].keyHi = key->hi;
        return found;
    }
    return 0;
}

} // namespace fn_f6c5dfc0

// 0x001c7720 FUN_001c7720 (69 B): matches/0x001c7720.cpp
// sym: ?FUN_001c7720@StoreBase@Render@@QAEXXZ
void Render::StoreBase::FUN_001c7720() {
    int i = 0;
    if (this->f_10 >= 0) {
        do {
            void* p = (*(void ** *)&this->f_14)[i];
            if (p) {
                vfunc_2(p);
                (*(void ** *)&this->f_14)[i] = 0;
            }
            ++i;
        } while (i <= this->f_10);
    }
    this->f_0c = 0;
    this->f_10 = -1;
}


// 0x001c7770 FUN_001c7770 (106 B): matches/0x001c7770.cpp
// sym: ?FUN_001c7770@StoreBase@Render@@QAEXI@Z
// FUN_001c7770 @ 0x001c7770
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d330
void Render::StoreBase::FUN_001c7770(unsigned int newCapacity) {
    int* fresh = static_cast<int*>(FUN_0008d690(newCapacity << 2));
    memset(fresh, 0, newCapacity << 2);
    if ((*(int * *)&this->f_14) != 0)
        memcpy(fresh, (*(int * *)&this->f_14), (*(unsigned int *)&this->f_10) * 4 + 4);
    (*(unsigned int *)&this->f_08) = newCapacity;
    thunk_FUN_00267090((*(int * *)&this->f_14));
    (*(int * *)&this->f_14) = fresh;
}

namespace fn_f6c5dfc0 {

// 0x001c77e0 FUN_001c77e0 (86 B): matches/0x001c77e0.cpp
// sym: ??0StoreBase_1c77e0@fn_f6c5dfc0@@QAE@IE@Z
StoreBase_1c77e0::StoreBase_1c77e0(unsigned int arg, unsigned char flag) {
    unsigned char* p = (unsigned char*)this;
    *(hulk_uintptr*)p = ((hulk_intptr)DAT_00421a3c);
    *(unsigned int*)(p + 8) = 0;
    *(unsigned int*)(p + 12) = 0;
    *(unsigned int*)(p + 16) = 0xffffffff;
    *(unsigned int*)(p + 20) = 0;
    unsigned int* q = (unsigned int*)(p + 24);
    int i;
    for (i = 0; i < 16; i++) {
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
        q += 4;
    }
    *(unsigned int*)(p + 0x118) = 0;
    *(unsigned char*)(p + 0x11c) = flag;
    ((Render::StoreBase *)this)->FUN_001c7770(arg);
}

} // namespace fn_f6c5dfc0

// 0x001c7840 Render::StoreBase::vfunc_0 (44 B): matches/0x001c7840.cpp [wrapped: conflict: StoreBase]
// sym: ?vfunc_0@StoreBase@fn_001c7840@@UAEPAU12@E@Z
namespace fn_001c7840 {
struct StoreBase {
    virtual StoreBase* vfunc_0(unsigned char);
    virtual void f1();
    virtual void f2();
    char pad[0x10];
    void* member;
};
extern void __cdecl helper_0008d330(void*);
extern void* hulk_at_00421a3c;
StoreBase* StoreBase::vfunc_0(unsigned char flag) {
    *(void**)this = &hulk_at_00421a3c;
    helper_0008d330(member);
    if (flag & 1)
        helper_0008d330(this);
    return this;
}
} // namespace fn_001c7840


// 0x001c7870 FUN_001c7870 (112 B): equivalent/0x001c7870.cpp
// sym: ?FUN_001c7870@StoreBase@Render@@QAEXHH@Z @fce4807c83f7 @w736e5423dfe0
// STATUS: equivalent (tools/equiv.py level 3: 1510 inputs, branch coverage 10/10)
// FUN_001c7870 @ 0x001c7870
// Stores value in the first empty slot, or appends it (growing the pool when full).
void Render::StoreBase::FUN_001c7870(int unused, int value) {
    if (this->f_0c != 0 && this->f_10 >= 0) {
        int* p = (*(int * *)&this->f_14);
        for (int i = 0; i <= this->f_10; i++) {
            if (p[i] == 0) {
                p[i] = value;
                this->f_0c--;
                return;
            }
        }
    }
    if (this->f_10 == this->f_08 - 1)
        ((StoreBase_nv_1c7870*)this)->FUN_001c7770(this->f_08 * 2);
    this->f_10++;
    (*(int * *)&this->f_14)[this->f_10] = value;
}

namespace fn_f6c5dfc0 {

// 0x001c7a00 FUN_001c7a00 (28 B): matches/0x001c7a00.cpp
// sym: ??0ShadowGenerator@fn_f6c5dfc0@@QAE@XZ
ShadowGenerator::ShadowGenerator() {
    mValue = 0;
    mVft = ((hulk_intptr)DAT_00421a68);
    mSub.Init_002a30a0();
}


// 0x001c7a20 FUN_001c7a20 (30 B): matches/0x001c7a20.cpp
// sym: ?vfunc_2@CCollisionAction@fn_f6c5dfc0@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_001c6f70*)(this))->FUN_001c6f70();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x001c7a60 FUN_001c7a60 (425 B): equivalent/0x001c7a60.cpp
// sym: ?Draw@Marker_1c7a60@fn_f6c5dfc0@@QAEXPAUTarget_1c7a60@2@MIII@Z @a332e199984d @w0a6fb0354c87
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001c7a60 @ 0x001c7a60
void Marker_1c7a60::Draw(Target_1c7a60 *target, float radius, unsigned int gray, unsigned int alpha, unsigned int edgeByte)
{
    unsigned int edge = ((((edgeByte | 0xffffff00) << 8) | edgeByte) << 8) | edgeByte;
    unsigned int fill = ((((alpha << 8) | gray) << 8 | gray) << 8) | gray;

    Vec3_1c7a60 origin = target->pos;
    (*(Wrapper1**)&DAT_0052c2ac)->dev->vfunc_15(0);
    (*(Wrapper1**)&DAT_0052c2ac)->FUN_00293d00(&origin);
    DAT_0052c2a8->vfunc_62(0);
    VertexSink_1c7a60 *sink = DAT_0052c2a8->vfunc_30(buffer->handle, 0, 0x2020, 0x24, 0);

    float angle = 0.0f;
    float x = (float)(sin(0.0) * radius);
    float y = (float)(cos(0.0) * radius);
    for (int i = 12; i != 0; i--) {
        *sink->color = fill;
        sink->pos[0] = 0.0f;
        sink->pos[1] = 0.03f;
        sink->pos[2] = 0.0f;
        sink->FUN_0008ef00();

        *sink->color = edge;
        sink->pos[0] = x;
        sink->pos[1] = 0.03f;
        sink->pos[2] = y;
        sink->FUN_0008ef00();

        angle = angle + 0.52359879f;
        *sink->color = edge;
        x = (float)(sin(angle) * radius);
        sink->pos[0] = x;
        sink->pos[1] = 0.03f;
        y = (float)(cos(angle) * radius);
        sink->pos[2] = y;
        sink->FUN_0008ef00();
    }

    DAT_0052c2a8->vfunc_31(sink);
    DAT_0052c2a8->vfunc_62(1);
    (*(Wrapper1**)&DAT_0052c2ac)->dev->vfunc_16(0);
}


// 0x001c7c30 FUN_001c7c30 (22 B): matches/0x001c7c30.cpp
// sym: ??1Store@fn_f6c5dfc0@@QAE@XZ
// Same code shape as 0x001c5640 (propagated; names are from that function)
Store::~Store() {
    ((Render::StoreBase *)this)->FUN_001c7720();
    Cleanup2_001c7500();
}

} // namespace fn_f6c5dfc0
