// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023a3f0..0x0023b540 (kind game, layer engine, confidence high), dominant class fight::ScriptReader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7afe597 {
#define TREE_TU_END }
namespace fn_f7afe597 {} using namespace fn_f7afe597;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f7afe597 {
class StringReader_23a3f0 {
  public:
    char pad0[8];
    unsigned char* mBuffer;
    char padc[4];
    unsigned int mLength;
    unsigned int mPosition;
};
extern void* hulk_at_003f6098;
struct Obj_23a440 {
    void** vf;
    char pad[4];
    struct Ref_23a440* p;
};
struct Ref_23a440 {
    virtual void a();
    virtual void b();
};
class Delegate_23a460 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
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
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual int f24();
};
class StringReader_23a460 {
  public:
    char pad[8];
    Delegate_23a460* sub;
};
typedef unsigned char u8_23a470;
struct Source_23a470 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void read(u8_23a470*, int, int);
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void finish();
};
class Reader_23a4d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(unsigned int*);
    virtual void v7(unsigned int*);
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
};
class Source_23a550 {
  public:
};
class Helper_23a5c0 {
  public:
    unsigned getA_00263fc0();
    unsigned getB_00263fb0();
};
struct X_23a5f0 {
    void Call_0027af00();
    X_23a5f0* Target();
};
class Reader {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual int Read();
    virtual void Advance();
};
class Parser_23a610 {
  public:
    char pad[8];
    Reader* reader;
};
class Slot_23a660 {
  public:
};
struct Obj_23ab40 {
    char pad[0x100];
    Obj_23ab40* next;
};
extern void __cdecl thunk_FUN_00267090(Obj_23ab40*);
class ScriptReader_23ab40 {
  public:
    char pad[0x12c];
    int count;
    char pad1[0x0c];
    void f();
};
} // namespace fn_f7afe597
namespace fight {
class Reader_23aba0 {
  public:
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
};
}
namespace fn_f7afe597 {
class Obj_23abb0 {
  public:
    char pad[0x12c];
    int count;
    char pad2[8];
    struct Item {
        int type;
        volatile int ivalue;
        char pad[16];
    } items[1];
    bool Get(int idx, bool* out);
};
class ScriptReader_23ac10 {
    char pad[0x12c];
    int count;
    char gap[0x8];
    struct Entry {
        int type;
        float value;
        char rest[16];
    } entries[1];

  public:
    char get(int index, int* out);
};
struct Node {
    char text[0x100];
    Node* next;           // 0x100
};
struct Entry_23acc0 {
    int type;
    Node* head;           // 0x04
    char pad08[0x18 - 8];
};
struct ScriptReader_23acc0 {
    char pad00[0x12c];
    int count;            // 0x12c
    char pad130[8];
    Entry_23acc0 entries[1];     // 0x138
    bool TotalLength(int index, int* total);
};
extern "C" void __cdecl FUN_00267880(char*, hulk_intptr, int);
struct B_23ada0 {
};
extern "C" void* F238190_00238190(int a);
extern "C" void* F266e00_00266e00(void* a, int n);
extern "C" void F267090_00267090(void* p);
struct ScriptReader_nv_23ada0 {
    bool Size_0023acc0(int a, int* n);
};
struct Entry { unsigned key1; unsigned key2; unsigned flags; char padding[12]; };
struct ScriptReader_23ae90 { char padding[0x12c]; int count; Entry entries[1]; int FUN_0023ae90(unsigned key1, unsigned key2, unsigned mask); };
struct ScriptReader_nv_23aee0 {
    int helper1_0023ae90(int, int, int);
    int helper2_0023abb0(int, int);
};
struct Entry_23af40 {
    int type;
    int val;
    int pad[4];
};
class ScriptReader {
  public:
    virtual int vfunc_6(int a, int b, int c, int d, int e);
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual bool v9(int a, int b, float* out);
    virtual void _m_vf10();
    virtual int vfunc_11(int, int, int);
    char _m_pad_4[0x128];
    int count;
    char _m_pad_130[0x8];
    Entry_23af40 e[1];
    int helper1_0023ae90(int, int, int);
    int helper2_0023ac10(int, int);
    int Find_0023ae90(int a, int b, int c);
    int helper2_0023ad30(int, int, int);
};
struct ScriptReader_nv_23afe0 {
    int first_0023ae90(int, int, int);
};
struct Reader_23b010 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void vfunc_12(int, int, int);
};
struct ScriptReader_nv_23b010 {
    int helper_0023ae90(int, int, int);
    int finish_0023ada0(int, int);
};
struct Pair_23b140 {
 unsigned int low, high;
 void FUN_0027af70(Pair_23b140*);
};
} // namespace fn_f7afe597
namespace fight {
struct ScriptReader_nv_23b140 {
    void FUN_0023ab40();
    void FUN_0023a6b0();
};
}
namespace fn_f7afe597 {
struct Inner_23b1f0 {
};
struct ScriptReader_nv_23b1f0 {
    void helper_0023ab40();
    void finish_0023a6b0();
};
extern "C" char DAT_00428590[];
class Obj_23b2f0 {
  public:
    virtual void f0();
    virtual void f1();
};
class IFileStringReader {
  public:
    hulk_uintptr vt;
    char _m_pad_4[0x4];
    union { Source_23a470* source; Obj_23b2f0* sub; };
    u8_23a470 value;
    u8_23a470 loaded;
    char _m_pad_e[0x2];
    u8_23a470 vfunc_4();
    IFileStringReader* vfunc_2(int);
};
class RenderThing_23b350 {
  public:
    virtual void f0();
    virtual void f1();
};
extern int hulk_at_004285b0;
extern int ref_vtable;
class StreamStringReader_23b350 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual StreamStringReader_23b350* vfunc_2(unsigned char);
    virtual void vfunc_3();
    char pad[8];
    RenderThing_23b350* member;
};
extern void destroy_00263f30(StreamStringReader_23b350*);
extern void* hulk_at_0042866c[];
class Ref_23b3b0 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Elem_23b3b0 {
    char b[0x18];
    void Fini_0027af50() throw();
};
struct Elem8 {
    char b[8];
    void Fini_0027af50() throw();
};
struct Reader_23b3b0 {
    void* vf;
    void Dtor_00232c30() throw();
};
struct ScriptReader_23b3b0 : Reader_23b3b0 {
    void Pre_0023ab40() throw();
    int p4;
    Ref_23b3b0* p8;
    char pad[0x10c];
    Elem8 e118;
    Elem8 e120;
    char pad2[8];
    Elem_23b3b0 arr[0x200];
    void Dtor2() throw();
};
class Inner_23b410 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

} // namespace fn_f7afe597

// 0x0023a3f0 fight::BufferStringReader::vfunc_4 (18 B): matches/0x0023a3f0.cpp
// sym: ?vfunc_4@BufferStringReader@fight@@UAEEXZ
 // namespace fight
unsigned char fight::BufferStringReader::vfunc_4() {
    if (this->f_14 >= this->f_10)
        return 0;
    return (*(unsigned char * *)&this->f_08)[this->f_14];
}


// 0x0023a410 fight::BufferStringReader::vfunc_5 (22 B): matches/0x0023a410.cpp
// sym: ?vfunc_5@BufferStringReader@fight@@UAEEXZ
unsigned char fight::BufferStringReader::vfunc_5() {
    unsigned int p = this->f_14;
    if (p >= this->f_10)
        return 0;
    unsigned char c = (*(unsigned char * *)&this->f_08)[p];
    this->f_14 = p + 1;
    return c;
}


// 0x0023a430 fight::BufferStringReader::vfunc_6 (10 B): matches/0x0023a430.cpp
// sym: ?vfunc_6@BufferStringReader@fight@@UAE_NXZ
bool fight::BufferStringReader::vfunc_6() {
    return this->f_14 >= this->f_10;
}

namespace fn_f7afe597 {

// 0x0023a440 FUN_0023a440 (25 B): matches/0x0023a440.cpp
// sym: ?target@fn_f7afe597@@YIXPAUObj_23a440@1@@Z
// Same code shape as 0x000af0d0 (propagated; names are from that function)
void __fastcall target(Obj_23a440* self) {
    self->p;
    self->vf = (void**)&gameVtable;
    self->p->b();
    self->vf = (void**)&hulk_at_003f6098;
}

} // namespace fn_f7afe597

// 0x0023a460 fight::IFileStringReader::vfunc_3 (8 B): matches/0x0023a460.cpp
// sym: ?vfunc_3@IFileStringReader@fight@@UAEIXZ
unsigned int fight::IFileStringReader::vfunc_3() {
    return (unsigned int)((*(Delegate_23a460 * *)&this->f_08)->f24());
}

namespace fn_f7afe597 {

// 0x0023a470 fight::IFileStringReader::vfunc_4 (52 B): matches/0x0023a470.cpp
// sym: ?vfunc_4@IFileStringReader@fn_f7afe597@@QAEEXZ
u8_23a470 IFileStringReader::vfunc_4() {
    if (loaded)
        return value;
    value = 0;
    source->read(&value, 1, 1);
    source->finish();
    loaded = 1;
    return value;
}

} // namespace fn_f7afe597

// 0x0023a4b0 fight::IFileStringReader::vfunc_5 (18 B): matches/0x0023a4b0.cpp [wrapped: conflict: fight::IFileStringReader]
// sym: ?vfunc_5@IFileStringReader@fight@fn_0023a4b0@@UAEHXZ
namespace fn_0023a4b0 {
namespace fight {
class IFileStringReader {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual int vfunc_4();
    virtual int vfunc_5();
    virtual void vfunc_6();
    char pad[8];
    char a;
    char b;
};
int IFileStringReader::vfunc_5() {
    int r = vfunc_4();
    a = 0;
    b = 0;
    return r;
}
} // namespace fight
} // namespace fn_0023a4b0


// 0x0023a4d0 fight::IFileStringReader::vfunc_6 (78 B): matches/0x0023a4d0.cpp
// sym: ?vfunc_6@IFileStringReader@fight@@UAE_NXZ
bool fight::IFileStringReader::vfunc_6() {
    if (this->f_0d)
        return false;
    (*(Reader_23a4d0 * *)&this->f_08)->v21();
    unsigned int a;
    unsigned int b;
    (*(Reader_23a4d0 * *)&this->f_08)->v6(&a);
    (*(Reader_23a4d0 * *)&this->f_08)->v7(&b);
    (*(Reader_23a4d0 * *)&this->f_08)->v21();
    return a >= b;
}


// 0x0023a520 FUN_0023a520 (25 B): matches/0x0023a520.cpp [wrapped: helper definitions (6 out-of-line function bodies)]
// sym: ??1StreamStringReader@fn_0023a520@@UAE@XZ
namespace fn_0023a520 {
class StreamStringReader_23a520 {
  public:
    virtual void A();
    virtual void B();
    virtual ~StreamStringReader_23a520() throw();
};
class StreamStringReader : public StreamStringReader_23a520 {
  public:
    char pad[8];
    StreamStringReader_23a520* m;
    virtual void A();
    virtual void B();
    ~StreamStringReader() throw();
};
void StreamStringReader_23a520::A() {}
void StreamStringReader_23a520::B() {}
StreamStringReader_23a520::~StreamStringReader_23a520() throw() {}
void StreamStringReader::A() {}
void StreamStringReader::B() {}
StreamStringReader::~StreamStringReader() throw() {
    m->B();
}
} // namespace fn_0023a520

namespace fn_f7afe597 {

// 0x0023a540 fight::StreamStringReader::vfunc_3 (4 B): matches/0x0023a540.cpp
// sym: ?FUN_0023a540@fn_f7afe597@@YIHPAX@Z
// Same code shape as 0x00086320 (propagated; names are from that function)
int __fastcall FUN_0023a540(void* p) {
    return *(int*)((char*)p + 8);
}

} // namespace fn_f7afe597

// 0x0023a550 fight::StreamStringReader::vfunc_4 (66 B): matches/0x0023a550.cpp
// sym: ?vfunc_4@StreamStringReader@fight@@UAEEXZ
unsigned char fight::StreamStringReader::vfunc_4() {
    if (this->f_11)
        return (unsigned char)(this->f_10);
    this->f_10 = false;
    if (vfunc_6()) {
        this->f_11 = false;
        return (unsigned char)(this->f_10);
    }
    ((owners::X_2647e0 *)(((Source_23a550*)*(void**)((char*)this + 12))))->FUN_002647e0((hulk_intptr)((char*)this + 16), (hulk_intptr)1, 1, (hulk_intptr)1);
    this->f_11 = true;
    return (unsigned char)(this->f_10);
}


// 0x0023a5a0 fight::StreamStringReader::vfunc_5 (18 B): matches/0x0023a5a0.cpp [wrapped: conflict: fight::StreamStringReader]
// sym: ?vfunc_5@StreamStringReader@fight@fn_0023a5a0@@UAEHXZ
namespace fn_0023a5a0 {
namespace fight {
class StreamStringReader {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4();
    virtual int vfunc_5();
    virtual void f6();
    char pad[12];
    char a;
    char b;
};
int StreamStringReader::vfunc_5() {
    int result = f4();
    a = 0;
    b = 0;
    return result;
}
} // namespace fight
} // namespace fn_0023a5a0


// 0x0023a5c0 fight::StreamStringReader::vfunc_6 (41 B): matches/0x0023a5c0.cpp
// sym: ?vfunc_6@StreamStringReader@fight@@UAE_NXZ
bool fight::StreamStringReader::vfunc_6() {
    if (this->f_11)
        return false;
    unsigned a = (*(Helper_23a5c0 * *)&this->f_0c)->getA_00263fc0();
    unsigned b = (*(Helper_23a5c0 * *)&this->f_0c)->getB_00263fb0();
    return a >= b;
}

namespace fn_f7afe597 {

// 0x0023a5f0 FUN_0023a5f0 (12 B): matches/0x0023a5f0.cpp
// sym: ?Target@X_23a5f0@fn_f7afe597@@QAEPAU12@XZ
// Same code shape as 0x00034ad0 (propagated; names are from that function)
X_23a5f0* X_23a5f0::Target() {
    Call_0027af00();
    return this;
}


// 0x0023a610 FUN_0023a610 (79 B): matches/0x0023a610.cpp
// sym: ?target@fn_f7afe597@@YIHPAVParser_23a610@1@@Z
int __fastcall target(Parser_23a610* p) {
    int count = 0;
    char c = (char)p->reader->Read();
    while (_isspace((int)c) && c != '\n') {
        p->reader->Advance();
        ++count;
        c = (char)p->reader->Read();
    }
    return count;
}

} // namespace fn_f7afe597

// 0x0023a660 FUN_0023a660 (65 B): matches/0x0023a660.cpp
// sym: ?FUN_0023a660@Owner_23a660@owners@@QAEHPAX@Z
int owners::Owner_23a660::FUN_0023a660(void* arg) {
    int i = count;
    int r = -1;
    if (i < 0x200) {
        Slot_23a660* s = (Slot_23a660*)((char*)this + (i * 3) * 8 + 0x130);
        ((owners::Target_27b040 *)s)->FUN_0027b040((hulk_uintptr)arg);
        *(int*)((char*)this + (i * 3 + 0x27) * 8) = 0;
        count++;
        r = i;
    }
    return r;
}

namespace fn_f7afe597 {

// 0x0023ab40 FUN_0023ab40 (90 B): matches/0x0023ab40.cpp
// sym: ?f@ScriptReader_23ab40@fn_f7afe597@@QAEXXZ
void ScriptReader_23ab40::f() {
    int n = count;
    if (--n >= 0) {
        char* p = (char*)this + 0x13c + n * 0x18;
        int left = n + 1;
        do {
            if (*((int*)p - 1) == 4) {
                Obj_23ab40* x = *(Obj_23ab40**)p;
                while (x) {
                    Obj_23ab40* cur = x;
                    x = x->next;
                    thunk_FUN_00267090(cur);
                }
            }
            p -= 0x18;
            --left;
        } while (left);
    }
    count = 0;
}

} // namespace fn_f7afe597

// 0x0023aba0 fight::ScriptReader::vfunc_4 (8 B): matches/0x0023aba0.cpp
// sym: ?vfunc_4@ScriptReader@fight@@UAEXXZ
 // namespace fight
void fight::ScriptReader::vfunc_4() {
    (*(Reader_23aba0 * *)&this->f_08)->r6();
}

namespace fn_f7afe597 {

// 0x0023abb0 FUN_0023abb0 (91 B): matches/0x0023abb0.cpp
// sym: ?Get@Obj_23abb0@fn_f7afe597@@QAE_NHPA_N@Z
bool Obj_23abb0::Get(int idx, bool* out) {
    if (idx < 0 || idx >= count)
        return false;
    switch (items[idx].type) {
    case 1:
        *out = items[idx].ivalue != 0;
        return true;
    case 2:
        *out = (int)*(float*)&items[idx].ivalue != 0;
        return true;
    }
    return false;
}


// 0x0023ac10 FUN_0023ac10 (81 B): matches/0x0023ac10.cpp
// sym: ?get@ScriptReader_23ac10@fn_f7afe597@@QAEDHPAH@Z
char ScriptReader_23ac10::get(int index, int* out) {
    if (index >= 0 && index < count) {
        switch (entries[index].type) {
        case 1:
            *out = *(int*)&entries[index].value;
            return 1;
        case 2:
            *out = (int)entries[index].value;
            return 1;
        }
    }
    return 0;
}


// 0x0023acc0 FUN_0023acc0 (106 B): equivalent/0x0023acc0.cpp
// sym: ?TotalLength@ScriptReader_23acc0@fn_f7afe597@@QAE_NHPAH@Z @c3e6236a5c4f @w300c2a9ad091
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_0023acc0 @ 0x0023acc0
bool ScriptReader_23acc0::TotalLength(int index, int* total)
{
    if (index < 0 || index >= count)
        return false;
    if (entries[index].type != 4)
        return false;
    *total = 0;
    for (Node* n = entries[index].head; n != 0; n = n->next) {
        const char* p = n->text;
        while (*p)
            p++;
        *total = *total + (int)(p - n->text);
    }
    return true;
}

} // namespace fn_f7afe597

// 0x0023ad30 FUN_0023ad30 (98 B): matches/0x0023ad30.cpp
// sym: ?FUN_0023ad30@ScriptReader@fight@@QAE_NHPADH@Z
bool fight::ScriptReader::FUN_0023ad30(int index, char* out, int arg) {
    if (index < 0 || index >= this->f_12c)
        return false;
    int* status = (int*)((char*)this + (index * 3 + 0x27) * 8);
    if (*status != 4)
        return false;
    if (out) {
        *out = 0;
        hulk_intptr p = *(int*)((char*)this + 0x13c + index * 24);
        while (p) {
            FUN_00267880(out, p, arg);
            p = *(int*)(p + 0x100);
        }
    }
    return true;
}


// 0x0023ada0 FUN_0023ada0 (120 B): matches/0x0023ada0.cpp
// sym: ?FUN_0023ada0@ScriptReader@fight@@QAE_NHPAX@Z
bool fight::ScriptReader::FUN_0023ada0(int a, void* __p1) { B_23ada0 * b = (B_23ada0 *)__p1;

    int n = 0;
    if (!((ScriptReader_nv_23ada0*)this)->Size_0023acc0(a, &n))
        return false;
    int len = n + 1;
    void* p = F266e00_00266e00(F238190_00238190(1), len);
    bool r = ((fight::ScriptReader *)(((ScriptReader_nv_23ada0*)this)))->FUN_0023ad30(a, (char *)p, len);
    if (!r)
        return false;
    ((owners::Target_27b040 *)b)->FUN_0027b040((hulk_uintptr)p);
    F267090_00267090(p);
    return r;
}

namespace fn_f7afe597 {

// 0x0023ae90 FUN_0023ae90 (76 B): equivalent/0x0023ae90.cpp
// sym: ?FUN_0023ae90@ScriptReader_23ae90@fn_f7afe597@@QAEHIII@Z @f8802d937415 @wd57f41f74af3
// STATUS: equivalent (tools/equiv.py level 3: 1586 inputs, branch coverage 12/12)
// FUN_0023ae90 @ 0x0023ae90
int ScriptReader_23ae90::FUN_0023ae90(unsigned key1, unsigned key2, unsigned mask) {
    int first = -1;
    for (int i = 0; i < count; ++i) {
        Entry &entry = entries[i];
        if (entry.key1 == key1 && entry.key2 == key2) {
            if (entry.flags & mask) return i;
            if (first < 0) first = i;
        }
    }
    return first;
}

} // namespace fn_f7afe597

// 0x0023aee0 fight::ScriptReader::vfunc_11 (39 B): matches/0x0023aee0.cpp
// sym: ?vfunc_11@ScriptReader@fight@@UAEHHHH@Z
int fight::ScriptReader::vfunc_11(int a, int b, int c) {
    int x = ((ScriptReader_nv_23aee0*)this)->helper1_0023ae90(a, b, 3);
    return ((ScriptReader_nv_23aee0*)this)->helper2_0023abb0(x, c);
}

namespace fn_f7afe597 {

// 0x0023af10 fight::ScriptReader::vfunc_10 (39 B): matches/0x0023af10.cpp
// sym: ?vfunc_11@ScriptReader@fn_f7afe597@@UAEHHHH@Z
// Same code shape as 0x0023aee0 (propagated; names are from that function)
int ScriptReader::vfunc_11(int a, int b, int c) {
    int x = helper1_0023ae90(a, b, 3);
    return helper2_0023ac10(x, c);
}


// 0x0023af40 fight::ScriptReader::vfunc_9 (97 B): matches/0x0023af40.cpp
// sym: ?v9@ScriptReader@fn_f7afe597@@UAE_NHHPAM@Z
bool ScriptReader::v9(int a, int b, float* out) {
    int i = Find_0023ae90(a, b, 3);
    if (i >= 0 && i < count) {
        switch (e[i].type) {
        case 1:
            *out = (float)e[i].val;
            return true;
        case 2:
            *out = *(float*)&e[i].val;
            return true;
        }
    }
    return false;
}

} // namespace fn_f7afe597

// 0x0023afb0 fight::ScriptReader::vfunc_12 (39 B): matches/0x0023afb0.cpp [wrapped: conflict: ScriptReader]
// sym: ?vfunc_12@ScriptReader@fn_0023afb0@@UAEXHHH@Z
namespace fn_0023afb0 {
struct Reader {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void vfunc_12(int, int, int);
};
struct ScriptReader : Reader {
    int helper_0023ae90(int, int, int);
    int finish_0023acc0(int, int);
    void vfunc_12(int, int, int);
};
void ScriptReader::vfunc_12(int a, int b, int c) {
    int x = helper_0023ae90(a, b, 4);
    finish_0023acc0(x, c);
}
} // namespace fn_0023afb0


// 0x0023afe0 fight::ScriptReader::vfunc_8 (44 B): matches/0x0023afe0.cpp
// sym: ?vfunc_8@ScriptReader@fight@@UAEXHHHH@Z
void fight::ScriptReader::vfunc_8(int a, int b, int c, int d) {
    int x = ((ScriptReader_nv_23afe0*)this)->first_0023ae90(a, b, 4);
    ((fight::ScriptReader *)(((ScriptReader_nv_23afe0*)this)))->FUN_0023ad30(x, (char *)(hulk_uintptr)(int)c, d);
}


// 0x0023b010 fight::ScriptReader::vfunc_7 (39 B): matches/0x0023b010.cpp
// sym: ?vfunc_7@ScriptReader@fight@@UAEXHHH@Z
// Same code shape as 0x0023afb0 (propagated; names are from that function)
void fight::ScriptReader::vfunc_7(int a, int b, int c) {
    int x = ((ScriptReader_nv_23b010*)this)->helper_0023ae90(a, b, 4);
    ((ScriptReader_nv_23b010*)this)->finish_0023ada0(x, c);
}

namespace fn_f7afe597 {

// 0x0023b040 fight::ScriptReader::vfunc_6 (44 B): matches/0x0023b040.cpp
// sym: ?vfunc_6@ScriptReader@fn_f7afe597@@UAEHHHHHH@Z
int ScriptReader::vfunc_6(int a, int b, int c, int d, int e) {
    int x = helper1_0023ae90(a, b, 4);
    return helper2_0023ad30(x, d, e);
}

} // namespace fn_f7afe597

// 0x0023b070 fight::ScriptReader::vfunc_5 (95 B): equivalent/0x0023b070.cpp [wrapped: conflict: fight::ScriptReader]
// sym: ?vfunc_5@ScriptReader@fight@fn_0023b070@@QAE_NHHPAX@Z @8ee758d3a301 @w854fdd10bb6f
namespace fn_0023b070 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// fight::ScriptReader::vfunc_5 @ 0x0023b070
namespace fight {
struct ScriptReader {
    char reserved[0x12c];
    int count;
    char gap[8];
    struct Entry { int kind; int value; float first; float second; char rest[8]; } entries[1];
    int FUN_0023ae90(int a, int b, int kind);
    bool vfunc_5(int a, int b, void* output);
};
bool ScriptReader::vfunc_5(int a, int b, void* output) {
    int index = FUN_0023ae90(a, b, 8);
    if (index < 0 || index >= count || entries[index].kind != 8)
        return false;
    struct Result { int value; float first; float second; };
    Result* result = (Result*)output;
    result->value = entries[index].value;
    result->first = entries[index].first;
    result->second = entries[index].second;
    return true;
}
}
} // namespace fn_0023b070


// 0x0023b0d0 fight::ScriptReader::vfunc_13 (38 B): matches/0x0023b0d0.cpp
// sym: ?vfunc_13@ScriptReader@fight@@UAEHXZ
 // namespace fight
int fight::ScriptReader::vfunc_13() {
    if (((*(volatile int *)&this->f_120) | this->f_124) && this->f_128 > (*(int (*)[67])&this->f_14)[this->f_10])
        return 1;
    return 0;
}


// 0x0023b100 fight::ScriptReader::vfunc_14 (33 B): matches/0x0023b100.cpp
// sym: ?vfunc_14@ScriptReader@fight@@UAE_JXZ
__int64 fight::ScriptReader::vfunc_14() {
    if (this->f_128 <= (*(int (*)[67])&this->f_14)[this->f_10])
        return (__int64)(0);
    return (__int64)(*(unsigned __int64*)((char*)this + 0x120));
}


// 0x0023b130 fight::ScriptReader::vfunc_15 (13 B): matches/0x0023b130.cpp
// sym: ?vfunc_15@ScriptReader@fight@@UAE_JXZ
__int64 fight::ScriptReader::vfunc_15() {
    return (__int64)(*(unsigned long long*)&this->f_118);
}


// 0x0023b140 fight::ScriptReader::vfunc_16 (174 B): equivalent/0x0023b140.cpp
// sym: ?vfunc_16@ScriptReader@fight@@UAE_JHH@Z @30d33226dbd1 @w6ba087865a69
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// fight::ScriptReader::vfunc_16 @ 0x0023b140
__int64 fight::ScriptReader::vfunc_16(int __p0, int __p1) { unsigned int low = (unsigned int)__p0; unsigned int high = (unsigned int)__p1;

 ++this->f_10;
 ((ScriptReader_nv_23b140*)this)->FUN_0023ab40();
 int level = this->f_10;
 if (level >= 64) return (__int64)(0);
 if (((*(Pair_23b140 *)&this->f_120).low | (*(Pair_23b140 *)&this->f_120).high) != 0 && this->f_128 >= (&this->f_10)[level] &&
     ((low | high) == 0 || ((*(Pair_23b140 *)&this->f_120).low == low && (*(Pair_23b140 *)&this->f_120).high == high))) {
   (*(Pair_23b140 *)&this->f_118).FUN_0027af70(&(*(Pair_23b140 *)&this->f_120));
   (&this->f_10)[this->f_10 + 1] = this->f_128;
   ((owners::Target_27b040 *)&((*(Pair_23b140 *)&this->f_120)))->FUN_0027b040((hulk_uintptr)0);
   this->f_128 = 0;
   ((ScriptReader_nv_23b140*)this)->FUN_0023a6b0();
   return (__int64)(((unsigned __int64)(*(Pair_23b140 *)&this->f_118).high << 32) | (*(Pair_23b140 *)&this->f_118).low);
 }
 (&this->f_10)[level + 1] = (&this->f_10)[level];
 return (__int64)(0);
}


// 0x0023b1f0 fight::ScriptReader::vfunc_17 (61 B): matches/0x0023b1f0.cpp
// sym: ?vfunc_17@ScriptReader@fight@@UAEXXZ
void fight::ScriptReader::vfunc_17() {
    --this->f_10;
    ((owners::Target_27b040 *)(((Inner_23b1f0*)((char*)this + 0x118))))->FUN_0027b040((hulk_uintptr)0);
    ((ScriptReader_nv_23b1f0*)this)->helper_0023ab40();
    if (this->f_10 >= 0) {
        int x = (*(volatile int *)&this->f_120);
        x |= (*(volatile int *)&this->f_124);
        if (x == 0)
            ((ScriptReader_nv_23b1f0*)this)->finish_0023a6b0();
    }
}


// 0x0023b240 fight::StringReader::vfunc_2 (31 B): matches/0x0023b240.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0023b240@@UAEPAV123@E@Z
namespace fn_0023b240 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class LoadObject_23b240 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public LoadObject_23b240 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0023b240


// 0x0023b290 fight::BufferStringReader::vfunc_3 (4 B): matches/0x0023b290.cpp
// sym: ?vfunc_3@BufferStringReader@fight@@UAEIXZ
// Same code shape as 0x001cc840 (propagated; names are from that function)
unsigned int fight::BufferStringReader::vfunc_3() {
    return this->f_0c;
}


// 0x0023b2a0 fight::BufferStringReader::vfunc_2 (31 B): matches/0x0023b2a0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0023b2a0@@UAEPAV123@E@Z
namespace fn_0023b2a0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class StringReader_23b2a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public StringReader_23b2a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0023b2a0

namespace fn_f7afe597 {

// 0x0023b2f0 fight::IFileStringReader::vfunc_2 (45 B): matches/0x0023b2f0.cpp
// sym: ?vfunc_2@IFileStringReader@fn_f7afe597@@QAEPAV12@H@Z
IFileStringReader* IFileStringReader::vfunc_2(int flag) {
    Obj_23b2f0* p = sub;
    vt = ((hulk_intptr)DAT_00428590);
    p->f1();
    vt = ((hulk_intptr)DAT_003f6098);
    if (flag & 1)
        thunk(this);
    return this;
}

} // namespace fn_f7afe597

// 0x0023b320 FUN_0023b320 (44 B): matches/0x0023b320.cpp [wrapped: conflict: content::LoadObject; fight::StreamStringReader; fight::StringReader]
// sym: ??0StreamStringReader@fight@fn_0023b320@@QAE@PAVObj_23b320@2@H@Z
namespace fn_0023b320 {
class Obj_23b320 {
  public:
    virtual void A();
};
namespace content {
class LoadObject {
  public:
    virtual void f0();
    virtual void f1();
    int mRef;
    LoadObject() : mRef(0) {}
};
} // namespace content
namespace fight {
class StringReader : public content::LoadObject {
  public:
    virtual void f2();
    int mType;
    StringReader(int b) : mType(b) {}
};
class StreamStringReader : public StringReader {
  public:
    Obj_23b320* mStream;
    bool mDone;
    bool mErr;
    virtual void f2();
    StreamStringReader(Obj_23b320*, int);
};
StreamStringReader::StreamStringReader(Obj_23b320* s, int b) : StringReader(b) {
    mDone = false;
    mErr = false;
    mStream = s;
    s->A();
}
} // namespace fight
} // namespace fn_0023b320

namespace fn_f7afe597 {

// 0x0023b350 fight::StreamStringReader::vfunc_2 (45 B): matches/0x0023b350.cpp
// sym: ?vfunc_2@StreamStringReader_23b350@fn_f7afe597@@UAEPAV12@E@Z
// Same code shape as 0x001b7790 (propagated; names are from that function)
StreamStringReader_23b350* StreamStringReader_23b350::vfunc_2(unsigned char flags) {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_004285b0;
    member->f1();
    *(hulk_intptr*)this = (hulk_intptr)&ref_vtable;
    if (flags & 1)
        destroy_00263f30(this);
    return this;
}

} // namespace fn_f7afe597

// 0x0023b390 fight::Reader::vfunc_2 (30 B): matches/0x0023b390.cpp
// sym: ??_GReader@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
fight::Reader::~Reader() {}

namespace fn_f7afe597 {

// 0x0023b3b0 FUN_0023b3b0 (80 B): matches/0x0023b3b0.cpp
// sym: ?Dtor2@ScriptReader_23b3b0@fn_f7afe597@@QAEXXZ
void ScriptReader_23b3b0::Dtor2() throw() {
    vf = hulk_at_0042866c;
    _ReadWriteBarrier();
    Pre_0023ab40();
    p8->Release();
    Elem_23b3b0* p = arr + 0x200;
    for (int i = 0x200; i; --i) {
        --p;
        p->Fini_0027af50();
    }
    e120.Fini_0027af50();
    e118.Fini_0027af50();
    Reader_23b3b0::Dtor_00232c30();
}

} // namespace fn_f7afe597

// 0x0023b400 fight::ScriptReader::vfunc_3 (3 B): matches/0x0023b400.cpp
// sym: ?vfunc_3@ScriptReader@fight@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char fight::ScriptReader::vfunc_3() {
    return 0;
}


// 0x0023b410 fight::ScriptReader::vfunc_18 (8 B): matches/0x0023b410.cpp
// sym: ?vfunc_18@ScriptReader@fight@@UAEXXZ
void fight::ScriptReader::vfunc_18() {
    (*(Inner_23b410 * *)&this->f_08)->f3();
}


// 0x0023b420 fight::ScriptReader::vfunc_19 (4 B): matches/0x0023b420.cpp
// sym: ?vfunc_19@ScriptReader@fight@@UAEIXZ
// Same code shape as 0x001cc840 (propagated; names are from that function)
unsigned int fight::ScriptReader::vfunc_19() {
    return this->f_0c;
}


// 0x0023b470 FUN_0023b470 (117 B): equivalent/0x0023b470.cpp [wrapped: conflict: fight::ScriptReader]
// sym: ??0ScriptReader@fight@fn_0023b470@@QAE@PAVSource_23b470@2@H@Z @9da11340e28f @wa0d974ba7b97
namespace fn_0023b470 {
// STATUS: equivalent (tools/equiv.py level 3: 1647 inputs, branch coverage 2/2)
// FUN_0023b470 @ 0x0023b470
struct Name_23b470 {
    char d[8];
    void FUN_0027af00();
};

struct Entry_23b470 {
    char d[0x18];
    void FUN_0027af00();
};

class Source_23b470 {
public:
    virtual void v0();
};

namespace fight {
class ScriptReader {
public:
    ScriptReader(Source_23b470 *src, int b);
    virtual void v0();
    int f4;
    Source_23b470 *src;
    int b;
    int f10;
    int f14;
    char pad18[0x118 - 0x18];
    Name_23b470 n118;
    Name_23b470 n120;
    int f128;
    int f12c;
    Entry_23b470 entries[0x200];
    void FUN_0023a6b0();
};
}

fight::ScriptReader::ScriptReader(Source_23b470 *s, int bb)
{
    f4 = 0;
    b = bb;
    f10 = 0;
    n118.FUN_0027af00();
    n120.FUN_0027af00();
    f128 = 0;
    f12c = 0;
    for (int i = 0; i < 0x200; i++)
        entries[i].FUN_0027af00();
    f14 = -1;
    src = s;
    s->v0();
    FUN_0023a6b0();
}
} // namespace fn_0023b470

