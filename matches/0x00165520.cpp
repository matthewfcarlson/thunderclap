class Thing {
    char pad[16];
    float angle;

  public:
    char Set(float x);
};
char Thing::Set(float x) {
    angle = x * 0.017453292f;
    return 1;
}