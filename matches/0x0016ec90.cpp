class Obj_16ec90 {
  public:
    char pad[0x14];
    int field;
    bool Set(int value);
};

bool Obj_16ec90::Set(int value) {
    field = value;
    return true;
}