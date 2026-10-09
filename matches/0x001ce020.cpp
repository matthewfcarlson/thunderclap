class Obj {
  public:
    char pad[0x1198];
    float value;
    char pad2[4];
    unsigned char flag;
    int Check();
    void First(float);
    void Second(float);
    void Target(float);
};
void Obj::Target(float x) {
    if (Check()) {
        if (!flag)
            value += x;
        First(x);
        Second(x);
    }
}