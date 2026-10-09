class Node { public: int a[4]; int next; };
class Search { public: Node* First(); };
class Worker { public: void Run(int); };
class Obj { public: char pad[0x608]; void Target(Search*, int); };
void Obj::Target(Search* search, int value) {
 Node* p=search->First();
 while(p) {
  char* rec=(char*)this+(p->a[0]*0x28)+0x608;
  short n=*(short*)(rec+0x22);
  if (*(unsigned char*)((char*)this+(n+0x104e)*0x14)&1) {
   Worker* w=*(Worker**)(rec+0x18); w->Run(value);
  }
  p=(Node*)p->next;
 }
}