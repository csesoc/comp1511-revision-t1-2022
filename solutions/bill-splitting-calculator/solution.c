#include <stdio.h>

int main(void) {
    int kmTravelled;
    scanf("%d", &kmTravelled);

    double fuelPrice;
    scanf("%lf", &fuelPrice);

    int numFriends;
    scanf("%d", &numFriends);

    double billCost;
    scanf("%lf", &billCost);

    double fuelCost = (double) kmTravelled * fuelPrice;

    double costPerPerson = (fuelCost + billCost) / (double) numFriends;
    printf("$%0.2lf\n", costPerPerson);

    return 0;
}