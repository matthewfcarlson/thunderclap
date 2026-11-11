// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00288820..0x00289ed0 (kind game, layer engine, confidence high), dominant class pure3d::AnimationLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f25f8e16 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f25f8e16 {} using namespace fn_f25f8e16;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f25f8e16 {
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
struct NonCopyable_288820 {
    int a;
    NonCopyable_288820() { a = 0; }
};
class AnimationMemoryBlock_288820 : public NonCopyable_288820 {
  public:
    virtual void f0();
    unsigned int sz1;
    unsigned int sz2;
    int b;
    int c;
    void* buf1;
    void* buf2;
    AnimationMemoryBlock_288820(unsigned int s1, unsigned int s2);
};
extern "C" char DAT_0042c8b4[];
typedef unsigned int u32_288890;
void thunk(u32_288890);
struct AnimationMemoryBlock_288890 {
    hulk_uintptr vf;
    char pad[0x14];
    u32_288890 a;
    u32_288890 b;
    void target();
};
class Sub_288900 {
  public:
    void Init();
    char pad[8];
};
class AnimationGroup {
  public:
    AnimationGroup();
    virtual ~AnimationGroup();
    char pad[4];
    Sub_288900 sub;
    int a, b, c, d;
};
extern void FUN_0027af50();
extern void thunk_FUN_00267090(CCollisionAction*);
class Item_288960 {
  public:
    virtual int A();
    virtual int B();
    virtual int Get();
    int a4;
    int key;
};
class Owner_288960 {
  public:
    char a[0x14];
    unsigned count;
    Item_288960** items;
    Item_288960* Find(int key, int value);
};
extern int anim_vt;
class Entity_2889b0 {
  public:
    virtual void B();
    int b[3];
    Entity_2889b0();
};
class Animation : public Entity_2889b0 {
  public:
    virtual void B();
    Animation();
    int x10;
    float x14;
    unsigned char x18;
    char pad2[3];
    int x1c[8];
};
} // namespace fn_f25f8e16
namespace pure3d {
class Entity_288a00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x100];
};
}
namespace fn_f25f8e16 {
struct Item_288a20 {
    char pad0[0x10];
    int key;                // 0x10
};
class ItemList_288a20 {
public:
    char pad0[0x24];
    int sorted;             // 0x24
    int count;              // 0x28
    Item_288a20 **items;           // 0x2c
    Item_288a20 *FUN_00288a20(int key);
};
struct Entry_288ad0 { char padding[8]; unsigned int low; unsigned int high; };
struct Table_288ad0 {
 char padding[0x24];
 int unsorted;
 int count;
 Entry_288ad0 **entries;
 Entry_288ad0 * FUN_00288ad0(unsigned int low, unsigned int high);
};
struct Entry_288c40 { char pad[8]; unsigned int low, high; };
struct Table_288c40 {
 char pad[0x24]; int unsorted; int count; Entry_288c40 **entries;
 int FUN_00288c40(unsigned int low, unsigned int high);
};
struct Window_288d10 { float start; float length; };
struct Entry_288d10 { unsigned key1, key2; Window_288d10 windows[2]; };
struct Object {
 char pad0[16]; float period; char pad1[32]; unsigned count; Entry_288d10* entries;
 bool FUN_00288d10(float time, unsigned key1, unsigned key2, unsigned* index, float* fraction);
};
struct Entry_288de0 {
    unsigned int key0;
    unsigned int key1;
    float offset;
    float scale;
    float pad[2];
};
struct Curve_288de0 {
    char pad0[0x10];
    float limit;
    char pad1[0x20];
    unsigned int count;
    Entry_288de0 *entries;
    hulk_freg FUN_00288de0(int slot, float x, unsigned int key0, unsigned int key1);
};
class AnimationFrameController {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void vfunc_8(int);
    char pad[0x18 - 4];
    int field;
};
class Obj_288ea0 {
  public:
    char pad[0x14];
    int mVal;
    int Target();
};
} // namespace fn_f25f8e16
inline void *operator new(size_t, void *p) throw() { return p; }
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *__cdecl memset(void *, int, unsigned int);
#endif
namespace fn_f25f8e16 {
extern "C" void *FUN_0008d690(unsigned int size);
struct StrField_288eb0 {
    int a, b;
    void FUN_0027af00();
    StrField_288eb0() { FUN_0027af00(); }
};
struct Alloc_288eb0 {
    virtual void v0();
    char pad4[0xc];
    unsigned int cur10;
    unsigned int cur14;
    char *base18;
    char *base1c;
};
} // namespace fn_f25f8e16
namespace pure3d {
class AnimationGroup_288eb0 {
public:
    virtual void v0();
    char pad4[4];
    StrField_288eb0 name;
    int f10;
    unsigned int f14;
    int *f18;
    Alloc_288eb0 *f1c;
    AnimationGroup_288eb0() {
        f10 = 0;
        f14 = 0;
        f18 = 0;
        f1c = 0;
    }
};
}
namespace fn_f25f8e16 {
struct Stream_288eb0 {
    bool FUN_002647e0(void *dst, int a, int b, int c);
};
struct Reader_288eb0 {
    char pad0[0x280];
    int depth;
    Stream_288eb0 *stream;
    bool FUN_002669f0();
    void FUN_00266a30();
    void FUN_00266be0();
};
struct Child_288eb0 {
    void *FUN_0028b0b0(Reader_288eb0 *r, int ctx, Alloc_288eb0 *a);
};
struct Stream_289070 {
    char pad[0xc];
};
class Field_289070 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Measure(int* outA, int* outB, int key, int value);
};
struct Table_289070 {
    Field_289070* FUN_0028b020(int key);
};
struct AnimationMemoryBlock_nv_289070 {
    pure3d::AnimationMemoryBlock* FUN_00288820(unsigned int total, unsigned int extra);
};
struct Reader_289070 {
    char pad000[0x280];
    int pad280;
    Stream_289070* stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};
struct AnimationLoader_289070 {
    char pad00[0x14];
    Table_289070* table;
    char pad18[8];
    int count;
    pure3d::AnimationMemoryBlock* FUN_00289070(Reader_289070* r);
};
struct Frame_289070 {
    unsigned int x2;
    unsigned int n;
    unsigned int key;
    unsigned int value;
    int outA;
    int outB;
    unsigned int skipC;
    unsigned int skipB;
    unsigned int pad38;
    unsigned int total;
};
struct Item {
    char pad[16];
    int value;
};
struct Key {
    unsigned pad[2];
    unsigned lo;
    unsigned hi;
};
} // namespace fn_f25f8e16
void __cdecl operator delete(void*);
namespace fn_f25f8e16 {
extern char gAMBVftable[];
extern char gIRefCountVftable[];
class AnimationMemoryBlock {
  public:
    void** mVftable;
    char pad[0x14];
    void* mField18;
    void* mField1C;
    AnimationMemoryBlock* vfunc_2(unsigned char flag);
};
extern void* g_vftable_2893b0[];
class Item_2893b0 {
  public:
    virtual void Del(int);
    virtual void Release();
};
class Entity_2893b0 {
  public:
    void* vptr;
    void Fin();
};
class Animation_2893b0 : public Entity_2893b0 {
  public:
    char pad[0x24];
    int count;
    Item_2893b0** items;
    Item_2893b0* owner;
    char pad2[4];
    void* m38;
    ~Animation_2893b0();
};
extern void* g_vftable_0042c8e8[];
extern void* g_base_2894d0[];
class Ref_2894d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class AnimationLoader_2894d0 {
  public:
    void* vptr;
    char pad[0x10];
    Ref_2894d0* m14;
    ~AnimationLoader_2894d0();
};
extern "C" double __cdecl FUN_00047970(float x);
extern "C" float __cdecl FUN_000186b0(float *v, float *lo, float *hi);
float __cdecl work(int, int, int, float, int, int, unsigned char, int);
class Obj {
    char pad[0x14];
    float factor;
    unsigned char mode;

  public:
    hulk_freg Run(int a, int b, int c, float value, int d, int e, unsigned char m, int p);
};
} // namespace fn_f25f8e16
void* operator new(size_t);
namespace fn_f25f8e16 {
class ChannelLoader_289e00 {
  public:
    ChannelLoader_289e00() throw();
    virtual void Init();
    char pad[0x48];
};
class SimpleChunkHandler_289e00 {
  public:
    virtual void Other();
    int a;
    void* b;
    int c, d;
    SimpleChunkHandler_289e00() : a(0), b((void*)0x121000), c(0), d(0) {}
};
class AnimationLoader_289e00 : public SimpleChunkHandler_289e00 {
  public:
    AnimationLoader_289e00();
    virtual void Dummy();
    ChannelLoader_289e00* anim;
    int e, f, g;
};
extern "C" char DAT_0042c8e8[];
typedef unsigned char byte_289e60;
struct Ref_289e60 {
    virtual void a();
    virtual void release();
};
struct AnimationLoader {
    virtual void v0();
    virtual void v1();
    virtual AnimationLoader* vfunc_2(byte_289e60);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad18[0x10];
    Ref_289e60* mRef;
};
extern void destroy(AnimationLoader*);


// 0x00288820 FUN_00288820 (97 B): matches/0x00288820.cpp
// sym: ??0AnimationMemoryBlock_288820@fn_f25f8e16@@QAE@II@Z
AnimationMemoryBlock_288820::AnimationMemoryBlock_288820(unsigned int s1, unsigned int s2) {
    sz1 = s1;
    b = 0;
    buf1 = s1 > 0 ? FUN_0008d6d0(s1) : 0;
    sz2 = s2;
    c = 0;
    buf2 = s2 > 0 ? FUN_0008d6d0(s2) : 0;
}


// 0x00288890 FUN_00288890 (38 B): matches/0x00288890.cpp
// sym: ?target@AnimationMemoryBlock_288890@fn_f25f8e16@@QAEXXZ
void AnimationMemoryBlock_288890::target() {
    vf = ((hulk_intptr)DAT_0042c8b4);
    thunk(a);
    thunk(b);
    vf = ((hulk_intptr)DAT_003f6098);
}

} // namespace fn_f25f8e16

// 0x002888c0 FUN_002888c0 (57 B): matches/0x002888c0.cpp
// sym: ?FUN_002888c0@C_2888c0@owners@@QAEHII@Z
hulk_intptr owners::C_2888c0::FUN_002888c0(unsigned n, unsigned x) {
    if (n > 0) {
        unsigned i = (x != 7);
        unsigned t = (a[i] + x) & ~x;
        unsigned r = b[i] + t;
        a[i] = t + n;
        return r;
    }
    return 0;
}

namespace fn_f25f8e16 {

// 0x00288900 FUN_00288900 (35 B): matches/0x00288900.cpp
// sym: ??0AnimationGroup@fn_f25f8e16@@QAE@XZ
AnimationGroup::AnimationGroup() {
    sub.Init();
    a = 0;
    b = 0;
    c = 0;
    d = 0;
}


// 0x00288930 FUN_00288930 (30 B): matches/0x00288930.cpp
// sym: ?vfunc_2@CCollisionAction@fn_f25f8e16@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    FUN_0027af50();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f25f8e16

// 0x00288950 FUN_00288950 (13 B): matches/0x00288950.cpp
// sym: ?FUN_00288950@C_288950@owners@@QAEHH@Z
hulk_intptr owners::C_288950::FUN_00288950(int index) {
    return p[index];
}

namespace fn_f25f8e16 {

// 0x00288960 FUN_00288960 (79 B): matches/0x00288960.cpp
// sym: ?Find@Owner_288960@fn_f25f8e16@@QAEPAVItem_288960@2@HH@Z
Item_288960* Owner_288960::Find(int key, int value) {
    unsigned i = 0;
    if (count > 0) {
        do {
            if (key == items[i]->key && value == items[i]->Get())
                return items[i];
            i = i + 1;
        } while (i < count);
    }
    return 0;
}


// 0x002889b0 FUN_002889b0 (57 B): matches/0x002889b0.cpp
// sym: ??0Animation@fn_f25f8e16@@QAE@XZ
Animation::Animation() : Entity_2889b0() {
    x10 = 0;
    x18 = 0;
    x1c[0] = 0;
    x1c[1] = 0;
    x1c[2] = 0;
    x1c[3] = 0;
    x1c[4] = 0;
    x1c[5] = 0;
    x1c[6] = 0;
    x1c[7] = 0;
    *((hulk_intptr*)this) = (hulk_intptr)&anim_vt;
    _ReadWriteBarrier();
    x14 = 30.0f;
}

} // namespace fn_f25f8e16

// 0x002889f0 pure3d::Animation::vfunc_3 (3 B): matches/0x002889f0.cpp
// sym: ?vfunc_3@Animation@pure3d@@UAE_NXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
bool pure3d::Animation::vfunc_3() {
    return (bool)(0);
}


// 0x00288a00 pure3d::Animation::vfunc_4 (3 B): matches/0x00288a00.cpp
// sym: ?vfunc_4@Animation@pure3d@@UAEPAXXZ
// Same code shape as 0x002a1130 (propagated; names are from that function)
 // namespace pure3d
void* pure3d::Animation::vfunc_4() {
    return (void*)(this);
}


// 0x00288a10 FUN_00288a10 (13 B): matches/0x00288a10.cpp
// sym: ?FUN_00288a10@Target_288a10@owners@@QAEHH@Z
hulk_intptr owners::Target_288a10::FUN_00288a10(int index) {
    return values[index];
}

namespace fn_f25f8e16 {

// 0x00288a20 FUN_00288a20 (164 B): equivalent/0x00288a20.cpp
// sym: ?FUN_00288a20@ItemList_288a20@fn_f25f8e16@@QAEPAUItem_288a20@2@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 2560 inputs, branch coverage 19/20, incomplete)
// FUN_00288a20 @ 0x00288a20
Item_288a20 *ItemList_288a20::FUN_00288a20(int key)
{
    int n = count;
    if (n <= 0)
        return 0;

    if (sorted == 1) {
        int hi = n - 1;
        int lo = 0;
        int mid = hi / 2;
        if (hi > 0) {
            Item_288a20 **arr = items;
            do {
                int v = arr[mid]->key;
                if (v > key) {
                    hi = mid - 1;
                } else if (v < key) {
                    lo = mid + 1;
                } else {
                    return arr[mid];
                }
                mid = (hi - lo) / 2 + lo;
            } while (lo < hi);
        }
        Item_288a20 *it = items[mid];
        if (it->key == key)
            return it;
        return 0;
    }

    Item_288a20 **arr = items;
    for (int i = 0; i < n; i++) {
        if (arr[i]->key == key)
            return arr[i];
    }
    return 0;
}


// 0x00288ad0 FUN_00288ad0 (211 B): equivalent/0x00288ad0.cpp
// sym: ?FUN_00288ad0@Table_288ad0@fn_f25f8e16@@QAEPAUEntry_288ad0@2@II@Z
// STATUS: equivalent (tools/equiv.py level 3: 162 inputs, branch coverage 27/32, incomplete)
// FUN_00288ad0 @ 0x00288ad0
Entry_288ad0 * Table_288ad0::FUN_00288ad0(unsigned int low, unsigned int high) {
 if (count <= 0) return 0;
 if (unsorted) {
  for (int i=0; i<count; ++i) {
   Entry_288ad0 *entry=entries[i];
   if (entry->low==low && entry->high==high) return entries[i];
  }
  return 0;
 }
 int first=0, last=count-1;
 int middle=last/2;
 while(first<last) {
  Entry_288ad0 *entry=entries[middle];
  if (entry->high>high || (entry->high==high && entry->low>low)) last=middle-1;
  else if (entry->high<high || (entry->high==high && entry->low<low)) first=middle+1;
  else return entries[middle];
  middle=first+(last-first)/2;
 }
 Entry_288ad0 *entry=entries[middle];
 if(entry->low==low && entry->high==high) return entry;
 return 0;
}


// 0x00288c40 FUN_00288c40 (195 B): equivalent/0x00288c40.cpp
// sym: ?FUN_00288c40@Table_288c40@fn_f25f8e16@@QAEHII@Z
// STATUS: equivalent (tools/equiv.py level 3: 181 inputs, branch coverage 27/32, incomplete)
// FUN_00288c40 @ 0x00288c40
int Table_288c40::FUN_00288c40(unsigned int low, unsigned int high) {
 if (count <= 0) return -1;
 if (unsorted) {
  for (int i=0; i<count; ++i) {
   Entry_288c40 *entry=entries[i];
   if (entry->low==low && entry->high==high) return i;
  }
  return -1;
 }
 int first=0, last=count-1;
 int middle=last/2;
 Entry_288c40 **items=entries;
 while(first<last) {
  unsigned int a=items[middle]->low;
  unsigned int b=items[middle]->high;
  if(b>high || (b==high && a>low)) last=middle-1;
  else if(b<high || (b==high && a<low)) first=middle+1;
  else return middle;
  middle=first+(last-first)/2;
 }
 Entry_288c40 *entry=entries[middle];
 if(entry->low==low && entry->high==high) return middle;
 return -1;
}


// 0x00288d10 FUN_00288d10 (193 B): equivalent/0x00288d10.cpp
// sym: ?FUN_00288d10@Object@fn_f25f8e16@@QAE_NMIIPAIPAM@Z
// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 17/18, incomplete)
// FUN_00288d10 @ 0x00288d10
bool Object::FUN_00288d10(float time, unsigned key1, unsigned key2, unsigned* index, float* fraction) {
 if (!entries) return false;
 for (unsigned i=0; i<count; ++i) {
  Entry_288d10& entry=entries[i];
  if (entry.key1!=key1 || entry.key2!=key2) continue;
  for (unsigned j=0; j<2; ++j) {
   double elapsed=(double)time-entry.windows[j].start;
   if (elapsed<0.0) elapsed+=(double)period-1.0f;
   if (elapsed<entry.windows[j].length && entry.windows[j].length>0.0f) {
    *index=j;
    *fraction=(float)(elapsed/entries[i].windows[j].length);
    return true;
   }
  }
 }
 return false;
}


// 0x00288de0 FUN_00288de0 (117 B): equivalent/0x00288de0.cpp
// sym: ?FUN_00288de0@Curve_288de0@fn_f25f8e16@@QAEMHMII@Z
// STATUS: equivalent (tools/equiv.py level 3: 235 inputs, branch coverage 12/12)
// FUN_00288de0 @ 0x00288de0
hulk_freg Curve_288de0::FUN_00288de0(int slot, float x, unsigned int key0, unsigned int key1)
{
    Entry_288de0 *e = entries;
    if (e == 0) {
        return 0.0f;
    }
    for (unsigned int i = 0; i < count; i++) {
        if (e->key0 == key0 && e->key1 == key1) {
            float *f = (float *)((char *)entries + (slot + i * 3) * 8);
            hulk_freg v = x * f[3] + f[2];
            if (!(v >= limit)) {
                return v;
            }
            return v - limit;
        }
        e++;
    }
    return 0.0f;
}


// 0x00288e80 FUN_00288e80 (10 B): matches/0x00288e80.cpp
// sym: ?vfunc_8@AnimationFrameController@fn_f25f8e16@@UAEXH@Z
// Same code shape as 0x00284b50 (propagated; names are from that function)
void AnimationFrameController::vfunc_8(int x) {
    field = x;
}


// 0x00288e90 FUN_00288e90 (4 B): matches/0x00288e90.cpp
// sym: ?FUN_00288e90@fn_f25f8e16@@YIHH@Z
// Same code shape as 0x00059a40 (propagated; names are from that function)
int __fastcall FUN_00288e90(hulk_intptr object) {
    return *(int*)(object + 0x18);
}


// 0x00288ea0 FUN_00288ea0 (4 B): matches/0x00288ea0.cpp
// sym: ?Target@Obj_288ea0@fn_f25f8e16@@QAEHXZ
int Obj_288ea0::Target() {
    return mVal;
}

} // namespace fn_f25f8e16

// 0x00288eb0 FUN_00288eb0 (444 B): equivalent/0x00288eb0.cpp
// sym: ?FUN_00288eb0@AnimationLoader@pure3d@@QAEPAXPAXH0@Z
// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 17/18, incomplete)
// FUN_00288eb0 @ 0x00288eb0
void* pure3d::AnimationLoader::FUN_00288eb0(void* __p0, int ctx, void* __p2) { Reader_288eb0 * r = (Reader_288eb0 *)__p0; Alloc_288eb0 * alloc = (Alloc_288eb0 *)__p2;

    struct Frame {
        char pad[3];
        unsigned char len;
        int v;
        pure3d::AnimationLoader *self; // the original spills `this` into the word after the value slot
        char name[0x100];
    } fr;

    fr.self = this;
    r->stream->FUN_002647e0(&fr.v, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.len, 1, 1, 1);
    unsigned int n = fr.len;
    r->stream->FUN_002647e0(fr.name, n, 1, 1);
    fr.name[n] = 0;

    void *mem;
    if (alloc == 0) {
        mem = FUN_0008d690((int)sizeof(pure3d::AnimationGroup_288eb0));
    } else {
        unsigned int off = (alloc->cur10 + 7) & 0xfffffff8;
        mem = alloc->base18 + off;
        alloc->cur10 = off + 0x20;
    }
    pure3d::AnimationGroup_288eb0 *obj = 0;
    if (mem)
        obj = new (mem) pure3d::AnimationGroup_288eb0();
    ((owners::Target_27b040 *)&(obj->name))->FUN_0027b040((hulk_uintptr)(fr.name));
    r->stream->FUN_002647e0(&fr.v, 1, 4, 1);
    obj->f10 = fr.v;
    r->stream->FUN_002647e0(&fr.v, 1, 4, 1);
    obj->f14 = fr.v;
    obj->f1c = alloc;
    if (alloc != 0)
        alloc->v0();
    if (obj->f14 != 0) {
        if (alloc == 0) {
            obj->f18 = (int *)FUN_0008d6d0(obj->f14 * 4);
        } else {
            unsigned int bytes = obj->f14 * 4;
            char *p = 0;
            if (bytes > 0) {
                unsigned int off = (alloc->cur14 + 3) & 0xfffffffc;
                p = alloc->base1c + off;
                alloc->cur14 = off + bytes;
            }
            obj->f18 = (int *)p;
        }
        memset(obj->f18, 0, obj->f14 * 4);
        unsigned int i = 0;
        if (r->FUN_002669f0()) {
            while (i < obj->f14) {
                r->FUN_00266a30();
                obj->f18[i] = (hulk_intptr)(*(Child_288eb0 * *)&fr.self->f_14)->FUN_0028b0b0(r, ctx, obj->f1c);
                r->FUN_00266be0();
                i++;
                if (!r->FUN_002669f0())
                    break;
            }
        }
    }
    return (void*)(obj);
}

namespace fn_f25f8e16 {

// 0x00289070 FUN_00289070 (456 B): equivalent/0x00289070.cpp
// sym: ?FUN_00289070@AnimationLoader_289070@fn_f25f8e16@@QAEPAVAnimationMemoryBlock@pure3d@@PAUReader_289070@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 17174 inputs, branch coverage 20/20)
// FUN_00289070 @ 0x00289070
pure3d::AnimationMemoryBlock* AnimationLoader_289070::FUN_00289070(Reader_289070* r)
{
    Frame_289070 f;
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.total), (hulk_intptr)1, 4, (hulk_intptr)1));
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.total), (hulk_intptr)1, 4, (hulk_intptr)1));
    if (f.total == 0)
        return 0;
    f.total = f.total << 5;
    unsigned int extra = 0;
    while (r->FUN_002669f0() != 0) {
        int id = r->FUN_00266a30();
        if (id == 0x121006) {
            r->FUN_00266be0();
            return 0;
        }
        if (id == 0x121007) {
            ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.skipB), (hulk_intptr)1, 4, (hulk_intptr)1));
            ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.key), (hulk_intptr)1, 4, (hulk_intptr)1));
            ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.n), (hulk_intptr)1, 4, (hulk_intptr)1));
            extra += f.n * 4;
            for (unsigned int i = f.n; i != 0; i--) {
                Field_289070* fld = table->FUN_0028b020(f.key);
                if (fld != 0) {
                    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.value), (hulk_intptr)1, 2, (hulk_intptr)1));
                    fld->Measure(&f.outA, &f.outB, f.key, f.value);
                    f.total += f.outA;
                    extra += f.outB;
                }
            }
        } else if (id == 0x121400) {
            ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.skipC), (hulk_intptr)1, 4, (hulk_intptr)1));
            ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.x2), (hulk_intptr)1, 4, (hulk_intptr)1));
            this->count = f.x2;
            extra += f.x2 * 24;
        }
        r->FUN_00266be0();
    }
    pure3d::AnimationMemoryBlock* res = (pure3d::AnimationMemoryBlock*)FUN_0008d690(0x20);
    if (res == 0)
        return 0;
    return ((AnimationMemoryBlock_nv_289070*)(((pure3d::AnimationMemoryBlock*)(res))))->FUN_00288820(f.total, extra);
}


// 0x00289240 FUN_00289240 (36 B): matches/0x00289240.cpp
// sym: ?compare@fn_f25f8e16@@YAHPCRAUItem@1@0@Z
int compare(Item* volatile* a, Item* volatile* b) {
    Item* left = *a;
    Item* right = *b;
    int bv = right->value;
    int av = left->value;
    if (av < bv)
        return -1;
    return av > bv;
}


// 0x00289270 FUN_00289270 (61 B): matches/0x00289270.cpp
// sym: ?FUN_00289270@fn_f25f8e16@@YAHPAPAUKey@1@0@Z
int FUN_00289270(Key** a, Key** b) {
    Key* x = *a;
    Key* y = *b;
    unsigned blo = y->lo;
    unsigned bhi = y->hi;
    unsigned alo = x->lo;
    unsigned ahi = x->hi;
    if (ahi <= bhi) {
        if (ahi < bhi || alo < blo)
            return -1;
    }
    if (ahi < bhi || (ahi <= bhi && alo <= blo))
        return 0;
    return 1;
}


// 0x002892f0 pure3d::AnimationMemoryBlock::vfunc_2 (59 B): matches/0x002892f0.cpp
// sym: ?vfunc_2@AnimationMemoryBlock@fn_f25f8e16@@QAEPAV12@E@Z
AnimationMemoryBlock* AnimationMemoryBlock::vfunc_2(unsigned char flag) {
    void* p18 = mField18;
    mVftable = (void**)&gAMBVftable;
    operator delete[](p18);
    operator delete[](mField1C);
    mVftable = (void**)&gIRefCountVftable;
    if (flag & 1) {
        operator delete((void*)this);
    }
    return this;
}

} // namespace fn_f25f8e16

// 0x00289330 pure3d::AnimationGroup::vfunc_1 (121 B): matches/0x00289330.cpp [wrapped: conflict: AnimationGroup]
// sym: ?vfunc_1@AnimationGroup@fn_00289330@@UAEXXZ
namespace fn_00289330 {
class Item_289330 {
  public:
    virtual void v0(int);
    virtual void v1();
};
class Sub_289330 {
  public:
    void run();
};
class AnimationGroup {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad[4];
    Sub_289330 sub;
    char pad2[8];
    unsigned int count;
    Item_289330** items;
    Item_289330* active;
};
void cleanup(void*);
void AnimationGroup::vfunc_1() {
    if (!active) {
        for (unsigned int i = 0; i < count; ++i) {
            Item_289330* it = items[i];
            if (it)
                it->v0(1);
        }
        cleanup(items);
        return;
    }
    sub.run();
    for (unsigned int j = 0; j < count; ++j)
        items[j]->v1();
    if (active) {
        active->v1();
        active = 0;
    }
}
} // namespace fn_00289330

namespace fn_f25f8e16 {

// 0x002893b0 FUN_002893b0 (154 B): matches/0x002893b0.cpp
// sym: ??1Animation_2893b0@fn_f25f8e16@@QAE@XZ
Animation_2893b0::~Animation_2893b0() {
    vptr = g_vftable_2893b0;
    if (owner == 0) {
        for (int i = 0; i < count; ++i) {
            Item_2893b0* p = items[i];
            if (p)
                p->Del(1);
        }
        operator delete[](m38);
    } else {
        for (int i = 0; i < count; ++i)
            items[i]->Release();
        if (m38)
            owner->Release();
    }
    operator delete[](items);
    if (owner) {
        owner->Release();
        owner = 0;
    }
    Fin();
}


// 0x002894d0 FUN_002894d0 (36 B): matches/0x002894d0.cpp
// sym: ??1AnimationLoader_2894d0@fn_f25f8e16@@QAE@XZ
AnimationLoader_2894d0::~AnimationLoader_2894d0() {
    vptr = g_vftable_0042c8e8;
    _ReadWriteBarrier();
    if (m14) {
        m14->Release();
        m14 = 0;
    }
    vptr = g_base_2894d0;
}

} // namespace fn_f25f8e16

// 0x00289500 pure3d::AnimationLoader::vfunc_5 (1246 B): equivalent/0x00289500.cpp [wrapped: conflict: pure3d::Animation; pure3d::AnimationLoader]
// sym: ?vfunc_5@AnimationLoader@pure3d@fn_00289500@@UAEXPAPAVAnimation@23@PAUPair_289500@3@PAUReader@3@H@Z
namespace fn_00289500 {
// STATUS: equivalent (tools/equiv.py level 3: 158 inputs, branch coverage 49/54, incomplete)
// pure3d::AnimationLoader::vfunc_5 @ 0x00289500
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *__cdecl memset(void *, int, unsigned int);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void __cdecl qsort(void *base, unsigned int count, unsigned int size,
                              int (__cdecl *cmp)(const void *, const void *));
#endif

void *thunk_FUN_0008d690(unsigned int size);
extern "C" void *FUN_0008d6d0(unsigned int size);
extern "C" int FUN_00266da0(int token);
int __cdecl FUN_00289240(const void *a, const void *b);
int __cdecl FUN_00289270(const void *a, const void *b);


struct Pair_289500 {
    unsigned int lo;
    unsigned int hi;
};
extern "C" Pair_289500 FUN_002672f0(const char *name, int a, int b);

struct Name_289500 {
    unsigned int lo, hi;
    void FUN_0027b040(const char *s);
};

class __declspec(novtable) Entity_289500 {
public:
    virtual void v0();
    char pad04[4];
    Name_289500 name;
    void FUN_0027b070();
    Entity_289500() { FUN_0027b070(); }
};

struct Alloc_289500 {
    virtual void v0();
    char pad4[0xc];
    unsigned int cur10;
    unsigned int cur14;
    char *base18;
    char *base1c;
};

struct Stream {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Reader {
    char pad0[0x284];
    Stream *stream;
    bool FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
};

namespace pure3d {
class Animation : public Entity_289500 {
public:
    int f10;
    float f14;
    char f18;
    char pad19[3];
    int f1c;
    int f20;
    int f24;
    int f28;
    int *f2c;
    Alloc_289500 *f30;
    int f34;
    char *f38;
    virtual void v1();
    Animation()
        : f10(0), f14(30.0f), f18(0), f1c(0), f20(0), f24(0), f28(0), f2c(0), f30(0), f34(0), f38(0)
    {
    }
};
}

class Table_289500 {
public:
    float FUN_dummy();
};

namespace pure3d {
class AnimationLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(Animation **out, Pair_289500 *outId, Reader *r, int ctx);
    char pad04[0x14];
    int f18;
    int f1c;
    int f20;
    Alloc_289500 *FUN_00289070(Reader *r);
    int FUN_00288eb0(Reader *r, int ctx, Alloc_289500 *alloc);
};

void AnimationLoader::vfunc_5(Animation **out, Pair_289500 *outId, Reader *r, int ctx)
{
    struct Frame {
        char pad10[3];
        unsigned char len;
        int v;
        AnimationLoader *self;
        int row3;
        int rowOff;
        int token;
        int unused;
        float fa;
        unsigned int count;
        float fb;
        int b;
        int a;
        int dummy;
        int skip;
        char name[0x100];
        char name2[0xf0];
        char pad[0x40];
    } fr;
    fr.self = this;
    fr.token = -1;
    if (f1c != -1)
        fr.token = FUN_00266da0(f1c);

    int &unused = fr.unused;
    unsigned char &len = fr.len;
    int &v = fr.v;
    char *name = fr.name;
    r->stream->FUN_002647e0(&unused, 1, 4, 1);
    r->stream->FUN_002647e0(&len, 1, 1, 1);
    unsigned int n = len;
    r->stream->FUN_002647e0(name, n, 1, 1);
    name[n] = 0;

    void *mem = thunk_FUN_0008d690(0x40);
    Animation *anim = 0;
    if (mem)
        anim = new (mem) Animation();
    anim->name.FUN_0027b040(name);
    r->stream->FUN_002647e0(&v, 1, 4, 1);
    anim->f1c = v;
    r->stream->FUN_002647e0(&v, 1, 4, 1);
    anim->f10 = v;
    r->stream->FUN_002647e0(&v, 1, 4, 1);
    anim->f14 = *(float *)&v;
    r->stream->FUN_002647e0(&v, 1, 4, 1);
    anim->f18 = (v == 1);
    anim->f24 = f18;

    if (r->FUN_002669f0()) {
        int &row3 = fr.row3;
        int &rowOff = fr.rowOff;
        row3 = 0;
        rowOff = 0;
        do {
            char *id = (char *)r->FUN_00266a30();
            if (id == ((char*)0x00121401)) {
                if (anim->f38 == 0) {
                    if (anim->f30 != 0) {
                        anim->f30->v0();
                        Alloc_289500 *pool = anim->f30;
                        unsigned int bytes = anim->f34 * 24;
                        if (bytes > 0) {
                            unsigned int off = (pool->cur14 + 3) & 0xfffffffc;
                            char *p = pool->base1c + off;
                            pool->cur14 = off + bytes;
                            anim->f38 = p;
                        } else {
                            anim->f38 = 0;
                        }
                    } else {
                        anim->f38 = (char *)FUN_0008d6d0(anim->f34 * 24);
                    }
                }
                char *name2 = fr.name2;
                unsigned char &len2 = fr.len;
                int &skip = fr.skip;
                unsigned int &count = (unsigned int &)fr.v;
                float &fa = fr.fa;
                float &fb = fr.fb;
                r->stream->FUN_002647e0(&len2, 1, 1, 1);
                unsigned int n2 = len2;
                r->stream->FUN_002647e0(name2, n2, 1, 1);
                name2[n2] = 0;
                r->stream->FUN_002647e0(&skip, 1, 4, 1);
                Pair_289500 key = FUN_002672f0(name2, 0, 0);
                *(Pair_289500 *)(anim->f38 + rowOff) = key;
                r->stream->FUN_002647e0(&count, 1, 4, 1);
                unsigned int k = 0;
                int off = rowOff;
                if (count > 0) {
                    k = count;
                    fr.count = count;
                    do {
                        r->stream->FUN_002647e0(&fa, 1, 4, 1);
                        *(float *)(anim->f38 + off + 8) = fa + 1.0f;
                        r->stream->FUN_002647e0(&fb, 1, 4, 1);
                        *(float *)(anim->f38 + off + 12) = fb + 1.0f;
                        off += 8;
                        k--;
                    } while (k != 0);
                }
                if (count < 2) {
                    int start = row3 * 8 + count * 8;
                    for (int j = 2 - count; j != 0; j--) {
                        *(int *)(anim->f38 + start + 8) = 0;
                        *(int *)(anim->f38 + start + 12) = 0;
                        start += 8;
                    }
                }
                rowOff += 0x18;
                row3 += 3;
            } else if (id == ((char*)0x00121402)) {
                r->stream->FUN_002647e0(&fr.dummy, 1, 4, 1);
                r->stream->FUN_002647e0(&fr.unused, 1, 4, 1);
                anim->f20 = fr.unused;
            } else if (id == ((char*)0x00121002)) {
                r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
                r->stream->FUN_002647e0(&fr.b, 1, 4, 1);
                anim->f28 = fr.b;
                if (fr.b > 0) {
                    anim->f2c = (int *)FUN_0008d6d0(fr.b * 4);
                    memset(anim->f2c, 0, anim->f28 * 4);
                    int i = 0;
                    while (r->FUN_002669f0() && i < anim->f28) {
                        r->FUN_00266a30();
                        anim->f2c[i] = fr.self->FUN_00288eb0(r, ctx, anim->f30);
                        r->FUN_00266be0();
                        i++;
                    }
                }
            } else if (id == ((char*)0x00121006)) {
                if (anim->f28 == 0) {
                    anim->f30 = fr.self->FUN_00289070(r);
                    if (anim->f30)
                        anim->f30->v0();
                    anim->f34 = fr.self->f20;
                }
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }

    if (anim->f28 > 0) {
        if (anim->f24 == 0)
            qsort(anim->f2c, anim->f28, 4, FUN_00289270);
        else if (anim->f24 == 1)
            qsort(anim->f2c, anim->f28, 4, FUN_00289240);
    }
    if (fr.self->f1c != -1)
        FUN_00266da0(fr.token);
    *out = anim;
    *outId = FUN_002672f0(name, 0, 0);
}
}
} // namespace fn_00289500

namespace fn_f25f8e16 {

// 0x002899e0 FUN_002899e0 (890 B): equivalent/0x002899e0.cpp
// sym: ?FUN_002899e0@fn_f25f8e16@@YAMPAMPADMMMMDH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20031 inputs, branch coverage 56/56)
// FUN_002899e0 @ 0x002899e0
hulk_freg FUN_002899e0(float *p, char *st, float v, float step, float lo, float hi, char flag, int mode)
{
    if (step == 0.0f)
        return v;
    if (mode == 1)
        return v;
    if (*p == 0.0f)
        return v;
    float range = hi - lo;
    v = FUN_000186b0(&v, &lo, &hi);
    float t = *p - step;
    *p = t;
    if (range <= 1e-05f)
        return v;

    switch (mode) {
    case 2: {
        *st = 1;
        if (flag == 0 && *p <= 0.0f) {
            *p = 0;
            return hi;
        }
        hulk_freg vp = (double)v + step;
        volatile float vr = (float)vp; // rounded frame copy; the unrounded vp is what gets returned
        if (!(vp > hi))
            return vp;
        return fmod(vr - hi, range) + lo;
    }
    case 3: {
        *st = 0;
        if (flag == 0 && *p <= 0.0f) {
            *p = 0;
            return lo;
        }
        hulk_freg vp = (double)v - step;
        volatile float vr = (float)vp; // rounded frame copy; the unrounded vp is what gets returned
        if (!(vp < lo))
            return vp;
        return fmod(vr - lo, range) + hi;
    }
    case 4:
        if (flag == 0 && t <= 0.0f) {
            *p = 0;
            return lo;
        }
        break;
    case 5:
        if (flag == 0 && t <= 0.0f) {
            *p = 0;
            return hi;
        }
        break;
    default: {
        *st = 1;
        hulk_freg vp = (double)v + step;
        volatile float vr = (float)vp; // rounded frame copy; the unrounded vp is what gets returned
        if (!(vp > hi))
            return vp;
        if (flag != 1) {
            *p = 0;
            return hi;
        }
        return fmod(vr - lo, range) + lo;
    }
    }

    if (*st == 1) {
        hulk_freg vp = (double)v + step;
        if (!(vp > hi))
            return vp;
        volatile float step2 = range + range; // the doubled range is a rounded frame slot in the original
        volatile float tt = (float)((vp - hi) / step2);
        double fr = (double)tt - FUN_00047970(tt);
        if (!(fr > 0.5f)) {
            *st = 0;
            return hi - fr * step2;
        }
        return (fr - 0.5f) * step2 + lo;
    }
    hulk_freg vp = (double)v - step;
    if (!(vp < lo))
        return vp;
    volatile float step2 = range + range;
    volatile float tt = (float)((vp - lo) / step2);
    if (tt < 0)
        tt = -tt;
    double fr = (double)tt - FUN_00047970(tt);
    if (fr > 0.5f)
        return hi - (fr - 0.5f) * step2;
    *st = 1;
    return fr * step2 + lo;
}

} // namespace fn_f25f8e16

// 0x00289d70 FUN_00289d70 (23 B): matches/0x00289d70.cpp [wrapped: conflict: AnimationGroup]
// sym: ?Target@AnimationGroup_289d70@fn_00289d70@@QAEXXZ
namespace fn_00289d70 {
extern "C" char DAT_0042c8c4[];
class AnimationGroup {
  public:
    int x;
    void vfunc_1();
};
struct Sub_289d70 {
    void Helper();
};
class AnimationGroup_289d70 : public AnimationGroup {
  public:
    char pad[4];
    Sub_289d70 sub;
    void Target();
};
void AnimationGroup_289d70::Target() {
    *(void**)this = (void*)((hulk_intptr)DAT_0042c8c4);
    AnimationGroup::vfunc_1();
    sub.Helper();
}
} // namespace fn_00289d70


// 0x00289d90 pure3d::Animation::vfunc_2 (30 B): matches/0x00289d90.cpp
// sym: ??_GAnimation@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::Animation::~Animation() {}

namespace fn_f25f8e16 {

// 0x00289db0 FUN_00289db0 (74 B): matches/0x00289db0.cpp
// sym: ?Run@Obj@fn_f25f8e16@@QAEMHHHMHHEH@Z
hulk_freg Obj::Run(int a, int b, int c, float value, int d, int e, unsigned char m, int p) {
    return work(a, b, c, value * factor * 0.001f, d, e, p == 0 ? mode : m, p);
}


// 0x00289e00 FUN_00289e00 (95 B): matches/0x00289e00.cpp
// sym: ??0AnimationLoader_289e00@fn_f25f8e16@@QAE@XZ
AnimationLoader_289e00::AnimationLoader_289e00() : anim(0), e(0), f(-1), g(0) {
    anim = new ChannelLoader_289e00;
    anim->Init();
}


// 0x00289e60 pure3d::AnimationLoader::vfunc_2 (56 B): matches/0x00289e60.cpp
// sym: ?vfunc_2@AnimationLoader@fn_f25f8e16@@UAEPAU12@E@Z
AnimationLoader* AnimationLoader::vfunc_2(byte_289e60 flags) {
    *(void**)this = (void*)((hulk_intptr)DAT_0042c8e8);
    _ReadWriteBarrier();
    if (mRef) {
        mRef->release();
        mRef = 0;
    }
    *(void**)this = (void*)((hulk_intptr)DAT_003f6098);
    if (flags & 1)
        destroy(this);
    return this;
}

} // namespace fn_f25f8e16

// 0x00289ea0 pure3d::AnimationGroup::vfunc_0 (44 B): matches/0x00289ea0.cpp [wrapped: conflict: AnimationGroup]
// sym: ?vfunc_0@AnimationGroup@fn_00289ea0@@UAEPAV12@E@Z
namespace fn_00289ea0 {
extern "C" char DAT_0042c8c4[];
struct Sub_289ea0 {
    void f();
};
class AnimationGroup {
  public:
    virtual AnimationGroup* vfunc_0(unsigned char);
    virtual void vfunc_1();
    char pad[4];
};
extern void __cdecl thunk_FUN_00267090(AnimationGroup*);
AnimationGroup* AnimationGroup::vfunc_0(unsigned char flags) {
    *(void**)this = (void*)((hulk_intptr)DAT_0042c8c4);
    AnimationGroup::vfunc_1();
    ((Sub_289ea0*)((char*)this + 8))->f();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00289ea0

