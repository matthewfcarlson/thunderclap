// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002719a0..0x00272a40 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f484c341 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f484c341 {} using namespace fn_f484c341;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f484c341 {
extern const unsigned char DAT_004bdce7[];
extern const unsigned short DAT_004adcc8[];
extern const unsigned short DAT_004adcd8[];
extern unsigned __int64 __fastcall FUN_002719a0(int length, const unsigned char *text);
int __cdecl FUN_00271c00(unsigned int, unsigned char *, unsigned int, unsigned int, unsigned int *, void *);
int __cdecl FUN_00271e40(unsigned int codepoint, unsigned short *output, unsigned int capacity, unsigned int replacement, unsigned int *written, unsigned int *unused);
typedef unsigned int uint_272070;
typedef unsigned char BOOL;
typedef unsigned int uint_2720b0;
extern short DAT_004cdbf4[];
typedef unsigned char byte_272240;
typedef unsigned int uint_272240;
extern "C" void __stdcall OutputDebugStringA(const char*);
extern "C" void __cdecl FUN_00267760(char*, unsigned int, const char*, ...);
typedef void(__cdecl* Handler_2726e0)(char*);
class Part_272840 {
  public:
    void Fini_00277540() throw();
};
struct Drive_272840 {
    void* v0;
    void* v4;
    unsigned p8;
    void* vc;
    int pad;
    Part_272840 part;
    void Dtor() throw();
};
class Sub_272880 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_272880 : public CoreDrive {
  public:
    int Run();
};
class Sub_2728a0 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_2728a0 {
  public:
    char pad[0x0c];
    Sub_2728a0 sub;
    char pad2[0xa4];
    int value;
    void F(int);
};
struct Node {
    hulk_uintptr a;
    Node* next;
};
class SubObj_2728e0 {
  public:
    virtual void Fn0();
    virtual void Fn1();
};
class Container_2728e0 : public CoreDrive {
  public:
    void Add(Node* p);
};
class Sub_272920 {
  public:
    virtual void Begin();
    virtual void End();
};
extern "C" CoreThread* __cdecl FUN_0026dbb0();
class Owner_272920 : public CoreDrive {
  public:
    void Run(hulk_intptr a, int b);
};
class Inner_272960 {
  public:
    virtual void A();
    virtual void B();
};
class Target_272960 {
  public:
    char pad[0xc];
    Inner_272960 inner;
    char pad2[0x30];
    int a;
    char pad3[4];
    int b;
    int c;
    void f(int);
};
class V {
  public:
    virtual void A();
    virtual void B();
};
class C_272990 : public CoreDrive {
  public:
    void F(hulk_uintptr*);
};
class Inner_2729c0 {
  public:
    virtual void First();
    virtual void Second();
};
class Target_2729c0 : public CoreDrive {
  public:
    void run(hulk_uintptr*);
};
class Sub {
  public:
    virtual void A();
    virtual void B();
};
class Obj {
  public:
    char pad[0xc];
    Sub mSub;
    char pad2[0x30];
    int mVal;
    void Set(int v);
};
class Inner_272a20 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_272a20 : public CoreDrive {
  public:
    int target();
};


// 0x002719a0 FUN_002719a0 (113 B): equivalent/0x002719a0.cpp
// sym: ?FUN_002719a0@fn_f484c341@@YIEIPBE@Z
// STATUS: equivalent (tools/equiv.py level 3: 113 inputs, branch coverage 24/32, incomplete)
// FUN_002719a0 @ 0x002719a0
// equiv-conv: FUN_002719a0 ecx edx
unsigned char __fastcall FUN_002719a0(unsigned int length, const unsigned char* bytes)
{
    if (length < 1 || length > 4)
        return 0;

    // Every byte after the first must be a UTF-8 continuation byte.
    for (unsigned int i = length - 1; i > 1; --i) {
        unsigned char continuation = bytes[i];
        if (continuation < 0x80 || continuation > 0xbf)
            return 0;
    }

    if (length >= 2) {
        unsigned char second = bytes[1];
        if (second > 0xbf)
            return 0;
        if (bytes[0] == 0xe0) {
            if (second < 0xa0)
                return 0;
        } else if (bytes[0] == 0xf0) {
            if (second < 0x90)
                return 0;
        } else if (bytes[0] == 0xf4) {
            if (second > 0x8f)
                return 0;
        } else if (second < 0x80) {
            return 0;
        }
    }

    unsigned char first = bytes[0];
    if (first >= 0x80 && first < 0xc2)
        return 0;
    return first <= 0xf4 ? 1 : 0;
}


// 0x00271a30 FUN_00271a30 (320 B): matches/0x00271a30.cpp
// sym: ?FUN_00271a30@fn_f484c341@@YA_NIPAI@Z
bool FUN_00271a30(unsigned int ch, unsigned int* out) {
    if (ch >= 0xff01 && ch <= 0xff5e) {
        *out = ch - 0xfee0;
        return true;
    }
    if (ch >= 0xff5f && ch <= 0xff60) {
        *out = ch - 0xd5da;
        return true;
    }
    if (ch >= 0xff61 && ch <= 0xff9f) {
        *out = DAT_004bdce7[ch] + 0x3000;
        return true;
    }
    if (ch == 0xffa0) {
        *out = 0x3164;
        return true;
    }
    if (ch >= 0xffa1 && ch <= 0xffbe) {
        *out = ch - 0xce70;
        return true;
    }
    if (ch >= 0xffc2 && ch <= 0xffc7) {
        *out = ch - 0xce73;
        return true;
    }
    if (ch >= 0xffca && ch <= 0xffcf) {
        *out = ch - 0xce75;
        return true;
    }
    if (ch >= 0xffd2 && ch <= 0xffd7) {
        *out = ch - 0xce77;
        return true;
    }
    if (ch >= 0xffda && ch <= 0xffdc) {
        *out = ch - 0xce79;
        return true;
    }
    if (ch >= 0xffe0 && ch <= 0xffe6) {
        *out = DAT_004adcc8[ch];
        return true;
    }
    if (ch >= 0xffe8 && ch <= 0xffee) {
        *out = DAT_004adcd8[ch];
        return true;
    }
    return false;
}


// 0x00271b70 FUN_00271b70 (116 B): equivalent/0x00271b70.cpp
// sym: _FUN_00271b70
// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 12/12)
// FUN_00271b70 @ 0x00271b70
// FUN_00271b70 @ 0x00271b70
extern "C" int __cdecl FUN_00271b70(const unsigned char *text, int *length, int *value)
{
    unsigned int first = *text;
    int extra = ((signed char*)&DAT_0042b6f8)[first];
    int count = extra + 1;
    unsigned __int64 result = FUN_002719a0(count, text);
    unsigned int low = (unsigned int)result;
    if (!(low & 255)) return low;
    const unsigned char *p = text;
    unsigned int code = 0;
    switch (extra) {
    case 3:
        code = first;
        ++p;
        code = (code << 6) + *p++;
        code = (code << 6) + *p++;
        code = (code << 6) + *p;
        break;
    case 2:
        code = *p++;
        code = (code << 6) + *p++;
        code = (code << 6) + *p;
        break;
    case 1:
        code = *p++;
        code = (code << 6) + *p;
        break;
    case 0:
        code = *p;
        break;
    }
    code -= ((int*)&DAT_0042b6d8)[extra];
    if (length) *length = count;
    if (value) *value = code;
    return ((hulk_uintptr)value & 0xffffff00) | 1;
}


// 0x00271c00 FUN_00271c00 (216 B): equivalent/0x00271c00.cpp
// sym: ?encode_utf8@fn_f484c341@@YAHIPAEIIPAIPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 18/20, incomplete)
// FUN_00271c00 @ 0x00271c00
int __cdecl encode_utf8(unsigned int codepoint, unsigned char *destination, unsigned int capacity, unsigned int replacement, unsigned int *written, void *context)
{
    unsigned int length;
    if (codepoint < 0x80) length = 1;
    else if (codepoint < 0x800) length = 2;
    else if (codepoint < 0x10000) length = 3;
    else if (codepoint < 0x200000) length = 4;
    else {
        if (!replacement) return -4;
        int result = FUN_00271c00(replacement, destination, capacity, 0, written, context);
        return result == -2 ? -6 : result;
    }
    if (capacity < length) return -1;
    unsigned int remaining = codepoint;
    for (unsigned int i = length; i > 1; --i) {
        destination[i - 1] = (unsigned char)((remaining & 0x3f) | 0x80);
        remaining >>= 6;
    }
    destination[0] = (unsigned char)(((unsigned char*)&DAT_0042b6f0)[length] | remaining);
    *written = length;
    return 0;
}


// 0x00271cf0 FUN_00271cf0 (115 B): equivalent/0x00271cf0.cpp
// sym: _FUN_00271cf0
// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 10/12, incomplete)
// FUN_00271cf0 @ 0x00271cf0
extern "C" int __cdecl FUN_00271cf0(char *destination, const unsigned char *source, unsigned int capacity)
{
    unsigned int written = 0;
    while (source[written] != 0) {
        unsigned int count = (int)((signed char*)&DAT_0042b6f8)[source[written]] + 1;
        if (written + count + 1 > capacity)
            break;
        for (unsigned int i = 0; i < count; ++i) {
            const unsigned char *current = source + written + i;
            if (current == 0)
                return -1;
            destination[written + i] = *current;
        }
        written += count;
    }
    destination[written] = 0;
    return written;
}


// 0x00271d70 FUN_00271d70 (81 B): matches/0x00271d70.cpp
// sym: ?CountChars@fn_f484c341@@YAHPBDPAI@Z
// data: gTable = DAT_0042b6f8
int __cdecl CountChars(const char* str, unsigned int* end) {
    int count = 0;
    unsigned int pos = 0;
    unsigned char c = str[pos];
    while (c) {
        const char* p = str + pos;
        unsigned int n = (int)((signed char*)&DAT_0042b6f8)[c] + 1;
        unsigned int i = 0;
        while (i < n) {
            if (!p)
                return -1;
            ++i;
            ++p;
        }
        pos += n;
        c = str[pos];
        ++count;
    }
    if (end)
        *end = pos;
    return count;
}


// 0x00271dd0 FUN_00271dd0 (103 B): matches/0x00271dd0.cpp
// sym: _FUN_00271dd0
extern "C" unsigned char __cdecl FUN_00271dd0(const unsigned short* text, unsigned int* bytesConsumed,
                                   unsigned int* codePoint) {
    unsigned int point = text[0];
    unsigned int units = 1;
    if (point >= 0xd800 && point <= 0xdbff) {
        unsigned int low = text[1];
        if (low < 0xdc00 || low > 0xdfff)
            return 0;
        point = ((point - 0xd7f7) << 10) + low;
        units = 2;
    } else if (point >= 0xdc00 && point <= 0xdfff) {
        return 0;
    }
    if (bytesConsumed)
        *bytesConsumed = units * 2;
    if (codePoint)
        *codePoint = point;
    return 1;
}


// 0x00271e40 FUN_00271e40 (210 B): equivalent/0x00271e40.cpp
// sym: ?encodeUtf16@fn_f484c341@@YAHIPAGIIPAI1@Z
// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 15/18, incomplete)
// FUN_00271e40 @ 0x00271e40
int __cdecl encodeUtf16(unsigned int codepoint, unsigned short *output, unsigned int capacity, unsigned int replacement, unsigned int *written, unsigned int *unused)
{
    if (codepoint >= 0x10ffff) {
        int result = FUN_00271e40(replacement, output, capacity, 0, written, unused);
        return result == -2 ? -6 : result;
    }
    unsigned int bytes = codepoint <= 0xffff ? 2 : 4;
    if (capacity < bytes)
        return -1;
    if (codepoint <= 0xffff) {
        if (codepoint >= 0xd800 && codepoint <= 0xdfff)
            return -2;
        output[0] = (unsigned short)codepoint;
    } else {
        unsigned int value = codepoint - 0x10000;
        output[0] = (unsigned short)((value >> 10) + 0xd800);
        output[1] = (unsigned short)((value & 0x3ff) + 0xdc00);
    }
    *written = bytes;
    return 0;
}


// 0x00271f20 FUN_00271f20 (178 B): matches/0x00271f20.cpp
// sym: ?FUN_00271f20@fn_f484c341@@YAHPAGPBGI@Z
int __cdecl FUN_00271f20(unsigned short* destination, const unsigned short* source, unsigned int capacity) {
    unsigned int count = 0;
    while (source[count] != 0) {
        unsigned short first = source[count];
        unsigned int length = 1;
        if (first >= 0xd800 && first <= 0xdbff) {
            unsigned short second = source[count + 1];
            if (second < 0xdc00 || second > 0xdfff)
                return -1;
            length = 2;
        } else if (first >= 0xdc00 && first <= 0xdfff) {
            return -1;
        }
        if ((count + length) * 2 + 2 > capacity) {
            destination[count] = 0;
            return (int)count;
        }
        for (unsigned int i = 0; i < length; ++i)
            destination[count + i] = source[count + i];
        count += length;
    }
    destination[count] = 0;
    return (int)(count * 2);
}


// 0x00271fe0 FUN_00271fe0 (129 B): equivalent/0x00271fe0.cpp
// sym: ?FUN_00271fe0@fn_f484c341@@YAHPBGPAI@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_00271fe0 @ 0x00271fe0
// Counts the UTF-16 code points of a string, returning -1 on an unpaired surrogate.
// Optionally stores the string length in bytes.
int FUN_00271fe0(const unsigned short *str, unsigned int *byteLength)
{
    int codePoints = 0;
    int index = 0;
    const unsigned short *cur = str;
    unsigned short c = str[0];

    while (c != 0) {
        int step = 1;
        if (c >= 0xd800 && c <= 0xdbff) {
            unsigned short low = cur[1];
            if (low < 0xdc00 || low > 0xdfff)
                return -1;
            step = 2;
        } else if (c >= 0xdc00 && c <= 0xdfff) {
            return -1;
        }
        index += step;
        c = str[index];
        cur = str + index;
        codePoints++;
    }

    if (byteLength != 0)
        *byteLength = index * 2;
    return codePoints;
}


// 0x00272070 FUN_00272070 (52 B): matches/0x00272070.cpp
// sym: _FUN_00272070
extern "C" BOOL FUN_00272070(uint_272070* src, uint_272070* length, uint_272070* codepoint) {
    uint_272070 value = *src;
    if (value >= 0xd800 && value <= 0xdfff)
        return 0;
    if (length != 0)
        *length = 4;
    if (codepoint != 0)
        *codepoint = value;
    return 1;
}


// 0x002720b0 FUN_002720b0 (54 B): matches/0x002720b0.cpp
// sym: _FUN_002720b0
extern "C" int __cdecl FUN_002720b0(uint_2720b0 value, uint_2720b0* outValue, uint_2720b0 size, uint_2720b0 unused, uint_2720b0* outSize) {
    if (size < 4)
        return -1;
    if (value >= 0xd800 && value <= 0xdfff)
        return -2;
    *outValue = value;
    *outSize = 4;
    return 0;
}


// 0x002721c0 FUN_002721c0 (128 B): equivalent/0x002721c0.cpp
// sym: ?FUN_002721c0@fn_f484c341@@YAFD@Z
// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 28/28)
// FUN_002721c0 @ 0x002721c0
// equiv-conv: FUN_002721c0 eax
short FUN_002721c0(char ch)
{
    if (ch >= ' ' && ch <= '/')
        return DAT_004cdc70[ch];
    if (ch >= '0' && ch <= '9')
        return (short)(ch + 0x821f);
    if (ch >= ':' && ch <= '@')
        return DAT_004cdc5c[ch];
    if (ch >= 'A' && ch <= 'Z')
        return (short)(ch + 0x821f);
    if (ch >= '[' && ch <= '`')
        return DAT_004cdc28[ch];
    if (ch >= 'a' && ch <= 'z')
        return (short)(ch + 0x8220);
    if (ch >= '{' && ch <= '~')
        return DAT_004cdbf4[ch];
    return 0;
}


// 0x00272240 FUN_00272240 (112 B): matches/0x00272240.cpp
// sym: _FUN_00272240
// data: g_code = DAT_004cdcaa
extern "C" bool __cdecl FUN_00272240(byte_272240* p, uint_272240* count, uint_272240* value) {
    byte_272240 b = *p;
    uint_272240 v;
    uint_272240 n;
    if (b <= 0x7f) {
        v = (uint_272240)b;
        n = 1;
    } else if (b >= 0xa1 && b <= 0xdf) {
        v = (uint_272240)b + 0xfec0;
        n = 1;
    } else if (((b >= 0x81 && b <= 0x9f) || (b >= 0xe0 && b <= 0xfc)) && p[1] >= 0x40 && p[1] <= 0xfc &&
               p[1] != 0x7f) {
        v = (*(unsigned short*)&DAT_004cdcaa);
        n = 2;
    } else
        return false;
    if (count)
        *count = n;
    if (value)
        *value = v;
    return true;
}

} // namespace fn_f484c341

// 0x002722b0 FUN_002722b0 (271 B): equivalent/0x002722b0.cpp [wrapped: conflict: FUN_00271a30]
// sym: ?target@fn_002722b0@@YAHIPAEIIPAII@Z
namespace fn_002722b0 {
// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 26/26)
// FUN_002722b0 @ 0x002722b0
// equiv-conv: FUN_002721c0 eax

unsigned int FUN_002721c0(unsigned int value);
unsigned char __cdecl FUN_00271a30(unsigned int value, unsigned int *converted);
int __cdecl FUN_002722b0(unsigned int, unsigned char *, unsigned int, unsigned int, unsigned int *, unsigned int);
int __cdecl target(unsigned int character, unsigned char *destination, unsigned int capacity, unsigned int fallback, unsigned int *written, unsigned int mode)
{
    unsigned int length;
    unsigned char first = (unsigned char)character;
    unsigned char second = 0;
    bool invalid = false;
    if (character <= 0x7f) {
        if (mode == 1) {
            length = 2;
            if (character != 0) {
                unsigned int bytes = FUN_002721c0(character);
                if ((bytes & 0xffff) == 0) invalid = true;
                else {
                    first = (unsigned char)(bytes >> 8);
                    second = (unsigned char)bytes;
                }
            } else first = 0;
        } else length = 1;
    } else if (character >= 0xff61 && character <= 0xff9f) {
        if (mode == 1) {
            unsigned int original = character;
            character = 0;
            if (FUN_00271a30(original, &character))
                return FUN_002722b0(character, destination, capacity, fallback, written, mode);
            invalid = true;
        } else {
            length = 1;
            first = (unsigned char)(character + 0x40);
        }
    } else {
        length = 2;
        if (character & 0xffff0000) invalid = true;
        else {
            unsigned int bytes = (*(unsigned int*)&DAT_004cdca8);
            first = (unsigned char)(bytes >> 8);
            second = (unsigned char)bytes;
        }
    }
    if (invalid) {
        if (!fallback) return -4;
        int result = FUN_002722b0(fallback, destination, capacity, 0, written, mode);
        return result == -2 ? -6 : result;
    }
    if (capacity < length) return -1;
    destination[0] = first;
    if (length == 2) destination[1] = second;
    *written = length;
    return 0;
}
} // namespace fn_002722b0

namespace fn_f484c341 {

// 0x002723c0 FUN_002723c0 (91 B): matches/0x002723c0.cpp
// sym: ?FUN_002723c0@fn_f484c341@@YAHPADPBD@Z
int __cdecl FUN_002723c0(char* dst, const char* src) {
    unsigned int i = 0;
    if (src[0]) {
        do {
            unsigned char c = src[i];
            dst[i] = c;
            if ((c >= 0x81 && c <= 0x9f) || (c >= 0xe0 && c <= 0xfc)) {
                c = src[i + 1];
                if (c < 0x40 || c > 0xfc || c == 0x7f) {
                    dst[i] = 0;
                    return -1;
                }
                dst[i + 1] = c;
                ++i;
            }
            c = src[i + 1];
            ++i;
            if (!c)
                break;
        } while (1);
    }
    dst[i] = 0;
    return i;
}


// 0x00272540 FUN_00272540 (24 B): matches/0x00272540.cpp
// sym: _FUN_00272540
extern "C" void FUN_00272540() {
    FUN_0026d820(((unsigned char*)&DAT_0052a1a4));
    DAT_0052a1c0 = 0x55555555;
}


// 0x00272560 FUN_00272560 (24 B): matches/0x00272560.cpp
// sym: ?FUN_00272560@fn_f484c341@@YAXXZ
void FUN_00272560(void) {
    FUN_0026d830(((unsigned char*)&DAT_0052a1a4));
    DAT_0052a1c0 = 0x33333333;
}


// 0x002725e0 FUN_002725e0 (193 B): equivalent/0x002725e0.cpp
// sym: _FUN_002725e0
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/12, incomplete)
// FUN_002725e0 @ 0x002725e0
extern "C" void __cdecl FUN_002725e0(const char* text)
{
    if (!text) text = "NULL";
    unsigned int length = 0;
    while (text[length]) ++length;
    char buffer[257];
    unsigned int blocks = length >> 8;
    unsigned int remainder = length & 255;
    for (unsigned int i = 0; i < blocks; ++i) {
        for (unsigned int j = 0; j < 256; ++j) buffer[j] = text[i * 256 + j];
        buffer[256] = 0;
        OutputDebugStringA(buffer);
    }
    if (remainder) {
        for (unsigned int j = 0; j < remainder; ++j) buffer[j] = text[blocks * 256 + j];
        buffer[remainder] = 0;
        OutputDebugStringA(buffer);
    }
}


// 0x002726e0 FUN_002726e0 (176 B): matches/0x002726e0.cpp
// sym: _FUN_002726e0
// data: gBuffer_2726e0 = DAT_0052a1a4, gCallback_2726e0 = DAT_004cdcf8, gFlag_2726e0 = DAT_004cdcf4
// data: gHandler = DAT_0052a1c4, gState_2726e0 = DAT_0052a1c0
extern "C" char __cdecl FUN_002726e0(const char* a, const char* b, int c) {
    char text[1024];
    FUN_00267760(text, 1024, "ASSERT FAILED : [%s]\n         Line : [%d] File: [%s]\n", a, c, b);
    text[1023] = 0;
    Handler_2726e0 h = (*(Handler_2726e0*)&DAT_0052a1c4);
    if (h)
        h(text);
    else {
        if ((*(int*)&DAT_0052a1c0) == 0x55555555)
            FUN_0026d850(((char*)&DAT_0052a1a4));
        (*(Handler_2726e0*)&DAT_004cdcf8)(text);
        if ((*(int*)&DAT_0052a1c0) == 0x55555555)
            FUN_0026d840(((char*)&DAT_0052a1a4));
    }
    return DAT_004cdcf4 != 0;
}


// 0x00272840 FUN_00272840 (61 B): matches/0x00272840.cpp
// sym: ?Dtor@Drive_272840@fn_f484c341@@QAEXXZ
void Drive_272840::Dtor() throw() {
    v0 = vDrive;
    v4 = vD4;
    vc = vDc;
    part.Fini_00277540();
    vc = vSafe;
    _ReadWriteBarrier();
    unsigned t = p8;
    (*(unsigned*)&DAT_004cdbb0) = t;
    v4 = vBase;
    v0 = vIRef;
}


// 0x00272880 FUN_00272880 (32 B): matches/0x00272880.cpp
// sym: ?Run@Obj_272880@fn_f484c341@@QAEHXZ
int Obj_272880::Run() {
    ((Sub_272880*)&vftableMutable)->A();
    int v = error;
    ((Sub_272880*)&vftableMutable)->B();
    return v;
}


// 0x002728a0 FUN_002728a0 (36 B): matches/0x002728a0.cpp
// sym: ?F@Obj_2728a0@fn_f484c341@@QAEXH@Z
void Obj_2728a0::F(int x) {
    sub.A();
    value = x;
    sub.B();
}

} // namespace fn_f484c341

// 0x002728d0 FUN_002728d0 (4 B): matches/0x002728d0.cpp
// sym: ?FUN_002728d0@ProjectileMissile_2728d0@owners@@QAEPAU12@XZ
// Same code shape as 0x00196630 (propagated; names are from that function)
owners::ProjectileMissile_2728d0* owners::ProjectileMissile_2728d0::FUN_002728d0() {
    return (owners::ProjectileMissile_2728d0*)((char*)this + 0x60);
}

namespace fn_f484c341 {

// 0x002728e0 FUN_002728e0 (58 B): matches/0x002728e0.cpp
// sym: ?Add@Container_2728e0@fn_f484c341@@QAEXPAUNode@2@@Z
void Container_2728e0::Add(Node* p) {
    ((SubObj_2728e0*)&vftableMutable)->Fn0();
    if (requests == 0) {
        requests = p;
    } else {
        ((Node*)lastRequest)->next = p;
    }
    p->next = 0;
    lastRequest = p;
    ((SubObj_2728e0*)&vftableMutable)->Fn1();
}


// 0x00272920 FUN_00272920 (55 B): matches/0x00272920.cpp
// sym: ?Run@Owner_272920@fn_f484c341@@QAEXHH@Z
void Owner_272920::Run(hulk_intptr a, int b) {
    ((Sub_272920*)&vftableMutable)->Begin();
    thread = FUN_0026dbb0();
    callback = (void*)a;
    argument = b;
    state = 2;
    ((Sub_272920*)&vftableMutable)->End();
}


// 0x00272960 FUN_00272960 (37 B): matches/0x00272960.cpp
// sym: ?f@Target_272960@fn_f484c341@@QAEXH@Z
void Target_272960::f(int x) {
    inner.A();
    c = 0;
    b = 0;
    a = 0;
    inner.B();
}


// 0x00272990 FUN_00272990 (40 B): matches/0x00272990.cpp
// sym: ?F@C_272990@fn_f484c341@@QAEXPAI@Z
void C_272990::F(hulk_uintptr* x) {
    ((V*)&vftableMutable)->A();
    signal = x;
    state = 2;
    ((V*)&vftableMutable)->B();
}


// 0x002729c0 FUN_002729c0 (40 B): matches/0x002729c0.cpp
// sym: ?run@Target_2729c0@fn_f484c341@@QAEXPAI@Z
void Target_2729c0::run(hulk_uintptr* x) {
    ((Inner_2729c0*)&vftableMutable)->First();
    signal = x;
    state = 0;
    ((Inner_2729c0*)&vftableMutable)->Second();
}


// 0x002729f0 FUN_002729f0 (33 B): matches/0x002729f0.cpp
// sym: ?Set@Obj@fn_f484c341@@QAEXH@Z
void Obj::Set(int v) {
    mSub.A();
    mVal = v;
    mSub.B();
}


// 0x00272a20 FUN_00272a20 (29 B): matches/0x00272a20.cpp
// sym: ?target@Obj_272a20@fn_f484c341@@QAEHXZ
int Obj_272a20::target() {
    ((Inner_272a20*)&vftableMutable)->A();
    int v = state;
    ((Inner_272a20*)&vftableMutable)->B();
    return v;
}

} // namespace fn_f484c341
