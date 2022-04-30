/* Exchange function */

#ifndef EXCHANGE_H_ 
#define EXCHANGE_H_

// Swap the values of two variables
void exchange(float *x1, float *x2) {
    float temp = *x1;
    *x1 = *x2;
    *x2 = temp;
}

#endif /* EXCHANGE_H_ */
