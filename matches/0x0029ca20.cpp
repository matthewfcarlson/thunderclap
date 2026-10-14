class Item_29ca20 {
  public:
    virtual void F();
    virtual void G();
};
class Target_29ca20 {
  public:
    Item_29ca20* a;
    Item_29ca20* b;
    Item_29ca20* c;
    Item_29ca20* d;
    void Run();
};
void Target_29ca20::Run() {
    d->G();
    c->G();
    b->G();
    a->G();
}