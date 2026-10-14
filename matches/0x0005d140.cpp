class Obj_5d140 {
  public:
    char pad[0x14];
    int m14;
    char Set(int value);
};

char Obj_5d140::Set(int value) {
    m14 = value;
    return 1;
}
