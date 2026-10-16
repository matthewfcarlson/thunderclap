class Obj {
  public:
    char pad[0x30];
    float value;
    char Set(float x);
};
char Obj::Set(float x) {
    value = x * 0.017453292f;
    return 1;
}