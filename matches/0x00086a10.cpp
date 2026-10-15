struct State {
    int value;
};
struct First {
    void f();
};
struct Second {
    void g();
};
struct A {
    char pad[0x10];
    First* first;
    char pad2[4];
    Second* second;
};
struct Root {
    char pad[0x54];
    A* a;
};
extern Root* globalRoot;
class Obj {
  public:
    char pad[4];
    State* state;
    void run();
};
void Obj::run() {
    State* s = state;
    if (s->value == 4) {
        s->value = 1;
        globalRoot->a->first->f();
        globalRoot->a->second->g();
    }
}