class Thing {
    char pad[0x70];
    float value;

  public:
    char Set(float x);
};
char Thing::Set(float x) {
    value = x * 0.017453292519943295f;
    return 1;
}