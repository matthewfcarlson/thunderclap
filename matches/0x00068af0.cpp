class Obj_68af0 {
  public:
    char pad[0x58];
    int value;
    bool Set(int x);
};

bool Obj_68af0::Set(int x) {
    value = x;
    return true;
}