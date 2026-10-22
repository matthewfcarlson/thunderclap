extern void* vftable_2fe210;
class Entity_2fe210 {
  public:
    virtual void f0();
    virtual void f1();
};
class WorldCollisionObject : public Entity_2fe210 {
  public:
    virtual WorldCollisionObject* f2(unsigned char);
    char pad[12];
    void* member10;
    void helper();
};
void __cdecl thunk(WorldCollisionObject*);
WorldCollisionObject* WorldCollisionObject::f2(unsigned char flag) {
    *(void**)this = &vftable_2fe210;
    if (member10)
        ((Entity_2fe210*)member10)->f1();
    helper();
    if (flag & 1)
        thunk(this);
    return this;
}