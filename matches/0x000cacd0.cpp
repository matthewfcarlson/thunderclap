struct Vec_cacd0 {
    float x, y, z;
};
class Found_cacd0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual Vec_cacd0* get(Vec_cacd0*);
};
class Lookup_cacd0 {
  public:
    Found_cacd0* find(int);
};
class Owner_cacd0 {
  public:
    char pad[0x28];
    Lookup_cacd0* manager;
};
class Obj_cacd0 {
  public:
    char pad[0xc];
    Owner_cacd0* owner;
    char pad2[0x4a8];
    Vec_cacd0 result;
    void work(int);
};
void Obj_cacd0::work(int id) {
    Lookup_cacd0* m = owner->manager;
    Found_cacd0* p = m->find(id);
    if (!p) {
        result.z = 0;
        result.y = 0;
        result.x = 0;
        return;
    }
    Vec_cacd0 tmp;
    Vec_cacd0* v = p->get(&tmp);
    result.x = v->x;
    result.y = v->y;
    result.z = v->z;
}