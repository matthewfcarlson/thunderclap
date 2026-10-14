class Obj_5a370 {
  public:
    char pad[0x10];
    int mValue;
    char Set(int value);
};

char Obj_5a370::Set(int value) {
    mValue = value;
    return 1;
}
