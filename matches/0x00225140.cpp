extern const float one;
extern const float zero;
struct Inner {
    char pad[0x10];
    float f;
};
class Obj {
  public:
    char pad[0x20];
    Inner* p;
    char pad2[0x20c];
    float value;
    void Set(float x);
};
void Obj::Set(float x) {
    float v = p->f - one;
    if (x < zero) {
        value = 0;
        return;
    }
    if (x > v)
        value = v;
    else
        value = x;
}
