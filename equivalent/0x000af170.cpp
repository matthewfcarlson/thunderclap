// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_000af170 @ 0x000af170
struct Samples {
    float v[17];
};

class Source_af170 {
public:
    void FUN_000ada70(Samples *out);
};

struct Track {
    int state;
    float held;
    float value;
};

struct Stick_af170 {
    int state;
    float held;
    float x;
    float y;
};

class InputTracker {
public:
    char pad0[8];
    Source_af170 *source;
    Track tracks[11];
    Stick_af170 sticks[2];
    void FUN_000af170(float dt);
};

static __forceinline void advance(int &state, float &held, float dt, bool active)
{
    if (active) {
        switch (state) {
        case 0:
            state = 1;
            held += dt;
            break;
        case 1:
            state = 2;
            held = dt;
            break;
        case 2:
            held += dt;
            break;
        case 3:
            state = 1;
            held = dt;
            break;
        }
    } else {
        switch (state) {
        case 0:
            held += dt;
            break;
        case 1:
            state = 3;
            held = dt;
            break;
        case 2:
            state = 3;
            held += dt;
            break;
        case 3:
            state = 0;
            held = dt;
            break;
        }
    }
}

void InputTracker::FUN_000af170(float dt)
{
    Samples in;
    source->FUN_000ada70(&in);
    for (int i = 0; i < 11; i++) {
        float v = in.v[i];
        advance(tracks[i].state, tracks[i].held, dt, v > 0.0f);
        tracks[i].value = v;
    }
    for (int i = 0; i < 2; i++) {
        float a = in.v[11 + i * 2];
        float b = in.v[12 + i * 2];
        union {
            float f;
            unsigned int u;
        } ta, tb;
        ta.f = a;
        ta.u &= 0x7fffffff;
        bool active = true;
        if (ta.f <= 1e-05f) {
            tb.f = b;
            tb.u &= 0x7fffffff;
            if (tb.f <= 1e-05f)
                active = false;
        }
        advance(sticks[i].state, sticks[i].held, dt, active);
        sticks[i].x = a;
        sticks[i].y = b;
    }
}
