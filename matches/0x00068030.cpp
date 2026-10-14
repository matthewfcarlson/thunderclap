class A_68030 {
  public:
    char pad[32];
    int m20;
    bool Set(int x);
};

bool A_68030::Set(int x) {
    m20 = x;
    return true;
}
