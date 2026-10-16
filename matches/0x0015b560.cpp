class Angle {
  public:
    char pad[0x1c];
    float value;
    char Set(float angle);
};
char Angle::Set(float angle) {
    value = angle * 0.0174532925f;
    return 1;
}