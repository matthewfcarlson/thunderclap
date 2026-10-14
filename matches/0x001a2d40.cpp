class T_1a2d40 {
  public:
    char Pad[0x194];
    int Value;
    bool Set(int x);
};

bool T_1a2d40::Set(int x) {
    Value = x;
    return true;
}