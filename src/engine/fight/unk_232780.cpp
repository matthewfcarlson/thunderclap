// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00232780..0x00232c40 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "gen/content.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f81ad613 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f81ad613 {} using namespace fn_f81ad613;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f81ad613 {
extern int __cdecl FUN_00238190(int);
extern int __cdecl FUN_00266da0(int);
extern "C" void* __cdecl FUN_0008d690(int);
class Node {
  public:
    virtual void F();
    virtual void G();
    char _m_pad_4[0xc];
    Node* next;
    void Rel(Node*);
};
class List_232810 {
  public:
    Node* head;
    Node* Get(int index);
};
struct Entry { char pad[8]; unsigned int first; unsigned int second; Entry *next; };
struct Collection { Entry *head; Entry *FUN_00232840(unsigned int first, unsigned int second); };
class X_232a30 {
  public:
    virtual void a();
    virtual void b();
};
struct C_232a30 {
    X_232a30* p;
    void f();
};
class Obj_232a50 {
  public:
    virtual void f0();
    virtual void f1();
};
class Target_232a50 {
  public:
    Obj_232a50* m;
    Target_232a50* f(unsigned char flags);
};
class Owner_232a80 {
  public:
    Node* head;
    void Set(Node*);
};
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);
void *thunk_FUN_0008d690(unsigned int size);
void __cdecl thunk_FUN_00267090(void *p);
struct LoadStream_nv_232ae0 {
    content::LoadStream *FUN_00264190(void *data, unsigned int size);
};
class Source_232ae0 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void Read(void *buffer, unsigned int size, int flag);
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void Rewind();
    virtual void s22();
    virtual void s23();
    virtual int GetOption();
};
class Loader_232ae0 {
public:
    int FUN_00232870(void *data, content::LoadStream *stream, unsigned int size, int option);
    int FUN_00232ae0(Source_232ae0 *source, unsigned int size);
};
struct B_232b80 {
    int f();
};
class Obj {
  public:
    virtual void a();
    virtual void release();
};
struct Holder {
    Obj* obj;
    ~Holder() {
        if (obj) {
            obj->release();
            obj = 0;
        }
    }
};
extern void* IRefCount_vftable_232c30;


// 0x00232780 FUN_00232780 (62 B): equivalent/0x00232780.cpp
// sym: ?FUN_00232780@fn_f81ad613@@YAPAHXZ
// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 2/2)
// FUN_00232780 @ 0x00232780
int* __cdecl FUN_00232780() {
    int value = FUN_00266da0(FUN_00238190(0));
    int* result = static_cast<int*>(FUN_0008d690(4));
    if (result) *result = 0;
    (*(int**)&DAT_004e5af8) = result;
    FUN_00266da0(value);
    return result;
}


// 0x002327c0 FUN_002327c0 (17 B): matches/0x002327c0.cpp
// sym: ?FUN_002327c0@fn_f81ad613@@YIHPAPAVNode@1@@Z
int __fastcall FUN_002327c0(Node** p) {
    int n = 0;
    Node* cur = *p;
    while (cur) {
        ++n;
        cur = *(Node**)((char*)cur + 0x10);
    }
    return n;
}


// 0x00232810 FUN_00232810 (35 B): matches/0x00232810.cpp
// sym: ?Get@List_232810@fn_f81ad613@@QAEPAVNode@2@H@Z
Node* List_232810::Get(int index) {
    int i = 0;
    Node* p = head;
    while (p != 0 && index >= i) {
        if (index == i)
            return p;
        p = p->next;
        i++;
    }
    return 0;
}


// 0x00232840 FUN_00232840 (43 B): equivalent/0x00232840.cpp
// sym: ?FUN_00232840@Collection@fn_f81ad613@@QAEPAUEntry@2@II@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00232840 @ 0x00232840
Entry *Collection::FUN_00232840(unsigned int first, unsigned int second) { for (Entry *entry = head; entry; entry = entry->next) { if (entry->first == first && entry->second == second) return entry; } return 0; }

} // namespace fn_f81ad613

// 0x00232870 FUN_00232870 (359 B): equivalent/0x00232870.cpp [wrapped: conflict: FUN_00266da0]
// sym: ?FUN_00232870@fn_00232870@@YGPAVChunk_232870@1@PBDHIH@Z
namespace fn_00232870 {
// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 18/18)
// FUN_00232870 @ 0x00232870
void* __cdecl FUN_00266da0(hulk_intptr n);
int __cdecl FUN_00238190(int n);
void* __cdecl FUN_00263ea0(unsigned int size);

class Stream {
public:
    virtual void v0();
    virtual void v1();
};

class StreamDataReader_232870 : public Stream {
public:
    StreamDataReader_232870* FUN_0023bb00(int a, int b);
};

class StreamStringReader_232870 : public Stream {
public:
    StreamStringReader_232870* FUN_0023b320(int a, int b);
};

class Model_232870 {
public:
    virtual void v0();
    virtual void v1();
};

class BinReader_232870 : public Model_232870 {
public:
    BinReader_232870* FUN_0023c260(Stream* s);
};

class ScriptReader_232870 : public Model_232870 {
public:
    ScriptReader_232870* FUN_0023b470(Stream* s, int flag);
};

class Chunk_232870 {
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
    virtual void v9(int a, Model_232870* m, int b);
    Chunk_232870* FUN_0023b540();
};

Chunk_232870* __stdcall FUN_00232870(const char* data, int a1, unsigned int size, int a3)
{
    void* guard = FUN_00266da0(FUN_00238190(1));
    Stream* stream;
    Model_232870* model;

    if (size > 4 && *(const int*)data == *(const int*)"fig0") {
        void* mem = FUN_00263ea0(0x10);
        stream = 0;
        if (mem)
            stream = ((StreamDataReader_232870*)mem)->FUN_0023bb00(a1, a3);
        stream->v0();
        mem = FUN_00263ea0(0x38);
        model = 0;
        if (mem)
            model = ((BinReader_232870*)mem)->FUN_0023c260(stream);
    } else if (size > 0xc
               && ((const int*)data)[0] == ((const int*)"\r\nfightChunk")[0]
               && ((const int*)data)[1] == ((const int*)"\r\nfightChunk")[1]
               && ((const int*)data)[2] == ((const int*)"\r\nfightChunk")[2]) {
        void* mem = FUN_00263ea0(0x14);
        stream = 0;
        if (mem)
            stream = ((StreamStringReader_232870*)mem)->FUN_0023b320(a1, a3);
        stream->v0();
        mem = FUN_00263ea0(0x3130);
        model = 0;
        if (mem)
            model = ((ScriptReader_232870*)mem)->FUN_0023b470(stream, 1);
    } else {
        FUN_00266da0((hulk_intptr)guard);
        return 0;
    }

    model->v0();
    void* inner = FUN_00266da0(FUN_00238190(2));
    void* mem = FUN_00263ea0(0x30);
    Chunk_232870* dest = 0;
    if (mem)
        dest = ((Chunk_232870*)mem)->FUN_0023b540();
    dest->v9(0, model, -1);
    FUN_00266da0((hulk_intptr)inner);
    model->v1();
    stream->v1();
    FUN_00266da0((hulk_intptr)guard);
    return dest;
}
} // namespace fn_00232870

namespace fn_f81ad613 {

// 0x00232a30 FUN_00232a30 (22 B): matches/0x00232a30.cpp
// sym: ?f@C_232a30@fn_f81ad613@@QAEXXZ
// Same code shape as 0x00045820 (propagated; names are from that function)
void C_232a30::f() {
    if (p) {
        p->b();
        p = 0;
    }
}


// 0x00232a50 FUN_00232a50 (42 B): matches/0x00232a50.cpp
// sym: ?f@Target_232a50@fn_f81ad613@@QAEPAV12@E@Z
Target_232a50* Target_232a50::f(unsigned char flags) {
    if (m) {
        m->f1();
        m = 0;
    }
    if (flags & 1)
        thunk(this);
    return this;
}


// 0x00232a80 FUN_00232a80 (81 B): matches/0x00232a80.cpp
// sym: ?Set@Owner_232a80@fn_f81ad613@@QAEXPAVNode@2@@Z
void Owner_232a80::Set(Node* arg) {
    if (arg) {
        Node* p = head;
        Node* last = 0;
        while (p) {
            last = p;
            p = p->next;
        }
        arg->Rel(p);
        if (last) {
            last->Rel(arg);
            return;
        }
        arg->F();
        if (head)
            head->G();
        head = arg;
    }
}


// 0x00232ae0 FUN_00232ae0 (160 B): matches/0x00232ae0.cpp
// sym: ?FUN_00232ae0@Loader_232ae0@fn_f81ad613@@QAEHPAVSource_232ae0@2@I@Z
// FUN_00232ae0 @ 0x00232ae0
// FUN_00232ae0 @ 0x00232ae0: reads a source into a temporary buffer and hands it to FUN_00232870 through a stream
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
int Loader_232ae0::FUN_00232ae0(Source_232ae0 *source, unsigned int size)
{
    int saved = FUN_00266da0(FUN_00238190(2));
    void *buffer = FUN_0008d6d0(size);
    source->Read(buffer, size, 1);
    source->Rewind();
    void *memory = thunk_FUN_0008d690(0x48);
    content::LoadStream *stream = memory ? ((LoadStream_nv_232ae0*)(((content::LoadStream*)(((content::LoadStream *)memory)))))->FUN_00264190(buffer, size) : 0;
    stream->vfunc_0();
    int result = FUN_00232870(buffer, stream, size, source->GetOption());
    stream->vfunc_1();
    thunk_FUN_00267090(buffer);
    FUN_00266da0(saved);
    return result;
}

} // namespace fn_f81ad613

// 0x00232b80 FUN_00232b80 (39 B): matches/0x00232b80.cpp
// sym: ?FUN_00232b80@A_232b80@owners@@QAEHHHH@Z
int owners::A_232b80::FUN_00232b80(hulk_intptr a, hulk_intptr b, int c) {
    B_232b80* x = (B_232b80*)((hulk_intptr)b);
    int r = x->f();
    return g(((int)a), ((hulk_intptr)b), r, c);
}

namespace fn_f81ad613 {

// 0x00232bb0 FUN_00232bb0 (50 B): matches/0x00232bb0.cpp
// sym: _FUN_00232bb0
// data: gHolder = DAT_004e5af8
extern "C" void FUN_00232bb0() {
    delete (*(Holder**)&DAT_004e5af8);
    (*(Holder**)&DAT_004e5af8) = 0;
}


// 0x00232c30 FUN_00232c30 (7 B): matches/0x00232c30.cpp
// sym: ?FUN_00232c30@fn_f81ad613@@YIXPAX@Z
// Same code shape as 0x001b6820 (propagated; names are from that function)
void __fastcall FUN_00232c30(void* self) {
    *(void**)self = &IRefCount_vftable_232c30;
}

} // namespace fn_f81ad613
