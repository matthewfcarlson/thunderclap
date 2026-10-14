class C_10b580 {
    char pad[0x1b78];

  public:
    void F(const unsigned int* p);
};
void C_10b580::F(const unsigned int* p) {
    *(unsigned int*)(pad + 0x1b78) = p[0];
    *(unsigned int*)(pad + 0x1b7c) = p[1];
    *(unsigned int*)(pad + 0x1b80) = p[2];
}