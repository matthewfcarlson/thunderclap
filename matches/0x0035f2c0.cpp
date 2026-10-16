extern "C" __int64 __cdecl lookup(const char*, int, int);
extern "C" __int64 result;
void init() {
    result = lookup("HalSystem", 0, 0);
}