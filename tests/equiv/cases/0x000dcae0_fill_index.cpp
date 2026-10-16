extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int __cdecl sprintf(char *, const char *, ...);

class FETextInput;
struct Cell {
    float v;
    int f4;
    int f8;
    int f0c;
    int f10;
    int f14;
};

struct Lay {
    void *p;
    int f04;
    __declspec(align(8)) char data[0x80];
    int idx;
    int pad8c;
    void FUN_000f7fe0(void *r) throw();
    void FUN_000f78e0() throw();
    void FUN_000f80e0(const char *buf, int z, const void *style) throw();
};

class Y {
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
    virtual void v21();
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
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void *v44();
};

class X {
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
    virtual void v21();
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
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48(int a, void *b);
    Y *f04;
    char pad08[0x958 - 8];
    char s958[0x14];
    float f96c;
    char pad970[8];
    char s978[0x10];
    unsigned int f988;
};

class Owner {
public:
    int pad04;
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
    virtual char v13(FETextInput *t);
    X *f08;
};

class Obj {
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
    virtual void v15(int z);
    virtual void v16(int z);
};

struct P2 {
    Obj *obj;
    void FUN_00293d00(void *arg) throw();
};

struct Widget {
    void FUN_000e9100(void *a) throw();
    void FUN_000e9130(void *a) throw();
};

extern unsigned int DAT_004d9968;
extern P2 *DAT_0052c2ac;
extern signed char DAT_004a0d38[];
Widget *__cdecl FUN_000fc260(const char *name) throw();

class FETextInput {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vfunc_5();
    char pad04[0x10];
    Owner *f14;
    char pad18[0x3c - 0x18];
    union {
        int f3c;
        struct {
            char b3c, b3d, b3e, b3f;
        };
    };
    char pad40[0x60 - 0x40];
    void *f60;
    void *f64;
    char b68;
    char pad69[0x74 - 0x69];
    char b74;
    char pad75[0x150 - 0x75];
    int f150;
    int f154;
    char pad158[4];
    char *f15c;
    char *f160;
    int *f164;
    int *f168;
    int *f16c;
    char pad170[4];
    union {
        unsigned int f174;
        struct {
            unsigned char b174, b175, b176, b177;
        };
    };
    int f178;
    float FUN_000e2840() throw();
    float FUN_000e2850() throw();
};

void FETextInput::vfunc_5()
{
    struct Frame {
        Lay L1;
        Lay L2;
        char buf2[8];
        char buf1[0x44];
        unsigned int cookie;
    } f;
    int tmp;
    int off;
    int i;

    f.cookie = DAT_004d9968;
    if (b74 != 0) {
        f.L1.FUN_000f7fe0(f14->f08->f04->v44());
        f.L2.FUN_000f7fe0(f14->f08->f04->v44());
        float s = FUN_000e2850();
        ((Cell *)((char *)&f.L1 + 8 + f.L1.idx * 16))->v = FUN_000e2840() * s;
        ((Cell *)((char *)&f.L1 + 8 + f.L1.idx * 16))->f8 = 2;
        float s2 = FUN_000e2850();
        ((Cell *)((char *)&f.L2 + 8 + f.L2.idx * 16))->v = FUN_000e2840() * s2;
        ((Cell *)((char *)&f.L2 + 8 + f.L2.idx * 16))->f8 = 2;
        sprintf(f.buf1, "___");
        Widget *w = FUN_000fc260("enter_code_text");
        if (f178 == 1) {
            if (w != 0) {
                if (f14->v13(this)) {
                    if (f60 != 0 && b68 == 0)
                        w->FUN_000e9100(f60);
                }
                if (!f14->v13(this)) {
                    if (f64 != 0)
                        w->FUN_000e9130(f64);
                }
            }
        } else if (w != 0) {
            w->FUN_000e9100(0);
            w->FUN_000e9130(0);
        }
        i = 0;
        if (f150 > 0) {
            off = 0;
            do {
                if (f168[i] != 0) {
                    DAT_0052c2ac->obj->v15(0);
                    f14->f08->v48(f168[i], f160 + off);
                    DAT_0052c2ac->FUN_00293d00(f160 + off);
                    Cell *c = (Cell *)((char *)&f.L1 + 8 + f.L1.idx * 16);
                    c->f4 = 1;
                    ((Cell *)((char *)&f.L1 + 8 + f.L1.idx * 16))->f0c = f3c;
                    f.L1.f04 = f3c;
                    if ((f178 == 2 && f154 == i) || f178 == 1) {
                        X *x = f14->f08;
                        float fa = x->f96c * 255.0f;
                        ((Cell *)((char *)&f.L1 + 8 + f.L1.idx * 16))->f0c = 0;
                        X *x2 = f14->f08;
                        tmp = x2->f988;
                        x2->f988 = (255 - (int)fa) << 24;
                        f.L1.FUN_000f80e0(f.buf1, 0, f14->f08->s978);
                        x2->f988 = tmp;
                        tmp = b177 * (unsigned char)b3f;
                        int a = (int)((float)tmp * 0.003921569f);
                        unsigned int col = (((((a << 8) | b176) << 8) | b175) << 8) | (f174 & 0xff);
                        ((Cell *)((char *)&f.L1 + 8 + f.L1.idx * 16))->f0c = col;
                        f.L1.FUN_000f80e0(f.buf1, 0, x->s958);
                    } else {
                        f.L1.FUN_000f80e0(f.buf1, 0, f14->f08->s978);
                    }
                    DAT_0052c2ac->obj->v16(0);
                }
                if (f16c[i] >= 0 && f164[i] != 0) {
                    sprintf(f.buf2, "%c", (int)DAT_004a0d38[f16c[i]]);
                    DAT_0052c2ac->obj->v15(0);
                    f14->f08->v48(f164[i], f15c + off);
                    DAT_0052c2ac->FUN_00293d00(f15c + off);
                    Cell *c = (Cell *)((char *)&f.L2 + 8 + f.L2.idx * 16);
                    c->f4 = 1;
                    ((Cell *)((char *)&f.L2 + 8 + f.L2.idx * 16))->f0c = f3c;
                    f.L2.f04 = f3c;
                    if (f178 == 2 && f154 == i) {
                        X *x = f14->f08;
                        float fa = x->f96c * 255.0f;
                        ((Cell *)((char *)&f.L2 + 8 + f.L2.idx * 16))->f0c = 0;
                        X *x2 = f14->f08;
                        tmp = x2->f988;
                        x2->f988 = (255 - (int)fa) << 24;
                        f.L2.FUN_000f80e0(f.buf2, 0, f14->f08->s978);
                        x2->f988 = tmp;
                        tmp = b177 * (unsigned char)b3f;
                        int a = (int)((float)tmp * 0.003921569f);
                        unsigned int col = (((((a << 8) | b176) << 8) | b175) << 8) | (f174 & 0xff);
                        ((Cell *)((char *)&f.L2 + 8 + f.L2.idx * 16))->f0c = col;
                        f.L2.FUN_000f80e0(f.buf2, 0, x->s958);
                    } else {
                        f.L2.FUN_000f80e0(f.buf2, 0, f14->f08->s978);
                    }
                    DAT_0052c2ac->obj->v16(0);
                }
                i = i + 1;
                off = off + 0xc;
            } while (i < f150);
        }
        f.L2.FUN_000f78e0();
        f.L1.FUN_000f78e0();
    }
    __security_check_cookie(f.cookie);
}
