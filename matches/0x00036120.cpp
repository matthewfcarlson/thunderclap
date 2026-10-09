class C {
    char pad[0x110];

  public:
    float value;
    void Add(float x);
};
void C::Add(float x) {
    value += x;
}