// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 32/32)
// FUN_002ffce0 @ 0x002ffce0
#include "compat/ptr.h"
void __cdecl FUN_002ffce0(unsigned int* first, unsigned int* middle, unsigned int* last)
{
    unsigned int a,b;
    hulk_intptr count = last-first;
    if(count > 40) {
        hulk_intptr step=(count+1)/8;
        unsigned int* p=first+step;
        unsigned int* q=first+2*step;
        a=*p; b=*first; if(a<b){*p=b;*first=a;}
        a=*q; b=*p; if(a<b){*q=b;*p=a;}
        a=*p; b=*first; if(a<b){*p=b;*first=a;}
        unsigned int* lo=middle-step;
        unsigned int* hi=middle+step;
        a=*middle; b=*lo; if(a<b){*middle=b;*lo=a;}
        a=*hi; b=*middle; if(a<b){*hi=b;*middle=a;}
        a=*middle; b=*lo; if(a<b){*middle=b;*lo=a;}
        unsigned int* r=last-step;
        unsigned int* s=last-2*step;
        a=*r; b=*s; if(a<b){*r=b;*s=a;}
        a=*last; b=*r; if(a<b){*last=b;*r=a;}
        a=*r; b=*s; if(a<b){*r=b;*s=a;}
        a=*middle; b=*p; if(a<b){*middle=b;*p=a;}
        a=*r; b=*middle; if(a<b){*r=b;*middle=a;}
        a=*middle; b=*p; if(a<b){*middle=b;*p=a;}
    } else {
        a=*middle; b=*first; if(a<b){*middle=b;*first=a;}
        a=*last; b=*middle; if(a<b){*last=b;*middle=a;}
        a=*middle; b=*first; if(a<b){*middle=b;*first=a;}
    }
}
