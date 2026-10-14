class Obj_192410 {
  public:
    char pad[0x76];
    char mVal;
    char Set(char value);
};

char Obj_192410::Set(char value) {
    mVal = value;
    return 1;
}
