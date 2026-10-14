class Obj {
  public:
    char pad[0x20];
    int m20;
    bool Set(int value);
};

bool Obj::Set(int value) {
    m20 = value;
    return true;
}
