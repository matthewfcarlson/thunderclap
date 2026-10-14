class C_79950 {
    char pad[0x374c];
    void* arr[1];
    int lookup(int);

  public:
    bool f(int);
};
bool C_79950::f(int x) {
    int i = lookup(x);
    if (i == -1)
        return false;
    return *(int*)((char*)arr[i] + 0x10) != 0x13;
}