// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 28/28)
// FUN_001ad7d0 @ 0x001ad7d0
struct Record { int children[3]; unsigned char levels[3]; unsigned char level; char pad[6]; unsigned short flags; };
struct Store { Record* FUN_001b5800(int); bool FUN_001b65f0(int,int); };
struct Context { Store* store; unsigned int minLevel; unsigned int maxLevel; unsigned int minFlags; };
bool __cdecl FUN_001ad730(int, Context*);
struct Iterator { int parent; int current; int index; int accept; void advance(Context*); };
void Iterator::advance(Context* ctx) {
 Record* root=ctx->store->FUN_001b5800(parent);
 if (!root) { index=-1; return; }
 ++index;
 while(index<3) {
  current=root->children[index];
  if(current==-1 && ctx->store->FUN_001b65f0(parent,index)) current=root->children[index];
  if(current!=-1) {
   Record* entry=ctx->store->FUN_001b5800(current);
   if(entry) {
    unsigned int flags=entry->flags >> 3;
    unsigned int group=(flags>>7)&7;
    if((group==0 || group>=ctx->minFlags) && !(flags & 0x1c00)) {
     if(entry->level>ctx->maxLevel) {
      if(FUN_001ad730(current,ctx)) return;
     } else if(accept || root->levels[index]>=ctx->minLevel) return;
    }
   }
  }
  ++index;
 }
 index=-1;
}
