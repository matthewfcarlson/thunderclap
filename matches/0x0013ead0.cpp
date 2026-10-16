class Obj {
    char pad[0x24];
    float angle;

  public:
    char Set(float x);
};
char Obj::Set(float x) {
    angle = x * 0.017453292519943295f;
    return 1;
}