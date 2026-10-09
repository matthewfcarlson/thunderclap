class AnimThing {
  public:
    void A(int, int);
    void B(int);
    void C(int);
    void D();
};
class GrappleThrowAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vfunc_5(int, int);
    char pad[0x48];
    int count;
    unsigned char flag;
};
void GrappleThrowAction::vfunc_5(int x, int y) {
    if (x == 0 && flag == 0)
        ((AnimThing*)((char*)this + 0x24))->A(count, y);
    flag = 0;
    ((AnimThing*)((char*)this + 0x24))->B(x);
    if (x == count - 1)
        ((AnimThing*)((char*)this + 0x24))->C(1);
    ((AnimThing*)((char*)this + 0x24))->D();
}