class Obj_193320 {
  public:
    char pad[0x90];
    int value;
    bool Set(int x);
};

bool Obj_193320::Set(int x) {
    value = x;
    return true;
}
