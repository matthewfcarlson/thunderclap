class Obj_1a4990 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void Call(int, int, int, int);
};
class Holder_1a4990 {
  public:
    virtual ~Holder_1a4990();
    char pad[0x10];
    Obj_1a4990* second;
    char rest[0x10];
    int* Run();
};
int* Holder_1a4990::Run() {
    Obj_1a4990* first = (Obj_1a4990*)this;
    first->Call(1, 6, 2, 1);
    if (second)
        second->Call(1, 2, 1, 1);
    return (int*)((char*)this + 0x28);
}