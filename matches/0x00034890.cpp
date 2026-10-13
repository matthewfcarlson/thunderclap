class Obj {
  public:
    char pad[0x370];
    float value;
    float GetValue();
};

float Obj::GetValue() {
    return value;
}
