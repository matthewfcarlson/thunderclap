// STATUS: equivalent (tools/equiv.py level 3: 964 inputs, branch coverage 26/26)
// FUN_000c1430 @ 0x000c1430
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;
inline void *operator new(unsigned int, void *p) throw() { return p; }
void __cdecl FUN_0008d340(void *p);

struct Id64_c1430 {
    unsigned int lo, hi;
    void FUN_0027af50() throw();
};

struct Id40 {
    Id64_c1430 a, b, c, d;
    char pad20[8];
};

class Releasable_c1430 {
public:
    virtual void v0();
    virtual void release();
};

class Owned0 {
public:
    virtual ~Owned0();
    virtual void v1();
};

class Owned1 {
public:
    virtual void v0();
    virtual ~Owned1();
};

struct Holder3ef0 {
    char pad0[4];
    void FUN_000b3ef0();
};

class Owned0b : public Owned0 {
public:
    void FUN_000b3ef0();
};

struct Done {
    void FUN_00092be0();
};

class __declspec(novtable) MethodBase_c1430 {
public:
    virtual void m0();
    char pad_04[0xc];
    MethodBase_c1430(const char *n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char *, int);
    void FUN_001d04a0();
};

template <class T, class R, class A, class B>
class Method2 : public MethodBase_c1430 {
public:
    typedef R (T::*Fn)(A, B);
    Method2(const char *name, Fn f) : MethodBase_c1430(name, 2) {
        fn = f;
        c18 = FUN_001d04d0(((const char*)&DAT_0048e100));
        c10 = FUN_001d04d0(((const char*)&DAT_0048e0f0));
        c11 = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
    char c10;
    char c11;
    char pad12[6];
    char c18;
    char pad19[3];
    Fn fn;
};

template <class T, class R, class A, class B>
class Closure2 : public Method2<T, R, A, B> {
public:
    Closure2(const char *name, T *o, Fn f) : Method2<T, R, A, B>(name, f), owner(o) {}
    T *owner;
};

void FUN_000b45a0(const char *);
void FUN_000b45b0(const char *);
void FUN_000b45d0(const char *);
struct Registry_c1430;

class CFEManager {
public:
    virtual void v0();
    char pad04[0x1c - 4];
    Releasable_c1430 *f1c;
    Releasable_c1430 *f20;
    Releasable_c1430 *f24;
    char pad28[0x48 - 0x28];
    int f48;
    Done *f4c;
    char pad50[0x60 - 0x50];
    Owned0b *f60;
    Owned1 *f64;
    Releasable_c1430 *f68;
    void *list6c[0x80];
    void *list26c[0x80];
    char pad46c[0x470 - 0x46c];
    Id40 ids[0x80];
    void FUN_000bc750();
    void FUN_000bc1e0();
    void FUN_000b47b0(const char *, const char *);
    void FUN_000b4850();
    void FUN_000bc230();
    void FUN_000bb5c0();
    void FUN_000b4b60(const char *, const char *);
    void FUN_000b43e0();
    void FUN_000b5490();
    void FUN_000b54d0();
    void FUN_000b5530();
    void FUN_000b5590();
    void FUN_000b5670();
    void FUN_000b5710();
    void FUN_000b5790();
    void FUN_000b57d0();
    void FUN_000b5810();

    void FUN_000c1430();
};

struct Registry_c1430 {
    void FUN_000c0a20(const char *, CFEManager *, void (CFEManager::*)());
    void FUN_000c0aa0(const char *, CFEManager *, void (CFEManager::*)());
    void FUN_000c0b80(const char *, CFEManager *, void (CFEManager::*)());
    void FUN_000c0be0(const char *, CFEManager *, void (CFEManager::*)());
    void FUN_000c0c40(const char *, CFEManager *, void (CFEManager::*)());
    void FUN_000c0cc0(const char *, CFEManager *, void (CFEManager::*)());
    void FUN_000bfd20(const char *, void (*)(const char *));
    void FUN_000bfda0(const char *, void (*)(const char *));
    void FUN_001d26d0(const char *, MethodBase_c1430 *);
};

Registry_c1430 *FUN_001d4c90();
void FUN_000fc3e0();

void CFEManager::FUN_000c1430()
{
    unsigned int cookie = DAT_004d9968;
    new (this) CFEManager;
    Registry_c1430 *reg = FUN_001d4c90();
    if (reg) {
        reg->FUN_000c0a20("fe_StartNextMission", this, &CFEManager::FUN_000bc750);
        reg->FUN_000bfd20("fe_changeScreen", FUN_000b45a0);
        reg->FUN_000bfda0("fe_backScreen", FUN_000b45b0);
        reg->FUN_000bfd20("fe_loadScript", FUN_000b45d0);
        reg->FUN_000c0aa0("fe_doScreen", this, &CFEManager::FUN_000bc1e0);
        {
            Closure2<CFEManager, void, const char *, const char *> c("fe_fullscreenMessage", this, &CFEManager::FUN_000b47b0);
            reg->FUN_001d26d0("fe_fullscreenMessage", &c);
            c.FUN_001d04a0();
        }
        reg->FUN_000c0b80("fe_fullscreenMessageEx", this, &CFEManager::FUN_000b4850);
        reg->FUN_000c0be0("fe_fullscreenQuestion", this, &CFEManager::FUN_000bc230);
        reg->FUN_000c0a20("fe_unlockStory", this, &CFEManager::FUN_000bb5c0);
        {
            Closure2<CFEManager, void, const char *, const char *> c("AddValidMission", this, &CFEManager::FUN_000b4b60);
            reg->FUN_001d26d0("AddValidMission", &c);
            c.FUN_001d04a0();
        }
        reg->FUN_000c0c40("fe_GetSelectedMove", this, &CFEManager::FUN_000b43e0);
        reg->FUN_000c0aa0("fe_SetupSMSuccessName", this, &CFEManager::FUN_000b5490);
        reg->FUN_000c0b80("fe_SetupSMSuccessResult", this, &CFEManager::FUN_000b54d0);
        reg->FUN_000c0b80("fe_SetupSMSuccessRecord", this, &CFEManager::FUN_000b5530);
        reg->FUN_000c0cc0("fe_SetupSMSuccessRanking", this, &CFEManager::FUN_000b5590);
        reg->FUN_000c0cc0("fe_SetupSMSuccessSmashPointsAward", this, &CFEManager::FUN_000b5670);
        reg->FUN_000c0b80("fe_SetupSMSuccessNewRecord", this, &CFEManager::FUN_000b5710);
        reg->FUN_000c0aa0("fe_SetupSMFailName", this, &CFEManager::FUN_000b5790);
        reg->FUN_000c0aa0("fe_SetupSMFailHint", this, &CFEManager::FUN_000b57d0);
        reg->FUN_000c0b80("fe_SetupSMFailRecord", this, &CFEManager::FUN_000b5810);
        if (f1c) {
            f1c->release();
            f1c = 0;
        }
        if (f20) {
            f20->release();
            f20 = 0;
        }
        if (f24) {
            f24->release();
            f24 = 0;
        }
        if (f60) {
            f60->FUN_000b3ef0();
            if (f60) {
                delete f60;
                f60 = 0;
            }
        }
        FUN_000fc3e0();
        if (f68) {
            f68->release();
            f68 = 0;
        }
        int i;
        for (i = 0; i < 0x80; i++) {
            if (!list6c[i])
                break;
            FUN_0008d340(list6c[i]);
            list6c[i] = 0;
        }
        for (i = 0; i < 0x80; i++) {
            if (!list26c[i])
                break;
            FUN_0008d340(list26c[i]);
            list26c[i] = 0;
        }
        if (f64) {
            delete f64;
            f64 = 0;
        }
        f4c->FUN_00092be0();
        f4c = 0;
        f48 = 0;
    }
    for (int i = 0x7f; i >= 0; i--) {
        ids[i].d.FUN_0027af50();
        ids[i].c.FUN_0027af50();
        ids[i].b.FUN_0027af50();
        ids[i].a.FUN_0027af50();
    }
    __security_check_cookie(cookie);
}
