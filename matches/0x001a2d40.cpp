class T {
  public:
    char Pad[0x194];
    int Value;
    bool Set(int x);
};

bool T::Set(int x) {
    Value = x;
    return true;
}