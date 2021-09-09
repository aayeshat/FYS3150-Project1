import matplotlib.pyplot as plt

X, Y = [], []
for line in open('x_y.txt', 'r'):
  values = [float(s) for s in line.split()]
  X.append(values[0])
  Y.append(values[1])

plt.plot(X, Y)

plt.title("problem 2 ", fontsize=10)
plt.ylabel("u(x)")
plt.xlabel("x")
# plt.xscale("x")
# plt.yscale("u(x)")
plt.savefig("plot problem 2.pdf")

plt.show()