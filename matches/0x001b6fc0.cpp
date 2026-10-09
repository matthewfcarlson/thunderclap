class CRadMovieRenderLoop {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(bool);
    virtual void vfunc_3();
    int pad;
    int mRefCount;
};
void CRadMovieRenderLoop::vfunc_1() {
    if (--mRefCount == 0)
        vfunc_2(true);
}