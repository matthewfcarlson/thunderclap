struct E_2b1330 {
    char b[16];
};
extern "C" void* __cdecl Alloc(unsigned int);
extern "C" void __cdecl Init(void*, unsigned int, void*);
class Buffer_2b1330 {
  public:
    E_2b1330* data;
    E_2b1330* end;
    char Create(unsigned int count, void* arg);
};
char Buffer_2b1330::Create(unsigned int count, void* arg) {
    if (data)
        return 0;
    if (count > 0) {
        data = (E_2b1330*)Alloc(count * sizeof(E_2b1330));
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
