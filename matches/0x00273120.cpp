typedef unsigned char u8_273120;
class Thing_273120 {
  public:
    char pad[0x88];
};
extern void __cdecl Helper(void*);
void __fastcall Target(Thing_273120* self, void*, u8_273120 value) {
    self->pad[0x88] = value;
    Helper((char*)self + 0x84);
}