extern const float negativeOne;
class Obj {
  public:
    char pad[0x3c];
    float a;
    char pad2[4];
    float b;
    char pad3[8];
    unsigned char flag;
    void update();
};
void Obj::update() {
    if (a > negativeOne && b > negativeOne) {
        flag = a <= b ? 1 : 0;
    }
}