class Obj_68a50 {
  public:
    char Pad[0x3c];
    float Value;
    char Fn(float a);
};
char Obj_68a50::Fn(float a) {
    Value = a * 0.01745329238474369f;
    return 1;
}
