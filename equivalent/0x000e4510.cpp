// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000e4510 @ 0x000e4510
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
struct PartA { char data[28]; void FUN_000dee10(); };
struct PartB { void FUN_000dee40(); };
struct FEContainer {
 virtual void slot0();
 unsigned int owner;
 char name[32];
 unsigned int values[8];
 unsigned int count;
 unsigned int first[128];
 char untouched[512];
 unsigned int second[128];
 unsigned int third[128];
 float scale;
 unsigned int state;
 int index;
 unsigned char flag;
 char padding[255];
 PartA a;
 float factor;
 PartB b;
 FEContainer(unsigned int, const char*);
};
FEContainer::FEContainer(unsigned int id, const char* text) {
 index = -1;
 a.FUN_000dee10();
 b.FUN_000dee40();
 owner = id;
 strncpy(name, text, 32);
 for (int i=0;i<8;++i) values[i]=0;
 for (int j=0;j<128;++j) first[j]=0;
 for (int k=0;k<128;++k) second[k]=0;
 for (int l=0;l<128;++l) third[l]=0;
 count=0;
 state=0;
 flag=0;
 scale=1.0f;
 factor=1.0f;
}
