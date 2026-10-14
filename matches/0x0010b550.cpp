class Obj {
  public:
    char pad[0x1b78];
    int a;
    int b;
    int c;
    void Get(int* out);
};
void Obj::Get(int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
}
