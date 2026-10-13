class Inner {
  public:
    void A();
};

class X {
  public:
    Inner** p;
    void Target();
};

void X::Target() {
    (*p)->A();
}
