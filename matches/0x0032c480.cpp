class Obj_32c480 {
  public:
    char pad[0x88];
    void Set(void* p);
};
void Obj_32c480::Set(void* p) {
    *(void**)((char*)this + 0x88) = p;
}
