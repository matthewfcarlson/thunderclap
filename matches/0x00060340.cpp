class Obj {
  public:
    char pad[0x90];
    int a, b, c;
    char Set(void* p);
};

char Obj::Set(void* p) {
    int* q = (int*)p;
    a = q[0];
    b = q[1];
    c = q[2];
    return 1;
}
