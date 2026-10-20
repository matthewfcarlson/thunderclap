// STATUS: equivalent (tools/equiv.py level 3: 19610 inputs, branch coverage 4/4)
// FUN_00216f60 @ 0x00216f60
class Inner_216f60 {
  public:
    char pad[0x34];
    int value;
};
class Outer_216f60 {
  public:
    char pad[0x10];
    Inner_216f60* inner;
};
// equiv-conv: FUN_00216ed0 esi
void step(Outer_216f60*);
void f(Outer_216f60* p) {
    while (p->inner->value != 0)
        step(p);
}