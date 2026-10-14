class Obj {
  public:
    char pad[0x14];
    int field;
    bool Set(int value);
};

bool Obj::Set(int value) {
    field = value;
    return true;
}