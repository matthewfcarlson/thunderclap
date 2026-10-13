// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000c7b70 @ 0x000c7b70
struct Timer {
 unsigned int a,b;
 Timer* FUN_0027af00();
 void FUN_0027af70(Timer* source);
 void FUN_0027af50();
};
struct Entry {
 int id;
 unsigned int x,y,z;
 unsigned int zero0,zero1,zero2,zero3,zero4;
 char pad[4];
 Timer timer;
 int state;
 unsigned int zero5,zero6;
 unsigned char flag0,flag1;
 char tail[2];
};
struct Manager {
 char pad[0x258];
 Entry entries[128];
 int FUN_000c7b70(int id,unsigned int x,unsigned int y,unsigned int z);
};
int Manager::FUN_000c7b70(int id,unsigned int x,unsigned int y,unsigned int z) {
 int i;
 for(i=0;i<128;++i) if(entries[i].id==-1) break;
 if(i==128) return -1;
 Entry &e=entries[i];
 e.id=id;
 Timer temp;
 Timer* result=temp.FUN_0027af00();
 e.timer.FUN_0027af70(result);
 temp.FUN_0027af50();
 e.state=2;
 e.y=y;
 e.x=x;
 e.z=z;
 e.zero1=0;
 e.zero0=0;
 e.zero2=0;
 e.zero3=0;
 e.zero4=0;
 e.zero5=0;
 e.zero6=0;
 e.flag0=0;
 e.flag1=0;
 return i;
}