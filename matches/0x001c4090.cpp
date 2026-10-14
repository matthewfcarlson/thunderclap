class Obj_1c4090 {
  public:
    virtual void f();
    virtual void g();
};
class Owner_1c4090 {
  public:
    char pad[0x78];
    Obj_1c4090* item;
    void set(Obj_1c4090* p);
};
void Owner_1c4090::set(Obj_1c4090* p) {
    if (p)
        p->f();
    if (item)
        item->g();
    item = p;
}