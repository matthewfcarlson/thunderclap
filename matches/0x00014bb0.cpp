struct Z;
struct C {
    bool IsOk();
    Z* GetZ(int);
};
struct B {
    C* GetC();
};
struct A {
    B* GetB();
};
struct SoundObj {
    char pad[0x10];
    char data[0x40];
    char flag;
};
struct Out {
    void Send(C*, void*);
    void Play(Z*, void*, float, int);
};
struct Mgr {
    char pad[0x34];
    Out* out;
};
extern Mgr* gMgr;
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
    A* m1c;
    SoundObj* m20;
};
bool CSoundAction::Fn(int) {
    C* c = m1c->GetB()->GetC();
    if (!m20->flag) {
        gMgr->out->Send(c, m20->data);
        return false;
    }
    if (c->IsOk()) {
        Z* z = c->GetZ(0);
        if (z)
            gMgr->out->Play(z, m20->data, 100.0f, 0);
    }
    return false;
}
