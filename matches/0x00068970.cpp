class Obj_68970 {
  public:
    char pad[0x10];
    int m;
    bool Set(int x);
};

bool Obj_68970::Set(int x) {
    m = x;
    return true;
}
