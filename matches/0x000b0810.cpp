extern char zero;
class Obj {
  public:
    char pad[0x110];
    struct E {
        int count;
        int base;
    } e[11];
    char* get(int a, int b);
};
char* Obj::get(int a, int b) {
    if (a < 0 || a >= 11)
        return &zero;
    if (b >= 0 && b < e[a].count)
        return (char*)e[a].base + b * 32;
    return &zero;
}