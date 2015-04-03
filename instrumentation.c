#include <stdio.h>
#include <stdlib.h>

#include "instrumentation.h"

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
            printf("ERROR in compare(a=%d,b=%d,op=%c): Not a valid op.\n",a,b,op);
            exit(1);
    }
}

void load_scanf(char* string, int* location)
{
    ++g_counter;
    ++g_counter_load;
    scanf(string, location);
}

void store_printfo(char* string)
{
    ++g_counter;
    ++g_counter_store;
    printf(string);
}

void store_printft(char* string, int* location)
{
    ++g_counter;
    ++g_counter_store;
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
