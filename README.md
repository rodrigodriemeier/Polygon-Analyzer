* POLYGON ANALYZER *

A C++ Program that allows the user to create, visualize, and analyze polygons through geomatric operations such as translation, rotation, scaling, perimeter, area and centroid calculation.

FEATURES
 - Create a polygon with any number of points (≥ 3)
 - Calculate:
     - Distance between 2 points
     - Distance from origin
     - Polygon perimeter
     - Polygon area
     - Polygon centroid
- Apply geometric transformations:
     - Translation
     - Rotation (degrees or radians)
     - Scaling
- Export the polygon's coordinates to a .csv file
- Visualize the polygone in Python using Matplotlib

PROJECT STRUCTURE

* Main directories *

** src/ → Contains the main C++ program
   - poligone2DCPP.cpp — Core implementation of all polygon operations

** python/ → Script for visualization
   - plot_polygon.py — Plots the polygon from the exported CSV

** examples/ → Screenshots and generated examples
   - Creating_Polygon_Example.jpg
   - Show_Polygon_Example.jpg
   - Calculating_Perimeter_Example.jpg
   - Distance_From_Origin_Example.jpg
   - Distance_Between_Two_Points_Example.jpg
   - Calculating_Area_Example.jpg
   - Calculating_Centroid_Example.jpg
   - Translating_Polygon_Example.jpg
   - Rotating_Polygon_Example.jpg
   - Changing_Polygon's_Scale.jpg
   - Creating_New_Polygon_Example.jpg
   - Saving_CSV_File_Example.jpg
   - Initial_Polygon_Graph.jpg
   - Modified_Polygon_Graph.jpg

** README.md — Project documentation

STEPS TO TAKE

1 - Compile the C++ program
g++ src/polygon.cpp -o polygon

2 - Run the executable
./polygon
or (on Windows):
polygon.exe

|You can then interact with the menu to create and modify polygons|

3 - Export data and visualize
After exporting the CSV file, run:
python python/plot_polygon.py
!!!Important!!!
If you chose a custom name for the .csv file when exporting from the C++ program, you need to update the variable filename inside the Python script (plot_polygon.py) with the same name so the visualization works correctly.

AUTHOR
Rodrigo Driemeier dos Santos
EESC - University of São Paulo (USP), São Carlos, Brazil — Mechatronics Engineering
École Centrale de Lille, France — Generalist Engineering
rodrigodriemeier@usp.br
https://www.linkedin.com/in/rodrigo-driemeier-dos-santos-a7698633b/

TECH STACK

C++ (Core application)
   - Python (Matplotlib, Pandas) for visualization
   - Git & GitHub for version control

Thanks for checking out the project — it started as a simple geometry exercise and ended up turning into a pretty fun mini tool :)
