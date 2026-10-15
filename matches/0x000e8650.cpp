class Obj {
    char pad[0x3c];
    float a;
    char pad2[4];
    float b;
    char pad3[8];
    char flag;

  public:
    void Set(float x);
};
void Obj::Set(float x) {
    a = x;
    if (x > -1.0f && b > -1.0f) {
        int v = x <= b ? 1 : 0;
        flag = v;
    }
}