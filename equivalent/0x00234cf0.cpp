// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 18/24, incomplete)
// fight::ParamValueEnum::vfunc_5 @ 0x00234cf0
extern "C" int strcmp(const char *a, const char *b);
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" unsigned int DAT_004d9968;

class Context {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual char vf6(int a, int b, int *index, char *name, int size);
};

void FUN_00232cc0(Context *ctx, const char *fmt, ...);

namespace fight {
class ParamValueEnum {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual char vfunc_5(void *a1, int a2, Context *ctx);
    virtual const char *vfunc_6(void *a1, int i);
    virtual int vfunc_7(void *a1);
    virtual char vfunc_8(void *a1, int i);

    char pad04[4];
    int key0;
    int key1;
};
}

char fight::ParamValueEnum::vfunc_5(void *a1, int a2, Context *ctx)
{
    unsigned int cookie = DAT_004d9968;
    char name[1024];
    for (int k = 0; k < 1024; k++)
        name[k] = 0;
    int index = -1;
    char ok = ctx->vf6(key0, key1, &index, name, 1024);
    if (!ok) {
        __security_check_cookie(cookie);
        return ok;
    }
    if (index >= 0) {
        if (index < vfunc_7(a1)) {
            vfunc_8(a1, index);
            __security_check_cookie(cookie);
            return ok;
        }
        FUN_00232cc0(ctx, "%d is not a valid enumerated value.", index);
        __security_check_cookie(cookie);
        return 0;
    }
    if (name[0] == 0) {
        __security_check_cookie(cookie);
        return ok;
    }
    char result = ok;
    int n = vfunc_7(a1);
    int i;
    for (i = 0; i < n; i++) {
        const char *s = vfunc_6(a1, i);
        if (strcmp(name, s) == 0) {
            result = vfunc_8(a1, i);
            break;
        }
    }
    if (i >= n) {
        FUN_00232cc0(ctx, "\"%s\" is not a valid enumerated value.", name);
        result = 0;
    }
    __security_check_cookie(cookie);
    return result;
}
