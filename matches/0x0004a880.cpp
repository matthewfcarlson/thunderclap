extern int vftA, vftB;
class Sub_4a880 {
  public:
    void Init();
};
class C_4a880 {
  public:
    char pad[0x10];
    Sub_4a880 sub;
    void Finish();
    void Run();
};
void C_4a880::Run() {
    *(int*)this = (int)&vftA;
    sub.Init();
    *(int*)this = (int)&vftB;
    Finish();
}