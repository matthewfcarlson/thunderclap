extern "C" int FUN_00267760(void* buf, int size, const char* fmt, ...);

class A_69730 {
  public:
    bool Fn(int x);
    char header[0x10];
    char buf[0x40];
};

bool A_69730::Fn(int x) {
    FUN_00267760(buf, 0x40, "%s", x);
    return true;
}
