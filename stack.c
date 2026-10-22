#include "DS.h"
#include <stdio.h>
#include <stdlib.h>
/*
  p-ийн зааж буй Stack-т x утгыг оруулна
 */
void s_push(Stack *p, int x)
{
 Elm *node = malloc(sizeof(Elm));
    if (node == NULL)
        return;

    node->x = x;
    node->next = p->top;
    p->top = node;
    p->len++;        /* Энд оруулах үйлдлийг хийнэ үү */
}
/*
  p-ийн зааж буй Stack-аас гарах функц
 */
void s_pop(Stack *p)
{
 if (p->top == NULL)
        return;

    Elm *old = p->top;
    p->top = old->next;
    free(old);
    p->len--;        /* Энд гаргах үйлдлийг хийнэ үү */
}
/*
    p-ийн зааж буй Stack-д байгаа элементүүдийг хэвлэх функц.
    Хамгийн сүүлд орсон элементээс эхлэн дарааллаар, нэг мөрөнд
    нэг л элемент хэвлэнэ.
 */
void s_print(Stack *p)
{
Elm *current = p->top;

    while (current != NULL) {
        printf("%d\n", current->x);
        current = current->next;
    }        /* Энд хэвлэх үйлдлийг хийнэ үү */
}
