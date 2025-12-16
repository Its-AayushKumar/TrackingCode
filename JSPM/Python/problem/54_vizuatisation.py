import pandas as pd
import numpy as np
import statistics as st
iris = pd.read_csv("C:\TrackingCode\JSPM\Python\problem\iris.csv")

print(iris.head())
print(iris.tail())
print("Mean:",np.mean(iris["sepal_length"]))
print("Median:",np.median(iris["sepal_length"]))
print("Mode:",st.mode(iris["sepal_length"]))
