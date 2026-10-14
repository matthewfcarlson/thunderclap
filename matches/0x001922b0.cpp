class Obj {
  public:
    char pad[0x4c];
    int a;
    int b;
    int c;
    unsigned char Fn(int* src);
};

unsigned char Obj::Fn(int* src) {
    a = src[0];
    b = src[1];
    c = src[2];
    return 1;
}