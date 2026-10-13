class Obj {
  public:
    float Get();
    char pad[0x34];
    float value;
};
float Obj::Get() {
    return value;
}
