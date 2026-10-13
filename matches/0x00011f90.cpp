class Obj {
  public:
    char pad[0x18];
    float value;
    float Get();
};
float Obj::Get() {
    return value;
}
