class C_228700 {
  public:
    char pad[0x8ac];
    float value;
    void Target(int x);
};
float __cdecl Calc(int x);
void C_228700::Target(int x) {
    value = Calc(x);
}