class Obj {
  public:
    char pad[0x34];
    float f;
    float Get();
};
float Obj::Get() {
    return f;
}
