// STATUS: equivalent (tools/equiv.py level 3: 2608 inputs, branch coverage 8/8)
// FUN_00293ef0 @ 0x00293ef0
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
struct Matrix { unsigned data[16]; void FUN_0022ca90(Matrix*, Matrix*); void FUN_0022cdb0(); };
#define V(n) virtual void s##n();
struct Provider { V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) virtual Matrix* matrix(); V(15) V(16) V(17) V(18) V(19) V(20) V(21) virtual void activate(); };
struct Gfx { V(0) V(1) V(2) V(3) V(4) V(5) virtual void set20(unsigned); V(7) virtual void set24(unsigned); V(9) virtual void set28(unsigned); V(11) virtual void set2c(unsigned); V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23) V(24) V(25) virtual void viewport(unsigned,unsigned,unsigned,unsigned); V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) virtual void state(unsigned); V(36) V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) virtual void enable(unsigned); V(79) virtual void values(unsigned,unsigned,unsigned); };
struct Renderer { V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) virtual void reset(unsigned); V(17) V(18) V(19) V(20) V(21) virtual void transform(unsigned,Matrix*); };
struct Item { V(0) V(1) V(2) V(3) V(4) virtual void bind(unsigned); };
struct Target;
struct Context { char pad[8]; Target* current; void FUN_0028fa40(Matrix*,Matrix*); };
struct Target { char pad[8]; unsigned x,y,w,h; Provider* provider; unsigned state; unsigned a,b,c,d; unsigned v0,v1,v2; Item* items[32]; unsigned char enabled; char padbd[3]; Matrix first,second; void run(); };
void Target::run() {
 (*(Context**)&DAT_0052c2b4)->current=this;
 provider->activate();
 DAT_0052c2a8->viewport(x,y,w,h);
 DAT_0052c2a8->state(state);
 struct { Matrix inverse, original, next; } matrices;
 matrices.original.FUN_0022ca90(provider->matrix(), &first);
 matrices.inverse=matrices.original;
 matrices.inverse.FUN_0022cdb0();
 (*(Context**)&DAT_0052c2b4)->FUN_0028fa40(&matrices.inverse,&matrices.original);
 matrices.next.FUN_0022ca90(provider->matrix(), &second);
 matrices.next.FUN_0022cdb0();
 (*(*(Renderer***)&DAT_0052c2ac))->transform(0,&matrices.next);
 unsigned slot=0;
 Item** item=items;
 unsigned remaining=32;
 do { if(*item) { (*item)->bind(slot); ++slot; } ++item; } while(--remaining);
 (*(*(Renderer***)&DAT_0052c2ac))->reset(0);
 if(enabled) { DAT_0052c2a8->enable(1); DAT_0052c2a8->values(v0,v1,v2); } else DAT_0052c2a8->enable(0);
 if(d) { DAT_0052c2a8->set20(a); DAT_0052c2a8->set24(b); DAT_0052c2a8->set28(c); DAT_0052c2a8->set2c(d); }
}
