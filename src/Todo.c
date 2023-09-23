#include<Todo_api.h>




todo_t todos_create(char* msg, bool is_important, time_t deadline){

}
status_t todos_delete(int id, todo_t * ret_to);
status_t todos_get_all(todo_t **ret_to, int *len);
status_t todos_get_important(todo_t *ret_to);
status_t todos_set_important(int id);
