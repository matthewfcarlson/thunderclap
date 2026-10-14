class Obj {
  public:
    char pad[0x38];
    int m38;
    bool Set(int value);
};

bool Obj::Set(int value) {
    m38 = value;
    return true;
}
