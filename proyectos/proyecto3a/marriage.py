import numpy as np
women  = []
men = []
engaged_dic = {}

# engaged_dic.update({1:2})
# print(engaged_dic)

t = int(input())
n = int(input())

while(len(women) < n):
    item = [int(x) for x in input().split()]
    women.append(item)

while(len(men) < n):
    item = [int(x) for x in input().split()]
    men.append(item)


#print(women)
#print(men)
print(np.matrix(women))
print(np.matrix(men))

