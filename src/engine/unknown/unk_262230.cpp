// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00262230..0x002628a0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f30a0110 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f30a0110 {} using namespace fn_f30a0110;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f30a0110 {
class Obj_262400 {
  public:
    hulk_uintptr FnA_0023f990();
    char* FnB_0023fb00();
};
class P2_262400 {
  public:
};
struct PathString {
    unsigned int FUN_0023f990();
    void FUN_0023fb10(unsigned int length);
};
struct Local {
    char data[12];
};
struct Result {
    unsigned char FUN_00240310(int);
};
extern "C" void * __cdecl FUN_00262400(void *, void *);
struct Str_2625a0 {
    char data[12];
    bool FUN_00240310(Str_2625a0* other);
};
struct Str_262620 {
    char data[12];
    unsigned int FUN_0023f990();
    char* FUN_0023fbb0();
    void FUN_0023fb10(unsigned int newLength);
    Str_262620* FUN_002401f0(Str_262620* out);
    void FUN_00240190(Str_262620* src);
    void FUN_00240060();
};
extern "C" void * __cdecl FUN_00262460(void *);
class Path_262700 {
  public:
    unsigned int Length_0023f990();
    void SetLength_0023fb10(unsigned int);
    char* Data_0023fb00();
    void Finish();
};
struct Temp_262700 {
    char pad[12];
};


// 0x00262230 FUN_00262230 (53 B): matches/0x00262230.cpp
// sym: _FUN_00262230
extern "C" unsigned int FUN_00262230(float scale, unsigned int n) {
    unsigned int v = (unsigned int)((float)n * scale);
    if (v < 0xbc)
        return 0xbc;
    if (v > 0x2edef)
        return 0x2edef;
    return v;
}


// 0x00262270 FUN_00262270 (60 B): matches/0x00262270.cpp
// sym: _FUN_00262270
// data: minimum = DAT_0042ab50
extern "C" int FUN_00262270(float x) {
    if (x < DAT_0042ab50)
        x = -100.0f;
    int n = (int)(__int64)(x * 100.0f);
    if (n > 0)
        return 0;
    if (n < -10000)
        n = -10000;
    return n;
}


// 0x00262320 FUN_00262320 (5 B): matches/0x00262320.cpp
// sym: ?FUN_00262320@fn_f30a0110@@YAPAHPAH@Z
int* FUN_00262320(int* p) {
    return p;
}


// 0x00262400 FUN_00262400 (86 B): matches/0x00262400.cpp
// sym: _FUN_00262400
extern "C" void* FUN_00262400(void * obj, void * p2) {
    if (((Obj_262400 *)obj)->FnA_0023f990() > 0) {
        char* start = ((Obj_262400 *)obj)->FnB_0023fb00();
        char* p = (char*)((Obj_262400 *)obj)->FnA_0023f990();
        p += (hulk_uintptr)((Obj_262400 *)obj)->FnB_0023fb00();
        while (p >= start) {
            if (*p == '.') {
                ((owners::String_23fe50 *)(((P2_262400 *)p2)))->FUN_0023fe50((const char *)(p + 1));
                return (void*)((P2_262400 *)p2);
            }
            --p;
        }
    }
    return (void*)((P2_262400 *)p2);
}


// 0x00262460 FUN_00262460 (214 B): equivalent/0x00262460.cpp
// sym: _FUN_00262460 @45f5ccd1343e @w50fef88b1cf8
// STATUS: equivalent (tools/equiv.py level 3: 128 inputs, branch coverage 33/34, incomplete)
// FUN_00262460 @ 0x00262460
extern "C" void * __cdecl FUN_00262460(void * path) {
    unsigned int length = ((PathString *)path)->FUN_0023f990();
    if (length != 0) {
        char* buffer = ((owners::String_23fbb0 *)(((PathString *)path)))->FUN_0023fbb0();
        char* end = buffer + length + 1;
        char* read = buffer;
        char* write = buffer;
        while (read < end) {
            char ch = *read;
            if (ch == '.') {
                char next = read[1];
                if (next == '.') {
                    unsigned int skip = 2;
                    if (write < buffer + 2 || write[-2] == '.' || write[-3] == '.') {
                        write[0] = '.';
                        write[1] = '.';
                        write += 2;
                    } else {
                        char previous = write[-2];
                        write -= 2;
                        while (previous != '\\' && previous != '/') {
                            if (write == buffer) {
                                skip = 3;
                                break;
                            }
                            previous = write[-1];
                            --write;
                        }
                    }
                    read += skip;
                    continue;
                }
                if (next == '\\' || next == '/') {
                    read += 2;
                    continue;
                }
                if (next == 0) {
                    if (write > buffer) --write;
                    *write = 0;
                    read += 2;
                    continue;
                }
            }
            *write++ = ch;
            ++read;
        }
        unsigned int newLength = 0;
        while (buffer[newLength] != 0) ++newLength;
        ((PathString *)path)->FUN_0023fb10(newLength);
    }
    return (PathString *)((PathString *)path);
}


// 0x00262550 FUN_00262550 (66 B): matches/0x00262550.cpp
// sym: ?FUN_00262550@fn_f30a0110@@YAEHH@Z
unsigned char __cdecl FUN_00262550(int first, int second) {
    Local local;
    ((owners::Thing_23fd20 *)&local)->FUN_0023fd20(0x100);
    unsigned char value = ((Result *)FUN_00262400((void *)(hulk_uintptr)(int)first, (Local *)(&local)))->FUN_00240310(second);
    ((owners::Str_240060 *)&local)->FUN_00240060();
    return value;
}


// 0x002625a0 FUN_002625a0 (103 B): matches/0x002625a0.cpp
// sym: ?FUN_002625a0@fn_f30a0110@@YA_NPAUStr_2625a0@1@0@Z
// FUN_002625a0 @ 0x002625a0
bool __cdecl FUN_002625a0(Str_2625a0* first, Str_2625a0* second) {
    Str_2625a0 a;
    Str_2625a0 b;
    ((owners::Thing_23fd20 *)&a)->FUN_0023fd20(0x100);
    ((owners::Thing_23fd20 *)&b)->FUN_0023fd20(0x100);
    bool result = ((Str_2625a0 *)FUN_00262400((Str_2625a0 *)first, (Str_2625a0 *)(&a)))->FUN_00240310(((Str_2625a0 *)FUN_00262400((Str_2625a0 *)second, (Str_2625a0 *)(&b))));
    ((owners::Str_240060 *)&b)->FUN_00240060();
    ((owners::Str_240060 *)&a)->FUN_00240060();
    return result;
}


// 0x00262620 FUN_00262620 (142 B): equivalent/0x00262620.cpp
// sym: ?FUN_00262620@fn_f30a0110@@YAPAUStr_262620@1@PAU21@@Z @83eea852ea20 @wa15992654213
// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 14/14)
// FUN_00262620 @ 0x00262620
// Normalises a path string in place: '/' becomes '\\', then any trailing separator is removed.
Str_262620* __cdecl FUN_00262620(Str_262620* path) {
    Str_262620 tmp;
    if (path->FUN_0023f990() > 0) {
        for (char* p = path->FUN_0023fbb0(); *p != 0; p++) {
            if (*p == '/')
                *p = '\\';
        }
    }
    FUN_00262460((Str_262620 *)path);
    unsigned int len = path->FUN_0023f990();
    if (len > 0) {
        char* p = path->FUN_0023fbb0();
        char last = p[len - 1];
        if (last == '\\' || last == '/') {
            p[len - 1] = 0;
            path->FUN_0023fb10(len - 1);
        }
    }
    path->FUN_00240190(path->FUN_002401f0(&tmp));
    tmp.FUN_00240060();
    return path;
}


// 0x00262700 FUN_00262700 (149 B): matches/0x00262700.cpp
// sym: _FUN_00262700
extern "C" Path_262700* FUN_00262700(Path_262700* self, Path_262700* other) {
    unsigned int n = self->Length_0023f990();
    if (n > 0) {
        char* s = ((owners::String_23fbb0 *)self)->FUN_0023fbb0();
        char c = s[n - 1];
        if (c == '\\' || c == '/') {
            s[n - 1] = 0;
            --n;
            self->SetLength_0023fb10(n);
        }
    }
    unsigned int m = other->Length_0023f990();
    if (m > 0) {
        char* p = self->Data_0023fb00();
        char c = *p;
        if (c != '\\' && c != '/') {
            if (self->Length_0023f990() > 0) {
                Temp_262700 t;
                char* x = ((char *)((owners::String_23fc40 *)&t)->FUN_0023fc40("\\", (hulk_intptr)0));
                ((owners::String_23ff50 *)self)->FUN_0023ff50((owners::String_23ff50 *)x);
                ((owners::Str_240060 *)&t)->FUN_00240060();
            }
        }
        ((owners::String_23ff50 *)self)->FUN_0023ff50((owners::String_23ff50 *)(Path_262700 *)other);
    }
    return self;
}


// 0x00262800 FUN_00262800 (5 B): matches/0x00262800.cpp
// sym: _FUN_00262800
extern "C" unsigned long long FUN_00262800() {
    return 0;
}


// 0x00262820 FUN_00262820 (15 B): matches/0x00262820.cpp
// sym: _FUN_00262820
extern "C" const char* FUN_00262820(int index) {
    return ((const char* const*)&DAT_0042ab5c)[index * 3];
}

} // namespace fn_f30a0110
