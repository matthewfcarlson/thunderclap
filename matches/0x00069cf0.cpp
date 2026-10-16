class Obj {
    char pad[20];
    float angle;

  public:
    char Set(float x);
};
char Obj::Set(float x) {
    angle = x * 0.017453292f;
    return 1;
}