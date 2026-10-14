class C {
  public:
    char pad[0x10];
    int mValue;
    bool Init(int value);
};

bool C::Init(int value) {
    mValue = value;
    return true;
}
