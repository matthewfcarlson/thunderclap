class Obj {
  public:
    char Pad[0x3c];
    float Value;
    char Fn(float a);
};
char Obj::Fn(float a) {
    Value = a * 0.01745329238474369f;
    return 1;
}
