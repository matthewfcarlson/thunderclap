// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000ac7d0 @ 0x000ac7d0
struct ResourceName {
    int word;
    void FUN_0027b040(const char *name);
};

class CScriptCamera;

class __declspec(novtable) CCameraBase {
public:
    virtual void v0();
    char pad04[4];
    ResourceName name;      // 0x08
    char pad0c[0xd0 - 0xc];
    int mode;               // 0xd0
    char padd4[0x170 - 0xd4];
    CCameraBase *FUN_000a9400();
    CCameraBase() { FUN_000a9400(); }
};

extern const char *DAT_0049ee00;

class CScriptCamera : public CCameraBase {
public:
    virtual void v0();
    unsigned char f170;
    char pad171[0x3];
    int f174;
    int f178;
    float f17c;
    int f180;
    int f184;
    int f188;
    unsigned char f18c;
    char pad18d[0x3];
    int f190;
    int f194;
    char pad198[0x10];
    unsigned char f1a8;
    char pad1a9[0x3];
    int f1ac;
    int f1b0;
    float f1b4;
    int f1b8;
    int f1bc;
    int f1c0;
    unsigned char f1c4;
    char pad1c5[0x3];
    int f1c8;
    int f1cc;
    char pad1d0[0x10];
    unsigned char f1e0;
    char pad1e1[0x3];
    int f1e4;
    int f1e8;
    float f1ec;
    int f1f0;
    int f1f4;
    int f1f8;
    unsigned char f1fc;
    char pad1fd[0x3];
    int f200;
    int f204;
    char pad208[0x10];
    unsigned char f218;
    char pad219[0x3];
    int f21c;
    int f220;
    float f224;
    int f228;
    int f22c;
    int f230;
    unsigned char f234;
    char pad235[0x3];
    int f238;
    int f23c;
    char pad240[0x10];
    unsigned char f250;
    char pad251[0x3];
    int f254;
    int f258;
    float f25c;
    int f260;
    int f264;
    int f268;
    unsigned char f26c;
    char pad26d[0x3];
    int f270;
    int f274;
    char pad278[0x10];
    int f288;
    int f28c;
    int f290;
    int f294;
    int f298;
    int f29c;
    char pad2a0[0xc];
    unsigned char f2ac;
    char pad2ad[0x3];
    int f2b0;
    float f2b4;
    float f2b8;
    float f2bc;
    int f2c0;
    float f2c4;
    float f2c8;
    unsigned char f2cc;
    unsigned char f2cd;
    CScriptCamera();
};

CScriptCamera::CScriptCamera()
{
    f170 = 0;
    f174 = 0;
    f178 = 0;
    f17c = -1.0f;
    f180 = 0;
    f184 = 0;
    f188 = 0;
    f18c = 0;
    f190 = 0;
    f194 = 0;
    f1a8 = 0;
    f1ac = 0;
    f1b0 = 0;
    f1b4 = -1.0f;
    f1b8 = 0;
    f1bc = 0;
    f1c0 = 0;
    f1c4 = 0;
    f1c8 = 0;
    f1cc = 0;
    f1e0 = 0;
    f1e4 = 0;
    f1e8 = 0;
    f1ec = -1.0f;
    f1f0 = 0;
    f1f4 = 0;
    f1f8 = 0;
    f1fc = 0;
    f200 = 0;
    f204 = 0;
    f218 = 0;
    f21c = 0;
    f220 = 0;
    f224 = -1.0f;
    f228 = 0;
    f22c = 0;
    f230 = 0;
    f234 = 0;
    f238 = 0;
    f23c = 0;
    f250 = 0;
    f254 = 0;
    f258 = 0;
    f25c = -1.0f;
    f260 = 0;
    f264 = 0;
    f268 = 0;
    f26c = 0;
    f270 = 0;
    f274 = 0;
    f288 = 0;
    f28c = 0;
    f290 = 0;
    f294 = 0;
    f298 = 0;
    f29c = 0;
    f2ac = 0;
    f2b0 = 0;
    f2b4 = 3.0f;
    f2b8 = 0.25f;
    f2bc = 20.0f;
    f2c0 = 0;
    f2c4 = 1.5f;
    f2c8 = 3.0f;
    f2cc = 0;
    f2cd = 0;
    mode = 4;
    name.FUN_0027b040(DAT_0049ee00);
}