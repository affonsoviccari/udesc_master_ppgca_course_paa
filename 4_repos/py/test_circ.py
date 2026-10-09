i = 0
limit = 5
for j in range(10):
    print(i)
    i = (i+1)%limit
print('='*40)
i = 0
limit = 5
for j in range(10):
    i = (i-1)%limit
    print(i)
    