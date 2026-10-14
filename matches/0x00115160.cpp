class Obj_115160 {
  public:
    char f(float x);
    char pad[0x14];
    float value;
};
char Obj_115160::f(float x) {
    value = x * 0.0174532925f;
    return 1;
}
