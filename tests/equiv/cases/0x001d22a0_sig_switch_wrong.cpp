extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" void* memset(void*, int, unsigned int);
extern unsigned int DAT_004d9968;

struct Vec3 {
    float x, y, z;
};

struct LuaState;

struct ArgBuffer {
    char* cur;
    char data[0x40];
    void FUN_001d1f30(Vec3 v);
};

class Binding {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int zero, void* args, void* out);
    char pad04[0xc - 4];
    int count;
    char sig[8];
    char ret;
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
    volatile unsigned int cookie;
};

int FUN_00212fe0(LuaState* L, int idx);
Binding* FUN_00213260(LuaState* L, int idx);
int FUN_00212d70(LuaState* L);
int FUN_00212f00(LuaState* L, int idx);
float FUN_002130e0(LuaState* L, int idx);
char* FUN_00213190(LuaState* L, int idx);
int FUN_00213160(LuaState* L, int idx);
void FUN_00213340(LuaState* L, float f);
void FUN_00213320(LuaState* L);
void FUN_002133d0(LuaState* L, char* s);
void FUN_00213550(LuaState* L, void* p);
void FUN_001d0870(LuaState* L, Vec3* v);

int FUN_001d22a0(LuaState* L)
{
    Frame f;
    f.cookie = DAT_004d9968;

    if (!FUN_00212fe0(L, -10002)) {
        __security_check_cookie(f.cookie);
        return 0;
    }
    Binding* bind = FUN_00213260(L, -10002);
    int expected = bind->count;
    if (expected != FUN_00212d70(L)) {
        __security_check_cookie(f.cookie);
        return 0;
    }

    f.args.cur = f.args.data;
    memset(f.args.data, 0, sizeof(f.args.data));

    for (int i = 1; i <= bind->count; i++) {
        int type = FUN_00212f00(L, i);
        char c;
        if ((unsigned int)(i - 1) < (unsigned int)bind->count)
            c = bind->sig[i - 1];
        else
            c = 'v';

        switch (c) {
        case 'V':
            if (type != 7) {
                __security_check_cookie(f.cookie);
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
                __security_check_cookie(f.cookie);
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
            if (type != 4) {
                __security_check_cookie(f.cookie);
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
                __security_check_cookie(f.cookie);
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
                        __security_check_cookie(f.cookie);
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
            __security_check_cookie(f.cookie);
            return 0;
        }
    }

    switch (bind->ret) {
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
        __security_check_cookie(f.cookie);
        return 0;
    default:
        __security_check_cookie(f.cookie);
        return 0;
    }
    __security_check_cookie(f.cookie);
    return 1;
}
