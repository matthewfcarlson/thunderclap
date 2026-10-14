class Obj {
  public:
    char pad[0x34];
    float m;
    char Set(float v);
};
char Obj::Set(float v) {
    m = v * 0.017453292519943295f;
    return 1;
}
