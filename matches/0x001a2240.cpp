class Obj_1a2240 {
  public:
    char pad[0x38];
    int m38;
    bool Set(int value);
};

bool Obj_1a2240::Set(int value) {
    m38 = value;
    return true;
}