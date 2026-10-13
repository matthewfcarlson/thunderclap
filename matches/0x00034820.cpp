class Obj {
  public:
    float Get();
    char pad[0x348];
    float value;
};
float Obj::Get() {
    return value;
}
