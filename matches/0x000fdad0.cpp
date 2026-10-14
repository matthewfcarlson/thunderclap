struct GolemPart {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual float vfunc_3(int a, int b);
    virtual void vfunc_4(int a, int b, bool changed);
    virtual void vfunc_5(int a, int b);
    virtual void vfunc_6();
    virtual void vfunc_7(int enabled);
};
struct CGolem {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(int a, int b);
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    int field4;
    int count;
    GolemPart* parts[16];
    int selected;
    char pad50[0xa4];
    bool disabled;
};
void CGolem::vfunc_4(int a, int b) {
    int previous = selected;
    selected = -1;
    float best = 0.0f;
    int winner = -1;
    for (int i = 0; i < count; ++i) {
        float score = parts[i]->vfunc_3(a, b);
        if (score > best) {
            best = score;
            winner = i;
        }
    }
    if (previous >= 0 && previous != winner)
        parts[previous]->vfunc_5(a, b);
    if (winner >= 0) {
        selected = winner;
        if (!disabled)
            parts[winner]->vfunc_4(a, b, winner != previous);
        parts[selected]->vfunc_7(1);
    }
}
