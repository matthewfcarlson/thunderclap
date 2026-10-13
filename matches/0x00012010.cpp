class Obj {
  public:
    char pad[0x30];
    float f;
    float Get();
};
float Obj::Get() {
    return f;
}
