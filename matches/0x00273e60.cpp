class Inner_273e60 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual int k(int, int);
    int m();
};
class Sub_273e60 {
  public:
    virtual void a();
    virtual void b();
};
struct Data_273e60 {
    char pad0[4];
    Sub_273e60 sub;
    char pad8[4];
    Inner_273e60* inner;
    char pad10[4];
    int y;
    char pad18[0x15c - 0x18];
    int field;
};
class FileCommitRequest {
  public:
    virtual void v0();
    virtual int v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    char pad[4];
    Data_273e60* volatile data;
};
int FileCommitRequest::v1() {
    Data_273e60* d = data;
    Inner_273e60* i = d->inner;
    int x = i->k(d->field, (int)((char*)d + 0x1e));
    int z = i->m();
    data->sub.a();
    data->y = z;
    data->sub.b();
    return x;
}