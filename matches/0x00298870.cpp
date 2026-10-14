struct Entry_298870 {
    char pad[8];
    void* p;
};
class Obj_298870 {
  public:
    char pad00[0x20];
    unsigned char count;
    char pad21[3];
    unsigned char* out;
    char pad28[8];
    unsigned char* other;
    char pad34[8];
    Entry_298870* entries;
    Entry_298870* end;
    void Run();
};
void Obj_298870::Run() {
    unsigned char* c = &count;
    *c = 0;
    unsigned int n = end - entries;
    for (unsigned int i = 0; i < n; ++i) {
        if (entries[i].p) {
            out[i] = count;
            other[count] = (unsigned char)i;
            ++count;
        } else {
            out[i] = 0xff;
            other[i] = 0xff;
        }
    }
}
