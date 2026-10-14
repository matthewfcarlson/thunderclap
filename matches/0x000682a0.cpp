class Obj_682a0 {
  public:
    char pad[0x14];
    int m14;
    char Set(int value);
};

char Obj_682a0::Set(int value) {
    m14 = value;
    return 1;
}
