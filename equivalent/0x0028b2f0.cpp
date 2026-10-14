// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0028b2f0 @ 0x0028b2f0
struct Source_28b2f0 { void FUN_0028ad20(int index, unsigned int* result); };
unsigned int* __cdecl FUN_0028b2f0(unsigned int* output, Source_28b2f0* first, Source_28b2f0* second, float factor, int index) {
 unsigned int a,b;
 first->FUN_0028ad20(index, &a);
 second->FUN_0028ad20(index, &b);
 int a1=(a>>8)&255, a2=(a>>16)&255, a3=a>>24, a0=a&255;
 unsigned int result=(unsigned int)((int)(((int)((b>>8)&255)-a1)*(double)factor)+a1)<<8;
 result |= (unsigned int)((int)(((int)((b>>16)&255)-a2)*(double)factor)+a2)<<16;
 result |= (unsigned int)((int)(((int)(b>>24)-a3)*(double)factor)+a3)<<24;
 result |= (unsigned int)((int)(((int)(b&255)-a0)*(double)factor)+a0);
 *output=result;
 return output;
}
