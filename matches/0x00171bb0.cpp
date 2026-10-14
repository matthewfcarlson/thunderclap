class Actor_171bb0;
class Owner_171bb0 {
    char pad[0x25];

  public:
    unsigned char flag;
    Actor_171bb0* GetActor();
};
class Actor_171bb0 {
    char pad[0x2140];

  public:
    unsigned char field;
    void SetFlag(unsigned char);
    void SetPosition(void*);
};
class Manager_171bb0 {
  public:
    Owner_171bb0* GetOwner();
};
class DriftToPositionAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void vfunc_4();
    virtual void f5();
    char pad1[0x18];
    Owner_171bb0* owner;
    Manager_171bb0* manager;
    char pad24[0x2c];
    unsigned char a;
    unsigned char b;
    unsigned char c;
    char pad53[0x0b];
};
void DriftToPositionAction::vfunc_4() {
    Owner_171bb0* o = manager->GetOwner();
    if (o) {
        Actor_171bb0* a = o->GetActor();
        if (a) {
            if (owner->flag && c)
                a->SetPosition((char*)this + 0x40);
            a->field = b;
            a->SetFlag(this->a);
        }
    }
}