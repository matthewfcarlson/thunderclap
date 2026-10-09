struct P;
struct Sub {
    virtual void a();
    virtual void b();
};
struct Inner {
    void run(P* p, int v);
};
struct P {
    int x;
    Sub s;
    int a;
    Inner* i;
    int c;
    int d;
};
class FileCancelRequest {
  public:
    virtual void v0();
    virtual int v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    char pad[4];
    P* req;
};
int FileCancelRequest::v1() {
    req->i->run(req, req->c);
    req->s.a();
    req->d = 0;
    req->s.b();
    return 1;
}
