#include <stdio.h>
#include <stdlib.h>


int encode(int h, int m){
    int ergebnis = 0;

        ergebnis = h*100 + m;

    return ergebnis;
}


int read(){
    int h = 0;
    int m = 0;
    int ergebnis = 0;

        printf("hours: ");
        scanf("%d", &h);
        printf("minutes: ");
        scanf("%d", &m);

            ergebnis = h*100 + m;

    return ergebnis;
}


int hours(int t){

    int counterHundert = 0;
    int counterTausend = 0;
    int neueSumme = 0;

    while(t >= 1000){
        t = t - 1000;
        ++counterTausend;
    }
    while(t >= 100){
        t = t - 100;
        ++counterHundert;
    }

        neueSumme = (counterTausend*10) + counterHundert;

    return neueSumme;
}

int minutes(int t){

    int counterZehner = 0;
    int neueSumme = 0;

    while(t >= 1000){
        t = t - 1000;
    }
    while(t >= 100){
        t = t - 100;
    }
    while(t >= 10){
        t = t - 10;
        ++counterZehner;
    }

        neueSumme = (counterZehner*10) + t;

    return neueSumme;
}


void print(int t){

    int counterHundert = 0;
    int counterTausend = 0;
    int counterZehner = 0;
    int neueStunden = 0;
    int neueMinuten = 0;

    while(t >= 1000){
        t = t - 1000;
        ++counterTausend;
    }
    while(t >= 100){
        t = t - 100;
        ++counterHundert;
    }
    while(t >= 10){
        t = t - 10;
        ++counterZehner;
    }

        neueStunden = (counterTausend*10) + counterHundert;
        neueMinuten = (counterZehner*10) + t;

    printf("%02d:%02d", neueStunden, neueMinuten);
}

int add(int t1, int t2){

    int counterHundert = 0;
    int counterTausend = 0;
    int counterZehner = 0;
    int neueStunden1 = 0;
    int neueMinuten1 = 0;
    int neueStunden2 = 0;
    int neueMinuten2 = 0;
    int ergebnis = 0;

    while(t1 >= 1000){
        t1 = t1 - 1000;
        ++counterTausend;
    }
    while(t1 >= 100){
        t1 = t1 - 100;
        ++counterHundert;
    }
    while(t1 >= 10){
        t1 = t1 - 10;
        ++counterZehner;
    }

        neueStunden1 = (counterTausend*10) + counterHundert;
        neueMinuten1 = (counterZehner*10) + t1;

    counterTausend = 0;
    counterHundert = 0;
    counterZehner = 0;

    while(t2 >= 1000){
        t2 = t2 - 1000;
        ++counterTausend;
    }
    while(t2 >= 100){
        t2 = t2 - 100;
        ++counterHundert;
    }
    while(t2 >= 10){
        t2 = t2 - 10;
        ++counterZehner;
    }

        neueStunden2 = (counterTausend*10) + counterHundert;
        neueMinuten2 = (counterZehner*10) + t2;

            neueStunden2 = neueStunden2 + neueStunden1;
            neueMinuten2 = neueMinuten2 + neueMinuten1;

                if(neueStunden2 >= 24){
                    neueStunden2 = neueStunden2 - 24;
                }
                if(neueMinuten2 >= 60){
                    neueMinuten2 = neueMinuten2 - 60;
                    neueStunden2++;
                }

            ergebnis = neueStunden2*100 + neueMinuten2;

    return ergebnis;
}


int total_minutes(int t){

    int counterHundert = 0;
    int counterTausend = 0;
    int neueStunden = 0;
    int ergebnis = 0;

    while(t >= 1000){
        t = t - 1000;
        ++counterTausend;
    }
    while(t >= 100){
        t = t - 100;
        ++counterHundert;
    }

        neueStunden = (counterTausend*10) + counterHundert;

            ergebnis = (neueStunden*60) + t;

    return ergebnis;
}


/* D O N T   T O U C H   T H I S */
void Test_1() {
    int h, m;
    printf("h: ");
    scanf("%d", &h);
    printf("m: ");
    scanf("%d", &m);
    printf("encoded: %04d", encode(h, m));
}

void Test_2() {
    printf("read: %04d", read());
}

void Test_3() {
    int t;
    printf("hours: %02d\n", hours(t = read()));
    printf("minutes: %02d\n", minutes(t));
}

void Test_4() {
    print(read());
}

void Test_5() {
    int t1 = read();
    int t2 = read();
    printf("add: ");
    print(t1);
    printf(" + ");
    print(t2);
    printf(" = ");
    print(add(t1, t2));
}

void Test_6() {
    int t = read();
    printf("read: %d\n", total_minutes(t));
}

int main() {
    /* Input */
    int num;
    /* List of all available tests */
    void (*tests[])() = { Test_1, Test_2, Test_3, Test_4, Test_5, Test_6 };
    int num_of_tests = (int)(sizeof(tests) / sizeof(void (*)()));

    /* Read test number */
    printf("Test #: ");
    scanf("%d", &num);

    /* Check valid range */
    if (num >= 1 && num <= num_of_tests) {
        /* Call the selected test */
        printf("Executing Test_%d.\n", num);
        tests[num - 1]();
    } else {
        /* Print error */
        printf("Invalid test number!");
    }

    return 0;
}
