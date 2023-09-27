#include <stdio.h>
#include <time.h>
#include "utils.h"
#include "Todo_api.h"
#include<windows.h>


todo_t *head = NULL;
void print_no_todos_options();
void print_todos_options();

int main(int argc, char *argv[])
{
    int option;
    char t[] = "s";
    todos_create(&head, t, false, time(NULL));

    printf("id is:%d\n", head->id);
    
    todo_t ret_to;    
    status_t s = todos_get_by_id(head, 1, &ret_to);
    if (s == status_OK)
    {
        printf("found\n");
        printf("%d\n", ret_to.id);
    }else{
        printf("not found\n");
    }

}


void handle_input(char *ret_to, screen_t screen){
get_input:
    scanf("%d", ret_to);
    if (screen == NO_TODOS_SCREEN && *ret_to >2)
    {
        printf("[!]\a invalid input.\n");
        goto get_input;
    }
    if (screen == TODOS_SCREEN && *ret_to >3)
    {
        printf("[!]\a invalid input.\n");
        goto get_input;
    }
    
    
}


void print_no_todos_options(){
    printf("[1] create a new todo.\n");
    printf("[2] exit.\n");
}


void print_todos_options(){
    printf("[1] show daily tasks.\n");
    printf("[2] show weekly tasks.\n");
    printf("[3] exit.\n");
}