class Obj_11b9f0 {
  public:
    char Set(int value);
    char pad[0x1c];
    int mValue;
};

char Obj_11b9f0::Set(int value) {
    mValue = value;
    return 1;
}
