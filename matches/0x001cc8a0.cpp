extern const float gZero;
class C {
  public:
    char pad[0x1198];
    float a;
    float b;
};
float __fastcall FUN_001cc8a0(C* p) {
    if (*(int*)&p->b == (int)0xbf800000)
        return p->a;
    float x = p->b - p->a;
    if (x < gZero)
        x = gZero;
    return x;
}