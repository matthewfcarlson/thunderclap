class A_269550 {
  public:
    virtual void f(int);
};

class B_269550 {
  public:
    virtual void f(int);
};

class C_269550 : public A_269550, public B_269550 {
  public:
    virtual void f(int);
};


C_269550 gC_269550;
