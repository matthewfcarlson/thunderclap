class Obj_11be50 {
  public:
    char Set(int value);
    char pad[0x1c];
    int mValue;
};

char Obj_11be50::Set(int value) {
    mValue = value;
    return 1;
}
