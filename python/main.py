import matplotlib.pyplot as plt
import numpy as np
import os
import csv

# Location of the CSV file
filename = "search_data_2023-08-10 16:47:42.csv"

# Dictionary to store data for each algorithm
algorithms_data = {}

# Read the data from the CSV file
with open(filename, 'r') as f:
    reader = csv.reader(f)
    header = next(reader)  # Skip header row
    for line in reader:
        algorithm, data_size, time_taken, stddev, samples, _ = line
        if algorithm not in algorithms_data:
            algorithms_data[algorithm] = {'sizes': [], 'times': [], 'stddevs': []}
        algorithms_data[algorithm]['sizes'].append(int(data_size))
        algorithms_data[algorithm]['times'].append(float(time_taken))
        algorithms_data[algorithm]['stddevs'].append(float(stddev))

# Create a new plot to show all search algorithms
plt.figure(figsize=(10, 6))

# Plot the data for each algorithm
for algorithm, data in algorithms_data.items():
    sizes = data['sizes']
    times = data['times']
    stddevs = data['stddevs']

    # Fit a polynomial to the data
    z = np.polyfit(sizes, times, 2)
    f = np.poly1d(z)

    # Generate a smooth curve for the fitted polynomial
    sizes_fine = np.linspace(sizes[0], sizes[-1], 100)
    times_fine = f(sizes_fine)

    # Plot the data
    plt.errorbar(sizes, times, yerr=stddevs, fmt="o", label=algorithm)
    plt.plot(sizes_fine, times_fine)

plt.title("Comparison of Search Algorithms")
plt.xlabel("Data Size")
plt.ylabel("Time Taken (ms)")
plt.legend(loc="upper left")
plt.grid()
plt.axis([0, None, 0, None])
plt.savefig("Comparison_of_Search_Algorithms.png")
plt.clf()
plt.close()

# Continue with individual plots as before...
# ...
 