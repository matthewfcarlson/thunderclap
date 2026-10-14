// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 28/28)
// FUN_00326e90 @ 0x00326e90
struct Format_326e90 { char pad[8]; unsigned flags; unsigned unused; unsigned count; };
struct Layout_326e90 {
 char pad[8]; Format_326e90* format; char* base; unsigned zero; unsigned arg; unsigned count; unsigned texCount; unsigned blendCount; char* position; unsigned reserved; char* normal; char* blend; char* color; char* tex; char* extra1; char* extra2; char* extra3; char* extra4; char* weight; char* point;
 char* FUN_00326e90(char* data, Format_326e90* fmt, unsigned value, unsigned unused);
};
char* Layout_326e90::FUN_00326e90(char* data, Format_326e90* fmt, unsigned value, unsigned unused) {
 base=data; zero=0; arg=value; reserved=0; blend=0; color=0; tex=0; extra1=0; extra2=0; extra3=0; extra4=0; point=0; weight=0; format=fmt;
 unsigned flags=fmt->flags;
 unsigned n=(flags&0x20)?1:((flags&0x4000)?((flags>>15)&7):0);
 unsigned t=flags&15;
 position=data; blendCount=n; texCount=t; count=fmt->count;
 char* p=data+12;
 if(flags&0x100){point=p;p+=4;}
 if(flags&0x80){weight=p;p+=4;}
 if(flags&0x10){normal=p;p+=4;}
 if(flags&0x20){blend=p;p+=4;} else if((flags&0x4000)&&n>0){blend=p;p+=n*4;}
 if(flags&0x40){color=p;p+=4;}
 if(t){tex=p;p+=t*8;}
 if(flags&0x200){extra1=p;p+=4;}
 if(flags&0x400){extra2=p;p+=4;}
 if(flags&0x800){extra3=p;p+=12;}
 if(flags&0x1000){extra4=p;}
 return p;
}
