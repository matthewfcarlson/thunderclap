class Obj {
  public:
    char pad[0x10];
    float m;
    char Fn(float v);
};
char Obj::Fn(float v) {
    m = v * 0.0174532923f;
    return 1;
}
