// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 53/60, incomplete)
// pure3d::d3dExtFramebufferEffects::vfunc_8 @ 0x00322cd0
#include "decls/data/platform/xbox/pure3d.h"

extern "C" double __cdecl exp(double);
namespace pure3d {struct d3dExtFramebufferEffects {virtual void vfunc_0();virtual void vfunc_1();virtual void vfunc_2();virtual void vfunc_3();virtual void vfunc_4();virtual void vfunc_5();virtual void vfunc_6();virtual void vfunc_7();virtual void vfunc_8(float,int,float,float,unsigned,float,float,float);char pad[180];float amount,blend,contrast,radius,unusedC8,mix;char padD0[8];float sigma;int mode;float red,green,blue;int unusedEC;float positions[20],weights[20];};
void d3dExtFramebufferEffects::vfunc_8(float a,int flag,float b,float q,unsigned color,float r,float c,float m){
blend=(b>=0.0f&&b<=1.0f)?b:(b>1.0f?1.0f:0.0f);radius=((r>=-100.0f&&r<=100.0f)?r:(r>100.0f?100.0f:-100.0f))*0.003921568859368563f;
double x=(double)a*0.5f;amount=(x>=0.0f&&x<=1.0f)?(float)x:(x>1.0f?1.0f:0.0f);mix=(m>=0.0f&&m<=1.0f)?m:(m>1.0f?1.0f:0.0f);contrast=(c>=-100.0f&&c<=100.0f)?c:(c>100.0f?100.0f:-100.0f);mode=flag;x=(double)q*0.25f;sigma=(x>=0.0f&&x<=25.0f)?(float)x:(x>25.0f?25.0f:0.0f);
blue=(color&255)*0.003921568859368563f;red=((color>>16)&255)*0.003921568859368563f;green=((color>>8)&255)*0.003921568859368563f;double total=(double)blue+green+red;if(total>0.0f){double inv=1.0f/total;red=(float)(inv*red);green=(float)(inv*green);blue=(float)(inv*blue);}else{red=green=blue=0.3333333432674408f;}
if(contrast<0.0f)contrast=(float)((double)contrast*0.01f+1.0f);else contrast=((float*)&DAT_00432a10)[(int)((double)contrast+0.5f)];
x=(double)sigma*0.45f+0.3f;float square=(float)(x*x);double initial=exp(0.0f/square),accum=initial;int count=1;for(;count<20;++count){double w=exp(-((double)count*count)/square);if(accum>255.5*w)break;accum+=w+w;}double sum=initial;weights[0]=(float)initial;positions[0]=0.0f;for(int i=1;i<count;++i){float w=(float)exp(-((double)i*i)/square);weights[i]=w;positions[i]=(float)i;if(!(w>0.003921568859368563f)){count=i;break;}sum+=(double)w+w;}float scale=(float)(1.0f/sum);for(int j=0;j<count;++j)weights[j]*=scale;for(;j<20;++j)weights[j]=0.0f;
}}
