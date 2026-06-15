#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "functions.h"
#include "data.h"

double weightedSum(int neuronIndex, double *polePixelov) {
    double sum = bias[neuronIndex];
    int offset = neuronIndex * IMAGE_SIZE;
    for (int i = 0; i < IMAGE_SIZE; i++) {
        sum += weights[offset + i] * polePixelov[i];
    }
    return sum;
}

void softMax(double *vystupy, double *pravdepodobnost) {
    double max_hodnota = vystupy[0];
    for (int i = 1; i < NUMBER_OF_NEURONS; i++) {
        if (vystupy[i] > max_hodnota) { max_hodnota = vystupy[i]; }
    }
    double sucet_exp = 0.0;
    for (int i = 0; i < NUMBER_OF_NEURONS; i++) {
        pravdepodobnost[i] = exp(vystupy[i] - max_hodnota);
        sucet_exp += pravdepodobnost[i];
    }
    for (int i = 0; i < NUMBER_OF_NEURONS; i++) {
        pravdepodobnost[i] /= sucet_exp;
    }
}

int findMax(double *pole) {
    int index = 0;
    for (int i = 1; i < NUMBER_OF_NEURONS; i++) {
        if (pole[i] > pole[index]) {index = i; }
    }
    return index;
}

int main(void) {
    int rezim;
    scanf("%d", &rezim);

    if (rezim == 1) {
        int neuron;
        scanf("%d", &neuron);
        int offset = neuron * IMAGE_SIZE;
        for (int i = 0; i < IMAGE_SIZE; i++) {
            printf("%6.2f", weights[offset + i]);
            if ((i + 1) % 10 == 0) printf("\n");
            else printf(" ");
        }

    } else if (rezim == 2) {
        int neuron;
        scanf("%d", &neuron);
        double obrazok[IMAGE_SIZE];
        load_data(obrazok, IMAGE_SIZE);
        printf("%.2f\n", weightedSum(neuron, obrazok));

    } else if (rezim == 3) {
        double hodnota;
        scanf("%lf", &hodnota);
        printf("%.2f\n", relu(hodnota));

    } else if (rezim == 4) {
        double vystupy[NUMBER_OF_NEURONS];
        double pravdepodobnosti[NUMBER_OF_NEURONS];
        for (int i = 0; i < NUMBER_OF_NEURONS; i++) scanf("%lf", &vystupy[i]);
        softMax(vystupy, pravdepodobnosti);
        for (int i = 0; i < NUMBER_OF_NEURONS; i++) {
            if (i > 0) printf(" ");
            printf("%.2f", pravdepodobnosti[i]);
        }
        printf("\n");

    } else if (rezim == 5) {
        double pole[NUMBER_OF_NEURONS];
        for (int i = 0; i < NUMBER_OF_NEURONS; i++) scanf("%lf", &pole[i]);
        printf("%d\n", findMax(pole));

    } else if (rezim == 6) {
        double obrazok[IMAGE_SIZE];
        load_data(obrazok, IMAGE_SIZE);
        print_image(obrazok, IMAGE_WIDTH, IMAGE_HEIGHT);

    } else if (rezim == 7) {
        double obrazok[IMAGE_SIZE];
        load_data(obrazok, IMAGE_SIZE);
        double aktivacie[NUMBER_OF_NEURONS];
        for (int i = 0; i < NUMBER_OF_NEURONS; i++) {
            aktivacie[i] = relu(weightedSum(i, obrazok));
        }
        double pravdepodobnosti[NUMBER_OF_NEURONS];
        softMax(aktivacie, pravdepodobnosti);
        printf("%d\n", findMax(pravdepodobnosti));
    }

    return 0;
}