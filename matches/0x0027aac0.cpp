typedef unsigned char bool8;
class Obj {
  public:
    char pad[0x10];
    int index;
    bool8 Check(int);
    bool8 Target(int, int*);
};
bool8 Obj::Target(int a, int* out) {
    if (Check(a)) {
        *out = index * 0x60 + (int)this + 0xd38;
        return 1;
    }
    *out = 0;
    return 0;
}