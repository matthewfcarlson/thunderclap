// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 54/54)
// FUN_0026de40 @ 0x0026de40
struct Event {
 unsigned type, a;
 union { unsigned b; unsigned char keyFlags[4]; };
 unsigned c,d,kind;
 unsigned char flags[4];
};
struct ReceiverA {
 virtual void key(unsigned);
 virtual void keyState(unsigned,bool,bool,bool);
};
struct ReceiverB {
 virtual void action0(unsigned,unsigned,unsigned,unsigned,bool,bool,bool);
 virtual void action1(unsigned,unsigned,unsigned,unsigned,bool,bool,bool);
 virtual void action2(unsigned,unsigned,unsigned,unsigned,bool,bool,bool);
 virtual void action3(unsigned,unsigned,unsigned,unsigned,bool,bool,bool,bool);
};
struct Queue {
 char pad[0x9c]; ReceiverB* receiverB; ReceiverA* receiverA; char pad2[8];
 Event events[256]; unsigned writeIndex,readIndex;
 void FUN_0026de40();
};
void Queue::FUN_0026de40() {
 while(writeIndex != readIndex) {
  Event& e=events[readIndex];
  readIndex=(readIndex+1)&255;
  switch(e.type) {
   case 0: if(receiverA) receiverA->key(e.a); break;
   case 1: if(receiverA) receiverA->keyState(e.a,e.keyFlags[0]!=0,e.keyFlags[1]!=0,e.keyFlags[2]!=0); break;
   case 2:
    if(receiverB) switch(e.kind) {
     case 0: receiverB->action3(e.a,e.b,e.c,e.d,e.flags[0]!=0,e.flags[1]!=0,e.flags[2]!=0,e.flags[3]!=0); break;
     case 1: receiverB->action1(e.a,e.b,e.c,e.d,e.flags[0]!=0,e.flags[1]!=0,e.flags[2]!=0); break;
     case 2: receiverB->action2(e.a,e.b,e.c,e.d,e.flags[0]!=0,e.flags[1]!=0,e.flags[2]!=0); break;
     case 3: receiverB->action0(e.a,e.b,e.c,e.d,e.flags[0]!=0,e.flags[1]!=0,e.flags[2]!=0); break;
    }
    break;
  }
 }
}