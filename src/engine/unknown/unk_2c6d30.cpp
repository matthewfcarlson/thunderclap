// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c6d30..0x002c89b0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3d8c80d {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3d8c80d {} using namespace fn_f3d8c80d;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f3d8c80d {
struct Obj_2c6d30 {
    unsigned short h[4];
    Obj_2c6d30();
};
struct V4_2c6d90 {
    short x, y, z, w;
    V4_2c6d90* Add(V4_2c6d90* out, V4_2c6d90* rhs);
};
struct Vec_2c6de0 {
    short x, y, z, w;
    void f(Vec_2c6de0* out, Vec_2c6de0* other);
};
struct Vec3_2c6eb0 {
    float x, y, z;
};
class Obj_2c6eb0 {
  public:
    char pad[0x10];
    Vec3_2c6eb0* points;
    void Interpolate(int index, Vec3_2c6eb0* value, float amount);
};
struct Vec3_2c6ef0 {
    float x, y, z;
};
class C_2c6ef0 {
  public:
    char pad[0x14];
    Vec3_2c6ef0* data;
    void f(int index, Vec3_2c6ef0* src, float t);
};
struct Value_2c6f70 { short component[4]; };
struct Object {
 char pad[0x28];
 Value_2c6f70* values[1];
 void blend(int index, const Value_2c6f70* target, int bank, float fraction);
};
} // namespace fn_f3d8c80d
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memset(void*, int, size_t);
#endif
namespace fn_f3d8c80d {
extern "C" void* __cdecl FUN_0008d6d0(unsigned);
extern "C" void __stdcall FUN_00011520(void*, unsigned, unsigned, void*);
extern "C" void __cdecl FUN_00011090();
class Obj_2c7180 {
  public:
    char pad0[8];
    unsigned int flags;
    char padc[4];
    void* ptr;
    void Clear();
};
void thunk_FUN_00267090(void*);
extern "C++" __declspec(nothrow) void __stdcall FUN_00011520(void*, unsigned, unsigned, void (*)());
extern "C" void LAB_00011090();
class Obj_2c7210 {
  public:
    char pad[8];
    unsigned flags;
    char pad2[8];
    void* value;
};
void __cdecl cleanup(void*);
extern "C" void __cdecl FUN_000c7920();
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern "C" void __stdcall Init(void*, int, int, const float*);
typedef void (__cdecl *Callback)();
extern "C++" __declspec(nothrow) void __stdcall FUN_00011520(void*, unsigned int, int, Callback);
extern "C" void __cdecl FUN_002c6d30();
struct V3_2c7340 {
    float x, y, z;
    void FUN_00011090();
};
void __stdcall FUN_00011520(void *arr, unsigned int size, int count, void (V3_2c7340::*ctor)());
class MeshBuffers_2c7340 {
public:
    char pad0[0x14];
    unsigned short *indices;    // 0x14
    V3_2c7340 *vec18;                  // 0x18
    V3_2c7340 *vec1c;                  // 0x1c
    float *raw20;               // 0x20
    float *raw24;               // 0x24
    V3_2c7340 *vec28;                  // 0x28
    float *raw2c;               // 0x2c
    V3_2c7340 *vec30;                  // 0x30
    float *raw34;               // 0x34
    float *uv[4];               // 0x38
    float *color[2];            // 0x48
    float *raw50;               // 0x50
    V3_2c7340 *vec54;                  // 0x54

    void FUN_002c7340(unsigned int flags, unsigned int n, unsigned int indexCount);
};
struct UV {
    float u, v;
};
struct UVi {
    int u, v;
};
struct VertexSink {
    char pad0[8];
    V3 *pos;                // 0x08
    V3 *normal;             // 0x0c
    int *color;             // 0x10
    UV *tex;                // 0x14
    void FUN_0008ef00();
    void FUN_000c7940(V3 *p, int c, UV *t);
};
struct Mesh {
    char pad0[8];
    unsigned int flags;     // 0x08
    char pad0c[4];
    unsigned int count;     // 0x10
    unsigned short *index;  // 0x14
    V3 *posA;               // 0x18
    V3 *nrmA;               // 0x1c
    V3 *posB;               // 0x20
    V3 *nrmB;               // 0x24
    char pad28[0x38 - 0x28];
    UV *uv0;                // 0x38
    UV *uv1;                // 0x3c
    UV *uv2;                // 0x40
    UV *uv3;                // 0x44
    int *color0;            // 0x48
    int *color1;            // 0x4c
};
struct Vec3_2c7a50 {
    float x, y, z;
};
struct Source_2c7a50 {
    char pad00[8];
    unsigned int format;
    unsigned int count;
    char pad10[8];
    Vec3_2c7a50* pos;
    Vec3_2c7a50* normal;
    Vec3_2c7a50* altPos;
    Vec3_2c7a50* altNormal;
    char pad28[0x38 - 0x28];
    float* uv0;
    float* uv1;
    float* uv2;
    float* uv3;
    int* color0;
    int* color1;
};
struct Vertex_2c7a50 {
    float x, y, z;
};
struct Emitter_2c7a50 {
    char pad00[8];
    Vertex_2c7a50* pos;
    Vertex_2c7a50* normal;
    int* color;
    float* uv;
    void FUN_0008ef00();
    void FUN_000c7940(Vec3_2c7a50* pos, int color, float* uv);
};
struct V3_2c7e40 {
    float x, y, z;
};
struct V2_2c7e40 {
    int a;
    int b;
};
class Renderer_2c7e40 {
public:
    virtual void vfunc_0(V3_2c7e40 v);
    virtual void vfunc_1(V3_2c7e40 v);
    virtual void vfunc_2(V3_2c7e40 v);
    virtual void vfunc_3(V3_2c7e40 v);
    virtual void vfunc_4(unsigned int color, int channel);
    virtual void vfunc_5();
    virtual void vfunc_6(V2_2c7e40 v, int channel);
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(V3_2c7e40 *a, V3_2c7e40 *b, V2_2c7e40 *c);
    virtual void vfunc_13(V3_2c7e40 *a, unsigned int color, V2_2c7e40 *c);
    virtual void vfunc_14(V3_2c7e40 *a, V2_2c7e40 *c);
    virtual void vfunc_15(V3_2c7e40 *a, V3_2c7e40 *b);
    virtual void vfunc_16(V3_2c7e40 *a, unsigned int color);
};
struct Batch_2c7e40 {
    char pad0[8];
    unsigned int flags;         // 0x8
    char padc[4];
    unsigned int count;         // 0x10
    unsigned short *indices;    // 0x14
    V3_2c7e40 *pos0;                   // 0x18
    V3_2c7e40 *pos1;                   // 0x1c
    V3_2c7e40 *pos0b;                  // 0x20
    V3_2c7e40 *pos1b;                  // 0x24
    V3_2c7e40 *pos2;                   // 0x28
    V3_2c7e40 *pos2b;                  // 0x2c
    V3_2c7e40 *extra;                  // 0x30
    V3_2c7e40 *extraB;                 // 0x34
    V2_2c7e40 *uv0;                    // 0x38
    V2_2c7e40 *uv1;                    // 0x3c
    V2_2c7e40 *uv2;                    // 0x40
    V2_2c7e40 *uv3;                    // 0x44
    unsigned int *col0;         // 0x48
    unsigned int *col1;         // 0x4c
};
struct Dev_2c8130 {
    virtual void v0(int a, int b, int c);
    virtual void v1(int a, int b, int c);
    virtual void v2(int a, int b, int c);
    virtual void v3(int a, int b, int c);
    virtual void v4(int a, int k);
    virtual void v5();
    virtual void v6(int a, int b, int k);
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(const int *a, const int *b, const int *c);
    virtual void v13(const int *a, int b, const int *c);
    virtual void v14(const int *a, const int *b);
    virtual void v15(const int *a, const int *b);
    virtual void v16(const int *a, int b);
};
struct Desc_2c8130 {
    char pad0[8];
    unsigned type;                  // 0x8
    unsigned count;                 // 0xc
    char pad10[8];
    const int *p18, *p1c, *p20, *p24, *p28, *p2c, *p30, *p34;
    const int *vtx[4];              // 0x38
    const int *uv[2];               // 0x48
};
extern "C" char DAT_0042efb0[];
class VertexOffsetList {
  public:
    VertexOffsetList(int value);
    void* vptr;
    int a1;
    int a2;
    int a3;
    int a4, a5, a6, a7, a8, a9, a10, a11;
};
namespace pure3d {
struct VertexOffsetList {
 virtual void destroy();
 unsigned int refs, flags, count;
 unsigned int *positions, *normals;
 unsigned int *texcoords[4];
 unsigned int *packed[2];
 void FUN_002c7120();
 void FUN_002c71b0();
 VertexOffsetList(const VertexOffsetList& source);
};
}
extern "C" char DAT_0042efc0[];
class VertexList {
  public:
    hulk_intptr vptr;
    int a;
    int b;
    int c;
    int d;
    int e[12];
    int pad[6];
    int q;
    int r;
    int s;
    void init(int, int, int);
    VertexList(int, int, int);
};
namespace pure3d {
struct VertexList {
 virtual void slot0();
 unsigned state, format, count, flags;
 void* streams[18];
 VertexList(const VertexList& source);
 void FUN_002c7340(unsigned,unsigned,unsigned);
};
}


// 0x002c6d30 FUN_002c6d30 (20 B): matches/0x002c6d30.cpp
// sym: ??0Obj_2c6d30@fn_f3d8c80d@@QAE@XZ
Obj_2c6d30::Obj_2c6d30() {
    h[0] = 0;
    h[1] = 0;
    h[2] = 0;
    h[3] = 0;
}


// 0x002c6d50 FUN_002c6d50 (1 B): matches/0x002c6d50.cpp
// sym: _FUN_002c6d50
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_002c6d50() {}

} // namespace fn_f3d8c80d

// 0x002c6d60 FUN_002c6d60 (39 B): matches/0x002c6d60.cpp
// sym: ?FUN_002c6d60@S_2c6d60@owners@@QAEPAU12@PBU12@@Z
owners::S_2c6d60* owners::S_2c6d60::FUN_002c6d60(const owners::S_2c6d60* src) {
    x[0] = src->x[0];
    x[1] = src->x[1];
    x[2] = src->x[2];
    x[3] = src->x[3];
    return this;
}

namespace fn_f3d8c80d {

// 0x002c6d90 FUN_002c6d90 (78 B): matches/0x002c6d90.cpp
// sym: ?Add@V4_2c6d90@fn_f3d8c80d@@QAEPAU12@PAU12@0@Z
V4_2c6d90* V4_2c6d90::Add(V4_2c6d90* out, V4_2c6d90* rhs) {
    V4_2c6d90 t;
    t.x = x + rhs->x;
    t.y = y + rhs->y;
    t.z = z + rhs->z;
    t.w = w + rhs->w;
    *out = t;
    return out;
}


// 0x002c6de0 FUN_002c6de0 (78 B): matches/0x002c6de0.cpp
// sym: ?f@Vec_2c6de0@fn_f3d8c80d@@QAEXPAU12@0@Z
void Vec_2c6de0::f(Vec_2c6de0* out, Vec_2c6de0* other) {
    Vec_2c6de0 t;
    t.x = x - other->x;
    t.y = y - other->y;
    t.z = z - other->z;
    t.w = w - other->w;
    *(unsigned int*)out = *(unsigned int*)&t;
    *((unsigned int*)out + 1) = *((unsigned int*)&t + 1);
}


// 0x002c6eb0 FUN_002c6eb0 (64 B): matches/0x002c6eb0.cpp
// sym: ?Interpolate@Obj_2c6eb0@fn_f3d8c80d@@QAEXHPAUVec3_2c6eb0@2@M@Z
void Obj_2c6eb0::Interpolate(int index, Vec3_2c6eb0* value, float amount) {
    Vec3_2c6eb0* p = points + index;
    p->x = (value->x - p->x) * amount + p->x;
    p->y = (value->y - p->y) * amount + p->y;
    p->z = (value->z - p->z) * amount + p->z;
}


// 0x002c6ef0 FUN_002c6ef0 (64 B): matches/0x002c6ef0.cpp
// sym: ?f@C_2c6ef0@fn_f3d8c80d@@QAEXHPAUVec3_2c6ef0@2@M@Z
void C_2c6ef0::f(int index, Vec3_2c6ef0* src, float t) {
    Vec3_2c6ef0* p = data + index;
    p->x = (src->x - p->x) * t + p->x;
    p->y = (src->y - p->y) * t + p->y;
    p->z = (src->z - p->z) * t + p->z;
}

} // namespace fn_f3d8c80d

// 0x002c6f30 FUN_002c6f30 (50 B): matches/0x002c6f30.cpp
// sym: ?FUN_002c6f30@C_2c6f30@owners@@QAEXHPAMHM@Z
void owners::C_2c6f30::FUN_002c6f30(int a, float* b, int c, float d) {
    float* p = arr[c] + a * 2;
    p[0] = (b[0] - p[0]) * d + p[0];
    p[1] = (b[1] - p[1]) * d + p[1];
}

namespace fn_f3d8c80d {

// 0x002c6f70 FUN_002c6f70 (254 B): equivalent/0x002c6f70.cpp
// sym: ?blend@Object@fn_f3d8c80d@@QAEXHPBUValue_2c6f70@2@HM@Z
// STATUS: equivalent (tools/equiv.py level 3: 2978 inputs, branch coverage 0/0)
// FUN_002c6f70 @ 0x002c6f70
void Object::blend(int index, const Value_2c6f70* target, int bank, float fraction) {
 for (int i=0;i<4;++i) {
  short* destination = &values[bank][index].component[i];
  int difference = (int)target->component[i] - (int)*destination;
  if(i == 3) {
   short original = *destination;
   int delta = (int)(difference * fraction);
   *destination = (short)(original + delta);
  } else {
   int delta = (int)(difference * fraction);
   *destination = (short)(*destination + delta);
  }
 }
}

} // namespace fn_f3d8c80d

// 0x002c7070 FUN_002c7070 (167 B): matches/0x002c7070.cpp
// sym: ?FUN_002c7070@Thing_2c7070@owners@@QAEXXZ
void owners::Thing_2c7070::FUN_002c7070() {
    if (a)
        memset(a, 0, count * 12);
    if (b)
        memset(b, 0, count * 12);
    for (int i = 0; i < 4; ++i)
        if (c[i])
            memset(c[i], 0, count * 8);
    for (int j = 0; j < 2; ++j)
        if (d[j])
            memset(d[j], 0, count * 8);
}


// 0x002c7120 FUN_002c7120 (84 B): equivalent/0x002c7120.cpp
// sym: ?FUN_002c7120@ItemBuffer_2c7120@owners@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_002c7120 @ 0x002c7120
void owners::ItemBuffer_2c7120::FUN_002c7120() { if (!items) { unsigned savedCount = count; void* p = FUN_0008d6d0(savedCount * 12); if (p) FUN_00011520(p, 12, savedCount, ((char*)(void (__cdecl*)())&FUN_00011090)); items = p; flags |= 0x10; } }

namespace fn_f3d8c80d {

// 0x002c7180 FUN_002c7180 (33 B): matches/0x002c7180.cpp
// sym: ?Clear@Obj_2c7180@fn_f3d8c80d@@QAEXXZ
void Obj_2c7180::Clear() {
    thunk_FUN_00267090(ptr);
    ptr = 0;
    flags &= 0xffffffef;
}

} // namespace fn_f3d8c80d

// 0x002c71b0 FUN_002c71b0 (84 B): equivalent/0x002c71b0.cpp
// sym: ?FUN_002c71b0@Buffer_2c71b0@owners@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002c71b0 @ 0x002c71b0
void owners::Buffer_2c71b0::FUN_002c71b0() {
    if (!data) {
        unsigned n = count;
        void* p = FUN_0008d6d0(n * 12);
        if (p) FUN_00011520(p, 12, n, LAB_00011090);
        data = p;
        flags |= 0x20;
    }
}

namespace fn_f3d8c80d {

// 0x002c7210 FUN_002c7210 (33 B): matches/0x002c7210.cpp
// sym: ?FUN_002c7210@fn_f3d8c80d@@YIXPAVObj_2c7210@1@@Z
void __fastcall FUN_002c7210(Obj_2c7210* self) {
    cleanup(self->value);
    self->value = 0;
    self->flags &= ~0x20u;
}

} // namespace fn_f3d8c80d

// 0x002c7240 FUN_002c7240 (89 B): matches/0x002c7240.cpp
// sym: ?FUN_002c7240@Obj_2c7240@owners@@QAEXH@Z
void owners::Obj_2c7240::FUN_002c7240(int index) {
    if (entries[index] == 0) {
        int n = count;
        void* p = Alloc(n * 8);
        if (p)
            Init(p, 8, n, (const float*)((hulk_intptr)(void (__cdecl*)())&FUN_000c7920));
        else
            p = 0;
        entries[index] = p;
        flags |= 1 << index;
    }
}


// 0x002c72e0 FUN_002c72e0 (92 B): equivalent/0x002c72e0.cpp
// sym: ?FUN_002c72e0@Object_2c72e0@owners@@QAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// FUN_002c72e0 @ 0x002c72e0
void owners::Object_2c72e0::FUN_002c72e0(int index) {
    if (!entries[index]) {
        int n = count;
        int* block = (int*)FUN_0008d6d0(n * 8 + 4);
        void* data = 0;
        if (block) {
            *block = n;
            data = block + 1;
            FUN_00011520(data, 8, n, FUN_002c6d30);
        }
        entries[index] = data;
        flags |= 0x40u << (index & 31);
    }
}

namespace fn_f3d8c80d {

// 0x002c7340 FUN_002c7340 (772 B): equivalent/0x002c7340.cpp
// sym: ?FUN_002c7340@MeshBuffers_2c7340@fn_f3d8c80d@@QAEXIII@Z
// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 52/52)
// FUN_002c7340 @ 0x002c7340
void MeshBuffers_2c7340::FUN_002c7340(unsigned int flags, unsigned int n, unsigned int indexCount)
{
    if (indexCount != 0)
        indices = (unsigned short *)FUN_0008d6d0(indexCount * 2);

    if (flags & 0x2000) {
        V3_2c7340 *p = (V3_2c7340 *)FUN_0008d6d0(n * 12);
        if (p)
            FUN_00011520(p, 12, n, &V3_2c7340::FUN_00011090);
        else
            p = 0;
        vec18 = p;
    }
    if (flags & 0x10) {
        V3_2c7340 *p = (V3_2c7340 *)FUN_0008d6d0(n * 12);
        if (p)
            FUN_00011520(p, 12, n, &V3_2c7340::FUN_00011090);
        else
            p = 0;
        vec1c = p;
    }
    if (flags & 0x800) {
        V3_2c7340 *p = (V3_2c7340 *)FUN_0008d6d0(n * 12);
        if (p)
            FUN_00011520(p, 12, n, &V3_2c7340::FUN_00011090);
        else
            p = 0;
        vec28 = p;
    }
    if (flags & 0x1000) {
        V3_2c7340 *p = (V3_2c7340 *)FUN_0008d6d0(n * 12);
        if (p)
            FUN_00011520(p, 12, n, &V3_2c7340::FUN_00011090);
        else
            p = 0;
        vec30 = p;
    }

    unsigned int uvCount = flags & 0xf;
    for (unsigned int k = 0; k < 4; k++) {
        uv[k] = 0;
        if (k < uvCount)
            uv[k] = (float *)FUN_0008d6d0(n * 8);
    }

    unsigned int colorCount = (flags >> 15) & 7;
    for (unsigned int k = 0; k < 2; k++) {
        color[k] = 0;
        if (k < colorCount)
            color[k] = (float *)FUN_0008d6d0(n * 4);
    }
    if (color[0] == 0 && (flags & 0x20))
        color[0] = (float *)FUN_0008d6d0(n * 4);

    if (flags & 0x80)
        raw50 = (float *)FUN_0008d6d0(n * 4);

    if (flags & 0x100) {
        vec54 = (V3_2c7340 *)FUN_0008d6d0(n * 12);
        for (unsigned int i = 0; i < n; i++) {
            vec54[i].x = 1.0f;
            vec54[i].y = 0.0f;
            vec54[i].z = 0.0f;
        }
    }

    if ((flags & 0x80) || (flags & 0x100)) {
        raw20 = (float *)FUN_0008d6d0(n * 12);
        if (flags & 0x10)
            raw24 = (float *)FUN_0008d6d0(n * 12);
        if (flags & 0x800)
            raw2c = (float *)FUN_0008d6d0(n * 12);
        if (flags & 0x1000)
            raw34 = (float *)FUN_0008d6d0(n * 12);
    }
}


// 0x002c7690 FUN_002c7690 (893 B): equivalent/0x002c7690.cpp
// sym: ?FUN_002c7690@fn_f3d8c80d@@YAXPAUMesh@1@PAUVertexSink@1@D@Z
// STATUS: equivalent (tools/equiv.py level 3: 113 inputs, branch coverage 46/46)
// FUN_002c7690 @ 0x002c7690
// Emit every indexed vertex of a mesh; the mesh arrives in eax, the sink in esi.
// equiv-conv: FUN_002c7690 eax esi stack
void FUN_002c7690(Mesh *m, VertexSink *out, char useB)
{
    unsigned int count = m->count;
    unsigned short *index = m->index;
    V3 *pos;
    V3 *nrm;
    if (useB == 1) {
        pos = m->posB;
        nrm = m->nrmB;
    } else {
        pos = m->posA;
        nrm = m->nrmA;
    }
    int *color0 = m->color0;
    int *color1 = m->color1;
    UV *uv0 = m->uv0;
    UV *uv1 = m->uv1;
    UV *uv2 = m->uv2;
    UV *uv3 = m->uv3;
    unsigned int sel = (m->flags & 0xfffc7fff) - 0x2001;
    unsigned int i;

    if (sel == 0x1f) {
        for (i = 0; i < count; i++) {
            unsigned int v = index[i];
            int c = color0[v];
            *(V3i *)out->pos = *(V3i *)&pos[v];
            *out->color = c;
            out->FUN_0008ef00();
        }
        return;
    }
    if (sel == 0xf) {
        for (i = 0; i < count; i++) {
            unsigned int v = index[i];
            *(V3i *)out->pos = *(V3i *)&pos[v];
            *(V3i *)out->normal = *(V3i *)&nrm[v];
            out->FUN_0008ef00();
        }
        return;
    }
    if (sel == 0) {
        if (count != 0) {
            unsigned int v = index[0];
            *(V3i *)out->pos = *(V3i *)&pos[v];
            *(UVi *)out->tex = *(UVi *)&uv0[v];
            out->FUN_0008ef00();
        }
        for (i = 0; i < count; i++) {
            unsigned int v = index[i];
            out->FUN_000c7940(&pos[v], color0[v], &uv0[v]);
        }
        return;
    }
    if (sel == 0x20) {
        for (i = 0; i < count; i++) {
            unsigned int v = index[i];
            out->FUN_000c7940(&pos[v], color0[v], &uv0[v]);
        }
        return;
    }
    if (sel == 0x10) {
        for (i = 0; i < count; i++) {
            unsigned int v = index[i];
            *(V3i *)out->pos = *(V3i *)&pos[v];
            *(V3i *)out->normal = *(V3i *)&nrm[v];
            *(UVi *)out->tex = *(UVi *)&uv0[v];
            out->FUN_0008ef00();
        }
        return;
    }
    // Generic path. index[i] is re-read for every attribute: the sink's arrays may
    // overlap the index array, and the original reloads it after each store.
    for (i = 0; i < count; i++) {
        if (nrm != 0) {
            V3 *s = &nrm[index[i]];
            float z = s->z;
            float y = s->y;
            *(int *)&out->normal->x = *(int *)&s->x;
            out->normal->y = y;
            out->normal->z = z;
        }
        if (color0 != 0)
            out->color[0] = color0[index[i]];
        if (color1 != 0)
            out->color[1] = color1[index[i]];
        if (uv0 != 0) {
            UV *s = &uv0[index[i]];
            float t = s->v;
            *(int *)&out->tex[0].u = *(int *)&s->u;
            out->tex[0].v = t;
        }
        if (uv1 != 0) {
            UV *s = &uv1[index[i]];
            float t = s->v;
            *(int *)&out->tex[1].u = *(int *)&s->u;
            out->tex[1].v = t;
        }
        if (uv2 != 0) {
            UV *s = &uv2[index[i]];
            float t = s->v;
            *(int *)&out->tex[2].u = *(int *)&s->u;
            out->tex[2].v = t;
        }
        if (uv3 != 0) {
            UV *s = &uv3[index[i]];
            float t = s->v;
            *(int *)&out->tex[3].u = *(int *)&s->u;
            out->tex[3].v = t;
        }
        {
            V3 *s = &pos[index[i]];
            float z = s->z;
            float y = s->y;
            *(int *)&out->pos->x = *(int *)&s->x;
            out->pos->y = y;
            out->pos->z = z;
        }
        out->FUN_0008ef00();
    }
}


// 0x002c7a50 FUN_002c7a50 (943 B): equivalent/0x002c7a50.cpp
// sym: ?FUN_002c7a50@fn_f3d8c80d@@YAXEPAUSource_2c7a50@1@PAUEmitter_2c7a50@1@@Z
// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 46/46)
// FUN_002c7a50 @ 0x002c7a50
// equiv-conv: FUN_002c7a50 ecx eax esi
void FUN_002c7a50(unsigned char alt, Source_2c7a50* src, Emitter_2c7a50* out)
{
    unsigned int n = src->count;
    Vec3_2c7a50* pos;
    Vec3_2c7a50* nrm;
    if (alt == 1) {
        pos = src->altPos;
        nrm = src->altNormal;
    } else {
        pos = src->pos;
        nrm = src->normal;
    }
    float* uv3 = src->uv3;
    int* c8 = src->color0;
    int* c4 = src->color1;
    float* u0 = src->uv0;
    float* u1 = src->uv1;
    float* u2 = src->uv2;
    unsigned int fmt = src->format;
    fmt = fmt & 0xfffc7fff;

    if (fmt == 0x2020) {
        for (unsigned int i = 0; i < n; i++) {
            int* v = (int*)out->pos;
            int px = ((int*)&pos[i])[0];
            int col = c8[i];
            v[0] = px;
            v[1] = ((int*)&pos[i])[1];
            v[2] = ((int*)&pos[i])[2];
            out->color[0] = col;
            out->FUN_0008ef00();
        }
    } else if (fmt == 0x2010) {
        for (unsigned int i = 0; i < n; i++) {
            int* v = (int*)out->pos;
            v[0] = ((int*)&pos[i])[0];
            v[1] = ((int*)&pos[i])[1];
            v[2] = ((int*)&pos[i])[2];
            int* nv = (int*)out->normal;
            nv[0] = ((int*)&nrm[i])[0];
            nv[1] = ((int*)&nrm[i])[1];
            nv[2] = ((int*)&nrm[i])[2];
            out->FUN_0008ef00();
        }
    } else if (fmt == 0x2011) {
        for (unsigned int i = 0; i < n; i++) {
            int* v = (int*)out->pos;
            v[0] = ((int*)&pos[i])[0];
            v[1] = ((int*)&pos[i])[1];
            v[2] = ((int*)&pos[i])[2];
            int* nv = (int*)out->normal;
            nv[0] = ((int*)&nrm[i])[0];
            nv[1] = ((int*)&nrm[i])[1];
            nv[2] = ((int*)&nrm[i])[2];
            int* uv = (int*)out->uv;
            uv[0] = ((int*)&u0[i * 2])[0];
            uv[1] = ((int*)&u0[i * 2])[1];
            out->FUN_0008ef00();
        }
    } else if (fmt == 0x2001 || fmt == 0x2021) {
        if (n == 0)
            return;
        if (fmt == 0x2001) {
            int* v = (int*)out->pos;
            v[0] = ((int*)&pos[0])[0];
            v[1] = ((int*)&pos[0])[1];
            v[2] = ((int*)&pos[0])[2];
            int* uv = (int*)out->uv;
            uv[0] = ((int*)u0)[0];
            uv[1] = ((int*)u0)[1];
            out->FUN_0008ef00();
        }
        for (unsigned int i = 0; i < n; i++)
            out->FUN_000c7940(&pos[i], c8[i], &u0[i * 2]);
    } else {
        for (unsigned int i = 0; i < n; i++) {
            if (nrm) {
                float ny = nrm[i].y;
                float nz = nrm[i].z;
                int nx = ((int*)&nrm[i])[0];
                ((int*)out->normal)[0] = nx;
                out->normal->y = ny;
                out->normal->z = nz;
            }
            if (c8)
                out->color[0] = c8[i];
            if (c4)
                out->color[1] = c4[i];
            if (u0) {
                float uy = u0[i * 2 + 1];
                int ux = ((int*)&u0[i * 2])[0];
                ((int*)out->uv)[0] = ux;
                out->uv[1] = uy;
            }
            if (u1) {
                float uy = u1[i * 2 + 1];
                int ux = ((int*)&u1[i * 2])[0];
                ((int*)out->uv)[2] = ux;
                out->uv[3] = uy;
            }
            if (u2) {
                float uy = u2[i * 2 + 1];
                int ux = ((int*)&u2[i * 2])[0];
                ((int*)out->uv)[4] = ux;
                out->uv[5] = uy;
            }
            if (uv3) {
                float uy = uv3[i * 2 + 1];
                int ux = ((int*)&uv3[i * 2])[0];
                ((int*)out->uv)[6] = ux;
                out->uv[7] = uy;
            }
            float pz = pos[i].z;
            float py = pos[i].y;
            int px = ((int*)&pos[i])[0];
            ((int*)out->pos)[0] = px;
            out->pos->y = py;
            out->pos->z = pz;
            out->FUN_0008ef00();
        }
    }
}


// 0x002c7e40 FUN_002c7e40 (681 B): equivalent/0x002c7e40.cpp
// sym: _FUN_002c7e40
// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 46/46)
// FUN_002c7e40 @ 0x002c7e40
// batch arrives in eax, mode in cl, renderer in esi.
// equiv-conv: FUN_002c7e40 eax ecx esi
extern "C" void FUN_002c7e40(Batch_2c7e40 *s, char mode, Renderer_2c7e40 *r)
{
    unsigned int n = s->count;
    unsigned short *idx = s->indices;
    V3_2c7e40 *p0;
    V3_2c7e40 *p1;
    V3_2c7e40 *p2;
    V3_2c7e40 *q;
    unsigned int *colors[2];
    V2_2c7e40 *uvs[4];
    unsigned int i;

    if (mode == 1) {
        p0 = s->pos0b;
        p2 = s->pos2b;
        p1 = s->pos1b;
        q = s->extraB;
    } else {
        p0 = s->pos0;
        p1 = s->pos1;
        p2 = s->pos2;
        q = s->extra;
    }
    colors[0] = s->col0;
    colors[1] = s->col1;
    uvs[0] = s->uv0;
    uvs[1] = s->uv1;
    uvs[2] = s->uv2;
    uvs[3] = s->uv3;

    switch (s->flags & 0xfffc7fff) {
    case 0x2020:
        for (i = 0; i < n; i++)
            r->vfunc_16(&p0[idx[i]], colors[0][idx[i]]);
        return;
    case 0x2010:
        for (i = 0; i < n; i++)
            r->vfunc_15(&p0[idx[i]], &p1[idx[i]]);
        return;
    case 0x2001:
        if (n > 0)
            r->vfunc_14(&p0[idx[0]], &uvs[0][idx[0]]);
        for (i = 0; i < n; i++)
            r->vfunc_13(&p0[idx[i]], colors[0][idx[i]], &uvs[0][idx[i]]);
        return;
    case 0x2021:
        for (i = 0; i < n; i++)
            r->vfunc_13(&p0[idx[i]], colors[0][idx[i]], &uvs[0][idx[i]]);
        return;
    case 0x2011:
        for (i = 0; i < n; i++)
            r->vfunc_12(&p0[idx[i]], &p1[idx[i]], &uvs[0][idx[i]]);
        return;
    default:
        for (i = 0; i < n; i++) {
            if (p1)
                r->vfunc_1(p1[idx[i]]);
            if (p2)
                r->vfunc_2(p2[idx[i]]);
            if (q)
                r->vfunc_3(q[idx[i]]);
            for (unsigned int j = 0; j < 2; j++) {
                if (colors[j])
                    r->vfunc_4(colors[j][idx[i]], j);
            }
            for (unsigned int j = 0; j < 4; j++) {
                if (uvs[j])
                    r->vfunc_6(uvs[j][idx[i]], j);
            }
            r->vfunc_0(p0[idx[i]]);
        }
        return;
    }
}


// 0x002c8130 FUN_002c8130 (719 B): equivalent/0x002c8130.cpp
// sym: _FUN_002c8130
// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 46/46)
// FUN_002c8130 @ 0x002c8130
// equiv-conv: FUN_002c8130 ecx eax esi
extern "C" void FUN_002c8130(unsigned char flag, Desc_2c8130 *d, Dev_2c8130 *dev)
{
    unsigned n = d->count;
    const int *a, *b, *c, *e;
    if (flag == 1) {
        c = d->p2c;
        b = d->p24;
        a = d->p20;
        e = d->p34;
    } else {
        b = d->p1c;
        a = d->p18;
        c = d->p28;
        e = d->p30;
    }
    const int *uv0 = d->uv[0];
    const int *uv1 = d->uv[1];
    const int *vtx[4];
    vtx[0] = d->vtx[0];
    vtx[1] = d->vtx[1];
    vtx[2] = d->vtx[2];
    vtx[3] = d->vtx[3];
    unsigned t = (d->type & 0xfffc7fffu) - 0x2001u;
    if (t == 31) {
        if (n == 0)
            return;
        for (unsigned i = 0; i < n; i++)
            dev->v16(a + 3 * i, uv0[i]);
        return;
    }
    if (t == 15) {
        if (n == 0)
            return;
        for (unsigned i = 0; i < n; i++)
            dev->v15(a + 3 * i, b + 3 * i);
        return;
    }
    if (t == 0 || t == 32) {
        if (n == 0)
            return;
        if (t == 0) {
            dev->v14(a, vtx[0]);
            if (n == 0)
                return;
        }
        for (unsigned i = 0; i < n; i++)
            dev->v13(a + 3 * i, uv0[i], vtx[0] + 2 * i);
        return;
    }
    if (t == 16) {
        if (n == 0)
            return;
        for (unsigned i = 0; i < n; i++)
            dev->v12(a + 3 * i, b + 3 * i, vtx[0] + 2 * i);
        return;
    }
    for (unsigned i = 0; i < n; i++) {
        if (b != 0)
            dev->v1(b[3 * i], b[3 * i + 1], b[3 * i + 2]);
        if (c != 0)
            dev->v2(c[3 * i], c[3 * i + 1], c[3 * i + 2]);
        if (e != 0)
            dev->v3(e[3 * i], e[3 * i + 1], e[3 * i + 2]);
        for (unsigned k = 0; k < 2; k++) {
            const int *u = k == 0 ? uv0 : uv1;
            if (u != 0)
                dev->v4(u[i], k);
        }
        for (unsigned k = 0; k < 4; k++) {
            if (vtx[k] != 0)
                dev->v6(vtx[k][2 * i], vtx[k][2 * i + 1], k);
        }
        dev->v0(a[3 * i], a[3 * i + 1], a[3 * i + 2]);
    }
}


// 0x002c8460 FUN_002c8460 (50 B): matches/0x002c8460.cpp
// sym: ??0VertexOffsetList@fn_f3d8c80d@@QAE@H@Z
VertexOffsetList::VertexOffsetList(int value) {
    a1 = 0;
    vptr = (void*)((hulk_intptr)DAT_0042efb0);
    a2 = 0;
    a3 = value;
    a4 = 0;
    a5 = 0;
    a6 = 0;
    a7 = 0;
    a8 = 0;
    a9 = 0;
    a10 = 0;
    a11 = 0;
}


// 0x002c84a0 FUN_002c84a0 (419 B): equivalent/0x002c84a0.cpp
// sym: ??0VertexOffsetList@pure3d@fn_f3d8c80d@@QAE@ABU012@@Z
// STATUS: equivalent (tools/equiv.py level 3: 21 inputs, branch coverage 18/18)
// FUN_002c84a0 @ 0x002c84a0
namespace pure3d {
VertexOffsetList::VertexOffsetList(const VertexOffsetList& source) {
 refs=0;
 flags=source.flags;
 count=source.count;
 positions=0; normals=0;
 if(source.positions) {
  FUN_002c7120();
  unsigned int n=(count*12u)>>2;
  unsigned int* dst=positions; const unsigned int* src=source.positions;
  for(unsigned int j=0;j<n;++j) dst[j]=src[j];
 }
 if(source.normals) {
  FUN_002c71b0();
  unsigned int n=(count*12u)>>2;
  unsigned int* dst=normals; const unsigned int* src=source.normals;
  for(unsigned int j=0;j<n;++j) dst[j]=src[j];
 }
 for(unsigned int i=0;i<4;++i) {
  texcoords[i]=0;
  if(source.texcoords[i]) {
   texcoords[i]=(unsigned int*)FUN_0008d6d0(count*8u);
   flags |= 1u<<i;
   unsigned int n=(count*8u)>>2;
   unsigned int* dst=texcoords[i]; const unsigned int* src=source.texcoords[i];
   for(unsigned int j=0;j<n;++j) dst[j]=src[j];
  }
 }
 for(unsigned int i=0;i<2;++i) {
  packed[i]=0;
  if(source.packed[i]) {
   unsigned int savedCount=count;
   unsigned int* allocation=(unsigned int*)FUN_0008d6d0(savedCount*8u+4u);
   unsigned int* data=0;
   if(allocation) {
    allocation[0]=savedCount;
    data=allocation+1;
    if((int)(savedCount-1u)>=0) {
     unsigned short* p=(unsigned short*)data;
     for(unsigned int j=0;j<savedCount;++j) {
      p[0]=0;p[1]=0;p[2]=0;p[3]=0;p+=4;
     }
    }
   }
   packed[i]=data;
   flags |= 0x40u<<i;
   unsigned int n=(count*8u)>>2;
   unsigned int* dst=packed[i]; const unsigned int* src=source.packed[i];
   for(unsigned int j=0;j<n;++j) dst[j]=src[j];
  }
 }
}
}


// 0x002c86d0 FUN_002c86d0 (89 B): matches/0x002c86d0.cpp
// sym: ??0VertexList@fn_f3d8c80d@@QAE@HHH@Z
VertexList::VertexList(int p2, int p3, int p4) {
    b = p2;
    a = 0;
    vptr = ((hulk_intptr)DAT_0042efc0);
    c = p3;
    d = p4;
    e[0] = 0;
    e[1] = 0;
    e[2] = 0;
    e[3] = 0;
    e[4] = 0;
    e[5] = 0;
    e[6] = 0;
    e[7] = 0;
    e[8] = 0;
    pad[3] = 0;
    pad[4] = 0;
    pad[5] = 0;
    init(p2, p3, p4);
}


// 0x002c8730 FUN_002c8730 (640 B): equivalent/0x002c8730.cpp
// sym: ??0VertexList@pure3d@fn_f3d8c80d@@QAE@ABU012@@Z
// STATUS: equivalent (tools/equiv.py level 3: 41 inputs, branch coverage 30/30)
// FUN_002c8730 @ 0x002c8730
namespace pure3d {
VertexList::VertexList(const VertexList& source) {
 state=0; format=source.format; count=source.count; flags=source.flags;
 for(unsigned i=0;i<18;++i) streams[i]=0;
 FUN_002c7340(format,count,flags);
 for(unsigned i=0;i<17;++i) {
  unsigned char* dest=(unsigned char*)streams[i];
  if(dest) {
   const unsigned char* src=(const unsigned char*)source.streams[i];
   unsigned size;
   if(i==0) size=count*2;
   else if(i<9 || i==16) size=count*12;
   else if(i<13) size=count*8;
   else size=count*4;
   unsigned words=size/4;
   for(unsigned j=0;j<words;++j) ((unsigned*)dest)[j]=((const unsigned*)src)[j];
   for(unsigned k=words*4;k<size;++k) dest[k]=src[k];
  }
 }
}
}

} // namespace fn_f3d8c80d
