struct E {
    char b[16];
};
extern "C" void* __cdecl Alloc(unsigned int);
extern "C" void __cdecl Init(void*, unsigned int, void*);
class Buffer {
  public:
    E* data;
    E* end;
    char Create(unsigned int count, void* arg);
};
char Buffer::Create(unsigned int count, void* arg) {
    if (data)
        return 0;
    if (count > 0) {
        data = (E*)Alloc(count * sizeof(E));
        if (data) {
            end = data + count;
            Init(data, count, arg);
            return 1;
        }
    }
    data = 0;
    end = 0;
    return 0;
}
