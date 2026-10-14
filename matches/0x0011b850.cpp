class Obj_11b850 {
  public:
    char pad[0x18];
    char m18;
    char Set(unsigned char value);
};

char Obj_11b850::Set(unsigned char value) {
    m18 = value;
    return 1;
}
