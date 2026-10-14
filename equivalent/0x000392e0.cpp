// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 19/20, incomplete)
// FUN_000392e0 @ 0x000392e0
struct Actor_392e0;
struct Request;
struct Handler_392e0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual int slot8(Request*, int);
};
struct State_392e0 {
 char pad0[0xf8]; Handler_392e0* handler;
 char pad1[0x1a4-0xfc]; int contribution;
 char pad2[8]; int identity;
};
struct Link_392e0 { char pad[8]; Actor_392e0* actor; int type; };
struct Data_392e0 {
 char pad0[0x24]; unsigned char enabled;
 char pad1[0x4c-0x25]; Link_392e0* link;
 char pad2[4]; int limit;
};
struct Request {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Data_392e0* slot3();
};
struct Actor_392e0 {
 char pad0[0x11c]; State_392e0* state;
 char pad1[0x318-0x120]; int count1; int count2;
 char pad2[0x1cef-0x320]; unsigned char flag;
 char pad3[0x2138-0x1cf0]; unsigned char blocked;
 int FUN_000392e0(Request* request);
};
int Actor_392e0::FUN_000392e0(Request* request) {
 if (!state) return 0;
 Data_392e0* data = request->slot3();
 unsigned char enabled = data->enabled;
 int limit = data->limit;
 State_392e0* current = state;
 int contribution = current ? current->contribution : 0;
 int total = (int)((unsigned int)count2 + (unsigned int)count1 + (unsigned int)contribution);
 if (total > limit) enabled = 0;
 Link_392e0* link = data->link;
 if (link && link->type == 1 && link->actor && !blocked && (float)flag > 0.0f && link->actor->state->identity == current->identity) return 0;
 data->enabled = enabled;
 Handler_392e0* handler = state->handler;
 if (!handler) return 0;
 return handler->slot8(request, 0);
}