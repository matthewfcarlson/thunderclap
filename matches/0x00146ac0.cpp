class C {
  public:
    char pad[0x20];
    int m;
    bool Fn(int x);
};
bool C::Fn(int x) {
    m = x;
    return true;
}
