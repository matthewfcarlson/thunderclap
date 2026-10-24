namespace movie {
class RenderStrategy {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
};
class Secondary {
  public:
    virtual void vfunc_2(int);
};
class RenderStrategyBink : public RenderStrategy, public Secondary {
  public:
    virtual void vfunc_2(int);
};
RenderStrategyBink instance;
} // namespace movie