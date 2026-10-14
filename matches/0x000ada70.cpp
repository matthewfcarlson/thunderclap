extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
class Obj_ada70 {
  public:
    char pad[0x18];
    int data[17];
    void Copy(void* out);
};
void Obj_ada70::Copy(void* out) {
    memcpy(out, data, 0x44);
}