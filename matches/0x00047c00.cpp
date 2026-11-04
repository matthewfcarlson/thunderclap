class Obj_47c00 {
  public:
    char pad[0x10];
    float m;
    char SetDirection_00047c00(float v);
};
char Obj_47c00::SetDirection_00047c00(float v) {
    m = v * 0.0174532923f;
    return 1;
}
