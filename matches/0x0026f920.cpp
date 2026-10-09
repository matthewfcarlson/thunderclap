typedef unsigned int U;
U __stdcall ReadA(U, U, U, U);
U __stdcall ReadB(U, U, U, U, U);
U __stdcall GetLastError();
class XboxDrive {
    char pad[0xb4];

  public:
    U mError;
    U ConvertError(U);
    U Run(U, U, U, U, U, U, U*, U);
};
U XboxDrive::Run(U p2, U p3, U p4, U p5, U p6, U p7, U* p8, U unused) {
    U r = ReadA(p2, p5, 0, 0);
    if (r == p5)
        if (ReadB(p2, p6, p7, (U)p8, 0)) {
            *p8 = p7;
            mError = 0;
            return 1;
        }
    mError = ConvertError(GetLastError());
    return 0;
}