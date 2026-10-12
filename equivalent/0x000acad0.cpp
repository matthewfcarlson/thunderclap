// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// CScriptCamera::vfunc_35 @ 0x000acad0
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

struct Vec3 {
    float x, y, z;
};

struct Mat {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bc20(float x, float y, float z);
    void FUN_0022be40(Vec3* pos);
};

struct Curve {
    char data[0x38];
    float FUN_000ac6f0(float time, float duration);
};

struct CameraArgs;

struct Receiver {
    void FUN_00099470(CameraArgs* args);
};

struct CameraArgs {
    int f0;
    int f4;
    Receiver* f8;
};

class CGameCamera {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void vfunc_21(Mat* m);
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void vfunc_35(CameraArgs* args, float dt, int flag, int extra);
    virtual void v36();
    virtual void vfunc_37(int mode, float x, float y, float z);
};

class CScriptCamera : public CGameCamera {
public:
    char pad04[0xf1 - 4];
    char frozen;
    char padf2[0x170 - 0xf2];
    Curve c170;
    Curve c1a8;
    Curve c1e0;
    Curve c218;
    Curve c250;
    Vec3 v288;
    Vec3 v294;
    Vec3 v2a0;
    char pending;
    char pad2ad[3];
    float f2b0;
    float f2b4;
    float f2b8;
    float f2bc;
    float time;
    int pad2c4;
    float duration;
    char flagA;
    char flagB;
    char pad2ce[2];
    void FUN_000a9090(float v);
    bool FUN_000aca40(int v);
    virtual void vfunc_35(CameraArgs* args, float dt, int flag, int extra);
};

void CScriptCamera::vfunc_35(CameraArgs* args, float dt, int flag, int extra)
{
    unsigned int cookie = DAT_004d9968;
    if (!frozen) {
        float dur0 = duration;
        float sum = dt + time;
        time = sum;
        float a0 = c170.FUN_000ac6f0(sum, dur0);
        float a1 = c1a8.FUN_000ac6f0(time, duration);
        float a2 = c1e0.FUN_000ac6f0(time, duration);

        if (pending && f2b0 <= time) {
            vfunc_37(1, f2b4, f2b8, f2bc);
            pending = 0;
        }

        Mat m;
        m.FUN_0022b980();
        m.FUN_0022bc20(a2 * 0.017453292f, a1 * 0.017453292f, 0.0f);

        float t = c218.FUN_000ac6f0(time, duration);
        v2a0.x = (v294.x - v288.x) * t + v288.x;
        v2a0.y = (v294.y - v288.y) * t + v288.y;
        v2a0.z = (v294.z - v288.z) * t + v288.z;

        Vec3 fwd;
        fwd.x = m.m[8] * a0;
        fwd.y = m.m[9] * a0;
        fwd.z = m.m[10] * a0;
        Vec3 d;
        d.x = v2a0.x - fwd.x;
        d.y = v2a0.y - fwd.y;
        d.z = v2a0.z - fwd.z;
        m.FUN_0022be40(&d);
        vfunc_21(&m);

        FUN_000a9090(c250.FUN_000ac6f0(time, duration));
        CGameCamera::vfunc_35(args, dt, (unsigned char)flagA, extra);
        if (FUN_000aca40(args->f4)) {
            if (!flagB)
                args->f8->FUN_00099470(args);
        }
    }
    __security_check_cookie(cookie);
}
