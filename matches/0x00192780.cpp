class Obj {
  public:
    char pad[0x10];
    int m10;
    bool Set(int value);
};

bool Obj::Set(int value) {
    m10 = value;
    return true;
}
