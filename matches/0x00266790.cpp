class Sub {
  public:
    int f();
    int g();
};
class Obj {
    char pad0[0x14];
    int mode;
    char pad18[4];
    Sub* sub;

  public:
    float run();
};
extern const float one;
extern const float zero;
extern const float fix;
float Obj::run() {
    switch (mode) {
    case 3:
        return 1.0f;
    case 2:
        if (sub)
            return (float)(unsigned int)sub->f() / (float)(unsigned int)sub->g();
        return 0.0f;
    default:
        return 0.0f;
    }
}