class Stream {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Read(void*, int);
};
class Obj {
    char pad[8];
    Stream* stream;
    unsigned char a, b, c;

  public:
    void Run();
    void Update();
};
void Obj::Run() {
    int x;
    stream->Read(&x, 4);
    char y[4] = {0, 0, 0, 0};
    stream->Read(y, 4);
    signed char k = y[0];
    a = k & 1;
    int t = k;
    b = ((unsigned int)t >> 1) & 1;
    c = ((unsigned int)t >> 2) & 1;
    Update();
}