class Item { public: char pad[0x74]; int value; };
class Param { public: char pad[0x12c]; Item* first; Item* second; };
class Context { public: void call(int); };
class Target { public: char pad[8]; Context* context; bool f(Param* p); };
bool Target::f(Param* p) {
    int a = 0;
    if (p->first) a = p->first->value;
    if (p->second && p->second->value) context->call(p->second->value);
    if (a) context->call(a);
    return true;
}