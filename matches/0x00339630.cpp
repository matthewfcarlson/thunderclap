struct Thing_339630 {
    int* a;
    int b;
    int c;
};
extern "C" void FUN_00339630(int L, Thing_339630* buffer) {
    buffer->c = L;
    buffer->a = (int*)((char*)buffer + 12);
    buffer->b = 0;
}