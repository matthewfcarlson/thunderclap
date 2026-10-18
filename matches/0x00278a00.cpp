typedef unsigned int DWORD;
extern int __stdcall FindThing(DWORD, int);
extern DWORD __stdcall GetLastError();
class Obj_278a00 {
  public:
    char pad[0xb4];
    int error;
    int TranslateError(DWORD);
    bool Run(DWORD x, int* out);
};
bool Obj_278a00::Run(DWORD x, int* out) {
    int r = FindThing(x, 0);
    *out = r;
    if (r == -1) {
        error = TranslateError(GetLastError());
        return false;
    }
    return true;
}