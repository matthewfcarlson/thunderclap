class C {
  public:
    char pad[0x18];
    int m18;
    void Fn(int x);
};
void C::Fn(int x) {
    m18 = x;
}
