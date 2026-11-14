
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score
from sklearn.preprocessing import StandardScaler

# Load dataset
iris = load_iris()
X = iris.data
y = iris.target

# Split dataset
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

# Feature scaling
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# Train KNN model
model = KNeighborsClassifier(n_neighbors=5)
model.fit(X_train, y_train)

# Prediction
y_pred = model.predict(X_test)

print("Actual values:", y_test)
print("Predicted values:", y_pred)
print("Accuracy:", accuracy_score(y_test, y_pred))

# Predict new flower
new_flower = scaler.transform([[5.1, 3.5, 1.4, 0.2]])
prediction = model.predict(new_flower)

print("Predicted Flower:", iris.target_names[prediction[0]])
