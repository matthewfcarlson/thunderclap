class Obj {
  public:
    char pad[0x1c];
    float value;
    float Get();
};

float Obj::Get() {
    return value;
}
