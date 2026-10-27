#include "DS.h"

/* p-ийн зааж буй Queue-д x утгыг хийнэ */
void q_push(Queue *p, int x)
{
Elm *node = malloc(sizeof(Elm));
    if (node == NULL)
        return;

    node->x = x;
    node->next = NULL;

    if (p->tail == NULL) {
        p->head = p->tail = node;
    } else {
        p->tail->next = node;
        p->tail = node;
    }

    p->len++;        /* Энд оруулах үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Queue-с гаргана */
void q_pop(Queue *p)
{
if (p->head == NULL)
        return;

    Elm *old = p->head;
    p->head = old->next;
    free(old);
    p->len--;

    if (p->head == NULL)
        p->tail = NULL;        /* Энд гаргах үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй Queue-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void q_print(Queue *p)
{
 Elm *current = p->head;

    while (current != NULL) {
        printf("%d\n", current->x);
        current = current->next;
    }        /* Энд хэвлэх үйлдлийг хийнэ үү */
}
