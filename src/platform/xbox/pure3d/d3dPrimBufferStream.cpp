// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00326e90..0x003278e0 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dPrimBufferStream
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fd8cb2f6 {
#define TREE_TU_END }
namespace fn_fd8cb2f6 {} using namespace fn_fd8cb2f6;
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fd8cb2f6 {
struct Format_326e90 { char pad[8]; unsigned flags; unsigned unused; unsigned count; };
struct Layout_326e90 {
 char pad[8]; Format_326e90* format; char* base; unsigned zero; unsigned arg; unsigned count; unsigned texCount; unsigned blendCount; char* position; unsigned reserved; char* normal; char* blend; char* color; char* tex; char* extra1; char* extra2; char* extra3; char* extra4; char* weight; char* point;
 char* FUN_00326e90(char* data, Format_326e90* fmt, unsigned value, unsigned unused);
};
class Obj_326f90 {
  public:
    char pad0[0x10];
    int count;
    char pad14[4];
    int delta;
    char pad1c[8];
    int a24;
    int a28;
    int a2c;
    int a30;
    int a34;
    int a38;
    int a3c;
    int a40;
    int a44;
    int a48;
    int a4c;
    int a50;
    void Fn();
};
extern "C" char DAT_00433424[];
extern "C" char DAT_004334b4[];
void Cleanup(void*);
void __stdcall Release(void*);
struct d3dPrimBuffer_nv_327050 {
    void BaseDestroy();
};
struct VertexFormat_3270c0 { char pad[0x10]; int stride; };
struct BufferOwner { char pad0[0x1c]; int count; char pad1[0x10]; void *buffer; char pad2[8]; VertexFormat_3270c0 *format; void FUN_003270c0(int n); };
namespace D3D8 {
void * __stdcall D3DDevice_CreateVertexBuffer2(int);
}
void __cdecl FUN_0031e210(void *);
extern "C" void __cdecl FUN_0031e1f0(void *,int);
extern "C" void __stdcall D3DResource_Release(int);
extern "C" void FreeOld(int);
extern "C" int __stdcall CreateIndexBuffer(int);
extern "C" void CheckError(unsigned int);
extern "C" void InitIndex(int, int);
class pddiObject_3271f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
class pddiPrimBuffer_3271f0 : public pddiObject_3271f0 {
  public:
    virtual void v6();
};
typedef unsigned int u32_327200;
class pddiObject_327230 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class pddiPrimBuffer_327230 : public pddiObject_327230 {
  public:
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
extern void* __stdcall D3DVertexBuffer_Lock2(void*, int);
class pddiPrimBuffer_327280 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
struct Store_3272b0 {
    char pad[4];
    void* data;
};
} // namespace fn_fd8cb2f6
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void __cdecl memcpy(void*, const void*, unsigned int);
#endif
namespace fn_fd8cb2f6 {
namespace D3D8 {
void __stdcall D3DDevice_SetIndices(DWORD, DWORD);
}
namespace D3D8 {
void __stdcall D3DDevice_SetVertexShader(DWORD);
}
namespace D3D8 {
void __stdcall D3DDevice_SetStreamSource(DWORD, DWORD, DWORD);
}
namespace D3D8 {
void __stdcall D3DDevice_DrawIndexedVertices(DWORD, DWORD, const void*);
}
namespace D3D8 {
void __stdcall D3DDevice_DrawVertices(DWORD, DWORD, DWORD);
}
struct PrimInfo {
    int mul;
    int add;
};
struct VertexFormat_3272f0 {
    char pad[0x10];
    DWORD stride;
    DWORD shader;
};
extern const void* DAT_0039db04;
extern "C" int FUN_00326dc0(int primType, int count);
struct MeshBatch {
    char pad[0x10];
    int primType;
    int primKind;
    char pad1[4];
    int vertexCount;
    char pad2[0x24 - 0x20];
    int indexCount;
    int overrideCount;
    DWORD indexBuffer;
    DWORD vertexBuffer;
    char pad3[0x3c - 0x34];
    VertexFormat_3272f0* format;
    void Draw();
};
} // namespace fn_fd8cb2f6
namespace pure3d {
class pddiPrimBufferStream_327450 {
  public:
    virtual void vfunc_0(int, int, int);
};
}
namespace pure3d {
struct d3dPrimBufferStream_nv_327450 {
    void Advance();
};
}
namespace fn_fd8cb2f6 {
class pddiPrimBufferStream_327530 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(unsigned long, unsigned long, unsigned long);
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
};
class pddiPrimBufferStream_327550 {
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
};
class pddiPrimBufferStream_327570 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int, int);
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
};
class pddiPrimBufferStream_3275b0 {
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
    virtual void v9(unsigned int);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
};
class pddiPrimBufferStream_3275c0 {
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
    virtual void f10(char, char, char, char);
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
};
typedef unsigned int U_327660;
} // namespace fn_fd8cb2f6
namespace pure3d {
class pddiPrimBufferStream_327660 {
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
    virtual void f16(U_327660*, U_327660);
    virtual void f17();
};
}
namespace pure3d {
struct d3dPrimBufferStream_nv_327660 {
    void helper();
};
}
namespace fn_fd8cb2f6 {
typedef unsigned int U_327690;
struct d3dPrimBufferStream_nv_327690 {
    void finish();
};
} // namespace fn_fd8cb2f6
namespace pure3d {
struct V3 {
  public:
    union { int a; int x; };
    union { int b; int y; };
    union { int c; int z; };
};
}
namespace pure3d {
struct V2 {
  public:
    union { int a; int x; };
    union { int b; int y; };
};
}
namespace pure3d {
inline void Copy3(V3* dst, const V3* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
}
}
namespace pure3d {
struct d3dPrimBufferStream_nv_3276d0 {
    void Advance();
};
}
namespace pure3d {
struct d3dPrimBufferStream_nv_327710 {
    void advance();
};
}
namespace pure3d {
struct Triple_327750 { unsigned x,y,z; };
}
namespace pure3d {
struct Pair_327750 { unsigned x,y; };
}
namespace pure3d {
struct d3dPrimBufferStream_nv_327750 {
    void FUN_00326f90();
};
}
namespace fn_fd8cb2f6 {
extern int vt_3277b0;
class d3dPrimBuffer_3277b0 {
  public:
    d3dPrimBuffer_3277b0(int arg);
    void InitBase();
    hulk_intptr p0;
    int p4, p8;
    int m0c;
    int p10, p14;
    int m18, m1c, m20, m24, m28, m2c, m30;
    unsigned char b34, b35, b36;
    int m38;
};
typedef unsigned int U_327800;
extern int vtd[], vtp[];
class pddiPrimBuffer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class d3dPrimBuffer : public pddiPrimBuffer {
  public:
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual void _m_vf14();
    char _m_pad_4[0x28];
    U_327800 a;
    union { U_327800 b; void* buffer; };
    char _m_pad_34[0x2];
    uchar locked;
    char _m_pad_37[0x1];
    hulk_uintptr target(int arg);
    void cleanup();
    d3dPrimBuffer* f3(unsigned char);
};
extern void __cdecl helper(U_327800);
extern void __stdcall release(U_327800);
extern void __cdecl destroy(d3dPrimBuffer*);
struct SkinSource_327860 {
    void *FUN_00321da0(const char *name, int index, unsigned int flags, int one);
};
struct Skin_327860 {
    char pad0[0x10];
    int field_10;
    int index;
    unsigned int flags;
    char pad1[0x1c];
    SkinSource_327860 *source;
    void *result;
    void FUN_003270c0(int a);
    void FUN_00327860(int index, unsigned int flags, int unused, int a4, int a5, const char *name);
};


// 0x00326e90 FUN_00326e90 (251 B): equivalent/0x00326e90.cpp
// sym: ?FUN_00326e90@Layout_326e90@fn_fd8cb2f6@@QAEPADPADPAUFormat_326e90@2@II@Z @b7c1ce54ac6d @w8c82ce826ddc
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 28/28)
// FUN_00326e90 @ 0x00326e90
char* Layout_326e90::FUN_00326e90(char* data, Format_326e90* fmt, unsigned value, unsigned unused) {
 base=data; zero=0; arg=value; reserved=0; blend=0; color=0; tex=0; extra1=0; extra2=0; extra3=0; extra4=0; point=0; weight=0; format=fmt;
 unsigned flags=fmt->flags;
 unsigned n=(flags&0x20)?1:((flags&0x4000)?((flags>>15)&7):0);
 unsigned t=flags&15;
 position=data; blendCount=n; texCount=t; count=fmt->count;
 char* p=data+12;
 if(flags&0x100){point=p;p+=4;}
 if(flags&0x80){weight=p;p+=4;}
 if(flags&0x10){normal=p;p+=4;}
 if(flags&0x20){blend=p;p+=4;} else if((flags&0x4000)&&n>0){blend=p;p+=n*4;}
 if(flags&0x40){color=p;p+=4;}
 if(t){tex=p;p+=t*8;}
 if(flags&0x200){extra1=p;p+=4;}
 if(flags&0x400){extra2=p;p+=4;}
 if(flags&0x800){extra3=p;p+=12;}
 if(flags&0x1000){extra4=p;}
 return p;
}


// 0x00326f90 FUN_00326f90 (151 B): matches/0x00326f90.cpp
// sym: ?Fn@Obj_326f90@fn_fd8cb2f6@@QAEXXZ
void Obj_326f90::Fn() {
    ++count;
    a24 += delta;
    if (a2c)
        a2c += delta;
    if (a28)
        a28 += delta;
    if (a44)
        a44 += delta;
    if (a48)
        a48 += delta;
    if (a30)
        a30 += delta;
    if (a34)
        a34 += delta;
    if (a38)
        a38 += delta;
    if (a3c)
        a3c += delta;
    if (a40)
        a40 += delta;
    if (a50)
        a50 += delta;
    if (a4c)
        a4c += delta;
}

} // namespace fn_fd8cb2f6

// 0x00327030 FUN_00327030 (18 B): matches/0x00327030.cpp [wrapped: lost its match in the tree (codegen differs (2 of 8 instructions))]
// sym: ??0pddiPrimBuffer@fn_00327030@@QAE@XZ
namespace fn_00327030 {
extern int vftable_327030;
class pddiPrimBuffer {
  public:
    void Init();
    pddiPrimBuffer();
};
pddiPrimBuffer::pddiPrimBuffer() {
    Init();
    *(hulk_intptr*)this = (hulk_intptr)&vftable_327030;
}
} // namespace fn_00327030


// 0x00327050 FUN_00327050 (73 B): matches/0x00327050.cpp
// sym: ?FUN_00327050@d3dPrimBuffer@pure3d@@QAEXXZ
void pure3d::d3dPrimBuffer::FUN_00327050() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004334b4);
    if ((*(void * *)&this->f_2c)) {
        Cleanup((*(void * *)&this->f_2c));
        Release((*(void * *)&this->f_2c));
    }
    if ((*(void * *)&this->f_30)) {
        Cleanup((*(void * *)&this->f_30));
        Release((*(void * *)&this->f_30));
    }
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00433424);
    ((d3dPrimBuffer_nv_327050*)this)->BaseDestroy();
}


// 0x003270a0 pure3d::d3dPrimBuffer::vfunc_14 (10 B): matches/0x003270a0.cpp
// sym: ?vfunc_14@d3dPrimBuffer@pure3d@@UAEXH@Z
// Same code shape as 0x00083d70 (propagated; names are from that function)
void pure3d::d3dPrimBuffer::vfunc_14(int x) {
    this->f_28 = x;
}

namespace fn_fd8cb2f6 {

// 0x003270c0 FUN_003270c0 (105 B): equivalent/0x003270c0.cpp
// sym: ?FUN_003270c0@BufferOwner@fn_fd8cb2f6@@QAEXH@Z @e8c5649216e3 @wc720d4b57744
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_003270c0 @ 0x003270c0
void BufferOwner::FUN_003270c0(int n) {
    count = n;
    if (buffer) {
        D3D8::D3DResource_Release(buffer);
        FUN_0031e210(buffer);
    }
    buffer = D3D8::D3DDevice_CreateVertexBuffer2(format->stride * count);
    int result = buffer ? 0 : 0x8007000e;
    FUN_0031e1f0(buffer, format->stride * count);
    FUN_0031c230(result);
}

} // namespace fn_fd8cb2f6

// 0x00327130 FUN_00327130 (96 B): matches/0x00327130.cpp
// sym: ?FUN_00327130@Buffer_327130@owners@@QAEXH@Z
void owners::Buffer_327130::FUN_00327130(int n) {
    int old = resource;
    count = n;
    if (old) {
        D3DResource_Release(old);
        FreeOld(resource);
    }
    resource = 0;
    if (n) {
        int size = n + n;
        resource = CreateIndexBuffer(size);
        CheckError((resource != 0) - 1 & 0x8007000e);
        InitIndex(resource, size);
    }
}


// 0x00327190 pure3d::d3dPrimBuffer::vfunc_4 (92 B): equivalent/0x00327190.cpp [wrapped: conflict: pure3d::d3dPrimBuffer]
// sym: ?vfunc_4@d3dPrimBuffer@pure3d@fn_00327190@@QAEPAURecord_327190@3@XZ @5e84ebb77904 @w3a46d8e8a8ec
namespace fn_00327190 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 3/4, incomplete)
// pure3d::d3dPrimBuffer::vfunc_4 @ 0x00327190

namespace D3D8 { int __stdcall D3DVertexBuffer_Lock2(void* buffer, int flags); }
extern "C" void __cdecl FUN_0031c230(int);
struct Record_327190 {
    int header;
    unsigned char active;
    char remaining[0x4f];
    void FUN_00326e90(int data, int value, int count, int flags);
};
namespace pure3d {
struct d3dPrimBuffer {
    char padding0[0x1c];
    int count;
    char padding20[0x10];
    void* buffer;
    unsigned char locked;
    char padding35[7];
    int value;
    Record_327190* vfunc_4();
};
Record_327190* d3dPrimBuffer::vfunc_4() {
    int data = D3D8::D3DVertexBuffer_Lock2(buffer, 0);
    FUN_0031c230(0);
    locked = 1;
    Record_327190* available = 0;
    for (int i = 0; i < 4; ++i) {
        if (!((Record_327190*)&DAT_004d3ed0)[i].active) {
            available = &((Record_327190*)&DAT_004d3ed0)[i];
            break;
        }
    }
    available->active = 1;
    available->FUN_00326e90(data, value, count, 0);
    return available;
}
}
} // namespace fn_00327190


// 0x003271f0 pure3d::d3dPrimBuffer::vfunc_5 (15 B): matches/0x003271f0.cpp
// sym: ?vfunc_5@d3dPrimBuffer@pure3d@@UAEXPAX@Z
void pure3d::d3dPrimBuffer::vfunc_5(void* __p0) { void * p = (void *)__p0;

    *(char*)((char*)this + 0x34) = 0;
    *(char*)((char*)p + 4) = 0;
}


// 0x00327200 pure3d::d3dPrimBuffer::vfunc_7 (29 B): matches/0x00327200.cpp
// sym: ?vfunc_7@d3dPrimBuffer@pure3d@@UAEHXZ
int pure3d::d3dPrimBuffer::vfunc_7() {
    u32_327200 result = *(u32_327200*)((char*)(*(void * *)&this->f_2c) + 4);
    FUN_0031c230(0);
    this->f_35 = 1;
    return (int)(result);
}


// 0x00327220 pure3d::d3dPrimBuffer::vfunc_8 (14 B): matches/0x00327220.cpp
// sym: ?vfunc_8@d3dPrimBuffer@pure3d@@UAEXI@Z
void pure3d::d3dPrimBuffer::vfunc_8(unsigned int x) {
    *((unsigned char*)this + 0x35) = 0;
    *((unsigned int*)this + 9) = x;
}


// 0x00327230 pure3d::d3dPrimBuffer::vfunc_10 (18 B): matches/0x00327230.cpp
// sym: ?vfunc_10@d3dPrimBuffer@pure3d@@UAE_NH@Z
bool pure3d::d3dPrimBuffer::vfunc_10(int value) {
    return value == 0x20001;
}

namespace fn_fd8cb2f6 {

// 0x00327250 pure3d::d3dPrimBuffer::vfunc_11 (38 B): matches/0x00327250.cpp
// sym: ?target@d3dPrimBuffer@fn_fd8cb2f6@@QAEIH@Z
hulk_uintptr d3dPrimBuffer::target(int arg) {
    void* p = D3DVertexBuffer_Lock2(buffer, 0);
    FUN_0031c230(0);
    locked = 1;
    return (hulk_uintptr)p;
}

} // namespace fn_fd8cb2f6

// 0x00327280 pure3d::d3dPrimBuffer::vfunc_12 (5 B): matches/0x00327280.cpp
// sym: ?vfunc_12@d3dPrimBuffer@pure3d@@UAEXXZ
void pure3d::d3dPrimBuffer::vfunc_12() {
    *((char*)this + 0x36) = 0;
}


// 0x003272a0 pure3d::d3dPrimBuffer::vfunc_13 (3 B): matches/0x003272a0.cpp
// sym: ?vfunc_13@d3dPrimBuffer@pure3d@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void pure3d::d3dPrimBuffer::vfunc_13(int a, int b) {}


// 0x003272b0 pure3d::d3dPrimBuffer::vfunc_9 (55 B): matches/0x003272b0.cpp
// sym: ?vfunc_9@d3dPrimBuffer@pure3d@@UAEXPAXH@Z
void pure3d::d3dPrimBuffer::vfunc_9(void* __p0, int count) { const void * src = (const void *)__p0;

    void* dst = (*(Store_3272b0 * *)&this->f_2c)->data;
    FUN_0031c230(0);
    memcpy(dst, src, count * 2);
    this->f_24 = count;
}

namespace fn_fd8cb2f6 {

// 0x003272f0 FUN_003272f0 (238 B): equivalent/0x003272f0.cpp
// sym: ?Draw@MeshBatch@fn_fd8cb2f6@@QAEXXZ @4f005e690c95 @w60922866e0ed
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 10/10)
// FUN_003272f0 @ 0x003272f0
// equiv-conv: FUN_00326dc0 eax ecx
void MeshBatch::Draw() {
    int saved;
    if (overrideCount != 0) {
        if (indexCount > 0) {
            saved = indexCount;
            indexCount = overrideCount;
        } else {
            saved = vertexCount;
            vertexCount = overrideCount;
        }
    }
    if (indexCount > 0) {
        D3D8::D3DDevice_SetIndices(indexBuffer, 0);
        D3D8::D3DDevice_SetVertexShader(format->shader);
        D3D8::D3DDevice_SetStreamSource(0, vertexBuffer, format->stride);
        int type = primType;
        int n = FUN_00326dc0(primKind, indexCount);
        D3D8::D3DDevice_DrawIndexedVertices(type, n * ((PrimInfo*)&DAT_003f3260)[type].mul + ((PrimInfo*)&DAT_003f3260)[type].add, DAT_0039db04);
    } else {
        D3D8::D3DDevice_SetVertexShader(format->shader);
        D3D8::D3DDevice_SetStreamSource(0, vertexBuffer, format->stride);
        int type = primType;
        int n = FUN_00326dc0(primKind, vertexCount);
        D3D8::D3DDevice_DrawVertices(type, 0, n * ((PrimInfo*)&DAT_003f3260)[type].mul + ((PrimInfo*)&DAT_003f3260)[type].add);
    }
    FUN_0031c230(0);
    if (overrideCount != 0) {
        if (indexCount > 0)
            indexCount = saved;
        else
            vertexCount = saved;
    }
}

} // namespace fn_fd8cb2f6

// 0x00327420 pure3d::d3dPrimBufferStream::vfunc_5 (3 B): matches/0x00327420.cpp
// sym: ?vfunc_5@d3dPrimBufferStream@pure3d@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void pure3d::d3dPrimBufferStream::vfunc_5(int a, int b) {}

namespace fn_fd8cb2f6 {

// 0x00327430 pure3d::d3dPrimBufferStream::vfunc_7 (3 B): matches/0x00327430.cpp
// sym: ?FUN_00327430@fn_fd8cb2f6@@YGXPAX000@Z
// Same code shape as 0x0023f7b0 (propagated; names are from that function)
void __stdcall FUN_00327430(void*, void*, void*, void*) {}

} // namespace fn_fd8cb2f6

// 0x00327440 pure3d::d3dPrimBufferStream::vfunc_8 (3 B): matches/0x00327440.cpp
// sym: ?vfunc_8@d3dPrimBufferStream@pure3d@@UAEXHHHHH@Z
// Same code shape as 0x00098440 (propagated; names are from that function)
void pure3d::d3dPrimBufferStream::vfunc_8(int , int , int , int , int ) {}


// 0x00327450 pure3d::d3dPrimBufferStream::vfunc_0 (37 B): matches/0x00327450.cpp
// sym: ?vfunc_0@d3dPrimBufferStream@pure3d@@UAEXHHH@Z
 // namespace pure3d
void pure3d::d3dPrimBufferStream::vfunc_0(int a, int b, int c) {
    (*(int * *)&this->f_24)[0] = a;
    (*(int * *)&this->f_24)[1] = b;
    (*(int * *)&this->f_24)[2] = c;
    ((d3dPrimBufferStream_nv_327450*)this)->Advance();
}


// 0x00327480 pure3d::d3dPrimBufferStream::vfunc_1 (176 B): equivalent/0x00327480.cpp [wrapped: conflict: pure3d::d3dPrimBufferStream; pure3d::pddiPrimBufferStream]
// sym: ?vfunc_1@d3dPrimBufferStream@pure3d@fn_00327480@@UAEXMMM@Z @c5cb2399b5eb @w7590cefcb567
namespace fn_00327480 {
// STATUS: equivalent (tools/equiv.py level 3: 19877 inputs, branch coverage 2/2)
// pure3d::d3dPrimBufferStream::vfunc_1 @ 0x00327480

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif

namespace pure3d {
struct pddiPrimBufferStream { virtual void vfunc_0(); virtual void vfunc_1(float x,float y,float z); };
struct d3dPrimBufferStream : pddiPrimBufferStream {
 char reserved[0x24]; float* normal; unsigned int* packedNormal;
 virtual void vfunc_1(float x,float y,float z);
};
void d3dPrimBufferStream::vfunc_1(float x,float y,float z) {
 unsigned int* output=packedNormal;
 if(output) {
  double scale=1.0f/(sqrt((double)x*x+(double)y*y+(double)z*z)*1.001f);
  int iy=(int)(__int64)((double)y*scale*2147483648.0f);
  unsigned int bits=(iy>>21)&0x7ff;
  int iz=(int)(__int64)((double)z*scale*2147483648.0f);
  bits|=(unsigned int)(__int64)(iz>>22)<<11;
  bits<<=11;
  int ix=(int)(__int64)(scale*x*2147483648.0f);
  bits|=(ix>>21)&0x7ff;
  *output=bits;
 } else { normal[0]=x; normal[1]=y; normal[2]=z; }
}
}
} // namespace fn_00327480


// 0x00327530 pure3d::d3dPrimBufferStream::vfunc_2 (32 B): matches/0x00327530.cpp
// sym: ?vfunc_2@d3dPrimBufferStream@pure3d@@UAEXKKK@Z
void pure3d::d3dPrimBufferStream::vfunc_2(unsigned long a, unsigned long b, unsigned long c) {
    (*(unsigned long * *)&this->f_44)[0] = a;
    (*(unsigned long * *)&this->f_44)[1] = b;
    (*(unsigned long * *)&this->f_44)[2] = c;
}


// 0x00327550 pure3d::d3dPrimBufferStream::vfunc_3 (32 B): matches/0x00327550.cpp
// sym: ?vfunc_3@d3dPrimBufferStream@pure3d@@UAEXIII@Z
void pure3d::d3dPrimBufferStream::vfunc_3(unsigned int a, unsigned int b, unsigned int c) {
    (*(unsigned int * *)&this->f_48)[0] = a;
    (*(unsigned int * *)&this->f_48)[1] = b;
    (*(unsigned int * *)&this->f_48)[2] = c;
}


// 0x00327570 pure3d::d3dPrimBufferStream::vfunc_4 (17 B): matches/0x00327570.cpp
// sym: ?vfunc_4@d3dPrimBufferStream@pure3d@@UAEXHH@Z
void pure3d::d3dPrimBufferStream::vfunc_4(int a, int b) {
    (*(int * *)&this->f_30)[b] = a;
}


// 0x00327590 pure3d::d3dPrimBufferStream::vfunc_6 (28 B): matches/0x00327590.cpp
// sym: ?vfunc_6@d3dPrimBufferStream@pure3d@@UAEXMMH@Z
void pure3d::d3dPrimBufferStream::vfunc_6(float a, float b, int i) {
    (*(float * *)&this->f_38)[i * 2] = a;
    (*(float * *)&this->f_38)[i * 2 + 1] = b;
}


// 0x003275b0 pure3d::d3dPrimBufferStream::vfunc_9 (12 B): matches/0x003275b0.cpp
// sym: ?vfunc_9@d3dPrimBufferStream@pure3d@@UAEXI@Z
void pure3d::d3dPrimBufferStream::vfunc_9(unsigned int param) {
    *(*(unsigned int * *)&this->f_34) = param;
}


// 0x003275c0 pure3d::d3dPrimBufferStream::vfunc_10 (58 B): matches/0x003275c0.cpp
// sym: ?vfunc_10@d3dPrimBufferStream@pure3d@@UAEXDDDD@Z
void pure3d::d3dPrimBufferStream::vfunc_10(char a, char b, char c, char d) {
    (*(unsigned char * *)&this->f_4c)[0] = c * 3;
    (*(unsigned char * *)&this->f_4c)[1] = b * 3;
    (*(unsigned char * *)&this->f_4c)[2] = a * 3;
    (*(unsigned char * *)&this->f_4c)[3] = d * 3;
}


// 0x00327600 pure3d::d3dPrimBufferStream::vfunc_11 (91 B): matches/0x00327600.cpp [wrapped: conflict: pure3d::d3dPrimBufferStream]
// sym: ?vfunc_11@d3dPrimBufferStream@pure3d@fn_00327600@@QAEXMMM@Z
namespace fn_00327600 {
namespace pure3d {
struct d3dPrimBufferStream {
    virtual void vfunc_0();
    char padding[0x4c];
    unsigned int* packedNormal;
    void vfunc_11(float x, float y, float z);
};
void d3dPrimBufferStream::vfunc_11(float x, float y, float z) {
    int iy = (int)(__int64)(y * 2147418112.0f);
    int iz = (int)(__int64)(z * 2147418112.0f);
    int ix = (int)(__int64)(x * 2147418112.0f);
    *packedNormal = (((unsigned int)(__int64)(iy >> 21) & 0x7ffU) | ((unsigned int)(__int64)(iz >> 22) << 11)) << 11 |
                    ((unsigned int)(__int64)(ix >> 21) & 0x7ffU);
}
} // namespace pure3d
} // namespace fn_00327600


// 0x00327660 pure3d::d3dPrimBufferStream::vfunc_16 (42 B): matches/0x00327660.cpp
// sym: ?vfunc_16@d3dPrimBufferStream@pure3d@@UAEXHH@Z
 // namespace pure3d
void pure3d::d3dPrimBufferStream::vfunc_16(hulk_intptr __p0, int __p1) { U_327660 * p = (U_327660 *)__p0; U_327660 v = (U_327660)__p1;

    U_327660* dst = (*(U_327660 * *)&this->f_24);
    dst[0] = p[0];
    dst[1] = p[1];
    dst[2] = p[2];
    *(*(U_327660 * *)&this->f_30) = v;
    ((d3dPrimBufferStream_nv_327660*)this)->helper();
}


// 0x00327690 pure3d::d3dPrimBufferStream::vfunc_15 (59 B): matches/0x00327690.cpp
// sym: ?vfunc_15@d3dPrimBufferStream@pure3d@@UAEXPAX0@Z
void pure3d::d3dPrimBufferStream::vfunc_15(void* __p0, void* __p1) { U_327690 * a = (U_327690 *)__p0; U_327690 * b = (U_327690 *)__p1;

    U_327690* p = (*(U_327690 * *)&this->f_24);
    p[0] = a[0];
    p[1] = a[1];
    p[2] = a[2];
    vfunc_1(b[0], b[1], b[2]);
    ((d3dPrimBufferStream_nv_327690*)this)->finish();
}


// 0x003276d0 pure3d::d3dPrimBufferStream::vfunc_14 (50 B): matches/0x003276d0.cpp
// sym: ?vfunc_14@d3dPrimBufferStream@pure3d@@UAEXHH@Z
 // namespace pure3d
void pure3d::d3dPrimBufferStream::vfunc_14(hulk_intptr __p0, hulk_intptr __p1) { const V3 * p = (const V3 *)__p0; const V2 * t = (const V2 *)__p1;

    Copy3((*(V3 * *)&this->f_24), p);
    *(*(V2 * *)&this->f_38) = *t;
    ((d3dPrimBufferStream_nv_3276d0*)this)->Advance();
}


// 0x00327710 pure3d::d3dPrimBufferStream::vfunc_13 (59 B): matches/0x00327710.cpp
// sym: ?vfunc_13@d3dPrimBufferStream@pure3d@@UAEXHHH@Z
 // namespace pure3d
void pure3d::d3dPrimBufferStream::vfunc_13(hulk_intptr __p0, int c, hulk_intptr __p2) { const V3 * p = (const V3 *)__p0; const V2 * t = (const V2 *)__p2;

    V3* dest = (*(V3 * *)&this->f_24);
    dest->x = p->x;
    dest->y = p->y;
    dest->z = p->z;
    *(*(int * *)&this->f_30) = c;
    *(*(V2 * *)&this->f_38) = *t;
    ((d3dPrimBufferStream_nv_327710*)this)->advance();
}


// 0x00327750 pure3d::d3dPrimBufferStream::vfunc_12 (76 B): equivalent/0x00327750.cpp
// sym: ?vfunc_12@d3dPrimBufferStream@pure3d@@UAEXHHH@Z @dcb8fb0a3151 @w1d119a9ddcbf
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// pure3d::d3dPrimBufferStream::vfunc_12 @ 0x00327750
void pure3d::d3dPrimBufferStream::vfunc_12(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { const Triple_327750 * p = (const Triple_327750 *)__p0; const Triple_327750 * n = (const Triple_327750 *)__p1; const Pair_327750 * uv = (const Pair_327750 *)__p2;

 Triple_327750* out=(*(Triple_327750 * *)&this->f_24);
 out->x=p->x;
 out->y=p->y;
 out->z=p->z;
 vfunc_1(n->x,n->y,n->z);
 Pair_327750* dest=(*(Pair_327750 * *)&this->f_38);
 dest->x=uv->x;
 dest->y=uv->y;
 ((d3dPrimBufferStream_nv_327750*)this)->FUN_00326f90();
}

// 0x003277a0 pure3d::d3dPrimBufferStream::vfunc_17 (5 B): not yet verified
namespace fn_fd8cb2f6 {

// 0x003277b0 FUN_003277b0 (71 B): matches/0x003277b0.cpp
// sym: ??0d3dPrimBuffer_3277b0@fn_fd8cb2f6@@QAE@H@Z
d3dPrimBuffer_3277b0::d3dPrimBuffer_3277b0(int arg) {
    InitBase();
    m18 = 0;
    m1c = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2c = 0;
    m30 = 0;
    b34 = 0;
    b35 = 0;
    b36 = 0;
    m38 = arg;
    this->p0 = (hulk_intptr)&vt_3277b0;
    m0c = *(int*)(*(hulk_intptr*)((char*)arg + 0x154) + 0x10);
}


// 0x00327800 pure3d::d3dPrimBuffer::vfunc_3 (94 B): matches/0x00327800.cpp
// sym: ?f3@d3dPrimBuffer@fn_fd8cb2f6@@QAEPAV12@E@Z
d3dPrimBuffer* d3dPrimBuffer::f3(unsigned char flag) {
    *(int**)this = vtd;
    if (a) {
        helper(a);
        release(a);
    }
    if (b) {
        helper(b);
        release(b);
    }
    *(int**)this = vtp;
    cleanup();
    if (flag & 1)
        destroy(this);
    return this;
}


// 0x00327860 FUN_00327860 (107 B): equivalent/0x00327860.cpp
// sym: ?FUN_00327860@Skin_327860@fn_fd8cb2f6@@QAEXHIHHHPBD@Z @7711284a52db @w02aa0e790bf0
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00327860 @ 0x00327860
void Skin_327860::FUN_00327860(int idx, unsigned int fl, int unused, int a4, int a5, const char *name)
{
    field_10 = DAT_004d3ea8[idx];
    index = idx;
    flags = fl;
    const char *s = ((char*)&DAT_005555b4);
    if ((char)fl < 0) {
        s = (fl & 0x100) ? "skin" : "skin_onebone";
    }
    if (name != 0) {
        s = name;
    }
    result = source->FUN_00321da0(s, idx, fl, 1);
    FUN_003270c0(a4);
    ((owners::Buffer_327130 *)this)->FUN_00327130(a5);
}

} // namespace fn_fd8cb2f6
