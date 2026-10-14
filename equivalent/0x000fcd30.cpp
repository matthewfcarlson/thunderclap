// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000fcd30 @ 0x000fcd30
// CControllerAgent::CControllerAgent @ 0x000fcd30
class AgentBase {
public:
    AgentBase(int arg);
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void vfunc_9();
    char pad4[0x5c - 4];
};

extern char DAT_004e0a90;

// equiv-map: ??0AgentBase@@QAE@H@Z = 0x000fc760
class CControllerAgent : public AgentBase {
public:
    CControllerAgent(int arg);
    virtual void vfunc_9();
    int f5c;
    int f60;
    float f64;
    float f68;
    char b6c;
    char b6d;
    char pad6e[2];
    int f70;
    int f74;
    float f78;
    int f7c;
    float f80;
    int f84;
    float f88, f8c, f90, f94, f98, f9c;
    char ba0;
    char ba1;
    char pada2[0xd4 - 0xa2];
    int fd4;
};

CControllerAgent::CControllerAgent(int arg) : AgentBase(arg)
{
    f88 = -1.0f;
    f8c = -1.0f;
    f90 = -1.0f;
    f94 = -1.0f;
    f98 = -1.0f;
    f9c = -1.0f;
    char seen = DAT_004e0a90;
    b6c = 0;
    f74 = 0;
    f84 = 0;
    ba0 = 0;
    ba1 = 0;
    fd4 = 0;
    f68 = 0.2f;
    b6d = 1;
    f70 = -1;
    f78 = 0.01f;
    f7c = 1;
    f80 = 0.1f;
    f5c = 0;
    f60 = 0;
    f64 = 1.0f;
    if (seen == 0)
        DAT_004e0a90 = 1;
}
