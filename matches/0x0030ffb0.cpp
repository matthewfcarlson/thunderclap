class Item_30ffb0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void invoke(void*);
};
class Container_30ffb0 {
  public:
    char pad[16];
    int limit;
    char p[4];
    int* counts;
    Item_30ffb0*** items;
    void run(int, void*);
};
void Container_30ffb0::run(int index, void* arg) {
    if (index < 0 || index >= limit)
        return;
    int i = 0;
    if (counts[index] <= 0)
        return;
    do {
        if (*((char*)items[index][i] + 16))
            items[index][i]->invoke(arg);
        ++i;
    } while (i < counts[index]);
}
