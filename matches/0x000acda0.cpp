class Obj {
    char pad[0x494];
    float value;

  public:
    float GetValue();
};

float Obj::GetValue() {
    return value;
}