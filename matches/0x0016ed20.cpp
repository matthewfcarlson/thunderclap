class Obj_16ed20 {
  public:
    char pad[0x34];
    float m;
    char Set(float v);
};
char Obj_16ed20::Set(float v) {
    m = v * 0.017453292519943295f;
    return 1;
}
