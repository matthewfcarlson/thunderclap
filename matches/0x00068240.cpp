class Obj_68240 {
  public:
    char pad[0x70];
    int value;
    bool Set(int x);
};

bool Obj_68240::Set(int x) {
    value = x;
    return true;
}
