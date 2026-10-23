typedef unsigned int DWORD;
extern int __stdcall FUN_002109b6(DWORD, int);
extern DWORD __stdcall GetLastError();
class XboxSaveDrive_278a00 {
  public:
    char pad[0xb4];
    int error;
    int TranslateError(DWORD);
    bool Run(DWORD x, int* out);
};
bool XboxSaveDrive_278a00::Run(DWORD x, int* out) {
    int r = FUN_002109b6(x, 0);
    *out = r;
    if (r == -1) {
        error = TranslateError(GetLastError());
        return false;
    }
    return true;
}