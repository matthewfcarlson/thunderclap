class Ref_2fe1a0 {
  public:
    virtual void AddRef();
};
class Base_2fe1a0 {
  public:
    virtual void V();
    Base_2fe1a0();
};
class WorldCollisionObject : public Base_2fe1a0 {
  public:
    char pad[0x0c];
    Ref_2fe1a0* mRef;
    bool active;
    WorldCollisionObject(Ref_2fe1a0*);
};
WorldCollisionObject::WorldCollisionObject(Ref_2fe1a0* r) : Base_2fe1a0() {
    mRef = r;
    active = true;
    if (r)
        r->AddRef();
}