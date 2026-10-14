class Obj {
  public:
    char pad[0x2c];
    int m2c;
    bool Set(int value);
};

bool Obj::Set(int value) {
    m2c = value;
    return true;
}
