class Obj {
    char pad[0x620];
    int vals[0x800][10];

  public:
    int get(int);
};
int Obj::get(int i) {
    if (i >= 0 && i < 0x800)
        return vals[i][0];
    return 0;
}