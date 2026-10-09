class Bc { public: void run(int); };
class B0 { public: void run(int); };
class B4 { public: void run(int); };
class Bd { public: void run(int); };
class A {
public:
  B0* p0; B4* p4; char p8[4]; Bc* pc; char p10[4]; Bd* p14; Bd* p18;
  char pad[0x52];
  unsigned char enabled;
  void go(int x);
};
void A::go(int x) {
  if (enabled) {
    pc->run(x);
    p0->run(x);
    p4->run(x);
    p18->run(x);
    p14->run(x);
  }
}
