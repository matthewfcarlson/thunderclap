class Inner_2250e0 {
    char pad[0x10];

  public:
    float value;
};
class Obj_2250e0 {
    char pad[0x20];

  public:
    Inner_2250e0* p;
    char pad2[0x208];
    float result;
    void set(float x);
};
void Obj_2250e0::set(float x) {
    float v = p->value - 1.0f;
    if (x < 0.0f)
        result = 0.0f;
    else if (x > v)
        result = v;
    else
        result = x;
}
