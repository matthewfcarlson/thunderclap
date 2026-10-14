class Obj {
  public:
    char pad[0x10];
    char value;
    bool Set(char c);
};

bool Obj::Set(char c) {
    value = c;
    return true;
}
