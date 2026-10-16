typedef __int64 I64;
extern "C" I64 __cdecl convert(const char*, int, int);
class Obj {
  public:
    void take(I64);
    void target(const char*);
};
void Obj::target(const char* s) {
    take(convert(s, 0, 0));
}