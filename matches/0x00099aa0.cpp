class Child { public: int probe(); void run(int a, int b); };
class Obj { public: char pad[0xb8]; Child* member; void f(int x); };
extern int gValue;
void Obj::f(int x) {
  if (member != 0) {
    int v = member->probe();
    if (v != 0 && x == v) member->run(gValue, x);
  }
}
