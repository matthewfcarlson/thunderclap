class Obj_68b50 {
  public:
    char pad[0x10];
    int value;
    bool Set(int x);
};

bool Obj_68b50::Set(int x) {
    value = x;
    return true;
}
