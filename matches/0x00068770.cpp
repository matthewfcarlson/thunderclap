class Obj_68770 {
  public:
    char pad[0xc];
    int value;
    bool Set(int x);
};

bool Obj_68770::Set(int x) {
    value = x;
    return true;
}