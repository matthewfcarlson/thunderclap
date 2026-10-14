class C_47f10 {
    char pad[0x20];
    int m20, m24, m28;

  public:
    char Set(const void* p);
};
char C_47f10::Set(const void* p) {
    const int* q = (const int*)p;
    m20 = q[0];
    m24 = q[1];
    m28 = q[2];
    return 1;
}
