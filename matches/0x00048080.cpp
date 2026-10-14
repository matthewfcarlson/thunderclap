class Obj_48080 {
  public:
    char m0[0xc];
    float mValue;
    char Convert(float degrees);
};

char Obj_48080::Convert(float degrees) {
    mValue = degrees * 0.017453293f;
    return 1;
}
