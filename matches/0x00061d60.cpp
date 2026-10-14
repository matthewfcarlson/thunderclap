class Obj_61d60 {
  public:
    char pad[0x10];
    int m;
    bool Set(int v);
};
bool Obj_61d60::Set(int v) {
    m = v;
    return true;
}