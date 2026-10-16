// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 13/14, incomplete)
// FUN_00282400 @ 0x00282400
#include "decls/address.h"
struct V3_282400 {
    float x, y, z;
};

struct Elem_282400 {
    char data[0x18];
};

struct Desc_282400 {
    int f0;
    int flags;
    char name[7];
    char padf;
    int count;
    int f14;
    char f18;
    char f19;
    char pad1a[2];
    int f1c;
    int f20;
};

class Buf_282400 {
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
    virtual void v15(float* a, float* b);
};

class Stream {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Buf_282400* v4();
    virtual void v5(Buf_282400* b);
    virtual void v6();
};

class Factory_282400 {
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
    virtual Stream* v10(Desc_282400* d);
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
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
};

struct Source_282400 {
    char pad0[0x18];
    V3_282400 pos;
};

struct Registry_282400 {
    int FUN_001b4890(V3_282400* pos, int key, int* ids, int cap);
};

struct Singleton_282400 {
    char pad0[0x594];
    Registry_282400 registry;
};

struct Item_282400 {
    char pad0[0x10];
    Source_282400* source;
    char pad14[0xc];
    V3_282400 savedPos;
    char pad2c[4];
    int key0;
    int key1;
    Stream* stream;
};

typedef void* (__fastcall *CtorFn)(void*);
void* __fastcall FUN_0027f5a0(void* p);
void __stdcall FUN_00011520(void* arr, unsigned int size, int count, CtorFn ctor);
void __stdcall FUN_0027f6f0(Item_282400* item);
Singleton_282400* __cdecl FUN_001b6580();
void __cdecl FUN_0027f5f0(int key, int n, int* ids, Elem_282400* out);
void __cdecl FUN_00280d90(Elem_282400* out, int n3, int cap, int* outCount, V3_282400 center, int key0, int key1);
int __cdecl FUN_00266da0(int mode);

extern Factory_282400* DAT_0052c2a0;

class Builder {
  public:
    char pad0[0x18];
    int mode;
    void FUN_00282400(Item_282400* item);
};

void Builder::FUN_00282400(Item_282400* item)
{
    struct Frame {
        int b0;
        int b1;
        V3_282400 a;
        Desc_282400 desc;
        int ids[0x1f4];
        Elem_282400 arr[0x5dc];
    } fr;
    if (item == 0)
        return;
    if (item->source == 0)
        return;
    FUN_0027f6f0(item);
    fr.a = item->source->pos;
    fr.b0 = item->key0;
    fr.b1 = item->key1;
    int key0 = fr.b0;
    int n = FUN_001b6580()->registry.FUN_001b4890(&fr.a, key0, fr.ids, 0x1f4);
    FUN_00011520(fr.arr, 0x18, 0x5dc, FUN_0027f5a0);
    FUN_0027f5f0(key0, n, fr.ids, fr.arr);
    int key1 = fr.b1;
    V3_282400 center = fr.a;
    fr.b0 = 0;
    FUN_00280d90(fr.arr, n * 3, 0x5dc, &fr.b0, center, key0, key1);
    int count = fr.b0;
    Stream* stream = 0;
    if (count != 0) {
        for (int i = 0; i < 7; i++)
            fr.desc.name[i] = ' ';
        fr.desc.f0 = 0;
        fr.desc.flags = 0x2010;
        fr.desc.count = count;
        fr.desc.f14 = 0;
        fr.desc.f18 = 0;
        fr.desc.f19 = 0;
        fr.desc.f1c = 0;
        fr.desc.f20 = 0;
        int prev = FUN_00266da0(mode);
        stream = DAT_0052c2a0->v10(&fr.desc);
        Buf_282400* buf = stream->v4();
        for (int i = 0; i < count; i++) {
            buf->v15((float*)&fr.arr[i], (float*)&fr.arr[i] + 3);
        }
        stream->v5(buf);
        stream->v6();
        FUN_00266da0(prev);
    }
    DAT_0052c2a8->v91();
    if (stream)
        stream->v0();
    if (item->stream)
        item->stream->v1();
    item->stream = stream;
    item->savedPos = fr.a;
}
