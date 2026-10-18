class Helper_236790 {
    char pad[0x18];

  public:
    Helper_236790(void*);
    int Run(int, int);
};
class Target_236790 {
  public:
    char pad[0x14];
    int F(int a, int b);
};
int Target_236790::F(int a, int b) {
    Helper_236790 h((char*)this + 0x14);
    return h.Run(a, b);
}