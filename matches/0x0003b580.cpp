class Ref_3b580 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_3b580 {
    char pad[0x1b58];
    int count;
    float value;
    Ref_3b580* ref;

  public:
    void Fn(char, float, Ref_3b580*);
};
void Obj_3b580::Fn(char enable, float x, Ref_3b580* r) {
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