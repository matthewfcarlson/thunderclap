extern int vftA, vftB;
class Sub {
  public:
    void Init();
};
class C {
  public:
    char pad[0x10];
    Sub sub;
    void Finish();
    void Run();
};
void C::Run() {
    *(int*)this = (int)&vftA;
    sub.Init();
    *(int*)this = (int)&vftB;
    Finish();
}