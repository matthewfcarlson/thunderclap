extern "C" void* memcpy(void*, const void*, unsigned int);
extern char* gPointer;
extern char gZero;
class Obj {
  public:
    void consume(const char*);
};
struct Source {
    char* data;
    char pad[4];
    unsigned short length;
};
void __cdecl FUN_00240110(Obj* obj, Source* src, unsigned int n) {
    __declspec(align(8)) char local[256];
    unsigned int len = src->length;
    unsigned int offset;
    if (len < n) {
        offset = 0;
        n = len + 1;
    } else {
        offset = len - n + 1;
    }
    char* data = src->data;
    if (data == gPointer)
        data = &gZero;
    memcpy(local, data + offset, n);
    obj->consume(local);
}