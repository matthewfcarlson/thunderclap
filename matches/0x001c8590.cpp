const float scale = 1000.0f;
class Item {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g(float, int);
    void Update(float);
};
class Owner {
  public:
    char pad0[8];
    Item* one;
    Item* two;
    char pad14[0x18];
    int count;
    Item** items;
    void Run(float);
};
void Owner::Run(float dt) {
    if (one)
        one->g(dt * scale, 0);
    if (two)
        two->g(dt * scale, 0);
    int i = 0;
    for (;;) {
        Item** a = items;
        while (a[i] == 0 && i <= count)
            ++i;
        if (i > count)
            break;
        Item* p = a[i++];
        if (!p)
            break;
        p->Update(dt);
    }
}