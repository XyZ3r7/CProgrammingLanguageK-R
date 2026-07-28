#include <stdio.h>
#include <string.h>

int binsearch(int x, int a[], int n);

int main() {

}

//3-1
int binsearch(int x, int a[], int n) {
    int low, high, mid;
    low = 0;
	high = n - 1;
	mid =(low + high) / 2;
	while (low <= high && x != a[mid]){
		if(x < a[mid])
			high = mid - 1;
		else
		 	low = mid + 1;
		mid = (low + high)/2;
	}
	if(a[mid] == x){
		return mid;
	}else{
		return -1;
	}
}


//3-2
void escape(char s[], char t[]) {
	int i = 0, j = 0;
	while (t[i] != '\0') {
		switch (t[i]) {
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default:
				s[j++] = t[i];
		}
		i++;
	}
	s[j] = '\0';
}

void unescape(char s[], char t[]) {
	int i = 0, j = 0;
	while (s[j] != '\0') {
		switch (s[j]) {
			case '\\':
				if (s[j + 1] == 'n') {
					t[i++] = '\n';
					j += 2;
				}else if (s[j + 1] == 't') {
					t[i++] = '\t';
					j += 2;
				}else {
					t[i++] = '\\';
					j += 1;
				}
			default:
				t[i++] = s[j++];
				break;
		}
	}
	t[i] = '\0';
}

//3-3
void expand(char s1[], char s2[]) {
	int i = 0, j = 0;
	int prev = -1;
	int current;
	int next = -1;
	for (;i < strlen(s1); i++) {
		current = s1[i];
		if (i + 1 < strlen(s1)) next = s1[i + 1];
		else next = -1;
		switch (current) {
			case '-':
				if (prev != -1 && next != -1 && prev < next) {
					for (int c = 1;c < next - prev; c++) {
						s2[j++] = (char)(prev + c);
					}
				}else {
					s2[j++] = '-';
				}
				break;
			default:
				s2[j++] = current;
				break;
		}
		prev = current;
	}
	s2[j] = '\0';
}

void reverse(char s[]) {
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i]; s[i] = s[j]; s[j] = c;
	}
}

//3-4 just process it as unsigned int, add - sign last
void itoa(int n, char s[])
{
	unsigned int u;
	int i, sign;

	sign = n;
	if (n < 0)
		u = -(unsigned int) n;
	else
		u = n;

	i = 0;
	do {
		s[i++] = u % 10 + '0';
	} while ((u /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}