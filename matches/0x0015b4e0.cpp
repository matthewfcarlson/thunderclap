class Obj_15b4e0 {
  public:
    char Set(int value);
    char pad[0xc];
    int mValue;
};

char Obj_15b4e0::Set(int value) {
    mValue = value;
    return 1;
}
