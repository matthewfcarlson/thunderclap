class Obj {
  public:
    char pad[12];
    int value;
    bool Set(int v);
};

bool Obj::Set(int v) {
    value = v;
    return true;
}
