class C_80ef0 {
    char pad[0xbc];

  public:
    void Set(int);
};
void C_80ef0::Set(int x) {
    *(int*)(pad + 0xbc) = x;
}