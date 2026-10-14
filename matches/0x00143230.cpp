class Obj_143230 {
  public:
    char pad[0xc];
    int value;
    bool Set(int v);
};

bool Obj_143230::Set(int v) {
    value = v;
    return true;
}
