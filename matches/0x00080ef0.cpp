class C {
    char pad[0xbc];

  public:
    void Set(int);
};
void C::Set(int x) {
    *(int*)(pad + 0xbc) = x;
}