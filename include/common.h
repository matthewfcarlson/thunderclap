// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
#ifndef TREE_COMMON_H
#define TREE_COMMON_H
#ifndef TREE_TU_BEGIN
#define TREE_TU_BEGIN
#define TREE_TU_END
#endif
#include "compat/ptr.h"
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl acos(double);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl asin(double);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif
extern "C" int __cdecl _isnan(double);
TREE_TU_BEGIN
typedef unsigned int uint;
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double cos(double);
#endif
TREE_TU_BEGIN
struct Item;
struct Z;
hulk_freg __cdecl FUN_000964e0();
struct V3i {
    int x, y, z;
};
struct Node;
struct Ctor_00232660 {
    Ctor_00232660();
};
struct Owner;
extern const int type_animation;
extern const int type_refcount;
extern void* g_vA[];
extern void* g_vB[];
extern void* g_base_vftable[];
TREE_TU_END
#ifdef TREE_LOCAL_pure3d
TREE_TU_BEGIN
#endif
namespace pure3d {
class Animation;
}
#ifdef TREE_LOCAL_pure3d
TREE_TU_END
#endif
TREE_TU_BEGIN
class Owner;
TREE_TU_END
#ifdef TREE_LOCAL_pure3d
TREE_TU_BEGIN
#endif
namespace pure3d {
class Shader;
}
#ifdef TREE_LOCAL_pure3d
TREE_TU_END
#endif
/* size_t: tree_prelude.h */
TREE_TU_BEGIN
union AbsFloat {
    float f;
    unsigned int bits;
};
typedef unsigned char u8;
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int strcmp(const char*, const char*);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl _stricmp(const char *a, const char *b);
#endif
TREE_TU_BEGIN
struct Request;
struct Object;
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double fabs(double);
#endif
TREE_TU_BEGIN
extern void* refcount_vftable[];
void __cdecl SweepTrack_DeleteThis(void* p);
TREE_TU_END
#ifdef TREE_LOCAL_CSPHulkProp
TREE_TU_BEGIN
#endif
class CSPHulkProp;
#ifdef TREE_LOCAL_CSPHulkProp
TREE_TU_END
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" long __cdecl atol(const char*);
#endif
#ifdef TREE_LOCAL_pure3d
TREE_TU_BEGIN
#endif
namespace pure3d {
class DrawableHierarchy;
}
#ifdef TREE_LOCAL_pure3d
TREE_TU_END
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl floor(double);
#endif
TREE_TU_BEGIN
extern void vt_name();
extern void vt_cond();
extern int smart_vftable;
extern int gTypeB;
struct TypeInfo {
    int x;
};
struct InitHelper {
    void init();
};
struct TrackImpl {
    int m0;
    int m1;
};
void thunk_delete(void*);
class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
struct ParamRegistry {
};
extern void* vA[];
class Track;
class __declspec(novtable) ParamConditionGroupBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00235220(const char* name);
    ParamConditionGroupBase(const char* name) { FUN_00235220(name); }
};
template <class T>
class ParamConditionGroup : public ParamConditionGroupBase {
public:
    ParamConditionGroup(const char* name, void (T::*s)()) : ParamConditionGroupBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
template <class T>
class ParamVector : public ParamVectorBase {
public:
    ParamVector(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class __declspec(novtable) ParamStringBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002349e0(const char* name);
    ParamStringBase(const char* name) { FUN_002349e0(name); }
};
struct ThisCall_00230b60 {
};
extern "C" void __cdecl FUN_00066a00();
extern "C" char DAT_003f98d0[];
extern "C" char DAT_003fbb34[];
extern void* g_vt2[];
extern void* CTrack_vftable[];
extern int hit_vftable;
extern int shakeVtable;
struct Jump {
    hulk_intptr construct();
};
extern "C" void* __cdecl alloc_54(unsigned int);
hulk_uintptr __fastcall construct_camera(void*);
extern "C" int __cdecl FUN_000113e0(int, int);
struct Matrix;
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double tan(double);
#endif
TREE_TU_BEGIN
union FloatBits {
    float f;
    unsigned int u;
};
extern void __cdecl thunk_FUN_00270a50();
extern "C" void __cdecl FUN_001bb0b0(const char*);
struct Stream;
TREE_TU_END
extern "C" int __cdecl _isspace(int);
TREE_TU_BEGIN
extern "C" char DAT_0040449c[];
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strcpy(char*, const char*);
#endif
TREE_TU_BEGIN
extern "C" char DAT_004044a4[];
extern "C" char DAT_00404b3c[];
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl exp(double);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double atan(double);
#endif
extern "C" int __isnan(double);
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double atan2(double y, double x);
#endif
TREE_TU_BEGIN
extern void* gameVtable;
extern "C" void FUN_000fc300();
extern "C" void __cdecl FUN_00087990();
extern void* v0[];
TREE_TU_END
#ifdef TREE_LOCAL_pure3d
TREE_TU_BEGIN
#endif
namespace pure3d {
class CompositeDrawable;
}
#ifdef TREE_LOCAL_pure3d
TREE_TU_END
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strchr(const char*, int);
#endif
#ifdef TREE_LOCAL_pure3d
TREE_TU_BEGIN
#endif
namespace pure3d {
class Texture;
}
#ifdef TREE_LOCAL_pure3d
TREE_TU_END
#endif
TREE_TU_BEGIN
extern char DAT_0049fd74[];
extern char DAT_0049fd9c[];
typedef unsigned char byte;
extern int CEffectStopTrack_vftable;
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl malloc(unsigned int);
#endif
TREE_TU_BEGIN
extern int rawVtable;
class CRawScript {
  public:
    int* vptr;
    char pad[12];
    int mArg;
    void finish();
    void run();
};
extern int desc1, desc2;
typedef unsigned short wchar16;
extern int __cdecl IsType(void*, int, const void*, const void*, int);
struct Ctx;
struct Entity_0027b070 {
    Entity_0027b070();
};
void postInit();
extern "C" void* AllocMem(hulk_uintptr);
struct TypeDescriptor;
extern "C" char DAT_0040dc14[];
TREE_TU_END
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
TREE_TU_BEGIN
class __declspec(novtable) ParamEnumBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumBase(const char* name) { FUN_00234cc0(name); }
};
extern int RTTI_Type1;
extern int RTTI_Type2;
extern int AIHistoryNameCondition_vftable;
class RefCounted {
public:
    virtual void AddRef();
    virtual void Release();
};
extern "C" void __fastcall BaseDtor(void* p);
extern "C" void operator_delete(void* p);
extern int IsKindOf(void*, int, int*, int*, int);
void __cdecl Cleanup(int);
extern "C" void __cdecl ai_free(void* p);
extern "C" void __cdecl ai_delete(void* p);
struct VFT {
    int x;
};
extern const VFT PathLocatorTestCondition_vftable;
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double pow(double, double);
#endif
TREE_TU_BEGIN
extern int IsType(void*, int, int*, int*, int);
extern int TypeCheck(void*, int, const void*, const void*, int);
extern "C" void* __cdecl DynCast(void*, int, void*, void*, int);
class Ender {
  public:
    void Finish();
};
extern "C" void* __cdecl DynamicCast(void*, int, void*, void*, int);
template <class T>
class ParamString : public ParamStringBase {
public:
    ParamString(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class PartA {
  public:
    PartA();
    char pad[12];
};
class PartB {
  public:
    PartB();
};
extern char vt[];
extern void __cdecl ReleaseSelf(void*);
struct Entity;
extern "C" void* allocMem(hulk_uintptr);
struct Source;
typedef unsigned short ushort;
struct Surface;
typedef unsigned short u16;
extern void* g_s[];
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char *strcat(char *, const char *);
#endif
TREE_TU_BEGIN
extern "C" char* strncat(char* dst, const char* src, unsigned int n);
struct Handle;
struct List;
void __cdecl FreeArray(void*);
extern "C" int __cdecl FUN_002381a0(int, int);
extern void* RestPoseVtable;
extern void* vIRef[];
struct Reader;
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int isdigit(int c);
#endif
TREE_TU_BEGIN
extern "C" char DAT_0042918c[];
TREE_TU_END
extern "C" int __cdecl _vsnprintf(char*, unsigned int, const char*, char*);
TREE_TU_BEGIN
extern "C" unsigned __cdecl FUN_0025e2b0(void *);
extern "C" char DAT_00429434[];
extern void __cdecl Cleanup(void*, void*);
typedef unsigned char uchar;
struct Group;
struct Pool;
extern void* vB[];
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double fmod(double x, double y);
#endif
TREE_TU_BEGIN
extern "C" void __cdecl FUN_0026d7a0(void*);
extern "C" char DAT_0042af64[];
extern "C" char DAT_0042afa8[];
extern "C" char DAT_0042b3a4[];
extern "C" void __stdcall thunk_FUN_003eac33(int, void*);
extern "C" void __cdecl FUN_0026d820(void *);
extern "C" void __cdecl FUN_0026d6d0(int);
extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b99c[];
struct File;
extern "C" char DAT_0042c1b4[];
extern void __fastcall ElemCtor(void*);
extern void* scenegraph_vftable;
extern void __cdecl f(int, int);
extern void* vD[];
void Rot(unsigned* a, unsigned* b, unsigned* c, int d, int e);
TREE_TU_END
#endif
