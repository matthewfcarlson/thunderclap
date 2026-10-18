namespace physics {
struct Part_2f55b0 {
    void work(int);
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
    virtual void vfunc_9(int);
    char pad[0x1c4 - 4];
    char flag;
};
void PhysicsObject::vfunc_9(int a0) {
    flag = 1;
    ((Part_2f55b0*)((char*)this + 0x168))->work(a0);
}
} // namespace physics