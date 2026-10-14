struct Vec_2ef200 {
    float x, y, z;
};
class Inner_2ef200 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual Vec_2ef200* Get();
    char pad[0x15];
    unsigned char flag;
};
class Obj_2ef200 {
  public:
    char pad0[0x20];
    Inner_2ef200* inner;
    char pad1[0x44];
    unsigned char changed;
    void Add(Vec_2ef200* v);
};
void Obj_2ef200::Add(Vec_2ef200* v) {
    changed = 1;
    Vec_2ef200* p = inner->Get();
    p->x = p->x + v->x;
    p->y = v->y + p->y;
    p->z = v->z + p->z;
    inner->flag = 0;
}