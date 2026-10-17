// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// CPathGraphAgent::vfunc_3 @ 0x00104930
extern float DAT_003f5d00;
extern float DAT_0040d510;
extern float DAT_003f32e0;

struct PathState {
    char pad[0x68];
    unsigned char blocked;
    char pad69;
    unsigned char active;
    char pad6b;
    float value;
};

struct CPathGraphAgent {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual float vfunc_3(int, int);
    char pad[0x58 - 4];
    PathState *state;
    unsigned char flag5c;
    unsigned char flag5d;
};

float CPathGraphAgent::vfunc_3(int, int) {
    PathState *s = state;
    if (!s->active && !(s->value < DAT_003f5d00) && !s->blocked)
        return DAT_0040d510;
    flag5d = 0;
    flag5c = 0;
    return DAT_003f32e0;
}