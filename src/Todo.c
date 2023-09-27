#include "Todo_api.h"




status_t todos_create(todo_t **todo, char *msg, bool is_important, time_t deadline)
{
    static int next_id = 1;
    if (msg == NULL)
        return status_NOK;
    if((*todo) == NULL)
    {
        printf("create:if\n");

        *todo = malloc(sizeof(todo_t));
        (*todo)->id = next_id++;
        (*todo)->is_done = false;
        (*todo)->is_important = is_important;
        (*todo)->msg = msg;
        (*todo)->deadline = deadline;
        (*todo)->date_created = time(NULL);
        printf("id after creating:%d\n", (*todo)->id);
    }
    else
    {
        printf("create: else %d \n", (*todo)->id);
        (*todo)->next = malloc(sizeof(todo_t));
        (*todo)->next->id = next_id++;
        (*todo)->next->is_done = false;
        (*todo)->next->is_important = is_important;
        (*todo)->next->msg = msg;
        (*todo)->next->deadline = deadline;
        (*todo)->next->date_created = time(NULL);
    }

    return status_OK;
}
/* 
status_t todos_delete(int id)
{
    for (int i = 0; i < todos_get_num(); i++)
    {
        if (todos[i]->id == id)
        {
            free(todos[i]->msg);
            free(todos[i]);
            shift_removal(todos, i, todos_get_num());
            todos_len -= 1;
            return status_OK;
        }
    }
    return status_NOK;
}

// TODO
status_t todos_get_all(todo_t **ret_to, int *len_ret)
{
    
}
status_t todos_get_important(todo_t ***ret_to);
status_t todos_set_important(int id);

int todos_get_num()
{
    return todos_len;
}
 */


status_t todos_get_by_id(todo_t *todo, int id, todo_t *ret_to)
{
    while (todo->next != NULL)
    {
        printf("id=%d", id);
        if(todo->id == id){
            ret_to = todo;
            return status_OK;
        }
        else{
            todo = todo->next;
        }
    }
    return status_NOK;
}
