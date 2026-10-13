class Obj {
  public:
    char pad[0x30];
    int m30;
    bool Set(int value);
};

bool Obj::Set(int value) {
    m30 = value;
    return true;
}
