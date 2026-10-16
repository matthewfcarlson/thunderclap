void __cdecl Fn(char);
class Obj {
  public:
    int pad;
    void* ptr;
    void Check(void* p);
};
void Obj::Check(void* p) {
    if (ptr)
        Fn(p == 0);
}