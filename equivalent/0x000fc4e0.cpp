// STATUS: equivalent (tools/equiv.py level 3: 599 inputs, branch coverage 6/6)
// FUN_000fc4e0 @ 0x000fc4e0
class Scorer {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float v3(int a, int b);
};
class Target {
public:
    char pad0[0x10];
    int count;
    Scorer *items[(0x54 - 0x14) / 4];
    int selected;
    float FUN_000fc4e0(int a, int b);
};
float Target::FUN_000fc4e0(int a, int b)
{
    float best = 0.0f;
    int idx = -1;
    for (int i = 0; i < count; i++) {
        float v = items[i]->v3(a, b);
        if (v > best) {
            best = v;
            idx = i;
        }
    }
    selected = idx;
    return best;
}
