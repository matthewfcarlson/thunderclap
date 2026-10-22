class TrackFactoryCasterTemplate_13c290 {
  public:
    virtual void f();
};
extern void fun(void*, TrackFactoryCasterTemplate_13c290*);
void target(void* p) {
    TrackFactoryCasterTemplate_13c290 c;
    fun(p, &c);
}