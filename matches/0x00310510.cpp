class PhysicsObject {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void vfunc_7();
};
class Node {
  public:
    void clean();
};
class ArticulatedPhysicsObject : public PhysicsObject {
  public:
    virtual void vfunc_7();
    char pad[0x1f4];
    Node** mItems;
    int gap;
    int mCount;
};
void ArticulatedPhysicsObject::vfunc_7() {
    PhysicsObject::vfunc_7();
    int i = 0;
    if (mCount > 0) {
        do {
            mItems[i]->clean();
            ++i;
        } while (i < mCount);
    }
}