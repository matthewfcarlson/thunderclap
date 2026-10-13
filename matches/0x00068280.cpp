class Obj {
  public:
    char pad[0xc];
    int value;
    bool Set(int arg);
};

bool Obj::Set(int arg) {
    value = arg;
    return true;
}
