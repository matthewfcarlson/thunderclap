extern "C" char DAT_00416898[];
class Character {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    char pad[8];
    int x;
    int y;
    Character(int);
};
extern "C" void* Alloc(unsigned int);
class Factory_16ddc0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Character* v5();
};
Character* Factory_16ddc0::v5() {
    Character* p = (Character*)Alloc(0x14);
    if (p) {
        p->Character::Character(0);
        *(int*)p = ((int)DAT_00416898);
        p->x = 0;
        p->y = 0;
        return p;
    }
    return 0;
}