class Obj_17f410 {
  public:
    char pad[0x28];
    int value;
    bool Set(int x);
};

bool Obj_17f410::Set(int x) {
    value = x;
    return true;
}
