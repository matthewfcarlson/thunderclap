// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// CNISCamera::vfunc_35 @ 0x000ac420
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

class Lens {
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
    virtual int Mode();
    char pad04[0x10 - 4];
    float fov;
};

class CGameCamera {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void SetMode(int mode);
    virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual void v34();
    virtual void vfunc_35(int a, int b, int c, int d);
};

class CNISCamera : public CGameCamera {
public:
    virtual void vfunc_35(int a, int b, int c, int d);
    char pad04[0xf1 - 4 - 0x0];
    unsigned char locked;
    char padf2[0x170 - 0xf2];
    Lens *lens;
    void FUN_000a9090(float fov);
};

void CNISCamera::vfunc_35(int a, int b, int c, int d)
{
    unsigned int cookie = DAT_004d9968;
    if (!locked && lens != 0) {
        SetMode(lens->Mode());
        FUN_000a9090(lens->fov * 57.2958f);
        CGameCamera::vfunc_35(a, b, c, d);
    }
    __security_check_cookie(cookie);
}
