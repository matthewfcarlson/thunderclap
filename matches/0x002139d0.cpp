struct Pair {
    int a;
    int b;
};
void process(void*, int, int);
void __cdecl target(void* p, Pair* q) {
    process(p, q->a, q->b);
}