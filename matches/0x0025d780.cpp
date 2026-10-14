class Owner_25d780;
class Thing_25d780 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void Act(Owner_25d780*);
    virtual void d();
    virtual int Check(Owner_25d780*);
};
class Owner_25d780 {
  public:
    char pad[0x40];
    char* mData;
    char pad2[0x14];
    int mState;
    void Run();
};
void Owner_25d780::Run() {
    if (mData) {
        Thing_25d780* t = (Thing_25d780*)(mData - 4);
        if (t && t->Check(this) == 3)
            t->Act(this);
    }
    mState = 4;
}