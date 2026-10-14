// STATUS: equivalent (tools/equiv.py level 3: 3030 inputs, branch coverage 14/16, incomplete)
// FUN_000f1650 @ 0x000f1650
class Curve_f1650 {
public:
    virtual void v0();
    virtual float v1(int a, int b);
};

class Sink_f1650 { public: void FUN_000f8b00(float v); };

class Mode_f1650 {
public:
    virtual void v0();
};

class C_f1650 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(int mode);
    char pad[0x182c - 4];
    Curve_f1650 *curve;
};


class B_f1650 { public: char pad[4]; C_f1650 *c; };
class A_f1650 { public: char pad[8]; B_f1650 *b; };

class Slider_f1650 {
public:
    char pad0[0x14];
    A_f1650 *a;
    char pad18[0x150 - 0x18];
    float value;
    int state;
    char pad158[4];
    float lo;
    float hi;
    char pad164[0x170 - 0x164];
    int curveArg0;
    int curveArg1;
    float rate;
    char pad17c[4];
    Sink_f1650 *sink;
    void FUN_000e9e60();
    void FUN_000f1650(float dt);
};

void Slider_f1650::FUN_000f1650(float dt)
{
    state = 1;
    double x = a->b->c->curve->v1(curveArg0, curveArg1);
    double curve = x * x * x * x * x * x * x;
    double k = rate * 0.5f + 0.01f;
    if (k >= 0.0) {
        if (k > 1.0)
            k = 1.0;
    } else {
        k = 0.0;
    }
    double v = value + (hi - lo) * (k * curve) * dt * 0.5f;
    if (v > hi)
        v = hi;
    value = v;
    float w;
    float cur = *(volatile float *)&value;
    if (cur >= lo && cur <= hi)
        w = cur;
    else if (cur > hi)
        w = hi;
    else
        w = lo;
    value = w;
    if (sink)
        sink->FUN_000f8b00(w);
    a->b->c->v48(3);
    FUN_000e9e60();
}
