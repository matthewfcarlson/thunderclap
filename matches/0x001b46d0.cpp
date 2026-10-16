class OtherClass {
  public:
    void Other(int a, float b);
};
extern OtherClass* g;
class Target {
  public:
    char pad[0x5a8];
    float value;
    void Fn(int a, float b);
};
void Target::Fn(int a, float b) {
    value = b;
    g->Other(a, b);
}