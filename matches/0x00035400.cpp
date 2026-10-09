class Obj {
  public:
    char pad[0x9c];
    unsigned int a;
    unsigned int b;
    unsigned int c;
    bool Get(unsigned int* out);
};
bool Obj::Get(unsigned int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
    return true;
}