extern "C" void* __cdecl Alloc(int);
struct Entity {
    void Init();
};
struct Condition {
    char pad[0xc];
    int value;
    Entity ent;
    void Ctor(int);
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Condition* Create();
};
Condition* Factory::Create() {
    Condition* p = (Condition*)Alloc(0x18);
    if (p) {
        p->Ctor(0);
        *(void**)p = (void*)0x3f734c;
        *(int*)((char*)p + 0xc) = 0;
        p->ent.Init();
        return p;
    }
    return 0;
}