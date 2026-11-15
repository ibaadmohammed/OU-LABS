
from sklearn.datasets import load_iris
from sklearn.preprocessing import MinMaxScaler
from minisom import MiniSom
import matplotlib.pyplot as plt

# Load dataset
iris = load_iris()
X = iris.data
y = iris.target

# Normalize data
scaler = MinMaxScaler()
X_scaled = scaler.fit_transform(X)

# Create SOM
som = MiniSom(
    x=7, y=7,
    input_len=4,
    sigma=1.0,
    learning_rate=0.5,
    random_seed=42
)

# Initialize and train SOM
som.random_weights_init(X_scaled)
som.train_random(X_scaled, 100)

# Display SOM
plt.figure(figsize=(8, 8))

for i, x in enumerate(X_scaled):
    winner = som.winner(x)
    plt.text(
        winner[0] + 0.5,
        winner[1] + 0.5,
        str(y[i]),
        color='black'
    )

plt.xlim(0, 7)
plt.ylim(0, 7)
plt.title("Self Organizing Map on Iris Dataset")
plt.grid()
plt.show()

print("SOM Training Completed")
