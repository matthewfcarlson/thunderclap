// STATUS: equivalent (tools/equiv.py level 3: 2628 inputs, branch coverage 6/6)
// FUN_0028ad20 @ 0x0028ad20
struct Track {
 char pad0[4]; int enabled; char pad8[12]; short* times; unsigned int* colors;
 bool FUN_00289f80(float value,int* lower,int* upper);
 void sample(float value,unsigned int* output);
};
void Track::sample(float value,unsigned int* output) {
 int lower,upper;
 if (!FUN_00289f80(value,&lower,&upper) || !enabled) { *output=colors[lower]; return; }
 int start=times[lower];
 int delta=(int)value-start;
 if (!delta) { *output=colors[lower]; return; }
 int duration=times[upper]-times[lower];
 unsigned int a=colors[lower],b=colors[upper];
 int alpha=a>>24, green=(a>>8)&255, blue=(a>>16)&255, red=a&255;
 unsigned int result=(unsigned int)(alpha+((int)(b>>24)-alpha)*delta/duration)<<24;
 result|=(unsigned int)(green+((int)((b>>8)&255)-green)*delta/duration)<<8;
 result|=(unsigned int)(blue+((int)((b>>16)&255)-blue)*delta/duration)<<16;
 result|=(unsigned int)(red+((int)(b&255)-red)*delta/duration);
 *output=result;
}
