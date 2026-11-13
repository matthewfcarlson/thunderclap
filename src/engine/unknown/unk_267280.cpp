// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00267280..0x00267ba0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/records.h"
#define TREE_TU_BEGIN namespace fn_fccd9b35 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fccd9b35 {} using namespace fn_fccd9b35;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fccd9b35 {
extern "C" char DAT_0042af2c[];
extern "C" void __cdecl FUN_00270510(void);
extern "C" int* FUN_002705f0();
extern "C" void FUN_00270370();
typedef unsigned int U;
typedef unsigned __int64 Q;
typedef unsigned __int64 U64_267340;
typedef unsigned int U32_267340;
extern "C" bool FUN_002674f0(const char*, const char*);   // (unb5) bool: sete al / xor al, al (its callers declare bool)
} // namespace fn_fccd9b35
extern "C" int __cdecl __vsnprintf(char*, unsigned int, const char*, char*);
namespace fn_fccd9b35 {
void __stdcall FUN_00354ce2(int*);
typedef unsigned long long QWORD_267aa0;
namespace XAPILIB {
void __stdcall QueryPerformanceCounter(QWORD_267aa0*);
}
typedef unsigned short u16_267ad0;
extern void __stdcall FUN_00355364(void*);
extern int DAT_004cd5ac[];


// 0x00267280 FUN_00267280 (105 B): matches/0x00267280.cpp
// sym: _FUN_00267280
extern "C" void FUN_00267280() {
    (*(unsigned char*)&DAT_00527f5c) = 1;
    FUN_00270510();
    (*(void**)&DAT_00527f50) = DAT_0042af2c;
    FUN_002705f0();
    (*(void**)&DAT_00527f58) = ((void**)&DAT_00527f50);
    DAT_00527f40.allocator = (void*)&DAT_00527f50;
    DAT_00527f40.child = 0;
    DAT_00527f40.next = 0;
    DAT_00527f40.parent = 0;
    unsigned i = 0;
    do {
        MemoryHeapSlot* e = (MemoryHeapSlot*)((char*)DAT_00527c60 + i);
        e->child = 0;
        e->parent = 0;
        e->next = 0;
        e->allocator = (void*)&DAT_00527f50;
        i += sizeof(MemoryHeapSlot);
    } while (i < 46 * sizeof(MemoryHeapSlot));
    FUN_00270370();
}

} // namespace fn_fccd9b35

// 0x002672f0 FUN_002672f0 (74 B): matches/0x002672f0.cpp
// sym: _FUN_002672f0
extern "C" Q __cdecl FUN_002672f0(const char* text, U low, U high) {
    Q value;
    ((U*)&value)[1] = high;
    ((U*)&value)[0] = low;
    if (text) {
        while (*text) {
            value = value * 0x1003fULL ^ (signed __int64)(signed char)*text;
            ++text;
        }
    }
    return value;
}

namespace fn_fccd9b35 {

// 0x00267340 FUN_00267340 (92 B): equivalent/0x00267340.cpp
// sym: _FUN_00267340 @e411990dafd0 @w287036b86d94
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_00267340 @ 0x00267340
extern "C" U64_267340 __cdecl FUN_00267340(const char* text, U32_267340 low, U32_267340 high)
{
    if (text) {
        while (*text) {
            U64_267340 product = ((U64_267340)high << 32 | low) * 0x1003fULL;
            int ch = (signed char)*text;
            if (ch < 'a') ch += 0x20;
            low = (U32_267340)product ^ (U32_267340)ch;
            high = (U32_267340)(product >> 32) ^ (U32_267340)(ch >> 31);
            ++text;
        }
    }
    return ((U64_267340)high << 32) | low;
}


// 0x002673a0 FUN_002673a0 (35 B): matches/0x002673a0.cpp
// sym: _FUN_002673a0
extern "C" int FUN_002673a0(char* s, int h) {
    if (s != 0) {
        char c = *s;
        while (c != 0) {
            h = h * 0x1f + (int)c;
            ++s;
            c = *s;
        }
    }
    return h;
}


// 0x002673d0 FUN_002673d0 (43 B): matches/0x002673d0.cpp
// sym: _FUN_002673d0
extern "C" int FUN_002673d0(char* s, int h) {
    if (s) {
        while (*s) {
            char c = *s;
            h = h * 31 + (c < 'a' ? c + 32 : c);
            ++s;
        }
    }
    return h;
}


// 0x00267400 FUN_00267400 (169 B): matches/0x00267400.cpp
// sym: _FUN_00267400
// data: initFlag = DAT_00528370
extern "C" void FUN_00267400(void) {
    if (!(*(unsigned char*)&DAT_00528370)) {
        unsigned int i = 0;
        do {
            unsigned int v = i << 24;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            ((unsigned int*)&DAT_00527f70)[i] = v;
            ++i;
        } while (i < 256);
        (*(unsigned char*)&DAT_00528370) = 1;
    }
}


// 0x002674f0 FUN_002674f0 (121 B): matches/0x002674f0.cpp
// sym: _FUN_002674f0
extern "C" bool FUN_002674f0(const char* pattern, const char* text) {
    const signed char* s = (const signed char*)pattern;
    const signed char* p = (const signed char*)text;
    int c = *s, a = *p;
    for (;;) {
        if (!a)
            return c ? false : true;   // (unb5) the end of the text matches the end of the pattern only
        if (c && a != '*' && a != '?' && c != a)
            return 0;
        if (!c && a != '*')
            return 0;
        if (a == '*') {
            ++p;
            if (!*p)
                return 1;
            do {
                if (FUN_002674f0((const char*)s, (const char*)p))
                    return 1;
                if (!*s)
                    return 0;
                ++s;
            } while (1);
        }
        ++p;
        ++s;
        c = *s;
        a = *p;
    }
}


// 0x00267660 FUN_00267660 (199 B): equivalent/0x00267660.cpp
// sym: _FUN_00267660 @f000ca1b0477 @w0e33996a9bda
// STATUS: equivalent (tools/equiv.py level 3: 146 inputs, branch coverage 33/34, incomplete)
// FUN_00267660 @ 0x00267660
extern "C" char* __cdecl FUN_00267660(char* path)
{
    if (!path) return path;
    char* end = path;
    while (*end) ++end;
    ++end;
    char* read = path;
    char* write = path;
    while (read < end) {
        char ch = *read;
        if (ch == '.') {
            char next = read[1];
            if (next == '.') {
                if (write < path + 2 || write[-2] == '.' || write[-3] == '.') {
                    write[0] = '.';
                    write[1] = '.';
                    write += 2;
                    read += 2;
                } else {
                    char prev = write[-2];
                    write -= 2;
                    if (prev == '\\' || prev == '/') {
                        read += 2;
                    } else {
                        for (;;) {
                            if (write == path) {
                                read += 3;
                                break;
                            }
                            prev = write[-1];
                            --write;
                            if (prev == '\\') {
                                read += 2;
                                break;
                            }
                            if (prev == '/') {
                                read += 2;
                                break;
                            }
                        }
                    }
                }
            } else if (next == '\\' || next == '/') {
                read += 2;
            } else if (next == 0) {
                if (write > path) --write;
                *write = 0;
                read += 2;
            } else {
                *write++ = *read++;
            }
        } else {
            *write++ = *read++;
        }
    }
    return path;
}


// 0x00267730 FUN_00267730 (42 B): matches/0x00267730.cpp
// sym: _FUN_00267730
extern "C" int __cdecl FUN_00267730(char* buf, unsigned int size, const char* fmt, char* args) {
    int n = _vsnprintf(buf, size, fmt, args);
    if (size <= 0)
        return n;
    buf[size - 1] = 0;
    return n;
}


// 0x00267760 FUN_00267760 (42 B): matches/0x00267760.cpp
// sym: _FUN_00267760
extern "C" void FUN_00267760(char* buffer, unsigned int size, const char* format, ...) {
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, format);
    __vsnprintf(buffer, size, format, args);
#else
    __vsnprintf(buffer, size, format, (char*)&format + 4);
#endif
    if (!(size <= 0U))
        buffer[size - 1] = 0;
}


// 0x00267830 FUN_00267830 (69 B): equivalent/0x00267830.cpp
// sym: _FUN_00267830 @bc1a80ae549f @w75db41fc50c5
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_00267830 @ 0x00267830
extern "C" char * __cdecl FUN_00267830(char *destination, const char *source, int capacity)
{
    int copied = 0;
    if (*source != '\0') {
        while (copied < capacity - 1 && *source != '\0') {
            destination[copied++] = *source++;
        }
    }
    destination[copied] = '\0';
    return destination;
}


// 0x00267880 FUN_00267880 (77 B): equivalent/0x00267880.cpp
// sym: _FUN_00267880 @4573a6ed0ed0 @wf6ce2055cdf7
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_00267880 @ 0x00267880
extern "C" void __cdecl FUN_00267880(char *destination, const char *source, int capacity)
{
    int length = 0;
    while (destination[length] != '\0')
        ++length;

    const char *current = source;
    char value = *current;
    while (value != '\0' && length < capacity - 1) {
        destination[length] = value;
        ++length;
        ++current;
        value = *current;
    }
    destination[length] = '\0';
}


// 0x00267a50 FUN_00267a50 (51 B): matches/0x00267a50.cpp
// sym: _FUN_00267a50
// data: count = DAT_00528378, first = DAT_00528380, second = DAT_00528380 + 4 (one 64-bit value)
extern "C" void FUN_00267a50() {
    (*(int*)&DAT_00528378)++;
    if ((*(int*)&DAT_00528378) == 1) {
        int local[2];
        FUN_00354ce2(local);
        (*(int*)&DAT_00528380) = local[0];
        (*(int*)((char*)&DAT_00528380 + 4)) = local[1];
    }
}


// 0x00267a90 FUN_00267a90 (7 B): matches/0x00267a90.cpp
// sym: _FUN_00267a90
extern "C" void FUN_00267a90() {
    --(*(int*)&DAT_00528378);
}


// 0x00267aa0 FUN_00267aa0 (45 B): matches/0x00267aa0.cpp
// sym: ?FUN_00267aa0@fn_fccd9b35@@YA_KXZ
QWORD_267aa0 FUN_00267aa0() {
    QWORD_267aa0 counter;
    XAPILIB::QueryPerformanceCounter(&counter);
    return counter / *(QWORD_267aa0*)((hulk_intptr)((char*)&DAT_00528380));
}


// 0x00267ad0 FUN_00267ad0 (62 B): matches/0x00267ad0.cpp
// sym: _FUN_00267ad0
extern "C" void FUN_00267ad0(u16_267ad0* out) {
    u8 local[16];  // a SYSTEMTIME: GetLocalTime writes 16 bytes
    FUN_00355364(local);
    u8* dst = (u8*)out;
    *(u16_267ad0*)dst = *(u16_267ad0*)local;
    dst[2] = local[2];
    dst[3] = local[6];
    dst[4] = local[8];
    dst[5] = local[10];
    dst[6] = local[12];
}


// 0x00267b10 FUN_00267b10 (144 B): equivalent/0x00267b10.cpp
// sym: ?FUN_00267b10@fn_fccd9b35@@YAIGEE@Z @bf140c4eb6a4 @wd3e06fee34a8
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 11/12, incomplete)
// FUN_00267b10 @ 0x00267b10
   // days before each month (non-leap), indexed by month
// Day of the week (0..6) for a Gregorian date.
unsigned int __cdecl FUN_00267b10(unsigned short year, unsigned char month, unsigned char day)
{
    bool leap = false;
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        leap = true;

    unsigned int dayOfYear = DAT_004cd5ac[month] + day - 1;
    if (leap && month > 2)
        dayOfYear++;

    int y = (year - 1) % 400;
    unsigned int uy = (unsigned int)y;
    unsigned int centuryAdjust = (uy >> 2) - uy / 100 + uy;
    return (centuryAdjust % 7 + dayOfYear) % 7;
}

} // namespace fn_fccd9b35
