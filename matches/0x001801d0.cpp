class Obj_1801d0 {
  public:
    char pad[0x10];
    int m10;
    char Set(int value);
};

char Obj_1801d0::Set(int value) {
    m10 = value;
    return 1;
}
