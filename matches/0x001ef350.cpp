class E {
  public:
    void F();
};
class C {
    char pad[0x40];

  public:
    void Run();
};
void C::Run() {
    E* p = (E*)((char*)this + 0x40);
    int n = 8;
    do {
        p = (E*)((char*)p - 8);
        p->F();
        --n;
    } while (n != 0);
}