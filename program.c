#include <stdio.h>

int main() {

    int choix;

    double altitude;
    double pressure;
    double pressure_altitude;

    double ias;
    double tas;

    double headwind;
    double ground_speed;

    double fuel;
    double consumption;
    double range;

    double weight;
    double wing_surface;
    double wing_loading;

    double temperature;
    double rate_of_climb;

    printf("1 - Altitude-pression\n");
    printf("2 - Vitesse vraie (TAS)\n");
    printf("3 - Vitesse-sol\n");
    printf("4 - Distance franchissable\n");
    printf("5 - Charge alaire\n");
    printf("6 - Taux de montee\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    if (choix == 1) {

        do {
            printf("Altitude [0 - 19500] ft : ");
            scanf("%lf", &altitude);
        } while (altitude < 0 || altitude > 19500);

        do {
            printf("Pression [300 - 1050] hPa : ");
            scanf("%lf", &pressure);
        } while (pressure < 300 || pressure > 1050);

        pressure_altitude = altitude + (1023 - pressure) * 30;

        printf("Altitude-pression : %.2f ft\n", pressure_altitude);
    }

    if (choix == 2) {

        do {
            printf("IAS [0 - 500] kts : ");
            scanf("%lf", &ias);
        } while (ias < 0 || ias > 500);

        do {
            printf("Altitude-pression (ft) : ");
            scanf("%lf", &pressure_altitude);
        } while (pressure_altitude < 0);

        tas = ias * (1 + 2 * pressure_altitude / 1000);

        printf("TAS : %.2f kts\n", tas);
    }

    if (choix == 3) {

        do {
            printf("TAS (kts) : ");
            scanf("%lf", &tas);
        } while (tas <= 0);

        printf("Vent de face (kts, negatif si vent arriere) : ");
        scanf("%lf", &headwind);

        ground_speed = tas - headwind;

        printf("Vitesse-sol : %.2f kts\n", ground_speed);
    }

    if (choix == 4) {

        do {
            printf("Carburant [20 - 350000] L : ");
            scanf("%lf", &fuel);
        } while (fuel < 20 || fuel > 350000);

        do {
            printf("Consommation [10 - 15000] L/h : ");
            scanf("%lf", &consumption);
        } while (consumption < 10 || consumption > 15000);

        do {
            printf("Vitesse-sol (kts) : ");
            scanf("%lf", &ground_speed);
        } while (ground_speed <= 0);

        range = fuel * ground_speed * 1.852 / consumption;

        printf("Distance franchissable : %.2f km\n", range);
    }

    if (choix == 5) {

        do {
            printf("Poids [500 - 600000] kg : ");
            scanf("%lf", &weight);
        } while (weight < 500 || weight > 600000);

        do {
            printf("Surface alaire [5 - 900] m2 : ");
            scanf("%lf", &wing_surface);
        } while (wing_surface < 5 || wing_surface > 900);

        wing_loading = weight / wing_surface;

        printf("Charge alaire : %.2f kg/m2\n", wing_loading);
    }

    if (choix == 6) {

        do {
            printf("Altitude-pression (ft) : ");
            scanf("%lf", &pressure_altitude);
        } while (pressure_altitude < 0);

        do {
            printf("Temperature (C) : ");
            scanf("%lf", &temperature);
        } while (temperature < -50 || temperature > 50);

        rate_of_climb = 700 * (1 - pressure_altitude / 10000);

        if (temperature > 15) {
            rate_of_climb = rate_of_climb * (1 - 0.01 * (temperature - 15));
        }

        printf("Taux de montee : %.2f ft/min\n", rate_of_climb);
    }

    return 0;
}
