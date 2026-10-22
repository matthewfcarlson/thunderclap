extern char G100_1f1050[], G49[], G128[];
char Lookup(char*);
class Function_1f1050 {
  public:
    Function_1f1050(int, int);
    virtual void X();
    char pad[0xc];
};
class Method3_1f1050 : public Function_1f1050 {
  public:
    virtual void X();
    char b10, b11, b12, pad2[5];
    char b18;
    char pad3[3];
    int m1c;
    Method3_1f1050(int a, int c);
};
Method3_1f1050::Method3_1f1050(int a, int c) : Function_1f1050(a, 3) {
    m1c = c;
    b18 = Lookup(G100_1f1050);
    b10 = Lookup(G49);
    b11 = Lookup(G128);
    b12 = Lookup(G128);
}
