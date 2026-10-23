class A_2777f0 {
  public:
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2();
    virtual void v3() {}
    virtual void v4() {}
    virtual void v5() {}
    virtual void v6() {}
    virtual void v7() {}
    virtual void v8() {}
    int pad;
};
class B_2777f0 {
  public:
    virtual void v2();
};
class CementLibrary : public A_2777f0, public B_2777f0 {
  public:
    virtual void v2();
};
void CementLibrary::v2() {}
CementLibrary gObj_2777f0;
