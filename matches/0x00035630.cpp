struct Cache {
    void* get();
};
struct Result {
    void run(unsigned int, unsigned int);
};
struct Owner {
    char pad[16];
    Cache* p;
    bool target(unsigned int a, unsigned int b);
};
bool Owner::target(unsigned int a, unsigned int b) {
    void* x = p->get();
    if (!x)
        return false;
    ((Result*)((char*)x + 16))->run(a, b);
    return true;
}