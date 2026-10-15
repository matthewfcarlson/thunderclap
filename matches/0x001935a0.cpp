class Obj {
  public:
    char pad[0xf0];
    int a;
    int b;
    int c;
    char Copy(int* p);
};
char Obj::Copy(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    return 1;
}
