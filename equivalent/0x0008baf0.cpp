// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0008baf0 @ 0x0008baf0
struct ThisWrap_0008baf0 {
    const char* FUN_0008abc0();
    void FUN_0008baf0(int* column, int* mode);
};
extern "C" int __cdecl FUN_00345804(const char*, const char*, ...);
void ThisWrap_0008baf0::FUN_0008baf0(int* column, int* mode) {
    const char* text = this->FUN_0008abc0();
    if (text && text[0] != '\0') {
        FUN_00345804(text, "c%dm%d", column, mode);
        return;
    }
    *column = 0;
    *mode = 0;
}
