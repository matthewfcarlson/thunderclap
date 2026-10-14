// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/9, incomplete)
// FEContainer::vfunc_47 @ 0x000e4330
extern "C" char *__cdecl strchr(const char *, int);

union Id64_e4330 {
    unsigned __int64 value;
    unsigned int word[2];
};

class Sub_e4330 {
public:
    unsigned int FUN_002843a0(unsigned int lo, unsigned int hi);
};

class Child_e4330 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual Sub_e4330 *Resolve();      // slot 11
};

struct Found_e4330 {
    Sub_e4330 *sub;                // 0x00
    int pad04;
    unsigned int idLo;       // 0x08
    unsigned int idHi;       // 0x0c
};

unsigned __int64 __cdecl FUN_0027b020(const char *name);
void __cdecl FUN_000f6cb0(const char *name, Found_e4330 *out);

class FEContainer {
public:
    virtual void v0();
    char pad04[0x24];
    Child_e4330 *children[8];      // 0x28
    void vfunc_47(const char *name, Found_e4330 *out);
};

void FEContainer::vfunc_47(const char *name, Found_e4330 *out) {
    if (strchr(name, '.') != 0) {
        FUN_000f6cb0(name, out);
        return;
    }
    Id64_e4330 id;
    id.value = FUN_0027b020(name);
    unsigned int index = 0;
    int i = 0;
    for (; i < 8; i++) {
        Child_e4330 *child = children[i];
        if (child == 0)
            return;
        index = child->Resolve()->FUN_002843a0(id.word[0], id.word[1]);
        if (index != 0xffff)
            break;
    }
    if (index == 0xffff)
        return;
    out->sub = children[i]->Resolve();
    out->idLo = id.word[0];
    out->idHi = id.word[1];
}
