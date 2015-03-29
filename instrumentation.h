#ifndef INSTRUMENTATION_H_INCLUDED
#define INSTRUMENTATION_H_INCLUDED

#define jump(label) ++g_counter; ++g_counter_jump; goto label;

int g_counter;
int g_counter_add;
int g_counter_sub;
int g_counter_mult;
int g_counter_divd;
int g_counter_compare;
int g_counter_jump;
int g_counter_load;
int g_counter_store;

int add(int a, int b);
int sub(int a, int b);
int mult(int a, int b);
int divd(int a, int b);
int compare(int a, int b, char op);
int load(int a);
int store(int a);

void store_scanf(char* string, int* location);
void load_printf_one(char* string);
void load_printf_two(char* string, int* location);

void print_counters(int d);

#endif // INSTRUMENTATION_H_INCLUDED
