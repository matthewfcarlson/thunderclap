class Obj {
  public:
    char pad[0x8c];
    Obj* p;
    int action(int, int);
    int fn(int, int);
};
int Obj::fn(int a, int b) {
    int result = -1;
    Obj* q = p;
    if (q)
        result = q->action(a, b);
    return result;
}