// Same code shape as 0x00091d20 (propagated; names are from that function)
class C_262f60 {
  public:
    char pad[0x28];
    char* f();
};
char* C_262f60::f() {
    return (char*)this + 0x28;
}