class A_146e70 {
  public:
    char pad[0x14];
    int value;
    bool Set(int x);
};

bool A_146e70::Set(int x) {
    value = x;
    return true;
}
