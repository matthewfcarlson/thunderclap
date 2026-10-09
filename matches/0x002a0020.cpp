class Worker { public: int get(); };
class Thing { public: char pad[0x44]; Worker* member; void f(int a, int b); void apply(int x, int a, int b); };
void Thing::f(int a, int b) { int x = member->get(); apply(x, a, b); }