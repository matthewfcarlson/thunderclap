// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 18/18)
// hulkfight::scenario::LuaCondition::vfunc_6 @ 0x001a14f0
namespace fight {
class Params {
public:
    virtual void v0();
};
}

class CFightParams : public fight::Params {
public:
    virtual void v1();
};

struct Blob {
    char data[0xe0];
    void FUN_001cb170();
};

class CScenarioParams : public fight::Params {
public:
    virtual void v1();
    char pad[4];
    int f8;
    Blob *FUN_001d03c0();
};


struct LuaMgr {
    char pad0[8];
    void *L;
    bool FUN_001d1cb0();
    void FUN_001d1d50(const char *name, char *buf);
    bool FUN_001d1d30();
    void FUN_001d2ee0(CFightParams *p);
    int FUN_001d35a0(const char *chunk, char *name, int len);
};

LuaMgr *FUN_001d4c90();
int FUN_00267760(char *buf, int n, const char *fmt, ...);
void *FUN_0008d6d0(unsigned int n);
void FUN_0008d340(void *p);
int FUN_00213160(void *L, int idx);
void FUN_00212d80(void *L, int idx);
unsigned int FUN_001d0440();
void FUN_001d0430(unsigned int v);

extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

class LuaCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, fight::Params *params, int c);
    char pad[0xc - 4];
    const char *script;
    int scriptLen;
};

bool LuaCondition::vfunc_6(int a, fight::Params *params, int c)
{
    struct Frame {
        char pad[0x18];
        char buf[0x100];
        Blob copy;
        int pad1f8;
        unsigned int cookie;
    } fr;
    fr.cookie = DAT_004d9968;
    LuaMgr *mgr = FUN_001d4c90();
    if (mgr == 0) {
        __security_check_cookie(fr.cookie);
        return false;
    }
    fr.buf[0] = 0;
    FUN_00267760(fr.buf, 0x100, "DO NOT USE THIS IN RELEASE MODE!  Talk to Kevin...");
    mgr->FUN_001d1cb0();
    mgr->FUN_001d1d50("node", fr.buf);
    mgr->FUN_001d1d30();
    CScenarioParams *sp = dynamic_cast<CScenarioParams *>(params);
    if (sp != 0) {
        unsigned int v = sp->f8;
        if (FUN_001d0440() != v) {
            FUN_001d0430(sp->f8);
            fr.copy = *sp->FUN_001d03c0();
            fr.copy.FUN_001cb170();
        }
    } else {
        CFightParams *fp = dynamic_cast<CFightParams *>(params);
        if (fp != 0)
            mgr->FUN_001d2ee0(fp);
    }
    const char *chunk = script;
    if (chunk == 0) {
        __security_check_cookie(fr.cookie);
        return false;
    }
    int len = scriptLen;
    bool allocated = false;
    if (*chunk != 0x1b) {
        char *tmp = (char *)FUN_0008d6d0(len + 0x10);
        FUN_00267760(tmp, scriptLen + 0x10, "return (%s)", script);
        allocated = true;
        chunk = tmp;
        const char *e = tmp;
        while (*e != 0)
            e++;
        len = e - tmp;
    }
    int rc = mgr->FUN_001d35a0(chunk, fr.buf, len);
    if (allocated)
        FUN_0008d340((void *)chunk);
    if (rc != 3) {
        __security_check_cookie(fr.cookie);
        return false;
    }
    void *L = mgr->L;
    bool ok = FUN_00213160(L, -1) == 1;
    FUN_00212d80(L, -2);
    __security_check_cookie(fr.cookie);
    return ok;
}
