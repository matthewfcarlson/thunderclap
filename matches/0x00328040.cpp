extern "C" void* __cdecl Alloc(unsigned int size);
class Obj {
  public:
    void* Fn(void* arg);
};
void* Target(void* self) {
    void* p = Alloc(0xec);
    if (p)
        return ((Obj*)p)->Fn(self);
    return 0;
}
