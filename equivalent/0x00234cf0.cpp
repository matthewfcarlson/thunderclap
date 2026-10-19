// STATUS: equivalent (tools/equiv.py level 3: 5195 inputs, branch coverage 23/24, incomplete)
// fight::ParamValueEnum::vfunc_5 @ 0x00234cf0
// cl-flags: /GS
extern "C" void *__cdecl memset(void *, int, unsigned int);
extern "C" int strcmp(const char *a, const char *b);

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
    struct Frame {
        char pad[3];
        char ok;
        int index;
        int n;
        char name[1024];
        int pad2;               // (a dead word between the buffer and the cookie)
    } f;
    f.name[0] = 0;
    memset(f.name + 1, 0, 1023);
    f.index = -1;
    f.ok = ctx->vf6(key0, key1, &f.index, f.name, 1024);
    if (!f.ok) {
        return f.ok;
    }
    if (f.index >= 0) {
        if (f.index < vfunc_7(a1)) {
            vfunc_8(a1, f.index);
            return f.ok;
        }
        FUN_00232cc0(ctx, "%d is not a valid enumerated value.", f.index);
        return 0;
    }
    if (f.name[0] == 0) {
        return f.ok;
    }
    f.n = vfunc_7(a1);
    int i;
    char result;
    for (i = 0; i < f.n; i++) {
        if (strcmp(f.name, vfunc_6(a1, i)) == 0) {
            result = vfunc_8(a1, i);
            if (i < f.n) {
                return result;
            }
            break;
        }
    }
    FUN_00232cc0(ctx, "\"%s\" is not a valid enumerated value.", f.name);
    return 0;
}
