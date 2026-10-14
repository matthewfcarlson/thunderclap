class Obj_68080 {
  public:
    char pad[0x3c];
    int value;
    bool Set(int x);
};

bool Obj_68080::Set(int x) {
    value = x;
    return true;
}
