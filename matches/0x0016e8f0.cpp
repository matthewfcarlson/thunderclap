class Target_16e8f0 {
  public:
    char pad[0x50];
    float value;
    char Set(float x);
};

char Target_16e8f0::Set(float x) {
    value = x * 0.017453292519943295f;
    return 1;
}
