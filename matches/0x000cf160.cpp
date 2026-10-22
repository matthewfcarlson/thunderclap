extern char G100_cf160[], G10c[], G134[];
char Lookup(char*);
class Function_cf160 {
  public:
    Function_cf160(int, int);
    virtual void X();
    char pad[0xc];
};
class Method3_cf160 : public Function_cf160 {
  public:
    virtual void X();
    char b10, b11, b12, pad2[5];
    char b18;
    char pad3[3];
    int m1c;
    Method3_cf160(int a, int c);
};
Method3_cf160::Method3_cf160(int a, int c) : Function_cf160(a, 3) {
    m1c = c;
    b18 = Lookup(G100_cf160);
    b10 = Lookup(G134);
    b11 = Lookup(G134);
    b12 = Lookup(G10c);
}
