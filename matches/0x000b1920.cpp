extern "C" void CopyBytes(void*, const void*, unsigned int);
struct Elem {
    int n;
    char* p;
    void Init(int);
};
class Obj {
  public:
    char pad[12];
    char flag;
    char pad2[0x103];
    Elem elems[11];
    bool Set(int index, const void* src, int slot);
};
bool Obj::Set(int index, const void* src, int slot) {
    if (index < 0 || index >= 11)
        return false;
    Elem* e = &elems[index];
    if (e->n <= 0)
        e->Init(1);
    CopyBytes(e->p + slot * 32, src, 32);
    flag = 1;
    return true;
}