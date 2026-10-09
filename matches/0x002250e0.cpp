class Inner {
    char pad[0x10];

  public:
    float value;
};
class Obj {
    char pad[0x20];

  public:
    Inner* p;
    char pad2[0x208];
    float result;
    void set(float x);
};
void Obj::set(float x) {
    float v = p->value - 1.0f;
    if (x < 0.0f)
        result = 0.0f;
    else if (x > v)
        result = v;
    else
        result = x;
}
