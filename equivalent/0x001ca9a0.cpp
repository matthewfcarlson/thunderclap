// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ca9a0 @ 0x001ca9a0
struct Arg { unsigned value; void FUN_0027af50(); };
struct Result { unsigned size, kind, unused8, unusedC, unused10, unused14; Arg first; unsigned second; Arg third; unsigned fourth; Result* FUN_001ca9a0(Arg a, unsigned b, Arg c, unsigned d); };
Result* Result::FUN_001ca9a0(Arg a, unsigned b, Arg c, unsigned d)
{
 size=0; kind=0; unused8=0; unusedC=0; unused10=0; unused14=0; first.value=0; second=0; third.value=0; fourth=0;
 first=a; second=b; third=c; fourth=d; size=0x28; kind=0x16;
 a.FUN_0027af50(); c.FUN_0027af50();
 return this;
}