struct Vec {
    float x, y, z;
};
class Found {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual Vec* get(Vec*);
};
class Lookup {
  public:
    Found* find(int);
};
class Owner {
  public:
    char pad[0x28];
    Lookup* manager;
};
class Obj {
  public:
    char pad[0xc];
    Owner* owner;
    char pad2[0x4a8];
    Vec result;
    void work(int);
};
void Obj::work(int id) {
    Lookup* m = owner->manager;
    Found* p = m->find(id);
    if (!p) {
        result.z = 0;
        result.y = 0;
        result.x = 0;
        return;
    }
    Vec tmp;
    Vec* v = p->get(&tmp);
    result.x = v->x;
    result.y = v->y;
    result.z = v->z;
}