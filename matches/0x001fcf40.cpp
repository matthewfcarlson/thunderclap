class C { public: char pad[0x20c]; int count; void* buffer; int foo(); };
extern void __fastcall FUN_001fb970(void*);
int C::foo() {
    int result = 0;
    if (count < 256) {
        char* p = (char*)buffer + (count << 6);
        FUN_001fb970(p);
        ++count;
        result = (int)p;
    }
    return result;
}