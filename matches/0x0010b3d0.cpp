class Obj_10b3d0 {
  public:
    char pad[12];
    int value;
    bool Set(int v);
};

bool Obj_10b3d0::Set(int v) {
    value = v;
    return true;
}
