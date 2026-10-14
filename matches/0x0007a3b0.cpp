struct Cell_7a3b0 {
    int a;
    int b;
    char pad[0x1c];
    char flag;
    char pad2[0x23];
};
class G_7a3b0 {
  public:
    char pad[0x1924];
    Cell_7a3b0 cells[1];
    void Fn(int x, int y, int* o1, int* o2);
};
void G_7a3b0::Fn(int x, int y, int* o1, int* o2) {
    int i = x * 0xe + y;
    int a = cells[i].a;
    int b = cells[i].b;
    if (a != -1 && b != -1 && *((char*)&cells[0] + (a * 0xe + b) * 0x48 + 0x24) != 0) {
        *o1 = a;
        *o2 = b;
        return;
    }
    *o1 = -1;
    *o2 = -1;
}
