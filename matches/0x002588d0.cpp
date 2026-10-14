extern const char TypeName[];
void __cdecl RegisterType(const char*, void*, void*);

class Type {
  public:
    virtual void V0();
    virtual void V1();
    char pad[0x2c];
};

void Type::V0() {
    RegisterType(TypeName, this, (char*)this + 0x30);
}