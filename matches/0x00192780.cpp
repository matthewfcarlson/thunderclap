class Obj_192780 {
  public:
    char pad[0x10];
    int m10;
    bool Set(int value);
};

bool Obj_192780::Set(int value) {
    m10 = value;
    return true;
}
