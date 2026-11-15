
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# Dataset
data = {
    'Area': [1000, 1200, 1500, 1800, 2000, 2200],
    'Price': [2000000, 2400000, 3000000,
              3600000, 4000000, 4400000]
}

df = pd.DataFrame(data)

X = df[['Area']]
y = df['Price']

# Train model
model = LinearRegression()
model.fit(X, y)

# Prediction
area = [[1600]]
prediction = model.predict(area)

print("Predicted House Price:", prediction[0])

# Visualization
plt.scatter(X, y, color='blue')
plt.plot(X, model.predict(X), color='red')
plt.xlabel("House Area")
plt.ylabel("House Price")
plt.title("House Price Prediction")
plt.show()
