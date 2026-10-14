class Obj_146be0 {
  public:
    char pad[0xc];
    int mValue;
    char Set(int value);
};

char Obj_146be0::Set(int value) {
    mValue = value;
    return 1;
}
