extern "C" void* __cdecl memcpy(void*, const void*, unsigned);
class Object {
    char pad[0x30];

  public:
    void vfunc_6(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};
void Object::vfunc_6(int a0, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int) {
    memcpy((char*)this + 0x30, &a0, 0x40);
}