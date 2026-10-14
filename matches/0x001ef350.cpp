class E_1ef350 {
  public:
    void F();
};
class C_1ef350 {
    char pad[0x40];

  public:
    void Run();
};
void C_1ef350::Run() {
    E_1ef350* p = (E_1ef350*)((char*)this + 0x40);
    int n = 8;
    do {
        p = (E_1ef350*)((char*)p - 8);
        p->F();
        --n;
    } while (n != 0);
}