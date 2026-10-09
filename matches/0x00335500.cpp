struct C { char pad[8]; int type; };
struct B { char pad[0x44]; int count; C* lookup(int); };
struct A { char pad[4]; B* b; unsigned int* values; bool run(int index, unsigned int* out); };
bool A::run(int index, unsigned int* out) {
    if (index < 0) return false;
    if (index >= b->count) return false;
    if (b->lookup(index)->type != 2) return false;
    *out = values[index];
    return true;
}