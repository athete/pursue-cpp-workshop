max_num = 10000

for i in range(max_num):
    if i == 50:
        break
    if i % 2 == 0:
        continue
    print(i)

print("End of loop!")