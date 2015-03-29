#include <stdio.h>
#include <stdlib.h>

#include "instrumentation.h"

int add(int a, int b)
{
    ++g_counter;
    ++g_counter_add;
    return a+b;
}

int sub(int a, int b)
{
    ++g_counter;
    ++g_counter_sub;
    return a-b;
}

int mult(int a, int b)
{
    ++g_counter;
    ++g_counter_mult;
    return a*b;
}

int divd(int a, int b)
{
    ++g_counter;
    ++g_counter_divd;
    return a/b;
}

int compare(int a, int b, char op)
{
    ++g_counter;
    ++g_counter_compare;
    switch(op)
    {
        case 'l':
            return a < b;
        case 'g':
            return a > b;
        case 'e':
            return a == b;
        case 'n':
            return a != b;
        default:
            exit(1);
    }
}

int load(int a)
{
    ++g_counter;
    ++g_counter_load;
    return a;
}

int store(int a)
{
    ++g_counter;
    ++g_counter_store;
    return a;
}

void store_scanf(char* string, int* location)
{
    ++g_counter;
    ++g_counter_store;
    scanf(string, location);
}

void load_printf_one(char* string)
{
    ++g_counter;
    ++g_counter_load;
    printf(string);
}

void load_printf_two(char* string, int* location)
{
    ++g_counter;
    ++g_counter_load;
    printf(string, *location);
}

void print_counters(int d)
{
    printf("\n");
    printf("d = %d\n",d);
    printf("==BEGIN COUNTER REPORT==============\n");
    printf("Add Counter: %d\n", g_counter_add);
    printf("Sub Counter: %d\n", g_counter_sub);
    printf("Mult Counter: %d\n", g_counter_mult);
    printf("Divd Counter: %d\n", g_counter_divd);
    printf("Compare Counter: %d\n", g_counter_compare);
    printf("Jump Counter: %d\n", g_counter_jump);
    printf("Load Counter: %d\n", g_counter_load);
    printf("Store Counter: %d\n", g_counter_store);
    printf("All Counters: %d\n", g_counter);
    printf("==END COUNTER REPORT================\n");
    printf("\n");
    printf("==BEGIN ANALYSIS====================\n");
    printf("Add Percent: %f\n",g_counter_add/(double)g_counter);
    printf("Sub Percent: %f\n",g_counter_sub/(double)g_counter);
    printf("Mult Percent: %f\n",g_counter_mult/(double)g_counter);
    printf("Divd Percent: %f\n",g_counter_divd/(double)g_counter);
    printf("Compare Percent: %f\n",g_counter_compare/(double)g_counter);
    printf("Jump Percent: %f\n",g_counter_jump/(double)g_counter);
    printf("Load Percent: %f\n",g_counter_load/(double)g_counter);
    printf("Store Percent: %f\n",g_counter_store/(double)g_counter);
    printf("==END ANALYSIS======================\n");
}
