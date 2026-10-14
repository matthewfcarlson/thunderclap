class Obj_13e8c0 {
  public:
    char pad[0x20];
    int m20;
    char SetFlag(int value);
};

char Obj_13e8c0::SetFlag(int value) {
    m20 = value;
    return 1;
}
