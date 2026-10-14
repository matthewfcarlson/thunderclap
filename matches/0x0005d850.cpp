class Obj_5d850 {
  public:
    char pad[12];
    int value;
    bool Set(int v);
};

bool Obj_5d850::Set(int v) {
    value = v;
    return true;
}
