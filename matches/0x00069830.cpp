extern "C" void __cdecl FUN_00267830(void*, void*, int);
class X {
  public:
    char pad[16];
    char data[64];
    bool Fn(void* p);
};
bool X::Fn(void* p) {
    FUN_00267830(data, p, 64);
    return true;
}