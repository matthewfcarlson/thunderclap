class CRadMovieRenderLoop {
public:
    virtual void AddRef();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char mPad[4];
    int mRefCount;
};

void CRadMovieRenderLoop::AddRef() {
    mRefCount++;
}
