// STATUS: equivalent (tools/equiv.py level 3: 680 inputs, branch coverage 12/12)
// FUN_00306380 @ 0x00306380
struct Node;
struct Children_306380 { Node** begin; Node** end; };
struct Node {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual int slot6();
 char pad04[0x10]; Children_306380* children;
 char pad18[0x20];
 unsigned int f38;
 char pad3c[8];
 unsigned int f44,f48,f4c,f50,f54,f58,f5c,f60,f64,f68,f6c,f70,f74;
 char pad78[0x10];
 unsigned int f88,f8c,f90,f94,f98,f9c,fa0,fa4,fa8,fac,fb0,fb4;
 void FUN_00306380();
};
void Node::FUN_00306380() {
 int kind=slot6();
 if(kind==2) f60=0;
 else if(kind==5) {
 f38=0;
 f48=f88; f54=f94; f58=f98; f5c=f9c;
 f4c=f8c; f60=fa0; f64=fa4; f68=fa8;
 f50=f90; f6c=fac; f70=fb0; f74=fb4;
 } else if(kind==8) f44=0;
 if(children) {
 unsigned int count=(unsigned int)(((int)children->end-(int)children->begin)>>2);
 for(unsigned int i=0;i<count;++i) {
 children->begin[i]->FUN_00306380();
 count=(unsigned int)(((int)children->end-(int)children->begin)>>2);
 }
 }
}