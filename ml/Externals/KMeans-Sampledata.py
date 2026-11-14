
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

# Sample dataset
X = np.array([
    [1, 2], [2, 3], [3, 2],
    [8, 8], [9, 8], [8, 9],
    [4, 5], [5, 5], [4, 6]
])

# Apply K-Means
model = KMeans(n_clusters=3, random_state=42, n_init=10)
model.fit(X)

# Cluster labels
labels = model.labels_

print("Cluster Labels:", labels)
print("Cluster Centers:")
print(model.cluster_centers_)

# Visualization
plt.scatter(X[:, 0], X[:, 1], c=labels, cmap='viridis')
plt.scatter(model.cluster_centers_[:, 0],
            model.cluster_centers_[:, 1],
            color='red', marker='X', s=200)

plt.xlabel("X")
plt.ylabel("Y")
plt.title("K-Means Clustering")
plt.show()
