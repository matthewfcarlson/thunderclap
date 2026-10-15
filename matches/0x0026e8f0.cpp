struct Args {
    int a;
    int b;
    char rest[20];
};
class Obj {
    char pad[0xa0];
    int flag;

  public:
    void Fn(int x);
    void Go(Args*);
};
void Obj::Fn(int x) {
    Args a;
    if (flag) {
        a.a = 0;
        a.b = x;
        Go(&a);
    }
}