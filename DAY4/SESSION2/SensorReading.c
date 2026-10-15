
#include <stdio.h>

union Value {
    float temperature;
    char door;
    long pulses;
};

struct Reading {
    int sensorID;
    char kind;
    union Value value;
};

struct AllFields {
    int sensorID;
    char kind;
    float temperature;
    char door;
    long pulses;
};

int main() {
    int n, i;
    struct Reading readings[1000];

    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("INVALID COUNT\n");
        return 0;
    }

    // Read and validate all sensor readings
    for (i = 0; i < n; i++) {
        scanf("%d %c", &readings[i].sensorID,
              &readings[i].kind);

        if (readings[i].kind == 'T') {
            scanf("%f", &readings[i].value.temperature);
        } else if (readings[i].kind == 'D') {
            scanf(" %c", &readings[i].value.door);

            if (readings[i].value.door != 'O' &&
                readings[i].value.door != 'C') {
                printf("INVALID KIND\n");
                return 0;
            }
        } else if (readings[i].kind == 'P') {
            scanf("%ld", &readings[i].value.pulses);
        } else {
            printf("INVALID KIND\n");
            return 0;
        }
    }

    printf("SENSOR REPORT\n");

    for (i = 0; i < n; i++) {
        switch (readings[i].kind) {
            case 'T':
                printf("Sensor %d temperature %.2f C\n",
                       readings[i].sensorID,
                       readings[i].value.temperature);
                break;

            case 'D':
                if (readings[i].value.door == 'O') {
                    printf("Sensor %d door OPEN\n",
                           readings[i].sensorID);
                } else {
                    printf("Sensor %d door CLOSED\n",
                           readings[i].sensorID);
                }
                break;

            case 'P':
                printf("Sensor %d pulses %ld\n",
                       readings[i].sensorID,
                       readings[i].value.pulses);
                break;
        }
    }

    printf("sizeof(union Value): %lu\n",
           (unsigned long)sizeof(union Value));

    printf("sizeof(Reading) with union: %lu\n",
           (unsigned long)sizeof(struct Reading));

    printf("sizeof(Reading) with all fields: %lu\n",
           (unsigned long)sizeof(struct AllFields));

    printf("Bytes saved per record: %ld\n",
           (long)(sizeof(struct AllFields) -
                 sizeof(struct Reading)));

    return 0;
}
