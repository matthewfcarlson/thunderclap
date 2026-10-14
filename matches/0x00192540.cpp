class A_192540 {
  public:
    char pad[0xb8];
    int m;
    bool Set(int v);
};

bool A_192540::Set(int v) {
    m = v;
    return true;
}
