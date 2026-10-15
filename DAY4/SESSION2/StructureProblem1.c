
#include <stdio.h>

struct Address {
    char village[50];
    int pincode;
};

struct Member {
    int id;
    char name[50];
    float share_capital;
    struct Address address;
};

int main() {
    struct Member members[200];
    int n, i, highest = 0;
    float total = 0.0;

    scanf("%d", &n);

    if (n <= 0 || n > 200) {
        printf("INVALID COUNT\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        scanf("%d %49s %f %49s %d",
              &members[i].id,
              members[i].name,
              &members[i].share_capital,
              members[i].address.village,
              &members[i].address.pincode);

        total += members[i].share_capital;

        if (members[i].share_capital >
            members[highest].share_capital) {
            highest = i;
        }
    }

    printf("MEMBER LEDGER\n");

    for (i = 0; i < n; i++) {
        printf("%d %s %s %d %.2f\n",
               members[i].id,
               members[i].name,
               members[i].address.village,
               members[i].address.pincode,
               members[i].share_capital);
    }

    printf("Total share capital (Rs): %.2f\n", total);

    printf("Highest holder: %d %s %s\n",
           members[highest].id,
           members[highest].name,
           members[highest].address.village);

    printf("%d %.2f\n",
           members[highest].address.pincode,
           members[highest].share_capital);

    return 0;
}
