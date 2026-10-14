class Host;
class MyFileStream {
  public:
    virtual void vf();
    int a, b, c;
    MyFileStream() : a(0), b(0), c(0) {}
};
class Wrapper {
  public:
    int dummy;
    MyFileStream stream;
    void Init() throw();
    void Close() throw();
    char Read(MyFileStream*, void*, int, Host*) throw();
};
class Host {
  public:
    int x, y;
    char Fn(void* p);
};
char Host::Fn(void* p) {
    Wrapper s;
    s.Init();
    if (s.Read(&s.stream, p, y, this)) {
        s.Close();
        return 1;
    }
    s.Close();
    return 0;
}