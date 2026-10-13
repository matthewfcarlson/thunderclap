// STATUS: equivalent (tools/equiv.py level 3: 174 inputs, branch coverage 21/22, incomplete)
// FUN_00237050 @ 0x00237050
typedef unsigned __int64 Token;
struct Stream { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual bool ready(); virtual Token token(); void FUN_00232c90(); };
struct Registry;
struct Node { Node* next; virtual void v0(); virtual void v1(); virtual void v2(); virtual bool parse(Token, Registry*, Stream*); void FUN_002344a0(Node*); };
struct Factory { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual Node* create(); };
struct Registry { Factory* FUN_00236790(Token); };
void __cdecl FUN_00232cc0(Stream*, const char*);
int __cdecl FUN_00238190(int);
int __cdecl FUN_00266da0(int);
struct List { Node* head; bool FUN_00237050(Registry*, Stream*, int); };
bool List::FUN_00237050(Registry* registry, Stream* stream, int index) {
 Node* current=head; Node* previous=0; int i=0;
 while(current && index>=0 && i<index) { previous=current; current=current->next; ++i; }
 while(stream->ready()) {
  Token token=stream->token();
  Factory* factory=registry ? registry->FUN_00236790(token) : 0;
  if(!factory) { FUN_00232cc0(stream,"Unrecognized condition."); stream->FUN_00232c90(); }
  else {
   int state=FUN_00266da0(FUN_00238190(2));
   Node* node=factory->create();
   if(node->parse(token,registry,stream)) {
    node->FUN_002344a0(current);
    if(previous) previous->FUN_002344a0(node); else head=node;
    previous=node;
   }
   FUN_00266da0(state);
  }
 }
 return true;
}