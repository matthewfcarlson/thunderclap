int __cdecl FUN_0027b020(void*);
class Obj {
  public:
    char pad[0x3f0];
    char field;
    int Fn();
};
int Obj::Fn() {
    return FUN_0027b020(&field);
}