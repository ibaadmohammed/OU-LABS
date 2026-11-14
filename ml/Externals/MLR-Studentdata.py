
import pandas as pd
from sklearn.linear_model import LinearRegression

# Dataset
data = {
    'StudyHours': [2, 3, 4, 5, 6, 7, 8, 9],
    'Attendance': [60, 65, 70, 75, 80, 85, 90, 95],
    'PreviousMarks': [50, 55, 60, 65, 70, 75, 80, 85],
    'Marks': [45, 50, 55, 60, 65, 70, 75, 80]
}

df = pd.DataFrame(data)

X = df[['StudyHours', 'Attendance', 'PreviousMarks']]
y = df['Marks']

# Train model
model = LinearRegression()
model.fit(X, y)

# Prediction
new_student = [[6, 80, 70]]
prediction = model.predict(new_student)

print("Predicted Student Marks:", prediction[0])
print("Coefficients:", model.coef_)
print("Intercept:", model.intercept_)
