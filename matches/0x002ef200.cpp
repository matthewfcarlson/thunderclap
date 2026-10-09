struct Vec {
    float x, y, z;
};
class Inner {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual Vec* Get();
    char pad[0x15];
    unsigned char flag;
};
class Obj {
  public:
    char pad0[0x20];
    Inner* inner;
    char pad1[0x44];
    unsigned char changed;
    void Add(Vec* v);
};
void Obj::Add(Vec* v) {
    changed = 1;
    Vec* p = inner->Get();
    p->x = p->x + v->x;
    p->y = v->y + p->y;
    p->z = v->z + p->z;
    inner->flag = 0;
}