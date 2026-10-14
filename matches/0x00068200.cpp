class Obj_68200 {
  public:
    char pad[0x38];
    int m;
    bool Set(int v);
};

bool Obj_68200::Set(int v) {
    m = v;
    return true;
}
