class Obj_68940 {
  public:
    char pad[0x10];
    int m;
    bool Set(int v);
};

bool Obj_68940::Set(int v) {
    m = v;
    return true;
}