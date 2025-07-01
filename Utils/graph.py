import pandas as pd
import matplotlib.pyplot as plt
import sys

def plot(filename, col_pairs, x_label, y_label):
    data = pd.read_csv(filename)
    
    plt.figure(figsize=(10, 6))
    
    for x_col, y_col in col_pairs:
        if x_col not in data.columns or y_col not in data.columns:
            print(f"Warning: Columns '{x_col}' or '{y_col}' not found in CSV")
            continue
        plt.plot(data[x_col], data[y_col], marker='o', markersize=1, label=f"{y_col}")
    
    plt.title(filename.split('.')[0].title())
    plt.xlabel(x_label)
    plt.ylabel(y_label)
    plt.legend()
    plt.grid(True)
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    if len(sys.argv) < 6 or (len(sys.argv) - 4) % 2 != 0:
        print("Usage: python graph.py <csv_file> <x_label> <y_label> <x_col1> <y_col1> [<x_col2> <y_col2> ...]")
        sys.exit(1)

    filename = sys.argv[1]
    x_label = sys.argv[2]
    y_label = sys.argv[3]
    col_pairs = [(sys.argv[i], sys.argv[i + 1]) for i in range(4, len(sys.argv), 2)]

    plot(filename, col_pairs, x_label, y_label)