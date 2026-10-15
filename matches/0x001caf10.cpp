extern "C" void* __cdecl memset(void*, int, unsigned int);
class X {
  public:
    X(int);
    int a[6];
};
X::X(int v) {
    memset(a, 0, 24);
    a[0] = 0x18;
    a[1] = 0x1c;
    a[5] = v;
}