// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 8/8)
// FUN_00309410 @ 0x00309410
struct Controller {
    void FUN_002ef8b0(int mode);
};

struct Part {
    char pad0[0x28];
    float y;
    float x;
    unsigned char active;
    char pad31[3];
};

class Body {
public:
    void FUN_00308fe0();
    void FUN_00309410();

    char pad0[0x10];
    Controller *controller;
    char pad14[0x3c - 0x14];
    float sumX;
    float sumY;
    float invSumY;
    char pad48[0x1f8 - 0x48];
    Part *parts;
    int partCount;
};

void Body::FUN_00309410() {
    sumX = 0;
    sumY = 0;
    for (int i = 0; i < partCount; i++) {
        Part *p = &parts[i];
        if (p->active) {
            sumX = p->x + sumX;
            sumY = p->y + sumY;
        }
    }
    if (sumY > 0.0f) {
        invSumY = 1.0f / sumY;
    } else {
        controller->FUN_002ef8b0(0);
    }
    FUN_00308fe0();
}
