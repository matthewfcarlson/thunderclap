// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_000e5440 @ 0x000e5440
extern float DAT_003f32e0;

class Fader_e5440 {
public:
    char pad00[0xa74];
    float level;             // 0xa74
    int state;               // 0xa78
    int stateTime;           // 0xa7c
    char padA80[0x10];
    float base;              // 0xa90
    char padA94[0xc];
    float output;            // 0xaa0
    void FUN_000e5330();
    void FUN_000e53e0(int oldState);
    void FUN_000e5440(int newState);
};

void Fader_e5440::FUN_000e5440(int newState) {
    int old = state;
    state = newState;
    switch (newState) {
    case 0:
        level = 0;
        output = base * 0.0f;
        if (old != 0)
            FUN_000e53e0(old);
        break;
    case 1:
        level = 1.0f;
        output = base;
        stateTime = 0;
        if (old != 1)
            FUN_000e5330();
        break;
    case 2:
        level = 0;
        stateTime = 0;
        output = base * 0.0f;
        if (old != 2)
            FUN_000e5330();
        break;
    }
}
