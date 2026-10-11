struct Request {
    int x[8];
    char a;
    char b;
};
class Result {
  public:
    virtual void Finish();
};
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual Result* Create(Request*);
};
Factory* gFactory;
class Owner {
  public:
    char pad[0x10];
    Result* result;
    bool Run(int, int, int, int, int, int, int, int);
};
bool Owner::Run(int a, int b, int c, int d, int e, int f, int g, int h) {
    Request request;
    request.b = 0;
    request.x[0] = a;
    request.x[1] = b;
    request.x[2] = c;
    request.x[3] = d;
    request.x[4] = e;
    request.x[5] = f;
    request.x[6] = g;
    request.x[7] = h;
    request.a = 1;
    result = gFactory->Create(&request);
    if (!result)
        return false;
    result->Finish();
    return true;
}
