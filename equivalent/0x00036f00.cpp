// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// FUN_00036f00 @ 0x00036f00
struct Key_36f00 { unsigned int low, high; };
struct Entry_36f00 { unsigned int low, high; unsigned char flag, active; char pad[6]; bool FUN_0027af90(Key_36f00*); void FUN_0027af70(Key_36f00*); };
struct Manager_36f00 { char pad[0x2258]; Entry_36f00 entries[4]; int next; char tailPad[4]; unsigned char extraFlag; unsigned char extraActive; int FUN_00036f00(Key_36f00* key); };
int Manager_36f00::FUN_00036f00(Key_36f00* key) {
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