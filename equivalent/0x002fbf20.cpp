// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 24/24)
// FUN_002fbf20 @ 0x002fbf20
extern "C" double fabs(double);
extern float DAT_004d2fb8;

class AxisRemap {
public:
    char pad0[0x38];
    int snapped;           // 0x38
    char pad3c[0x48 - 0x3c];
    float scale[3];        // 0x48
    float m[3][3];         // 0x54, row-major
    void FUN_002fbf20();
};

void AxisRemap::FUN_002fbf20()
{
    int pickA = 0;
    int pickB = 0;

    if (fabs(m[0][0]) > DAT_004d2fb8) {
        pickA = 1;
    } else if (fabs(m[1][0]) > DAT_004d2fb8) {
        pickB = 1;
    } else if (!(fabs(m[2][0]) > DAT_004d2fb8)) {
        return;
    }

    if (fabs(m[0][1]) > DAT_004d2fb8) {
        pickA = 2;
    } else if (fabs(m[1][1]) > DAT_004d2fb8) {
        pickB = 2;
    } else if (!(fabs(m[2][1]) > DAT_004d2fb8)) {
        return;
    }

    if (fabs(m[0][2]) > DAT_004d2fb8) {
        pickA = 3;
    } else if (fabs(m[1][2]) > DAT_004d2fb8) {
        pickB = 3;
    } else if (!(fabs(m[2][2]) > DAT_004d2fb8)) {
        return;
    }

    snapped = 1;
    if (pickA != 1) {
        float t = scale[0];
        if (pickB == 1) {
            scale[0] = scale[1];
            scale[1] = t;
            pickB = pickA;
        } else {
            scale[0] = scale[2];
            scale[2] = t;
        }
    }
    if (pickB != 2) {
        float t = scale[2];
        scale[2] = scale[1];
        scale[1] = t;
    }
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[0][0] = 1.0f;
    m[1][0] = 0.0f;
    m[1][1] = 1.0f;
    m[1][2] = 0.0f;
    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = 1.0f;
}
