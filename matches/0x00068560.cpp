class Obj_68560 {
  public:
    char pad[0x10];
    int mValue;
    char Set(int value);
};

char Obj_68560::Set(int value) {
    mValue = value;
    return 1;
}