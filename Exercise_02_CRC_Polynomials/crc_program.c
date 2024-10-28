#include <stdio.h>

int gen[4], genl, frl, rem[4];

// Function declaration for the calc_remainder
void calc_remainder(int fr[]);

int main() {
    int i, j, fr[8], dupfr[11], recfr[11], tlen, flag;
    
    // Setting frame and generator lengths
    frl = 8;
    genl = 4;

    // Input frame
    printf("Enter frame: ");
    for (i = 0; i < frl; i++) {
        scanf("%d", &fr[i]);
        dupfr[i] = fr[i];
    }

    // Input generator
    printf("Enter generator: ");
    for (i = 0; i < genl; i++) {
        scanf("%d", &gen[i]);
    }

    // Calculate total length of the transmitted frame
    tlen = frl + genl - 1;

    // Padding with zeros
    for (i = frl; i < tlen; i++) {
        dupfr[i] = 0;
    }

    // Call to calc_remainder function to get the calc_remainder for the transmitted frame
    calc_remainder(dupfr);

    // Copy frame to recfr
    for (i = 0; i < frl; i++) {
        recfr[i] = fr[i];
    }

    // Append calc_remainder to the received frame
    for (i = frl, j = 1; j < genl; i++, j++) {
        recfr[i] = rem[j];
    }

    // Call to calc_remainder function for the received frame
    calc_remainder(recfr);

    // Checking if the received frame is correct
    flag = 0;
    for (i = 0; i < genl; i++) {
        if (rem[i] != 0)
            flag++;
    }

    if (flag == 0) {
        printf("Frame received correctly\n");
    } else {
        printf("The received frame is wrong\n");
    }

    return 0;
}

void calc_remainder(int fr[]) {
    int k, k1, i, j;
    
    for (k = 0; k < frl; k++) {
        if (fr[k] == 1) {
            k1 = k;
            for (i = 0, j = k; i < genl; i++, j++) {
                rem[i] = fr[j] ^ gen[i];
            }
            for (i = 0; i < genl; i++) {
                fr[k1] = rem[i];
                k1++;
            }
        }
    }
}
