import numpy as np
import matplotlib.pyplot as plt

#
# Read data into numpy arrays
#

h, d2u_approx, d2u_exact, d3u_approx, d3u_exact, d4u_approx, d4u_exact = np.loadtxt(
    "problem_8_output.txt", usecols=(0, 1, 2, 3, 4, 5, 6), unpack=True
)


log10_h = np.log10(h)

d2u_abs_err = np.absolute(d2u_approx - d2u_exact)
d2u_rel_err = np.absolute(d2u_abs_err / d2u_exact)
log10_d2u_rel_err = np.log10(d2u_rel_err)

d3u_abs_err = np.absolute(d3u_approx - d3u_exact)
d3u_rel_err = np.absolute(d3u_abs_err / d3u_exact)
log10_d3u_rel_err = np.log10(d3u_rel_err)

d4u_abs_err = np.absolute(d4u_approx - d4u_exact)
d4u_rel_err = np.absolute(d4u_abs_err / d4u_exact)
log10_d4u_rel_err = np.log10(d4u_rel_err)


# Common title string
exact_result = d2u_exact[0]
common_title_string = "for approximation of\n u''".format(exact_result)

# Figure size (inches)
figwidth = 5.5
figheight = figwidth / 1.33333


# Plot absolute error vs h on log-log axes
plt.figure(figsize=(figwidth, figheight))
plt.plot(h, d2u_abs_err, "--", c="0.8", linewidth=1.5)
plt.plot(h, d2u_abs_err, ".", c="black", markersize=10)

plt.plot(h, d3u_abs_err, "--", c="0.8", linewidth=1.5)
plt.plot(h, d3u_abs_err, ".", c="black", markersize=10)

plt.plot(h, d4u_abs_err, "--", c="0.8", linewidth=1.5)
plt.plot(h, d4u_abs_err, ".", c="black", markersize=10)

plt.title("Absolute error " + common_title_string, fontsize=10)
plt.ylabel("absolute error")
plt.xlabel("h")
plt.xscale("log")
plt.yscale("log")
plt.savefig("abs_err_vs_h.pdf")


# Plot log10(relative error) vs log10(h)
plt.figure(figsize=(figwidth, figheight))
plt.plot(log10_h, log10_d2u_rel_err, "--", c="0.8", linewidth=1.5)
plt.plot(log10_h, log10_d2u_rel_err, ".", c="black", markersize=10)

plt.plot(log10_h, log10_d3u_rel_err, "--", c="0.8", linewidth=1.5)
plt.plot(log10_h, log10_d3u_rel_err, ".", c="black", markersize=10)

plt.plot(log10_h, log10_d4u_rel_err, "--", c="0.8", linewidth=1.5)
plt.plot(log10_h, log10_d4u_rel_err, ".", c="black", markersize=10)

plt.title("Log10(relative error) " + common_title_string, fontsize=10)
plt.ylabel("log10(relative error)")
plt.xlabel("log10(h)")
plt.savefig("log10_rel_err_vs_log10_h.pdf")
