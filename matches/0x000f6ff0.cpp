extern "C" void* __cdecl allocbuf(int);
extern "C" void __cdecl freebuf(void*);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
class Buffer {
  public:
    void* data;
    int capacity;
    int size;
    void Reserve(int n);
};
void Buffer::Reserve(int n) {
    if (n > capacity) {
        void* old = data;
        void* fresh = allocbuf(n * 2);
        data = fresh;
        if (old) {
            memcpy(fresh, old, size * 2);
            freebuf(old);
        }
        capacity = n;
    }
}