class Obj {
  public:
    char pad[0x68];
    float angle;
    char Set(float v);
};
char Obj::Set(float v) {
    angle = v * 0.017453292f;
    return 1;
}