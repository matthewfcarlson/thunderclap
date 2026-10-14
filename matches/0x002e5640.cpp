struct E_2e5640 {
    char b[16];
};
extern "C" void* __cdecl Alloc(unsigned int);
extern "C" void __cdecl Init(void*, unsigned int, void*);
class Buffer_2e5640 {
  public:
    E_2e5640* data;
    E_2e5640* end;
    char Create(unsigned int count, void* arg);
};
char Buffer_2e5640::Create(unsigned int count, void* arg) {
    if (data)
        return 0;
    if (count > 0) {
        data = (E_2e5640*)Alloc(count * sizeof(E_2e5640));
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
