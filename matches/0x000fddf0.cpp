class C {
    char pad[0x74];

  public:
    void F(void* a, unsigned* b);
};
void C::F(void* a, unsigned* b) {
    *(void**)(pad + 0x74) = a;
    if (!a) {
        *(unsigned*)(pad + 0x78) = b[0];
        *(unsigned*)(pad + 0x7c) = b[1];
        *(unsigned*)(pad + 0x80) = b[2];
    }
}