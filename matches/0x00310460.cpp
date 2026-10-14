class C_310460 {
  public:
    char pad[0x1fc];
    void** arr;
    bool f(int index, char value);
};
bool C_310460::f(int index, char value) {
    char* p = (char*)arr[index];
    if (p && p[4] != value)
        p[4] = value;
    return false;
}