// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000cb750 @ 0x000cb750
class Curve {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    virtual void v8();
    virtual void v9();
    virtual float v10(int value);
};

struct Bank {
    char pad00[0x24];
    Curve* curves[1];         // 0x24
    int FUN_000f7220(int a);
};

struct Slot { float value; float pad[3]; };

struct Sampler {
    Bank* bank;               // 0x00
    char pad04[4];
    Slot slots[1];            // 0x08 (16 bytes each)
    char pad18[0x88 - 0x18];
    int current;              // 0x88
    float Sample(int a, int b);
};

float Sampler::Sample(int a, int b)
{
    if (a < 0)
        return 0.0f;
    Curve* curve = bank->curves[b];
    Curve* first = bank->curves[0];
    Slot* slot = &slots[current];
    float inv = 14.0f / first->v7();
    return curve->v10(bank->FUN_000f7220(a)) * slot->value * inv;
}
