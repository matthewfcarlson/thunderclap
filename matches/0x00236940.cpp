extern void __cdecl f1(void*, const char*);
extern void __cdecl f2(void*, const char*);
extern void __cdecl f3(void*, const char*);
extern void __cdecl f4(void*, const char*);
extern void __cdecl f5(void*, const char*);
extern void __cdecl f6(void*, const char*);
extern void __cdecl f7(void*, const char*);
extern void __cdecl f8(void*, const char*);
extern void __cdecl f9(void*, const char*);
extern void __cdecl f10(void*, const char*);
void __cdecl target(void* self, int unused) {
    f1(self, "comment");
    f2(self, "debug");
    f3(self, "false");
    f4(self, "or");
    f5(self, "not");
    f6(self, "platform");
    f7(self, "print");
    f8(self, "random");
    f9(self, "maybe");
    f10(self, "subConditionGroup");
}