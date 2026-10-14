class A_687b0 {
  public:
    char Pad[0x10];
    int Value;
    bool Set(int x);
};

bool A_687b0::Set(int x) {
    Value = x;
    return true;
}
