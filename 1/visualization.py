import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

insertion_df=pd.read_excel("insertion sort/analysis.xlsx")
merge_df=pd.read_excel("merge sort/analysis.xlsx")
quick_df=pd.read_excel("quick sort/analysis.xlsx")

plt.figure(figsize=(10,13))
plt.plot(insertion_df["Input Size"],insertion_df["Time Taken"],marker="o",color="red",label="Insertion Sort")
plt.plot(merge_df["Input Size"],merge_df["Time Taken"],marker="o",color="blue",label="Merge Sort")
plt.plot(quick_df["Input Size"],quick_df["Time Taken"],marker="o",color="green",label="Quick Sort")
plt.title("Sorting Analysis")
plt.xlabel("Input Size")
plt.ylabel("Time Taken (seconds)")
plt.yticks(np.arange(0, 1.7, 0.025))
plt.legend()
plt.savefig("analysis.png")