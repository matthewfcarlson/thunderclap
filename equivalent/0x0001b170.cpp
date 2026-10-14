// STATUS: equivalent (tools/equiv.py level 3: 242 inputs, branch coverage 20/20)
// FUN_0001b170 @ 0x0001b170
struct Node;
struct Children_1b170 { Node **begin; Node **end; };
struct Node {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int type();
 char pad04[16]; Children_1b170 *children; char pad18[48]; float values[3];
};
void __cdecl FUN_0001b170(Node *node, Node **best, float *maximum, int *index) {
 if (!node) return;
 int kind=node->type();
 if(kind==5) {
 float values[3]; values[0]=node->values[0]; values[1]=node->values[1]; values[2]=node->values[2];
 for(int i=0;i<3;++i) if(values[i]>*maximum) { *maximum=values[i]; *best=node; *index=i; }
 } else if(kind==2) {
 float value=node->values[2]; if(value>*maximum) { *maximum=value; *best=node; *index=-1; }
 }
 Children_1b170 *children=node->children;
 if(children) for(unsigned i=0; i<(unsigned)(children->end-children->begin); ++i) FUN_0001b170(children->begin[i],best,maximum,index);
}
