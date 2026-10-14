class C_36c90 {
    char pad[0x1e04];

  public:
    void Set(unsigned int index, unsigned int value);
};
void C_36c90::Set(unsigned int index, unsigned int value) {
    if (index < 0x10)
        *(unsigned int*)(pad + 0x1e04 + index * 4) = value;
}