class A_146d90 {
  public:
    char pad[0x30];
    float f30;
    char Set(float v);
};
char A_146d90::Set(float v) {
    f30 = v * 0.017453292f;
    return 1;
}
