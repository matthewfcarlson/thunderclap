class Thing {
public:
    char pad[0x80];
    unsigned int a;
    unsigned int b;
    unsigned int c;
    bool Get(unsigned int* out);
};
bool Thing::Get(unsigned int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
    return true;
}