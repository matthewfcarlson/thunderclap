struct V {
    int a;
    int b;
    int c;
};
class T_602d0 {
  public:
    char Pad[0x6c];
    int m6c;
    int m70;
    int m74;
    char Set(V* v);
};
char T_602d0::Set(V* v) {
    m6c = v->a;
    m70 = v->b;
    m74 = v->c;
    return 1;
}