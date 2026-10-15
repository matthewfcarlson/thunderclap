struct Elem {
    char pad[0xc0];
    void Fn();
};
struct Count {
    char pad[0x10];
    int n;
};
class Obj {
    char pad[8];
    Count* count;
    Elem* elems;

  public:
    void Fn();
};
void Obj::Fn() {
    int n;
    if (count == 0)
        n = 0;
    else
        n = count->n;
    for (int i = 0; i < n; ++i)
        elems[i].Fn();
}