struct S_17fd80 {
    int a, b, c;
};
class C_17fd80 {
  public:
    char Pad[0x38];
    int v38;
    int v3c;
    int v40;
    char Set(S_17fd80* p);
};
char C_17fd80::Set(S_17fd80* p) {
    S_17fd80* q = p;
    v38 = q->a;
    v3c = q->b;
    v40 = q->c;
    return 1;
}