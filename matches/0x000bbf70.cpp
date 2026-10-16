class Dest {
  public:
    void Fn(int);
};
class Obj {
  public:
    int pad;
    Dest* p;
    int Run(int n, int* v);
};
int Obj::Run(int n, int* v) {
    Dest* q = p;
    if (!q)
        return -1;
    if (n != 1)
        return -1;
    q->Fn(*v);
    return 0;
}