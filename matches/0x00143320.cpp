class Obj_143320 {
  public:
    char pad[0x18];
    int a;
    int b;
    int c;
    char Set(const int* p);
};
char Obj_143320::Set(const int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    return 1;
}
