class Obj_18cc00 {
  public:
    char pad[0x18];
    int mValue;
    unsigned char Set(int value);
};

unsigned char Obj_18cc00::Set(int value) {
    mValue = value;
    return 1;
}
