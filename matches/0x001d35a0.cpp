extern "C" unsigned int __cdecl strlen(const char*);
class Obj_1d35a0 {
  public:
    char pad[4];
    int state;
    int handle;
    int Func(const char* text, int x, int len);
    int Do(int h, const char* text, int len, int x);
};
void __cdecl Init(int, int);
int Obj_1d35a0::Func(const char* text, int x, int len) {
    Init(handle, 0);
    if (len == -1)
        len = strlen(text);
    int result = 3;
    if (Do(handle, text, len, x))
        result = 0;
    state = result;
    return result;
}