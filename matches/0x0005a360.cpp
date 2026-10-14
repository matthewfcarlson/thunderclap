class Obj_5a360 {
  public:
    char Pad[12];
    int mValue;
    char Set(int value);
};

char Obj_5a360::Set(int value) {
    mValue = value;
    return 1;
}
