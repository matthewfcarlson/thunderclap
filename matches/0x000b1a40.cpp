struct Cell {
    char pad[8];
    void Set(int, int);
};
class Obj {
  public:
    char pad[0xc];
    char flag;
    char rest[0x2f8 - 0xd];
    Cell cells[12];
    bool Fn(int a, int b, int c, int d);
};
bool Obj::Fn(int a, int b, int c, int d) {
    if (a < 0 || a >= 2 || b < 0 || b >= 2 || c < 0 || c >= 3)
        return false;
    cells[(a * 2 + b) * 3 + c].Set(0, d);
    flag = 1;
    return true;
}