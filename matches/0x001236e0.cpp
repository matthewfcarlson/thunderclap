class Obj {
  public:
    char pad[0x10];
    int value;
    bool Set(int a);
};

bool Obj::Set(int a) {
    value = a;
    return true;
}