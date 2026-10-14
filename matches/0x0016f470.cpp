class Obj {
  public:
    char Pad[0x38];
    float Value;
    char Set(float x);
};

char Obj::Set(float x) {
    Value = x * 0.017453292519943295f;
    return 1;
}
