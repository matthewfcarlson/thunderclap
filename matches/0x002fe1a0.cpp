class Ref {
  public:
    virtual void AddRef();
};
class Base {
  public:
    virtual void V();
    Base();
};
class WorldCollisionObject : public Base {
  public:
    char pad[0x0c];
    Ref* mRef;
    bool active;
    WorldCollisionObject(Ref*);
};
WorldCollisionObject::WorldCollisionObject(Ref* r) : Base() {
    mRef = r;
    active = true;
    if (r)
        r->AddRef();
}