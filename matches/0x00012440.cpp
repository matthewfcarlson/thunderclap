class A {
  public:
    char pad[0x20];
    float mX;
    float GetX();
};

float A::GetX() {
    return mX;
}