class A {
  public:
    char pad[0x10];
    int m10;
    bool Init(int value);
};
bool A::Init(int value) {
    m10 = value;
    return true;
}
