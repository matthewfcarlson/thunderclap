class O_47b80 {
  public:
    char pad[0x1c];
    float m;
    char F(float angle);
};
char O_47b80::F(float angle) {
    m = angle * 0.017453292519943295f;
    return 1;
}
