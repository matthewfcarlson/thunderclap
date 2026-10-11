extern "C" char DAT_00427368[];
struct Inner {
    virtual void A();
    virtual void B();
};
extern int gCount;
struct AnimationDriver {
    void* vptr;
    char pad[0x1c];
    Inner* mInner;
    void F();
    void Tail();
};
void AnimationDriver::F() {
    *(int*)this = ((int)DAT_00427368);
    mInner->B();
    --gCount;
    Tail();
}