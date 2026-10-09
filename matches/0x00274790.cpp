class V {
  public:
    virtual void A();
    virtual void B();
};
class Inner {
  public:
    virtual void X();
    virtual void Y();
    V obj;
    int x[3];
    int refs;
};
class Request {
  public:
    virtual void A();
    virtual void B();
};
class DriveRequest : public Request {
  public:
    char p[4];
    Inner* sub;
    void Cleanup();
};
void DriveRequest::Cleanup() {
    *(int*)this = 0x42b9bc;
    sub->obj.A();
    --sub->refs;
    sub->obj.B();
    sub->Y();
    *(int*)this = 0x42b914;
}
