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

    return ret_todo;
}


status_t todos_delete(int id){

}


status_t todos_get_all(todo_t **ret_to, int *len);
status_t todos_get_important(todo_t *ret_to);
status_t todos_set_important(int id);
