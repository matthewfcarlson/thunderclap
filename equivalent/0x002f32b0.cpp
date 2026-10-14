// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002f32b0 @ 0x002f32b0
// FUN_002f32b0 @ 0x002f32b0: snaps a direction vector to the dominant axis when one component is near +-1
union FloatBits_2f32b0 {
    float f;
    unsigned int u;
};

class Axis {
public:
    char pad00[0x44];
    float x;
    float y;
    float z;
    char pad50[0x60 - 0x50];
    int dominant;
    void FUN_002f32b0();
};

void Axis::FUN_002f32b0()
{
    FloatBits_2f32b0 a;
    a.f = x;
    a.u &= 0x7fffffff;
    dominant = 0;
    if (a.f > 0.9999f) {
        dominant = 2;
        x = 1.0f;
        z = 0.0f;
        y = 0.0f;
        return;
    }
    FloatBits_2f32b0 b;
    b.f = y;
    b.u &= 0x7fffffff;
    if (b.f > 0.9999f) {
        dominant = 3;
        x = 0.0f;
        y = 1.0f;
        z = 0.0f;
        return;
    }
    FloatBits_2f32b0 c;
    c.f = z;
    c.u &= 0x7fffffff;
    if (c.f > 0.9999f) {
        dominant = 4;
        x = 0.0f;
        z = 1.0f;
        y = 0.0f;
    }
}
