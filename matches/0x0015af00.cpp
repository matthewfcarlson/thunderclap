class Obj {
  public:
    char pad[0x34];
    int m34;
    bool Set(int value);
};

bool Obj::Set(int value) {
    m34 = value;
    return true;
}