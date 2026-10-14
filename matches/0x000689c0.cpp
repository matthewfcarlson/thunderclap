class Obj_689c0 {
  public:
    char pad[0x10];
    int mValue;
    char Set(int value);
};

char Obj_689c0::Set(int value) {
    mValue = value;
    return 1;
}
