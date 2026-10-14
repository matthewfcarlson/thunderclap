class Target {
  public:
    char pad[0x50];
    float value;
    char Set(float x);
};

char Target::Set(float x) {
    value = x * 0.017453292519943295f;
    return 1;
}
