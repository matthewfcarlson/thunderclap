extern "C" void* memcpy(void*, const void*, unsigned int);
extern char* gPointer;
extern char gZero_240110;
class Obj_240110 {
  public:
    void consume(const char*);
};
struct Source_240110 {
    char* data;
    char pad[4];
    unsigned short length;
};
void __cdecl FUN_00240110(Obj_240110* obj, Source_240110* src, unsigned int n) {
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
        data = &gZero_240110;
    memcpy(local, data + offset, n);
    obj->consume(local);
}