
from sklearn.datasets import load_iris
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
import matplotlib.pyplot as plt

# Load dataset
iris = load_iris()
X = iris.data
y = iris.target

# Apply LDA
lda = LinearDiscriminantAnalysis(n_components=2)
X_lda = lda.fit_transform(X, y)

# Display reduced dimensions
print("Original Shape:", X.shape)
print("Reduced Shape:", X_lda.shape)

print("Reduced Data:")
print(X_lda[:5])

# Visualization
plt.scatter(X_lda[:, 0], X_lda[:, 1], c=y, cmap='viridis')

plt.xlabel("LDA Component 1")
plt.ylabel("LDA Component 2")
plt.title("LDA Dimensionality Reduction")
plt.show()
