### - stands for spaces
### 1:
(a): ----86,1040
#### (b): -3.02530e+01 12 -> space + 11, .5 -> 02530
(c) 83.1620
#### (d) 1e-06- .2 means round to 2 valid numbers, therefore 0.0000009979 -> 0.00000010 -> to e = 1e-06 
### 2:
printf("%-8.1e", x);  
printf("%10.6e", x);  
printf("%-8.3f", x);  
printf("%6.0f", x);  
### 3:
(a) no difference (space in format String made scanf skip all white spaces until reach first non-white spaces)  
(b) there is difference, %d-%d doesn't allow spaces in front - (%d can skip spaces so it works with 3-  4)
(c) no difference  
(d) There is difference, similar to b  
### 4:
i = 10, x = 0.3, j = 5  
### 5:
x = 12.3, i = 45, y = 0.6
### 6:
Just add spaces before /  
