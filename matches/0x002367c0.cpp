class Source_2367c0 {
  public:
    virtual void V();
    int pad;
    int b;
    int a;
};
class Sub_2367c0 {
  public:
    void H(int, int, Source_2367c0*);
};
class Owner_2367c0 {
  public:
    char pad[0x38];
    Sub_2367c0 sub;
    bool F(Source_2367c0*);
};
bool Owner_2367c0::F(Source_2367c0* src) {
    int b = src->b;
    int a = src->a;
    src->V();
    sub.H(b, a, src);
    return true;
}