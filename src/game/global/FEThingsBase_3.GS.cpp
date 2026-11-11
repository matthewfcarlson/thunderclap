// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000f1570..0x000f8690 (kind game, layer game, confidence high), dominant class FEThingsBase
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f1b16f90 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f1b16f90 {} using namespace fn_f1b16f90;
#include "game/global.h"

// ---- declarations shared by the functions below
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_f1b16f90 {
namespace content { namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};
} }
namespace content { namespace LoadInventory {
template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
} }
} // namespace fn_f1b16f90
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int sprintf(char *, const char *, ...);
#endif
namespace fn_f1b16f90 {
class Ref_f2a80 {
public:
    virtual void AddRef();
    virtual void Release();
};
class Loader_f2a80 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Ref_f2a80 *v3(content::LoadInventory::DynamicCasterBase *caster, unsigned int lo, unsigned int hi);
};
class Owner_f2a80 {
public:
    char pad000[0x194];
    Ref_f2a80 *drawables[10];
    void LoadDrawables(const char *prefix);
};
class Ref_f2b10 {
public:
    virtual void AddRef();
    virtual void Release();
};
class Loader_f2b10 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Ref_f2b10 *v3(content::LoadInventory::DynamicCasterBase *caster, unsigned int lo, unsigned int hi);
};
class Owner_f2b10 {
public:
    char pad000[0x1bc];
    Ref_f2b10 *drawables[10];
    void LoadDrawables(const char *prefix);
};
} // namespace fn_f1b16f90
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#endif
namespace fn_f1b16f90 {
extern "C" void __cdecl FUN_000f6af0(char*, char*, unsigned int);
extern "C" void __cdecl FUN_000f6b50(char*, const char*, int);
extern "C" void __cdecl FUN_000f6bd0(char *, const char *, const char *);
} // namespace fn_f1b16f90
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *memset(void *dst, int c, unsigned int n);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);
#endif
namespace fn_f1b16f90 {
void *__cdecl FUN_00263ea0(unsigned int size);
class LoadStream_f7a80 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad04[8];
    char ok;
    LoadStream_f7a80 *FUN_00264430(const char *name, int a, int b);
    void FUN_002647e0(void *out, int a, int b, int c);
};
class StringTable_f7a80 {
public:
    unsigned short *pool;
    int poolCapacity;
    int used;
    unsigned short **strings;
    int maxStrings;
    int count;
    unsigned long long *hashes;
    int maxHashes;
    int hashCount;

    int FUN_000f7080(unsigned short *buf, int n, LoadStream_f7a80 *file);
    void FUN_000f76c0(unsigned short *line);
    int FUN_000f7790(unsigned short *line);
    bool FUN_000f7a80(const char *filename);
};
extern "C" void __cdecl FUN_00294c70(int src, char* dst, int size);
class Manager_f8500 {
  public:
    int FUN_000f7240(unsigned long long key);
};
class Entry_f8500 {
  public:
    void FUN_000f8500(const char* name, Manager_f8500* manager, char flag);
    char pad_00[0x10];
    short* text;
    int id;
    char pad_18[8];
    int field_20;
};
extern "C" Manager_f8500* FUN_000fc1b0();
int FUN_000dfcc0(char* dst, int size, const char* fmt, ...);
extern "C" void* FUN_0008d6d0(unsigned int size);
extern "C" void FUN_000fb740(short* dst, const char* src, hulk_intptr count);

} // namespace fn_f1b16f90

// 0x000f25f0 FUN_000f25f0 (139 B): equivalent/0x000f25f0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ??0FEBillboardAnimation@fn_000f25f0@@QAE@HPBD@Z @cf96fc34271c @w8b7da9de135a
namespace fn_000f25f0 {
// STATUS: equivalent (tools/equiv.py level 3: 17954 inputs, branch coverage 6/6)
// FUN_000f25f0 @ 0x000f25f0
// cl-flags: /GS
// FEBillboardAnimation constructor: look the billboard object up by name when the name is short enough.

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};
template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}
namespace pure3d { class BillboardObject; }


class Ref_f25f0 {
public:
    virtual void AddRef();
    virtual void Release();
};
class Loader_f25f0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Ref_f25f0 *v3(content::LoadInventory::DynamicCaster<pure3d::BillboardObject> *caster, unsigned int lo, unsigned int hi);
};
struct Id64_f25f0 { unsigned int lo; unsigned int hi; };
extern "C++" __declspec(nothrow) Id64_f25f0 __cdecl FUN_0027b020(const char *name);

// equiv-map: ??0FEBase@@QAE@HPBD@Z = 0x000e13c0
class FEAnimation_f25f0 {
public:
    FEAnimation_f25f0(int a, const char *name);
    virtual void v0();
    char pad04[8];
    Ref_f25f0 *p0c;
    char pad10[0x50];
};

class FEBillboardAnimation : public FEAnimation_f25f0 {
public:
    FEBillboardAnimation(int a, const char *name);
    virtual void v0();
};

FEBillboardAnimation::FEBillboardAnimation(int a, const char *name) : FEAnimation_f25f0(a, name)
{
    char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
    const char *start = name + 1;
    const char *end = name;
    while (*end++) {
    }
    hulk_uintptr length = end - start;
    if (length <= 0xfb) {
        Loader_f25f0 *ld = (*(Loader_f25f0**)&DAT_004dd9cc);
        Id64_f25f0 id = FUN_0027b020(name);
        content::LoadInventory::DynamicCaster<pure3d::BillboardObject> caster;
        Ref_f25f0 *r = ld->v3(&caster, id.lo, id.hi);
        if (r != 0) {
            p0c = 0;
        }
    }
}
} // namespace fn_000f25f0

namespace fn_f1b16f90 {

// 0x000f2a80 FUN_000f2a80 (132 B): equivalent/0x000f2a80.cpp
// sym: ?LoadDrawables@Owner_f2a80@fn_f1b16f90@@QAEXPBD@Z @3be221d6766e @w8213e3f5440a
// STATUS: equivalent (tools/equiv.py level 3: 4866 inputs, branch coverage 4/4)
// FUN_000f2a80 @ 0x000f2a80
void Owner_f2a80::LoadDrawables(const char *prefix)
{
    char name[0x20];
    for (int i = 1; i <= 10; i++) {
        sprintf(name, "%s_%d", prefix, i);
        Loader_f2a80 *ld = (*(Loader_f2a80**)&DAT_004dd9cc);
        unsigned __int64 id = FUN_0027b020(name);
        content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
        Ref_f2a80 *r = ld->v3(&caster, (unsigned int)id, (unsigned int)(id >> 32));
        drawables[i - 1] = r;
        if (r != 0)
            r->AddRef();
    }
}


// 0x000f2b10 FUN_000f2b10 (132 B): equivalent/0x000f2b10.cpp
// sym: ?LoadDrawables@Owner_f2b10@fn_f1b16f90@@QAEXPBD@Z @ceea9f6868cb @w124642dfee1b
// STATUS: equivalent (tools/equiv.py level 3: 4957 inputs, branch coverage 4/4)
// FUN_000f2b10 @ 0x000f2b10
void Owner_f2b10::LoadDrawables(const char *prefix)
{
    char name[0x20];
    for (int i = 1; i <= 10; i++) {
        sprintf(name, "%s_%d", prefix, i);
        Loader_f2b10 *ld = (*(Loader_f2b10**)&DAT_004dd9cc);
        unsigned __int64 id = FUN_0027b020(name);
        content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
        Ref_f2b10 *r = ld->v3(&caster, (unsigned int)id, (unsigned int)(id >> 32));
        drawables[i - 1] = r;
        if (r != 0)
            r->AddRef();
    }
}


// 0x000f6cb0 FUN_000f6cb0 (86 B): matches/0x000f6cb0.cpp
// sym: _FUN_000f6cb0
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 0/0)
// FUN_000f6cb0 @ 0x000f6cb0
extern "C" void __cdecl FUN_000f6cb0(char* path, unsigned int arg) {
    struct Frame { char prefix[40];  } frame;
    char* dot = strchr(path, '.');
    hulk_uintptr length = dot - path;
    strncpy(frame.prefix, path, length);
    frame.prefix[length] = 0;
    FUN_000f6af0(frame.prefix, dot + 1, arg);
}


// 0x000f6d10 FUN_000f6d10 (86 B): matches/0x000f6d10.cpp
// sym: _FUN_000f6d10
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 0/0)
// FUN_000f6d10 @ 0x000f6d10
extern "C" void __cdecl FUN_000f6d10(const char* filename, int value)
{
    struct Scratch { char stem[40];  } scratch;
    const char* dot = strchr(filename, '.');
    hulk_uintptr length = dot - filename;
    strncpy(scratch.stem, filename, length);
    scratch.stem[length] = '\0';
    FUN_000f6b50(scratch.stem, dot + 1, value);
}


// 0x000f6d70 FUN_000f6d70 (86 B): matches/0x000f6d70.cpp
// sym: _FUN_000f6d70
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 0/0)
// FUN_000f6d70 @ 0x000f6d70
extern "C" void __cdecl FUN_000f6d70(const char *filename, const char *other)
{
    char name[40];
    const char *dot = strchr(filename, '.');
    unsigned int length = (unsigned int)(dot - filename);
    strncpy(name, filename, length);
    name[length] = 0;
    FUN_000f6bd0(name, dot + 1, other);
}


// 0x000f7a80 FUN_000f7a80 (600 B): equivalent/0x000f7a80.cpp
// sym: ?FUN_000f7a80@StringTable_f7a80@fn_f1b16f90@@QAE_NPBD@Z @91e22f53f762 @wd772c1b7d4f7
// STATUS: equivalent (tools/equiv.py level 3: 101 inputs, branch coverage 38/46, incomplete)
// FUN_000f7a80 @ 0x000f7a80
// checked with equiv.py --time-budget 3600 (at the defaults most inputs hit the time budget)
bool StringTable_f7a80::FUN_000f7a80(const char *filename)
{
    unsigned short line[0x1000];
    char key[0x80];
    char hdr[4];

    const char *fn = filename;
    if (fn == 0 || *fn == 0)
        fn = "frontend\\lang\\str_en.txt";

    if (used != 0) {
        int bytes = maxStrings * 4;
        unsigned short **p = strings;
        used = 0;
        memset(p, 0, bytes);
    }

    LoadStream_f7a80 *file = 0;
    void *mem = FUN_00263ea0(0x48);
    if (mem != 0)
        file = ((LoadStream_f7a80 *)mem)->FUN_00264430(fn, 0, 1);

    if (file->ok == 0) {
        file->vfunc_1();
        return false;
    }

    file->FUN_002647e0(hdr, 1, 2, 1);
    line[0] = *(unsigned short *)hdr;

    int more = FUN_000f7080(line, 0x1000, file);
    while (more != 0) {
        FUN_000f76c0(line);
        int n = FUN_000f7790(line) + 1;
        if (line[0] != '#' && line[0] != 0) {
            unsigned short *p = line;
            do {
                if (*p == ' ' || *p == '\t')
                    break;
                p++;
            } while (*p != 0);
            if (*p != 0) {
                *p = 0;
                unsigned short c = p[1];
                p++;
                if (c != 0) {
                    bool done = false;
                    while (c == ' ' || c == '\t') {
                        c = p[1];
                        p++;
                        if (c == 0) {
                            done = true;
                            break;
                        }
                    }
                    if (!done && *p != 0) {
                        n -= (int)(p - line);
                        char *d = key;
                        const unsigned short *s = line;
                        if (*s != 0) {
                            do {
                                *d++ = (char)*s;
                                s++;
                            } while (*s != 0);
                        }
                        *d = 0;
                        int start = used;
                        if ((start + n) * 2 > poolCapacity)
                            break;
                        memcpy((char *)pool + start * 2, p, n * 2);
                        int e = count;
                        used = used + n;
                        count = e + 1;
                        if (e >= maxStrings)
                            break;
                        strings[e] = (unsigned short *)((char *)pool + start * 2);
                        if (e >= maxHashes)
                            break;
                        hashes[e] = FUN_0027b020(key);
                        hashCount = e + 1;
                    }
                }
            }
        }
        more = FUN_000f7080(line, 0x1000, file);
    }
    file->vfunc_1();
    return true;
}

} // namespace fn_f1b16f90

// 0x000f7f60 FUN_000f7f60 (121 B): matches/0x000f7f60.cpp
// sym: ?FUN_000f7f60@Printer_f7f60@owners@@QAEXHHHHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000f7f60 @ 0x000f7f60
void owners::Printer_f7f60::FUN_000f7f60(int src, int a2, int a3, int a4, int a5, int a6) {
    struct Frame {
        char text[0x400];
    } fr;
    FUN_00294c70(src, fr.text, 0x200);
    FUN_000f7d60(fr.text, a2, a3, a4, a5, a6);
}

namespace fn_f1b16f90 {

// 0x000f8500 FUN_000f8500 (382 B): equivalent/0x000f8500.cpp
// sym: ?FUN_000f8500@Entry_f8500@fn_f1b16f90@@QAEXPBDPAVManager_f8500@2@D@Z @3c4fc29be76f @w6422d36a8b85
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 26/26)
// FUN_000f8500 @ 0x000f8500
void Entry_f8500::FUN_000f8500(const char* name, Manager_f8500* manager, char flag) {
    char prefix[0x20];
    char full[0x100];
    if (name == 0) {
        return;
    }
    if (manager == 0) {
        manager = FUN_000fc1b0();
        if (manager == 0) {
            return;
        }
    }
    field_20 = -1;
    int newId = manager->FUN_000f7240(FUN_0027b020(name));
    id = newId;
    if (newId != -1) {
        if (text != 0) {
            FUN_0008d340(text);
            text = 0;
        }
        return;
    }
    if (text != 0) {
        FUN_0008d340(text);
        text = 0;
    }
    FUN_000dfcc0(prefix, 0x20, "[NITB]");
    if (name[0] != 0 && flag != 0 && (*(char*)&DAT_004dd8e8) != 0)
        FUN_000dfcc0(full, 0x100, "%s %s", prefix, name);
    else
        FUN_000dfcc0(full, 0x100, "%s", name);
    hulk_intptr count = strlen(prefix) + strlen(name) + 2;
    text = (short*)FUN_0008d6d0(count * 2);
    if (text != 0) {
        FUN_000fb740(text, full, count);
        id = -1;
    }
}

} // namespace fn_f1b16f90
