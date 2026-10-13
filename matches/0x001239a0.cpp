class O {
  public:
    char pad[0x10];
    int m;
    bool Fn(int a);
};
bool O::Fn(int a) {
    m = a;
    return true;
}
