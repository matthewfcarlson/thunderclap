struct P_2742f0;
struct Sub_2742f0 {
    virtual void a();
    virtual void b();
};
struct Inner_2742f0 {
    void run(P_2742f0* p, int v);
};
struct P_2742f0 {
    int x;
    Sub_2742f0 s;
    int a;
    Inner_2742f0* i;
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
    P_2742f0* req;
};
int FileCancelRequest::v1() {
    req->i->run(req, req->c);
    req->s.a();
    req->d = 0;
    req->s.b();
    return 1;
}
