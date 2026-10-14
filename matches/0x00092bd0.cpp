class C_92bd0 {
    char pad[0xd88];

  public:
    void Set(int value);
};
void C_92bd0::Set(int value) {
    *(int*)(pad + 0xd88) = value;
}