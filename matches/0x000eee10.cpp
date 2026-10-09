class Widget { public:
#define V(n) virtual int v##n();
V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57)
virtual int get(int);
int h(int);
void h2(int);
};
class FEContainer { public:
#define F(n) virtual int f##n();
F(0) F(1) F(2) F(3) F(4) F(5) F(6) F(7) F(8) F(9) F(10) F(11) F(12) F(13) F(14) F(15) F(16) F(17) F(18) F(19) F(20) F(21) F(22) F(23) virtual int f24(int,int); F(25) F(26) F(27) F(28) F(29) virtual int f30(int,int); F(31) F(32) F(33) F(34) F(35) F(36) F(37) F(38) F(39) F(40) virtual int f41(int); F(42) F(43) F(44) F(45) F(46) F(47) F(48) F(49) F(50) F(51) F(52)
Widget *child;
};
int FEContainer::f30(int b, int a) {
  int x = child->get(b);
  f24(x, b);
  if (a) {
    int y = f41(a);
    if (!y) y = child->h(a);
    if (y) ((Widget*)x)->h2(y);
  }
  return x;
}
