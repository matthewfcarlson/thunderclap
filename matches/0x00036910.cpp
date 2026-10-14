class C_36910 {
    char pad[0x12c];

  public:
    void f(unsigned char x);
};
void C_36910::f(unsigned char x) {
    int p = *(int*)((char*)this + 0x12c);
    if (p && *(int*)(p + 0x74))
        *(unsigned char*)(*(int*)(p + 0x74) + 0x72) = x;
}