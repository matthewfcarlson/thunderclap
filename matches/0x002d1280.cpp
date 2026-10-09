class C {
    char pad0[0xc];
    int a;
    char pad1[0xc];
    int b;

  public:
    void Set(int x, int y);
};
void C::Set(int x, int y) {
    a = x;
    b = y;
}