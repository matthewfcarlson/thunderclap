class PhysicsObject {
  public:
    char pad[0x148];
    unsigned char flag;
    char pad2[3];
    int c, b, a, f, e, d;
    void vfunc_27(int);
};
void PhysicsObject::vfunc_27(int x) {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    flag = 1;
}