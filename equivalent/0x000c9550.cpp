// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 14/14)
// FUN_000c9550 @ 0x000c9550
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" char* strncpy(char* dst, const char* src, unsigned int n);

class Handle_c9550 {
public:
    virtual void v0();
    virtual void Release();
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void v22();
    virtual bool v23();
    bool FUN_00266750();
    int FUN_00266700();
};

struct Request {
    char name[0x100];
    int f100;
    int f104;
    int f108;
    char f10c;
    char pad10d[3];
};

struct Mgr_c9550 {
    char pad00[4];
    int limit;
    void FUN_00265810(Request* r, Handle_c9550** out);
    int FUN_00264870();
    void FUN_00264860(int v);
};

struct Item_c9550 {
    void FUN_001eb2a0(int a, int b);
};

struct Scene_c9550 {
    Item_c9550* FUN_000862e0();
};

struct Sys_c9550 {
    char pad00[0x54];
    Scene_c9550* scene;
};

struct Target_c9550 {
    void FUN_00266220(int v);
};

void thunk_FUN_00271230(Handle_c9550** out, const char* name, int a, int b, int c, int d, int e, int f);
void FUN_002656a0();
extern unsigned int DAT_004d9968;
extern Mgr_c9550* DAT_00527c58;
extern Sys_c9550* DAT_004dd700;

void __stdcall FUN_000c9550(const char* name, Target_c9550* target, int arg)
{
    unsigned int cookie = DAT_004d9968;
    struct Frame {
        Handle_c9550* l2;
        Handle_c9550* l1;
        Request req;
    } f;
    thunk_FUN_00271230(&f.l1, name, 0, 0, 1, 0, 1, 1);
    if (!f.l1->v23()) {
        if (f.l1)
            f.l1->Release();
        __security_check_cookie(cookie);
        return;
    }
    if (f.l1) {
        f.l1->Release();
        f.l1 = 0;
    }
    f.l2 = 0;
    f.req.name[0] = 0;
    f.req.f100 = 0;
    f.req.f104 = 0;
    f.req.f108 = 0;
    f.req.f10c = 0;
    if (name)
        strncpy(f.req.name, name, 0xff);
    f.req.f108 = arg;
    f.req.f10c = 0;
    DAT_00527c58->FUN_00265810(&f.req, &f.l2);
    int saved = DAT_00527c58->FUN_00264870();
    DAT_00527c58->FUN_00264860(250000);
    Scene_c9550* scene = DAT_004dd700->scene;
    while (!f.l2->FUN_00266750()) {
        FUN_002656a0();
        scene->FUN_000862e0()->FUN_001eb2a0(0, 0);
    }
    DAT_00527c58->FUN_00264860(saved);
    target->FUN_00266220(f.l2->FUN_00266700());
    if (f.l2)
        f.l2->Release();
    __security_check_cookie(cookie);
}
