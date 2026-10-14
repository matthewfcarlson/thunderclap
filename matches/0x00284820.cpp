class C_284820 {
  public:
    char pad[0x24];
    int count;
    void A(int);
    void B(int);
    void D(int);
    void E(int);
    void Target(int);
};
void C_284820::Target(int x) {
    A(x);
    B(x);
    D(x);
    E(x);
    ++count;
}