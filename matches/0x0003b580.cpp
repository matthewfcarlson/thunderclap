class Ref {
  public:
    virtual void A();
    virtual void B();
};
class Obj {
    char pad[0x1b58];
    int count;
    float value;
    Ref* ref;

  public:
    void Fn(char, float, Ref*);
};
void Obj::Fn(char enable, float x, Ref* r) {
    if (enable) {
        ++count;
        if (count <= 0)
            return;
        if (x > value)
            value = x;
        if (r)
            r->A();
        if (ref)
            ref->B();
        ref = r;
    } else {
        --count;
        if (count > 0)
            return;
        float* q = &value;
        *q = 0.0f;
        if (ref) {
            ref->B();
            ref = 0;
        }
    }
}