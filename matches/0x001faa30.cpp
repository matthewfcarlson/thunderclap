class MyBufferStream {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool vfunc_4();
    int pad;
    int mSize;
    int mPosition;
};
bool MyBufferStream::vfunc_4() {
    return mPosition < mSize;
}