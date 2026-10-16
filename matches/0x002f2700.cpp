class Obj {
  public:
    char pad[8];
    float a;
    char pad2[12];
    float b;
    void Set(float v);
};
void Obj::Set(float v) {
    b = v;
    a = v;
}