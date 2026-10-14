class Inner_29cc40 {
  public:
    virtual void a();
    virtual void b();
};
void thunk(void*);
void thunk2(void*);
class Target_29cc40 {
  public:
    Inner_29cc40* mObj;
    void* mArg;
    Target_29cc40* run(unsigned char flags);
};
Target_29cc40* Target_29cc40::run(unsigned char flags) {
    mObj->b();
    thunk2(mArg);
    if (flags & 1)
        thunk(this);
    return this;
}
