class Obj {
  public:
    char pad[0x1ce0];
    float value;
    float GetValue();
};

float Obj::GetValue() {
    return value;
}
