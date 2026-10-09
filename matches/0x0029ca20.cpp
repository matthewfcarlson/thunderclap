class Item {
  public:
    virtual void F();
    virtual void G();
};
class Target {
  public:
    Item* a;
    Item* b;
    Item* c;
    Item* d;
    void Run();
};
void Target::Run() {
    d->G();
    c->G();
    b->G();
    a->G();
}