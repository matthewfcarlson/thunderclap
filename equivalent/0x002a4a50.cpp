// STATUS: equivalent (tools/equiv.py level 3: 52 inputs, branch coverage 16/18, incomplete)
// FUN_002a4a50 @ 0x002a4a50
struct Element { virtual void unused(); virtual void release(); };
struct Array { unsigned int unknown; Element** begin; Element** end; };
extern "C" void __cdecl FUN_0008d340(void*);
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
void __stdcall resizeArray(Array* a, unsigned int count) {
    unsigned int i=count;
    while(i < (unsigned int)(a->end-a->begin)) {
        Element** slot=a->begin+i;
        if(*slot) { (*slot)->release(); *slot=0; }
        ++i;
    }
    if(a->begin) FUN_0008d340(a->begin);
    a->begin=0;
    a->end=0;
    if(count) {
        Element** p=(Element**)FUN_0008d6d0(count*4);
        a->begin=p;
        if(p) {
            a->end=(Element**)((char*)p+count*4);
            for(unsigned int j=0;j<count;++j,++p) if(p) *p=0;
            return;
        }
    }
    a->begin=0;
    a->end=0;
}
