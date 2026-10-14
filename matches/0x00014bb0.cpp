struct Z;
struct C_14bb0 {
    bool IsOk();
    Z* GetZ(int);
};
struct B_14bb0 {
    C_14bb0* GetC();
};
struct A_14bb0 {
    B_14bb0* GetB();
};
struct SoundObj_14bb0 {
    char pad[0x10];
    char data[0x40];
    char flag;
};
struct Out_14bb0 {
    void Send(C_14bb0*, void*);
    void Play(Z*, void*, float, int);
};
struct Mgr_14bb0 {
    char pad[0x34];
    Out_14bb0* out;
};
extern Mgr_14bb0* gMgr_14bb0;
class CSoundAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual bool Fn(int);
    virtual void f8();
    char pad[0x18];
    A_14bb0* m1c;
    SoundObj_14bb0* m20;
};
bool CSoundAction::Fn(int) {
    C_14bb0* c = m1c->GetB()->GetC();
    if (!m20->flag) {
        gMgr_14bb0->out->Send(c, m20->data);
        return false;
    }
    if (c->IsOk()) {
        Z* z = c->GetZ(0);
        if (z)
            gMgr_14bb0->out->Play(z, m20->data, 100.0f, 0);
    }
    return false;
}
