struct State_3111f0 {
    char pad[0x94];
    char busy;
};
struct H3_3111f0 {
    void* Get();
};
struct H2_3111f0 {
    H3_3111f0* Get();
};
struct H1 {
    H2_3111f0* Get(int);
};
struct Item_3111f0 {
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
struct Obj_3111f0 {
    char pad0[0x10];
    State_3111f0* state;
    char pad1[0x1e4];
    Item_3111f0** items;
    char pad2[4];
    int count;
    char pad3[4];
    H1* helper;
    void Run();
    void Tail();
};
void Obj_3111f0::Run() {
    if (state->busy)
        return;
    for (int i = 0; i < count; i++) {
        H2_3111f0* h = helper->Get(items[i]->id);
        items[i]->Use(h->Get()->Get());
    }
    Tail();
}