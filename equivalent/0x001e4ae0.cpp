// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001e4ae0 @ 0x001e4ae0
#include "decls/address.h"
inline void *operator new(unsigned int, void *p) { return p; }

class CSPHulkProp;

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

extern "C" unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

struct Handle_1e4ae0 { char pad[4]; };

class Factory_1e4ae0 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Handle_1e4ae0 *f3(content::LoadInventory::DynamicCaster<CSPHulkProp> *caster, unsigned int lo, unsigned int hi);
};

struct Holder44_1e4ae0 { Factory_1e4ae0 *FUN_00203d70(); };
struct Holder28_1e4ae0 { Holder44_1e4ae0 *FUN_000862a0(); };
struct World { char pad0[0x54]; Holder28_1e4ae0 *holder; };
extern int DAT_004e2748;

struct Mat_1e4ae0 {
    float m[16];
    void FUN_0022b980();
};

int __cdecl FUN_000964a0(char *buf, int n, const char *fmt, const char *a, const char *b);
int __cdecl FUN_00267760(char *buf, int n, const char *fmt, const char *a, int b);

struct Frame_1e4ae0 {
    char caster[4];
    union {
        char name[0x80];
        Mat_1e4ae0 mat;
    } u;
    char text[0x100];
};

class Spawner_1e4ae0 {
public:
    int FUN_001dbfe0(const char *key);
    int FUN_001e4760(Handle_1e4ae0 *h, const char *text, int a, Mat_1e4ae0 *mat, int p5, int p6, int p7);
    int FUN_001e4ae0(const char *key, const char *name, const char *prefix, int p3, int p4, int p5);
};

int Spawner_1e4ae0::FUN_001e4ae0(const char *key, const char *name, const char *prefix, int p3, int p4, int p5)
{
    unsigned int cookie = DAT_004d9968;
    Frame_1e4ae0 f;
    Factory_1e4ae0 *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    unsigned __int64 id = FUN_002672f0(name, 0, 0);
    Handle_1e4ae0 *h = factory->f3(new (f.caster) content::LoadInventory::DynamicCaster<CSPHulkProp>,
                            (unsigned int)id, (unsigned int)(id >> 32));
    if (!h) {
        FUN_000964a0(f.u.name, 0x80, "%s_%s", prefix, name);
        id = FUN_002672f0(f.u.name, 0, 0);
        h = factory->f3(new (f.caster) content::LoadInventory::DynamicCaster<CSPHulkProp>,
                        (unsigned int)id, (unsigned int)(id >> 32));
    }
    int result = 0;
    if (h) {
        f.u.mat.FUN_0022b980();
        if (FUN_001dbfe0(key) < 0) {
            result = FUN_001e4760(h, key, 0, &f.u.mat, p3, p4, p5);
        } else {
            FUN_00267760(f.text, 0x100, "%sZXQKJ%d", key, DAT_004e2748);
            DAT_004e2748 = DAT_004e2748 + 1;
            result = FUN_001e4760(h, f.text, 0, &f.u.mat, p3, p4, p5);
        }
    }
    __security_check_cookie(cookie);
    return result;
}
