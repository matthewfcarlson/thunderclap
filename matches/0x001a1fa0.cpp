class Obj_1a1fa0 {
  public:
    char pad[0x10];
    int m10;
    char Set(int value);
};

char Obj_1a1fa0::Set(int value) {
    m10 = value;
    return 1;
}
