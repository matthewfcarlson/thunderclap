class A_1a25c0 {
  public:
    char pad[0xa4];
    int value;
    bool Set(int v);
};

bool A_1a25c0::Set(int v) {
    value = v;
    return true;
}
