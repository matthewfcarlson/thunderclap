// STATUS: equivalent (tools/equiv.py level 3: 36 inputs, branch coverage 49/50, incomplete)
// FUN_000b0a50 @ 0x000b0a50
extern "C" int strcmp(const char *, const char *);

struct Elem {
    char data[0x20];
};
extern Elem DAT_003f335c;

class Control {
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

class Factory {
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
    virtual Control *vfunc_10(Elem *e);
};

struct Rec {
    int count;
    Elem *items;
};

struct Row {
    Control *ctl[2][3];
    int flag[2][3];
};

void FUN_000b0a50(Factory *factory, int na, int nb, Rec *a, Rec *b, Rec *c, Control ***outA, Row *outB, Control **outC)
{
    int i;
    int k;
    int m;
    int e;

    for (i = 0; i < na; i++) {
        Rec *rec = &a[i];
        int cnt = rec->count;
        for (int j = 0; j < cnt; j++) {
            Elem *p;
            if (j >= 0 && j < rec->count)
                p = &rec->items[j];
            else
                p = &DAT_003f335c;
            Control *ctl = factory->vfunc_10(p);
            if (ctl) {
                ctl->vfunc_10(0.0f, 1.0f);
                ctl->AddRef();
                if (outA[i][j])
                    outA[i][j]->Release();
                outA[i][j] = ctl;
            }
        }
    }

    Rec *walk = b;
    for (k = 0; k < nb; k++) {
        for (m = 0; m < 2; m++) {
            for (e = 0; e < 3; e++) {
                Elem *p = (walk->count > 0) ? walk->items : &DAT_003f335c;
                Control *ctl = factory->vfunc_10(p);
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

    Elem *p = (c->count > 0) ? c->items : &DAT_003f335c;
    Control *ctl = factory->vfunc_10(p);
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
