// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// FUN_00036f00 @ 0x00036f00
struct Key { unsigned int low, high; };
struct Entry { unsigned int low, high; unsigned char flag, active; char pad[6]; bool FUN_0027af90(Key*); void FUN_0027af70(Key*); };
struct Manager { char pad[0x2258]; Entry entries[4]; int next; char tailPad[4]; unsigned char extraFlag; unsigned char extraActive; int FUN_00036f00(Key* key); };
int Manager::FUN_00036f00(Key* key) {
 if ((key->low | key->high)==0) return -1;
 for(int i=0;i<4;++i) if(entries[i].FUN_0027af90(key)) return i;
 int slot=next;
 entries[slot].FUN_0027af70(key);
 entries[slot].flag=0;
 extraActive=1;
 int empty=0;
 for(;empty<4;++empty) if((entries[empty].low|entries[empty].high)==0) break;
 if(empty<4) next=empty;
 else next=(slot+1)%4;
 return slot;
}