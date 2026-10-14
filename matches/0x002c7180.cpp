class Obj_2c7180 {
  public:
    char pad0[8];
    unsigned int flags;
    char padc[4];
    void* ptr;
    void Clear();
};
void thunk_FUN_00267090(void*);
void Obj_2c7180::Clear() {
    thunk_FUN_00267090(ptr);
    ptr = 0;
    flags &= 0xffffffef;
}