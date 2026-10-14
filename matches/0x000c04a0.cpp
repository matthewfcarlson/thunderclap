class B_c04a0 {
  public:
    int G();
};
class A_c04a0 {
  public:
    char pad[4];
    B_c04a0* p;
    int Fn(int a, int b);
};
int A_c04a0::Fn(int a, int b) {
    B_c04a0* q = p;
    if (q == 0)
        return -1;
    q->G();
    return 0;
}
