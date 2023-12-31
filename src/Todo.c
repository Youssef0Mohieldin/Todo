#include<Todo_api.h>




todo_t *todos_create(char* msg, bool is_important, time_t deadline){
    static int next_id = 1;
    todo_t *ret_todo = malloc(sizeof(todo_t));
    if (msg == NULL || ret_todo == NULL)
        return NULL;

    

    ret_todo->id = next_id++;
    ret_todo->msg = msg;
    ret_todo->is_important = is_important;
    ret_todo->deadline = deadline;
    ret_todo->date_created = time(NULL); // the NULL gets the time now
    
    todos_len += 1;

    return ret_todo;
}


status_t todos_delete(int id){
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


status_t todos_get_all(todo_t ***ret_to, int *len_ret) {
    *ret_to = malloc(todos_get_num() * sizeof(todo_t *));
    if (*ret_to == NULL) {
        return status_NOK;
    }
    for (int i = 0; i < todos_get_num; i++) {
        (*ret_to)[i] = &todos[i];
    }
    *len_ret = todos_get_num();
    return status_OK;
}
status_t todos_get_important(todo_t ***ret_to);
status_t todos_set_important(int id);

int todos_get_num(){
    return todos_len;
}

