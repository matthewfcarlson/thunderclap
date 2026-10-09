class Obj {
  public:
    virtual void f();
    virtual void g();
};
class Owner {
  public:
    char pad[0x78];
    Obj* item;
    void set(Obj* p);
};
void Owner::set(Obj* p) {
    if (p)
        p->f();
    if (item)
        item->g();
    item = p;
}