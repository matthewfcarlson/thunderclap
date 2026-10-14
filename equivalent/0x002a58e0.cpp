// STATUS: equivalent (tools/equiv.py level 3: 1166 inputs, branch coverage 20/20)
// FUN_002a58e0 @ 0x002a58e0
struct Node {
    virtual void v0();
    virtual void v1();
    virtual unsigned GetId();
    virtual void v3();
    virtual void Apply(float t, float *out);
    int pad4;
    unsigned sub;
    void FUN_0028a1c0(float t, float *value);
};

struct NodeList_2a58e0 {
    char pad0[0x14];
    int count;
    Node *FUN_00288950(int index);
};

struct Source_2a58e0 {
    NodeList_2a58e0 *FUN_00288a10(int index);
};

class Target_2a58e0 {
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
    virtual float Eval();
    virtual void v11();
    virtual void v12();
    virtual float GetTime();
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
    virtual Source_2a58e0 *GetSource();
};

void FUN_002a5570(float t, Target_2a58e0 *self, int a, int b, float *params);

struct Frame_2a58e0 {
    float time;
    float timeCopy;
    float one;
    float vec[3];
    float zero;
    float half;
    float fifth;
};

void FUN_002a58e0(Target_2a58e0 *self, Target_2a58e0 *obj, int a, int b)
{
    Frame_2a58e0 f;
    f.one = 1.0f;
    f.vec[0] = 0;
    f.vec[1] = 0;
    f.vec[2] = 0;
    f.zero = 0;
    f.half = 0.5f;
    f.fifth = 0.2f;
    f.time = self->GetTime();
    f.timeCopy = f.time;

    NodeList_2a58e0 *list = self->GetSource()->FUN_00288a10(0);
    for (int i = 0; i < list->count; i++) {
        Node *n = list->FUN_00288950(i);
        unsigned id = n->GetId();
        if (id == 0x31544c46) {
            switch (n->sub) {
            case 0x53505052:
                n->FUN_0028a1c0(f.timeCopy, &f.one);
                break;
            case 0x4c414652:
                n->FUN_0028a1c0(f.timeCopy, &f.zero);
                break;
            case 0x4d415052:
                n->FUN_0028a1c0(f.timeCopy, &f.half);
                break;
            case 0x4d415552:
                n->FUN_0028a1c0(f.timeCopy, &f.fifth);
                break;
            case 0x454d4954:
                n->FUN_0028a1c0(f.timeCopy, &f.time);
                break;
            }
        } else if (id == 0x54434556) {
            if (n->sub == 0x49524f52)
                n->Apply(f.timeCopy, f.vec);
        }
    }
    FUN_002a5570(f.time / self->Eval(), obj, a, b, &f.one);
}
