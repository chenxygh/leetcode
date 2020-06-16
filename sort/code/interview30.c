#define MAX_INT 2147483647

int min (int a, int b) {
    return a < b? a: b;
}

typedef struct {
    int min[20001];
    int stack[20001];
    int top;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj = (MinStack *) malloc (sizeof (MinStack));
    obj->top = 0;
    obj->stack[0] = obj->min[0] = MAX_INT;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    obj->stack[++obj->top] = x;
    obj->min[obj->top] = min (obj->min[obj->top - 1], x);
}

void minStackPop(MinStack* obj) {
    --obj->top;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackMin(MinStack* obj) {
    return obj->min[obj->top];
}

void minStackFree(MinStack* obj) {
    free (obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackMin(obj);
 
 * minStackFree(obj);
*/
