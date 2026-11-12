// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x003338a0..0x00334090 (kind game, layer platform/xbox, confidence high), dominant class movie::PlayerBink
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/platform/xbox/movie.h"
#include "gen/core.h"
#include "gen/movie.h"
#define TREE_TU_BEGIN namespace fn_f1126c37 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f1126c37 {} using namespace fn_f1126c37;
namespace fn_f1126c37 { extern "C" char DAT_003f6098[], DAT_0043406c[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "platform/xbox/movie.h"

// ---- declarations shared by the functions below
namespace fn_f1126c37 {
extern "C" void __cdecl FUN_00266eb0(void*, void*, int);
extern "C" void __cdecl helper(hulk_intptr);
struct Obj_333970 {
    char pad0[0x1c];
    int mArg;
    char pad20[8];
    uint mCount;
    uint mArray;
};
void __stdcall Work(int, int, void*, int);
extern "C" void __stdcall Func_00367610(void*, void*, unsigned int);
class PlayerBink {
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
    virtual void vfunc_10(float param);
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();

  private:
    char pad0[0x1c - 4];
    void* mPtr1c;
    float mParamStore;
    char pad1[4];
    unsigned int mCount;
    void* mArray2c[1];
};
struct Thing_333aa0 {
    char pad[0xc];
    unsigned int value;
};
struct SourceEntry_333ab0 {
    uint key;
    uint count;
    uint* values;
};
struct Source_333ab0 {
    uint count;
    SourceEntry_333ab0* entries;
};
struct DestEntry_333ab0 {
    uint count;
    uint values[16];
};
struct Object {
    char padding[0x28];
    uint count;
    uint keys[6];
    DestEntry_333ab0 entries[1];
    void FUN_00333ab0(Source_333ab0* source);
};
extern "C" void __cdecl FUN_003338a0();
extern "C" void __cdecl FUN_003338c0();
extern "C" void __stdcall FUN_0033eb70(void*, void*);
extern "C" void __cdecl FUN_003351a0(int);
extern "C" void FUN_00334940();
class Item_333ba0 {
  public:
    virtual void Add();
    virtual void Release();
};
class Holder_333ba0 {
  public:
    Item_333ba0* mItem;
    Item_333ba0* Set(Item_333ba0* item);
};
class Item_333bf0 {
  public:
    virtual void Add();
    virtual void Release();
};
class Holder_333bf0 {
  public:
    Item_333bf0* mItem;
    Item_333bf0* Set(Item_333bf0* item);
};
namespace pure3d {
class NonCopyable_333c30 : public ::core::IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_333c30* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable_333c30*);
class Ref_333c50 {
  public:
    virtual void Release();
    virtual void AddRef();
};
void __stdcall ReleaseHandle(void*);
extern void __stdcall FUN_00366b40(int, int);
struct Data_333de0 { char pad[8]; int count; int index; };
struct Reader { virtual void f0(); virtual void f1(); virtual void f2(); virtual void FUN_slot3(); virtual unsigned int FUN_slot4(int* values); virtual void FUN_slot5(); };
struct Listener_333de0 { virtual void f0(); virtual void f1(); virtual void f2(); virtual void FUN_slot3(void*); };
struct Obj_333de0 {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void FUN_slot7();
 int field4; int field8; int fieldc; Listener_333de0* listener; Reader* reader; int state; Data_333de0* data; int field20; unsigned char flag24; unsigned char busy;
 void FUN_00333de0();
};
extern int __stdcall FUN_00366940(Data_333de0*);
extern int __stdcall FUN_00367bc0(Data_333de0*);
extern int __stdcall FUN_00365f30(Data_333de0*,int,int,int,int,int,int,int,int,int,int);
extern void __stdcall FUN_003681d0(Data_333de0*);
class Obj_333ef0 {
  public:
    void Fn();
};
extern void* v1_333f10[];
extern void* v2_333f10[];
extern void* v3_333f10[];
extern void* v4_333f10[];
class PlayerBink_333f10;
void FUN_002705f0() throw();
class PlayerBink_333f10 {
  public:
    void* p0;
    void* p1;
    int id;
    int m0c;
    int a, b, c, d;
    float f;
    char x, y;
    PlayerBink_333f10() throw();
};
class IB_333f80 {
  public:
    void helper();
};
class PlayerBink_333f80 : public movie::Player2, public IB_333f80 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
extern "C" void* __cdecl FUN_00266e00(int, hulk_intptr);
struct Obj_334010 {
    void* FUN_00333f10();
};
typedef unsigned char u8_334040;
class PlayerBink_334040 {
  public:
    void cleanup();
    virtual void f0();
    virtual void f1();
    virtual PlayerBink_334040* f2(u8_334040);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
};


// 0x003338a0 FUN_003338a0 (25 B): matches/0x003338a0.cpp
// sym: ?FUN_003338a0@fn_f1126c37@@YGXPAX@Z
void __stdcall FUN_003338a0(void* p) {
    FUN_00266eb0((*(void**)&DAT_00555ba0), p, 0x10);
}


// 0x003338c0 FUN_003338c0 (14 B): matches/0x003338c0.cpp
// sym: ?FUN_003338c0@fn_f1126c37@@YGXH@Z
void __stdcall FUN_003338c0(int x) {
    helper(x);
}

} // namespace fn_f1126c37

// 0x003338e0 movie::PlayerBink::vfunc_6 (135 B): equivalent/0x003338e0.cpp [wrapped: conflict: movie::PlayerBink]
// sym: ?vfunc_6@PlayerBink@movie@fn_003338e0@@UAEXIHII@Z @1371ba213891 @wcc948612ee32
namespace fn_003338e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// movie::PlayerBink::vfunc_6 @ 0x003338e0
namespace movie {

struct Param {
    int count;
    int* values;
};

class PlayerBink {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(unsigned int a1, Param* param, unsigned int a3, unsigned int a4);
    virtual void vfunc_6(unsigned int a1, int id, unsigned int a3, unsigned int a4);
};

void PlayerBink::vfunc_6(unsigned int a1, int id, unsigned int a3, unsigned int a4)
{
    struct Frame {
        int zero;
        int one;
        Param param;
        int values[2];
        int* zeroPtr;
    } f;

    if (id != -1) {
        f.values[0] = id;
        f.param.values = f.values;
        f.zeroPtr = &f.zero;
        f.param.count = 1;
        f.one = 1;
        f.zero = 0;
        f.values[1] = 2;
        vfunc_5(a1, &f.param, a3, a4);
    } else {
        f.param.count = 0;
        f.param.values = 0;
        vfunc_5(a1, &f.param, a3, a4);
    }
}

}
} // namespace fn_003338e0

namespace fn_f1126c37 {

// 0x00333970 FUN_00333970 (57 B): matches/0x00333970.cpp
// sym: ?FUN_00333970@fn_f1126c37@@YIXPAUObj_333970@1@@Z
void __fastcall FUN_00333970(Obj_333970* self) {
    uint i = 0;
    if (self->mCount <= 0)
        return;
    uint* p = &self->mArray;
    char* q = (char*)self + 0x48;
    do {
        Work(self->mArg, *p, q, *(int*)(q - 4));
        ++i;
        ++p;
        q += 0x44;
    } while (i < self->mCount);
}


// 0x003339b0 movie::PlayerBink::vfunc_10 (84 B): matches/0x003339b0.cpp
// sym: ?vfunc_10@PlayerBink@fn_f1126c37@@UAEXM@Z
void PlayerBink::vfunc_10(float param) {
    mParamStore = param;
    if (mPtr1c) {
        unsigned int converted = (unsigned int)(param * param * 65536.0f);
        for (unsigned int i = 0; i < mCount; i++) {
            Func_00367610(mPtr1c, mArray2c[i], converted);
        }
    }
}

} // namespace fn_f1126c37

// 0x00333a10 movie::PlayerBink::vfunc_11 (4 B): matches/0x00333a10.cpp
// sym: ?vfunc_11@PlayerBink@movie@@UAEMXZ
// Same code shape as 0x00069080 (propagated; names are from that function)
hulk_freg movie::PlayerBink::vfunc_11() {
    return this->f_20;
}

namespace fn_f1126c37 {

// 0x00333a20 movie::PlayerBink::vfunc_12 (4 B): matches/0x00333a20.cpp
// sym: ?FUN_00333a20@fn_f1126c37@@YIHH@Z
// Same code shape as 0x00059a40 (propagated; names are from that function)
int __fastcall FUN_00333a20(hulk_intptr object) {
    return *(int*)(object + 0x18);
}

} // namespace fn_f1126c37

// 0x00333a30 movie::PlayerBink::vfunc_13 (34 B): matches/0x00333a30.cpp
// sym: ?vfunc_13@PlayerBink@movie@@UAE_NPAX@Z
bool movie::PlayerBink::vfunc_13(void* __p0) { unsigned int * out = (unsigned int *)__p0;

    if ((*(void * *)&this->f_1c)) {
        out[1] = *(unsigned int*)(*(void * *)&this->f_1c);
        out[0] = *((unsigned int*)(*(void * *)&this->f_1c) + 1);
        return true;
    }
    return false;
}


// 0x00333a60 movie::PlayerBink::vfunc_14 (52 B): matches/0x00333a60.cpp [wrapped: conflict: movie::PlayerBink]
// sym: ?vfunc_14@PlayerBink@movie@fn_00333a60@@UAEMXZ
namespace fn_00333a60 {
struct BinkInfo {
    char pad[0x14];
    unsigned width;
    unsigned height;
};
namespace movie {
class PlayerBink {
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
    virtual hulk_freg vfunc_14();
    virtual void v15();
    char pad[0x18];
    BinkInfo* info;
};
hulk_freg PlayerBink::vfunc_14() {
    if (info)
        return (hulk_freg)info->width / (hulk_freg)info->height;     // x87: both fild, unrounded
    return 0.0f;
}
} // namespace movie
} // namespace fn_00333a60


// 0x00333aa0 movie::PlayerBink::vfunc_15 (14 B): matches/0x00333aa0.cpp
// sym: ?vfunc_15@PlayerBink@movie@@UAEIXZ
unsigned int movie::PlayerBink::vfunc_15() {
    if ((*(Thing_333aa0 * *)&this->f_1c))
        return (*(Thing_333aa0 * *)&this->f_1c)->value;
    return 0;
}

namespace fn_f1126c37 {

// 0x00333ab0 FUN_00333ab0 (143 B): matches/0x00333ab0.cpp
// sym: ?FUN_00333ab0@Object@fn_f1126c37@@QAEXPAUSource_333ab0@2@@Z
void Object::FUN_00333ab0(Source_333ab0* source) {
    count = source->count;
    for (uint i = 0; i < count; ++i) {
        SourceEntry_333ab0* entry = &source->entries[i];
        keys[i] = entry->key;
        uint n = entry->count;
        entries[i].count = n;
        for (uint j = 0; j < n; ++j)
            entries[i].values[j] = entry->values[j];
    }
}


// 0x00333b50 FUN_00333b50 (41 B): matches/0x00333b50.cpp
// sym: _FUN_00333b50
extern "C" void __cdecl FUN_00333b50(int value) {
    FUN_0033eb70((void*)((hulk_intptr)(void (__cdecl*)())&FUN_003338a0), (void*)((hulk_intptr)(void (__cdecl*)())&FUN_003338c0));
    DAT_00555ba0 = value;
    FUN_003351a0(value);
    (*(unsigned char*)&DAT_00555b9c) = 1;
}


// 0x00333b80 FUN_00333b80 (13 B): matches/0x00333b80.cpp
// sym: _FUN_00333b80
extern "C" void FUN_00333b80() {
    FUN_00334940();
    (*(volatile unsigned char*)&DAT_00555b9c) = 0;
}


// 0x00333ba0 FUN_00333ba0 (42 B): matches/0x00333ba0.cpp
// sym: ?Set@Holder_333ba0@fn_f1126c37@@QAEPAVItem_333ba0@2@PAV32@@Z
// Same code shape as 0x001b7620 (propagated; names are from that function)
Item_333ba0* Holder_333ba0::Set(Item_333ba0* item) {
    Item_333ba0* old = mItem;
    if (old != item) {
        mItem = item;
        if (item)
            item->Add();
        if (old)
            old->Release();
    }
    return mItem;
}


// 0x00333bf0 FUN_00333bf0 (42 B): matches/0x00333bf0.cpp
// sym: ?Set@Holder_333bf0@fn_f1126c37@@QAEPAVItem_333bf0@2@PAV32@@Z
// Same code shape as 0x001b7620 (propagated; names are from that function)
Item_333bf0* Holder_333bf0::Set(Item_333bf0* item) {
    Item_333bf0* old = mItem;
    if (old != item) {
        mItem = item;
        if (item)
            item->Add();
        if (old)
            old->Release();
    }
    return mItem;
}


// 0x00333c30 movie::Player2::vfunc_2 (31 B): matches/0x00333c30.cpp
// sym: ?f2@NonCopyable_333c30@pure3d@fn_f1126c37@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_333c30* pure3d::NonCopyable_333c30::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f1126c37

// 0x00333c50 movie::PlayerBink::vfunc_3 (75 B): matches/0x00333c50.cpp
// sym: ?vfunc_3@PlayerBink@movie@@UAEXPAX0@Z
void movie::PlayerBink::vfunc_3(void* __p0, void* __p1) { Ref_333c50 * x = (Ref_333c50 *)__p0; Ref_333c50 * y = (Ref_333c50 *)__p1;

    if ((*(Ref_333c50 * *)&this->f_10) != x) {
        Ref_333c50* old = (*(Ref_333c50 * *)&this->f_10);
        (*(Ref_333c50 * *)&this->f_10) = x;
        if (x)
            x->Release();
        if (old)
            old->AddRef();
    }
    if ((*(Ref_333c50 * *)&this->f_14) != y) {
        Ref_333c50* old = (*(Ref_333c50 * *)&this->f_14);
        (*(Ref_333c50 * *)&this->f_14) = y;
        if (y)
            y->Release();
        if (old)
            old->AddRef();
    }
}


// 0x00333ca0 movie::PlayerBink::vfunc_4 (12 B): matches/0x00333ca0.cpp [wrapped: conflict: movie::Player2; movie::PlayerBink]
// sym: ?vfunc_4@PlayerBink@movie@fn_00333ca0@@QAEXXZ
namespace fn_00333ca0 {
namespace movie {
class Player2 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
};
class PlayerBink : public Player2 {
  public:
    char pad[0x20];
    unsigned char state;
    void vfunc_4();
};
void PlayerBink::vfunc_4() {
    state = 0;
    Player2* p = *(Player2**)((char*)this + 0x14);
    p->f7();
}
} // namespace movie
} // namespace fn_00333ca0


// 0x00333cb0 movie::PlayerBink::vfunc_5 (159 B): matches/0x00333cb0.cpp [wrapped: conflict: movie::PlayerBink]
// sym: ?vfunc_5@PlayerBink@movie@fn_00333cb0@@UAEXHHHH@Z
namespace fn_00333cb0 {

namespace movie {
struct Renderer_333cb0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void vfunc_6(int, int, int, int);
};
struct PlayerBink {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(int, int, int, int);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10(int);
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    char pad04[4];
    int field08;
    char pad0c[8];
    Renderer_333cb0* renderer;
    int state;
    void* bink;
    int field20;
    char field24;
    char pad25[3];
    unsigned int field28;
    char field2c;
    void FUN_00333970();
};
} // namespace movie
struct ThisCall_00333ab0 {
    void FUN_00333ab0(int);
};
void __stdcall FUN_00364dc0(unsigned int, void*);
extern "C" void __cdecl FUN_00334fa0();
void __stdcall FUN_00364da0(void(__cdecl*)());
void* __stdcall FUN_00364fe0(int, int);
void __stdcall FUN_00366b40(void*, int);
void movie::PlayerBink::vfunc_5(int a, int b, int c, int d) {
    ((ThisCall_00333ab0*)(this))->FUN_00333ab0(b);
    field24 = 0;
    if (field28 > 0)
        FUN_00364dc0(field28, &field2c);
    else
        FUN_00364dc0(0, 0);
    DAT_00555ba0 = field08;
    FUN_00364da0(FUN_00334fa0);
    bink = FUN_00364fe0(a, 0xa004000);
    if (bink) {
        FUN_00366b40(bink, 1);
        FUN_00333970();
        vfunc_10(field20);
        int* values = (int*)bink;
        renderer->vfunc_6(values[0], values[1], c, d);
        state = 3;
    } else
        state = 0;
}
} // namespace fn_00333cb0


// 0x00333d50 movie::PlayerBink::vfunc_7 (35 B): matches/0x00333d50.cpp
// sym: ?vfunc_7@PlayerBink@movie@@UAEXXZ
void movie::PlayerBink::vfunc_7() {
    if (this->f_18) {
        ReleaseHandle((*(void * *)&this->f_1c));
        (*(void * *)&this->f_1c) = 0;
        this->f_18 = 0;
    }
}


// 0x00333d80 movie::PlayerBink::vfunc_8 (45 B): matches/0x00333d80.cpp
// sym: ?vfunc_8@PlayerBink@movie@@UAEXXZ
void movie::PlayerBink::vfunc_8() {
    if (this->f_18 == 3) {
        FUN_00366b40((*(int *)&this->f_1c), 0);
        this->f_18 = 4;
        return;
    }
    if (this->f_18 == 1)
        this->f_18 = 2;
}


// 0x00333db0 movie::PlayerBink::vfunc_9 (45 B): matches/0x00333db0.cpp
// sym: ?vfunc_9@PlayerBink@movie@@UAEXXZ
void movie::PlayerBink::vfunc_9() {
    if (this->f_18 == 4) {
        FUN_00366b40((*(int *)&this->f_1c), 1);
        this->f_18 = 3;
        return;
    }
    if (this->f_18 == 2)
        this->f_18 = 1;
}

namespace fn_f1126c37 {

// 0x00333de0 FUN_00333de0 (265 B): equivalent/0x00333de0.cpp
// sym: ?FUN_00333de0@Obj_333de0@fn_f1126c37@@QAEXXZ @51de8ad48bc4 @w28722a24910f
// STATUS: equivalent (tools/equiv.py level 3: 111 inputs, branch coverage 18/22, incomplete)
// FUN_00333de0 @ 0x00333de0
void Obj_333de0::FUN_00333de0() {
 if (busy) return;
 busy=1;
 if (state==4) {
  DAT_00555ba0=field8;
  if (!FUN_00366940(data)) {
   bool failed=false;
   if (!flag24 && !FUN_00367bc0(data)) {
    reader->FUN_slot3();
    int values[8];
    while (reader->FUN_slot4(values)>0) {
     int start=values[0];
     int stride=values[1];
     if (stride<0) start+=(values[7]-1)*stride;
     int result=FUN_00365f30(data,start,stride,values[7],0,0,values[4],values[5],values[6],values[7],3);
     if (!result) failed=true;
     else failed=false;
     reader->FUN_slot5();
     if (result) break;
    }
   }
   if (data->index==data->count-1) { FUN_slot7(); busy=0; return; }
   FUN_003681d0(data);
   if (failed) { flag24=1; if (listener) listener->FUN_slot3(this); }
  }
 }
 busy=0;
}


// 0x00333ef0 FUN_00333ef0 (25 B): matches/0x00333ef0.cpp
// sym: _FUN_00333ef0
extern "C" void FUN_00333ef0() {
    if (*(volatile unsigned char*)((hulk_intptr)((char*)&DAT_00555b9c))) {
        Obj_333ef0* p = *(Obj_333ef0* volatile*)((hulk_intptr)((char*)&DAT_00555ba4));
        if (p)
            p->Fn();
    }
}


// 0x00333f10 FUN_00333f10 (96 B): matches/0x00333f10.cpp
// sym: ??0PlayerBink_333f10@fn_f1126c37@@QAE@XZ
PlayerBink_333f10::PlayerBink_333f10() throw() {
    *(void* volatile*)&p0 = (void**)DAT_0043406c;
    *(void* volatile*)&p1 = v1_333f10;
    id = DAT_004cdbb0;
    FUN_002705f0();
    *(void* volatile*)&p1 = v2_333f10;
    m0c = 0;
    FUN_002705f0();
    *(void* volatile*)&p0 = v3_333f10;
    p1 = v4_333f10;
    _ReadWriteBarrier();
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    x = 0;
    y = 0;
    f = 1.0f;
    (*(PlayerBink_333f10**)&DAT_00555ba4) = this;
}

} // namespace fn_f1126c37

// 0x00333f70 movie::PlayerBink::vfunc_0 (4 B): matches/0x00333f70.cpp
// sym: ?vfunc_0@PlayerBink@movie@@UAEXXZ
// Same code shape as 0x00267ba0 (propagated; names are from that function)
void movie::PlayerBink::vfunc_0() {
    ++this->f_0c;
}

namespace fn_f1126c37 {

// 0x00333f80 movie::PlayerBink::vfunc_1 (8 B): matches/0x00333f80.cpp
// sym: ?vfunc_1@PlayerBink_333f80@fn_f1126c37@@UAEXXZ
// Same code shape as 0x0026d270 (propagated; names are from that function)
void PlayerBink_333f80::vfunc_1() {
    IB_333f80::helper();
}

} // namespace fn_f1126c37

// 0x00333f90 movie::PlayerBink::vfunc_0_adj4 (8 B): matches/0x00333f90.cpp [wrapped: conflict: PlayerBink]
// sym: ?f@PlayerBink@fn_00333f90@@W3AEXXZ
namespace fn_00333f90 {
class Player2 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void f();
};
class IRefCount {
  public:
    virtual void f();
};
class PlayerBink : public Player2, public IRefCount {
  public:
    virtual void f();
    int x;
};
void consume(PlayerBink*);
void PlayerBink::f() {
    PlayerBink b;
    consume(&b);
}
} // namespace fn_00333f90


// 0x00333fa0 FUN_00333fa0 (102 B): matches/0x00333fa0.cpp [wrapped: conflict: core::BaseObject; core::IRefCount; movie::PlayerBink]
// sym: ??1PlayerBink@movie@fn_00333fa0@@QAE@XZ
namespace fn_00333fa0 {

namespace core {
struct IRefCount {
    virtual void unused();
    virtual void release();
    ~IRefCount() throw() {}
};
struct BaseObject {
    virtual void unused();
    virtual void release();
    ~BaseObject() throw() {}
};
} // namespace core
struct Resource_333fa0 {
    virtual void unused();
    virtual void release() throw();
};
extern "C" void __stdcall FUN_00368530(void*) throw();
namespace movie {
struct PlayerBink : core::IRefCount, core::BaseObject {
    int id;
    char gap[4];
    Resource_333fa0* first;
    Resource_333fa0* second;
    int active;
    void* buffer;
    ~PlayerBink() throw();
};
} // namespace movie
movie::PlayerBink::~PlayerBink() throw() {
    if (active) {
        FUN_00368530(buffer);
        buffer = 0;
        active = 0;
    }
    DAT_00555ba4 = 0;
    if (second) {
        Resource_333fa0* p = second;
        second = 0;
        p->release();
    }
    if (first) {
        Resource_333fa0* p = first;
        first = 0;
        p->release();
    }
    DAT_004cdbb0 = id;
}
} // namespace fn_00333fa0

namespace fn_f1126c37 {

// 0x00334010 FUN_00334010 (37 B): matches/0x00334010.cpp
// sym: _FUN_00334010
// data: g_value_334010 = DAT_004cdbb0
// movie::PlayerBink on the heap `heap` (0x00333f10 constructs it and returns it)
extern "C" void* __cdecl FUN_00334010(int heap) {
    HULK_SIZE32(MoviePlayerBink, 0x1dc);
    DAT_004cdbb0 = heap;
    Obj_334010* q = (Obj_334010*)FUN_00266e00(heap, (hulk_intptr)sizeof(MoviePlayerBink));
    if (q)
        return q->FUN_00333f10();
    return 0;
}


// 0x00334040 movie::PlayerBink::vfunc_2 (36 B): matches/0x00334040.cpp
// sym: ?f2@PlayerBink_334040@fn_f1126c37@@UAEPAV12@E@Z
// Same code shape as 0x00269560 (propagated; names are from that function)
// data: globalValue = DAT_004cdbb0
PlayerBink_334040* PlayerBink_334040::f2(u8_334040 flag) {
    cleanup();
    if (flag & 1)
        FUN_00266f00(DAT_004cdbb0, this);
    return this;
}

} // namespace fn_f1126c37
