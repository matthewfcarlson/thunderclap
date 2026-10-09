class A {
    char pad[0x258];

  public:
    int field;
    void Set(int value);
};
void A::Set(int value) {
    field = value;
}