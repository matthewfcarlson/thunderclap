class OtherClass {
  public:
    void Other(int a, float b, float c);
};
extern OtherClass* g;
class Target {
  public:
    char pad[0x5a8];
    float value;
    void Fn(int a, float b, float c);
};
void Target::Fn(int a, float b, float c) {
    value = b;
    g->Other(a, b, c);
}