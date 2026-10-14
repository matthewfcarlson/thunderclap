// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_000b78e0 @ 0x000b78e0
// equiv-map: ??_R0?AVFEObject@@@8 = 0x0049dba4
// equiv-map: ??_R0?AVTextSelector@@@8 = 0x0049dbbc
// equiv-map: ??_R0?AVCUnlockable@@@8 = 0x0049dab8
// equiv-map: ??_R0?AVCUnlockableBlonskyFile@@@8 = 0x0049dad4

class FEObject {
public:
    virtual void f0();
};

class Target_b78e0 {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35(); virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39(); virtual void f40(); virtual void f41(); virtual void f42(); virtual void f43(); virtual void f44(); virtual void f45(); virtual void f46(); virtual void f47(); virtual void f48();
    virtual void f49(int v);
};

class CUnlockable {
public:
    virtual void u0();
    int FUN_00091d20();
};

class CUnlockableBlonskyFile : public CUnlockable {
public:
    virtual void u1();
};

struct Link8_b78e0 {
    char pad0[4];
    Target_b78e0 *target;          // 0x04
};

struct Link14 {
    char pad0[8];
    Link8_b78e0 *next;             // 0x08
};

class TextSelector : public FEObject {
public:
    char pad04[0x14 - 4];
    Link14 *link;            // 0x14
    char pad18[0x154 - 0x18];
    char *list;              // 0x154
    char pad158[0x1d58 - 0x158];
    int count;               // 0x1d58
};

struct Store {
    CUnlockable *FUN_00092ad0(char *name);
};

struct Cursor_b78e0 {
    void FUN_001be060();
};

FEObject *__cdecl FUN_000fc260(const char *name);

class Screen_b78e0 {
public:
    char pad0[0x4c];
    Store *store;            // 0x4c
    char pad50[0x5c - 0x50];
    Cursor_b78e0 *cursor;          // 0x5c
    void FUN_000b78e0(const char *name);
};

void Screen_b78e0::FUN_000b78e0(const char *name)
{
    if (store == 0)
        return;
    TextSelector *sel = dynamic_cast<TextSelector *>(FUN_000fc260(name));
    if (sel == 0)
        return;
    if (sel->count == 0)
        return;
    if (cursor != 0)
        cursor->FUN_001be060();
    CUnlockableBlonskyFile *file = dynamic_cast<CUnlockableBlonskyFile *>(store->FUN_00092ad0(sel->list + 0x34));
    if (file == 0)
        return;
    sel->link->next->target->f49(file->FUN_00091d20());
}
