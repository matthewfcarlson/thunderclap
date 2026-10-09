class Object {
  public:
    char pad[0xaec];
    void* member;
};
extern "C" int __fastcall FUN_002666f0(void*);
int __fastcall FUN_00203840(Object* self) {
    if (self->member)
        return FUN_002666f0(self->member);
    return 0;
}