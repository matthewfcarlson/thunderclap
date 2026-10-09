class Inner {
  public:
    virtual void a();
    virtual void b();
};
void thunk(void*);
void thunk2(void*);
class Target {
  public:
    Inner* mObj;
    void* mArg;
    Target* run(unsigned char flags);
};
Target* Target::run(unsigned char flags) {
    mObj->b();
    thunk2(mArg);
    if (flags & 1)
        thunk(this);
    return this;
}
