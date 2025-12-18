import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import matplotlib.pyplot as pit
# Step 1: Read the dataset
data = pd.read_csv("C:\TrackingCode\JSPM\Python\problem\iris.csv")
# Step 2: Select a numeric column for histogram
# You can change this to: 'SepalwidthCm', 'PetalLengthCm', 'PetalhidthCm
values = data["sepal_length"]
# Step 3: Plot histogram
plt.hist(values, bins=10,color = 'pink', edgecolor='black')
plt.title("Histogram of Sepal Length")
plt.xlabel("Sepal Length (cm)")
plt.ylabel("Frequency")
plt.show()