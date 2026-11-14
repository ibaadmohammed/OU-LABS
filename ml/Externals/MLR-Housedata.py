
import pandas as pd
from sklearn.linear_model import LinearRegression

# Dataset
data = {
    'Area': [1000, 1200, 1500, 1800, 2000, 2200],
    'Bedrooms': [2, 2, 3, 3, 4, 4],
    'Age': [10, 8, 5, 4, 3, 2],
    'Price': [2000000, 2400000, 3000000,
              3600000, 4000000, 4400000]
}

df = pd.DataFrame(data)

X = df[['Area', 'Bedrooms', 'Age']]
y = df['Price']

# Train model
model = LinearRegression()
model.fit(X, y)

# Prediction
new_house = [[1600, 3, 5]]
prediction = model.predict(new_house)

print("Predicted House Price:", prediction[0])
print("Coefficients:", model.coef_)
print("Intercept:", model.intercept_)
