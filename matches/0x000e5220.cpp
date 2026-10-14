struct Node {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int, int);
    virtual void v9();
    virtual void v10();
    virtual void v11();
};
struct Renderer_e5220 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(int);
    virtual void v16(int);
};
struct Context {
    Renderer_e5220* renderer;
    void FUN_00293d00(void*);
};
extern Context* DAT_0052c2ac;
struct FEScreenBase {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    char pad04[0x24c - 4];
    Node* items[128];
    char pad44c[0x9a4 - 0x44c];
    Node* groupA[4];
    char pad9b4[0x10];
    Node* groupB[6];
    char pad9dc[8];
    Node* groupC[32];
    char pada64[0x34];
    char state[0x20];
    unsigned char enabled;
    unsigned char visible;
    char padaba[2];
    Node* children[32];
    int childCount;
};
void FEScreenBase::vfunc_11() {
    if (!enabled || !visible)
        return;
    DAT_0052c2ac->renderer->v15(0);
    DAT_0052c2ac->FUN_00293d00(state);
    for (int i = 0; i < 4; ++i)
        if (groupA[i])
            groupA[i]->v8(0, 0);
    for (int j = 0; j < 6; ++j)
        if (groupB[j])
            groupB[j]->v8(0, 0);
    for (int k = 0; k < 32 && groupC[k]; ++k)
        groupC[k]->v3();
    for (int m = 0; m < 128 && items[m]; ++m)
        items[m]->v2();
    DAT_0052c2ac->renderer->v16(0);
    for (int n = 0; n < childCount; ++n)
        children[n]->v11();
}
