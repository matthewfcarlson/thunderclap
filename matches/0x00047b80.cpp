class O {
  public:
    char pad[0x1c];
    float m;
    char F(float angle);
};
char O::F(float angle) {
    m = angle * 0.017453292519943295f;
    return 1;
}
