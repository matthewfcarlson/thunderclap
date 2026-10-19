// STATUS: equivalent (tools/equiv.py level 3: 93 inputs, branch coverage 15/17, incomplete)
// FUN_00216ac0 @ 0x00216ac0
struct Node { unsigned int h; unsigned char type, flags, mode, shift; Node* next8; char p0[12]; Node* next18; unsigned int count1c, count20, count24, count28, count2c, count30, count34, count38; char p1[4]; Node* next40; char p2[8]; Node* next4c; };
struct State_216ac0 { char pad[40]; Node* head; Node* list; };
// equiv-conv: FUN_00216670 edi stack
int FUN_00216670(Node*, State_216ac0*);
// equiv-conv: FUN_002168d0 esi stack
void __cdecl FUN_002168d0(Node*, State_216ac0*);
// equiv-conv: FUN_002169e0 edi stack
void FUN_002169e0(Node*, State_216ac0*);
// equiv-conv: FUN_00216810 esi stack
void __cdecl FUN_00216810(Node*, State_216ac0*);
// equiv-conv: FUN_00216ac0 eax stack
int FUN_00216ac0(int budget, State_216ac0* state) {
 Node* n=state->head;
 if (!n) return budget;
 do {
 n->flags |= 4;
 switch(n->type) {
 case 5: state->head=n->next18; if(FUN_00216670(n,state)) n->flags &= ~4; budget += (unsigned int)(-4-n->count1c)*8 - ((1u<<(n->shift&31))*20); break;
 case 6: state->head=n->next8; FUN_002168d0(n,state); budget -= n->mode ? n->shift*8+16 : n->shift*4+24; break;
 case 8: state->head=n->next4c; n->next4c=state->list; state->list=n; n->flags &= ~4; FUN_002169e0(n,state); budget += (-11-2*(n->count2c&65535)-n->count20)*8; break;
 case 9: state->head=n->next40; FUN_00216810(n,state); budget += (-2*n->count28-3*(n->count38+6)-n->count34-n->count30-n->count2c-n->count24)*4; break;
 }
 if(budget<=0) break;
 n=state->head;
 } while(n);
 return budget;
}