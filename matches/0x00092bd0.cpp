class C {
    char pad[0xd88];

  public:
    void Set(int value);
};
void C::Set(int value) {
    *(int*)(pad + 0xd88) = value;
}