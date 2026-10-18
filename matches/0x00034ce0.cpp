typedef __int64 I64;
extern "C" I64 __cdecl convert(const char*, int, int);
class Obj {
  public:
    int take(I64);
    int target(const char*);
};
int Obj::target(const char* s) {
    return take(convert(s, 0, 0));
}