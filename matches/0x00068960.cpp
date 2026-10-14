class Obj_68960 {
  public:
    char pad[12];
    int value;
    bool Set(int x);
};
bool Obj_68960::Set(int x) {
    value = x;
    return true;
}