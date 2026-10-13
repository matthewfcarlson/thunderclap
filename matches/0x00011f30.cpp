class Obj {
  public:
    char pad[0x14];
    float value;
    float GetValue();
};

float Obj::GetValue() {
    return value;
}