extern char G100[], G10c[], G134[];
char Lookup(char*);
class Base {
  public:
    Base(int, int);
    virtual void X();
    char pad[0xc];
};
class M3 : public Base {
  public:
    virtual void X();
    char b10, b11, b12, pad2[5];
    char b18;
    char pad3[3];
    int m1c;
    M3(int a, int c);
};
M3::M3(int a, int c) : Base(a, 3) {
    m1c = c;
    b18 = Lookup(G100);
    b10 = Lookup(G134);
    b11 = Lookup(G134);
    b12 = Lookup(G10c);
}
