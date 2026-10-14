class Inner_1eb550 {
  public:
    void A();
};

class X_1eb550 {
  public:
    Inner_1eb550** p;
    void Target();
};

void X_1eb550::Target() {
    (*p)->A();
}
