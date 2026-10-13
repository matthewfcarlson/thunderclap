// STATUS: equivalent (tools/equiv.py level 3: 174 inputs, branch coverage 21/22, incomplete)
// FUN_00239f10 @ 0x00239f10
struct Reader;
struct Factory;
struct Node {
 virtual void v0(); virtual void v1(); virtual void v2();
 virtual bool initialize(unsigned __int64 id, Factory* factory, Reader* reader);
 virtual void v4(); virtual Node* clone();
 Node* next;
 void FUN_00236b70(Node* nextNode);
};
struct Reader {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
 virtual bool more(); virtual unsigned __int64 readId();
 void FUN_00232c90();
};
struct Factory { Node* FUN_002367f0(unsigned __int64 id); };
extern void __cdecl FUN_00232cc0(Reader*, const char*);
extern unsigned int __cdecl FUN_00238190(int);
extern unsigned int __cdecl FUN_00266da0(unsigned int);
struct List { Node* head; bool FUN_00239f10(Factory*, Reader*, int); };
bool List::FUN_00239f10(Factory* factory, Reader* reader, int index) {
 Node* current = head;
 Node* previous = 0;
 int position = 0;
 while (current && index >= 0 && position < index) {
  previous = current;
  current = current->next;
  ++position;
 }
 while (reader->more()) {
  unsigned __int64 id = reader->readId();
  Node* prototype = factory ? factory->FUN_002367f0(id) : 0;
  if (!prototype) {
   FUN_00232cc0(reader, "Unrecognized track.");
   reader->FUN_00232c90();
  } else {
   unsigned int state = FUN_00266da0(FUN_00238190(2));
   Node* node = prototype->clone();
   if (node->initialize(id, factory, reader)) {
    node->FUN_00236b70(current);
    if (previous) previous->FUN_00236b70(node);
    else head = node;
    previous = node;
   }
   FUN_00266da0(state);
  }
 }
 return true;
}
