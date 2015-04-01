#ifndef INSTRUMENTATION_H_INCLUDED
#define INSTRUMENTATION_H_INCLUDED

#define add(s,a,b) ++g_counter; ++g_counter_add; s = a + b;
#define sub(s,a,b) ++g_counter; ++g_counter_sub; s = a - b;
#define mult(s,a,b) ++g_counter; ++g_counter_mult; s = a * b;
#define divd(s,a,b) ++g_counter; ++g_counter_divd; s = a / b;
#define jump(label) ++g_counter; ++g_counter_jump; goto label;
#define load(s,a)  ++g_counter; ++g_counter_load; s = a;
#define store(s,a) ++g_counter; ++g_counter_store; s = a;

int g_counter;
int g_counter_add;
int g_counter_sub;
int g_counter_mult;
int g_counter_divd;
int g_counter_compare;
int g_counter_jump;
int g_counter_load;
int g_counter_store;

int compare(int a, int b, char op);

void store_scanf(char* string, int* location);
void load_printfo(char* string);
void load_printft(char* string, int* location);

void print_counters(int d);

#endif // INSTRUMENTATION_H_INCLUDED
