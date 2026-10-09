class Inner { public: Inner(); char d[0x28]; };
class Owner { public: virtual void F(); };
class Ref { public: virtual void Add(); virtual void Release(); };
class Base { public: Base(); virtual void B(); };
class SpawnAction : public Base {
public:
    SpawnAction(Owner *owner, int value, Ref *ref);
    virtual void V();
    char p4[0x18];
    int m1c;
    int m20;
    int m24;
    Inner inner;
    int m50;
    char flag;
};
SpawnAction::SpawnAction(Owner *owner, int value, Ref *ref) : Base(), m24(0), inner() {
    m50 = 0;
    flag = 0;
    m20 = (int)owner;
    owner->F();
    m1c = value;
    if (ref) ref->Add();
    if (m24) ((Ref *)m24)->Release();
    m24 = (int)ref;
}
