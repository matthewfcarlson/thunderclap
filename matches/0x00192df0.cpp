// cl-flags: /O2
class C {
  public:
    char Set(const void* p);
    char pad[0x100];
    char m100[4];
    char m104[4];
    char m108[4];
};

char C::Set(const void* p) {
    const unsigned int* q = (const unsigned int*)p;
    *(unsigned int*)m100 = q[0];
    *(unsigned int*)m104 = q[1];
    *(unsigned int*)m108 = q[2];
    return 1;
}
