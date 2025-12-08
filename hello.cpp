bool push_forward(subforwardlist** sfl, int d) {
    if (sfl == nullptr) {
        return false;
    }
    if (*sfl == NULL) {
        *sfl = new subforwardlist;
        (*sfl)->data = d;
        (*sfl)->next = *sfl;
        return true;
    }
    subforwardlist* new_h = new subforwardlist;
    new_h->data = d;
    new_h->next = *sfl;
    sfl = &new_h;
    return true;
}

subforwardlist* a = new subforwardlist;
push_forward(&a, 5);