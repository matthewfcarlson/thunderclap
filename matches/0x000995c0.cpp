struct Data {
    char a[0x254];
    int x;
    char b[0x70];
    int y;
    char flag;
};
class Obj {
    char a[0xc4];
    Data* d;

  public:
    void Set(int x, int y, char flag);
};
void Obj::Set(int x, int y, char flag) {
    d->x = x;
    d->y = y;
    d->flag = flag;
}