 #include <stdio.h>

int main() {
  // Still assume tab is align to four
  // I think one space is greater than one tab because for tab there's an extra
  // calculation.(Originally I thought like this but no tab is always better because I can process them with one logic)
  // Tab is align not just typing four tabs. it always jump to the 4(or 8) * n
  // location in the line
    int c;
    int counterSpace = 0; // This is a counter for checking how many spaces
    int location = 1;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            counterSpace++;
            if (location % 4 == 0 && counterSpace != 0) {
                putchar('\t');
                counterSpace = 0;
            }
        } else {
            while (counterSpace > 0) {
                putchar(' ');
                counterSpace--;
            }
            putchar(c);

            if(c == '\n'){
               location = 0;
            } else if (c == '\t') {
                location = location +(4 - (location - 1) % 4) - 1;
            }
        }
        location++;
    }
}
