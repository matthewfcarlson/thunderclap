class Obj_10c140 {
  public:
    char pad[12];
    int value;
    bool Set(int x);
};

bool Obj_10c140::Set(int x) {
    value = x;
    return true;
}