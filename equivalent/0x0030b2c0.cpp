// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0030b2c0 @ 0x0030b2c0
struct Settings { char pad[0x224]; float scale; };
struct Object {
 char pad0[0x10]; float lower; float upper; Settings* settings;
 char pad1[0x10c-0x1c]; float time;
 char pad2[0x11c-0x110]; float offset;
 float FUN_0030adc0(float start, float delta, float lower, float upper);
 float target(float delta);
};
extern float DAT_004d3198;
float Object::target(float delta) {
 float limit=1.0f;
 if(delta==0.0f || time+delta==0.0f) return limit;
 float result=FUN_0030adc0(time*settings->scale+offset,delta*settings->scale,lower,upper);
 if(result>0.0f) limit=FUN_0030adc0(time,delta,-DAT_004d3198,DAT_004d3198);
 return result<limit ? result:limit;
}