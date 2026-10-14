class Obj_11b990 {
  public:
    char Set(int value);
    char pad[0x10];
    int m10;
};

char Obj_11b990::Set(int value) {
    m10 = value;
    return 1;
}
