#include <stdio.h>
#include <stdbool.h>

typedef enum {SOFT, MEDIUM, HARD} tType;

#define MINIMUMLAPS 2
#define SOFTCAP 65
#define MEDIUMCAP 75
#define HARDCAP 90
#define SAFETYCAP 30

int main() {
    int intToBool;
    int fuelLaps;
    int tirePercentage;
    int tmpType;
    bool isSafety;
    bool isRecommended;
    tType tire;

    printf("INPUT \n");
    printf("FUEL LAPS REMAINING? \n");
    scanf(" %d", &fuelLaps);
    printf("TIRE TYPE (0-SOFT , 1-MEDIUM, 2-HARD)? \n");
    scanf("%d", &tmpType);
    tire = (tType)tmpType;
    printf("TIRE WEAR PERCENTAGE (0-100)? \n");
    scanf(" %d", &tirePercentage);
    printf("IS SAFETY CAR DEPLOYED (0-FALSE, 1-TRUE)? \n");
    scanf(" %d", &intToBool);
    isSafety = (bool)intToBool;
    

    isRecommended =
       (fuelLaps < MINIMUMLAPS)
    || ((tire == SOFT  && tirePercentage > SOFTCAP)  ||
        (tire == MEDIUM && tirePercentage > MEDIUMCAP) ||
        (tire == HARD  && tirePercentage > HARDCAP))
    || (isSafety && tirePercentage > SAFETYCAP);
    
    printf("OUTPUT \n");
    printf("PIT STOP RECOMMENDED (0-FALSE, 1-TRUE): %d\n", isRecommended);

    return 0;
}