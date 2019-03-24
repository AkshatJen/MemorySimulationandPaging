#include "lib/myfunctions.h"
#include "lib/consts.h"
#include <stdio.h>

int main(){

        //https://www.quora.com/What-is-the-difference-between-char*-and-char
        //https://www.geeksforgeeks.org/whats-difference-between-char-s-and-char-s-in-c/
        char *physical_memory = get_physical_memory(TOTAL_MEMORY);
        hey_printf_print_this("---allocating total memory---");

        // hard_drive_memory = same as pte size ie (only 2 pages)
        char *hard_drive_memory = get_page_table_memory(HARD_DRIVE_MEMORY);
        hey_printf_print_this("---allocating hard drive memory---");

        char *page_table = get_page_table_memory(PAGE_TABLE_ENTRY_SIZE);

        // could make above func with 2 arguments to do this
        //printf("---allocating page table entry size---%5hu\n", PAGE_TABLE_ENTRY_SIZE);

        //get_rand(LOWEST_RAND,HIGHEST_RAND);
        hey_printf_print_this("---randomness is in my drivers---");

        put_physical_memory(PHYSICAL_MEMORY_LOCATION , physical_memory , TOTAL_MEMORY);
        hey_printf_print_this("---creating your physical_memory.txt---");

        put_page_table(PAGE_TABLE_LOCATION);
        hey_printf_print_this("---creating your page_table.txt---");

        put_hard_drive_memory_table(HARD_DRIVE_MEMORY_LOCATION, hard_drive_memory , HARD_DRIVE_MEMORY,LOWEST_ASCII,HIGHEST_ASCII);

        free_that_memory(physical_memory);
        hey_printf_print_this("---physical_memory freed---");

        free_that_memory(hard_drive_memory);
        hey_printf_print_this("---hard_drive_memory freed---");

        free_that_memory(page_table);
        hey_printf_print_this("---page_table memory freed");
        return 0;
}
