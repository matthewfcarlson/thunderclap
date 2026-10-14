class Obj_10c350 {
  public:
    char pad[0x10];
    int value;
    bool Set(int x);
};

bool Obj_10c350::Set(int x) {
    value = x;
    return true;
}
