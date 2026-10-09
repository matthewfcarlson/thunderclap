typedef unsigned char u8;
class Thing {
  public:
    char pad[0x88];
};
extern void __cdecl Helper(void*);
void __fastcall Target(Thing* self, void*, u8 value) {
    self->pad[0x88] = value;
    Helper((char*)self + 0x84);
}