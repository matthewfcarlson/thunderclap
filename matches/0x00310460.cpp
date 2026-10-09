class C {
  public:
    char pad[0x1fc];
    void** arr;
    bool f(int index, char value);
};
bool C::f(int index, char value) {
    char* p = (char*)arr[index];
    if (p && p[4] != value)
        p[4] = value;
    return false;
}