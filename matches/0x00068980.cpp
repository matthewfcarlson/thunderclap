class Obj {
  public:
    char pad[0x14];
    int value;
    bool Set(int arg);
};

bool Obj::Set(int arg) {
    value = arg;
    return true;
}