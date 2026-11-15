
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# Dataset
data = {
    'YearsExperience': [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    'Salary': [30000, 35000, 40000, 45000, 50000,
               55000, 60000, 65000, 70000, 75000]
}

df = pd.DataFrame(data)

X = df[['YearsExperience']]
y = df['Salary']

# Train model
model = LinearRegression()
model.fit(X, y)

# Prediction
predicted = model.predict([[6.5]])
print("Predicted Salary:", predicted[0])

print("Slope:", model.coef_[0])
print("Intercept:", model.intercept_)

# Visualization
plt.scatter(X, y, color='blue')
plt.plot(X, model.predict(X), color='red')
plt.xlabel("Years of Experience")
plt.ylabel("Salary")
plt.title("Simple Linear Regression")
plt.show()
