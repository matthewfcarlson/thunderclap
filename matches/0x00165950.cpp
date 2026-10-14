class A_165950 {
  public:
    char pad[0x10];
    int value;
    bool Set(int x);
};

bool A_165950::Set(int x) {
    value = x;
    return true;
}
