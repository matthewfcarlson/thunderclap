class Obj {
  public:
    char pad[0x24];
    float value;
    float Get();
};

float Obj::Get() {
    return value;
}
