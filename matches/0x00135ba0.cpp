struct A_135ba0 {
    A_135ba0* get();
    void init();
    int check();
};
struct Result_135ba0 {
    void apply(int, int);
};
struct FlyingAttackAction {
    char pad[0x1c];
    A_135ba0* mAt20;
    int mAt24;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc4();
    virtual void v5();
    void mid();
};
void FlyingAttackAction::vfunc4() {
    A_135ba0* edi = mAt20->get();
    edi->init();
    mid();
    int result = edi->check();
    if (result)
        ((Result_135ba0*)result)->apply(mAt24, 0);
}