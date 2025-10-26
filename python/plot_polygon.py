# ---------------------------------------------------------------
# Polygon Visualization Script
# Author: Rodrigo Driemeier dos Santos
# Description: Plots polygon coordinates exported from the C++ program
# Date: October 2025
# ---------------------------------------------------------------

import pandas as pd
import matplotlib.pyplot as plt

# Read polygon data from the CSV file
# Make sure the filename matches the one exported from the C++ program
df = pd.read_csv("polygon_modified.csv", names=["x", "y"])

# Create a figure for visualization
plt.figure(figsize=(5, 5))

# Plot the polygon as connected points with circular markers
plt.plot(df["x"], df["y"], "-o", color="royalblue", linewidth=2, markersize=6)

# Add title, labels, and formatting
plt.title("Polygon Visualization", fontsize=14)
plt.xlabel("X coordinate")
plt.ylabel("Y coordinate")
plt.axis("equal")  # Keep scale consistent on both axes
plt.grid(True, linestyle="--", alpha=0.6)

# Display the figure
plt.show()
