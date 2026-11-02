struct ThisCall_00090050 {
    int FindThing(const char*);
};
extern "C" int __fastcall FUN_00090110(void* self) {
    int i = ((ThisCall_00090050*)(self))->FindThing("xp");
    if (i == -1)
        return 0;
    return *(int*)((char*)self + i * 0x40 + 0x38);
}