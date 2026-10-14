class Obj_68350 {
  public:
    char pad[0x10];
    int m10;
    bool Set(int value);
};

bool Obj_68350::Set(int value) {
    m10 = value;
    return true;
}
