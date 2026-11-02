// STATUS: equivalent (tools/equiv.py level 3: 1081 inputs, branch coverage 17/17)
// FUN_00216ac0 @ 0x00216ac0
// FUN_00216ac0 @ 0x00216ac0
struct Node { unsigned int h; unsigned char type, flags, mode, shift; Node* next8; char p0[12]; Node* next18; unsigned int count1c, count20, count24, count28, count2c, count30, count34, count38; char p1[4]; Node* next40; char p2[8]; Node* next4c; };
struct State_216ac0 { char pad[40]; Node* head; Node* list; };
// equiv-conv: FUN_00216670 edi stack
extern "C" int __cdecl FUN_00216670(void *, void *);
// equiv-conv: FUN_002168d0 esi stack
extern "C" void __cdecl FUN_002168d0(void *, void *);
// equiv-conv: FUN_002169e0 edi stack
extern "C" void __cdecl FUN_002169e0(void *, void *);
// equiv-conv: FUN_00216810 esi stack
extern "C" void __cdecl FUN_00216810(void *, void *);
// equiv-conv: FUN_00216ac0 eax stack
extern "C" int FUN_00216ac0(int budget, void * state) {
 Node* n=((State_216ac0 *)state)->head;
 if (!n) return budget;
 do {
 n->flags |= 4;
 switch(n->type) {
 case 5: ((State_216ac0 *)state)->head=n->next18; if(FUN_00216670((Node *)n,(State_216ac0 *)((State_216ac0 *)state))) n->flags &= ~4; budget += (unsigned int)(-4-n->count1c)*8 - ((1u<<(n->shift&31))*20); break;
 case 6: ((State_216ac0 *)state)->head=n->next8; FUN_002168d0((Node *)n,(State_216ac0 *)((State_216ac0 *)state)); budget -= n->mode ? n->shift*8+16 : n->shift*4+24; break;
 case 8: ((State_216ac0 *)state)->head=n->next4c; n->next4c=((State_216ac0 *)state)->list; ((State_216ac0 *)state)->list=n; n->flags &= ~4; FUN_002169e0((Node *)n,(State_216ac0 *)((State_216ac0 *)state)); budget += (-11-2*(n->count2c&65535)-n->count20)*8; break;
 case 9: ((State_216ac0 *)state)->head=n->next40; FUN_00216810((Node *)n,(State_216ac0 *)((State_216ac0 *)state)); budget += (-2*n->count28-3*(n->count38+6)-n->count34-n->count30-n->count2c-n->count24)*4; break;
 }
 if(budget<=0) break;
 n=((State_216ac0 *)state)->head;
 } while(n);
 return budget;
}
