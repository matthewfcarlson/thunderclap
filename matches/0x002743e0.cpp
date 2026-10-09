// Same code shape as 0x00273880 (propagated; names are from that function)
class Request {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int vfunc_3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
class FileRequest : public Request {
  public:
    int pad4;
    int* mThing;
    virtual int vfunc_3();
};
int FileRequest::vfunc_3() {
    return *(int*)((char*)mThing + 12);
}