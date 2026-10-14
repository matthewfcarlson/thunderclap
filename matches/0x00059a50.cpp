struct Data_59a50 {
    char pad[0x40];
    unsigned a, b, c;
};
struct Out_59a50 {
    unsigned a, b, c;
};
class Obj_59a50 {
  public:
    char pad[4];
    unsigned a;
    unsigned b;
    unsigned c;
    char pad2[8];
    Data_59a50* p;
    bool Get(Out_59a50* out);
};
bool Obj_59a50::Get(Out_59a50* out) {
    Data_59a50* d = p;
    if (d) {
        out->a = d->a;
        out->b = d->b;
        out->c = d->c;
        return true;
    }
    out->a = a;
    out->b = b;
    out->c = c;
    return true;
}