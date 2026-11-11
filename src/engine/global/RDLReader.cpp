// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0027ab90..0x0027aec0 (kind game, layer engine, confidence medium), dominant class RDLReader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3d8c179 {
#define TREE_TU_END }
namespace fn_f3d8c179 {} using namespace fn_f3d8c179;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_f3d8c179 {
int __cdecl FUN_00345804(const char* src, const char* fmt, ...);
struct Stream_27adf0 {
    virtual void s0();
    virtual void release();
    virtual void s2();
    virtual void read(char *buf, int size, int count);
    virtual void s4(); virtual void s5(); virtual void s6();
    virtual void readSize(int *out);
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14();
    virtual int size();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20();
    virtual void reset();
    virtual void s22();
    virtual bool valid();
};
extern "C" void __cdecl thunk_FUN_002710d0(Stream_27adf0 **, const char *, int, int, int, int, int, int);
char *__cdecl FUN_0008d690(int size);
class RDLFile_27ae90 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Ref_27ae90 {
  public:
    virtual void f0();
    virtual void f1();
};
void thunk_FUN_00267090(void*);

} // namespace fn_f3d8c179

// 0x0027ab90 FUN_0027ab90 (159 B): equivalent/0x0027ab90.cpp [wrapped: conflict: RDLReader]
// sym: ??0RDLReader@fn_0027ab90@@QAE@PBD@Z @164c62844621 @wfb48624c88b6
namespace fn_0027ab90 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_0027ab90 @ 0x0027ab90
struct PathRef { const char *s; };

class Stream {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3(void *buf, int size, int flag);
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7(int *size);
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual int vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual bool vfn23();
};

extern void *__cdecl FUN_0008d690(unsigned int n);
void thunk_FUN_002710d0(Stream **out, PathRef name, int a, int b, int c, int d, int e, int f);

class RDLReader {
public:
    RDLReader(const char *name);
    virtual void vfn0_0027adf0(hulk_intptr);

    Stream *stream;
    void *data;
    int pos;
    int size;
    char section[0x40];
};

RDLReader::RDLReader(const char *name)
{
    PathRef ref;
    ref.s = name;
    thunk_FUN_002710d0(&stream, ref, 0, 0, 1, 0, 1, 1);
    stream->vfn21();
    if (stream->vfn23() && stream->vfn15() != 0) {
        stream->vfn7(&size);
        stream->vfn21();
        data = FUN_0008d690(size);
        stream->vfn3(data, size, 1);
        stream->vfn21();
        pos = 0;
    } else {
        stream->vfn1();
        stream = 0;
    }
}
} // namespace fn_0027ab90


// 0x0027ac30 FUN_0027ac30 (192 B): equivalent/0x0027ac30.cpp [wrapped: conflict: RDLReader]
// sym: ?FUN_0027ac30@RDLReader@fn_0027ac30@@QAE_NPAPAD@Z @288887fe0251 @w5070bbbd0c83
namespace fn_0027ac30 {
// STATUS: equivalent (tools/equiv.py level 3: 130 inputs, branch coverage 24/30, incomplete)
// FUN_0027ac30 @ 0x0027ac30
class RDLReader {
public:
    bool FUN_0027ac30(char **out);
    virtual void vfn0();

    void *stream;
    signed char *buf;
    int pos;
    int size;
    char section[0x40];
};

int FUN_00345804(const char *str, const char *fmt, char *out);

bool RDLReader::FUN_0027ac30(char **out)
{
    if (!stream)
        return false;

    signed char *b = buf;
    if (b[pos] < 0x20) {
        while (pos != size) {
            pos++;
            if (buf[pos] >= 0x20)
                break;
        }
    }

    int i = pos;
    if (i == size || b[i] != '[')
        return false;

    if (b[i] != '\r') {
        for (;;) {
            if (b[i] == '\n')
                break;
            if (i == size)
                break;
            signed char next = buf[i + 1];
            i++;
            if (next == '\r')
                break;
        }
    }
    if (i != size)
        b[i] = 0;
    FUN_00345804((const char *)buf + pos, " [ %s ]", section);
    pos = i;
    *out = section;
    return true;
}
} // namespace fn_0027ac30


// 0x0027acf0 FUN_0027acf0 (244 B): equivalent/0x0027acf0.cpp
// sym: ?FUN_0027acf0@ConfigParser_27acf0@owners@@QAE_NPAPAD0@Z @e8ef4523ff87 @w06815e9e4be7
// STATUS: equivalent (tools/equiv.py level 3: 119 inputs, branch coverage 31/38, incomplete)
// FUN_0027acf0 @ 0x0027acf0
bool owners::ConfigParser_27acf0::FUN_0027acf0(char** outKey, char** outValue) {
    if (!source)
        return false;
    while (buf[pos] <= ' ' && pos != end)
        pos++;
    int p = pos;
    if (p == end || buf[p] == '[')
        return false;
    while (buf[p] != '\r' && buf[p] != '\n' && p != end)
        p++;
    if (p != end)
        buf[p] = 0;
    value[0] = 0;
    FUN_00345804(buf + pos, " %s = %[^\r\n]", key, value);
    pos = p;
    int len = 0;
    while (value[len])
        len++;
    for (int i = len - 1; i > 0 && value[i] <= ' '; i--)
        value[i] = 0;
    *outKey = key;
    *outValue = value;
    return true;
}


// 0x0027adf0 RDLReader::vfunc_0 (154 B): equivalent/0x0027adf0.cpp
// sym: ?vfunc_0@RDLReader@@UAEXH@Z @ef485d580f8e @w8c6625d1fb7c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// RDLReader::vfunc_0 @ 0x0027adf0
void RDLReader::vfunc_0(hulk_intptr __p0) { const char * path = (const char *)__p0;

    vfunc_1();
    thunk_FUN_002710d0(&(*(Stream_27adf0 * *)&this->f_04), path, 0, 0, 1, 0, 1, 1);
    (*(Stream_27adf0 * *)&this->f_04)->reset();
    if (!(*(Stream_27adf0 * *)&this->f_04)->valid() || (*(Stream_27adf0 * *)&this->f_04)->size() == 0) {
        (*(Stream_27adf0 * *)&this->f_04)->release();
        (*(Stream_27adf0 * *)&this->f_04) = 0;
        return;
    }
    (*(Stream_27adf0 * *)&this->f_04)->readSize(&this->f_10);
    (*(Stream_27adf0 * *)&this->f_04)->reset();
    (*(char * *)&this->f_08) = FUN_0008d690(this->f_10);
    (*(Stream_27adf0 * *)&this->f_04)->read((*(char * *)&this->f_08), this->f_10, 1);
    (*(Stream_27adf0 * *)&this->f_04)->reset();
    this->f_0c = 0;
}


// 0x0027ae90 RDLReader::vfunc_1 (40 B): matches/0x0027ae90.cpp
// sym: ?vfunc_1@RDLReader@@UAEXXZ
void RDLReader::vfunc_1() {
    if ((*(Ref_27ae90 * *)&this->f_04)) {
        (*(Ref_27ae90 * *)&this->f_04)->f1();
        (*(Ref_27ae90 * *)&this->f_04) = 0;
        if ((*(void * *)&this->f_08))
            thunk_FUN_00267090((*(void * *)&this->f_08));
    }
}

