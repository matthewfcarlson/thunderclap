class Obj {
  public:
    char pad[0x48];
    float angle;
    char Set(float v);
};
char Obj::Set(float v) {
    angle = v * 0.017453292519943295f;
    return 1;
}
