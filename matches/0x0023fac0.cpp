struct Buf {
    short count;
};
extern char* gData;
class X {
  public:
    X();
    char* ptr;
    short mode;
    short pad;
    short value;
};
X::X() {
    ptr = gData;
    ++((short*)gData)[-2];
    value = 0;
    mode = 2;
}