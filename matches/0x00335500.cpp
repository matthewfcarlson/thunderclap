struct C_335500 {
    char pad[8];
    int type;
};
struct B_335500 {
    char pad[0x44];
    int count;
    C_335500* lookup(int);
};
struct A_335500 {
    char pad[4];
    B_335500* b;
    unsigned int* values;
    bool run(int index, unsigned int* out);
};
bool A_335500::run(int index, unsigned int* out) {
    if (index < 0)
        return false;
    if (index >= b->count)
        return false;
    if (b->lookup(index)->type != 2)
        return false;
    *out = values[index];
    return true;
}