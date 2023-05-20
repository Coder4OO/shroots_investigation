import statistics

file = open("shroots_data.txt", "r")
data = []
lines = file.readlines()
for line in lines:
    line = line.rstrip("\n")
    data.append(int(pow(2,int(line))))
file.close()
print("You should pay below these prices for the game:")
print("Median: %s" % statistics.median(data))
print("Mean: %s" % statistics.mean(data))
