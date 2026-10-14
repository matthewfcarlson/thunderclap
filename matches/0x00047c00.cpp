class Obj_47c00 {
  public:
    char pad[0x10];
    float m;
    char Fn(float v);
};
char Obj_47c00::Fn(float v) {
    m = v * 0.0174532923f;
    return 1;
}
