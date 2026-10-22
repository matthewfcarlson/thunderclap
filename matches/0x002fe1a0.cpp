class Ref_2fe1a0 {
  public:
    virtual void AddRef();
};
class Entity_2fe1a0 {
  public:
    virtual void V();
    Entity_2fe1a0();
};
class WorldCollisionObject : public Entity_2fe1a0 {
  public:
    char pad[0x0c];
    Ref_2fe1a0* mRef;
    bool active;
    WorldCollisionObject(Ref_2fe1a0*);
};
WorldCollisionObject::WorldCollisionObject(Ref_2fe1a0* r) : Entity_2fe1a0() {
    mRef = r;
    active = true;
    if (r)
        r->AddRef();
}