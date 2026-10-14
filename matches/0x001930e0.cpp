class Obj_1930e0 {
  public:
    char pad[0x5c];
    int value;
    bool Set(int v);
};

bool Obj_1930e0::Set(int v) {
    value = v;
    return true;
}
