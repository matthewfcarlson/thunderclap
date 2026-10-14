struct Data_17fe20 {
    int a;
    int b;
    int c;
};
class Obj_17fe20 {
  public:
    char pad[0x68];
    Data_17fe20 d;
    bool Set(Data_17fe20* src);
};
bool Obj_17fe20::Set(Data_17fe20* src) {
    d.a = src->a;
    d.b = src->b;
    d.c = src->c;
    return true;
}
