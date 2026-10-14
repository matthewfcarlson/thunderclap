extern "C" void __cdecl Format(char*, unsigned int, const char*, const char*);
class Obj_899d0 {
  public:
    char before[0x138];
    char pad[0x20];
    void Set(const char*);
};
void Obj_899d0::Set(const char* p) {
    if (p)
        Format(pad, 0x20, "%s", p);
}