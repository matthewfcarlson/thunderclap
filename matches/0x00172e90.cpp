class Sub {
  public:
    void run();
    char pad[8];
};
class SyncToLocatorTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual SyncToLocatorTrack* vfunc_5(unsigned char flags);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x1c];
    Sub sub;
    void* mThing;
    void step();
};
void cleanup(void* p);
void destroyObj(SyncToLocatorTrack* p);

SyncToLocatorTrack* SyncToLocatorTrack::vfunc_5(unsigned char flags) {
    *(unsigned long*)this = 0x417988;
    cleanup(mThing);
    sub.run();
    step();
    if (flags & 1)
        destroyObj(this);
    return this;
}
