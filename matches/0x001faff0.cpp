class Host_1faff0;
class MyFileStream {
  public:
    virtual void vf();
    int a, b, c;
    MyFileStream() : a(0), b(0), c(0) {}
};
class Wrapper_1faff0 {
  public:
    int dummy;
    MyFileStream stream;
    void Init() throw();
    void Close() throw();
    char Read(MyFileStream*, void*, int, Host_1faff0*) throw();
};
class Host_1faff0 {
  public:
    int x, y;
    char Fn(void* p);
};
char Host_1faff0::Fn(void* p) {
    Wrapper_1faff0 s;
    s.Init();
    if (s.Read(&s.stream, p, y, this)) {
        s.Close();
        return 1;
    }
    s.Close();
    return 0;
}