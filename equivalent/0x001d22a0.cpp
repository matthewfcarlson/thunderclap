// STATUS: equivalent (tools/equiv.py level 3: 3202 inputs, branch coverage 48/51, incomplete)
// FUN_001d22a0 @ 0x001d22a0
// cl-flags: /GS
#include "decls/data/script.h"
extern "C" void* memset(void*, int, unsigned int);

struct Vec3 {
    float x, y, z;
};


struct ArgBuffer {
    char* cur;
    char data[0x40];
    void FUN_001d1f30(Vec3 v);
};

// Function (include/decls/data/script.h): argc, the argument type codes and the return type code.
class Binding : public ScriptFunctionFields {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int zero, void* args, void* out);
};

struct Frame {
    char pad10[3];
    char flag;
    char* str;
    void* userdata;
    int pad1c;
    int pad20;
    union {
        Vec3 tmp;
        struct {
            int pad24;
            int num;
            float fnum;
        } n;
    };
    Vec3 vec;
    ArgBuffer args;
};

extern "C" int FUN_00212fe0(LuaVMState* L, int idx);
extern "C" Binding* FUN_00213260(LuaVMState* L, int idx);
int FUN_00212d70(LuaVMState* L);
extern "C" int FUN_00212f00(LuaVMState* L, int idx);
extern "C" float FUN_002130e0(LuaVMState* L, int idx);
char* FUN_00213190(LuaVMState* L, int idx);
extern "C" int FUN_00213160(LuaVMState* L, int idx);
extern "C" void FUN_00213340(LuaVMState* L, float f);
extern "C" void FUN_00213320(LuaVMState* L);
void FUN_002133d0(LuaVMState* L, char* s);
extern "C" void FUN_00213550(LuaVMState* L, void* p);
extern "C" void FUN_001d0870(LuaVMState* L, Vec3* v);

extern "C" int FUN_001d22a0(LuaVMState* L)
{
    Frame f;

    if (!FUN_00212fe0(L, -10002)) {
        return 0;
    }
    Binding* bind = FUN_00213260(L, -10002);
    int expected = bind->argc;
    if (expected != FUN_00212d70(L)) {
        return 0;
    }

    f.args.cur = f.args.data;
    memset(f.args.data, 0, sizeof(f.args.data));

    for (int i = 1; i <= bind->argc; i++) {
        int type = FUN_00212f00(L, i);
        char c;
        if ((unsigned int)(i - 1) < (unsigned int)bind->argc)
            c = bind->argTypes[i - 1];
        else
            c = 'v';

        switch (c) {
        case 'V':
            if (type != 7) {
                return 0;
            }
            {
                Vec3* v = (Vec3*)FUN_00213260(L, i);
                f.tmp = *v;
                f.args.FUN_001d1f30(f.tmp);
            }
            break;
        case 'b':
            {
                int r = FUN_00213160(L, i);
                char* cur = f.args.cur;
                if ((unsigned int)(cur - f.args.data + 1) < 0x40) {
                    *cur = (r != 0);
                    f.args.cur += 4;
                }
            }
            break;
        case 'c':
        case 'v':
            if (type != 2) {
                return 0;
            }
            {
                void* p = FUN_00213260(L, i);
                char* cur = f.args.cur;
                if ((unsigned int)(cur - f.args.data + 4) < 0x40) {
                    *(void**)cur = p;
                    f.args.cur += 4;
                }
            }
            break;
        case 'f':
            if (type != 3) {
                return 0;
            }
            {
                float v = FUN_002130e0(L, i);
                char* cur = f.args.cur;
                if ((unsigned int)(cur - f.args.data + 4) < 0x40) {
                    *(float*)cur = v;
                    f.args.cur += 4;
                }
            }
            break;
        case 'i':
            if (type != 3) {
                return 0;
            }
            {
                int v = (int)FUN_002130e0(L, i);
                char* cur = f.args.cur;
                if ((unsigned int)(cur - f.args.data + 4) < 0x40) {
                    *(int*)cur = v;
                    f.args.cur += 4;
                }
            }
            break;
        case 's':
            {
                char* s = 0;
                if (FUN_00212f00(L, i) != 0) {
                    if (type != 4) {
                        return 0;
                    }
                    s = FUN_00213190(L, i);
                }
                char* cur = f.args.cur;
                if ((unsigned int)(cur - f.args.data + 4) < 0x40) {
                    *(char**)cur = s;
                    f.args.cur += 4;
                }
            }
            break;
        default:
            return 0;
        }
    }

    switch (bind->retType) {
    case 'V':
        bind->vfunc_2(0, f.args.data, &f.vec);
        FUN_001d0870(L, &f.vec);
        break;
    case 'b':
        bind->vfunc_2(0, f.args.data, &f.flag);
        if (!f.flag)
            FUN_00213320(L);
        else
            FUN_00213340(L, 1.0f);
        break;
    case 'c':
        bind->vfunc_2(0, f.args.data, &f.userdata);
        FUN_00213550(L, f.userdata);
        break;
    case 'f':
        bind->vfunc_2(0, f.args.data, &f.n.fnum);
        FUN_00213340(L, f.n.fnum);
        break;
    case 'i':
        bind->vfunc_2(0, f.args.data, &f.n.num);
        FUN_00213340(L, (float)f.n.num);
        break;
    case 's':
        bind->vfunc_2(0, f.args.data, &f.str);
        FUN_002133d0(L, f.str);
        break;
    case 'v':
        bind->vfunc_2(0, f.args.data, 0);
        return 0;
    default:
        return 0;
    }
    return 1;
}
