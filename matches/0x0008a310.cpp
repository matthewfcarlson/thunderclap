class C {
    char pad[0xd0];
    int a;
    int b;

  public:
    int* F();
};
int* C::F() {
    if (a == -1)
        return 0;
    if (b == -1)
        return 0;
    return (int*)((char*)this + 0xd8);
}