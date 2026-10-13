class Obj {
  public:
    char pad[0x11b0];
    float value;
    float GetValue();
};

float Obj::GetValue() {
    return value;
}
