extern int Log(void* buf, int size, const char* fmt, int arg);

class A_69730 {
  public:
    bool Fn(int x);
    char header[0x10];
    char buf[0x40];
};

bool A_69730::Fn(int x) {
    Log(buf, 0x40, "%s", x);
    return true;
}
