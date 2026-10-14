class Obj {
  public:
    char pad[0x30];
    float value;
    char Set(float v);
};

char Obj::Set(float v) {
    value = v * 0.017453292f;
    return 1;
}