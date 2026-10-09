class Obj {
  public:
    virtual void f();
    virtual void g();
};
class Base {
  public:
    Base();
    virtual void a();
    char pad[0x18];
};
class Wall : public Base {
  public:
    Wall(int p, Obj* o);
    virtual void a();
    int m1;
    Obj* m2;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    float m3c;
    char m40;
    int m44;
    int m48;
    int m4c;
};
Wall::Wall(int p, Obj* o) {
    int* q = &m1;
    *q = 0;
    m2 = 0;
    m24 = 0;
    m28 = 0;
    m2c = 0;
    m30 = 0;
    m34 = 0;
    m38 = 0;
    m3c = -1.0f;
    m40 = 0;
    m44 = 0;
    m48 = 0;
    m4c = 0;
    m1 = p;
    if (o)
        o->f();
    if (m2)
        m2->g();
    m2 = o;
}
