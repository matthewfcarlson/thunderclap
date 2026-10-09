typedef unsigned int u32;
class Callee { public: void Run(int a, int b); };
class Obj { public: char pad[0xac4]; Callee* mArg; char* mBase; void Target(int param2, int index); };
void Obj::Target(int param2, int index) {
    char* p = mBase + index * 0xbe8;
    for (int i=0; i<0x2fa; ++i) ((u32*)p)[i]=0;
    p[4]=0;
    mArg->Run(param2,index);
}