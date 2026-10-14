// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 10/10)
// FUN_001c68e0 @ 0x001c68e0
extern float DAT_004c5314;

class Listener_1c68e0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float value, int arg);
};

struct Fader_1c68e0 {
    char pad00[8];
    char active;             // 0x08
    char pad09[3];
    Listener_1c68e0* listener;      // 0x0c
    char pad10[0x58 - 0x10];
    float timeLeft;          // 0x58
    void Update(float dt);
};

void Fader_1c68e0::Update(float dt)
{
    if (active == 0)
        return;
    if (timeLeft > 0.0f) {
        if (DAT_004c5314 <= 0.01f) {
            timeLeft = 0.0f;
        } else {
            timeLeft = timeLeft - dt / DAT_004c5314;
            if (timeLeft < 0.0f)
                timeLeft = 0.0f;
        }
    }
    if (listener != 0)
        listener->v6(dt * 1000.0f, 0);
}
