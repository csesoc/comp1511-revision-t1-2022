#include <stdio.h>
#include <stdlib.h>

struct transaction {
    int amount;
    int sender;
};

int main (void) {
    struct transaction *trans[1000] = {0};
    int t, r;
    scanf("%d %d", &t, &r);

    for (int i = 0; i < t; i++) {
        int id, amount;
        char sender;
        scanf("%d %d %c", &id, &amount, &sender);
        struct transaction *new = malloc(sizeof(struct transaction));
        new->amount = amount;
        new->sender = sender;
        trans[id] = new;
    }

    for (int i = 0; i < r; i++) {
        int id;
        scanf("%d", &id);
        trans[id] = NULL;
    }

    int bBalance = 100;
    for (int i = 0; i < 1000; i++) {
        if (trans[i] == NULL) continue;
        bBalance += trans[i]->amount * ((trans[i]->sender == 'B') ? -1 : 1);
    }

    printf("%d %d\n", bBalance, 200 - bBalance);

}
