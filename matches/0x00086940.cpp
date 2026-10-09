class A {
  public:
    void Run();
};
class B {
  public:
    void Finish();
};
class Thing {
  public:
    char pad[0x18];
    A* a;
    char pad2[0x14];
    B* b;
    void Run();
};
void Thing::Run() {
    a->Run();
    b->Finish();
}