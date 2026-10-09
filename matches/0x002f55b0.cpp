namespace physics {
struct Part {
    void work();
};
class PhysicsObject {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void vfunc_9();
    char pad[0x1c4 - 4];
    char flag;
};
void PhysicsObject::vfunc_9() {
    flag = 1;
    ((Part*)((char*)this + 0x168))->work();
}
} // namespace physics