class Obj {
  public:
    unsigned char Check(void*);
    void* Find(__int64);
};
extern __int64 __cdecl Convert(void*);
class Other {
  public:
    unsigned char Valid();
};
unsigned char Obj::Check(void* p) {
    __int64 x = Convert(p);
    Other* o = (Other*)Find(x);
    if (!o)
        return 0;
    return o->Valid();
}