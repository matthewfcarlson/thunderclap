class Owner;
class Thing {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void Act(Owner*);
    virtual void d();
    virtual int Check(Owner*);
};
class Owner {
  public:
    char pad[0x40];
    char* mData;
    char pad2[0x14];
    int mState;
    void Run();
};
void Owner::Run() {
    if (mData) {
        Thing* t = (Thing*)(mData - 4);
        if (t && t->Check(this) == 3)
            t->Act(this);
    }
    mState = 4;
}