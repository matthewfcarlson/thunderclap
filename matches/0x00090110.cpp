extern int __stdcall FindThing(const char*);
int __fastcall Target(void* self) {
    int i = FindThing("xp");
    if (i == -1)
        return 0;
    return *(int*)((char*)self + i * 0x40 + 0x38);
}