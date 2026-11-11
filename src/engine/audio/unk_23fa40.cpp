// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023fa40..0x00240c20 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/engine/content.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/om.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f2774db1 {
#define TREE_TU_END }
namespace fn_f2774db1 {} using namespace fn_f2774db1;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f2774db1 {
struct Buf {
    short count;
};
class X {
  public:
    X();
    char* ptr;
    short mode;
    short pad;
    short value;
};
extern "C++" __declspec(nothrow) void __cdecl FUN_0023fa40(char **, char *, unsigned int, int);
struct StringHeader_23fbb0 { unsigned int capacity; unsigned short references; unsigned short reserved; };
extern void __cdecl FUN_00247570(StringHeader_23fbb0*);
extern "C++" __declspec(nothrow) void __cdecl FUN_0023fa40(int *, char *, unsigned int, int);
void __cdecl FUN_00247570(void* p);
class SharedStr;
class SharedStr {
public:
    char* data;                 // 0x0
    unsigned short mode;        // 0x4
    unsigned short pad6;
    unsigned short len;         // 0x8
    SharedStr* FUN_0023fd60(char* src, int length, int newMode);
};
extern int Fmt(char* buf, int n, const char* fmt, char* va);
struct Out_23fde0 {
    int p;
    ushort flag;
    ushort pad;
    ushort len;
};
struct StringHeader_23fe50 { unsigned int capacity; unsigned short references; unsigned short reserved; };
extern void __cdecl FUN_00247570(StringHeader_23fe50*);
typedef unsigned int U_23fef0;
class Obj_23fef0 {
  public:
};
extern "C" void __cdecl CopyLike(char* buf, U_23fef0 size, hulk_uintptr v, void* p);
struct Header_23ff50 { unsigned int reserved; unsigned short references; unsigned short capacity; };
extern "C" void freebuf(void*);
} // namespace fn_f2774db1
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif
namespace fn_f2774db1 {
class Obj_240110 {
  public:
};
struct Source_240110 {
    char* data;
    char pad[4];
    unsigned short length;
};
struct StringHeader_2401f0 { unsigned int capacity; unsigned short references; unsigned short reserved; };
extern void __cdecl FUN_00247570(StringHeader_2401f0*);
struct StringHeader_240280 { unsigned int capacity; unsigned short references; unsigned short reserved; };
extern void __cdecl FUN_00247570(StringHeader_240280*);
struct String {
  public:
    char* data;
    unsigned short kind;
    char _m_pad_6[0x6];
    char* FUN_0023fbb0();
    String* ToUpper(String* out);
    void FUN_00240430(float value);
    String* Concat(String* out, float value);
    void FUN_00240500(unsigned value);
    String* Concat(String* out, unsigned value);
};
struct S_240310 {
    const char* p;
    char Eq(const S_240310& o);
};
struct Text_240430 { char *data; unsigned int flags; unsigned short length; unsigned short spare; };
struct Object {
  public:
    Object *format(float);
    Object *FUN_00240500(unsigned int value);
};
struct StringValue_240500 { char *text; unsigned int flags; unsigned short length; unsigned short padding; };
struct StringHeader_240500 { unsigned int capacity; unsigned short references; unsigned short extra; };
struct StringHeader_2405c0 { unsigned int capacity; unsigned short references; unsigned short reserved; };
extern void __cdecl FUN_00247570(StringHeader_2405c0*);
struct StringHeader_240630 { unsigned int capacity; unsigned short references; unsigned short reserved; };
extern void __cdecl FUN_00247570(StringHeader_240630*);
struct Str_2406a0 {
    char* p;
    unsigned short kind;
    char pad6[6];
    Str_2406a0* FUN_002406a0(Str_2406a0* ret, const void* rhs);
};
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
struct ThisCall_00240060 {
    void FUN_00240060();
};
extern void thunk_FUN_00267090(CCollisionAction*);
struct Obj_240760 {
};
struct Str_2407a0 {
};
struct Subsystem_2407a0 {
    virtual void init();
    char pad04[0x68 - 4];
    int handle;
};
struct EntityLoader_nv_2407a0 {
    om::EntityLoader *FUN_0024d360(Subsystem_2407a0 *sys);
};
struct Registry_2407a0 {
    void FUN_00265210(om::EntityLoader *loader, int handle);
};
extern "C" void *FUN_0008d690(unsigned int size);
} // namespace fn_f2774db1
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_f2774db1 {
Subsystem_2407a0 *FUN_00256660();
Subsystem_2407a0 *FUN_00245330();
Subsystem_2407a0 *FUN_00241660();
Subsystem_2407a0 *FUN_00255d20();
Subsystem_2407a0 *FUN_00255480();
Subsystem_2407a0 *FUN_00254e70();
Subsystem_2407a0 *FUN_00254a70();
Subsystem_2407a0 *FUN_00254640();
Subsystem_2407a0 *FUN_00253c50();
Subsystem_2407a0 *FUN_00253770();
Subsystem_2407a0 *FUN_00253390();
Subsystem_2407a0 *FUN_00252fb0();
Subsystem_2407a0 *FUN_00252b50();
Subsystem_2407a0 *FUN_002527a0();
Subsystem_2407a0 *FUN_00252370();
Subsystem_2407a0 *FUN_002518d0();
Subsystem_2407a0 *FUN_002513c0();
Subsystem_2407a0 *FUN_00250db0();
Subsystem_2407a0 *FUN_002509b0();
Subsystem_2407a0 *FUN_00250540();
Subsystem_2407a0 *FUN_002500d0();
Subsystem_2407a0 *FUN_0024fc50();
Subsystem_2407a0 *FUN_0024f810();
Subsystem_2407a0 *FUN_0024ea00();
Subsystem_2407a0 *FUN_0024e540();
extern "C" Subsystem_2407a0 *FUN_0024df00();
void *FUN_0024d200();
extern "C" om::EntityLoader *FUN_00247530(void *);
Subsystem_2407a0 *FUN_0024d5a0();
extern "C" int FUN_00242bd0();
int FUN_00267f80();
extern int __fastcall FUN_00267f80(void*);
extern "C" void __cdecl FUN_0024c060();
extern "C" void __cdecl FUN_00243090(int, float);
extern "C" void __cdecl FUN_00240f50();

} // namespace fn_f2774db1

// 0x0023fa40 FUN_0023fa40 (88 B): matches/0x0023fa40.cpp [wrapped: conflict: FUN_0023fa40]
// sym: _FUN_0023fa40
namespace fn_0023fa40 {
typedef unsigned int uint_23fa40;
typedef unsigned short ushort;
extern "C" void* FUN_00247610(const char*, const char*, int, int);
extern const char str1_23fa40[];
extern const char str2_23fa40[];

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif

extern "C" void FUN_0023fa40(char** out, char* src, unsigned int n, int len) {
    char* p = (char*)FUN_00247610(str1_23fa40, str2_23fa40, len + 9, 4);
    *out = p + 8;
    *(ushort*)(*out - 2) = (ushort)len;
    *(ushort*)(*out - 4) = 1;
    memcpy(*out, src, n);
    (*out)[n] = 0;
}
} // namespace fn_0023fa40

namespace fn_f2774db1 {

// 0x0023fac0 FUN_0023fac0 (33 B): matches/0x0023fac0.cpp
// sym: ??0X@fn_f2774db1@@QAE@XZ
// data: gData = DAT_004cc02c
X::X() {
    ptr = (*(char**)&DAT_004cc02c);
    ++((short*)(*(char**)&DAT_004cc02c))[-2];
    value = 0;
    mode = 2;
}


// 0x0023fb00 FUN_0023fb00 (16 B): matches/0x0023fb00.cpp
// sym: @FUN_0023fb00@4
// data: g_compare = DAT_004cc02c, g_zero_23fb00 = DAT_003f335c
extern "C" void* __fastcall FUN_0023fb00(void* p) {
    void* v = *(void**)p;
    if (v == (*(void**)&DAT_004cc02c))
        return ((unsigned char*)&DAT_003f335c);
    return v;
}

} // namespace fn_f2774db1

// 0x0023fb10 FUN_0023fb10 (12 B): matches/0x0023fb10.cpp
// sym: ?FUN_0023fb10@C_23fb10@owners@@QAEXG@Z
void owners::C_23fb10::FUN_0023fb10(unsigned short x) {
    value = x;
}


// 0x0023fb20 FUN_0023fb20 (82 B): matches/0x0023fb20.cpp
// sym: ?FUN_0023fb20@Obj_23fb20@owners@@QAEXPBDIIH@Z
void owners::Obj_23fb20::FUN_0023fb20(const char *a1, hulk_uintptr a2, hulk_uintptr a3, int a4) {
    a = (unsigned short)a4;
    b = (unsigned short)a2;
    if (a4 == 0) {
        value = a1;
        return;
    }
    if (a4 == 1) {
        value = a1;
        return;
    }
    FUN_0023fa40((char **)(&a1), (char *)a1, (unsigned int)a2, (unsigned int)a3);
    value = a1;
}


// 0x0023fbb0 FUN_0023fbb0 (135 B): equivalent/0x0023fbb0.cpp
// sym: ?FUN_0023fbb0@String_23fbb0@owners@@QAEPADXZ
// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 10/10)
// FUN_0023fbb0 @ 0x0023fbb0
// Makes the text private to this string (copy on write) and returns it.
char* owners::String_23fbb0::FUN_0023fbb0()
{
    int fresh;
    if (kind == 0) {
        FUN_0023fa40(&fresh, data, (int)length, length);
        data = (char*)fresh;
        return data;
    }
    StringHeader_23fbb0* header = reinterpret_cast<StringHeader_23fbb0*>(data) - 1;
    if (header->references > 1) {
        FUN_0023fa40(&fresh, data, (int)length, length);
        if (kind == 2) {
            header = reinterpret_cast<StringHeader_23fbb0*>(data) - 1;
            if (header->references == 1) {
                if (data != (*(char**)&DAT_004cc02c))
                    FUN_00247570(header);
            } else {
                --header->references;
            }
        }
        data = (char*)fresh;
    }
    return data;
}


// 0x0023fc40 FUN_0023fc40 (80 B): equivalent/0x0023fc40.cpp
// sym: ?FUN_0023fc40@String_23fc40@owners@@QAEPAU12@PBDH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_0023fc40 @ 0x0023fc40
owners::String_23fc40 *owners::String_23fc40::FUN_0023fc40(const char *text, int option) { if (!text) { data = (*(char**)&DAT_004cc02c); ++*(unsigned short *)((*(char**)&DAT_004cc02c) - 4); extra = 0; capacity = 2; } else { const char *end = text; while (*end) ++end; hulk_intptr length = end - text; FUN_0023fb20(text, length, length, option); } return this; }


// 0x0023fc90 FUN_0023fc90 (68 B): matches/0x0023fc90.cpp
// sym: ?FUN_0023fc90@Obj_23fc90@owners@@QAEPAU12@HHH@Z
// data: gThing_23fc90 = DAT_004cc02c
owners::Obj_23fc90* owners::Obj_23fc90::FUN_0023fc90(hulk_intptr a, int b, int c) {
    if (((int)a) == 0) {
        mPtr = (*(void**)&DAT_004cc02c);
        short* p = (short*)((char*)(*(void**)&DAT_004cc02c) - 4);
        ++*p;
        mC = 0;
        mB = 2;
    } else
        helper(((int)a), b, b, c);
    return this;
}


// 0x0023fd20 FUN_0023fd20 (49 B): matches/0x0023fd20.cpp
// sym: ?FUN_0023fd20@Thing_23fd20@owners@@QAEPAU12@H@Z
owners::Thing_23fd20* owners::Thing_23fd20::FUN_0023fd20(int arg) {
    a = 2;
    b = 0;
    FUN_0023fa40(&arg, (char *)(hulk_uintptr)(int)0, 0, arg);
    value = arg;
    return this;
}

namespace fn_f2774db1 {

// 0x0023fd60 FUN_0023fd60 (114 B): equivalent/0x0023fd60.cpp
// sym: ?FUN_0023fd60@SharedStr@fn_f2774db1@@QAEPAV12@PADHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 10/10)
// FUN_0023fd60 @ 0x0023fd60
// Releases the old buffer reference, then takes the new data in the given mode.
SharedStr* SharedStr::FUN_0023fd60(char* src, int length, int newMode)
{
    if (mode == 2) {
        char* old = data;
        if (*(short*)(old - 4) == 1) {
            if (old != (*(char**)&DAT_004cc02c))
                FUN_00247570(old - 8);
        } else {
            (*(short*)(old - 4))--;
        }
    }
    mode = (unsigned short)newMode;
    len = (unsigned short)length;
    if (newMode != 0 && newMode != 1)
        FUN_0023fa40((int *)(char * *)(&src), src, (int)length, length);
    data = src;
    return this;
}


// 0x0023fde0 FUN_0023fde0 (103 B): matches/0x0023fde0.cpp
// sym: ?Fn@fn_f2774db1@@YAPAUOut_23fde0@1@PAU21@HPBDZZ
Out_23fde0* Fn(Out_23fde0* out, int x, const char* fmt, ...) {
    char buf[0x1000];
#if defined(HULK_PTR64)
    __builtin_va_list va;
    __builtin_va_start(va, fmt);
#else
    char* va = (char*)&fmt + 4;
#endif
    int n = Fmt(buf, 0x1000, fmt, va);
    out->len = (ushort)n;
    buf[0xfff] = 0;
    out->flag = 2;
    int tmp;
    FUN_0023fa40(&tmp, buf, (unsigned)n, n);
    out->p = tmp;
    return out;
}

} // namespace fn_f2774db1

// 0x0023fe50 FUN_0023fe50 (147 B): equivalent/0x0023fe50.cpp
// sym: ?FUN_0023fe50@String_23fe50@owners@@QAEPAU12@PBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 9/10, incomplete)
// FUN_0023fe50 @ 0x0023fe50
owners::String_23fe50* owners::String_23fe50::FUN_0023fe50(const char* source) {
    if (kind == 2) {
        StringHeader_23fe50* header = reinterpret_cast<StringHeader_23fe50*>(data) - 1;
        if (header->references == 1) {
            if (data != (*(char**)&DAT_004cc02c)) FUN_00247570(header);
        } else {
            --header->references;
        }
    }
    if (source) {
        unsigned int count = 0;
        while (source[count]) ++count;
        length = (unsigned short)count;
        kind = 2;
        FUN_0023fa40((int *)(const char * *)(&source), (char *)(const char *)source, count, (unsigned int)count);
        data = const_cast<char*>(source);
    } else {
        data = (*(char**)&DAT_004cc02c);
        ++(reinterpret_cast<StringHeader_23fe50*>((*(char**)&DAT_004cc02c)) - 1)->references;
        length = 0;
        kind = 2;
    }
    return this;
}

namespace fn_f2774db1 {

// 0x0023fef0 FUN_0023fef0 (82 B): matches/0x0023fef0.cpp
// sym: ?Target@fn_f2774db1@@YAPAVObj_23fef0@1@PAV21@IZZ
Obj_23fef0* __cdecl Target(Obj_23fef0* a, hulk_uintptr b, ...) {
    char buf[0x1000];
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, b);
    CopyLike(buf, 0x1000, b, args);
#else
    CopyLike(buf, 0x1000, b, (void**)&b + 1);
#endif
    buf[0xfff] = 0;
    ((owners::String_23fe50 *)a)->FUN_0023fe50((const char *)buf);
    return a;
}

} // namespace fn_f2774db1

// 0x0023ff50 FUN_0023ff50 (252 B): equivalent/0x0023ff50.cpp
// sym: ?FUN_0023ff50@String_23ff50@owners@@QAEPAU12@PAU12@@Z
// STATUS: equivalent (tools/equiv.py level 3: 690 inputs, branch coverage 26/26)
// FUN_0023ff50 @ 0x0023ff50
owners::String_23ff50 *owners::String_23ff50::FUN_0023ff50(owners::String_23ff50 *other) {
 unsigned int oldLength = length;
 unsigned int total = oldLength + other->length;
 Header_23ff50 *header = reinterpret_cast<Header_23ff50 *>(data) - 1;
 if (kind == 2 && header->references <= 1 && header->capacity >= total) {
  const char *source = other->data == (*(char**)&DAT_004cc02c) ? ((char*)&DAT_003f335c) : other->data;
  char *dest = data + oldLength;
  char c;
  do { c = *source++; *dest++ = c; } while (c);
  length = (unsigned short)total;
  return this;
 }
 const char *source = data == (*(char**)&DAT_004cc02c) ? ((char*)&DAT_003f335c) : data;
 char *newData;
 FUN_0023fa40((int *)(char * *)(&newData), (char *)(const char *)source, oldLength, (unsigned int)total);
 source = data == (*(char**)&DAT_004cc02c) ? ((char*)&DAT_003f335c) : data;
 char *dest = newData;
 char c;
 do { c = *source++; *dest++ = c; } while(c);
 source = other->data == (*(char**)&DAT_004cc02c) ? ((char*)&DAT_003f335c) : other->data;
 dest = newData + length;
 do { c = *source++; *dest++ = c; } while(c);
 if (kind == 2) {
  Header_23ff50 *oldHeader = reinterpret_cast<Header_23ff50 *>(data) - 1;
  if (oldHeader->references == 1) {
   if (data != (*(char**)&DAT_004cc02c)) FUN_00247570(oldHeader);
  } else --oldHeader->references;
 }
 data = newData;
 kind = 2;
 length = (unsigned short)(length + other->length);
 return this;
}


// 0x00240060 FUN_00240060 (42 B): matches/0x00240060.cpp
// sym: ?FUN_00240060@Str_240060@owners@@QAEXXZ
// data: sentinel = DAT_004cc02c
void owners::Str_240060::FUN_00240060() {
    if (type == 2) {
        char* p = data;
        if (*(volatile short*)(p - 4) == 1) {
            if (p != (*(char**)&DAT_004cc02c)) {
                freebuf(p - 8);
                return;
            }
        } else {
            --*(short*)(p - 4);
        }
    }
}


// 0x00240090 FUN_00240090 (126 B): equivalent/0x00240090.cpp
// sym: ?FUN_00240090@Handle_240090@owners@@QAEXPBU12@@Z
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 4/4)
// FUN_00240090 @ 0x00240090
// Copy-constructs a handle: kind 0 is copied as is, kind 1 is converted through FUN_0023fa40
// (which writes its result over the incoming argument slot), anything else shares the text and
// bumps its reference count.
void owners::Handle_240090::FUN_00240090(const owners::Handle_240090* other)
{
    const owners::Handle_240090* src = other;
    unsigned short k = src->kind;
    if (k == 0) {
        text = src->text;
        kind = 0;
        extra = src->extra;
    } else if (k == 1) {
        unsigned int e = src->extra;
        kind = 2;
        extra = (unsigned short)e;
        FUN_0023fa40((int*)&other, (char *)(hulk_uintptr)(hulk_intptr)(src->text), (int)e, e);
        text = (hulk_intptr)other;
        extra = src->extra;
    } else {
        kind = 2;
        text = src->text;
        extra = src->extra;
        (*(unsigned short*)(text - 4))++;
    }
}

namespace fn_f2774db1 {

// 0x00240110 FUN_00240110 (95 B): matches/0x00240110.cpp
// sym: ?FUN_00240110@fn_f2774db1@@YAXPAVObj_240110@1@PAUSource_240110@1@I@Z
// data: gPointer = DAT_004cc02c, gZero_240110 = DAT_003f335c
void __cdecl FUN_00240110(Obj_240110* obj, Source_240110* src, unsigned int n) {
    __declspec(align(8)) char local[256];
    unsigned int len = src->length;
    unsigned int offset;
    if (len < n) {
        offset = 0;
        n = len + 1;
    } else {
        offset = len - n + 1;
    }
    char* data = src->data;
    if (data == (*(char**)&DAT_004cc02c))
        data = ((char*)&DAT_003f335c);
    memcpy(local, data + offset, n);
    ((owners::String_23fe50 *)obj)->FUN_0023fe50(local);
}

} // namespace fn_f2774db1

// 0x00240170 FUN_00240170 (19 B): matches/0x00240170.cpp
// sym: ?FUN_00240170@Thing_240170@owners@@QAEPAU12@H@Z
owners::Thing_240170* owners::Thing_240170::FUN_00240170(hulk_intptr x) {
    FUN_00240090((const void*)x);
    return this;
}


// 0x00240190 FUN_00240190 (82 B): equivalent/0x00240190.cpp
// sym: ?FUN_00240190@Text_240190@owners@@QAEPAU12@PBU12@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 8/8)
// FUN_00240190 @ 0x00240190
owners::Text_240190 *owners::Text_240190::FUN_00240190(const owners::Text_240190 *other) { if (other != this) { if (kind == 2) { short *count = (short *)(data - 4); if (*count == 1) { if (data != (*(char**)&DAT_004cc02c)) FUN_00247570(data - 8); } else --*count; } FUN_00240090(other); } return this; }


// 0x002401f0 FUN_002401f0 (135 B): equivalent/0x002401f0.cpp
// sym: ?FUN_002401f0@String_2401f0@owners@@QAEPAU12@PAU12@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 16/16)
// FUN_002401f0 @ 0x002401f0
owners::String_2401f0* owners::String_2401f0::FUN_002401f0(owners::String_2401f0* out) {
    owners::String_2401f0 tmp;
    tmp.FUN_00240090(this);
    char* p = tmp.FUN_0023fbb0();
    if (p) {
        while (*p) {
            if (*p >= 'A' && *p <= 'Z') *p += 0x20;
            ++p;
        }
    }
    out->FUN_00240090(&tmp);
    if (tmp.kind == 2) {
        StringHeader_2401f0* header = reinterpret_cast<StringHeader_2401f0*>(tmp.data) - 1;
        if (header->references == 1) {
            if (tmp.data != (*(char**)&DAT_004cc02c)) FUN_00247570(header);
        } else {
            --header->references;
        }
    }
    return out;
}

namespace fn_f2774db1 {

// 0x00240280 FUN_00240280 (135 B): equivalent/0x00240280.cpp
// sym: ?ToUpper@String@fn_f2774db1@@QAEPAU12@PAU12@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 16/16)
// FUN_00240280 @ 0x00240280
String* String::ToUpper(String* out) {
    String tmp;
    ((owners::Handle_240090 *)&tmp)->FUN_00240090((const owners::Handle_240090 *)(const String *)this);
    char* p = tmp.FUN_0023fbb0();
    if (p) {
        while (*p) {
            if (*p >= 'a' && *p <= 'z') *p -= 0x20;
            ++p;
        }
    }
    ((owners::Handle_240090 *)out)->FUN_00240090((const owners::Handle_240090 *)(const String *)(&tmp));
    if (tmp.kind == 2) {
        StringHeader_240280* header = reinterpret_cast<StringHeader_240280*>(tmp.data) - 1;
        if (header->references == 1) {
            if (tmp.data != (*(char**)&DAT_004cc02c)) FUN_00247570(header);
        } else {
            --header->references;
        }
    }
    return out;
}


// 0x00240310 FUN_00240310 (101 B): matches/0x00240310.cpp
// sym: ?Eq@S_240310@fn_f2774db1@@QAEDABU12@@Z
// data: gEmpty_240310 = DAT_004cc02c, gZero_240310 = DAT_003f335c
char S_240310::Eq(const S_240310& o) {
    const char* b = o.p;
    if (b == (*(const char**)&DAT_004cc02c))
        return p == (*(const char**)&DAT_004cc02c);
    const char* a = p;
    if (a == (*(const char**)&DAT_004cc02c))
        a = ((const char*)&DAT_003f335c);
    return strcmp(a, b) == 0;
}

} // namespace fn_f2774db1

// 0x00240380 FUN_00240380 (99 B): matches/0x00240380.cpp
// sym: ?FUN_00240380@StringLike_240380@owners@@QAEDPBD@Z
// data: gEmpty_240380 = DAT_003f335c, gSentinel_240380 = DAT_004cc02c
char owners::StringLike_240380::FUN_00240380(const char* other) {
    char* p = mData;
    if (other == 0)
        return p == (*(char**)&DAT_004cc02c);
    if (p == (*(char**)&DAT_004cc02c))
        p = ((char*)&DAT_003f335c);
    return strcmp(p, other) == 0;
}


// 0x00240410 FUN_00240410 (18 B): matches/0x00240410.cpp
// sym: ?FUN_00240410@ThisWrap_00240410@owners@@QAE_NH@Z
bool owners::ThisWrap_00240410::FUN_00240410(hulk_intptr value) {
    return this->FUN_00240380(((int)value)) == 0;
}

namespace fn_f2774db1 {

// 0x00240430 FUN_00240430 (198 B): equivalent/0x00240430.cpp
// sym: ?format@Object@fn_f2774db1@@QAEPAU12@M@Z
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 7/8, incomplete)
// FUN_00240430 @ 0x00240430
Object *Object::format(float value) {
 char buffer[64];
 int count=sprintf(buffer,"%f",value);
 Text_240430 text;
 text.flags=(text.flags & 0xffff0002U)|2;
 text.length=(unsigned short)count;
 char *data;
 FUN_0023fa40((int *)(char * *)(&data),(char *)(const char *)buffer,(int)count,count);
 text.data=data;
 ((owners::String_23ff50 *)this)->FUN_0023ff50((owners::String_23ff50 *)(Text_240430 *)(&text));
 if ((unsigned short)text.flags==2) {
  unsigned short *refs=(unsigned short *)(data-4);
  if (*refs==1) {
   if(data!=(*(char**)&DAT_004cc02c)) FUN_00247570(data-8);
  } else --*refs;
 }
 return this;
}


// 0x00240500 FUN_00240500 (192 B): equivalent/0x00240500.cpp
// sym: ?FUN_00240500@Object@fn_f2774db1@@QAEPAU12@I@Z
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 7/8, incomplete)
// FUN_00240500 @ 0x00240500
Object *Object::FUN_00240500(unsigned int value) {
 char buffer[64];
 int length = sprintf(buffer, "%u", value);
 StringValue_240500 temporary;
 temporary.flags = (temporary.flags & 0xffff0002u) | 2u;
 temporary.length = (unsigned short)length;
 char *text;
 FUN_0023fa40((int *)(char * *)(&text), (char *)(const char *)buffer, (int)length, length);
 temporary.text = text;
 ((owners::String_23ff50 *)this)->FUN_0023ff50((owners::String_23ff50 *)(StringValue_240500 *)(&temporary));
 if ((unsigned short)temporary.flags == 2) {
  StringHeader_240500 *header = reinterpret_cast<StringHeader_240500 *>(text) - 1;
  if (header->references == 1) {
   if (text != (*(char**)&DAT_004cc02c)) FUN_00247570(header);
  } else {
   --header->references;
  }
 }
 return this;
}


// 0x002405c0 FUN_002405c0 (105 B): equivalent/0x002405c0.cpp
// sym: ?Concat@String@fn_f2774db1@@QAEPAU12@PAU12@M@Z
// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 6/6)
// FUN_002405c0 @ 0x002405c0
String* String::Concat(String* out, float value) {
    String tmp;
    ((owners::Handle_240090 *)&tmp)->FUN_00240090((const owners::Handle_240090 *)(const String *)this);
    tmp.FUN_00240430(value);
    ((owners::Handle_240090 *)out)->FUN_00240090((const owners::Handle_240090 *)(const String *)(&tmp));
    if (tmp.kind == 2) {
        StringHeader_2405c0* header = reinterpret_cast<StringHeader_2405c0*>(tmp.data) - 1;
        if (header->references == 1) {
            if (tmp.data != (*(char**)&DAT_004cc02c)) FUN_00247570(header);
        } else {
            --header->references;
        }
    }
    return out;
}


// 0x00240630 FUN_00240630 (105 B): equivalent/0x00240630.cpp
// sym: ?Concat@String@fn_f2774db1@@QAEPAU12@PAU12@I@Z
// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 6/6)
// FUN_00240630 @ 0x00240630
String* String::Concat(String* out, unsigned value) {
    String tmp;
    ((owners::Handle_240090 *)&tmp)->FUN_00240090((const owners::Handle_240090 *)(const String *)this);
    tmp.FUN_00240500(value);
    ((owners::Handle_240090 *)out)->FUN_00240090((const owners::Handle_240090 *)(const String *)(&tmp));
    if (tmp.kind == 2) {
        StringHeader_240630* header = reinterpret_cast<StringHeader_240630*>(tmp.data) - 1;
        if (header->references == 1) {
            if (tmp.data != (*(char**)&DAT_004cc02c)) FUN_00247570(header);
        } else {
            --header->references;
        }
    }
    return out;
}


// 0x002406a0 FUN_002406a0 (105 B): equivalent/0x002406a0.cpp
// sym: ?FUN_002406a0@Str_2406a0@fn_f2774db1@@QAEPAU12@PAU12@PBX@Z
// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 6/6)
// FUN_002406a0 @ 0x002406a0
Str_2406a0* Str_2406a0::FUN_002406a0(Str_2406a0* ret, const void* rhs) {
    Str_2406a0 tmp;
    ((owners::Handle_240090 *)&tmp)->FUN_00240090((const owners::Handle_240090 *)(const Str_2406a0 *)this);
    ((owners::String_23ff50 *)&tmp)->FUN_0023ff50((owners::String_23ff50 *)rhs);
    ((owners::Handle_240090 *)ret)->FUN_00240090((const owners::Handle_240090 *)(const Str_2406a0 *)(&tmp));
    if (tmp.kind == 2) {
        char* data = tmp.p;
        if (*(unsigned short*)(data - 4) == 1) {
            if (data != (*(const char**)&DAT_004cc02c))
                FUN_00247570(data - 8);
        } else {
            (*(unsigned short*)(data - 4))--;
        }
    }
    return ret;
}


// 0x00240730 FUN_00240730 (30 B): matches/0x00240730.cpp
// sym: ?vfunc_2@CCollisionAction@fn_f2774db1@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_00240060*)(this))->FUN_00240060();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x00240750 FUN_00240750 (6 B): matches/0x00240750.cpp
// sym: _FUN_00240750
// Same code shape as 0x00085cd0 (propagated; names are from that function)
extern "C" hulk_intptr FUN_00240750(void) {
    return DAT_004e5cac;
}


// 0x00240760 FUN_00240760 (17 B): matches/0x00240760.cpp
// sym: _FUN_00240760
// Same code shape as 0x000fc130 (propagated; names are from that function)
// data: gObject_240760 = DAT_004e5ca0
extern "C" void __cdecl FUN_00240760(unsigned int text) {
    ((owners::Text_240190 *)((*(Obj_240760**)&DAT_004e5ca0)))->FUN_00240190((const owners::Text_240190 *)(hulk_uintptr)(unsigned int)text);
}


// 0x00240780 FUN_00240780 (6 B): matches/0x00240780.cpp
// sym: _FUN_00240780
// Same code shape as 0x00085cd0 (propagated; names are from that function)
extern "C" hulk_intptr FUN_00240780(void) {
    return *(hulk_intptr*)&DAT_004e5ca0;
}


// 0x002407a0 FUN_002407a0 (609 B): equivalent/0x002407a0.cpp
// sym: _FUN_002407a0
// STATUS: equivalent (tools/equiv.py level 3: 20022 inputs, branch coverage 12/12)
// FUN_002407a0 @ 0x002407a0
extern "C" void FUN_002407a0(unsigned int flags)
{
    Str_2407a0 *str;
    DAT_004e5ca4 = flags;
    void *mem = FUN_0008d690(0xc);
    if (mem != 0) {
        str = ((Str_2407a0 *)((owners::String_23fc40 *)(((Str_2407a0 *)mem)))->FUN_0023fc40("english", (hulk_intptr)2));
        (*(Str_2407a0**)&DAT_004e5ca0) = str;
    } else {
        (*(Str_2407a0**)&DAT_004e5ca0) = 0;
    }
    FUN_00256660()->init();
    FUN_00245330()->init();
    FUN_00241660()->init();
    FUN_00255d20()->init();
    FUN_00255480()->init();
    FUN_00254e70()->init();
    FUN_00254a70()->init();
    FUN_00254640()->init();
    FUN_00253c50()->init();
    FUN_00253770()->init();
    FUN_00253390()->init();
    FUN_00252fb0()->init();
    FUN_00252b50()->init();
    FUN_002527a0()->init();
    FUN_00252370()->init();
    FUN_002518d0()->init();
    FUN_002513c0()->init();
    FUN_00250db0()->init();
    FUN_002509b0()->init();
    FUN_00250540()->init();
    FUN_002500d0()->init();
    FUN_0024fc50()->init();
    FUN_0024f810()->init();
    FUN_0024ea00()->init();
    FUN_0024e540()->init();
    FUN_0024df00();
    if (flags & 1) {
        om::EntityLoader *l;
        l = FUN_00247530(FUN_0024d200());
        if (l != 0)
            l = ((EntityLoader_nv_2407a0*)(l))->FUN_0024d360(FUN_00245330());
        { int handleArg = FUN_00245330()->handle; (*(Registry_2407a0**)&DAT_00527c58)->FUN_00265210(l, handleArg); } // MSVC evaluates the argument first
        l = FUN_00247530(FUN_0024d200());
        if (l != 0)
            l = ((EntityLoader_nv_2407a0*)(l))->FUN_0024d360(FUN_00256660());
        { int handleArg = FUN_00256660()->handle; (*(Registry_2407a0**)&DAT_00527c58)->FUN_00265210(l, handleArg); } // MSVC evaluates the argument first
        l = FUN_00247530(FUN_0024d200());
        if (l != 0)
            l = ((EntityLoader_nv_2407a0*)(l))->FUN_0024d360(FUN_00241660());
        { int handleArg = FUN_00241660()->handle; (*(Registry_2407a0**)&DAT_00527c58)->FUN_00265210(l, handleArg); } // MSVC evaluates the argument first
        l = FUN_00247530(FUN_0024d200());
        if (l != 0)
            l = ((EntityLoader_nv_2407a0*)(l))->FUN_0024d360(FUN_0024d5a0());
        { int handleArg = FUN_0024d5a0()->handle; (*(Registry_2407a0**)&DAT_00527c58)->FUN_00265210(l, handleArg); } // MSVC evaluates the argument first
    }
    DAT_004e5cac = FUN_00242bd0();
    DAT_004e5ca8 = FUN_00267f80();
}


// 0x00240bb0 FUN_00240bb0 (46 B): matches/0x00240bb0.cpp
// sym: @FUN_00240bb0@4
extern "C" void __fastcall FUN_00240bb0(void* p) {
    int i = FUN_00267f80(p) - DAT_004e5ca8;
    FUN_0024c060();
    FUN_00243090(DAT_004e5cac, (float)i);
    FUN_00240f50();
}

} // namespace fn_f2774db1
