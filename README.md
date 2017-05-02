#Algorithm_HW2
## make two subset get a same sum
### using KnapSack_Problem


## Algorithm

if input 1,2,3,4,5,6,7
default value : arr[0] = 1
and arr[1~n] = 0;
sum = 1+2+3+4+5+6+7 = 28

j = 1 + 0
j -> 1 ~ 0
arr[j + 1] = arr[j + 1] + arr[j]

next -> 
j = 1 + 2
j -> 3 ~ 0
arr[j + 2] = arr[j + 2] + arr[j]

next -> 
j = 3 + 3
j -> 6 ~ 0
arr[j + 3] = arr[j + 3] + arr[j]

....
