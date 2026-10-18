class Item_266f20 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void h();
    virtual int g(int);
};
struct Entry_266f20 {
    Item_266f20* ptr;
    char pad[12];
};
extern Entry_266f20 gItems_266f20[];
int target(int index, int value) {
    return gItems_266f20[index].ptr->g(value);
}