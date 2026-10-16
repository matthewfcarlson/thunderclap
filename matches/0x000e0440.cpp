class Obj {
    char pad[0x1850];

  public:
    int value;
    int* Get(int* out);
};
int* Obj::Get(int* out) {
    *out = value;
    return out;
}