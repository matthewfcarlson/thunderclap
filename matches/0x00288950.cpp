class C_288950 {
  public:
    char pad[0x18];
    int* p;
    int Get(int index);
};
int C_288950::Get(int index) {
    return p[index];
}