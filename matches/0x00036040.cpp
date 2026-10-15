class Obj {
    char pad[0x1b0c];
    float a;
    float b;

  public:
    char Set(float x);
};
char Obj::Set(float x) {
    if (b <= 0.0f)
        return 0;
    b = x;
    if (a > x)
        a = x;
    return 1;
}