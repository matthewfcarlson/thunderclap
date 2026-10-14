class Obj_180210 {
  public:
    char pad[0x18];
    int value;
    char Set(int x);
};

char Obj_180210::Set(int x) {
    value = x;
    return 1;
}
