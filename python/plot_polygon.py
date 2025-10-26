import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("polygon_modified.csv", names=["x", "y"])

plt.figure(figsize=(5,5))
plt.plot(df["x"], df["y"], "-o", color="royalblue", linewidth=2, markersize=6)

plt.title("Polygon Visualization", fontsize=14)
plt.xlabel("X coordinate")
plt.ylabel("Y coordinate")
plt.axis("equal")
plt.grid(True, linestyle="--", alpha=0.6)

plt.show()
