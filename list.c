#include "DS.h"

/* p-ийн зааж буй List-д x утгыг төгсгөлд хийнэ */
void l_push_back(List *p, int x)
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

    p->len++;	/* Энд оруулах үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй List-д x утгыг эхэнд хийнэ
   Бүх элементүүд нэг нэг байрлал хойшилно.
 */
void l_push_front(List *p, int x)
{
Elm *node = malloc(sizeof(Elm));
    if (node == NULL)
        return;

    node->x = x;
    node->next = p->head;
    p->head = node;

    if (p->tail == NULL)
        p->tail = node;

    p->len++;	/* Энд оруулах үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
  pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
  Тухайн байрлал List-ийн сүүлийн индексээс их бол төгсгөлд орно.
 */
void l_insert(List *p, int x, int pos)
{
 if (pos <= 0) {
        l_push_front(p, x);
        return;
    }

    if (pos >= p->len) {
        l_push_back(p, x);
        return;
    }

    Elm *node = malloc(sizeof(Elm));
    if (node == NULL)
        return;

    Elm *current = p->head;

    for (int i = 0; i < pos - 1; i++)
        current = current->next;

    node->x = x;
    node->next = current->next;
    current->next = node;
    p->len++;
	/* Энд оруулах үйлдлийг хийнэ үү */
}


/*
  p-ийн зааж буй List-н эхлэлээс гаргана.
  List-ийн бүх элементүүд нэг нэг байрлал урагшилна
 */
void l_pop_front(List *p)
{
if (p->head == NULL)
        return;

    Elm *old = p->head;
    p->head = old->next;
    free(old);
    p->len--;

    if (p->head == NULL)
        p->tail = NULL;	/* Энд гаргах үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй List-н төгсгөлөөс гаргана */
void l_pop_back(List *p)
{
if (p->head == NULL)
        return;

    if (p->head == p->tail) {
        free(p->head);
        p->head = p->tail = NULL;
        p->len = 0;
        return;
    }

    Elm *current = p->head;

    while (current->next != p->tail)
        current = current->next;

    free(p->tail);
    p->tail = current;
    p->tail->next = NULL;
    p->len--;	/* Энд гаргах үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй List-н pos байрлалаас гаргана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
   pos байрлалаас гарах боломжгүй бол юу ч хийхгүй.
 */
void l_erase(List *p, int pos)
{
 if (pos < 0 || pos >= p->len)
        return;

    if (pos == 0) {
        l_pop_front(p);
        return;
    }

    Elm *current = p->head;

    /* current нь pos - 1 байрлалын элемент болно */
    for (int i = 0; i < pos - 1; i++)
        current = current->next;

    Elm *old = current->next;
    current->next = old->next;

    if (old == p->tail)
        p->tail = current;

    free(old);
    p->len--;	/* Энд гаргах үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй List-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void l_print(List *p)
{
Elm *current = p->head;

    while (current != NULL) {
        printf("%d\n", current->x);
        current = current->next;
    }        /* Энд хэвлэх үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй List-с x тоог хайн олдсон хаягийг буцаана.
  Олдохгүй бол NULL хаяг буцаана.
 */
Elm *l_search(List *p, int x)
{
Elm *current = p->head;

    while (current != NULL) {
        if (current->x == x)
            return current;

        current = current->next;
    }

    return NULL;	
}
