// STATUS: equivalent (tools/equiv.py level 3: 36 inputs, branch coverage 49/50, incomplete)
// FUN_000b0a50 @ 0x000b0a50
extern "C" int strcmp(const char *, const char *);

struct Elem_b0a50 {
    char data[0x20];
};
extern Elem_b0a50 DAT_003f335c;

class Control_b0a50 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual const char *vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10(float lo, float hi);
};

class Factory_b0a50 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual Control_b0a50 *vfunc_10(Elem_b0a50 *e);
};

struct Rec_b0a50 {
    int count;
    Elem_b0a50 *items;
};

struct Row_b0a50 {
    Control_b0a50 *ctl[2][3];
    int flag[2][3];
};

void FUN_000b0a50(Factory_b0a50 *factory, int na, int nb, Rec_b0a50 *a, Rec_b0a50 *b, Rec_b0a50 *c, Control_b0a50 ***outA, Row_b0a50 *outB, Control_b0a50 **outC)
{
    int i;
    int k;
    int m;
    int e;

    for (i = 0; i < na; i++) {
        Rec_b0a50 *rec = &a[i];
        int cnt = rec->count;
        for (int j = 0; j < cnt; j++) {
            Elem_b0a50 *p;
            if (j >= 0 && j < rec->count)
                p = &rec->items[j];
            else
                p = &DAT_003f335c;
            Control_b0a50 *ctl = factory->vfunc_10(p);
            if (ctl) {
                ctl->vfunc_10(0.0f, 1.0f);
                ctl->AddRef();
                if (outA[i][j])
                    outA[i][j]->Release();
                outA[i][j] = ctl;
            }
        }
    }

    Rec_b0a50 *walk = b;
    for (k = 0; k < nb; k++) {
        for (m = 0; m < 2; m++) {
            for (e = 0; e < 3; e++) {
                Elem_b0a50 *p = (walk->count > 0) ? walk->items : &DAT_003f335c;
                Control_b0a50 *ctl = factory->vfunc_10(p);
                if (ctl) {
                    const char *name = ctl->vfunc_4();
                    if (strcmp(name, "XAxis") == 0 || strcmp(name, "YAxis") == 0 ||
                        strcmp(name, "ZAxis") == 0 || strcmp(name, "RzAxis") == 0) {
                        ctl->vfunc_10(-1.0f, 1.0f);
                        outB[k].flag[m][e] = 0;
                    } else if (strcmp(name, "Button") == 0 || strcmp(name, "AnalogButton") == 0) {
                        ctl->vfunc_10(0.0f, 1.0f);
                        outB[k].flag[m][e] = 1;
                    } else {
                        outB[k].flag[m][e] = 1;
                    }
                    ctl->AddRef();
                    if (outB[k].ctl[m][e])
                        outB[k].ctl[m][e]->Release();
                    outB[k].ctl[m][e] = ctl;
                }
                walk++;
            }
        }
    }

    Elem_b0a50 *p = (c->count > 0) ? c->items : &DAT_003f335c;
    Control_b0a50 *ctl = factory->vfunc_10(p);
    if (ctl) {
        ctl->vfunc_10(0.0f, 1.0f);
        if (outC) {
            ctl->AddRef();
            if (*outC)
                (*outC)->Release();
            *outC = ctl;
        }
    }
}
