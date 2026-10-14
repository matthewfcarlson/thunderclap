class O {
  public:
    char pad[0xc];
    int m;
    bool Set(int a);
};
bool O::Set(int a) {
    m = a;
    return true;
}
