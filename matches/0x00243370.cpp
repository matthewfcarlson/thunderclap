class Entity {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    char pad[0x20 - 4];
    short count;
    void vfunc_1();
};
void Entity::vfunc_1() {
    if (count == 1) {
        f2(1);
        return;
    }
    --count;
}