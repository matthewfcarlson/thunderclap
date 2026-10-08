extern int gBase;
extern int gResult;
void __stdcall target(int value) { gResult = gBase + value; }