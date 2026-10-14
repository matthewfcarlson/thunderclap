class Obj {
  public:
    char m0[0xc];
    float mValue;
    char Convert(float degrees);
};

char Obj::Convert(float degrees) {
    mValue = degrees * 0.017453293f;
    return 1;
}
