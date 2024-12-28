import csv

# Define the checklist data
checklist = [
    {
        "Concept": "Hello World",
        "Python": "path/to/python/hello_world.py",
        "Java": "path/to/java/HelloWorld.java",
        "C": "path/to/c/hello_world.c"
    },
    {
        "Concept": "Data Structures",
        "Python": "path/to/python/data_structures.py",
        "Java": "path/to/java/DataStructures.java",
        "C": "path/to/c/data_structures.c"
    },
    {
        "Concept": "Sorting Algorithms",
        "Python": "path/to/python/sorting_algorithms.py",
        "Java": "path/to/java/SortingAlgorithms.java",
        "C": "path/to/c/sorting_algorithms.c"
    },
    # Add more concepts as needed
]

# Specify the CSV file path
csv_file_path = 'cs_checklist.csv'

# Create the CSV file
with open(csv_file_path, mode='w', newline='') as file:
    writer = csv.DictWriter(file, fieldnames=["Concept", "Python", "Java", "C"])
    writer.writeheader()
    for item in checklist:
        writer.writerow(item)

print(f"CSV checklist created at: {csv_file_path}")