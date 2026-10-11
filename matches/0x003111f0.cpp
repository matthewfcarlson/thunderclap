struct State {
    char pad[0x94];
    char busy;
};
struct H3 {
    void* Get();
};
struct H2 {
    H3* Get();
};
struct H1 {
    H2* Get(int);
};
struct Item {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void Use(void*);
    int pad;
    int id;
};
struct Obj {
    char pad0[0x10];
    State* state;
    char pad1[0x1e4];
    Item** items;
    char pad2[4];
    int count;
    char pad3[4];
    H1* helper;
    void Run();
    void Tail();
};
void Obj::Run() {
    if (state->busy)
        return;
    for (int i = 0; i < count; i++) {
        H2* h = helper->Get(items[i]->id);
        items[i]->Use(h->Get()->Get());
    }
    Tail();
}