class Angle {
  public:
    char pad[12];
    float val;
    char Set(float x);
};
char Angle::Set(float x) {
    val = x * 0.017453292519943295f;
    return 1;
}