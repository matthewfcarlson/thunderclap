// STATUS: equivalent (tools/equiv.py level 3: 102 inputs, branch coverage 52/54, incomplete)
// FUN_0031c290 @ 0x0031c290
extern unsigned char DAT_0031c544[39];
struct FormatInfo {
 char reserved[16];
 unsigned int type;
 unsigned char direct;
 char pad[3];
 unsigned int redStart, greenStart, blueStart, alphaStart;
 unsigned int redShift, greenShift, blueShift, alphaShift;
 unsigned int redMask, greenMask, blueMask, alphaMask;
};
void __cdecl FUN_0031c290(unsigned int format, FormatInfo* out) {
 unsigned int r=0,g=0,b=0,a=0;
 unsigned int index=format-2;
 if(index<=38) switch(DAT_0031c544[index]) {
 case 3: r=0xf800;g=0x7e0;b=0x1f;out->type=1;break;
 case 0: a=0x8000;r=0x7c00;g=0x3e0;b=0x1f;out->type=2;break;
 case 2: a=0xf000;r=0xf00;g=0xf0;b=0xf;out->type=4;break;
 case 4: a=0xff000000;r=0xff0000;g=0xff00;b=0xff;out->type=6;break;
 case 5: r=0xff0000;g=0xff00;b=0xff;out->type=6;break;
 case 1: r=0x7c00;g=0x3e0;b=0x1f;out->type=3;break;
 case 7: out->type=11;break;
 case 8: out->type=13;break;
 case 9: out->type=15;break;
 case 6: out->type=7;break;
 case 10: out->type=10;break;
 }
 out->redMask=r;out->greenMask=g;out->blueMask=b;out->alphaMask=a;
 unsigned int masks[4];masks[0]=r;masks[1]=g;masks[2]=b;masks[3]=a;
 unsigned int counts[4], starts[4];
 for(int j=0;j<4;++j){counts[j]=0;starts[j]=0;bool found=false;for(unsigned int i=0;i<32;++i){if(masks[j] & (1u<<i)){++counts[j];if(!found){starts[j]=i;found=true;}}}}
 out->redShift=24-counts[0];out->greenShift=16-counts[1];out->blueShift=8-counts[2];out->alphaShift=32-counts[3];
 out->redStart=starts[0];out->greenStart=starts[1];out->blueStart=starts[2];out->alphaStart=starts[3];
 out->direct=(r==0xff0000 && g==0xff00 && b==0xff && a==0xff000000);
}