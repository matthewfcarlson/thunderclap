class Item {
  public:
    int Fn(int, int);
};
class Obj {
    char pad[0x88];
    Item* p;

  public:
    int Go(int a, int b);
};
int Obj::Go(int a, int b) {
    int result = -1;
    Item* q = p;
    if (q)
        result = q->Fn(a, b);
    return result;
}