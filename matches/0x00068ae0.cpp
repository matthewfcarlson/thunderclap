class Obj_68ae0 {
  public:
    char pad[0x54];
    int mValue;
    char Set(int value);
};

char Obj_68ae0::Set(int value) {
    mValue = value;
    return 1;
}
