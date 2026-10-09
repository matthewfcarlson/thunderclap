class C {
    char pad[0x1b78];

  public:
    void F(const unsigned int* p);
};
void C::F(const unsigned int* p) {
    *(unsigned int*)(pad + 0x1b78) = p[0];
    *(unsigned int*)(pad + 0x1b7c) = p[1];
    *(unsigned int*)(pad + 0x1b80) = p[2];
}