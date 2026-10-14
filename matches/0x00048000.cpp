class A_48000 {
  public:
    char pad[12];
    int mValue;
    bool Set(int x);
};

bool A_48000::Set(int x) {
    mValue = x;
    return true;
}
