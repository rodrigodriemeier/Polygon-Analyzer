#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

struct Point{
    double x, y;

    double distance_from_origine(){
        return sqrt(x*x+y*y);
    }
};

struct Polygon{
    vector<Point> v;

    double distance_between_points(int a, int b){
        return sqrt(pow(v[a].x - v[b].x, 2) + pow(v[a].y - v[b].y, 2));
    }

    double perimeter(){
        double perim = 0;
        int n = v.size();
        for(int i = 0; i < n; i++){
            int j = (i+1) % n;
            perim += distance_between_points(i, j);
        }
        return perim;
    }

    void show_polygon(){
        for(int i = 0; i < (int)v.size(); i++){
            cout << "Point " << i+1 << ": (" << fixed << setprecision(2)
                 << v[i].x << " , " << v[i].y << ")" << endl;
        }
    }

    double area(){
        double area = 0;
        int n = v.size();
        for(int i = 0; i < n; i++){
            int j = (i+1) % n;
            area += v[i].x*v[j].y - v[j].x*v[i].y;
        }
        return fabs(area)/2;
    }

    Point centroid(){
        double cx = 0, cy = 0, A = 0;
        int n = v.size();
        for(int i = 0; i < n; i++){
            int j = (i+1)%n;
            A += (v[i].x*v[j].y - v[j].x*v[i].y);
            cx += (v[i].x+v[j].x)*(v[i].x*v[j].y-v[j].x*v[i].y);
            cy += (v[i].y+v[j].y)*(v[i].x*v[j].y-v[j].x*v[i].y);
        }
        A = A/2;
        Point c = {cx/(6*A), cy/(6*A)};
        return c;
    }

    Polygon translate(double dx, double dy){
        Polygon p;
        p.v.resize(v.size());
        for(int i = 0; i < (int)v.size(); i++){
            p.v[i].x = v[i].x + dx;
            p.v[i].y = v[i].y + dy;
        }
        return p;
    }

    Polygon rotate(double theta, bool deg){
        Polygon p;
        p.v.resize(v.size());
        double xb, yb, pi = 3.141592653589793;
        if(deg == 1){
            theta = theta * pi / 180;
        }
        for(int i = 0; i < (int)v.size(); i++){
            xb = v[i].x;
            yb = v[i].y;
            p.v[i].x = xb*cos(theta) - yb*sin(theta);
            p.v[i].y = xb*sin(theta) + yb*cos(theta);
        }
        return p;
    }

    Polygon scale(double k){
        Polygon p;
        p.v.resize(v.size());
        for(int i = 0; i < (int)v.size(); i++){
            p.v[i].x = k*v[i].x;
            p.v[i].y = k*v[i].y;
        }
        return p;
    }
};

Polygon create_polygon(Polygon p, int n);
void create_menu();
void export_to_csv(const Polygon& p, const string& filename);

int main(){
    int option = 12, orig, a, b, n;
    double theta, k, dx, dy;
    bool deg;
    Polygon p;
    
    do{
        cout << "How many points do you want to insert? " << endl;
        cin >> n;
    }while(n < 3);

    p = create_polygon(p, n);

    while(option != 0){
        create_menu();
        cout << "Choose an option" << endl;
        cin >> option;
        if(option == 0){
            break;
        }
        else if(option == 1){
            cout << "The permiter of the polygon is: " << fixed << setprecision(2) << p.perimeter() << endl;
        }
        else if(option == 2){
            cout << "Insert a point: " << endl << "(Ex. of insertion: '1')" << endl;
            cin >> orig;
            cout << "The distance from the point " << orig << " and the origin is " << fixed << setprecision(2) << p.v[orig-1].distance_from_origine() << endl;
        }
        else if(option == 3){
            cout << "Insert the first point: " << endl << "(Ex. of insertion: '1')" << endl;
            cin >> a;
            cout << "Insert the second point: " << endl << "(Ex. of insertion: '1')" << endl;
            cin >> b;
            cout << "The distance between point " << a << " and point " << b << " is: " << fixed << setprecision(2) << p.distance_between_points(a-1,b-1) << endl;
        }
        else if(option == 4){
            p.show_polygon();
        }
        else if(option == 5){
            cout << "The polygon's area values " << fixed << setprecision(2) << p.area() << endl;
        }
        else if(option == 6){
            cout << "Centroid : (" << fixed << setprecision(2) << p.centroid().x << " , " << fixed << setprecision(2) << p.centroid().y << ")" << endl;
        }
        else if(option == 7){
            cout << "Horizontal (dx): " << endl;
            cin >> dx;
            cout << "Vertical (dy): " << endl;
            cin >> dy;
            p = p.translate(dx, dy);
            cout << "Translation finished" << endl;
            p.show_polygon();
        }
        else if(option == 8){
            cout << "Radians (0) or degrees (1):" << endl;
            cin >> deg;
            cout << "Insert the angle:" << endl << "Please notice: 'theta' is measured from the X axis, positive counterclockwise" << endl;
            cin >> theta;
            p = p.rotate(theta, deg);
            cout << "The polygon has been rotated" << endl;
            p.show_polygon();
        }
        else if(option == 9){
            cout<< "Insert the value of K (scale factor):" << endl;
            cin >> k;
            p = p.scale(k);
            cout << "The polygon's scale has been changed" << endl;
            p.show_polygon();
        }
        else if(option == 10){
            do{
                cout << "How many points do you want to insert? " << endl;
                cin >> n;
            }while(n < 3);
            p = create_polygon(p, n);
            cout << "New polygon created." << endl;
        }
        else if(option == 11){
            string filename;
            cout << "Enter file name (e.g., polygon1.csv): ";
            cin >> filename;
            export_to_csv(p, filename);
        }
    }
    return 0;
}

Polygon create_polygon(Polygon p, int n){
    p.v.resize(n);
    cout << "You must insert the points in order (clockwise or counterclock wise)" << endl;
    cout << "(The program works for both convex and concave polygons, as long as the shape is simple (non self-intersecting))" << endl;
    for(int i = 0 ; i < n; i++){
        cout << "- Point " << i+1 << " -" << endl;
        cout << "Insert the value of X:" << endl;
        cin >> p.v[i].x;
        cout << "Insert the value of Y:" << endl;
        cin >> p.v[i].y;
    }
    return p;
}

void create_menu(){
    cout << "------------------------------------------------------------" << endl;
    cout << "                          MENU" << endl;
    cout << "0 - Finish" << endl << "1 - Polygon's Perimeter" << endl << "2 - Distance from Origin" << endl << "3 - Distance Between Polygon's Points" << endl;
    cout << "4 - Show Polygon's Points" << endl << "5 - Polygon's Area Value" << endl << "6 - Polygon's Centroid" << endl << "7 - Translate the Polygon" << endl;
    cout << "8 - Rotate the polygon" << endl << "9 - Change Polygon's Scale" << endl << "10 - Create a new polygon" << endl << "11 - Export polygon to CSV" << endl;
    cout << "------------------------------------------------------------" << endl;
}

void export_to_csv(const Polygon& p, const string& filename){
    ofstream file(filename);
    for (auto& point : p.v){
        file << point.x << "," << point.y << "\n";
    }
    file << p.v[0].x << "," << p.v[0].y << "\n";
    file.close();
    cout << "Polygon exported to " << filename << endl;
}