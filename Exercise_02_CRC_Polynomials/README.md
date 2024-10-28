# Exercise 2: Implement the Three CRC Polynomials on a Data Set of Characters – CRC 12, CRC 16, and CRC CCIP

Cyclic Redundancy Check (CRC) is a method that can detect a single burst of length **n**, since only one bit per column will be changed. A burst of length **n+1** can pass undetected if the first bit is inverted, the last bit is inverted, and all other bits are correct. If the block is badly garbled by a long burst or multiple shorter bursts, the probability that any of the **n** columns will have the correct parity is **0.5**. Hence, the probability of a bad block being accepted when it should not is **2^(-n)**. This scheme is known as the **Cyclic Redundancy Code (CRC)**.

## Program for Cyclic Redundancy Check (CRC)

```c
#include <stdio.h>

int gen[4], genl, frl, rem[4];

void calc_remainder(int fr[]);

int main() {
    int i, j, fr[8], dupfr[11], recfr[11], tlen, flag;
    
    frl = 8;   // Frame length
    genl = 4;  // Generator length

    // Input Frame
    printf("Enter frame: ");
    for (i = 0; i < frl; i++) {
        scanf("%d", &fr[i]);
        dupfr[i] = fr[i];
    }

    // Input Generator
    printf("Enter generator: ");
    for (i = 0; i < genl; i++) {
        scanf("%d", &gen[i]);
    }

    tlen = frl + genl - 1;  // Total length

    // Append 0s to the frame
    for (i = frl; i < tlen; i++) {
        dupfr[i] = 0;
    }

    // Calculate remainder for the duplicate frame
    calc_remainder(dupfr);

    // Copy the frame to the received frame
    for (i = 0; i < frl; i++) {
        recfr[i] = fr[i];
    }

    // Append the remainder to the received frame
    for (i = frl, j = 1; j < genl; i++, j++) {
        recfr[i] = rem[j];
    }

    // Recalculate the remainder for the received frame
    calc_remainder(recfr);

    // Check for errors in the received frame
    flag = 0;
    for (i = 0; i < genl; i++) {
        if (rem[i] != 0)
            flag++;
    }

    // Output the result
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
```

**Output**:

```bash
Enter frame: 1
1
1
1
1
1
1
1
Enter generator: 1
1
0 
1
Frame received correctly
```

This program simulates the **CRC method** to detect errors in data frames by calculating and checking calc_remainders based on a given generator polynomial. It demonstrates how to implement **Cyclic Redundancy Check** for data validation.
