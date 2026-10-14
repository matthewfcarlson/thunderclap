class Item_1b4140 {
  public:
    char pad[0x74];
    int value;
};
class Param {
  public:
    char pad[0x12c];
    Item_1b4140* first;
    Item_1b4140* second;
};
class Context {
  public:
    void call(int);
};
class Target_1b4140 {
  public:
    char pad[8];
    Context* context;
    bool f(Param* p);
};
bool Target_1b4140::f(Param* p) {
    int a = 0;
    if (p->first)
        a = p->first->value;
    if (p->second && p->second->value)
        context->call(p->second->value);
    if (a)
        context->call(a);
    return true;
}