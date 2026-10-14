extern int Log(void* buf, int size, const char* fmt, int arg);

class A {
  public:
    bool Fn(int x);
    char header[0x10];
    char buf[0x40];
};

bool A::Fn(int x) {
    Log(buf, 0x40, "%s", x);
    return true;
}
