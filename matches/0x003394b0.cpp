extern "C" void __cdecl copybytes(int, void*, int);
struct Buffer {
    char* pos;
    int count;
    int size;
    char data[512];
};
extern "C" void __cdecl flush(Buffer*);
void __cdecl FUN_003394b0(Buffer* b, const char* src, int n) {
    for (; n != 0; --n) {
        if (b->pos >= b->data + 512) {
            int len = b->pos - b->data;
            if (len != 0) {
                copybytes(b->size, b->data, len);
                b->pos = b->data;
                ++b->count;
                flush(b);
            }
        }
        *b->pos++ = *src++;
    }
}