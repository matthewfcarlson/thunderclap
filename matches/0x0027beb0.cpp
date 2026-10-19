struct Base {
    virtual void unused();
    char pad[12];
    int value;
    Base() : value(0) {}
};
struct Limb : Base {
    char extra[20];
    virtual void other();
};
struct Wrapper {
    void FUN_0027be00(void*, Limb*);
    void FUN_0027beb0(void* arg);
};
void Wrapper::FUN_0027beb0(void* arg) {
    Limb limb;
    FUN_0027be00(arg, &limb);
}