class Obj {
  public:
    char pad[15];
    char value;
    bool Set(char x);
};

bool Obj::Set(char x) {
    value = x;
    return true;
}
