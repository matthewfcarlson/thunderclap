class Obj {
  public:
    char pad[0x88];
    void Set(void* p);
};
void Obj::Set(void* p) {
    *(void**)((char*)this + 0x88) = p;
}
