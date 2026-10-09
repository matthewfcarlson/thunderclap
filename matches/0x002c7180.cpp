class Obj {
  public:
    char pad0[8];
    unsigned int flags;
    char padc[4];
    void* ptr;
    void Clear();
};
void thunk_FUN_00267090(void*);
void Obj::Clear() {
    thunk_FUN_00267090(ptr);
    ptr = 0;
    flags &= 0xffffffef;
}