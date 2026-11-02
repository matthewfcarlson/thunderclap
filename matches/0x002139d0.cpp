struct Pair {
    int a;
    int b;
};
void process(void*, int, int);
extern "C" void __cdecl FUN_002139d0(void* p, Pair* q) {
    process(p, q->a, q->b);
}