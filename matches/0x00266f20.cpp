class Item {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void h();
    virtual void g(int);
};
struct Entry {
    Item* ptr;
    char pad[12];
};
extern Entry gItems[];
void target(int index, int value) {
    gItems[index].ptr->g(value);
}