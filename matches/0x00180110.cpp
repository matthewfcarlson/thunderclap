class Obj {
  public:
    char pad[0x78];
    void* Get() throw();
};

void* Obj::Get() throw() {
    return (void*)((char*)this + 0x78);
}
