class Obj_1a2640 {
  public:
    char pad[0xb4];
    int m;
    bool Set(int x);
};

bool Obj_1a2640::Set(int x) {
    m = x;
    return true;
}
