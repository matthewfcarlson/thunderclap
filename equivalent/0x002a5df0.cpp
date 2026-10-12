// STATUS: equivalent (tools/equiv.py level 3: 1176 inputs, branch coverage 30/30)
// FUN_002a5df0 @ 0x002a5df0
struct Item {
    virtual void v0();
    virtual void v1();
    virtual int GetType();
    virtual void v3();
    virtual void v4(float time, float *out);
    int pad4;
    int subType;
    void FUN_0028a1c0(float time, float *out);
};


struct V3 {
    float x, y, z;
    float FUN_0022d110();
};


struct List {
    char pad0[0x14];
    int count;
    Item *FUN_00288950(int index);
};

struct Clips {
    List *FUN_00288a10(int flags);
};

struct Anim {
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
    virtual float v10();
    virtual void v11();
    virtual void v12();
    virtual float v13();
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
    virtual Clips *v25();
};

void __cdecl FUN_002a5a20(float v, int a2, int a3, int a4, float *params);

struct Frame {
    float t;        // time; a TIME item overrides it; divides the result
    float t0;       // time as read at the start: passed to every item
    float f[14];
};

void FUN_002a5df0(Anim *obj, int a2, int a3, int a4)
{
    Frame fr;
    fr.f[0] = 1.0f;
    fr.f[1] = 0.0f;
    fr.f[2] = 0.0f;
    fr.f[3] = 0.0f;
    fr.f[4] = 1.0f;
    fr.f[5] = 0.0f;
    fr.f[6] = 0.0f;
    fr.f[7] = 10.0f;
    fr.f[8] = 0.0f;
    fr.f[9] = 1.0f;
    fr.f[10] = 0.5f;
    fr.f[11] = 0.0f;
    fr.f[12] = 0.0f;
    fr.f[13] = 0.2f;
    fr.t0 = fr.t = obj->v13();
    List *list = obj->v25()->FUN_00288a10(0);
    for (int i = 0; i < list->count; i++) {
        Item *item = list->FUN_00288950(i);
        int type = item->GetType();
        if (type == 0x31544c46) {
            float *dst;
            switch (item->subType) {
            case 0x53505657: dst = &fr.f[0]; break;
            case 0x4e454c57: dst = &fr.f[7]; break;
            case 0x4c414657: dst = &fr.f[8]; break;
            case 0x4d415057: dst = &fr.f[9]; break;
            case 0x4d414357: dst = &fr.f[10]; break;
            case 0x4d414157: dst = &fr.f[11]; break;
            case 0x464f4357: dst = &fr.f[12]; break;
            case 0x4d415557: dst = &fr.f[13]; break;
            case 0x454d4954: dst = &fr.t; break;
            default: continue;
            }
            item->FUN_0028a1c0(fr.t0, dst);
        } else if (type == 0x54434556) {
            if (item->subType == 0x49524f57) {
                item->v4(fr.t0, &fr.f[1]);
            } else if (item->subType == 0x52494457) {
                item->v4(fr.t0, &fr.f[4]);
                ((V3 *)&fr.f[4])->FUN_0022d110();
            }
        }
    }
    FUN_002a5a20(fr.t / obj->v10(), a2, a3, a4, fr.f);
}
