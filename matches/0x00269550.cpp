class A_269550 {
  public:
    virtual void f();
};

class B_269550 {
  public:
    virtual void f();
};

class C_269550 : public A_269550, public B_269550 {
  public:
    virtual void f();
};


C_269550 gC_269550;
