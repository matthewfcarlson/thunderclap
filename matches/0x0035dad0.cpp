extern "C" unsigned long long __cdecl FUN_0027b020(const char* name);
extern void* gCursorLocators[2];

void FUN_0035dad0() {
    unsigned long long r = FUN_0027b020("TextInputCursorLocators");
    gCursorLocators[0] = (void*)((unsigned int)r);
    gCursorLocators[1] = (void*)((unsigned int)(r >> 32));
}
