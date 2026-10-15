struct Data {
    char pad[0x2b0];
    int a, b, c, d;
};
class Obj {
    char pad[0xc4];
    Data* data;

  public:
    void Set(int a, int b, int c, int d);
};
void Obj::Set(int a, int b, int c, int d) {
    data->a = a;
    data->b = b;
    data->c = c;
    data->d = d;
}