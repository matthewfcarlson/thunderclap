extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b9bc[];
class V {
  public:
    virtual void A();
    virtual void B();
};
class Inner_274790 {
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
    Inner_274790* sub;
    void Cleanup();
};
void DriveRequest::Cleanup() {
    *(int*)this = ((int)DAT_0042b9bc);
    sub->obj.A();
    --sub->refs;
    sub->obj.B();
    sub->Y();
    *(int*)this = ((int)DAT_0042b914);
}
