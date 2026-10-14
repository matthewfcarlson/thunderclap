const float scale_1c8590 = 1000.0f;
class Item_1c8590 {
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
class Owner_1c8590 {
  public:
    char pad0[8];
    Item_1c8590* one;
    Item_1c8590* two;
    char pad14[0x18];
    int count;
    Item_1c8590** items;
    void Run(float);
};
void Owner_1c8590::Run(float dt) {
    if (one)
        one->g(dt * scale_1c8590, 0);
    if (two)
        two->g(dt * scale_1c8590, 0);
    int i = 0;
    for (;;) {
        Item_1c8590** a = items;
        while (a[i] == 0 && i <= count)
            ++i;
        if (i > count)
            break;
        Item_1c8590* p = a[i++];
        if (!p)
            break;
        p->Update(dt);
    }
}