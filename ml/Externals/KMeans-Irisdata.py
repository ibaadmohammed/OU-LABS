
from sklearn.datasets import load_iris
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt

# Load dataset
iris = load_iris()
X = iris.data

# Feature scaling
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# Apply K-Means
model = KMeans(n_clusters=3, random_state=42, n_init=10)
model.fit(X_scaled)

# Cluster labels
labels = model.labels_

print("Cluster Labels:")
print(labels)

print("Cluster Centers:")
print(model.cluster_centers_)

# Visualization using first two features
plt.scatter(X_scaled[:, 0], X_scaled[:, 1],
            c=labels, cmap='viridis')

plt.xlabel("Sepal Length (Scaled)")
plt.ylabel("Sepal Width (Scaled)")
plt.title("K-Means Clustering on Iris Dataset")
plt.show()
