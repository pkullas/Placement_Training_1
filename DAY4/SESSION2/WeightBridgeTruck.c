
#include <stdio.h>
#include <stdlib.h>

struct Ticket {
    int ticketNo;
    char vehicleNo[30];
    float grossWeight;
    float tareWeight;
};

// Helper function 1: Calculate net weight
float getNetWeight(struct Ticket *t) {
    return t->grossWeight - t->tareWeight;
}

// Helper function 2: Print ticket details
void printTicket(struct Ticket *t) {
    printf("%d %s gross %.2f tare %.2f\n",
           t->ticketNo,
           t->vehicleNo,
           t->grossWeight,
           t->tareWeight);

    printf("net %.2f\n", getNetWeight(t));
}

int main() {
    int n, i, heaviest = 0;
    float totalNet = 0.0;

    scanf("%d", &n);

    if (n <= 0 || n > 100000) {
        printf("INVALID COUNT\n");
        return 0;
    }

    struct Ticket *tickets =
        (struct Ticket *)malloc(n * sizeof(struct Ticket));

    if (tickets == NULL) {
        return 0;
    }

    for (i = 0; i < n; i++) {
        scanf("%d %29s %f %f",
              &tickets[i].ticketNo,
              tickets[i].vehicleNo,
              &tickets[i].grossWeight,
              &tickets[i].tareWeight);

        totalNet += getNetWeight(&tickets[i]);

        if (i == 0 ||
            getNetWeight(&tickets[i]) >
            getNetWeight(&tickets[heaviest])) {
            heaviest = i;
        }
    }

    printf("WEIGHBRIDGE DAY BOOK\n");

    for (i = 0; i < n; i++) {
        printTicket(&tickets[i]);
    }

    printf("Tickets: %d\n", n);
    printf("Total net weight (kg): %.2f\n", totalNet);

    printf("Heaviest net load: ticket %d %s\n",
           tickets[heaviest].ticketNo,
           tickets[heaviest].vehicleNo);

    printf("%.2f\n", getNetWeight(&tickets[heaviest]));

    free(tickets);

    return 0;
}