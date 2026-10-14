class Obj {
  public:
    char pad[0x8c];
    int m8c;
    bool Set(int value);
};
bool Obj::Set(int value) {
    m8c = value;
    return true;
}
