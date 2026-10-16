class Thing {
  public:
    char pad[0x30];
    float angle;
    char Set(float a);
};
char Thing::Set(float a) {
    angle = a * 0.017453292f;
    return 1;
}