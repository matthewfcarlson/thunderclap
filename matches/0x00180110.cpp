class Obj_180110 {
  public:
    char pad[0x78];
    void* Get() throw();
};

void* Obj_180110::Get() throw() {
    return (void*)((char*)this + 0x78);
}
