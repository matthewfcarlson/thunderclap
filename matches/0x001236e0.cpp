class Obj_1236e0 {
  public:
    char pad[0x10];
    int value;
    bool Set(int a);
};

bool Obj_1236e0::Set(int a) {
    value = a;
    return true;
}