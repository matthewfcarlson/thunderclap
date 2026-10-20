unsigned __int64 __cdecl FUN_0027b020(void*);
class Obj {
  public:
    char pad[0x3f0];
    char field;
    unsigned __int64 Fn();
};
unsigned __int64 Obj::Fn() {
    return FUN_0027b020(&field);
}