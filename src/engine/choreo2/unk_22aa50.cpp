// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0022aa50..0x0022b080 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/choreo2.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f986a29e {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f986a29e {} using namespace fn_f986a29e;
#include "engine/choreo2.h"

// ---- declarations shared by the functions below
namespace fn_f986a29e {
struct LocomotionDriver {
    void* vf;
    char pad[0x1c];
    int a;
    int b;
    void InitA_00222590(LocomotionDriver*);
    void InitB_00222460(LocomotionDriver*);
    LocomotionDriver* Copy(LocomotionDriver*);
};
struct Pair_22aaa0 { unsigned a,b; };
struct Source_22aaa0 { char pad[16]; float scale; char pad2[12]; float fallback; float FUN_00288de0(unsigned,unsigned,unsigned,unsigned); };
float __cdecl FUN_0004af40(float,float,float);
struct Vector3_22aca0 { float x,y,z; };
struct Random_22aca0 {
 unsigned int seed1,seed2;
 Vector3_22aca0* FUN_0022aca0(Vector3_22aca0* result);
};
struct Object {  void FUN_0022add0(float *out); };
struct V3_22ae20 {
    float x, y, z;
};
union FloatBits_22ae20 {
    float f;
    unsigned int u;
};
struct Rng_22ae20 {
    unsigned int s0;
    unsigned int s1;

    float Next()
    {
        s0 = (s0 & 0xffff) * 0x9069 + (s0 >> 16);
        s1 = (s1 & 0xffff) * 0x4650 + (s1 >> 16);
        unsigned int r = (s0 << 16) + (s1 & 0xffff);
        FloatBits_22ae20 m;
        m.u = (r & 0x7fffff) | 0x3f800000;
        FloatBits_22ae20 v;
        v.f = m.f - 1.0f;
        v.u |= r & 0x80000000;
        return v.f;
    }

    void FUN_0022ae20(V3_22ae20 *out);
};


// 0x0022aa50 FUN_0022aa50 (73 B): matches/0x0022aa50.cpp
// sym: ?Copy@LocomotionDriver@fn_f986a29e@@QAEPAU12@PAU12@@Z
// data: gCount_22aa50 = DAT_004e5ac4
LocomotionDriver* LocomotionDriver::Copy(LocomotionDriver* src) {
    InitA_00222590(src);
    vf = (void*)((hulk_intptr)DAT_00427534);
    InitB_00222460(src);
    a = src->a;
    b = src->b;
    ++(*(int*)&DAT_004e5ac4);
    if ((*(int*)&DAT_004e5ac4) > (*(int*)&DAT_004e5ac8))
        (*(int*)&DAT_004e5ac8) = (*(int*)&DAT_004e5ac4);
    return this;
}


// 0x0022aaa0 FUN_0022aaa0 (241 B): equivalent/0x0022aaa0.cpp
// sym: _FUN_0022aaa0 @5d2a1c8a2871 @w89a5085878b4
// STATUS: equivalent (tools/equiv.py level 3: 312 inputs, branch coverage 9/10, incomplete)
// FUN_0022aaa0 @ 0x0022aaa0
extern "C" float __cdecl FUN_0022aaa0(Pair_22aaa0* entries, Source_22aaa0* source) {
 if (!entries || !(entries[0].a | entries[0].b)) return source->fallback;
 float t=(source->scale-1.0f)*0.5f;
 float result=source->FUN_00288de0(0,0,entries[0].a,entries[0].b);
 unsigned n=1;
 unsigned a=entries[n].a, b=entries[n].b;
 if (a|b) {
  float negative=-t;
  do {
   float sample=source->FUN_00288de0(n&1,0,a,b);
   ++n;
   float weight=1.0f/(double)n;
   float delta=sample-result;
   float adjusted=FUN_0004af40(negative,t,delta);
   a=entries[n].a; b=entries[n].b;
   result=adjusted*weight+(1.0f-weight)*result;
  } while(a|b);
 }
 return result;
}

} // namespace fn_f986a29e

// 0x0022aba0 FUN_0022aba0 (124 B): equivalent/0x0022aba0.cpp
// sym: ?FUN_0022aba0@Random_22aba0@owners@@QAEXI@Z @c2931303364c @w3762a1216013
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0022aba0 @ 0x0022aba0
void owners::Random_22aba0::FUN_0022aba0(unsigned int seed)
{
    if (seed == 0)
        seed = 0xfc7d2ba2;
    b = seed & 0xffff;
    a = (seed >> 16) * 0x9069;
    b = (b & 0xffff) * 0x4650 + (b >> 16);
    a = (a & 0xffff) * 0x9069 + (a >> 16);
    b = (b & 0xffff) * 0x4650 + (b >> 16);
}

namespace fn_f986a29e {

// 0x0022aca0 FUN_0022aca0 (299 B): equivalent/0x0022aca0.cpp
// sym: ?FUN_0022aca0@Random_22aca0@fn_f986a29e@@QAEPAUVector3_22aca0@2@PAU32@@Z @94e7cbf59e1e @wb718d0b04126
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022aca0 @ 0x0022aca0
Vector3_22aca0* Random_22aca0::FUN_0022aca0(Vector3_22aca0* result) {
 float values[3];
 for(int i=0;i<3;++i) {
  seed1 = (seed1 & 65535u)*36969u + (seed1 >> 16);
  seed2 = (seed2 & 65535u)*18000u + (seed2 >> 16);
  union { unsigned int bits; float value; } convert;
  convert.bits = (((seed1 << 16) + (seed2 & 65535u)) & 0x7fffffu) | 0x3f800000u;
  values[i] = convert.value - 1.0f;
 }
 result->x=values[0];
 result->y=values[1];
 result->z=values[2];
 return result;
}


// 0x0022add0 FUN_0022add0 (70 B): equivalent/0x0022add0.cpp
// sym: ?FUN_0022add0@Object@fn_f986a29e@@QAEXPAM@Z @79204c2d0bf8 @wcfee4d55160d
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022add0 @ 0x0022add0
void Object::FUN_0022add0(float *out) {
    float x = ((owners::RandomGen_143100 *)this)->FUN_00143100();
    float y = ((owners::RandomGen_143100 *)this)->FUN_00143100();
    float z = ((owners::RandomGen_143100 *)this)->FUN_00143100();
    out[0] = x;
    out[1] = y;
    out[2] = z;
}


// 0x0022ae20 FUN_0022ae20 (485 B): equivalent/0x0022ae20.cpp
// sym: ?FUN_0022ae20@Rng_22ae20@fn_f986a29e@@QAEXPAUV3_22ae20@2@@Z @291f85ccb17c @wfb9a19030b55
// STATUS: equivalent (tools/equiv.py level 3: 52 inputs, branch coverage 3/4, incomplete)
// FUN_0022ae20 @ 0x0022ae20
void Rng_22ae20::FUN_0022ae20(V3_22ae20 *out)
{
    V3_22ae20 v;
    float len2;
    do {
        v.x = Next();
        v.y = Next();
        v.z = Next();
        len2 = v.z * v.z + v.y * v.y + v.x * v.x;
    } while (len2 > 1.0f || len2 < 0.001f);
    double inv = 1.0 / sqrt((double)len2);
    out->x = (float)(v.x * inv);
    out->y = (float)(v.y * inv);
    out->z = (float)(v.z * inv);
}

} // namespace fn_f986a29e
